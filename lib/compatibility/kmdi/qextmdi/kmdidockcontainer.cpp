/* This file is part of the KDE project
 Copyright (C) 2002 Christoph Cullmann <cullmann@kde.org>
 Copyright (C) 2002,2003 Joseph Wenninger <jowenn@kde.org>

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Library General Public
 License version 2 as published by the Free Software Foundation.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Library General Public License for more details.

 You should have received a copy of the GNU Library General Public License
 along with this library; see the file COPYING.LIB.  If not, write to
 the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 Boston, MA 02110-1301, USA.
*/

#include "kmdimainfrm.h"
#include "kmdidockcontainer.h"
#include "kmdidockcontainer.moc"

#include "kdockwidget_private.h"

#include <qwidgetstack.h>
#include <qlayout.h>
#include <qtimer.h>
#include <qtooltip.h>
#include <kmultitabbar.h>
#include <kglobalsettings.h>

#include <kdebug.h>
#include <kiconloader.h>
#include <kapplication.h>
#include <kconfig.h>
#include <klocale.h>

//TODO: Well, this is already defined in kdeui/kdockwidget.cpp
static const char* const kmdi_not_close_xpm[] =
    {
        "5 5 2 1",
        "# c black",
        ". c None",
        "#####",
        "#...#",
        "#...#",
        "#...#",
        "#####"
    };

KMdiDockContainer::KMdiDockContainer( QWidget *parent, QWidget *win, int position, int flags )
		: QWidget( parent ), KDockContainer()
{
	m_tabSwitching = false;
	m_block = false;
	m_inserted = -1;
	m_mainWin = win;
	oldtab = -1;
	mTabCnt = 0;
	m_position = position;
	m_previousTab = -1;
	m_separatorPos = 17;
	m_movingState = NotMoving;
	m_startEvent = 0;
	kdDebug( 760 ) << k_funcinfo << endl;

	QBoxLayout *l;
	m_horizontal = ( ( position == KDockWidget::DockTop ) || ( position == KDockWidget::DockBottom ) );


	if ( m_horizontal )
		l = new QVBoxLayout( this ); //vertical layout for top and bottom docks
	else
		l = new QHBoxLayout( this ); //horizontal layout for left and right docks

	l->setAutoAdd( false );

	m_tb = new KMultiTabBar( m_horizontal ? KMultiTabBar::Horizontal : KMultiTabBar::Vertical, this );

	m_tb->setStyle( KMultiTabBar::KMultiTabBarStyle( flags ) );
	m_tb->showActiveTabTexts( true );

	KMultiTabBar::KMultiTabBarPosition kmtbPos;
	switch( position )
	{
	case KDockWidget::DockLeft:
		kmtbPos = KMultiTabBar::Left;
		break;
	case KDockWidget::DockRight:
		kmtbPos = KMultiTabBar::Right;
		break;
	case KDockWidget::DockTop:
		kmtbPos = KMultiTabBar::Top;
		break;
	case KDockWidget::DockBottom:
		kmtbPos = KMultiTabBar::Bottom;
		break;
	default:
		kmtbPos = KMultiTabBar::Right;
		break;
	}
	m_tb->setPosition( kmtbPos );

	m_ws = new QWidgetStack( this );

	m_ws->setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding ) );

	//layout the tabbar
	if ( position == KDockWidget::DockLeft || position == KDockWidget::DockTop )
	{
		//add the tabbar then the widget stack
		l->add( m_tb );
		l->add( m_ws );
	}
	else
	{
		//add the widget stack then the tabbar
		l->add( m_ws );
		l->add( m_tb );
	}

	l->activate();
	m_ws->hide();

}

void KMdiDockContainer::setStyle( int style )
{
	if ( m_tb )
		m_tb->setStyle( KMultiTabBar::KMultiTabBarStyle( style ) );
}

KMdiDockContainer::~KMdiDockContainer()
{
	QMap<KDockWidget*, int>::iterator it;
	while ( m_map.count() )
	{
		it = m_map.begin();
		KDockWidget *w = it.key();
		if ( m_overlapButtons.contains( w ) )
		{
			( static_cast<KDockWidgetHeader*>( w->getHeader()->qt_cast( "KDockWidgetHeader" ) ) )->removeButton( m_overlapButtons[w] );
			m_overlapButtons.remove( w );
		}
		m_map.remove( w );
		w->undock();
	}
	deactivated( this );
}


void KMdiDockContainer::init()
{
	kdDebug( 760 ) << k_funcinfo << endl;
	if ( !m_horizontal )
	{
		kdDebug( 760 ) << k_funcinfo << "Horizontal tabbar. Setting forced fixed width." << endl;
		parentDockWidget()->setForcedFixedWidth( m_tb->width() );
		activateOverlapMode( m_tb->width() );
	}
	else
	{
		kdDebug( 760 ) << k_funcinfo << "Vertical tabbar. Setting forced fixed height." << endl;
		parentDockWidget()->setForcedFixedHeight( m_tb->height() );
		activateOverlapMode( m_tb->height() );
	}

	// try to restore splitter size
	if ( parentDockWidget() && parentDockWidget()->parent() )
	{
		KDockSplitter * sp = static_cast<KDockSplitter*>( parentDockWidget()->parent()->qt_cast( "KDockSplitter" ) );
		if ( sp )
			sp->setSeparatorPosX( m_separatorPos );
	}
}

KDockWidget* KMdiDockContainer::parentDockWidget()
{
	return ( ( KDockWidget* ) parent() );
}

void KMdiDockContainer::insertWidget ( KDockWidget *dwdg, QPixmap pixmap, const QString &text, int & )
{
	kdDebug( 760 ) << k_funcinfo << "Adding a dockwidget to the dock container" << endl;
	KDockWidget* w = dwdg;
	int tab;
	bool alreadyThere = m_map.contains( w );

	if ( alreadyThere )
	{
		tab = m_map[ w ];
		if ( m_ws->addWidget( w, tab ) != tab )
			kdDebug( 760 ) << "ERROR COULDN'T READD WIDGET" << endl;
		
		kdDebug( 760 ) << k_funcinfo << "Readded widget " << dwdg << endl;
	}
	else
	{
		tab = m_ws->addWidget( w );
		m_map.insert( w, tab );
		m_revMap.insert( tab, w );

		if ( ( ( KDockWidget* ) parentWidget() ) ->mayBeShow() )
			( ( KDockWidget* ) parentWidget() ) ->dockBack();

		if ( w->getHeader()->qt_cast( "KDockWidgetHeader" ) )
		{
			kdDebug( 760 ) << k_funcinfo << "The dockwidget we're adding has a header" << endl;
			kdDebug( 760 ) << k_funcinfo << "Adding our overlap mode button to it" << endl;

			KDockWidgetHeader *hdr = static_cast<KDockWidgetHeader*>( w->getHeader()->qt_cast( "KDockWidgetHeader" ) );
			KDockButton_Private *btn = new KDockButton_Private( hdr, "OverlapButton" );

			QToolTip::add( btn, i18n( "Switch between overlap and side by side mode", "Overlap" ) );

			btn->setToggleButton( true );
			btn->setPixmap( const_cast< const char** >( kmdi_not_close_xpm ) );
			hdr->addButton( btn );
			m_overlapButtons.insert( w, btn );
			btn->setOn( !isOverlapMode() );

			connect( btn, SIGNAL( clicked() ), this, SLOT( changeOverlapMode() ) );
		}

		m_tb->appendTab( pixmap.isNull() ? SmallIcon( "misc" ) : pixmap, tab, w->tabPageLabel() );
		m_tb->tab( tab )->installEventFilter( this );
		kdDebug( 760 ) << k_funcinfo << "Added tab with label " << w->tabPageLabel() <<
			" to the tabbar" << endl;

		connect( m_tb->tab( tab ), SIGNAL( clicked( int ) ), this, SLOT( tabClicked( int ) ) );

		mTabCnt++;
		m_inserted = tab;
		int dummy = 0;
		KDockContainer::insertWidget( w, pixmap, text, dummy );
		itemNames.append( w->name() );
		tabCaptions.insert( w->name(), w->tabPageLabel() );
		tabTooltips.insert( w->name(), w->toolTipString() );
	}

	//FB  m_ws->raiseWidget(tab);
}


bool KMdiDockContainer::eventFilter( QObject *obj, QEvent *event )
{
	switch ( event->type() )
	{
	case QEvent::MouseButtonPress:
	{
		KMultiTabBarTab* kmtbTab = dynamic_cast<KMultiTabBarTab*>( obj );
		if ( !obj )
		{
			kdDebug(760) << k_funcinfo << "Got a mouse button press but we have no tab" << endl;
			break;
		}
		
		KDockWidget* w = m_revMap[ dynamic_cast<KMultiTabBarTab*>( obj )->id() ];
		if ( !w )
		{
			kdDebug(760) << k_funcinfo << "Got a mouse button press but we have no widget" << endl;
			break;
		}
		
		if ( !w->getHeader() )
		{
			kdDebug(760) << k_funcinfo << "Got a mouse button press but we have no header" << endl;
			break;
		}
		
		KDockWidgetHeader *hdr = static_cast<KDockWidgetHeader*>( w->getHeader()->qt_cast( "KDockWidgetHeader" ) );
		if ( !hdr )
		{
			kdDebug(760) << "Wrong header type in KMdiDockContainer::eventFilter" << endl;
			break;
		}
		
		m_dockManager = w->dockManager();
		m_dragPanel = hdr->dragPanel();
		
		if ( m_dragPanel )
			m_movingState = WaitingForMoveStart;
		
		delete m_startEvent;
		m_startEvent = new QMouseEvent( * ( ( QMouseEvent* ) event ) );
	}
	break;
	case QEvent::MouseButtonRelease:
		if ( m_movingState == Moving )
		{
			m_movingState = NotMoving;
			QApplication::postEvent( m_dragPanel, new QMouseEvent( * ( ( QMouseEvent* ) event ) ) );
			delete m_startEvent;
			m_startEvent = 0;
		}
	case QEvent::MouseMove:
		if ( m_movingState == WaitingForMoveStart )
		{
			QPoint p( ( ( QMouseEvent* ) event )->pos() - m_startEvent->pos() );
			if ( p.manhattanLength() > KGlobalSettings::dndEventDelay() )
			{
				m_dockManager->eventFilter( m_dragPanel, m_startEvent );
				m_dockManager->eventFilter( m_dragPanel, event );
				m_movingState = Moving;
			}
		}
		else if ( m_movingState == Moving )
			m_dockManager->eventFilter( m_dragPanel, event );
		
		break;
	default:
		break;

	}
	return false;

}

void KMdiDockContainer::showWidget( KDockWidget *w )
{
	if ( !m_map.contains( w ) )
		return ;
	
	int id = m_map[ w ];
	m_tb->setTab( id, true );
	tabClicked( id );
}

void KMdiDockContainer::changeOverlapMode()
{
	const KDockButton_Private * btn = dynamic_cast<const KDockButton_Private*>( sender() );

	if ( !btn )
		return ;

	if ( !btn->isOn() )
	{
		kdDebug( 760 ) << k_funcinfo << "Activating overlap mode" << endl;
		if ( !m_horizontal )
			activateOverlapMode( m_tb->width() );
		else
			activateOverlapMode( m_tb->height() );

	}
	else
	{
		kdDebug( 760 ) << k_funcinfo << "Deactivating overlap mode" << endl;
		deactivateOverlapMode();
	}

	QMap<KDockWidget*, KDockButton_Private*>::iterator it;
	for ( it = m_overlapButtons.begin(); it != m_overlapButtons.end(); ++it )
		it.data()->setOn( !isOverlapMode() );
}

void KMdiDockContainer::hideIfNeeded()
{
	if ( itemNames.count() == 0 )
	{
		kdDebug( 760 ) << k_funcinfo << "Hiding the dock container" << endl;
		( ( KDockWidget* ) parentWidget() )->undock();
	}
}

void KMdiDockContainer::removeWidget( KDockWidget* dwdg )
{
	KDockWidget * w = dwdg;
	if ( !m_map.contains( w ) )
		return; //we don't have this widget in our container

	kdDebug( 760 ) << k_funcinfo << endl;
	//lower the tab. ( TODO: needed? )
	int id = m_map[ w ];
	if ( m_tb->isTabRaised( id ) )
	{
		m_tb->setTab( id, false );
		tabClicked( id );
	}
	
	m_tb->removeTab( id );
	m_ws->removeWidget( w );
	m_map.remove( w );
	m_revMap.remove( id );
	if ( m_overlapButtons.contains( w ) )
	{
		( static_cast<KDockWidgetHeader*>( w->getHeader() ->qt_cast( "KDockWidgetHeader" ) ) )->removeButton( m_overlapButtons[ w ] );
		m_overlapButtons.remove( w );
	}
	KDockContainer::removeWidget( w );
	itemNames.remove( w->name() );
	tabCaptions.remove( w->name() );
	tabTooltips.remove( w->name() );
	hideIfNeeded();
}

void KMdiDockContainer::undockWidget( KDockWidget *dwdg )
{
	KDockWidget * w = dwdg;

	if ( !m_map.contains( w ) )
		return ;

	int id = m_map[ w ];
	if ( m_tb->isTabRaised( id ) )
	{
		kdDebug( 760 ) << k_funcinfo << "Widget has been undocked, setting tab down" << endl;
		m_tb->setTab( id, false );
		tabClicked( id );
	}
}

void KMdiDockContainer::tabClicked( int t )
{
	bool call_makeVisible = !m_tabSwitching;
	m_tabSwitching = true;
	if ( m_tb->isTabRaised( t ) )
	{
		kdDebug( 760 ) << k_funcinfo << "Tab " << t << " was just activated" << endl;
		if ( m_ws->isHidden() )
		{
			kdDebug( 760 ) << k_funcinfo << "Showing widgetstack for tab just clicked" << endl;
			m_ws->show();
			parentDockWidget()->restoreFromForcedFixedSize();
		}
		
		if ( !m_ws->widget( t ) )
		{
			kdDebug( 760 ) << k_funcinfo << "Widget tab was clicked for is not in our stack" << endl;
			kdDebug( 760 ) << k_funcinfo << "Docking it back in" << endl;
			m_revMap[t]->manualDock( parentDockWidget(), KDockWidget::DockCenter, 20 );
			if ( call_makeVisible )
				m_revMap[t]->makeDockVisible();
			m_tabSwitching = false;
			emit activated( this );
			return ;
		}
		
		if ( m_ws->widget( t ) )
		{
			m_ws->raiseWidget( t );
			KDockWidget * tmpDw = static_cast<KDockWidget*>( m_ws->widget( t )->qt_cast( "KDockWidget" ) );
			if ( tmpDw )
			{
				if ( tmpDw->getWidget() )
					tmpDw->getWidget()->setFocus();
			}
			else
				kdDebug( 760 ) << k_funcinfo << "Something really weird is going on" << endl;
		}
		else
			kdDebug( 760 ) << k_funcinfo << "We have no widget to handle in our stack." << endl;

		if ( oldtab != t )
			m_tb->setTab( oldtab, false );
		
		m_tabSwitching = true;
		oldtab = t;
		emit activated( this );
	}
	else
	{
		kdDebug( 760 ) << k_funcinfo << "Tab " << t << " was just deactiviated" << endl;
		// try save splitter position
		if ( parentDockWidget() && parentDockWidget()->parent() )
		{
			KDockSplitter * sp = static_cast<KDockSplitter*>( parentDockWidget()->parent()->qt_cast( "KDockSplitter" ) );
			if ( sp )
				m_separatorPos = sp->separatorPos();
		}
		m_previousTab = t;
		//    oldtab=-1;
		if ( m_block )
			return ;
		emit deactivated( this );
		m_block = true;
		if ( m_ws->widget( t ) )
		{
			//    ((KDockWidget*)m_ws->widget(t))->undock();
		}
		m_block = false;
		m_ws->hide ();


		kdDebug( 760 ) << k_funcinfo << "Fixed Width:" << m_tb->width() << endl;
		if ( !m_horizontal )
			parentDockWidget()->setForcedFixedWidth( m_tb->width() ); // strange why it worked before at all
		else
			parentDockWidget()->setForcedFixedHeight( m_tb->height() ); // strange why it worked before at all
	}
	m_tabSwitching = false;
}

void KMdiDockContainer::setToolTip ( KDockWidget* w, QString &s )
{
	kdDebug( 760 ) << k_funcinfo << "Setting tooltip '" << s << "' for widget " << w << endl;
	int tabId = m_map[w];
	KMultiTabBarTab *mbTab = m_tb->tab( tabId );
	QToolTip::remove( mbTab );
	QToolTip::add( mbTab, s );
}

void KMdiDockContainer::setPixmap( KDockWidget* widget , const QPixmap& pixmap )
{
	int id = m_ws->id( widget );
	if ( id == -1 )
		return ;
	KMultiTabBarTab *tab = m_tb->tab( id );
	tab->setIcon( pixmap.isNull() ? SmallIcon( "misc" ) : pixmap );
}

void KMdiDockContainer::save( QDomElement& dockEl )
{
	QDomDocument doc = dockEl.ownerDocument();
	QDomElement el;
	el = doc.createElement( "name" );
	el.appendChild( doc.createTextNode( QString( "%1" ).arg( parent() ->name() ) ) );
	dockEl.appendChild( el );
	el = doc.createElement( "overlapMode" );
	el.appendChild( doc.createTextNode( isOverlapMode() ? "true" : "false" ) );
	dockEl.appendChild( el );
	QPtrList<KMultiTabBarTab>* tl = m_tb->tabs();
	QPtrListIterator<KMultiTabBarTab> it( *tl );
	QStringList::Iterator it2 = itemNames.begin();
	int i = 0;
	for ( ;it.current() != 0;++it, ++it2 )
	{
		el = doc.createElement( "child" );
		el.setAttribute( "pos", QString( "%1" ).arg( i ) );
		QString s = tabCaptions[ *it2 ];
		if ( !s.isEmpty() )
		{
			el.setAttribute( "tabCaption", s );
		}
		s = tabTooltips[ *it2 ];
		if ( !s.isEmpty() )
		{
			el.setAttribute( "tabTooltip", s );
		}
		el.appendChild( doc.createTextNode( *it2 ) );
		dockEl.appendChild( el );
		if ( m_tb->isTabRaised( it.current() ->id() ) )
		{
			QDomElement el2 = doc.createElement( "raised" );
			el2.appendChild( doc.createTextNode( m_ws->widget( it.current() ->id() ) ->name() ) );
			el.appendChild( el2 );
		}
		++i;
	}


}

void KMdiDockContainer::load( QDomElement& dockEl )
{
	QString raise;

	for ( QDomNode n = dockEl.firstChild();!n.isNull();n = n.nextSibling() )
	{
		QDomElement el = n.toElement();
		if ( el.isNull() )
			continue;
		if ( el.tagName() == "overlapMode" )
		{
			if ( el.attribute( "overlapMode" ) != "false" )
				activateOverlapMode( m_tb->width() );
			else
				deactivateOverlapMode();
		}
		else if ( el.tagName() == "child" )
		{
			KDockWidget * dw = ( ( KDockWidget* ) parent() ) ->dockManager() ->getDockWidgetFromName( el.text() );
			if ( dw )
			{
				if ( el.hasAttribute( "tabCaption" ) )
				{
					dw->setTabPageLabel( el.attribute( "tabCaption" ) );
				}
				if ( el.hasAttribute( "tabTooltip" ) )
				{
					dw->setToolTipString( el.attribute( "tabTooltip" ) );
				}
				dw->manualDock( ( KDockWidget* ) parent(), KDockWidget::DockCenter );
			}
		}
	}

	QPtrList<KMultiTabBarTab>* tl = m_tb->tabs();
	QPtrListIterator<KMultiTabBarTab> it1( *tl );
	m_ws->hide();
	if ( !m_horizontal )
		parentDockWidget()->setForcedFixedWidth( m_tb->width() );
	else
		parentDockWidget()->setForcedFixedHeight( m_tb->height() );
	
	for ( ;it1.current() != 0;++it1 )
		m_tb->setTab( it1.current() ->id(), false );

	kapp->syncX();
	m_delayedRaise = -1;

	for ( QMap<KDockWidget*, KDockButton_Private*>::iterator it = m_overlapButtons.begin();
	        it != m_overlapButtons.end();++it )
		it.data() ->setOn( !isOverlapMode() );

	if ( !raise.isEmpty() )
	{
		for ( QMap<KDockWidget*, int>::iterator it = m_map.begin();it != m_map.end();++it )
		{
			if ( it.key() ->name() == raise )
			{
				m_delayedRaise = it.data();
				QTimer::singleShot( 0, this, SLOT( delayedRaise() ) );
				kdDebug( 760 ) << k_funcinfo << "raising " << it.key()->name() << endl;
				break;
			}
		}

	}
	if ( m_delayedRaise == -1 )
		QTimer::singleShot( 0, this, SLOT( init() ) );
}

void KMdiDockContainer::save( KConfig* cfg, const QString& group_or_prefix )
{
	QString grp = cfg->group();
	cfg->deleteGroup( group_or_prefix + QString( "::%1" ).arg( parent() ->name() ) );
	cfg->setGroup( group_or_prefix + QString( "::%1" ).arg( parent() ->name() ) );

	if ( isOverlapMode() )
		cfg->writeEntry( "overlapMode", "true" );
	else
		cfg->writeEntry( "overlapMode", "false" );

	// try to save the splitter position
	if ( parentDockWidget() && parentDockWidget() ->parent() )
	{
		KDockSplitter * sp = static_cast<KDockSplitter*>( parentDockWidget() ->
		                     parent() ->qt_cast( "KDockSplitter" ) );
		if ( sp )
			cfg->writeEntry( "separatorPos", m_separatorPos );
	}

	QPtrList<KMultiTabBarTab>* tl = m_tb->tabs();
	QPtrListIterator<KMultiTabBarTab> it( *tl );
	QStringList::Iterator it2 = itemNames.begin();
	int i = 0;
	for ( ;it.current() != 0;++it, ++it2 )
	{
		//    cfg->writeEntry(QString("widget%1").arg(i),m_ws->widget(it.current()->id())->name());
		cfg->writeEntry( QString( "widget%1" ).arg( i ), ( *it2 ) );
		QString s = tabCaptions[ *it2 ];
		if ( !s.isEmpty() )
		{
			cfg->writeEntry( QString( "widget%1-tabCaption" ).arg( i ), s );
		}
		s = tabTooltips[ *it2 ];
		if ( !s.isEmpty() )
		{
			cfg->writeEntry( QString( "widget%1-tabTooltip" ).arg( i ), s );
		}
		//    kdDebug(760)<<"****************************************Saving: "<<m_ws->widget(it.current()->id())->name()<<endl;
		if ( m_tb->isTabRaised( it.current() ->id() ) )
			cfg->writeEntry( m_ws->widget( it.current() ->id() ) ->name(), true );
		++i;
	}
	cfg->sync();
	cfg->setGroup( grp );

}

void KMdiDockContainer::load( KConfig* cfg, const QString& group_or_prefix )
{
	QString grp = cfg->group();
	cfg->setGroup( group_or_prefix + QString( "::%1" ).arg( parent() ->name() ) );

	if ( cfg->readEntry( "overlapMode" ) != "false" )
		activateOverlapMode( m_tb->width() );
	else
		deactivateOverlapMode();

	m_separatorPos = cfg->readNumEntry( "separatorPos", 18 );

	int i = 0;
	QString raise;
	while ( true )
	{
		QString dwn = cfg->readEntry( QString( "widget%1" ).arg( i ) );
		if ( dwn.isEmpty() )
			break;
		kdDebug( 760 ) << k_funcinfo << "configuring dockwidget :" << dwn << endl;
		KDockWidget *dw = ( ( KDockWidget* ) parent() ) ->dockManager() ->getDockWidgetFromName( dwn );
		if ( dw )
		{
			QString s = cfg->readEntry( QString( "widget%1-tabCaption" ).arg( i ) );
			if ( !s.isEmpty() )
			{
				dw->setTabPageLabel( s );
			}
			s = cfg->readEntry( QString( "widget%1-tabTooltip" ).arg( i ) );
			if ( !s.isEmpty() )
			{
				dw->setToolTipString( s );
			}
			dw->manualDock( ( KDockWidget* ) parent(), KDockWidget::DockCenter );
		}
		if ( cfg->readBoolEntry( dwn, false ) )
			raise = dwn;
		i++;

	}

	QPtrList<KMultiTabBarTab>* tl = m_tb->tabs();
	QPtrListIterator<KMultiTabBarTab> it1( *tl );
	m_ws->hide();
	if ( !m_horizontal )
		parentDockWidget() ->setForcedFixedWidth( m_tb->width() );
	else
		parentDockWidget() ->setForcedFixedHeight( m_tb->height() );
	for ( ;it1.current() != 0;++it1 )
	{
		m_tb->setTab( it1.current() ->id(), false );
	}
	kapp->syncX();
	m_delayedRaise = -1;

	for ( QMap<KDockWidget*, KDockButton_Private*>::iterator it = m_overlapButtons.begin();
	        it != m_overlapButtons.end();++it )
		it.data() ->setOn( !isOverlapMode() );

	if ( !raise.isEmpty() )
	{
		for ( QMap<KDockWidget*, int>::iterator it = m_map.begin();it != m_map.end();++it )
		{
			if ( it.key() ->name() == raise )
			{
				/*        tabClicked(it.data());
				        m_tb->setTab(it.data(),true);
				        tabClicked(it.data());
				        m_ws->raiseWidget(it.key());
				        kapp->sendPostedEvents();
				        kapp->syncX();*/

				m_delayedRaise = it.data();
				QTimer::singleShot( 0, this, SLOT( delayedRaise() ) );
				kdDebug( 760 ) << k_funcinfo << "raising" << it.key() ->name() << endl;
				break;
			}
		}

	}
	if ( m_delayedRaise == -1 )
		QTimer::singleShot( 0, this, SLOT( init() ) );
	cfg->setGroup( grp );

}

void KMdiDockContainer::delayedRaise()
{
	m_tb->setTab( m_delayedRaise, true );
	tabClicked( m_delayedRaise );
}

void KMdiDockContainer::collapseOverlapped()
{
	//don't collapse if we're switching tabs
	if ( m_tabSwitching )
		return;
	
	if ( isOverlapMode() )
	{
		QPtrList<KMultiTabBarTab>* tl = m_tb->tabs();
		QPtrListIterator<KMultiTabBarTab> it( *tl );
		for ( ;it.current();++it )
		{
			if ( it.current()->isOn() )
			{
				kdDebug( 760 ) << k_funcinfo << "lowering tab with id " << ( *it )->id() << endl;
				it.current()->setState( false );
				tabClicked( ( *it )->id() );
			}
		}
	}
}

void KMdiDockContainer::toggle()
{
	kdDebug( 760 ) << k_funcinfo << endl;
	
	if ( m_tb->isTabRaised( oldtab ) )
	{
		kdDebug( 760 ) << k_funcinfo << "lowering tab" << endl;
		m_tb->setTab( oldtab, false );
		tabClicked( oldtab );
		KMdiMainFrm *mainFrm = dynamic_cast<KMdiMainFrm*>( m_mainWin );
		if ( mainFrm && mainFrm->activeWindow() )
			mainFrm->activeWindow()->setFocus();
	}
	else
	{
		kdDebug( 760 ) << k_funcinfo << "raising tab" << endl;
		if ( m_tb->tab( m_previousTab ) == 0 )
		{
			if ( m_tb->tabs() ->count() == 0 )
				return ;
			
			m_previousTab = m_tb->tabs() ->getFirst() ->id();
		}
		m_tb->setTab( m_previousTab, true );
		tabClicked( m_previousTab );
	}
}

void KMdiDockContainer::prevToolView()
{
	kdDebug( 760 ) << k_funcinfo << endl;
	QPtrList<KMultiTabBarTab>* tabs = m_tb->tabs();
	int pos = tabs->findRef( m_tb->tab( oldtab ) );
	
	if ( pos == -1 )
		return ;
	
	pos--;
	if ( pos < 0 )
		pos = tabs->count() - 1;
	
	KMultiTabBarTab *tab = tabs->at( pos );
	if ( !tab )
		return ; //can never happen here, but who knows
	
	m_tb->setTab( tab->id(), true );
	tabClicked( tab->id() );
}

void KMdiDockContainer::nextToolView()
{
	kdDebug( 760 ) << k_funcinfo << endl;
	QPtrList<KMultiTabBarTab>* tabs = m_tb->tabs();
	int pos = tabs->findRef( m_tb->tab( oldtab ) );
	
	if ( pos == -1 )
		return ;
	
	pos++;
	if ( pos >= ( int ) tabs->count() )
		pos = 0;
	
	KMultiTabBarTab *tab = tabs->at( pos );
	if ( !tab )
		return ; //can never happen here, but who knows
	
	m_tb->setTab( tab->id(), true );
	tabClicked( tab->id() );
}

// kate: space-indent off; tab-width 4; replace-tabs off; indent-mode csands;

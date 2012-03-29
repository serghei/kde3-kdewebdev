//----------------------------------------------------------------------------
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU Library General Public License as
//    published by the Free Software Foundation; either version 2 of the
//    License, or (at your option) any later version.
//
//----------------------------------------------------------------------------

#include <ktabbar.h>
#include <kpopupmenu.h>
#include "kmdidocumentviewtabwidget.h"

KMdiDocumentViewTabWidget::KMdiDocumentViewTabWidget( QWidget* parent, const char* name ) : KTabWidget( parent, name )
{
	m_visibility = KMdi::ShowWhenMoreThanOneTab;
	tabBar() ->hide();
#ifndef Q_WS_WIN //todo

	setHoverCloseButton( true );
#endif

	connect( this, SIGNAL( closeRequest( QWidget* ) ), this, SLOT( closeTab( QWidget* ) ) );
}

KMdiDocumentViewTabWidget::~KMdiDocumentViewTabWidget()
{}

void KMdiDocumentViewTabWidget::closeTab( QWidget* w )
{
	w->close();
}
void KMdiDocumentViewTabWidget::addTab ( QWidget * child, const QString & label )
{
	KTabWidget::addTab( child, label );
	showPage( child );
	maybeShow();
}

void KMdiDocumentViewTabWidget::addTab ( QWidget * child, const QIconSet & iconset, const QString & label )
{
	KTabWidget::addTab( child, iconset, label );
	showPage( child );
	maybeShow();
}

void KMdiDocumentViewTabWidget::addTab ( QWidget * child, QTab * tab )
{
	KTabWidget::addTab( child, tab );
	showPage( child );
	maybeShow();
}

void KMdiDocumentViewTabWidget::insertTab ( QWidget * child, const QString & label, int index )
{
	KTabWidget::insertTab( child, label, index );
	showPage( child );
	maybeShow();
	tabBar() ->repaint();
}

void KMdiDocumentViewTabWidget::insertTab ( QWidget * child, const QIconSet & iconset, const QString & label, int index )
{
	KTabWidget::insertTab( child, iconset, label, index );
	showPage( child );
	maybeShow();
	tabBar() ->repaint();
}

void KMdiDocumentViewTabWidget::insertTab ( QWidget * child, QTab * tab, int index )
{
	KTabWidget::insertTab( child, tab, index );
	showPage( child );
	maybeShow();
	tabBar() ->repaint();
}

void KMdiDocumentViewTabWidget::removePage ( QWidget * w )
{
	KTabWidget::removePage( w );
	maybeShow();
}

void KMdiDocumentViewTabWidget::updateIconInView( QWidget *w, QPixmap icon )
{
	changeTab( w, icon, tabLabel( w ) );
}

void KMdiDocumentViewTabWidget::updateCaptionInView( QWidget *w, const QString &caption )
{
	changeTab( w, caption );
}

void KMdiDocumentViewTabWidget::maybeShow()
{
	if ( m_visibility == KMdi::AlwaysShowTabs )
	{
		tabBar() ->show();
		if ( cornerWidget() )
		{
			if ( count() == 0 )
				cornerWidget() ->hide();
			else
				cornerWidget() ->show();
		}
	}

	if ( m_visibility == KMdi::ShowWhenMoreThanOneTab )
	{
		if ( count() < 2 )
			tabBar() ->hide();
		if ( count() > 1 )
			tabBar() ->show();
		if ( cornerWidget() )
		{
			if ( count() < 2 )
				cornerWidget() ->hide();
			else
				cornerWidget() ->show();
		}
	}

	if ( m_visibility == KMdi::NeverShowTabs )
	{
		tabBar() ->hide();
	}
}

void KMdiDocumentViewTabWidget::setTabWidgetVisibility( KMdi::TabWidgetVisibility visibility )
{
	m_visibility = visibility;
	maybeShow();
}

void KMdiDocumentViewTabWidget::moveTab( int from, int to )
{
  emit initiateTabMove( from, to );
  KTabWidget::moveTab( from, to );
}

KMdi::TabWidgetVisibility KMdiDocumentViewTabWidget::tabWidgetVisibility( )
{
	return m_visibility;
}


#ifndef NO_INCLUDE_MOCFILES
#include "kmdidocumentviewtabwidget.moc"
#endif

// kate: space-indent off; tab-width 4; replace-tabs off; indent-mode csands;


/**********************************************************************
** Copyright (C) 2000 Trolltech AS.  All rights reserved.
**
** This file is part of Qt Designer.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#include "formwindow.h"
#include "mainwindow.h"
#include "listvieweditorimpl.h"
#include "pixmapchooser.h"
#include "command.h"

#include <qlistview.h>
#include <qheader.h>
#include <qlistbox.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qtabwidget.h>
#include <qspinbox.h>
#include <qpushbutton.h>
#include <qptrstack.h>

#include <klocale.h>

ListViewEditor::ListViewEditor( QWidget *parent, QListView *lv, FormWindow *fw )
    : ListViewEditorBase( parent, 0, true ), listview( lv ), formwindow( fw )
{
    connect( helpButton, SIGNAL( clicked() ), MainWindow::self, SLOT( showDialogHelp() ) );
    itemText->setEnabled( false );
    itemChoosePixmap->setEnabled( false );
    itemDeletePixmap->setEnabled( false );
    itemColumn->setEnabled( false );

    setupColumns();
    PopulateListViewCommand::transferItems( listview, itemsPreview );
    setupItems();

    itemsPreview->setShowSortIndicator( listview->showSortIndicator() );
    itemsPreview->setAllColumnsShowFocus( listview->allColumnsShowFocus() );
    itemsPreview->setRootIsDecorated( listview->rootIsDecorated() );

    if ( itemsPreview->firstChild() ) {
	itemsPreview->setCurrentItem( itemsPreview->firstChild() );
	itemsPreview->setSelected( itemsPreview->firstChild(), true );
    }
}

void ListViewEditor::applyClicked()
{
    setupItems();
    PopulateListViewCommand *cmd = new PopulateListViewCommand( i18n("Edit Items and Columns of '%1'" ).arg( listview->name() ),
								formwindow, listview, itemsPreview );
    cmd->execute();
    formwindow->commandHistory()->addCommand( cmd );
}

void ListViewEditor::okClicked()
{
    applyClicked();
    accept();
}



void ListViewEditor::columnClickable( bool b )
{
    Column *c = findColumn( colPreview->item( colPreview->currentItem() ) );
    if ( !c )
	return;
    c->clickable = b;
}

void ListViewEditor::columnDownClicked()
{
    if ( colPreview->currentItem() == -1 ||
	 colPreview->currentItem() > (int)colPreview->count() - 2 )
	return;

    colPreview->clearSelection();
    QListBoxItem *i = colPreview->item( colPreview->currentItem() );
    QListBoxItem *below = i->next();

    colPreview->takeItem( i );
    colPreview->insertItem( i, below );

    colPreview->setCurrentItem( i );
    colPreview->setSelected( i, true );
}

void ListViewEditor::columnPixmapChosen()
{
    Column *c = findColumn( colPreview->item( colPreview->currentItem() ) );
    if ( !c )
	return;

    QPixmap pix;
    if ( colPixmap->pixmap() )
	pix = qChoosePixmap( this, formwindow, *colPixmap->pixmap() );
    else
	pix = qChoosePixmap( this, formwindow, QPixmap() );

    if ( pix.isNull() )
	return;

    c->pixmap = pix;
    colPreview->blockSignals( true );
    if ( !c->pixmap.isNull() )
	colPreview->changeItem( c->pixmap, c->text, colPreview->index( c->item ) );
    else
	colPreview->changeItem( c->text, colPreview->index( c->item ) );
    c->item = colPreview->item( colPreview->currentItem() );
    colPixmap->setPixmap( c->pixmap );
    colPreview->blockSignals( false );
    colDeletePixmap->setEnabled( true );
}

void ListViewEditor::columnPixmapDeleted()
{
    Column *c = findColumn( colPreview->item( colPreview->currentItem() ) );
    if ( !c )
	return;

    c->pixmap = QPixmap();
    colPreview->blockSignals( true );
    if ( !c->pixmap.isNull() )
	colPreview->changeItem( c->pixmap, c->text, colPreview->index( c->item ) );
    else
	colPreview->changeItem( c->text, colPreview->index( c->item ) );
    c->item = colPreview->item( colPreview->currentItem() );
    colPixmap->setText( "" );
    colPreview->blockSignals( false );
    colDeletePixmap->setEnabled( false );
}

void ListViewEditor::columnResizable( bool b )
{
    Column *c = findColumn( colPreview->item( colPreview->currentItem() ) );
    if ( !c )
	return;
    c->resizable = b;
}

void ListViewEditor::columnTextChanged( const QString &txt )
{
    Column *c = findColumn( colPreview->item( colPreview->currentItem() ) );
    if ( !c )
	return;

    c->text = txt;
    colPreview->blockSignals( true );
    if ( !c->pixmap.isNull() )
	colPreview->changeItem( c->pixmap, c->text, colPreview->index( c->item ) );
    else
	colPreview->changeItem( c->text, colPreview->index( c->item ) );
    c->item = colPreview->item( colPreview->currentItem() );
    colPreview->blockSignals( false );
}

void ListViewEditor::columnUpClicked()
{
    if ( colPreview->currentItem() <= 0 )
	return;

    colPreview->clearSelection();
    QListBoxItem *i = colPreview->item( colPreview->currentItem() );
    QListBoxItem *above = i->prev();

    colPreview->takeItem( above );
    colPreview->insertItem( above, i );

    colPreview->setCurrentItem( i );
    colPreview->setSelected( i, true );
}

void ListViewEditor::currentColumnChanged( QListBoxItem *i )
{
    Column *c = findColumn( i );
    if ( !i || !c ) {
	colText->setEnabled( false );
	colPixmap->setEnabled( false );
	colDeletePixmap->setEnabled( false );
	colText->blockSignals( true );
	colText->setText( "" );
	colText->blockSignals( false );
	colClickable->setEnabled( false );
	colResizeable->setEnabled( false );
	return;
    }

    colText->setEnabled( true );
    colPixmap->setEnabled( true );
    colDeletePixmap->setEnabled( i->pixmap() && !i->pixmap()->isNull() );
    colClickable->setEnabled( true );
    colResizeable->setEnabled( true );

    colText->blockSignals( true );
    colText->setText( c->text );
    colText->blockSignals( false );
    if ( !c->pixmap.isNull() )
	colPixmap->setPixmap( c->pixmap );
    else
	colPixmap->setText( "" );
    colClickable->setChecked( c->clickable );
    colResizeable->setChecked( c->resizable );
}

void ListViewEditor::newColumnClicked()
{
    Column col;
    col.text = i18n("New Column" );
    col.pixmap = QPixmap();
    col.clickable = true;
    col.resizable = true;
    if ( !col.pixmap.isNull() )
	col.item = new QListBoxPixmap( colPreview, col.pixmap, col.text );
    else
	col.item = new QListBoxText( colPreview, col.text );
    columns.append( col );
    colPreview->setCurrentItem( col.item );
    colPreview->setSelected( col.item, true );
}

void ListViewEditor::deleteColumnClicked()
{
    QListBoxItem *i = colPreview->item( colPreview->currentItem() );
    if ( !i )
	return;

    for ( QValueList<Column>::Iterator it = columns.begin(); it != columns.end(); ++it ) {
	if ( ( *it ).item == i ) {
	    delete (*it).item;
	    columns.remove( it );
	    break;
	}
    }

    if ( colPreview->currentItem() != -1 )
	colPreview->setSelected( colPreview->currentItem(), true );
}






void ListViewEditor::currentItemChanged( QListViewItem *i )
{
    if ( !i ) {
	itemText->setEnabled( false );
	itemChoosePixmap->setEnabled( false );
	itemDeletePixmap->setEnabled( false );
	itemColumn->setEnabled( false );
	return;
    }

    itemText->setEnabled( true );
    itemChoosePixmap->setEnabled( true );
    itemDeletePixmap->setEnabled( i->pixmap( itemColumn->value() ) &&
				  !i->pixmap( itemColumn->value() )->isNull() );
    itemColumn->setEnabled( true );

    displayItem( i, itemColumn->value() );
}

void ListViewEditor::displayItem( QListViewItem *i, int col )
{
    itemText->blockSignals( true );
    itemText->setText( i->text( col ) );
    itemText->blockSignals( false );

    itemPixmap->blockSignals( true );
    if ( i->pixmap( col ) )
	itemPixmap->setPixmap( *i->pixmap( col ) );
    else
	itemPixmap->setText( "" );
    itemPixmap->blockSignals( false );
}

void ListViewEditor::itemColChanged( int col )
{
    QListViewItem *i = itemsPreview->currentItem();
    if ( !i )
	return;

    displayItem( i, col );
    itemDeletePixmap->setEnabled( i->pixmap( col ) && !i->pixmap( col )->isNull() );
}

void ListViewEditor::itemDeleteClicked()
{
    QListViewItem *i = itemsPreview->currentItem();
    if ( !i )
	return;

    delete i;
    if ( itemsPreview->firstChild() ) {
	itemsPreview->setCurrentItem( itemsPreview->firstChild() );
	itemsPreview->setSelected( itemsPreview->firstChild(), true );
    }
}

void ListViewEditor::itemDownClicked()
{
    QListViewItem *i = itemsPreview->currentItem();
    if ( !i )
	return;

    QListViewItemIterator it( i );
    QListViewItem *parent = i->parent();
    it++;
    while ( it.current() ) {
	if ( it.current()->parent() == parent )
	    break;
	it++;
    }

    if ( !it.current() )
	return;
    QListViewItem *other = it.current();

    i->moveItem( other );
}

void ListViewEditor::itemNewClicked()
{
    QListViewItem *item = new QListViewItem( itemsPreview );
    item->setText( 0, "Item" );
    itemsPreview->setCurrentItem( item );
    itemsPreview->setSelected( item, true );
}

void ListViewEditor::itemNewSubClicked()
{
    QListViewItem *parent = itemsPreview->currentItem();
    QListViewItem *item = 0;
    if ( parent ) {
	item = new QListViewItem( parent );
	parent->setOpen( true );
    } else {
	item = new QListViewItem( itemsPreview );
    }
    item->setText( 0, "Subitem" );
    itemsPreview->setCurrentItem( item );
    itemsPreview->setSelected( item, true );
}

void ListViewEditor::itemPixmapChoosen()
{
    QListViewItem *i = itemsPreview->currentItem();
    if ( !i )
	return;

    QPixmap pix;
    if ( itemPixmap->pixmap() )
	pix = qChoosePixmap( this, formwindow, *itemPixmap->pixmap() );
    else
	pix = qChoosePixmap( this, formwindow, QPixmap() );

    if ( pix.isNull() )
	return;

    i->setPixmap( itemColumn->value(), QPixmap( pix ) );
    itemPixmap->setPixmap( pix );
    itemDeletePixmap->setEnabled( true );
}

void ListViewEditor::itemPixmapDeleted()
{
    QListViewItem *i = itemsPreview->currentItem();
    if ( !i )
	return;

    i->setPixmap( itemColumn->value(), QPixmap() );
    itemPixmap->setText( "" );
    itemDeletePixmap->setEnabled( false );
}

void ListViewEditor::itemTextChanged( const QString &txt )
{
    QListViewItem *i = itemsPreview->currentItem();
    if ( !i )
	return;
    i->setText( itemColumn->value(), txt );
}

void ListViewEditor::itemUpClicked()
{
    QListViewItem *i = itemsPreview->currentItem();
    if ( !i )
	return;

    QListViewItemIterator it( i );
    QListViewItem *parent = i->parent();
    --it;
    while ( it.current() ) {
	if ( it.current()->parent() == parent )
	    break;
	--it;
    }

    if ( !it.current() )
	return;
    QListViewItem *other = it.current();

    other->moveItem( i );
}

void ListViewEditor::itemRightClicked()
{
    QListViewItem *i = itemsPreview->currentItem();
    if ( !i )
	return;

    QListViewItemIterator it( i );
    QListViewItem *parent = i->parent();
    parent = parent ? parent->firstChild() : itemsPreview->firstChild();
    if ( !parent )
	return;
    it++;
    while ( it.current() ) {
	if ( it.current()->parent() == parent )
	    break;
	it++;
    }

    if ( !it.current() )
	return;
    QListViewItem *other = it.current();

    for ( int c = 0; c < itemsPreview->columns(); ++c ) {
	QString s = i->text( c );
	i->setText( c, other->text( c ) );
	other->setText( c, s );
	QPixmap pix;
	if ( i->pixmap( c ) )
	    pix = *i->pixmap( c );
	if ( other->pixmap( c ) )
	    i->setPixmap( c, *other->pixmap( c ) );
	else
	    i->setPixmap( c, QPixmap() );
	other->setPixmap( c, pix );
    }

    itemsPreview->setCurrentItem( other );
    itemsPreview->setSelected( other, true );
}

void ListViewEditor::itemLeftClicked()
{
    QListViewItem *i = itemsPreview->currentItem();
    if ( !i )
	return;

    QListViewItemIterator it( i );
    QListViewItem *parent = i->parent();
    if ( !parent )
	return;
    parent = parent->parent();
    --it;
    while ( it.current() ) {
	if ( it.current()->parent() == parent )
	    break;
	--it;
    }

    if ( !it.current() )
	return;
    QListViewItem *other = it.current();

    for ( int c = 0; c < itemsPreview->columns(); ++c ) {
	QString s = i->text( c );
	i->setText( c, other->text( c ) );
	other->setText( c, s );
	QPixmap pix;
	if ( i->pixmap( c ) )
	    pix = *i->pixmap( c );
	if ( other->pixmap( c ) )
	    i->setPixmap( c, *other->pixmap( c ) );
	else
	    i->setPixmap( c, QPixmap() );
	other->setPixmap( c, pix );
    }

    itemsPreview->setCurrentItem( other );
    itemsPreview->setSelected( other, true );
}

void ListViewEditor::setupColumns()
{
    QHeader *h = listview->header();
    for ( int i = 0; i < (int)h->count(); ++i ) {
	Column col;
	col.text = h->label( i );
	col.pixmap = QPixmap();
	if ( h->iconSet( i ) )
	    col.pixmap = h->iconSet( i )->pixmap();
	col.clickable = h->isClickEnabled( i );
	col.resizable = h->isResizeEnabled( i );
	if ( !col.pixmap.isNull() )
	    col.item = new QListBoxPixmap( colPreview, col.pixmap, col.text );
	else
	    col.item = new QListBoxText( colPreview, col.text );
	columns.append( col );
    }

    colText->setEnabled( false );
    colPixmap->setEnabled( false );
    colClickable->setEnabled( false );
    colResizeable->setEnabled( false );

    if ( colPreview->firstItem() )
	colPreview->setCurrentItem( colPreview->firstItem() );
    numColumns = colPreview->count();
}

void ListViewEditor::setupItems()
{
    itemColumn->setMinValue( 0 );
    itemColumn->setMaxValue( QMAX( numColumns - 1, 0 ) );
    int i = 0;
    QHeader *header = itemsPreview->header();
    for ( QListBoxItem *item = colPreview->firstItem(); item; item = item->next() ) {
	Column *col = findColumn( item );
	if ( !col )
	    continue;
	if ( i >= itemsPreview->columns() )
	    itemsPreview->addColumn( col->text );
	header->setLabel( i, col->pixmap, col->text );
	header->setResizeEnabled( col->resizable, i );
	header->setClickEnabled( col->clickable, i );
	++i;
    }
    while ( itemsPreview->columns() > i )
	itemsPreview->removeColumn( i );

    itemColumn->setValue( QMIN( numColumns - 1, itemColumn->value() ) );
}

ListViewEditor::Column *ListViewEditor::findColumn( QListBoxItem *i )
{
    if ( !i )
	return 0;

    for ( QValueList<Column>::Iterator it = columns.begin(); it != columns.end(); ++it ) {
	if ( ( *it ).item == i )
	    return &( *it );
    }

    return 0;
}

void ListViewEditor::initTabPage( const QString &page )
{
    numColumns = colPreview->count();
    if ( page == i18n("&Items" ) ) {
	setupItems();
	if ( numColumns == 0 ) {
	    itemNew->setEnabled( false );
	    itemNewSub->setEnabled( false );
	    itemText->setEnabled( false );
	    itemChoosePixmap->setEnabled( false );
	    itemDeletePixmap->setEnabled( false );
	    itemColumn->setEnabled( false );
	} else {
	    itemNew->setEnabled( true );
	    itemNewSub->setEnabled( true );
	}
    }
}
#include "listvieweditorimpl.moc"

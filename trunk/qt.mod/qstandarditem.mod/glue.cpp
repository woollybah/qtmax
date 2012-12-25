/*
  Copyright (c) 2009 Bruce A Henderson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/ 

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxQStandardItem::MaxQStandardItem(const QString & text)
	: dataHandle(0), QStandardItem(text)
{
	//qsibind(this, handle);
}

MaxQStandardItem::MaxQStandardItem(const QIcon & icon, const QString & text)
	: dataHandle(0), QStandardItem(icon, text)
{
	//qsibind(this, handle);
}

MaxQStandardItem::~MaxQStandardItem()
{
	if (dataHandle) {
		BBRELEASE(dataHandle);
		dataHandle = 0;
	}

	//qsiunbind(this);
}

int MaxQStandardItem::type() const{
	return QStandardItem::UserType + 73;
}

QVariant MaxQStandardItem::data(int role) const {
	if (role == Qt::UserRole + 1) {
		
		if (dataHandle) {
			QVariant v(QMetaType::VoidStar, (void*)dataHandle);
			return v;
		} else {
			QVariant v(QMetaType::VoidStar, (void*)&bbNullObject);
			return v;
		}
		
	} else {
		return QStandardItem::data(role);
	}
}

void MaxQStandardItem::setData(const QVariant & value, int role) {
	if (role == Qt::UserRole + 1) {
		// release old data
		if (dataHandle) {
			BBRELEASE(dataHandle);
		}
	
		// set new data
		dataHandle = (BBObject * )qvariant_cast<void *>(value);
		
	} else {
		QStandardItem::setData(value, role);
	}
}

// *********************************************

typedef std::map<MaxQStandardItem*, BBObject*> QStandardItemPeerMap;

static QStandardItemPeerMap qQStandardItemPeerMap;

void qsibind( MaxQStandardItem *obj, BBObject *peer ) {
	if( !obj || peer==&bbNullObject ) return;
	qQStandardItemPeerMap.insert( std::make_pair( obj,peer ) );
	BBRETAIN( peer );
}

BBObject *qsifind( MaxQStandardItem *obj ){
	if( !obj ) return &bbNullObject;
	QStandardItemPeerMap::iterator it = qQStandardItemPeerMap.find( obj );
	if( it != qQStandardItemPeerMap.end() ) return it->second;
	return &bbNullObject;
}

void qsiunbind(MaxQStandardItem *obj) {
	BBObject * peer = qsifind(obj);
	if (peer != &bbNullObject) {
		qQStandardItemPeerMap.erase(obj);
		//_qt_qstandarditem_QStandardItem__Free(peer);
		BBRELEASE(peer);
	}
}

// *********************************************

QStandardItem * bmx_qt_qstandarditem_create(BBString * text, MaxQIcon * icon) {
	if (icon) {
		return new MaxQStandardItem(icon->Icon(), qStringFromBBString(text));
	} else {
		return new MaxQStandardItem(qStringFromBBString(text));
	}
}

BBString * bmx_qt_qstandarditem_accessibledescription(QStandardItem * standardItem) {
	return bbStringFromQString(standardItem->accessibleDescription());
}

BBString * bmx_qt_qstandarditem_accessibletext(QStandardItem * standardItem) {
	return bbStringFromQString(standardItem->accessibleText());
}

void bmx_qt_qstandarditem_appendrow(QStandardItem * standardItem, QStandardItem * item) {
	standardItem->appendRow(item);
}

int bmx_qt_qstandarditem_checkstate(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->checkState());
}

int bmx_qt_qstandarditem_column(QStandardItem * standardItem) {
	return standardItem->column();
}

int bmx_qt_qstandarditem_columncount(QStandardItem * standardItem) {
	return standardItem->columnCount();
}

BBObject * bmx_qt_qstandarditem_data(QStandardItem * standardItem) {
	return (BBObject * )qvariant_cast<void *>(standardItem->data(Qt::UserRole + 1));
}

int bmx_qt_qstandarditem_flags(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->flags());
}

int bmx_qt_qstandarditem_haschildren(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->hasChildren());
}

void bmx_qt_qstandarditem_insertrow(QStandardItem * standardItem, int row, QStandardItem * item) {
	standardItem->insertRow(row, item);
}

void bmx_qt_qstandarditem_insertrows(QStandardItem * standardItem, int row, int count) {
	standardItem->insertRows(row, count);
}

int bmx_qt_qstandarditem_ischeckable(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->isCheckable());
}

int bmx_qt_qstandarditem_isdragenabled(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->isDragEnabled());
}

int bmx_qt_qstandarditem_isdropenabled(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->isDropEnabled());
}

int bmx_qt_qstandarditem_iseditable(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->isEditable());
}

int bmx_qt_qstandarditem_isenabled(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->isEnabled());
}

int bmx_qt_qstandarditem_isselectable(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->isSelectable());
}

int bmx_qt_qstandarditem_istristate(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->isTristate());
}

void bmx_qt_qstandarditem_removecolumn(QStandardItem * standardItem, int column) {
	standardItem->removeColumn(column);
}

void bmx_qt_qstandarditem_removecolumns(QStandardItem * standardItem, int column, int count) {
	standardItem->removeColumns(column, count);
}

void bmx_qt_qstandarditem_removerow(QStandardItem * standardItem, int row) {
	standardItem->removeRow(row);
}

void bmx_qt_qstandarditem_removerows(QStandardItem * standardItem, int row, int count) {
	standardItem->removeRows(row, count);
}

int bmx_qt_qstandarditem_row(QStandardItem * standardItem) {
	return standardItem->row();
}

int bmx_qt_qstandarditem_rowcount(QStandardItem * standardItem) {
	return standardItem->rowCount();
}

void bmx_qt_qstandarditem_setaccessibledescription(QStandardItem * standardItem, BBString * accessibleDescription) {
	standardItem->setAccessibleDescription(qStringFromBBString(accessibleDescription));
}

void bmx_qt_qstandarditem_setaccessibletext(QStandardItem * standardItem, BBString * accessibleText) {
	standardItem-> setAccessibleText(qStringFromBBString(accessibleText));
}

void bmx_qt_qstandarditem_setcheckstate(QStandardItem * standardItem, int state) {
	standardItem->setCheckState(bmx_qt_getcheckstate(state));
}

void bmx_qt_qstandarditem_setcheckable(QStandardItem * standardItem, int checkable) {
	standardItem->setCheckable(static_cast<bool>(checkable));
}

void bmx_qt_qstandarditem_setchildrc(QStandardItem * standardItem, int row, int column, QStandardItem * item) {
	standardItem->setChild(row, column, item);
}

void bmx_qt_qstandarditem_setchild(QStandardItem * standardItem, int row, QStandardItem * item) {
	standardItem->setChild(row, item);
}

void bmx_qt_qstandarditem_setcolumncount(QStandardItem * standardItem, int columns) {
	standardItem->setColumnCount(columns);
}

void bmx_qt_qstandarditem_setdata(QStandardItem * standardItem, BBObject * value) {
	QVariant v(QMetaType::VoidStar, (void*)value);
	standardItem->setData(v, Qt::UserRole + 1);
}

void bmx_qt_qstandarditem_setdragenabled(QStandardItem * standardItem, int dragEnabled) {
	standardItem->setDragEnabled(static_cast<bool>(dragEnabled));
}

void bmx_qt_qstandarditem_setdropenabled(QStandardItem * standardItem, int dropEnabled) {
	standardItem->setDropEnabled(static_cast<bool>(dropEnabled));
}

void bmx_qt_qstandarditem_seteditable(QStandardItem * standardItem, int editable) {
	standardItem->setEditable(static_cast<bool>(editable));
}

void bmx_qt_qstandarditem_setenabled(QStandardItem * standardItem, int enabled) {
	standardItem->setEnabled(static_cast<bool>(enabled));
}

void bmx_qt_qstandarditem_setflags(QStandardItem * standardItem, int flags) {
	standardItem->setFlags(bmx_qt_getitemflags(flags));
}

void bmx_qt_qstandarditem_setrowcount(QStandardItem * standardItem, int rows) {
	standardItem->setRowCount(rows);
}

void bmx_qt_qstandarditem_setselectable(QStandardItem * standardItem, int selectable) {
	standardItem->setSelectable(static_cast<bool>(selectable));
}

void bmx_qt_qstandarditem_setsizehint(QStandardItem * standardItem, int width, int height) {
	standardItem->setSizeHint(QSize(width, height));
}

void bmx_qt_qstandarditem_setstatustip(QStandardItem * standardItem, BBString * statustip) {
	standardItem->setStatusTip(qStringFromBBString(statustip));
}

void bmx_qt_qstandarditem_settext(QStandardItem * standardItem, BBString * text) {
	standardItem->setText(qStringFromBBString(text));
}

void bmx_qt_qstandarditem_settextalignment(QStandardItem * standardItem, int alignment) {
	standardItem->setTextAlignment(bmx_qt_getalignment(alignment));
}

void bmx_qt_qstandarditem_settooltip(QStandardItem * standardItem, BBString * toolTip) {
	standardItem->setToolTip(qStringFromBBString(toolTip));
}

void bmx_qt_qstandarditem_settristate(QStandardItem * standardItem, int tristate) {
	standardItem->setTristate(static_cast<bool>(tristate));
}

void bmx_qt_qstandarditem_setwhatsthis(QStandardItem * standardItem, BBString * whatsThis) {
	standardItem->setWhatsThis(qStringFromBBString(whatsThis));
}

BBString * bmx_qt_qstandarditem_statustip(QStandardItem * standardItem) {
	return bbStringFromQString(standardItem->statusTip());
}

BBString * bmx_qt_qstandarditem_text(QStandardItem * standardItem) {
	return bbStringFromQString(standardItem->text());
}

int bmx_qt_qstandarditem_textalignment(QStandardItem * standardItem) {
	return static_cast<int>(standardItem->textAlignment());
}

BBString * bmx_qt_qstandarditem_tooltip(QStandardItem * standardItem) {
	return bbStringFromQString(standardItem->toolTip());
}

int bmx_qt_qstandarditem_type(QStandardItem * standardItem) {
	return standardItem->type();
}

BBString * bmx_qt_qstandarditem_whatsthis(QStandardItem * standardItem) {
	return bbStringFromQString(standardItem->whatsThis());
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

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

#ifndef MAX_QT_QSTANDARDITEM
#define MAX_QT_QSTANDARDITEM

#include "../core.mod/glue.h"
#include "../qicon.mod/glue.h"
#include <QtCore>
#include <QStandardItem>

class MaxQStandardItem;

extern "C" {

#include <blitz.h>

	void qsibind( MaxQStandardItem *obj, BBObject *peer );
	BBObject *qsifind( MaxQStandardItem *obj );
	void qsiunbind(MaxQStandardItem *obj);

	//void _qt_qstandarditem_QStandardItem__Free(BBObject * handle);

	QStandardItem * bmx_qt_qstandarditem_create(BBString * text, MaxQIcon * icon);
	BBString * bmx_qt_qstandarditem_accessibledescription(QStandardItem * standardItem);
	BBString * bmx_qt_qstandarditem_accessibletext(QStandardItem * standardItem);
	void bmx_qt_qstandarditem_appendrow(QStandardItem * standardItem, QStandardItem * item);
	int bmx_qt_qstandarditem_checkstate(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_column(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_columncount(QStandardItem * standardItem);
	BBObject * bmx_qt_qstandarditem_data(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_flags(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_haschildren(QStandardItem * standardItem);
	void bmx_qt_qstandarditem_insertrow(QStandardItem * standardItem, int row, QStandardItem * item);
	void bmx_qt_qstandarditem_insertrows(QStandardItem * standardItem, int row, int count);
	int bmx_qt_qstandarditem_ischeckable(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_isdragenabled(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_isdropenabled(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_iseditable(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_isenabled(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_isselectable(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_istristate(QStandardItem * standardItem);
	void bmx_qt_qstandarditem_removecolumn(QStandardItem * standardItem, int column);
	void bmx_qt_qstandarditem_removecolumns(QStandardItem * standardItem, int column, int count);
	void bmx_qt_qstandarditem_removerow(QStandardItem * standardItem, int row);
	void bmx_qt_qstandarditem_removerows(QStandardItem * standardItem, int row, int count);
	int bmx_qt_qstandarditem_row(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_rowcount(QStandardItem * standardItem);
	void bmx_qt_qstandarditem_setaccessibledescription(QStandardItem * standardItem, BBString * accessibleDescription);
	void bmx_qt_qstandarditem_setaccessibletext(QStandardItem * standardItem, BBString * accessibleText);
	void bmx_qt_qstandarditem_setcheckstate(QStandardItem * standardItem, int state);
	void bmx_qt_qstandarditem_setcheckable(QStandardItem * standardItem, int checkable);
	void bmx_qt_qstandarditem_setchildrc(QStandardItem * standardItem, int row, int column, QStandardItem * item);
	void bmx_qt_qstandarditem_setchild(QStandardItem * standardItem, int row, QStandardItem * item);
	void bmx_qt_qstandarditem_setcolumncount(QStandardItem * standardItem, int columns);
	void bmx_qt_qstandarditem_setdata(QStandardItem * standardItem, BBObject * value);
	void bmx_qt_qstandarditem_setdragenabled(QStandardItem * standardItem, int dragEnabled);
	void bmx_qt_qstandarditem_setdropenabled(QStandardItem * standardItem, int dropEnabled);
	void bmx_qt_qstandarditem_seteditable(QStandardItem * standardItem, int editable);
	void bmx_qt_qstandarditem_setenabled(QStandardItem * standardItem, int enabled);
	void bmx_qt_qstandarditem_setflags(QStandardItem * standardItem, int flags);
	void bmx_qt_qstandarditem_setrowcount(QStandardItem * standardItem, int rows);
	void bmx_qt_qstandarditem_setselectable(QStandardItem * standardItem, int selectable);
	void bmx_qt_qstandarditem_setsizehint(QStandardItem * standardItem, int width, int height);
	void bmx_qt_qstandarditem_setstatustip(QStandardItem * standardItem, BBString * statustip);
	void bmx_qt_qstandarditem_settext(QStandardItem * standardItem, BBString * text);
	void bmx_qt_qstandarditem_settextalignment(QStandardItem * standardItem, int alignment);
	void bmx_qt_qstandarditem_settooltip(QStandardItem * standardItem, BBString * toolTip);
	void bmx_qt_qstandarditem_settristate(QStandardItem * standardItem, int tristate);
	void bmx_qt_qstandarditem_setwhatsthis(QStandardItem * standardItem, BBString * whatsThis);
	BBString * bmx_qt_qstandarditem_statustip(QStandardItem * standardItem);
	BBString * bmx_qt_qstandarditem_text(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_textalignment(QStandardItem * standardItem);
	BBString * bmx_qt_qstandarditem_tooltip(QStandardItem * standardItem);
	int bmx_qt_qstandarditem_type(QStandardItem * standardItem);
	BBString * bmx_qt_qstandarditem_whatsthis(QStandardItem * standardItem);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQStandardItem : public QStandardItem
{
public:

	MaxQStandardItem(const QString & text);
	MaxQStandardItem(const QIcon & icon, const QString & text);
	
	~MaxQStandardItem();

	virtual int type() const;
	virtual QVariant data(int role = Qt::UserRole + 1) const;
	virtual void setData(const QVariant & value, int role = Qt::UserRole + 1);

	virtual MaxQStandardItem *clone() const;
	
private:
	BBObject * dataHandle;
};

#endif

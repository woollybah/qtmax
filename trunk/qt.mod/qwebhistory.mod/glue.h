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

#ifndef MAX_QT_QWEBHISTORY
#define MAX_QT_QWEBHISTORY

#include "../core.mod/glue.h"
#include <QtCore>
#include <QWebHistory>

class MaxQWebHistory;
class MaxQWebHistoryItem;

extern "C" {

#include <blitz.h>

	BBArray * _qt_qwebhistory_QWebHistory__newItems(int size);
	void _qt_qwebhistory_QWebHistory__setItem(BBArray * items, int index, MaxQWebHistoryItem * item);

	void bmx_qt_qwebhistory_back(MaxQWebHistory * history);
	MaxQWebHistoryItem * bmx_qt_qwebhistory_backitem(MaxQWebHistory * history);
	int bmx_qt_qwebhistory_cangoback(MaxQWebHistory * history);
	int bmx_qt_qwebhistory_cangoforward(MaxQWebHistory * history);
	void bmx_qt_qwebhistory_clear(MaxQWebHistory * history);
	int bmx_qt_qwebhistory_count(MaxQWebHistory * history);
	MaxQWebHistoryItem * bmx_qt_qwebhistory_currentitem(MaxQWebHistory * history);
	int bmx_qt_qwebhistory_currentitemindex(MaxQWebHistory * history);
	void bmx_qt_qwebhistory_forward(MaxQWebHistory * history);
	MaxQWebHistoryItem * bmx_qt_qwebhistory_forwarditem(MaxQWebHistory * history);
	void bmx_qt_qwebhistory_gotoitem(MaxQWebHistory * history, MaxQWebHistoryItem * item);
	MaxQWebHistoryItem * bmx_qt_qwebhistory_itemat(MaxQWebHistory * history, int index);
	int bmx_qt_qwebhistory_maximumitemcount(MaxQWebHistory * history);
	void bmx_qt_qwebhistory_setmaximumitemcount(MaxQWebHistory * history, int count);
	void bmx_qt_qwebhistory_free(MaxQWebHistory * history);

	BBArray * bmx_qt_qwebhistory_backitems(MaxQWebHistory * history, int maxItems);
	BBArray * bmx_qt_qwebhistory_forwarditems(MaxQWebHistory * history, int maxItems);
	BBArray * bmx_qt_qwebhistory_items(MaxQWebHistory * history);

	void bmx_qt_qwebhistoryitem_free(MaxQWebHistoryItem * item);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQWebHistory
{
public:
	MaxQWebHistory(QWebHistory h);
	~MaxQWebHistory();
	
	QWebHistory & History();

private:
	QWebHistory & history;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQWebHistoryItem
{
public:
	MaxQWebHistoryItem(QWebHistoryItem i);
	~MaxQWebHistoryItem();
	
	QWebHistoryItem & Item();

private:
	QWebHistoryItem & item;
};

#endif

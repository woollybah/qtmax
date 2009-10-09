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

MaxQWebHistory::MaxQWebHistory(QWebHistory h)
	: history(h)
{
}

MaxQWebHistory::~MaxQWebHistory()
{
}

QWebHistory & MaxQWebHistory::History() {
	return history;
}

// ---------------------------------------------------------------------------------------

MaxQWebHistoryItem::MaxQWebHistoryItem(QWebHistoryItem i)
	: item(i)
{
}

MaxQWebHistoryItem::~MaxQWebHistoryItem()
{
}

QWebHistoryItem & MaxQWebHistoryItem::Item() {
	return item;
}

// *********************************************

void bmx_qt_qwebhistory_back(MaxQWebHistory * history) {
	history->History().back();
}

MaxQWebHistoryItem * bmx_qt_qwebhistory_backitem(MaxQWebHistory * history) {
	return new MaxQWebHistoryItem(history->History().backItem());
}

int bmx_qt_qwebhistory_cangoback(MaxQWebHistory * history) {
	return static_cast<int>(history->History().canGoBack());
}

int bmx_qt_qwebhistory_cangoforward(MaxQWebHistory * history) {
	return static_cast<int>(history->History().canGoForward());
}

void bmx_qt_qwebhistory_clear(MaxQWebHistory * history) {
	history->History().clear();
}

int bmx_qt_qwebhistory_count(MaxQWebHistory * history) {
	return history->History().count();
}

MaxQWebHistoryItem * bmx_qt_qwebhistory_currentitem(MaxQWebHistory * history) {
	return new MaxQWebHistoryItem(history->History().currentItem());
}

int bmx_qt_qwebhistory_currentitemindex(MaxQWebHistory * history) {
	return history->History().currentItemIndex();
}

void bmx_qt_qwebhistory_forward(MaxQWebHistory * history) {
	history->History().forward();
}

MaxQWebHistoryItem * bmx_qt_qwebhistory_forwarditem(MaxQWebHistory * history) {
	return new MaxQWebHistoryItem(history->History().forwardItem());
}

void bmx_qt_qwebhistory_gotoitem(MaxQWebHistory * history, MaxQWebHistoryItem * item) {
	history->History().goToItem(item->Item());
}

MaxQWebHistoryItem * bmx_qt_qwebhistory_itemat(MaxQWebHistory * history, int index) {
	return new MaxQWebHistoryItem(history->History().itemAt(index));
}

int bmx_qt_qwebhistory_maximumitemcount(MaxQWebHistory * history) {
	return history->History().maximumItemCount();
}

void bmx_qt_qwebhistory_setmaximumitemcount(MaxQWebHistory * history, int count) {
	history->History().setMaximumItemCount(count);
}

void bmx_qt_qwebhistory_free(MaxQWebHistory * history) {
	delete history;
}

BBArray * bbArrayFromQWebHistoryItemList(QList<QWebHistoryItem> list) {
	int n = list.count();
	BBArray * arr = _qt_qwebhistory_QWebHistory__newItems(n);
	if (n > 0) {
		for( int i=0; i < n ;++i ) {
			_qt_qwebhistory_QWebHistory__setItem(arr, i, new MaxQWebHistoryItem(list[i]));
		}
	}

	return arr;
}

BBArray * bmx_qt_qwebhistory_backitems(MaxQWebHistory * history, int maxItems) {
	return bbArrayFromQWebHistoryItemList(history->History().backItems(maxItems));	
}

BBArray * bmx_qt_qwebhistory_forwarditems(MaxQWebHistory * history, int maxItems) {
	return bbArrayFromQWebHistoryItemList(history->History().forwardItems(maxItems));
}

BBArray * bmx_qt_qwebhistory_items(MaxQWebHistory * history) {
	return bbArrayFromQWebHistoryItemList(history->History().items());
}


// *********************************************

void bmx_qt_qwebhistoryitem_free(MaxQWebHistoryItem * item) {
	delete item;
}

MaxQIcon * bmx_qt_qwebhistoryitem_icon(MaxQWebHistoryItem * item) {
	return new MaxQIcon(item->Item().icon());
}

int bmx_qt_qwebhistoryitem_isvalid(MaxQWebHistoryItem * item) {
	return static_cast<int>(item->Item().isValid());
}

MaxQDateTime * bmx_qt_qwebhistoryitem_lastvisited(MaxQWebHistoryItem * item) {
	return new MaxQDateTime(item->Item().lastVisited());
}

MaxQUrl * bmx_qt_qwebhistoryitem_originalurl(MaxQWebHistoryItem * item) {
	return new MaxQUrl(item->Item().originalUrl());
}

BBString * bmx_qt_qwebhistoryitem_title(MaxQWebHistoryItem * item) {
	return bbStringFromQString(item->Item().title());
}

MaxQUrl * bmx_qt_qwebhistoryitem_url(MaxQWebHistoryItem * item) {
	return new MaxQUrl(item->Item().url());
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

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
//#include <QStandardItem>

class MaxQStandardItem;

extern "C" {

#include <blitz.h>


	int _qt_qstandarditem_QStandardItem__columnCount(BBObject * handle);
	int _qt_qstandarditem_QStandardItem__rowCount(BBObject * handle);
	BBObject * bmx_qt_qstandarditem_casttoobj(MaxQStandardItem * item);


	MaxQStandardItem * bmx_qt_qstandarditem_create(BBObject * handle);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQStandardItem
{
public:

	MaxQStandardItem(BBObject * handle);
	
	~MaxQStandardItem();

	int rowCount();
	int columnCount();
	
	BBObject * handle() {
		return maxHandle;
	}
	
private:
	BBObject * maxHandle;
};

#endif

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

#ifndef MAX_QT_QMENUBAR
#define MAX_QT_QMENUBAR

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qmenu.mod/glue.h"
#include <QtCore>
#include <QMenuBar>

class MaxQMenuBar;

extern "C" {

#include <blitz.h>

	QMenuBar * bmx_qt_qmenubar_create(BBObject * handle, QWidget * parent);
	QAction * bmx_qt_qmenubar_activeaction(QMenuBar * mb);
	QAction * bmx_qt_qmenubar_adaction(QMenuBar * mb, QAction * action);
	QAction * bmx_qt_qmenubar_adactiontxt(QMenuBar * mb, BBString *action);
	QAction * bmx_qt_qmenubar_addmenu(QMenuBar * mb, QMenu * menu);
	QMenu * bmx_qt_qmenubar_addmenutxt(QMenuBar * mb, BBString * menu);
	QAction * bmx_qt_qmenubar_addseparator(QMenuBar * mb);
	void bmx_qt_qmenubar_clear(QMenuBar * mb);
	QAction * bmx_qt_qmenubar_insertmenu(QMenuBar * mb, QAction * before, QMenu * menu);
	QAction * bmx_qt_qmenubar_insertSeparator(QMenuBar * mb, QAction * before);
	int bmx_qt_qmenubar_isdefaultup(QMenuBar * mb);
	void bmx_qt_qmenubar_setactiveaction(QMenuBar * mb, QAction * act);
	void bmx_qt_qmenubar_setdefaultup(QMenuBar * mb, int value);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQMenuBar : public QMenuBar
{
public:
	MaxQMenuBar(BBObject * handle, QWidget * parent);
	~MaxQMenuBar();

private:
	BBObject * maxHandle;
	
};

#endif

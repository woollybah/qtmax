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

#ifndef MAX_QT_QCOMBOBOX
#define MAX_QT_QCOMBOBOX

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QComboBox>

class MaxQComboBox;

extern "C" {

#include <blitz.h>

	void _qt_qcombobox_QComboBox__OnActivated(BBObject * handle, int index);
	void _qt_qcombobox_QComboBox__OnCurrentIndexChanged(BBObject * handle, int index);
	void _qt_qcombobox_QComboBox__OnEditTextChanged(BBObject * handle, BBString * text);
	void _qt_qcombobox_QComboBox__OnHighlighted(BBObject * handle, int index);

	QComboBox * bmx_qt_qcombobox_create(BBObject * handle, QWidget * parent);
	void bmx_qt_qcombobox_addItem(QComboBox * cb, BBString * text, BBObject * data);
	void bmx_qt_qcombobox_addItems(QComboBox * cb, BBArray * texts);
	int bmx_qt_qcombobox_count(QComboBox * cb);
	int bmx_qt_qcombobox_currentindex(QComboBox * cb);
	void bmx_qt_qcombobox_insertitem(QComboBox * cb, int index, BBString * text, BBInt64 itemId);
	BBObject * bmx_qt_qcombobox_itemdata(QComboBox * cb, int index);
	void bmx_qt_qcombobox_removeitem(QComboBox * cb, int index);
	void bmx_qt_qcombobox_setitemdata(QComboBox * cb, int index, BBObject * data);
	BBString * bmx_qt_qcombobox_currenttext(QComboBox * cb);
	int bmx_qt_qcombobox_findtext(QComboBox * cb, BBString * text, int flags);
	void bmx_qt_qcombobox_setcurrentindex(QComboBox * cb, int index);
	int bmx_qt_qcombobox_duplicatesenabled(QComboBox * cb);
	int bmx_qt_qcombobox_hasframe(QComboBox * cb);
	void bmx_qt_qcombobox_hidepopup(QComboBox * cb);
	void bmx_qt_qcombobox_setmodel(QComboBox * cb, QAbstractItemModel * model);
	BBString * bmx_qt_qcombobox_itemtext(QComboBox * cb, int index);
	int bmx_qt_qcombobox_maxcount(QComboBox * cb);
	int bmx_qt_qcombobox_maxvisibleitems(QComboBox * cb);
	int bmx_qt_qcombobox_minimumcontentslength(QComboBox * cb);
	int bmx_qt_qcombobox_modelcolumn(QComboBox * cb);
	void bmx_qt_qcombobox_setduplicatesenabled(QComboBox * cb, int enable);
	void bmx_qt_qcombobox_seteditable(QComboBox * cb, int editable);
	void bmx_qt_qcombobox_setframe(QComboBox * cb, int value);
	void bmx_qt_qcombobox_seticonsize(QComboBox * cb, int w, int h);
	void bmx_qt_qcombobox_setinsertpolicy(QComboBox * cb, int policy);

	// QComboBox
	// QWidget
	void bmx_qt_qcombobox_default_actionevent(MaxQComboBox * combo, QActionEvent * event);
	void bmx_qt_qcombobox_default_changeevent(MaxQComboBox * combo, QEvent * event);
	void bmx_qt_qcombobox_default_closeevent(MaxQComboBox * combo, QCloseEvent * event);
	void bmx_qt_qcombobox_default_contextmenuevent(MaxQComboBox * combo, QContextMenuEvent * event);
	void bmx_qt_qcombobox_default_dragenterevent(MaxQComboBox * combo, QDragEnterEvent * event);
	void bmx_qt_qcombobox_default_dragleaveevent(MaxQComboBox * combo, QDragLeaveEvent * event);
	void bmx_qt_qcombobox_default_dragmoveevent(MaxQComboBox * combo, QDragMoveEvent * event);
	void bmx_qt_qcombobox_default_dropevent(MaxQComboBox * combo, QDropEvent * event);
	void bmx_qt_qcombobox_default_enterevent(MaxQComboBox * combo, QEvent * event);
	void bmx_qt_qcombobox_default_focusinevent(MaxQComboBox * combo, QFocusEvent * event);
	int bmx_qt_qcombobox_default_focusnextprevchild(MaxQComboBox * combo, int next);
	int bmx_qt_qcombobox_default_focusnextchild(MaxQComboBox * combo);
	void bmx_qt_qcombobox_default_focusoutevent(MaxQComboBox * combo, QFocusEvent * event);
	int bmx_qt_qcombobox_default_focuspreviouschild(MaxQComboBox * combo);
	void bmx_qt_qcombobox_default_hideevent(MaxQComboBox * combo, QHideEvent * event);
	void bmx_qt_qcombobox_default_inputmethodevent(MaxQComboBox * combo, QInputMethodEvent * event);
	void bmx_qt_qcombobox_default_keypressevent(MaxQComboBox * combo, QKeyEvent * event);
	void bmx_qt_qcombobox_default_keyreleaseevent(MaxQComboBox * combo, QKeyEvent * event);
	void bmx_qt_qcombobox_default_leaveevent(MaxQComboBox * combo, QEvent * event);
	void bmx_qt_qcombobox_default_mousedoubleclickevent(MaxQComboBox * combo, QMouseEvent * event);
	void bmx_qt_qcombobox_default_mousemoveevent(MaxQComboBox * combo, QMouseEvent * event);
	void bmx_qt_qcombobox_default_mousepressevent(MaxQComboBox * combo, QMouseEvent * event);
	void bmx_qt_qcombobox_default_mousereleaseevent(MaxQComboBox * combo, QMouseEvent * event);
	void bmx_qt_qcombobox_default_moveevent(MaxQComboBox * combo, QMoveEvent * event);
	void bmx_qt_qcombobox_default_paintevent(MaxQComboBox * combo, QPaintEvent * event);
	void bmx_qt_qcombobox_default_resizeevent(MaxQComboBox * combo, QResizeEvent * event);
	void bmx_qt_qcombobox_default_showevent(MaxQComboBox * combo, QShowEvent * event);
	void bmx_qt_qcombobox_default_tabletevent(MaxQComboBox * combo, QTabletEvent * event);
	void bmx_qt_qcombobox_default_wheelevent(MaxQComboBox * combo, QWheelEvent * event);
	// QObject
	int bmx_qt_qcombobox_default_event(MaxQComboBox * combo, QEvent * event);
	void bmx_qt_qcombobox_default_timerevent(MaxQComboBox * combo, QTimerEvent * event);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQComboBox : public QComboBox
{
	Q_OBJECT

public:
	MaxQComboBox(BBObject * handle, QWidget * parent);
	~MaxQComboBox();

private:
	BBObject * maxHandle;

private slots:
	void onActivated(int index);
	void onCurrentIndexChanged(int index);
	void onEditTextChanged(const QString & text);
	void onHighlighted(int index);
	
	void onCustomContextMenuRequested(const QPoint & pos);

public:
	// QComboBox
	// QWidget
	void defaultactionEvent(QActionEvent * event);
	void defaultchangeEvent(QEvent * event);
	void defaultcloseEvent(QCloseEvent * event);
	void defaultcontextMenuEvent(QContextMenuEvent * event);
	void defaultdragEnterEvent(QDragEnterEvent * event);
	void defaultdragLeaveEvent(QDragLeaveEvent * event);
	void defaultdragMoveEvent(QDragMoveEvent * event);
	void defaultdropEvent(QDropEvent * event);
	void defaultenterEvent(QEvent * event);
	void defaultfocusInEvent(QFocusEvent * event);
	bool defaultfocusNextChild ();
	bool defaultfocusNextPrevChild(bool next);
	void defaultfocusOutEvent(QFocusEvent * event);
	bool defaultfocusPreviousChild();
	void defaulthideEvent(QHideEvent * event);
	void defaultinputMethodEvent(QInputMethodEvent * event);
	void defaultkeyPressEvent(QKeyEvent * event);
	void defaultkeyReleaseEvent(QKeyEvent * event);
	void defaultleaveEvent(QEvent * event);
	void defaultmouseDoubleClickEvent(QMouseEvent * event);
	void defaultmouseMoveEvent(QMouseEvent * event);
	void defaultmousePressEvent(QMouseEvent * event);
	void defaultmouseReleaseEvent(QMouseEvent * event);
	void defaultmoveEvent(QMoveEvent * event);
	void defaultpaintEvent(QPaintEvent * event);
	void defaultresizeEvent(QResizeEvent * event);
	void defaultshowEvent(QShowEvent * event);
	void defaulttabletEvent(QTabletEvent * event);
	void defaultwheelEvent(QWheelEvent * event);
	// QObject
	bool defaultevent(QEvent * event);
	void defaulttimerEvent(QTimerEvent * event);

protected:
	// QComboBox
	// QWidget
	virtual void actionEvent(QActionEvent * event);
	virtual void changeEvent(QEvent * event);
	virtual void closeEvent(QCloseEvent * event);
	virtual void contextMenuEvent(QContextMenuEvent * event);
	virtual void dragEnterEvent(QDragEnterEvent * event);
	virtual void dragLeaveEvent(QDragLeaveEvent * event);
	virtual void dragMoveEvent(QDragMoveEvent * event);
	virtual void dropEvent(QDropEvent * event);
	virtual void enterEvent(QEvent * event);
	virtual void focusInEvent(QFocusEvent * event);
	bool focusNextChild();
	virtual bool focusNextPrevChild(bool next);
	virtual void focusOutEvent(QFocusEvent * event);
	bool focusPreviousChild();
	virtual void hideEvent(QHideEvent * event);
	virtual void inputMethodEvent(QInputMethodEvent * event);
	virtual void leaveEvent(QEvent * event);
	virtual void keyPressEvent(QKeyEvent * event);
	virtual void keyReleaseEvent(QKeyEvent * event);
	virtual void mouseDoubleClickEvent(QMouseEvent * event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual void moveEvent(QMoveEvent * event);
	virtual void paintEvent(QPaintEvent * event);
	virtual void resizeEvent(QResizeEvent * event);
	virtual void showEvent(QShowEvent * event);
	virtual void tabletEvent(QTabletEvent * event);
	virtual void wheelEvent(QWheelEvent * event);
	// QObject
	virtual bool event(QEvent * event);
	virtual void timerEvent(QTimerEvent * event);
};

#endif

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

MaxQMessageBox::MaxQMessageBox(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QMessageBox(parent)
{
	qbind(this, handle);
	
	connect(this, SIGNAL(buttonClicked(QAbstractButton *)), SLOT(onButtonClicked(QAbstractButton *)));
	connect(this, SIGNAL(accepted()), SLOT(onAccepted()));
	connect(this, SIGNAL(finished(int)), SLOT(onFinished(int)));
	connect(this, SIGNAL(rejected()), SLOT(onRejected()));
}

MaxQMessageBox::~MaxQMessageBox()
{
	qunbind(this);
}

void MaxQMessageBox::onButtonClicked(QAbstractButton * button) {
	_qt_qmessagebox_QMessageBox__OnButtonClicked(maxHandle, button);
}

void MaxQMessageBox::onAccepted() {
	_qt_qdialog_QDialog__OnAccepted(maxHandle);
}

void MaxQMessageBox::onFinished(int result) {
	_qt_qdialog_QDialog__OnFinished(maxHandle, result);
}

void MaxQMessageBox::onRejected() {
	_qt_qdialog_QDialog__OnRejected(maxHandle);
}

void MaxQMessageBox::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

void MaxQMessageBox::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

QMessageBox::StandardButtons bmx_qt_intToStandardButtons(int b) {
	QMessageBox::StandardButtons button;
	
	if (b & 0x00000400) button |= QMessageBox::Ok;
	if (b & 0x00002000) button |= QMessageBox::Open;
	if (b & 0x00000800) button |= QMessageBox::Save;
	if (b & 0x00400000) button |= QMessageBox::Cancel;
	if (b & 0x00200000) button |= QMessageBox::Close;
	if (b & 0x00800000) button |= QMessageBox::Discard;
	if (b & 0x02000000) button |= QMessageBox::Apply;
	if (b & 0x04000000) button |= QMessageBox::Reset;
	if (b & 0x08000000) button |= QMessageBox::RestoreDefaults;
	if (b & 0x01000000) button |= QMessageBox::Help;
	if (b & 0x00001000) button |= QMessageBox::SaveAll;
	if (b & 0x00004000) button |= QMessageBox::Yes;
	if (b & 0x00008000) button |= QMessageBox::YesToAll;
	if (b & 0x00010000) button |= QMessageBox::No;
	if (b & 0x00020000) button |= QMessageBox::NoToAll;
	if (b & 0x00040000) button |= QMessageBox::Abort;
	if (b & 0x00080000) button |= QMessageBox::Retry;
	if (b & 0x00100000) button |= QMessageBox::Ignore;

	return button;
}

int bmx_qt_standardButtonsToInt(QMessageBox::StandardButtons b) {
	int button = 0;
	
	if (b & QMessageBox::Ok) button |= 0x00000400;
	if (b & QMessageBox::Open) button |= 0x00002000;
	if (b & QMessageBox::Save) button |= 0x00000800;
	if (b & QMessageBox::Cancel) button |= 0x00400000;
	if (b & QMessageBox::Close) button |= 0x00200000;
	if (b & QMessageBox::Discard) button |= 0x00800000;
	if (b & QMessageBox::Apply) button |= 0x02000000;
	if (b & QMessageBox::Reset) button |= 0x04000000;
	if (b & QMessageBox::RestoreDefaults) button |= 0x08000000;
	if (b & QMessageBox::Help) button |= 0x01000000;
	if (b & QMessageBox::SaveAll) button |= 0x00001000;
	if (b & QMessageBox::Yes) button |= 0x00004000;
	if (b & QMessageBox::YesToAll) button |= 0x00008000;
	if (b & QMessageBox::No) button |= 0x00010000;
	if (b & QMessageBox::NoToAll) button |= 0x00020000;
	if (b & QMessageBox::Abort) button |= 0x00040000;
	if (b & QMessageBox::Retry) button |= 0x00080000;
	if (b & QMessageBox::Ignore) button |= 0x00100000;
	
	
	return button;
}

QMessageBox::StandardButton bmx_qt_intToStandardButton(int b) {
	switch (b) {
		case 0x00000400:
			return QMessageBox::Ok;
		case 0x00002000:
			return QMessageBox::Open;
		case 0x00000800:
			return QMessageBox::Save;
		case 0x00400000:
			return QMessageBox::Cancel;
		case 0x00200000:
			return QMessageBox::Close;
		case 0x00800000:
			return QMessageBox::Discard;
		case 0x02000000:
			return QMessageBox::Apply;
		case 0x04000000:
			return QMessageBox::Reset;
		case 0x08000000:
			return QMessageBox::RestoreDefaults;
		case 0x01000000:
			return QMessageBox::Help;
		case 0x00001000:
			return QMessageBox::SaveAll;
		case 0x00004000:
			return QMessageBox::Yes;
		case 0x00008000:
			return QMessageBox::YesToAll;
		case 0x00010000:
			return QMessageBox::No;
		case 0x00020000:
			return QMessageBox::NoToAll;
		case 0x00040000:
			return QMessageBox::Abort;
		case 0x00080000:
			return QMessageBox::Retry;
		case 0x00100000:
			return QMessageBox::Ignore;
	}
	
	return QMessageBox::NoButton;
}

int bmx_qt_standardButtonToInt(QMessageBox::StandardButton b) {
	switch (b) {
		case QMessageBox::Ok:
			return 0x00000400;
		case QMessageBox::Open:
			return 0x00002000;
		case QMessageBox::Save:
			return 0x00000800;
		case QMessageBox::Cancel:
			return 0x00400000;
		case QMessageBox::Close:
			return 0x00200000;
		case QMessageBox::Discard:
			return 0x00800000;
		case QMessageBox::Apply:
			return 0x02000000;
		case QMessageBox::Reset:
			return 0x04000000;
		case QMessageBox::RestoreDefaults:
			return 0x08000000;
		case QMessageBox::Help:
			return 0x01000000;
		case QMessageBox::SaveAll:
			return 0x00001000;
		case QMessageBox::Yes:
			return 0x00004000;
		case QMessageBox::YesToAll:
			return 0x00008000;
		case QMessageBox::No:
			return 0x00010000;
		case QMessageBox::NoToAll:
			return 0x00020000;
		case QMessageBox::Abort:
			return 0x00040000;
		case QMessageBox::Retry:
			return 0x00080000;
		case QMessageBox::Ignore:
			return 0x00100000;
	}
		
	return 0;
}

QMessageBox::Icon bmx_qt_messagebox_IntToIcon(int i) {
	switch (i) {
		case 1:
			return QMessageBox::Information;
		case 2:
			return QMessageBox::Warning;
		case 3:
			return QMessageBox::Critical;
		case 4:
			return QMessageBox::Question;
	}
	
	return QMessageBox::NoIcon;
}

// *********************************************

QMessageBox * bmx_qt_qmessagebox_create(BBObject * handle, QWidget * parent) {
	return new MaxQMessageBox(handle, parent);
}

void bmx_qt_qmessagebox_removebutton(QMessageBox * messageBox, QAbstractButton * button) {
	messageBox->removeButton(button);
}

void bmx_qt_qmessagebox_setdefaultbutton(QMessageBox * messageBox, QPushButton * button) {
	messageBox->setDefaultButton(button);
}

void bmx_qt_qmessagebox_setdefaultbuttontype(QMessageBox * messageBox, int button) {
	messageBox->setDefaultButton(bmx_qt_intToStandardButton(button));
}

void bmx_qt_qmessagebox_setdetailedtext(QMessageBox * messageBox, BBString * text) {
	messageBox->setDetailedText(qStringFromBBString(text));
}

void bmx_qt_qmessagebox_setescapebutton(QMessageBox * messageBox, QAbstractButton * button) {
	messageBox->setEscapeButton(button);
}

void bmx_qt_qmessagebox_setescapebuttontype(QMessageBox * messageBox, int button) {
	messageBox->setEscapeButton(bmx_qt_intToStandardButton(button));
}

void bmx_qt_qmessagebox_setinformativetext(QMessageBox * messageBox, BBString * text) {
	messageBox->setInformativeText(qStringFromBBString(text));
}

void bmx_qt_qmessagebox_setstandardbuttons(QMessageBox * messageBox, int buttons) {
	messageBox->setStandardButtons(bmx_qt_intToStandardButtons(buttons));
}

void bmx_qt_qmessagebox_settext(QMessageBox * messageBox, BBString * text) {
	messageBox->setText(qStringFromBBString(text));
}

void bmx_qt_qmessagebox_settextformat(QMessageBox * messageBox, int format) {
	messageBox->setTextFormat(static_cast<Qt::TextFormat>(format));
}

void bmx_qt_qmessagebox_setwindowmodality(QMessageBox * messageBox, int windowModality) {
	messageBox->setWindowModality(static_cast<Qt::WindowModality>(windowModality));
}

void bmx_qt_qmessagebox_setwindowtitle(QMessageBox * messageBox, BBString * text) {
	messageBox->setWindowTitle(qStringFromBBString(text));
}

int bmx_qt_qmessagebox_exec(QMessageBox * messageBox) {
	return messageBox->exec();
}

void bmx_qt_qmessagebox_free(QMessageBox * messageBox) {
	delete messageBox;
}

void bmx_qt_qmessagebox_seticon(QMessageBox * messageBox, int icon) {
	messageBox->setIcon(bmx_qt_messagebox_IntToIcon(icon));
}

int bmx_qt_qmessagebox_icon(QMessageBox * messageBox) {
	return messageBox->icon();
}

void bmx_qt_qmessagebox_about(QWidget * parent, BBString * title, BBString * text) {
	QMessageBox::about(parent, qStringFromBBString(title), qStringFromBBString(text));
}

void bmx_qt_qmessagebox_aboutqt(QWidget * parent, BBString * title) {
	QMessageBox::aboutQt(parent, qStringFromBBString(title));
}

int bmx_qt_qmessagebox_critical(QWidget * parent, BBString * title, BBString * text, int buttons, int defaultButton) {
	return bmx_qt_standardButtonToInt(QMessageBox::critical(parent, qStringFromBBString(title), qStringFromBBString(text),
		bmx_qt_intToStandardButtons(buttons), bmx_qt_intToStandardButton(defaultButton)));
}

int bmx_qt_qmessagebox_information(QWidget * parent, BBString * title, BBString * text, int buttons, int defaultButton) {
	return bmx_qt_standardButtonToInt(QMessageBox::information(parent, qStringFromBBString(title), qStringFromBBString(text),
		bmx_qt_intToStandardButtons(buttons), bmx_qt_intToStandardButton(defaultButton)));
}

int bmx_qt_qmessagebox_question(QWidget * parent, BBString * title, BBString * text, int buttons, int defaultButton) {
	return bmx_qt_standardButtonToInt(QMessageBox::question(parent, qStringFromBBString(title), qStringFromBBString(text),
		bmx_qt_intToStandardButtons(buttons), bmx_qt_intToStandardButton(defaultButton)));
}

int bmx_qt_qmessagebox_warning(QWidget * parent, BBString * title, BBString * text, int buttons, int defaultButton) {
	return bmx_qt_standardButtonToInt(QMessageBox::warning(parent, qStringFromBBString(title), qStringFromBBString(text),
		bmx_qt_intToStandardButtons(buttons), bmx_qt_intToStandardButton(defaultButton)));
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

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



// *********************************************

int bmx_qt_qabstractspinbox_alignment(QAbstractSpinBox * box) {
	return box->alignment();
}

int bmx_qt_qabstractspinbox_buttonsybmols(QAbstractSpinBox * box) {
	return box->buttonSymbols();
}

int bmx_qt_qabstractspinbox_correctionmode(QAbstractSpinBox * box) {
	return box->correctionMode();
}

BBString * bmx_qt_qabstractspinbox_fixup(QAbstractSpinBox * box, BBString * inp) {
	QString s(qStringFromBBString(inp));
	box->fixup(s);
	return bbStringFromQString(s);
}

int bmx_qt_qabstractspinbox_hasacceptableinput(QAbstractSpinBox * box) {
	return static_cast<int>(box->hasAcceptableInput());
}

int bmx_qt_qabstractspinbox_hasframe(QAbstractSpinBox * box) {
	return static_cast<int>(box->hasFrame());
}

void bmx_qt_qabstractspinbox_interprettext(QAbstractSpinBox * box) {
	box->interpretText();
}

int bmx_qt_qabstractspinbox_isaccelerated(QAbstractSpinBox * box) {
	return static_cast<int>(box->isAccelerated());
}

int bmx_qt_qabstractspinbox_isreadonly(QAbstractSpinBox * box) {
	return static_cast<int>(box->isReadOnly());
}

int bmx_qt_qabstractspinbox_keyboardtracking(QAbstractSpinBox * box) {
	return static_cast<int>(box->keyboardTracking());
}

void bmx_qt_qabstractspinbox_setaccelerated(QAbstractSpinBox * box, int on) {
	box->setAccelerated(static_cast<bool>(on));
}

void bmx_qt_qabstractspinbox_setalignment(QAbstractSpinBox * box, int flag) {
	box->setAlignment(bmx_qt_getalignment(flag));
}

void bmx_qt_qabstractspinbox_setbuttonsymbols(QAbstractSpinBox * box, int bs) {
	QAbstractSpinBox::ButtonSymbols s;
	switch(bs) {
		case 0:
			s = QAbstractSpinBox::UpDownArrows;
			break;
		case 1:
			s = QAbstractSpinBox::PlusMinus;
			break;
		case 2:
			s = QAbstractSpinBox::NoButtons;
			break;
		default:
			s = QAbstractSpinBox::UpDownArrows;
	}			
	box->setButtonSymbols(s);
}

void bmx_qt_qabstractspinbox_setcorrectionmode(QAbstractSpinBox * box, int cm) {
	QAbstractSpinBox:: CorrectionMode c;
	switch(cm) {
		case 0:
			c = QAbstractSpinBox::CorrectToPreviousValue;
			break;
		case 1:
			c = QAbstractSpinBox::CorrectToNearestValue;
			break;
		default:
			c = QAbstractSpinBox::CorrectToPreviousValue;
	}
	box->setCorrectionMode(c);
}

void bmx_qt_qabstractspinbox_setframe(QAbstractSpinBox * box, int frame) {
	box->setFrame(static_cast<bool>(frame));
}

void bmx_qt_qabstractspinbox_setkeyboardtracking(QAbstractSpinBox * box, int kt) {
	box->setKeyboardTracking(static_cast<bool>(kt));
}

void bmx_qt_qabstractspinbox_setreadonly(QAbstractSpinBox * box, int r) {
	box->setReadOnly(static_cast<bool>(r));
}

void bmx_qt_qabstractspinbox_setspecialvaluetext(QAbstractSpinBox * box, BBString * txt) {
	box->setSpecialValueText(qStringFromBBString(txt));
}

void bmx_qt_qabstractspinbox_setwrapping(QAbstractSpinBox * box, int w) {
	box->setWrapping(static_cast<bool>(w));
}

BBString * bmx_qt_qabstractspinbox_specialvaluetext(QAbstractSpinBox * box) {
	return bbStringFromQString(box->specialValueText());
}

void bmx_qt_qabstractspinbox_stepby(QAbstractSpinBox * box, int steps) {
	box->stepBy(steps);
}

BBString * bmx_qt_qabstractspinbox_text(QAbstractSpinBox * box) {
	return bbStringFromQString(box->text());
}

int bmx_qt_qabstractspinbox_validate(QAbstractSpinBox * box, BBString * inp, int * pos) {
	int p = *pos;
	QString s(qStringFromBBString(inp));
	QValidator::State state = box->validate(s, p);
	*pos = p;
	return state;
}

int bmx_qt_qabstractspinbox_wrapping(QAbstractSpinBox * box) {
	return static_cast<int>(box->wrapping());
}

void bmx_qt_qabstractspinbox_clear(QAbstractSpinBox * box) {
	box->clear();
}

void bmx_qt_qabstractspinbox_selectall(QAbstractSpinBox * box) {
	box->selectAll();
}

void bmx_qt_qabstractspinbox_stepdown(QAbstractSpinBox * box) {
	box->stepDown();
}

void bmx_qt_qabstractspinbox_stepup(QAbstractSpinBox * box) {
	box->stepUp();
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

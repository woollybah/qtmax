/*
  Copyright (c) 2009-2013 Bruce A Henderson
 
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

MaxQClipboard::MaxQClipboard(BBObject * handle, QClipboard * clipboard)
	: clipboard(clipboard), MaxQObjectWrapper(handle, clipboard)
{
	doConnections();
}

MaxQClipboard::MaxQClipboard(QClipboard * c)
	: clipboard(c), MaxQObjectWrapper(c)
{
	maxHandle = _qt_qclipboard_QClipboard__create(clipboard);
	qbind(clipboard, maxHandle);

	doConnections();
}

void MaxQClipboard::doConnections() {
	
}

QClipboard * MaxQClipboard::Clipboard() {
	return clipboard;
}

void MaxQClipboard::link(QClipboard * c) {
	BBObject * handle = qfind(c);
	
	if (handle == &bbNullObject) {
		MaxQClipboard * clipboard = new MaxQClipboard(c);
	}
}

MaxQClipboard::~MaxQClipboard()
{
}

void MaxQClipboard::onChanged(QClipboard::Mode mode) {
	_qt_qclipboard_QClipboard__OnChanged(maxHandle, static_cast<int>(mode));
}

void MaxQClipboard::onDataChanged() {
	_qt_qclipboard_QClipboard__OnDataChanged(maxHandle);
}

void MaxQClipboard::onFindBufferChanged() {
	_qt_qclipboard_QClipboard__OnFindBufferChanged(maxHandle);
}

void MaxQClipboard::onSelectionChanged() {
	_qt_qclipboard_QClipboard__OnSelectionChanged(maxHandle);
}

// *********************************************

void bmx_qt_qclipboard_clear(QClipboard * clipboard, int mode) {
	clipboard->clear((QClipboard::Mode)mode);
}

MaxQImage * bmx_qt_qclipboard_image(QClipboard * clipboard, int mode) {
	return new MaxQImage(clipboard->image((QClipboard::Mode)mode));
}

const QMimeData * bmx_qt_qclipboard_mimedata(QClipboard * clipboard, int mode) {
	return clipboard->mimeData((QClipboard::Mode)mode);
}

int bmx_qt_qclipboard_ownsclipboard(QClipboard * clipboard) {
	return static_cast<int>(clipboard->ownsClipboard());
}

int bmx_qt_qclipboard_ownsfindbuffer(QClipboard * clipboard) {
	return static_cast<int>(clipboard->ownsFindBuffer());
}

int bmx_qt_qclipboard_ownsselection(QClipboard * clipboard) {
	return static_cast<int>(clipboard->ownsSelection());
}

MaxQPixmap * bmx_qt_qclipboard_pixmap(QClipboard * clipboard, int mode) {
	return new MaxQPixmap(clipboard->pixmap((QClipboard::Mode)mode));
}

void bmx_qt_qclipboard_setimage(QClipboard * clipboard, MaxQImage * image, int mode) {
	clipboard->setImage(image->Image(), (QClipboard::Mode)mode);
}

void bmx_qt_qclipboard_setmimedata(QClipboard * clipboard, QMimeData * src, int mode) {
	clipboard->setMimeData(src, (QClipboard::Mode)mode);
}

void bmx_qt_qclipboard_setpixmap(QClipboard * clipboard, MaxQPixmap * pixmap, int mode) {
	clipboard->setPixmap(pixmap->Pixmap(), (QClipboard::Mode)mode);
}

void bmx_qt_qclipboard_settext(QClipboard * clipboard, BBString * text, int mode) {
	clipboard->setText(qStringFromBBString(text), (QClipboard::Mode)mode);
}

int bmx_qt_qclipboard_supportsfindbuffer(QClipboard * clipboard) {
	return static_cast<int>(clipboard->supportsFindBuffer());
}

int bmx_qt_qclipboard_supportsselection(QClipboard * clipboard) {
	return static_cast<int>(clipboard->supportsSelection());
}

BBString * bmx_qt_qclipboard_text(QClipboard * clipboard, int mode) {
	return bbStringFromQString(clipboard->text((QClipboard::Mode)mode));
}

BBString * bmx_qt_qclipboard_textsubtype(QClipboard * clipboard, BBString * subtype, int mode) {
	QString s(qStringFromBBString(subtype));
	
	return bbStringFromQString(clipboard->text(s, (QClipboard::Mode)mode));
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

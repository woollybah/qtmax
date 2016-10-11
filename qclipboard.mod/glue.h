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

#ifndef MAX_QT_QCLIPBOARD
#define MAX_QT_QCLIPBOARD

#include "../core.mod/glue.h"
#include "../qimage.mod/glue.h"
#include "../qpixmap.mod/glue.h"
#include <QtCore>
#include <QClipboard>

class MaxQClipboard;

extern "C" {

#include <blitz.h>

	// used for on-the-fly QClipboard creation - linking to a BlitzMax object.
	BBObject * _qt_qclipboard_QClipboard__create(QClipboard * clipboard);
	
	void _qt_qclipboard_QClipboard__OnChanged(BBObject * handle, int mode);
	void _qt_qclipboard_QClipboard__OnDataChanged(BBObject * handle);
	void _qt_qclipboard_QClipboard__OnFindBufferChanged(BBObject * handle);
	void _qt_qclipboard_QClipboard__OnSelectionChanged(BBObject * handle);

	void bmx_qt_qclipboard_clear(QClipboard * clipboard, int mode);
	MaxQImage * bmx_qt_qclipboard_image(QClipboard * clipboard, int mode);
	const QMimeData * bmx_qt_qclipboard_mimedata(QClipboard * clipboard, int mode);
	int bmx_qt_qclipboard_ownsclipboard(QClipboard * clipboard);
	int bmx_qt_qclipboard_ownsfindbuffer(QClipboard * clipboard);
	int bmx_qt_qclipboard_ownsselection(QClipboard * clipboard);
	MaxQPixmap * bmx_qt_qclipboard_pixmap(QClipboard * clipboard, int mode);
	void bmx_qt_qclipboard_setimage(QClipboard * clipboard, MaxQImage * image, int mode);
	void bmx_qt_qclipboard_setmimedata(QClipboard * clipboard, QMimeData * src, int mode);
	void bmx_qt_qclipboard_setpixmap(QClipboard * clipboard, MaxQPixmap * pixmap, int mode);
	void bmx_qt_qclipboard_settext(QClipboard * clipboard, BBString * text, int mode);
	int bmx_qt_qclipboard_supportsfindbuffer(QClipboard * clipboard);
	int bmx_qt_qclipboard_supportsselection(QClipboard * clipboard);
	BBString * bmx_qt_qclipboard_text(QClipboard * clipboard, int mode);
	BBString * bmx_qt_qclipboard_textsubtype(QClipboard * clipboard, BBString * subtype, int mode);


}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQClipboard : public MaxQObjectWrapper
{
	Q_OBJECT

public:
	MaxQClipboard(BBObject * handle, QClipboard * clipboard);
	MaxQClipboard(QClipboard * clipboard);
	
	QClipboard * Clipboard();
	
	static void link(QClipboard * c);
	
	~MaxQClipboard();

private:
	void doConnections();
	QClipboard * clipboard;
	
private slots:
	void onChanged(QClipboard::Mode mode);
	void onDataChanged();
	void onFindBufferChanged();
	void onSelectionChanged();
};

#endif

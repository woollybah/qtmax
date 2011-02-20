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

MaxQCoreApplication::MaxQCoreApplication(BBObject * handle, int & argc, char ** argv)
	: maxHandle(handle), QCoreApplication(argc, argv)
{
	qbind(this, handle);
	
	connect(this, SIGNAL(aboutToQuit()), SLOT(onAboutToQuit()));
}

MaxQCoreApplication::~MaxQCoreApplication()
{
	qunbind(this);
}

void MaxQCoreApplication::onAboutToQuit() {
	_qt_qcoreapplication_QCoreApplication__OnAboutToQuit(maxHandle);
}

void MaxQCoreApplication::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}


// *********************************************

QCoreApplication * bmx_qt_qcoreapplication_create(BBObject * handle) {

	static int i = 0;
	static const char *const empty = "";


	MaxQCoreApplication * app = new MaxQCoreApplication(handle, i, (char **)&empty);
	
	// accepts all strings from Max as utf-8
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	
	return app;
}

void bmx_qt_qcoreapplication_addlibrarypath(BBString * path) {
	QCoreApplication::addLibraryPath(qStringFromBBString(path));
}

BBString * bmx_qt_qcoreapplication_applicationdirpath() {
	return bbStringFromQString(QCoreApplication::applicationDirPath());
}

BBString * bmx_qt_qcoreapplication_applicationfilepath() {
	return bbStringFromQString(QCoreApplication::applicationFilePath());
}

BBString * bmx_qt_qcoreapplication_applicationname() {
	return bbStringFromQString(QCoreApplication::applicationName());
}

void bmx_qt_qcoreapplication_applicationpid(BBInt64 * pid) {
	*pid = QCoreApplication::applicationPid();
}

void bmx_qt_qcoreapplication_flush() {
	QCoreApplication::flush();
}

void bmx_qt_qcoreapplication_quit(QCoreApplication * app) {
	app->quit();
}

BBString * bmx_qt_qcoreapplication_translate(BBString * context, BBString * text, BBString * disambiguation, int e) {
	char * c = 0;
	char * s = bbStringToUTF8String(text);
	char *d = 0;
	
	if (context != &bbEmptyString) {
		c = bbStringToUTF8String(context);
	}
	
	if (disambiguation != &bbEmptyString) {
		d = bbStringToUTF8String(disambiguation);
	}
	
	QCoreApplication::Encoding encoding;
	switch (e) {
		case 0:
			encoding = QCoreApplication::CodecForTr;
			break;
		case 1:
			encoding = QCoreApplication::UnicodeUTF8;
			break;
	}

	BBString * ret = bbStringFromQString(QCoreApplication::translate(c, s, d, encoding));

	bbMemFree(s);
	if (c) bbMemFree(c);
	if (d) bbMemFree(d);

	return ret;
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"


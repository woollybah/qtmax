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

MaxQFontDatabase::MaxQFontDatabase(const QFontDatabase & d)
	: database(d)
{
}

MaxQFontDatabase::~MaxQFontDatabase()
{
}

QFontDatabase & MaxQFontDatabase::Database() {
	return database;
}


// *********************************************

MaxQFontDatabase * bmx_qt_qfontdatabase_create() {
	QFontDatabase db;
	return new MaxQFontDatabase(db);
}

int bmx_qt_qfontdatabase_bold(MaxQFontDatabase * db, BBString * family, BBString * style) {
	return db->Database().bold(qStringFromBBString(family), qStringFromBBString(style));
}

BBArray * bmx_qt_qfontdatabase_families(MaxQFontDatabase * db, int writingSystem) {
//
}

MaxQFont * bmx_qt_qfontdatabase_font(MaxQFontDatabase * db, BBString * family, BBString * style, int pointSize) {
	return new MaxQFont(db->Database().font(qStringFromBBString(family), qStringFromBBString(style), pointSize));
}

int bmx_qt_qfontdatabase_isbitmapscalable(MaxQFontDatabase * db, BBString * family, BBString * style) {
	return static_cast<int>(db->Database().isBitmapScalable(qStringFromBBString(family), qStringFromBBString(style)));
}

int bmx_qt_qfontdatabase_isfixedpitch(MaxQFontDatabase * db, BBString * family, BBString * style) {
	return static_cast<int>(db->Database().isFixedPitch(qStringFromBBString(family), qStringFromBBString(style)));
}

int bmx_qt_qfontdatabase_isscalable(MaxQFontDatabase * db, BBString * family, BBString * style) {
	return static_cast<int>(db->Database().isScalable(qStringFromBBString(family), qStringFromBBString(style)));
}

int bmx_qt_qfontdatabase_issmoothlyscalable(MaxQFontDatabase * db, BBString * family, BBString * style) {
	return static_cast<int>(db->Database().isSmoothlyScalable(qStringFromBBString(family), qStringFromBBString(style)));
}

int bmx_qt_qfontdatabase_italic(MaxQFontDatabase * db, BBString * family, BBString * style) {
	return db->Database().italic(qStringFromBBString(family), qStringFromBBString(style));
}

BBArray * bmx_qt_qfontdatabase_pointsizes(MaxQFontDatabase * db, BBString * family, BBString * style) {
	return bbIntArrayFromQIntList(db->Database().pointSizes(qStringFromBBString(family), qStringFromBBString(style)));
}

BBArray * bmx_qt_qfontdatabase_smoothsizes(MaxQFontDatabase * db, BBString * family, BBString * style) {
	return bbIntArrayFromQIntList(db->Database().smoothSizes(qStringFromBBString(family), qStringFromBBString(style)));
}

BBString * bmx_qt_qfontdatabase_stylestring(MaxQFontDatabase * db, MaxQFont * font) {
	return bbStringFromQString(db->Database().styleString(font->Font()));
}

BBString * bmx_qt_qfontdatabase_stylestringinfo(MaxQFontDatabase * db, MaxQFontInfo * fontInfo) {
	return bbStringFromQString(db->Database().styleString(fontInfo->Info()));
}

BBArray * bmx_qt_qfontdatabase_styles(MaxQFontDatabase * db, BBString * family) {
	return bbStringArrayFromQStringList(db->Database().styles(qStringFromBBString(family)));
}

int bmx_qt_qfontdatabase_weight(MaxQFontDatabase * db, BBString * family, BBString * style) {
	return db->Database().weight(qStringFromBBString(family), qStringFromBBString(style));
}

BBArray * bmx_qt_qfontdatabase_writingsystems(MaxQFontDatabase * db, BBString * family) {
//
}

int bmx_qt_qfontdatabase_addapplicationfont(BBString * fileName) {
	return QFontDatabase::addApplicationFont(qStringFromBBString(fileName));
}

BBArray * bmx_qt_qfontdatabase_applicationfontfamilies(int id) {
	return bbStringArrayFromQStringList(QFontDatabase::applicationFontFamilies(id));
}

int bmx_qt_qfontdatabase_removeallapplicationfonts() {
	return static_cast<int>(QFontDatabase::removeAllApplicationFonts());
}

int bmx_qt_qfontdatabase_removeapplicationfont(int id) {
	return static_cast<int>(QFontDatabase::removeApplicationFont(id));
}

BBArray * bmx_qt_qfontdatabase_standardsizes() {
	return bbIntArrayFromQIntList(QFontDatabase::standardSizes());
}

int bmx_qt_qfontdatabase_supportsthreadedfontrendering() {
	return static_cast<int>(QFontDatabase::supportsThreadedFontRendering());
}

BBString * bmx_qt_qfontdatabase_writingsystemname(int writingSystem) {
	return bbStringFromQString(QFontDatabase::writingSystemName((QFontDatabase::WritingSystem)writingSystem));
}

BBString * bmx_qt_qfontdatabase_writingsystemsample(int writingSystem) {
	return bbStringFromQString(QFontDatabase::writingSystemSample((QFontDatabase::WritingSystem)writingSystem));
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

' Copyright (c) 2009-2013 Bruce A Henderson
' 
' Permission is hereby granted, free of charge, to any person obtaining a copy
' of this software and associated documentation files (the "Software"), to deal
' in the Software without restriction, including without limitation the rights
' to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
' copies of the Software, and to permit persons to whom the Software is
' furnished to do so, subject to the following conditions:
' 
' The above copyright notice and this permission notice shall be included in
' all copies or substantial portions of the Software.
' 
' THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
' IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
' FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
' AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
' LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
' OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
' THE SOFTWARE.
' 
SuperStrict

Module Qt.QFontDatabase

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QFontDatabase

	Field qObjectPtr:Byte Ptr
	
	Function CreateFontDatabase:QFontDatabase()
		Return New QFontDatabase.Create()
	End Function
	
	Method Create:QFontDatabase()
		qObjectPtr = bmx_qt_qfontdatabase_create()
		Return Self
	End Method
	
	Method bold:Int(family:String, style:String)
		Return bmx_qt_qfontdatabase_bold(qObjectPtr, family, style)
	End Method
	
	Method families:String[](writingSystem:Int)
		Return bmx_qt_qfontdatabase_families(qObjectPtr, writingSystem)
	End Method
	
	Method font:QFont(family:String, style:String, pointSize:Int)
		Return QFont._create(bmx_qt_qfontdatabase_font(qObjectPtr, family, style, pointSize))
	End Method
	
	Method isBitmapScalable:Int(family:String, style:String = "")
		Return bmx_qt_qfontdatabase_isbitmapscalable(qObjectPtr, family, style)
	End Method
	
	Method isFixedPitch:Int(family:String, style:String = "")
		Return bmx_qt_qfontdatabase_isfixedpitch(qObjectPtr, family, style)
	End Method
	
	Method isScalable:Int(family:String, style:String = "")
		Return bmx_qt_qfontdatabase_isscalable(qObjectPtr, family, style)
	End Method
	
	Method isSmoothlyScalable:Int(family:String, style:String = "")
		Return bmx_qt_qfontdatabase_issmoothlyscalable(qObjectPtr, family, style)
	End Method
	
	Method italic:Int(family:String, style:String)
		Return bmx_qt_qfontdatabase_italic(qObjectPtr, family, style)
	End Method
	
	Method pointSizes:Int[](family:String, style:String = "")
		Return bmx_qt_qfontdatabase_pointsizes(qObjectPtr, family, style)
	End Method
	
	Method smoothSizes:Int[](family:String, style:String)
		Return bmx_qt_qfontdatabase_smoothsizes(qObjectPtr, family, style)
	End Method
	
	Method styleString:String(font:Object)
		If QFont(font) Then
			Return bmx_qt_qfontdatabase_stylestring(qObjectPtr, QFont(font).qObjectPtr)
		Else If QFontInfo(font) Then
			Return bmx_qt_qfontdatabase_stylestringinfo(qObjectPtr, QFontInfo(font).qObjectPtr)
		End If
	End Method
	
	Method styles:String[](family:String)
		Return bmx_qt_qfontdatabase_styles(qObjectPtr, family)
	End Method
	
	Method weight:Int(family:String, style:String)
		Return bmx_qt_qfontdatabase_weight(qObjectPtr, family, style)
	End Method
	
	Method writingSystems:Int[](family:String = Null)
		Return bmx_qt_qfontdatabase_writingsystems(qObjectPtr, family)
	End Method

	Function addApplicationFont:Int(fileName:String)
		Return bmx_qt_qfontdatabase_addapplicationfont(fileName)
	End Function
	
	Function applicationFontFamilies:String[](id:Int)
		Return bmx_qt_qfontdatabase_applicationfontfamilies(id)
	End Function
	
	Function removeAllApplicationFonts:Int()
		Return bmx_qt_qfontdatabase_removeallapplicationfonts()
	End Function
	
	Function removeApplicationFont:Int(id:Int)
		Return bmx_qt_qfontdatabase_removeapplicationfont(id)
	End Function
	
	Function standardSizes:Int[]()
		Return bmx_qt_qfontdatabase_standardsizes()
	End Function
	
	Function supportsThreadedFontRendering:Int()
		Return bmx_qt_qfontdatabase_supportsthreadedfontrendering()
	End Function

	Function writingSystemName:String(writingSystem:Int)
		Return bmx_qt_qfontdatabase_writingsystemname(writingSystem)
	End Function

	Function writingSystemSample:String(writingSystem:Int)
		Return bmx_qt_qfontdatabase_writingsystemsample(writingSystem)
	End Function

	Method Free()
		If qObjectPtr Then
			bmx_qt_qfontdatabase_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type

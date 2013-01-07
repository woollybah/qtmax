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

Import Qt.Core
Import Qt.QWidget
Import Qt.QMenu
Import Qt.QNetwork
Import Qt.QIcon
Import Qt.QPalette
Import Qt.QContextMenuEvent
Import Qt.QUndoStack
Import Qt.QPainter
Import Qt.QWebDatabase
Import Qt.QWebHistory
Import BRL.Blitz


' headers :-)
?win32
Import "../lib/win32/include/*.h"
?macos
Import "../lib/macos/include/*.h"
?Not linux
Import "../src/include/*.h"
Import "../src/include/Qt/*.h"
Import "../src/include/QtCore/*.h"
Import "../src/include/QtGui/*.h"
Import "../src/include/QtWebKit/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
Import "/usr/include/QtGui/*.h"
Import "/usr/include/qt4/QtWebKit/*.h"
Import "/usr/include/QtWebKit/*.h"
?


Import "glue.cpp"

Extern

	Function bmx_qt_qwebview_create:Byte Ptr(handle:Object, parent:Byte Ptr, flags:Int)
	Function bmx_qt_qwebview_load(handle:Byte Ptr, url:Byte Ptr)
	Function bmx_qt_qwebview_pageaction:Byte Ptr(handle:Byte Ptr, action:Int)
	Function bmx_qt_qwebview_title:String(handle:Byte Ptr)
	Function bmx_qt_qwebview_url:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebview_settings:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebview_page:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebview_findtext:Int(handle:Byte Ptr, subString:String, options:Int)
	Function bmx_qt_qwebview_icon:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebview_ismodified:Int(handle:Byte Ptr)
	Function bmx_qt_qwebview_selectedtext:String(handle:Byte Ptr)
	Function bmx_qt_qwebview_sethtml(handle:Byte Ptr, html:String, baseUrl:Byte Ptr)
	Function bmx_qt_qwebview_setpage(handle:Byte Ptr, page:Byte Ptr)
	Function bmx_qt_qwebview_settextsizemultiplier(handle:Byte Ptr, factor:Double)
	Function bmx_qt_qwebview_seturl(handle:Byte Ptr, url:Byte Ptr)
	Function bmx_qt_qwebview_setzoomfactor(handle:Byte Ptr, factor:Double)

	Function bmx_qt_qwebsettings_setattribute(handle:Byte Ptr, attribute:Int, on:Int)
	Function bmx_qt_qwebsettings_fontfamily:String(handle:Byte Ptr, which:Int)
	Function bmx_qt_qwebsettings_fontsize:Int(handle:Byte Ptr, sizeType:Int)
	Function bmx_qt_qwebsettings_resetattribute(handle:Byte Ptr, attribute:Int)
	Function bmx_qt_qwebsettings_resetfontfamily(handle:Byte Ptr, which:Int)
	Function bmx_qt_qwebsettings_resetfontsize(handle:Byte Ptr, sizeType:Int)
	Function bmx_qt_qwebsettings_setfontfamily(handle:Byte Ptr, which:Int, family:String)
	Function bmx_qt_qwebsettings_setfontsize(handle:Byte Ptr, sizeType:Int, size:Int)
	Function bmx_qt_qwebsettings_setuserstylesheeturl(handle:Byte Ptr, location:Byte Ptr)
	Function bmx_qt_qwebsettings_testattribute:Int(handle:Byte Ptr, attribute:Int)
	Function bmx_qt_qwebsettings_userstylesheeturl:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebsettings_clearicondatabase()
	Function bmx_qt_qwebsettings_globalsettings:Byte Ptr()
	Function bmx_qt_qwebsettings_icondatabasepath:String()
	Function bmx_qt_qwebsettings_iconforurl:Byte Ptr(url:Byte Ptr)
	Function bmx_qt_qwebsettings_maximumpagesincache:Int()
	Function bmx_qt_qwebsettings_offlinestoragedefaultquota(value:Long Ptr)
	Function bmx_qt_qwebsettings_offlinestoragepath:String()
	Function bmx_qt_qwebsettings_seticondatabasepath(path:String)
	Function bmx_qt_qwebsettings_setmaximumpagesincache(pages:Int)
	Function bmx_qt_qwebsettings_setobjectcachecapacities(cacheMinDeadCapacity:Int, cacheMaxDead:Int, totalCapacity:Int)
	Function bmx_qt_qwebsettings_setofflinestoragedefaultquota(maximumSize:Long)
	Function bmx_qt_qwebsettings_setofflinestoragepath(path:String)
	Function bmx_qt_qwebsettings_setwebgraphic(graphicType:Int, graphic:Byte Ptr)
	Function bmx_qt_qwebsettings_webgraphic:Byte Ptr(graphicType:Int)

	Function bmx_qt_qwebpage_mainframe:Byte Ptr(handle:Byte Ptr)

	Function bmx_qt_qwebframe_evaluatejavascript:String(handle:Byte Ptr, scriptSource:String)
	Function bmx_qt_qwebframe_hittestcontent:Byte Ptr(handle:Byte Ptr, x:Int, y:Int)

	Function bmx_qt_qwebhittestresult_alternatetext:String(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_boundingrect:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_frame:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_imageurl:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_iscontenteditable:Int(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_iscontentselected:Int(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_isnull:Int(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_linktargetframe:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_linktext:String(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_linktitle:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_linkurl:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_pixmap:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_pos(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qwebhittestresult_title:String(handle:Byte Ptr)
	Function bmx_qt_qwebhittestresult_free(handle:Byte Ptr)

End Extern

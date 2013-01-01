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
Import Qt.QObject
Import Qt.QTextCharFormat
Import Qt.QPrinter
Import Qt.QFont
Import Qt.QTextBlockFormat
Import Qt.QTextFrameFormat
Import Qt.QTextImageFormat
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
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qtextdocument_idealwidth:Double(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_indentewidth:Double(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_isempty:Int(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_ismodified:Int(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_isredoavailable:Int(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_isundoavailable:Int(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_isundoredoenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_lastblock:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_linecount:Int(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_markcontentsdirty(handle:Byte Ptr, position:Int, length:Int)
	Function bmx_qt_qtextdocument_maximumblockcount:Int(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_metainformation:String(handle:Byte Ptr, info:Int)
	Function bmx_qt_qtextdocument_object:Byte Ptr(handle:Byte Ptr, objectIndex:Int)
	Function bmx_qt_qtextdocument_objectforformat:Byte Ptr(handle:Byte Ptr, f:Byte Ptr)
	Function bmx_qt_qtextdocument_pagecount:Int(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_pagesize(handle:Byte Ptr, w:Double Ptr, h:Double Ptr)
	Function bmx_qt_qtextdocument_print(handle:Byte Ptr, printer:Byte Ptr)
	Function bmx_qt_qtextdocument_redo(handle:Byte Ptr, cursor:Byte Ptr)
	Function bmx_qt_qtextdocument_revision:Int(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_rootframe:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_setdefaultfont(handle:Byte Ptr, font:Byte Ptr)
	Function bmx_qt_qtextdocument_setdefaultstylesheet(handle:Byte Ptr, sheet:String)
	Function bmx_qt_qtextdocument_setdefaulttextoption(handle:Byte Ptr, option:Byte Ptr)
	Function bmx_qt_qtextdocument_setdocumentlayout(handle:Byte Ptr, layout:Byte Ptr)
	Function bmx_qt_qtextdocument_setdocumentmargin(handle:Byte Ptr, margin:Double)
	Function bmx_qt_qtextdocument_sethtml(handle:Byte Ptr, html:String)
	Function bmx_qt_qtextdocument_setindentwidth(handle:Byte Ptr, width:Double)
	Function bmx_qt_qtextdocument_setmaximumblockcount(handle:Byte Ptr, maximum:Int)
	Function bmx_qt_qtextdocument_setmetainformation(handle:Byte Ptr, info:Int, text:String)
	Function bmx_qt_qtextdocument_setpagesize(handle:Byte Ptr, w:Double, h:Double)
	Function bmx_qt_qtextdocument_setplaintext(handle:Byte Ptr, text:String)
	Function bmx_qt_qtextdocument_settextwidth(handle:Byte Ptr, width:Double)
	Function bmx_qt_qtextdocument_setundoredoenabled(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qtextdocument_setusedesignmetrics(handle:Byte Ptr, b:Int)
	Function bmx_qt_qtextdocument_size(handle:Byte Ptr, w:Double Ptr, h:Double Ptr)
	Function bmx_qt_qtextdocument_textwidth:Double(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_toplaintext:String(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_undo(handle:Byte Ptr, cursor:Byte Ptr)
	Function bmx_qt_qtextdocument_usedesignmetrics:Int(handle:Byte Ptr)
	Function bmx_qt_qtextdocument_setmodified(handle:Byte Ptr, m:Int)


	Function bmx_qt_qtextcursor_anchor:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_atblockend:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_atblockstart:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_atend:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_atstart:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_begineditblock(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_block:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_blockcharformat:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_blockformat:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_blocknumber:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_charformat:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_clearselection(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_columnnumber:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_deletechar(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_deletepreviouschar(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_endeditblock(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_hascomplexselection:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_hasselection:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_insertblock(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_insertblockformat(handle:Byte Ptr, format:Byte Ptr)
	Function bmx_qt_qtextcursor_insertblockcharformat(handle:Byte Ptr, format:Byte Ptr, charFormat:Byte Ptr)
	Function bmx_qt_qtextcursor_insertfragment(handle:Byte Ptr, fragment:Byte Ptr)
	Function bmx_qt_qtextcursor_inserthtml(handle:Byte Ptr, html:String)
	Function bmx_qt_qtextcursor_insertimage(handle:Byte Ptr, format:Byte Ptr)
	Function bmx_qt_qtextcursor_insertimagealign(handle:Byte Ptr, format:Byte Ptr, alignment:Int)
	Function bmx_qt_qtextcursor_insertimagename(handle:Byte Ptr, name:String)
	Function bmx_qt_qtextcursor_insertimageimage(handle:Byte Ptr, image:Byte Ptr, name:String)
	Function bmx_qt_qtextcursor_inserttext(handle:Byte Ptr, text:String)
	Function bmx_qt_qtextcursor_inserttextformat(handle:Byte Ptr, text:String, format:Byte Ptr)
	Function bmx_qt_qtextcursor_iscopyof:Int(handle:Byte Ptr, other:Byte Ptr)
	Function bmx_qt_qtextcursor_isnull:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_joinpreviouseditblock(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_keeppositiononinsert:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_mergeblockcharformat(handle:Byte Ptr, modifier:Byte Ptr)
	Function bmx_qt_qtextcursor_mergeblockformat(handle:Byte Ptr, modifier:Byte Ptr)
	Function bmx_qt_qtextcursor_mergecharformat(handle:Byte Ptr, modifier:Byte Ptr)
	Function bmx_qt_qtextcursor_moveposition:Int(handle:Byte Ptr, operation:Int, Mode:Int, n:Int)
	Function bmx_qt_qtextcursor_position:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_positioninblock:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_removeselectedtext(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_selecttext(handle:Byte Ptr, selection:Int)
	Function bmx_qt_qtextcursor_selectedtext:String(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_selection:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_selectionend:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_selectionstart:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_setblockcharformat(handle:Byte Ptr, format:Byte Ptr)
	Function bmx_qt_qtextcursor_setblockformat(handle:Byte Ptr, format:Byte Ptr)
	Function bmx_qt_qtextcursor_setcharformat(handle:Byte Ptr, format:Byte Ptr)
	Function bmx_qt_qtextcursor_setkeepoisitiononinsert(handle:Byte Ptr, value:Int)
	Function bmx_qt_qtextcursor_setposition(handle:Byte Ptr, pos:Int, Mode:Int)
	Function bmx_qt_qtextcursor_setverticalmovementx(handle:Byte Ptr, x:Int)
	Function bmx_qt_qtextcursor_setvisualnavigation(handle:Byte Ptr, value:Int)
	Function bmx_qt_qtextcursor_verticalmovementx:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcursor_visualnavigation:Int(handle:Byte Ptr)

End Extern

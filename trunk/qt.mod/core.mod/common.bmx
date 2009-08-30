' Copyright (c) 2009 Bruce A Henderson
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

Import BRL.Blitz
Import BRL.Map

' headers :-)
?win32
Import "../lib/win32/include/*.h"
?macos
Import "../lib/macos/include/*.h"
?Not linux
Import "../src/include/*.h"
Import "../src/include/Qt/*.h"
Import "../src/include/QtCore/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
?

Import "consts.bmx"

Import "glue.cpp"

Extern

	Function qfind:Object(handle:Byte Ptr)

	Function bmx_qt_qurl_create:Byte Ptr(url:String)
	Function bmx_qt_qurl_free(handle:Byte Ptr)
	Function bmx_qt_qurl_tostring:String(handle:Byte Ptr)

	Function bmx_qt_qrect_create:Byte Ptr(x:Int, y:Int, w:Int, h:Int)
	Function bmx_qt_qrect_free(handle:Byte Ptr)
	Function bmx_qt_qrect_adjust(handle:Byte Ptr, dx1:Int, dy1:Int, dx2:Int, dy2:Int)
	Function bmx_qt_qrect_adjusted:Byte Ptr(handle:Byte Ptr, dx1:Int, dy1:Int, dx2:Int, dy2:Int)
	Function bmx_qt_qrect_bottom:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_bottomleft(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qrect_bottomright(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qrect_center(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qrect_contains:Int(handle:Byte Ptr, x:Int, y:Int, proper:Int)
	Function bmx_qt_qrect_containsrect:Int(handle:Byte Ptr, rectangle:Byte Ptr, proper:Int)
	Function bmx_qt_qrect_getcoords(handle:Byte Ptr, x1:Int Ptr, y1:Int Ptr, x2:Int Ptr, y2:Int Ptr)
	Function bmx_qt_qrect_getrect(handle:Byte Ptr, x:Int Ptr, y:Int Ptr, width:Int Ptr, height:Int Ptr)
	Function bmx_qt_qrect_height:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_intersected:Byte Ptr(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qrect_intersects:Int(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qrect_isempty:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_isnull:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_isvalid:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_left:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_movebottom(handle:Byte Ptr, y:Int)
	Function bmx_qt_qrect_movebottomleft(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_movebottomright(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_movecenter(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_moveleft(handle:Byte Ptr, x:Int)
	Function bmx_qt_qrect_moveright(handle:Byte Ptr, x:Int)
	Function bmx_qt_qrect_moveto(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_movetop(handle:Byte Ptr, y:Int)
	Function bmx_qt_qrect_movetopleft(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_movetopright(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_normalized:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qrect_right:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_setbottom(handle:Byte Ptr, y:Int)
	Function bmx_qt_qrect_setbottomleft(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_setbottomright(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_setcoords(handle:Byte Ptr, x1:Int, y1:Int, x2:Int, y2:Int)
	Function bmx_qt_qrect_setheight(handle:Byte Ptr, height:Int)
	Function bmx_qt_qrect_setleft(handle:Byte Ptr, x:Int)
	Function bmx_qt_qrect_setrect(handle:Byte Ptr, x:Int, y:Int, width:Int, height:Int)
	Function bmx_qt_qrect_setright(handle:Byte Ptr, x:Int)
	Function bmx_qt_qrect_setsize(handle:Byte Ptr, w:Int, h:Int)
	Function bmx_qt_qrect_settop(handle:Byte Ptr, y:Int)
	Function bmx_qt_qrect_settopleft(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_settopright(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_setwidth(handle:Byte Ptr, width:Int)
	Function bmx_qt_qrect_setx(handle:Byte Ptr, x:Int)
	Function bmx_qt_qrect_sety(handle:Byte Ptr, y:Int)
	Function bmx_qt_qrect_size(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qrect_top:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_topleft(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qrect_topright(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qrect_translate(handle:Byte Ptr, dx:Int, dy:Int)
	Function bmx_qt_qrect_translated:Byte Ptr(handle:Byte Ptr, dx:Int, dy:Int)
	Function bmx_qt_qrect_united:Byte Ptr(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qrect_width:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_x:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_y:Int(handle:Byte Ptr)

	Function bmx_qt_qevent_accept(handle:Byte Ptr)
	Function bmx_qt_qevent_ignore(handle:Byte Ptr)
	Function bmx_qt_qevent_isaccepted:Int(handle:Byte Ptr)
	Function bmx_qt_qevent_setaccepted(handle:Byte Ptr, accepted:Int)
	Function bmx_qt_qevent_spontaneous:Int(handle:Byte Ptr)
	Function bmx_qt_qevent_gettype:Int(handle:Byte Ptr)

	Function bmx_qt_qtime_elapsed:Int(handle:Byte Ptr)
	Function bmx_qt_qtime_hour:Int(handle:Byte Ptr)
	Function bmx_qt_qtime_isnull:Int(handle:Byte Ptr)
	Function bmx_qt_qtime_isvalid:Int(handle:Byte Ptr)
	Function bmx_qt_qtime_minute:Int(handle:Byte Ptr)
	Function bmx_qt_qtime_msec:Int(handle:Byte Ptr)
	Function bmx_qt_qtime_msecsto:Int(handle:Byte Ptr, t:Byte Ptr)
	Function bmx_qt_qtime_restart(handle:Byte Ptr)
	Function bmx_qt_qtime_second:Int(handle:Byte Ptr)
	Function bmx_qt_qtime_secsto:Int(handle:Byte Ptr, t:Byte Ptr)
	Function bmx_qt_qtime_sethms:Int(handle:Byte Ptr, h:Int, m:Int, s:Int, ms:Int)
	Function bmx_qt_qtime_start(handle:Byte Ptr)
	Function bmx_qt_qtime_currenttime:Byte Ptr()
	Function bmx_qt_qtime_free(handle:Byte Ptr)

	Function bmx_qt_qrectf_create:Byte Ptr(x:Double, y:Double, w:Double, h:Double)
	Function bmx_qt_qrectf_free(handle:Byte Ptr)
	Function bmx_qt_qrectf_adjust(handle:Byte Ptr, dx1:Double, dy1:Double, dx2:Double, dy2:Double)
	Function bmx_qt_qrectf_adjusted:Byte Ptr(handle:Byte Ptr, dx1:Double, dy1:Double, dx2:Double, dy2:Double)
	Function bmx_qt_qrectf_bottom:Double(handle:Byte Ptr)
	Function bmx_qt_qrectf_bottomleft(handle:Byte Ptr, x:Double Ptr, y:Double Ptr)
	Function bmx_qt_qrectf_bottomright(handle:Byte Ptr, x:Double Ptr, y:Double Ptr)
	Function bmx_qt_qrectf_center(handle:Byte Ptr, x:Double Ptr, y:Double Ptr)
	Function bmx_qt_qrectf_contains:Int(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_containsrect:Int(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qrectf_getcoords(handle:Byte Ptr, x1:Double Ptr, y1:Double Ptr, x2:Double Ptr, y2:Double Ptr)
	Function bmx_qt_qrectf_getrect(handle:Byte Ptr, x:Double Ptr, y:Double Ptr, width:Double Ptr, height:Double Ptr)
	Function bmx_qt_qrectf_height:Double(handle:Byte Ptr)
	Function bmx_qt_qrectf_intersected:Byte Ptr(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qrectf_intersects:Int(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qrectf_isempty:Int(handle:Byte Ptr)
	Function bmx_qt_qrectf_isnull:Int(handle:Byte Ptr)
	Function bmx_qt_qrectf_isvalid:Int(handle:Byte Ptr)
	Function bmx_qt_qrectf_left:Double(handle:Byte Ptr)
	Function bmx_qt_qrectf_movebottom(handle:Byte Ptr, y:Double)
	Function bmx_qt_qrectf_movebottomleft(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_movebottomright(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_movecenter(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_moveleft(handle:Byte Ptr, x:Double)
	Function bmx_qt_qrectf_moveright(handle:Byte Ptr, x:Double)
	Function bmx_qt_qrectf_moveto(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_movetop(handle:Byte Ptr, y:Double)
	Function bmx_qt_qrectf_movetopleft(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_movetopright(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_normalized:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qrectf_right:Double(handle:Byte Ptr)
	Function bmx_qt_qrectf_setbottom(handle:Byte Ptr, y:Double)
	Function bmx_qt_qrectf_setbottomleft(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_setbottomright(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_setcoords(handle:Byte Ptr, x1:Double, y1:Double, x2:Double, y2:Double)
	Function bmx_qt_qrectf_setheight(handle:Byte Ptr, height:Double)
	Function bmx_qt_qrectf_setleft(handle:Byte Ptr, x:Double)
	Function bmx_qt_qrectf_setrect(handle:Byte Ptr, x:Double, y:Double, width:Double, height:Double)
	Function bmx_qt_qrectf_setright(handle:Byte Ptr, x:Double)
	Function bmx_qt_qrectf_setsize(handle:Byte Ptr, w:Double, h:Double)
	Function bmx_qt_qrectf_settop(handle:Byte Ptr, y:Double)
	Function bmx_qt_qrectf_settopleft(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_settopright(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qrectf_setwidth(handle:Byte Ptr, width:Double)
	Function bmx_qt_qrectf_setx(handle:Byte Ptr, x:Double)
	Function bmx_qt_qrectf_sety(handle:Byte Ptr, y:Double)
	Function bmx_qt_qrectf_size(handle:Byte Ptr, w:Double Ptr, h:Double Ptr)
	Function bmx_qt_qrectf_top:Double(handle:Byte Ptr)
	Function bmx_qt_qrectf_topleft(handle:Byte Ptr, x:Double Ptr, y:Double Ptr)
	Function bmx_qt_qrectf_topright(handle:Byte Ptr, x:Double Ptr, y:Double Ptr)
	Function bmx_qt_qrectf_translate(handle:Byte Ptr, dx:Double, dy:Double)
	Function bmx_qt_qrectf_translated:Byte Ptr(handle:Byte Ptr, dx:Double, dy:Double)
	Function bmx_qt_qrectf_united:Byte Ptr(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qrectf_width:Double(handle:Byte Ptr)
	Function bmx_qt_qrectf_x:Double(handle:Byte Ptr)
	Function bmx_qt_qrectf_y:Double(handle:Byte Ptr)

	Function bmx_qt_qsize_scale(w:Int Ptr, h:Int Ptr, scaleW:Int, scaleH:Int, _mode:Int)

	Function bmx_qt_qdate_create:Byte Ptr(y:Int, m:Int, d:Int)
	Function bmx_qt_qdate_free(handle:Byte Ptr)
	Function bmx_qt_qdate_adddays:Byte Ptr(handle:Byte Ptr, ndays:Int)
	Function bmx_qt_qdate_addmonths:Byte Ptr(handle:Byte Ptr, nmonths:Int)
	Function bmx_qt_qdate_addYears:Byte Ptr(handle:Byte Ptr, nyears:Int)
	Function bmx_qt_qdate_day:Int(handle:Byte Ptr)
	Function bmx_qt_qdate_dayofweek:Int(handle:Byte Ptr)
	Function bmx_qt_qdate_dayofyear:Int(handle:Byte Ptr)
	Function bmx_qt_qdate_daysinmonth:Int(handle:Byte Ptr)
	Function bmx_qt_qdate_daysinyear:Int(handle:Byte Ptr)
	Function bmx_qt_qdate_daysto:Int(handle:Byte Ptr, d:Byte Ptr)
	Function bmx_qt_qdate_getdate(handle:Byte Ptr, year:Int Ptr, _month:Int Ptr, day:Int Ptr)
	Function bmx_qt_qdate_isnull:Int(handle:Byte Ptr)
	Function bmx_qt_qdate_isvalid:Int(handle:Byte Ptr)
	Function bmx_qt_qdate_month:Int(handle:Byte Ptr)
	Function bmx_qt_qdate_setdate:Int(handle:Byte Ptr, year:Int, _month:Int, day:Int)
	Function bmx_qt_qdate_tojulianday:Int(handle:Byte Ptr)
	Function bmx_qt_qdate_toformatedstring:String(handle:Byte Ptr, format:String)
	Function bmx_qt_qdate_tostring:String(handle:Byte Ptr)
	Function bmx_qt_qdate_weeknumber:Int(handle:Byte Ptr, yearNumber:Int Ptr)
	Function bmx_qt_qdate_year:Int(handle:Byte Ptr)


End Extern

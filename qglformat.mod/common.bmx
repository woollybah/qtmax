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
Import "../src/include/QtOpenGL/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/QtCore/*.h"
Import "/usr/include/qt4/QtOpenGL/*.h"
Import "/usr/include/QtOpenGL/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qglformat_create:Byte Ptr(formatOptions:Int, plane:Int)
	Function bmx_qt_qglformat_defaultformat:Byte Ptr()
	Function bmx_qt_qglformat_defaultoverlayformat:Byte Ptr()
	Function bmx_qt_qglformat_hasopengl:Int()
	Function bmx_qt_qglformat_hasopengloverlays:Int()
	Function bmx_qt_qglformat_openglversionflags:Int()
	Function bmx_qt_qglformat_setdefaultformat(format:Byte Ptr)
	Function bmx_qt_qglformat_setdefaultoverayformat(format:Byte Ptr)
	Function bmx_qt_qglformat_accum:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_accumbuffersize:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_alpha:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_alphabuffersize:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_bluebuffersize:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_depth:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_depthbuffersize:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_directrendering:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_doublebuffer:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_greenbuffersize:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_hasoverlay:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_majorversion:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_minorversion:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_plane:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_profile:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_redbuffersize:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_rgba:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_samplebuffers:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_samples:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_setaccum(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qglformat_setaccumbuffersize(handle:Byte Ptr, size:Int)
	Function bmx_qt_qglformat_setalpha(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qglformat_setalphabuffersize(handle:Byte Ptr, size:Int)
	Function bmx_qt_qglformat_setbluebuffersize(handle:Byte Ptr, size:Int)
	Function bmx_qt_qglformat_setdepth(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qglformat_setdepthbuffersize(handle:Byte Ptr, size:Int)
	Function bmx_qt_qglformat_setdirectrendering(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qglformat_setdoublebuffer(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qglformat_setgreenbuffersize(handle:Byte Ptr, size:Int)
	Function bmx_qt_qglformat_setoption(handle:Byte Ptr, opt:Int)
	Function bmx_qt_qglformat_setoverlay(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qglformat_setplane(handle:Byte Ptr, plane:Int)
	Function bmx_qt_qglformat_setprofile(handle:Byte Ptr, profile:Int)
	Function bmx_qt_qglformat_setredbuffersize(handle:Byte Ptr, size:Int)
	Function bmx_qt_qglformat_setrgba(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qglformat_setsamplebuffers(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qglformat_setsamples(handle:Byte Ptr, numSamples:Int)
	Function bmx_qt_qglformat_setstencil(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qglformat_setstencilbuffersize(handle:Byte Ptr, size:Int)
	Function bmx_qt_qglformat_setstereo(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qglformat_setswapinterval(handle:Byte Ptr, interval:Int)
	Function bmx_qt_qglformat_setversion(handle:Byte Ptr, major:Int, minor:Int)
	Function bmx_qt_qglformat_stencil:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_stencilbuffersize:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_stereo:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_swapinterval:Int(handle:Byte Ptr)
	Function bmx_qt_qglformat_testoption:Int(handle:Byte Ptr, opt:Int)
	Function bmx_qt_qglformat_free(handle:Byte Ptr)

End Extern

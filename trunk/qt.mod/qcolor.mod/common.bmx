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
Import "../src/include/QtGui/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qcolor_free(handle:Byte Ptr)

	Function bmx_qt_qcolor_create:Byte Ptr(r:Int, g:Int, b:Int, a:Int)
	Function bmx_qt_qcolor_createwithglobalcolor:Byte Ptr(color:Int)
	Function bmx_qt_qcolor_lighter:Byte Ptr(handle:Byte Ptr, factor:Int)

	Function bmx_qt_qcolor_getrgb(handle:Byte Ptr, r:Int Ptr, g:Int Ptr, b:Int Ptr)
	Function bmx_qt_qcolor_getrgba(handle:Byte Ptr, r:Int Ptr, g:Int Ptr, b:Int Ptr, a:Int Ptr)
	Function bmx_qt_qcolor_isvalid:Int(handle:Byte Ptr)

End Extern


Rem
bbdoc:  White (#ffffff)
end rem
Const Qt_white:Int = 3
Rem
bbdoc: Black (#000000)
end rem
Const Qt_black:Int = 2
Rem
bbdoc: Red (#ff0000)
end rem
Const Qt_red:Int = 7
Rem
bbdoc: Dark red (#800000)
end rem
Const Qt_darkRed:Int = 13
Rem
bbdoc: Green (#00ff00)
end rem
Const Qt_green:Int = 8
Rem
bbdoc: Dark green (#008000)
end rem
Const Qt_darkGreen:Int = 14
Rem
bbdoc: Blue (#0000ff)
end rem
Const Qt_blue:Int = 9
Rem
bbdoc: Dark blue (#000080)
end rem
Const Qt_darkBlue:Int = 15
Rem
bbdoc: Cyan (#00ffff)
end rem
Const Qt_cyan:Int = 10
Rem
bbdoc: Dark cyan (#008080)
end rem
Const Qt_darkCyan:Int = 16
Rem
bbdoc: Magenta (#ff00ff)
end rem
Const Qt_magenta:Int = 11
Rem
bbdoc: Dark magenta (#800080)
end rem
Const Qt_darkMagenta:Int = 17
Rem
bbdoc: Yellow (#ffff00)
end rem
Const Qt_yellow:Int = 12
Rem
bbdoc: Dark yellow (#808000)
end rem
Const Qt_darkYellow:Int = 18
Rem
bbdoc: Gray (#a0a0a4)
end rem
Const Qt_gray:Int = 5
Rem
bbdoc: Dark gray (#808080)
end rem
Const Qt_darkGray:Int = 4
Rem
bbdoc: Light gray (#c0c0c0)
end rem
Const Qt_lightGray:Int = 6
Rem
bbdoc: a transparent black value (i.e., QColor(0, 0, 0, 0))
end rem
Const Qt_transparent:Int = 19
Rem
bbdoc: 0 pixel value (for bitmaps)
end rem
Const Qt_color0:Int = 0
Rem
bbdoc: 1 pixel value (for bitmaps)
end rem
Const Qt_color1:Int = 1

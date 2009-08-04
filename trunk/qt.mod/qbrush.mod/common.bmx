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
Import Qt.QGradient
Import Qt.QPixmap
Import Qt.QPainterPath
Import Qt.QImage
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

	Function bmx_qt_qbrush_create:Byte Ptr()
	Function bmx_qt_qbrush_createwithglobalcolor:Byte Ptr(color:Int, style:Int)
	Function bmx_qt_qbrush_free(handle:Byte Ptr)


End Extern

Rem
bbdoc: No brush pattern.
end rem
Const Qt_NoBrush:Int = 0
Rem
bbdoc: Uniform color.
end rem
Const Qt_SolidPattern:Int = 1
Rem
bbdoc: Extremely dense brush pattern.
end rem
Const Qt_Dense1Pattern:Int = 2
Rem
bbdoc: Very dense brush pattern.
end rem
Const Qt_Dense2Pattern:Int = 3
Rem
bbdoc: Somewhat dense brush pattern.
end rem
Const Qt_Dense3Pattern:Int = 4
Rem
bbdoc: Half dense brush pattern.
end rem
Const Qt_Dense4Pattern:Int = 5
Rem
bbdoc: Somewhat sparse brush pattern.
end rem
Const Qt_Dense5Pattern:Int = 6
Rem
bbdoc: Very sparse brush pattern.
end rem
Const Qt_Dense6Pattern:Int = 7
Rem
bbdoc: Extremely sparse brush pattern.
end rem
Const Qt_Dense7Pattern:Int = 8
Rem
bbdoc: Horizontal lines.
end rem
Const Qt_HorPattern:Int = 9
Rem
bbdoc: Vertical lines.
end rem
Const Qt_VerPattern:Int = 10
Rem
bbdoc: Crossing horizontal and vertical lines.
end rem
Const Qt_CrossPattern:Int = 11
Rem
bbdoc: Backward diagonal lines.
end rem
Const Qt_BDiagPattern:Int = 12
Rem
bbdoc: Forward diagonal lines.
end rem
Const Qt_FDiagPattern:Int = 13
Rem
bbdoc: Crossing diagonal lines.
end rem
Const Qt_DiagCrossPattern:Int = 14
Rem
bbdoc: Linear gradient (set using a dedicated QBrush constructor).
end rem
Const Qt_LinearGradientPattern:Int = 15
Rem
bbdoc: Conical gradient (set using a dedicated QBrush constructor).
end rem
Const Qt_ConicalGradientPattern:Int = 17
Rem
bbdoc: Radial gradient (set using a dedicated QBrush constructor).
end rem
Const Qt_RadialGradientPattern:Int = 16
Rem
bbdoc: Custom pattern (see QBrush_setTexture()).
end rem
Const Qt_TexturePattern:Int = 24


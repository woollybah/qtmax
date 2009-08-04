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

Module Qt.QPainter

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QPainter

	Rem
	bbdoc: This is the default composition mode.
	about: The alpha of the source is used to blend the pixel on top of the destination.
	End Rem
	Const CompositionMode_SourceOver:Int = 0
	Rem
	bbdoc: The alpha of the destination is used to blend it on top of the source pixels.
	about: This mode is the inverse of CompositionMode_SourceOver.
	end rem
	Const CompositionMode_DestinationOver:Int = 1
	Rem
	bbdoc: The pixels in the destination are cleared (set to fully transparent) independent of the source.
	end rem
	Const CompositionMode_Clear:Int = 2
	Rem
	bbdoc: The output is the source pixel.
	about: This means a basic copy operation and is identical to SourceOver when the source pixel is opaque.
	end rem
	Const CompositionMode_Source:Int = 3
	Rem
	bbdoc: The output is the destination pixel.
	about: This means that the blending has no effect. This mode is the inverse of CompositionMode_Source.
	end rem
	Const CompositionMode_Destination:Int = 4
	Rem
	bbdoc: The output is the source, where the alpha is reduced by that of the destination.
	end rem
	Const CompositionMode_SourceIn:Int = 5
	Rem
	bbdoc: The output is the destination, where the alpha is reduced by that of the source.
	about: This mode is the inverse of CompositionMode_SourceIn.
	end rem
	Const CompositionMode_DestinationIn:Int = 6
	Rem
	bbdoc: The output is the source, where the alpha is reduced by the inverse of destination.
	end rem
	Const CompositionMode_SourceOut:Int = 7
	Rem
	bbdoc: The output is the destination, where the alpha is reduced by the inverse of the source.
	about: This mode is the inverse of CompositionMode_SourceOut.
	end rem
	Const CompositionMode_DestinationOut:Int = 8
	Rem
	bbdoc: The source pixel is blended on top of the destination, with the alpha of the source pixel reduced by the alpha of the destination pixel.
	end rem
	Const CompositionMode_SourceAtop:Int = 9
	Rem
	bbdoc: The destination pixel is blended on top of the source, with the alpha of the destination pixel is reduced by the alpha of the destination pixel.
	about: This mode is the inverse of CompositionMode_SourceAtop.
	end rem
	Const CompositionMode_DestinationAtop:Int = 10
	Rem
	bbdoc: The source, whose alpha is reduced with the inverse of the destination alpha, is merged with the destination, whose alpha is reduced by the inverse of the source alpha.
	about: CompositionMode_Xor is not the same as the bitwise Xor.
	end rem
	Const CompositionMode_Xor:Int = 11
	Rem
	bbdoc: Both the alpha and color of the source and destination pixels are added together.
	end rem
	Const CompositionMode_Plus:Int = 12
	Rem
	bbdoc: The output is the source color multiplied by the destination.
	about: Multiplying a color with white leaves the color unchanged, while multiplying a color with black produces black.
	end rem
	Const CompositionMode_Multiply:Int = 13
	Rem
	bbdoc: The source and destination colors are inverted and then multiplied.
	about: Screening a color with white produces white, whereas screening a color with black leaves the color unchanged.
	end rem
	Const CompositionMode_Screen:Int = 14
	Rem
	bbdoc: Multiplies or screens the colors depending on the destination color.
	about: The destination color is mixed with the source color to reflect the lightness or darkness of the destination.
	end rem
	Const CompositionMode_Overlay:Int = 15
	Rem
	bbdoc: The darker of the source and destination colors is selected.
	end rem
	Const CompositionMode_Darken:Int = 16
	Rem
	bbdoc: The lighter of the source and destination colors is selected.
	end rem
	Const CompositionMode_Lighten:Int = 17
	Rem
	bbdoc: The destination color is brightened to reflect the source color.
	about: A black source color leaves the destination color unchanged.
	end rem
	Const CompositionMode_ColorDodge:Int = 18
	Rem
	bbdoc: The destination color is darkened to reflect the source color.
	about: A white source color leaves the destination color unchanged.
	end rem
	Const CompositionMode_ColorBurn:Int = 19
	Rem
	bbdoc: Multiplies or screens the colors depending on the source color.
	about: A light source color will lighten the destination color, whereas a dark source color will darken the destination color.
	end rem
	Const CompositionMode_HardLight:Int = 20
	Rem
	bbdoc: Darkens or lightens the colors depending on the source color.
	about: Similar to CompositionMode_HardLight.
	end rem
	Const CompositionMode_SoftLight:Int = 21
	Rem
	bbdoc: Subtracts the darker of the colors from the lighter.
	about: Painting with white inverts the destination color, whereas painting with black leaves the destination color unchanged.
	end rem
	Const CompositionMode_Difference:Int = 22
	Rem
	bbdoc: Similar to CompositionMode_Difference, but with a lower contrast.
	about: Painting with white inverts the destination color, whereas painting with black leaves the destination color unchanged.
	end rem
	Const CompositionMode_Exclusion:Int = 23
	Rem
	bbdoc: Does a bitwise OR operation on the source and destination pixels (src OR dst).
	end rem
	Const RasterOp_SourceOrDestination:Int = 24
	Rem
	bbdoc: Does a bitwise AND operation on the source and destination pixels (src AND dst).
	end rem
	Const RasterOp_SourceAndDestination:Int = 25
	Rem
	bbdoc: Does a bitwise XOR operation on the source and destination pixels (src XOR dst).
	end rem
	Const RasterOp_SourceXorDestination:Int = 26
	Rem
	bbdoc: Does a bitwise NOR operation on the source and destination pixels ((NOT src) AND (NOT dst)).
	end rem
	Const RasterOp_NotSourceAndNotDestination:Int = 27
	Rem
	bbdoc: Does a bitwise NAND operation on the source and destination pixels ((NOT src) OR (NOT dst)).
	end rem
	Const RasterOp_NotSourceOrNotDestination:Int = 28
	Rem
	bbdoc: Does a bitwise operation where the source pixels are inverted and then XOR'ed with the destination ((NOT src) XOR dst).
	end rem
	Const RasterOp_NotSourceXorDestination:Int = 29
	Rem
	bbdoc: Does a bitwise operation where the source pixels are inverted (NOT src).
	end rem
	Const RasterOp_NotSource:Int = 30
	Rem
	bbdoc: Does a bitwise operation where the source is inverted and then AND'ed with the destination ((NOT src) AND dst).
	end rem
	Const RasterOp_NotSourceAndDestination:Int = 31
	Rem
	bbdoc: Does a bitwise operation where the source is AND'ed with the inverted destination pixels (src AND (NOT dst)).
	end rem
	Const RasterOp_SourceAndNotDestination:Int = 32

	Rem
	bbdoc: Indicates that the engine should antialias edges of primitives if possible.
	End Rem
	Const Antialiasing:Int = $01
	Rem
	bbdoc: Indicates that the engine should antialias text if possible.
	about: To forcibly disable antialiasing for text, do not use this hint. Instead, set QFont::NoAntialias on
	your font's style strategy.
	End Rem
	Const TextAntialiasing:Int = $02
	Rem
	bbdoc: Indicates that the engine should use a smooth pixmap transformation algorithm (such as bilinear) rather than nearest neighbor.
	End Rem
	Const SmoothPixmapTransform:Int = $04
	Rem
	bbdoc: An OpenGL-specific rendering hint indicating that the engine should use fragment programs and offscreen rendering for antialiasing.
	End Rem
	Const HighQualityAntialiasing:Int = $08
	Rem
	bbdoc: The engine should interpret pens with a width of 0 (which otherwise enables QPen::isCosmetic()) as being a non-cosmetic pen with a width of 1.
	End Rem
	Const NonCosmeticDefaultPen:Int = $10


	Field qObjectPtr:Byte Ptr
	Field _owner:Int = False
	
	Function _create:QPainter(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QPainter = New QPainter
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function CreatePainter:QPainter(device:Object)
		Return New QPainter.Create(device)
	End Function
	
	Method Create:QPainter(device:Object)
		Local obj:QCoreObjectPtr = QCoreObjectPtr(device)
		If obj Then
			qObjectPtr = bmx_qt_qpainter_create(obj.qObjectPtr)
			_owner = True
			Return Self
		End If
	End Method
	
	Method doBegin:Int(device:Object)
		If _owner Then
			Local obj:QCoreObjectPtr = QCoreObjectPtr(device)
			If obj Then
				Return bmx_qt_qpainter_begin(qObjectPtr, obj.qObjectPtr)
			End If
		End If
	End Method
	
	Method doEnd:Int()
		If _owner Then
			Local res:Int = bmx_qt_qpainter_end(qObjectPtr)
			Free()
			Return res
		End If
	End Method
	
	Method drawConvexPolygon(points:Int[])
		bmx_qt_qpainter_drawConvexPolygon(qObjectPtr, points)
	End Method

	Method drawConvexPolygonD(points:Double[])
		bmx_qt_qpainter_drawConvexPolygond(qObjectPtr, points)
	End Method
	
	Method drawEllipse(x:Int, y:Int, width:Int, height:Int)
		bmx_qt_qpainter_drawEllipse(qObjectPtr, x, y, width, height)
	End Method

	Method drawEllipseRect(rect:QRect)
	End Method
	
	Method drawEllipseCenter(cx:Int, cy:Int, rx:Int, ry:Int)
		bmx_qt_qpainter_drawEllipsecenter(qObjectPtr, cx, cy, rx, ry)
	End Method

	Method drawEllipseCenterD(cx:Double, cy:Double, rx:Double, ry:Double)
		bmx_qt_qpainter_drawEllipsecenterd(qObjectPtr, cx, cy, rx, ry)
	End Method
	
	Method DrawLine(x1:Int, y1:Int, x2:Int, y2:Int)
		bmx_qt_qpainter_drawline(qObjectPtr, x1, y1, x2, y2)
	End Method

	Method drawLineD(x1:Double, y1:Double, x2:Double, y2:Double)
		bmx_qt_qpainter_drawlined(qObjectPtr, x1, y1, x2, y2)
	End Method
	
	Method DrawRectRect(rectangle:QRect)
		bmx_qt_qpainter_drawrectrect(qObjectPtr, rectangle.qObjectPtr)
	End Method
	
	Method DrawRect(x:Int, y:Int, width:Int, height:Int)
		bmx_qt_qpainter_drawrect(qObjectPtr, x, y, width, height)
	End Method
	
	Method DrawText(x:Int, y:Int, text:String)
		bmx_qt_qpainter_drawtext(qObjectPtr, x, y, text)
	End Method

	Method fillPath(path:QPainterPath, brush:QBrush)
		bmx_qt_qpainter_fillpath(qObjectPtr, path.qObjectPtr, brush.qObjectPtr)
	End Method
	
	Method fillRect(x:Int, y:Int, width:Int, height:Int, style:Int)
		bmx_qt_qpainter_fillrect(qObjectPtr, x, y, width, height, style)
	End Method
	
	Method fillRectRect(rectangle:QRect, style:Int)
		bmx_qt_qpainter_fillrectrect(qObjectPtr, rectangle.qObjectPtr, style)
	End Method

	Method fillRectBrush(x:Int, y:Int, width:Int, height:Int, brush:QBrush)
		bmx_qt_qpainter_fillrectbrush(qObjectPtr, x, y, width, height, brush.qObjectPtr)
	End Method
	
	Method fillRectRectBrush(rectangle:QRect, brush:QBrush)
		bmx_qt_qpainter_fillrectrectbrush(qObjectPtr, rectangle.qObjectPtr, brush.qObjectPtr)
	End Method
	
	Method resetMatrix()
		bmx_qt_qpainter_resetmatrix(qObjectPtr)
	End Method
	
	Method resetTransform()
		bmx_qt_qpainter_resettransform(qObjectPtr)
	End Method
	
	Method restore()
		bmx_qt_qpainter_restore(qObjectPtr)
	End Method
	
	Method rotate(angle:Double)
		bmx_qt_qpainter_rotate(qObjectPtr, angle)
	End Method

	Method save()
		bmx_qt_qpainter_save(qObjectPtr)
	End Method
	
	Method scale(sx:Double, sy:Double)
		bmx_qt_qpainter_scale(qObjectPtr, sx, sy)
	End Method

	Method setBackground(brush:QBrush)
	' TODO
	End Method
	
	Method setBackgroundMode(Mode:Int)
	' TODO
	End Method
	
	Method setBrush(brush:QBrush)
		bmx_qt_qpainter_setbrush(qObjectPtr, brush.qObjectPtr)
	End Method

	Method setBrushColor(color:QColor)
		bmx_qt_qpainter_setbrushcolor(qObjectPtr, color.qObjectPtr)
	End Method

	Method setBrushGradient(gradient:QGradient)
		bmx_qt_qpainter_setbrushgradient(qObjectPtr, gradient.qObjectPtr)
	End Method
	
	Method setBrushStyle(style:Int)
	' TODO
	End Method

	Method setClipping(enable:Int)
	' TODO
	End Method
	
	Method setCompositionMode(Mode:Int)
	' TODO
	End Method
	
	Method setFont(font:QFont)
	' TODO
	End Method
	
	Method setLayoutDirection(direction:Int)
	' TODO
	End Method
	
	Method setOpacity(opacity:Double)
	' TODO
	End Method
	
	Method setPen(pen:QPen)
	' TODO
	End Method
	
	Method setPenColor(color:QColor)
		bmx_qt_qpainter_setpencolor(qObjectPtr, color.qObjectPtr)
	End Method
	
	Method setPenStyle(style:Int)
		bmx_qt_qpainter_setpenstyle(qObjectPtr, style)
	End Method

	Method setRenderHint(hint:Int, on:Int = True)
		bmx_qt_qpainter_setrenderhint(qObjectPtr, hint, on)
	End Method
	
	Method translate(dx:Double, dy:Double)
		bmx_qt_qpainter_translate(qObjectPtr, dx, dy)
	End Method
	
	Method Free()
		If qObjectPtr And _owner Then
			bmx_qt_qpainter_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method

	Method Delete()
		Free()
	End Method
	
End Type


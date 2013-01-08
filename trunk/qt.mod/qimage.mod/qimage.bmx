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

Module Qt.QImage

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QImage Extends QPaintDevice

	Rem
	bbdoc: The image is invalid.
	end rem
	Const Format_Invalid:Int = 0
	Rem
	bbdoc: The image is stored using 1-bit per pixel. Bytes are packed with the most significant bit (MSB) first.
	end rem
	Const Format_Mono:Int = 1
	Rem
	bbdoc: The image is stored using 1-bit per pixel. Bytes are packed with the less significant bit (LSB) first.
	end rem
	Const Format_MonoLSB:Int = 2
	Rem
	bbdoc: The image is stored using 8-bit indexes into a colormap.
	end rem
	Const Format_Indexed8:Int = 3
	Rem
	bbdoc: The image is stored using a 32-bit RGB format (0xffRRGGBB).
	end rem
	Const Format_RGB32:Int = 4
	Rem
	bbdoc: The image is stored using a 32-bit ARGB format (0xAARRGGBB).
	end rem
	Const Format_ARGB32:Int = 5
	Rem
	bbdoc: The image is stored using a premultiplied 32-bit ARGB format (0xAARRGGBB), i.e. the red, green, and blue channels are multiplied by the alpha component divided by 255. (If RR, GG, or BB has a higher value than the alpha channel, the results are undefined.) Certain operations (such as image composition using alpha blending) are faster using premultiplied ARGB32 than with plain ARGB32.
	end rem
	Const Format_ARGB32_Premultiplied:Int = 6
	Rem
	bbdoc: The image is stored using a 16-bit RGB format (5-6-5).
	end rem
	Const Format_RGB16:Int = 7
	Rem
	bbdoc: The image is stored using a premultiplied 24-bit ARGB format (8-5-6-5).
	end rem
	Const Format_ARGB8565_Premultiplied:Int = 8
	Rem
	bbdoc: The image is stored using a 24-bit RGB format (6-6-6). The unused most significant bits is always zero.
	end rem
	Const Format_RGB666:Int = 9
	Rem
	bbdoc: The image is stored using a premultiplied 24-bit ARGB format (6-6-6-6).
	end rem
	Const Format_ARGB6666_Premultiplied:Int = 10
	Rem
	bbdoc: The image is stored using a 16-bit RGB format (5-5-5). The unused most significant bit is always zero.
	end rem
	Const Format_RGB555:Int = 11
	Rem
	bbdoc: The image is stored using a premultiplied 24-bit ARGB format (8-5-5-5).
	end rem
	Const Format_ARGB8555_Premultiplied:Int = 12
	Rem
	bbdoc: The image is stored using a 24-bit RGB format (8-8-8).
	end rem
	Const Format_RGB888:Int = 13
	Rem
	bbdoc: The image is stored using a 16-bit RGB format (4-4-4). The unused bits are always zero.
	end rem
	Const Format_RGB444:Int = 14
	Rem
	bbdoc: The image is stored using a premultiplied 16-bit ARGB format (4-4-4-4).
	end rem
	Const Format_ARGB4444_Premultiplied:Int = 15
	
	Function _create:QImage(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QImage = New QImage
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function CreateImage:QImage(width:Int, height:Int, format:Int)
		Return New QImage.Create(width, height, format)
	End Function
	
	Method Create:QImage(width:Int, height:Int, format:Int)
		qObjectPtr = bmx_qt_qimage_create(width, height, format)
		Return Self
	End Method

	Method CreateWithData:QImage(data:Byte Ptr, width:Int, height:Int, bytesPerLine:Int, format:Int)
		qObjectPtr = bmx_qt_qimage_createwithdata(data, width, height, bytesPerLine, format)
		Return Self
	End Method
	
	Method CreateWithPixmap:QImage(pixmap:TPixmap)
		If pixmap.format = PF_BGRA8888 Or pixmap.format = PF_RGBA8888 Then
			' convert pixels
			Local pix:TPixmap = TPixmap.Create(pixmap.width, pixmap.height, pixmap.format)
			For Local y:Int = 0 Until pixmap.height
				ConvertPixelsToARGB(pixmap.PixelPtr(0,y), pix.PixelPtr(0,y), pix.format, pixmap.width)
			Next

			Return CreateWithData(pix.pixels, pix.width, pix.height, pix.pitch, Format_ARGB32)
		Else
			Return CreateWithData(pixmap.pixels, pixmap.width, pixmap.height, pixmap.pitch, imageFormatFromPixmapFormat(pixmap.format))
		End If
	End Method

	Function ConvertPixelsToARGB( in_buf:Byte Ptr,out_buf:Byte Ptr,format:Int, count:Int )
		Local in:Byte Ptr=in_buf
		Local out:Byte Ptr=out_buf
		Local out_end:Byte Ptr=out+count*4
		Select format
			Case PF_BGRA8888
				While out<>out_end
					out[0]=in[2]
					out[1]=in[1]
					out[2]=in[0]
					out[3]=in[3]
					in:+4;out:+4
				Wend
			Case PF_RGBA8888
				While out<>out_end
					out[0]=in[2]
					out[1]=in[1]
					out[2]=in[0]
					out[3]=in[3]
					in:+4;out:+4
				Wend
		End Select
	End Function
	
	Method imageFormatFromPixmapFormat:Int(format:Int)
		Select format
			Case PF_I8
				Return Format_Indexed8
			Case PF_BGR888
				Return Format_RGB888
			Case PF_RGB888
				Return Format_RGB888
			Case PF_BGRA8888
				Return Format_ARGB32
			Case PF_RGBA8888
				Return Format_ARGB32
			'Case PF_ARGB8888
			'	Return Format_ARGB32
		End Select
	End Method
	
	Method allGray:Int()
	' TODO
	End Method
	
	Method bits:Byte Ptr()
	' TODO
	End Method
	
	Method bytesPerLine:Int()
	' TODO
	End Method
	
	Method cacheKey:Long()
	' TODO
	End Method
	
	'Method color:QRgb(index:Int)
	' TODO
	'End Method
	
	Method depth:Int()
	' TODO
	End Method
	
	Method dotsPerMeterX:Int()
	' TODO
	End Method
	
	Method dotsPerMeterY:Int()
	' TODO
	End Method
	
	Method size(w:Int Var, h:Int Var)
		bmx_qt_qimage_size(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qimage_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method
	
End Type


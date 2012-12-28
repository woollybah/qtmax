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

Module Qt.QGLFormat

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"



Type QGLFormat

	Field qObjectPtr:Byte Ptr
	
	' CONTEXT PROFILE
	Rem
	bbdoc: OpenGL version is lower than 3.2.
	end rem
	Const NoProfile:Int = 0
	
	Rem
	bbdoc: Functionality deprecated in OpenGL version 3.0 is not available.
	end rem
	Const CoreProfile:Int = 1
	
	Rem
	bbdoc: Functionality from earlier OpenGL versions is available.
	end rem
	Const CompatibilityProfile:Int = 2
	
	' VERSION FLAG
	Rem
	bbdoc: If no OpenGL is present or if no OpenGL context is current.
	end rem
	Const OpenGL_Version_None:Int = $00000000

	Rem
	bbdoc: OpenGL version 1.1 or higher is present.
	end rem
	Const OpenGL_Version_1_1:Int = $00000001

	Rem
	bbdoc: OpenGL version 1.2 or higher is present.
	end rem
	Const OpenGL_Version_1_2:Int = $00000002

	Rem
	bbdoc: OpenGL version 1.3 or higher is present.
	end rem
	Const OpenGL_Version_1_3:Int = $00000004

	Rem
	bbdoc: OpenGL version 1.4 or higher is present.
	end rem
	Const OpenGL_Version_1_4:Int = $00000008

	Rem
	bbdoc: OpenGL version 1.5 or higher is present.
	end rem
	Const OpenGL_Version_1_5:Int = $00000010

	Rem
	bbdoc: OpenGL version 2.0 or higher is present.
	about: Note that version 2.0 supports all the functionality of version 1.5.
	End Rem
	Const OpenGL_Version_2_0:Int = $00000020

	Rem
	bbdoc: OpenGL version 2.1 or higher is present.
	end rem
	Const OpenGL_Version_2_1:Int = $00000040

	Rem
	bbdoc: OpenGL version 3.0 or higher is present.
	end rem
	Const OpenGL_Version_3_0:Int = $00001000

	Rem
	bbdoc: OpenGL version 3.1 or higher is present.
	about: Note that OpenGL version 3.1 or higher does not necessarily support all the features of version 3.0 and lower.
	End Rem
	Const OpenGL_Version_3_1:Int = $00002000

	Rem
	bbdoc: OpenGL version 3.2 or higher is present.
	end rem
	Const OpenGL_Version_3_2:Int = $00004000

	Rem
	bbdoc: OpenGL version 3.3 or higher is present.
	end rem
	Const OpenGL_Version_3_3:Int = $00008000

	Rem
	bbdoc: OpenGL version 4.0 or higher is present.
	end rem
	Const OpenGL_Version_4_0:Int = $00010000

	Rem
	bbdoc: OpenGL ES version 1.0 Common Lite or higher is present.
	end rem
	Const OpenGL_ES_CommonLite_Version_1_0:Int = $00000100

	Rem
	bbdoc: OpenGL ES version 1.0 Common or higher is present.
	about: The Common profile supports all the features of Common Lite.
	End Rem
	Const OpenGL_ES_Common_Version_1_0:Int = $00000080

	Rem
	bbdoc: OpenGL ES version 1.1 Common Lite or higher is present.
	end rem
	Const OpenGL_ES_CommonLite_Version_1_1:Int = $00000400

	Rem
	bbdoc: OpenGL ES version 1.1 Common or higher is present.
	about: The Common profile supports all the features of Common Lite.
	End Rem
	Const OpenGL_ES_Common_Version_1_1:Int = $00000200

	Rem
	bbdoc: OpenGL ES version 2.0 or higher is present.
	about: Note that OpenGL ES version 2.0 does not support all the features of OpenGL ES 1.x.
	So if OpenGL_ES_Version_2_0 is returned, none of the ES 1.x flags are returned.
	End Rem
	Const OpenGL_ES_Version_2_0:Int = $00000800
	
	
	Function _create:QGLFormat(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QGLFormat = New QGLFormat
			this.qObjectPtr = qObjectPtr
			Return this
		End If
		Return Null
	End Function
	
	Function CreateGLFormat:QGLFormat(formatOptions:Int, plane:Int = 0)
		Return New QGLFormat.Create(formatOptions, plane)
	End Function
	
	Method Create:QGLFormat(formatOptions:Int, plane:Int = 0)
		qObjectPtr = bmx_qt_qglformat_create(formatOptions, plane)
		Return Self
	End Method
	
	Function defaultFormat:QGLFormat()
		Return QGLFormat._create(bmx_qt_qglformat_defaultformat())
	End Function
	
	Function defaultOverlayFormat:QGLFormat()
		Return QGLFormat._create(bmx_qt_qglformat_defaultoverlayformat())
	End Function
	
	Function hasOpenGL:Int()
		Return bmx_qt_qglformat_hasopengl()
	End Function
	
	Function hasOpenGLOverlays:Int()
		Return bmx_qt_qglformat_hasopengloverlays()
	End Function
	
	Function openGLVersionFlags:Int()
		Return bmx_qt_qglformat_openglversionflags()
	End Function
	
	Function setDefaultFormat(f:QGLFormat)
		bmx_qt_qglformat_setdefaultformat(f.qObjectPtr)
	End Function
	
	Function setDefaultOverlayFormat(f:QGLFormat)
		bmx_qt_qglformat_setdefaultoverayformat(f.qObjectPtr)
	End Function
	
	Method accum:Int()
		Return bmx_qt_qglformat_accum(qObjectPtr)
	End Method

	Method accumBufferSize:Int()
		Return bmx_qt_qglformat_accumbuffersize(qObjectPtr)
	End Method

	Method alpha:Int()
		Return bmx_qt_qglformat_alpha(qObjectPtr)
	End Method

	Method alphaBufferSize:Int()
		Return bmx_qt_qglformat_alphabuffersize(qObjectPtr)
	End Method

	Method blueBufferSize:Int()
		Return bmx_qt_qglformat_bluebuffersize(qObjectPtr)
	End Method

	Method depth:Int()
		Return bmx_qt_qglformat_depth(qObjectPtr)
	End Method

	Method depthBufferSize:Int()
		Return bmx_qt_qglformat_depthbuffersize(qObjectPtr)
	End Method

	Method directRendering:Int()
		Return bmx_qt_qglformat_directrendering(qObjectPtr)
	End Method

	Method doubleBuffer:Int()
		Return bmx_qt_qglformat_doublebuffer(qObjectPtr)
	End Method

	Method greenBufferSize:Int()
		Return bmx_qt_qglformat_greenbuffersize(qObjectPtr)
	End Method

	Method hasOverlay:Int()
		Return bmx_qt_qglformat_hasoverlay(qObjectPtr)
	End Method

	Method majorVersion:Int()
		Return bmx_qt_qglformat_majorversion(qObjectPtr)
	End Method

	Method minorVersion:Int()
		Return bmx_qt_qglformat_minorversion(qObjectPtr)
	End Method

	Method plane:Int()
		Return bmx_qt_qglformat_plane(qObjectPtr)
	End Method

	Method profile:Int()
		Return bmx_qt_qglformat_profile(qObjectPtr)
	End Method

	Method redBufferSize:Int()
		Return bmx_qt_qglformat_redbuffersize(qObjectPtr)
	End Method

	Method rgba:Int()
		Return bmx_qt_qglformat_rgba(qObjectPtr)
	End Method

	Method sampleBuffers:Int()
		Return bmx_qt_qglformat_samplebuffers(qObjectPtr)
	End Method

	Method samples:Int()
		Return bmx_qt_qglformat_samples(qObjectPtr)
	End Method

	Method setAccum(enable:Int)
		bmx_qt_qglformat_setaccum(qObjectPtr, enable)
	End Method

	Method setAccumBufferSize(size:Int)
		bmx_qt_qglformat_setaccumbuffersize(qObjectPtr, size)
	End Method

	Method SetAlpha(enable:Int)
		bmx_qt_qglformat_setalpha(qObjectPtr, enable)
	End Method

	Method setAlphaBufferSize(size:Int)
		bmx_qt_qglformat_setalphabuffersize(qObjectPtr, size)
	End Method

	Method setBlueBufferSize(size:Int)
		bmx_qt_qglformat_setbluebuffersize(qObjectPtr, size)
	End Method

	Method setDepth(enable:Int)
		bmx_qt_qglformat_setdepth(qObjectPtr, enable)
	End Method

	Method setDepthBufferSize(size:Int)
		bmx_qt_qglformat_setdepthbuffersize(qObjectPtr, size)
	End Method

	Method setDirectRendering(enable:Int)
		bmx_qt_qglformat_setdirectrendering(qObjectPtr, enable)
	End Method

	Method setDoubleBuffer(enable:Int)
		bmx_qt_qglformat_setdoublebuffer(qObjectPtr, enable)
	End Method

	Method setGreenBufferSize(size:Int)
		bmx_qt_qglformat_setgreenbuffersize(qObjectPtr, size)
	End Method

	Method setOption(opt:Int)
		bmx_qt_qglformat_setoption(qObjectPtr, opt)
	End Method

	Method setOverlay(enable:Int)
		bmx_qt_qglformat_setoverlay(qObjectPtr, enable)
	End Method

	Method setPlane(plane:Int)
		bmx_qt_qglformat_setplane(qObjectPtr, plane)
	End Method

	Method setProfile(profile:Int)
		bmx_qt_qglformat_setprofile(qObjectPtr, profile)
	End Method

	Method setRedBufferSize(size:Int)
		bmx_qt_qglformat_setredbuffersize(qObjectPtr, size)
	End Method

	Method setRgba(enable:Int)
		bmx_qt_qglformat_setrgba(qObjectPtr, enable)
	End Method

	Method setSampleBuffers(enable:Int)
		bmx_qt_qglformat_setsamplebuffers(qObjectPtr, enable)
	End Method

	Method setSamples(numSamples:Int)
		bmx_qt_qglformat_setsamples(qObjectPtr, numSamples)
	End Method

	Method setStencil(enable:Int)
		bmx_qt_qglformat_setstencil(qObjectPtr, enable)
	End Method

	Method setStencilBufferSize(size:Int)
		bmx_qt_qglformat_setstencilbuffersize(qObjectPtr, size)
	End Method

	Method setStereo(enable:Int)
		bmx_qt_qglformat_setstereo(qObjectPtr, enable)
	End Method

	Method setSwapInterval(interval:Int)
		bmx_qt_qglformat_setswapinterval(qObjectPtr, interval)
	End Method

	Method setVersion(major:Int, minor:Int)
		bmx_qt_qglformat_setversion(qObjectPtr, major, minor)
	End Method

	Method stencil:Int()
		Return bmx_qt_qglformat_stencil(qObjectPtr)
	End Method

	Method stencilBufferSize:Int()
		Return bmx_qt_qglformat_stencilbuffersize(qObjectPtr)
	End Method

	Method stereo:Int()
		Return bmx_qt_qglformat_stereo(qObjectPtr)
	End Method

	Method swapInterval:Int()
		Return bmx_qt_qglformat_swapinterval(qObjectPtr)
	End Method

	Method testOption:Int(opt:Int)
		Return bmx_qt_qglformat_testoption(qObjectPtr, opt)
	End Method	
	
	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qglformat_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method

	Method Delete()
		Free()
	End Method
	
End Type


Rem
bbdoc: Specifies the use of double buffering.
end rem
Const QGL_DoubleBuffer:Int = $0001

Rem
bbdoc: Enables the use of a depth buffer.
end rem
Const QGL_DepthBuffer:Int = $0002

Rem
bbdoc: Specifies that the context should use RGBA as its pixel format.
end rem
Const QGL_Rgba:Int = $0004

Rem
bbdoc: Enables the use of an alpha channel.
end rem
Const QGL_AlphaChannel:Int = $0008

Rem
bbdoc: Enables the use of an accumulation buffer.
end rem
Const QGL_AccumBuffer:Int = $0010

Rem
bbdoc: Enables the use of a stencil buffer.
end rem
Const QGL_StencilBuffer:Int = $0020

Rem
bbdoc: Enables the use of a stereo buffers for use with visualization hardware.
end rem
Const QGL_StereoBuffers:Int = $0040

Rem
bbdoc: Specifies that the context is used for direct rendering to a display.
end rem
Const QGL_DirectRendering:Int = $0080

Rem
bbdoc: Enables the use of an overlay.
end rem
Const QGL_HasOverlay:Int = $0100

Rem
bbdoc: Enables the use of sample buffers.
end rem
Const QGL_SampleBuffers:Int = $0200

Rem
bbdoc: Enables the use of deprecated functionality for OpenGL 3.x contexts.
about: A context with deprecated functionality enabled is called a full context in the OpenGL specification.
End Rem
Const QGL_DeprecatedFunctions:Int = $0400

Rem
bbdoc: Specifies the use of a single buffer, as opposed to double buffers.
end rem
Const QGL_SingleBuffer:Int = QGL_DoubleBuffer Shl 16

Rem
bbdoc: Disables the use of a depth buffer.
end rem
Const QGL_NoDepthBuffer:Int = QGL_DepthBuffer Shl 16

Rem
bbdoc: Specifies that the context should use a color index as its pixel format.
end rem
Const QGL_ColorIndex:Int = QGL_Rgba Shl 16

Rem
bbdoc: Disables the use of an alpha channel.
end rem
Const QGL_NoAlphaChannel:Int = QGL_AlphaChannel Shl 16

Rem
bbdoc: Disables the use of an accumulation buffer.
end rem
Const QGL_NoAccumBuffer:Int = QGL_AccumBuffer Shl 16

Rem
bbdoc: Disables the use of a stencil buffer.
end rem
Const QGL_NoStencilBuffer:Int = QGL_StencilBuffer Shl 16

Rem
bbdoc: Disables the use of stereo buffers.
end rem
Const QGL_NoStereoBuffers:Int = QGL_StereoBuffers Shl 16

Rem
bbdoc: Specifies that the context is used for indirect rendering to a buffer.
end rem
Const QGL_IndirectRendering:Int = QGL_DirectRendering Shl 16

Rem
bbdoc: Disables the use of an overlay.
end rem
Const QGL_NoOverlay:Int = QGL_HasOverlay Shl 16

Rem
bbdoc: Disables the use of sample buffers.
end rem
Const QGL_NoSampleBuffers:Int = QGL_SampleBuffers Shl 16

Rem
bbdoc: Disables the use of deprecated functionality for OpenGL 3.x contexts.
about: A context with deprecated functionality disabled is called a forward compatible context in the OpenGL specification.
End Rem
Const QGL_NoDeprecatedFunctions:Int = QGL_DeprecatedFunctions Shl 16


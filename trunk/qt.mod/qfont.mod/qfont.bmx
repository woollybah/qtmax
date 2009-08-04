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

Module Qt.QFont

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QFont

	Field qObjectPtr:Byte Ptr
	
	Rem
	bbdoc: This is the normal text rendering option where no capitalization change is applied.
	end rem
	Const Case_MixedCase:Int = 0
	Rem
	bbdoc: This alters the text to be rendered in all uppercase type.
	end rem
	Const Case_AllUppercase:Int = 1
	Rem
	bbdoc: This alters the text to be rendered in all lowercase type.
	end rem
	Const Case_AllLowercase:Int = 2
	Rem
	bbdoc: This alters the text to be rendered in small-caps type.
	end rem
	Const Case_SmallCaps:Int = 3
	Rem
	bbdoc: This alters the text to be rendered with the first character of each word as an uppercase character.
	end rem
	Const Case_Capitalize:Int = 4
	Rem
	bbdoc: A value of 100 will keep the spacing unchanged; a value of 200 will enlarge the spacing after a character by the width of the character itself.
	end rem
	Const Case_PercentageSpacing:Int = 0
	Rem
	bbdoc: A positive value increases the letter spacing by the corresponding pixels; a negative value decreases the spacing.
	end rem
	Const Case_AbsoluteSpacing:Int = 1
	Rem
	bbdoc: 50
	end rem
	Const Stretch_UltraCondensed:Int = 50
	Rem
	bbdoc: 62
	end rem
	Const Stretch_ExtraCondensed:Int = 62
	Rem
	bbdoc: 75
	end rem
	Const Stretch_Condensed:Int = 75
	Rem
	bbdoc: 87
	end rem
	Const Stretch_SemiCondensed:Int = 87
	Rem
	bbdoc: 100
	end rem
	Const Stretch_Unstretched:Int = 100
	Rem
	bbdoc: 112
	end rem
	Const Stretch_SemiExpanded:Int = 112
	Rem
	bbdoc: 125
	end rem
	Const Stretch_Expanded:Int = 125
	Rem
	bbdoc: 150
	end rem
	Const Stretch_ExtraExpanded:Int = 150
	Rem
	bbdoc: 200
	end rem
	Const Stretch_UltraExpanded:Int = 200
	Rem
	bbdoc: Normal glyphs used in unstyled text.
	end rem
	Const StyleNormal:Int = 0
	Rem
	bbdoc: Italic glyphs that are specifically designed for the purpose of representing italicized text.
	end rem
	Const StyleItalic:Int = 1
	Rem
	bbdoc: Glyphs with an italic appearance that are typically based on the unstyled glyphs, but are not fine-tuned for the purpose of representing italicized text.
	end rem
	Const StyleOblique:Int = 2
	Rem
	bbdoc: the default style strategy. It does not prefer any type of font.
	end rem
	Const Strategy_PreferDefault:Int = $0001
	Rem
	bbdoc: prefers bitmap fonts (as opposed to outline fonts).
	end rem
	Const Strategy_PreferBitmap:Int = $0002
	Rem
	bbdoc: prefers device fonts.
	end rem
	Const Strategy_PreferDevice:Int = $0004
	Rem
	bbdoc: prefers outline fonts (as opposed to bitmap fonts).
	end rem
	Const Strategy_PreferOutline:Int = $0008
	Rem
	bbdoc: forces the use of outline fonts.
	end rem
	Const Strategy_ForceOutline:Int = $0010
	Rem
	bbdoc: don't antialias the fonts.
	end rem
	Const Strategy_NoAntialias:Int = $0100
	Rem
	bbdoc: antialias if possible.
	end rem
	Const Strategy_PreferAntialias:Int = $0080
	Rem
	bbdoc: forces the use of OpenGL compatible fonts.
	end rem
	Const Strategy_OpenGLCompatible:Int = $0200
	Rem
	bbdoc: If a font does not contain a character requested to draw then Qt automatically chooses a similar looking for that contains the character. This flag disables this feature.
	end rem
	Const Strategy_NoFontMerging:Int = $8000
	Rem
	bbdoc: prefer an exact match.
	about: The font matcher will try to use the exact font size that has been specified.
	End Rem
	Const Strategy_PreferMatch:Int = $0020
	Rem
	bbdoc: prefer the best quality font.
	about: The font matcher will use the nearest standard point size that the font supports.
	End Rem
	Const Strategy_PreferQuality:Int = $0040
	Rem
	bbdoc: 25
	end rem
	Const Weight_Light:Int = 25
	Rem
	bbdoc: 50
	end rem
	Const Weight_Normal:Int = 50
	Rem
	bbdoc: 63
	end rem
	Const Weight_DemiBold:Int = 63
	Rem
	bbdoc: 75
	end rem
	Const Weight_Bold:Int = 75
	Rem
	bbdoc: 87
	end rem
	Const Weight_Black:Int = 87
	Rem
	bbdoc: Is a synonym for Hint_SansSerif.
	end rem
	Const Hint_Helvetica:Int = 0
	Rem
	bbdoc: The font matcher prefer sans serif fonts.
	end rem
	Const Hint_SansSerif:Int = Hint_Helvetica
	Rem
	bbdoc: Is a synonym for Hint_Serif.
	end rem
	Const Hint_Times:Int = 1
	Rem
	bbdoc: The font matcher prefers serif fonts.
	end rem
	Const Hint_Serif:Int = Hint_Times
	Rem
	bbdoc: A synonym for Hint_TypeWriter.
	end rem
	Const Hint_Courier:Int = 2
	Rem
	bbdoc: The font matcher prefers fixed pitch fonts.
	end rem
	Const Hint_TypeWriter:Int = Hint_Courier
	Rem
	bbdoc: Is a synonym for Hint_Decorator.
	end rem
	Const Hint_OldEnglish:Int = 3
	Rem
	bbdoc: The font matcher prefers decorative fonts.
	end rem
	Const Hint_Decorative:Int = Hint_OldEnglish
	Rem
	bbdoc: The font matcher prefers system fonts.
	end rem
	Const Hint_System:Int = 4
	Rem
	bbdoc: Leaves the font matching algorithm to choose the family.
	about: This is the default.
	end rem
	Const Hint_AnyStyle:Int = 5
	
	Function _create:QFont(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QFont = New QFont
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function CreateFont:QFont(family:String = "", pointSize:Int = -1, weight:Int = -1, italic:Int = False)
		Return New QFont.Create(family, pointSize, weight, italic)
	End Function

	Method Create:QFont(family:String = "", pointSize:Int = -1, weight:Int = -1, italic:Int = False)
		qObjectPtr = bmx_qt_qfont_create(family, pointSize, weight, italic)
		Return Self
	End Method

	Method bold:Int()
		Return bmx_qt_qfont_bold(qObjectPtr)
	End Method
	
	Method capitalization:Int()
		Return bmx_qt_qfont_capitalization(qObjectPtr)
	End Method
	
	Method defaultFamily:String()
		Return bmx_qt_qfont_defaultfamily(qObjectPtr)
	End Method
	
	Method exactMatch:Int()
		Return bmx_qt_qfont_exactmatch(qObjectPtr)
	End Method
	
	Method family:String()
		Return bmx_qt_qfont_family(qObjectPtr)
	End Method
	
	Method fixedPitch:Int()
		Return bmx_qt_qfont_fixedpitch(qObjectPtr)
	End Method
	
	Method fromString:Int(description:String)
		Return bmx_qt_qfont_fromstring(qObjectPtr, description)
	End Method
	
	Method isCopyOf:Int(f:QFont)
		Return bmx_qt_qfont_iscopyof(qObjectPtr, f.qObjectPtr)
	End Method
	
	Method italic:Int()
		Return bmx_qt_qfont_italic(qObjectPtr)
	End Method
	
	Method kerning:Int()
		Return bmx_qt_qfont_kerning(qObjectPtr)
	End Method
	
	Method key:String()
		Return bmx_qt_qfont_key(qObjectPtr)
	End Method
	
	Method lastResortFamily:String()
		Return bmx_qt_qfont_lastresortfamily(qObjectPtr)
	End Method
	
	Method lastResortFont:String()
		Return bmx_qt_qfont_lastresortfont(qObjectPtr)
	End Method
	
	Method letterSpacing:Double()
		Return bmx_qt_qfont_letterspacing(qObjectPtr)
	End Method
	
	Method letterSpacingType:Int()
		Return bmx_qt_qfont_letterspacingtype(qObjectPtr)
	End Method
	
	Method overline:Int()
		Return bmx_qt_qfont_overline(qObjectPtr)
	End Method
	
	Method pixelSize:Int()
		Return bmx_qt_qfont_pixelsize(qObjectPtr)
	End Method
	
	Method pointSize:Int()
		Return bmx_qt_qfont_pointsize(qObjectPtr)
	End Method
	
	Method pointSizeF:Double()
		Return bmx_qt_qfont_pointsizef(qObjectPtr)
	End Method
	
	Method rawMode:Int()
		Return bmx_qt_qfont_rawmode(qObjectPtr)
	End Method
	
	Method rawName:String()
		Return bmx_qt_qfont_rawname(qObjectPtr)
	End Method
	
	Method resolve:QFont(other:QFont)
		Return QFont._create(bmx_qt_qfont_resolve(qObjectPtr, other.qObjectPtr))
	End Method
	
	Method setBold(enable:Int)
		bmx_qt_qfont_setbold(qObjectPtr, enable)
	End Method
	
	Method setCapitalization(caps:Int)
		bmx_qt_qfont_setcapitalization(qObjectPtr, caps)
	End Method
	
	Method setFamily(family:String)
		bmx_qt_qfont_setfamily(qObjectPtr, family)
	End Method
	
	Method setFixedPitch(enable:Int)
		bmx_qt_qfont_setfixedpitch(qObjectPtr, enable)
	End Method
	
	Method setItalic(enable:Int)
		bmx_qt_qfont_setitalic(qObjectPtr, enable)
	End Method
	
	Method setKerning(enable:Int)
		bmx_qt_qfont_setkerning(qObjectPtr, enable)
	End Method
	
	Method setLetterSpacing(_type:Int, spacing:Double)
		bmx_qt_qfont_setletterspacing(qObjectPtr, _type, spacing)
	End Method
	
	Method setOverline(enable:Int)
		bmx_qt_qfont_setoverline(qObjectPtr, enable)
	End Method
	
	Method setPixelSize(pixelSize:Int)
		bmx_qt_qfont_setpixelsize(qObjectPtr, pixelSize)
	End Method
	
	Method setPointSize(pointSize:Int)
		bmx_qt_qfont_setpointsize(qObjectPtr, pointSize)
	End Method
	
	Method setPointSizeF(pointSize:Double)
		bmx_qt_qfont_setpointsizef(qObjectPtr, pointSize)
	End Method
	
	Method setRawMode(enable:Int)
		bmx_qt_qfont_setrawmode(qObjectPtr, enable)
	End Method
	
	Method setRawName(name:String)
		bmx_qt_qfont_setrawname(qObjectPtr, name)
	End Method
	
	Method setStretch(factor:Int)
		bmx_qt_qfont_setstretch(qObjectPtr, factor)
	End Method
	
	Method setStrikeOut(enable:Int)
		bmx_qt_qfont_setstrikeout(qObjectPtr, enable)
	End Method
	
	Method setStyle(style:Int)
		bmx_qt_qfont_setstyle(qObjectPtr, style)
	End Method
	
	Method setStyleHint(hint:Int, strategy:Int = Strategy_PreferDefault)
		bmx_qt_qfont_setstylehint(qObjectPtr, hint, strategy)
	End Method
	
	Method setStyleStrategy(s:Int)
		bmx_qt_qfont_setstylestrategy(qObjectPtr, s)
	End Method
	
	Method setUnderline(enable:Int)
		bmx_qt_qfont_setunderline(qObjectPtr, enable)
	End Method
	
	Method setWeight(weight:Int)
		bmx_qt_qfont_setweight(qObjectPtr, weight)
	End Method
	
	Method setWordSpacing(spacing:Double)
		bmx_qt_qfont_setwordspacing(qObjectPtr, spacing)
	End Method
	
	Method stretch:Int()
		Return bmx_qt_qfont_stretch(qObjectPtr)
	End Method
	
	Method strikeOut:Int()
		Return bmx_qt_qfont_strikeout(qObjectPtr)
	End Method
	
	Method style:Int()
		Return bmx_qt_qfont_style(qObjectPtr)
	End Method
	
	Method styleHint:Int()
		Return bmx_qt_qfont_stylehint(qObjectPtr)
	End Method
	
	Method styleStrategy:Int()
		Return bmx_qt_qfont_stylestrategy(qObjectPtr)
	End Method
	
	Method toString:String()
		Return bmx_qt_qfont_tostring(qObjectPtr)
	End Method
	
	Method underline:Int()
		Return bmx_qt_qfont_underline(qObjectPtr)
	End Method
	
	Method weight:Int()
		Return bmx_qt_qfont_weight(qObjectPtr)
	End Method
	
	Method wordSpacing:Double()
		Return bmx_qt_qfont_wordspacing(qObjectPtr)
	End Method

	Method Free()
		If qObjectPtr Then
			bmx_qt_qfont_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method
End Type


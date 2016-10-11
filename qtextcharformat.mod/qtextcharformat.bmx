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

Module Qt.QTextCharFormat

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QTextCharFormat Extends QTextFormat

	Rem
	bbdoc: Text is draw without any underlining decoration.
	end rem
	Const NoUnderline:Int = 0
	Rem
	bbdoc: A line is drawn using Qt::SolidLine.
	end rem
	Const SingleUnderline:Int = 1
	Rem
	bbdoc: Dashes are drawn using Qt::DashLine.
	end rem
	Const DashUnderline:Int = 2
	Rem
	bbdoc: Dots are drawn using Qt::DotLine;
	end rem
	Const DotLine:Int = 3
	Rem
	bbdoc: Dashs and dots are drawn using Qt::DashDotLine.
	end rem
	Const DashDotLine:Int = 4
	Rem
	bbdoc: Underlines draw drawn using Qt::DashDotDotLine.
	end rem
	Const DashDotDotLine:Int = 5
	Rem
	bbdoc: The text is underlined using a wave shaped line.
	end rem
	Const WaveUnderline:Int = 6
	Rem
	bbdoc: The underline is drawn depending on the QStyle::SH_SpellCeckUnderlineStyle style hint of the QApplication style. By default this is mapped to WaveUnderline, on Mac OS X it is mapped to DashDotLine.
	end rem
	Const SpellCheckUnderline:Int = 7
	Rem
	bbdoc: Adjacent characters are positioned in the standard way for text in the writing system in use.
	end rem
	Const AlignNormal:Int = 0
	Rem
	bbdoc: Characters are placed above the baseline for normal text.
	end rem
	Const AlignSuperScript:Int = 1
	Rem
	bbdoc: Characters are placed below the baseline for normal text.
	end rem
	Const AlignSubScript:Int = 2
	Rem
	bbdoc: The center of the object is vertically aligned with the base line. Currently, this is only implemented for inline objects.
	end rem
	Const AlignMiddle:Int = 3
	Rem
	bbdoc: The bottom edge of the object is vertically aligned with the base line.
	end rem
	Const AlignBottom:Int = 5
	Rem
	bbdoc: The top edge of the object is vertically aligned with the base line.
	end rem
	Const AlignTop:Int = 4

	
	Function _create:QTextCharFormat(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTextCharFormat = New QTextCharFormat
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function CreateTextCharFormat:QTextCharFormat()
		Return New QTextCharFormat.Create()
	End Function
	
	Method Create:QTextCharFormat()
		qObjectPtr = bmx_qt_qtextcharformat_create()
		Return Self
	End Method


	Method background:QBrush()
		Return QBrush._create(bmx_qt_qtextcharformat_background(qObjectPtr))
	End Method

	Method boolProperty:Int(propertyId:Int)
		Return bmx_qt_qtextcharformat_boolproperty(qObjectPtr, propertyId)
	End Method

	Method brushProperty:QBrush(propertyId:Int)
		Return QBrush._create(bmx_qt_qtextcharformat_brushproperty(qObjectPtr, propertyId))
	End Method

	Method clearBackground()
		bmx_qt_qtextcharformat_clearbackground(qObjectPtr)
	End Method

	Method clearForeground()
		bmx_qt_qtextcharformat_clearforeground(qObjectPtr)
	End Method

	Method clearProperty(propertyId:Int)
		bmx_qt_qtextcharformat_clearproperty(qObjectPtr, propertyId)
	End Method

	Method colorProperty:QColor(propertyId:Int)
		Return QColor._create(bmx_qt_qtextcharformat_colorProperty(qObjectPtr, propertyId))
	End Method

	Method doubleProperty:Double(propertyId:Int)
		Return bmx_qt_qtextcharformat_doubleproperty(qObjectPtr, propertyId)
	End Method

	Method foreground:QBrush()
		Return QBrush._create(bmx_qt_qtextcharformat_foreground(qObjectPtr))
	End Method

	Method hasProperty:Int(propertyId:Int)
		Return bmx_qt_qtextcharformat_hasproperty(qObjectPtr, propertyId)
	End Method

	Method intProperty:Int(propertyId:Int)
		Return bmx_qt_qtextcharformat_intproperty(qObjectPtr, propertyId)
	End Method

	Method isBlockFormat:Int()
		Return bmx_qt_qtextcharformat_isblockformat(qObjectPtr)
	End Method

	Method isCharFormat:Int()
		Return bmx_qt_qtextcharformat_ischarformat(qObjectPtr)
	End Method

	Method isFrameFormat:Int()
		Return bmx_qt_qtextcharformat_isframeformat(qObjectPtr)
	End Method

	Method isImageFormat:Int()
		Return bmx_qt_qtextcharformat_isimageformat(qObjectPtr)
	End Method

	Method isListFormat:Int()
		Return bmx_qt_qtextcharformat_islistformat(qObjectPtr)
	End Method

	Method isTableCellFormat:Int()
		Return bmx_qt_qtextcharformat_istablecellformat(qObjectPtr)
	End Method

	Method isTableFormat:Int()
		Return bmx_qt_qtextcharformat_istableformat(qObjectPtr)
	End Method

	Method layoutDirection:Int()
		Return bmx_qt_qtextcharformat_layoutdirection(qObjectPtr)
	End Method

	'Method lengthProperty:QTextLength(propertyId:Int)
	' TODO
	'End Method

	'Method QVector<QTextLength> lengthVectorProperty(propertyId:Int)
	' TODO
	'End Method

	Method merge(other:QTextFormat)
		bmx_qt_qtextcharformat_merge(qObjectPtr, other.qObjectPtr)
	End Method

	Method objectIndex:Int()
		Return bmx_qt_qtextcharformat_objectindex(qObjectPtr)
	End Method

	Method objectType:Int()
		Return bmx_qt_qtextcharformat_objecttype(qObjectPtr)
	End Method

	Method penProperty:QPen(propertyId:Int)
		Return QPen._create(bmx_qt_qtextcharformat_penproperty(qObjectPtr, propertyId))
	End Method

	'Method QMap<Int, QVariant> properties()
	' TODO
	'End Method

	'Method QVariant property(propertyId:Int)
	' TODO
	'End Method

	Method propertyCount:Int()
		Return bmx_qt_qtextcharformat_propertycount(qObjectPtr)
	End Method

	Method setBackground(brush:QBrush)
		bmx_qt_qtextcharformat_setbackground(qObjectPtr, brush.qObjectPtr)
	End Method

	Method setForeground(brush:QBrush)
		bmx_qt_qtextformat_setforeground(qObjectPtr, brush.qObjectPtr)
	End Method

	Method setLayoutDirection(direction:Int)
		bmx_qt_qtextcharformat_setlayoutdirection(qObjectPtr, direction)
	End Method

	Method setObjectIndex(index:Int)
		bmx_qt_qtextcharformat_setobjectindex(qObjectPtr, index)
	End Method

	Method setObjectType(_type:Int)
		bmx_qt_qtextcharformat_setobjecttype(qObjectPtr, _type)
	End Method

	'Method setProperty(propertyId:Int, value:QVariant)
	' TODO
	'End Method

	'Method setProperty(propertyId:Int, QVector<QTextLength> & value)
	' TODO
	'End Method

	Method stringProperty:String(propertyId:Int)
		Return bmx_qt_qtextcharformat_stringproperty(qObjectPtr, propertyId)
	End Method


	Method anchorHref:String()
		Return bmx_qt_qtextcharformat_anchorhref(qObjectPtr)
	End Method
	
	Method anchorNames:String[]()
		Return bmx_qt_qtextcharformat_anchornames(qObjectPtr)
	End Method
	
	Method font:QFont()
		Return QFont._create(bmx_qt_qtextcharformat_font(qObjectPtr))
	End Method
	
	Method fontCapitalization:Int()
		Return bmx_qt_qtextcharformat_fontcapitalization(qObjectPtr)
	End Method
	
	Method fontFamily:String()
		Return bmx_qt_qtextcharformat_fontfamily(qObjectPtr)
	End Method
	
	Method fontFixedPitch:Int()
		Return bmx_qt_qtextcharformat_fontfixedpitch(qObjectPtr)
	End Method
	
	Method fontItalic:Int()
		Return bmx_qt_qtextcharformat_fontitalic(qObjectPtr)
	End Method
	
	Method fontKerning:Int()
		Return bmx_qt_qtextcharformat_fontkerning(qObjectPtr)
	End Method
	
	Method fontLetterSpacing:Double()
		Return bmx_qt_qtextcharformat_fontletterspacing(qObjectPtr)
	End Method
	
	Method fontOverline:Int()
		Return bmx_qt_qtextcharformat_fontoverline(qObjectPtr)
	End Method
	
	Method fontPointSize:Double()
		Return bmx_qt_qtextcharformat_fontpointsize(qObjectPtr)
	End Method
	
	Method fontStrikeOut:Int()
		Return bmx_qt_qtextcharformat_fontstrikeout(qObjectPtr)
	End Method
	
	Method fontStyleHint:Int()
		Return bmx_qt_qtextcharformat_fontstylehint(qObjectPtr)
	End Method
	
	Method fontStyleStrategy:Int()
		Return bmx_qt_qtextcharformat_fontstylestrategy(qObjectPtr)
	End Method
	
	Method fontUnderline:Int()
		Return bmx_qt_qtextcharformat_fontunderline(qObjectPtr)
	End Method
	
	Method fontWeight:Int()
		Return bmx_qt_qtextcharformat_fontweight(qObjectPtr)
	End Method
	
	Method fontWordSpacing:Double()
		Return bmx_qt_qtextcharformat_fontwordspacing(qObjectPtr)
	End Method
	
	Method isAnchor:Int()
		Return bmx_qt_qtextcharformat_isanchor(qObjectPtr)
	End Method
	
	Method isValid:Int()
		Return bmx_qt_qtextcharformat_isvalid(qObjectPtr)
	End Method
	
	Method setAnchor(anchor:Int)
		bmx_qt_qtextcharformat_setanchor(qObjectPtr, anchor)
	End Method
	
	Method setAnchorHref(value:String)
		bmx_qt_qtextcharformat_setanchorhref(qObjectPtr, value)
	End Method
	
	Method setAnchorNames(names:String[])
		bmx_qt_qtextcharformat_setanchornames(qObjectPtr, names)
	End Method
	
	Method setFont(font:QFont)
		bmx_qt_qtextcharformat_setfont(qObjectPtr, font.qObjectPtr)
	End Method
	
	Method setFontCapitalization(capitalization:Int)
		bmx_qt_qtextcharformat_setfontcapitalization(qObjectPtr, capitalization)
	End Method
	
	Method setFontFamily(family:String)
		bmx_qt_qtextcharformat_setfontfamily(qObjectPtr, family)
	End Method
	
	Method setFontFixedPitch(fixedPitch:Int)
		bmx_qt_qtextcharformat_setfontfixedpitch(qObjectPtr, fixedpitch)
	End Method
	
	Method setFontItalic(italic:Int)
		bmx_qt_qtextcharformat_setfontitalic(qObjectPtr, italic)
	End Method
	
	Method setFontKerning(enable:Int)
		bmx_qt_qtextcharformat_setfontkerning(qObjectPtr, enable)
	End Method
	
	Method setFontLetterSpacing(spacing:Double)
		bmx_qt_qtextcharformat_setfontletterspacing(qObjectPtr, spacing)
	End Method
	
	Method setFontOverline(overline:Int)
		bmx_qt_qtextcharformat_setfontoverline(qObjectPtr, overline)
	End Method
	
	Method setFontPointSize(size:Double)
		bmx_qt_qtextcharformat_setfontpointsize(qObjectPtr, size)
	End Method
	
	Method setFontStrikeOut(strikeOut:Int)
		bmx_qt_qtextcharformat_setfontstrikeout(qObjectPtr, strikeOut)
	End Method
	
	Method setFontStyleHint(hint:Int, strategy:Int = QFont.Strategy_PreferDefault)
		bmx_qt_qtextcharformat_setfontstylehint(qObjectPtr, hint, strategy)
	End Method
	
	Method setFontStyleStrategy(strategy:Int)
		bmx_qt_qtextcharformat_setfontstylestrategy(qObjectPtr, strategy)
	End Method
	
	Method setFontUnderline(underline:Int)
		bmx_qt_qtextcharformat_setfontunderline(qObjectPtr, underline)
	End Method
	
	Method setFontWeight(weight:Int)
		bmx_qt_qtextcharformat_setfontweight(qObjectPtr, weight)
	End Method
	
	Method setFontWordSpacing(spacing:Double)
		bmx_qt_qtextcharformat_setfontwordspacing(qObjectPtr, spacing)
	End Method
	
	Method setTextOutline(pen:QPen)
		bmx_qt_qtextcharformat_settextoutline(qObjectPtr, pen.qObjectPtr)
	End Method
	
	Method setToolTip(text:String)
		bmx_qt_qtextcharformat_settooltip(qObjectPtr, text)
	End Method
	
	Method setUnderlineColor(color:QColor)
		bmx_qt_qtextcharformat_setunderlinecolor(qObjectPtr, color.qObjectPtr)
	End Method
	
	Method setUnderlineStyle(style:Int)
		bmx_qt_qtextcharformat_setunderlinestyle(qObjectPtr, style)
	End Method
	
	Method setVerticalAlignment(alignment:Int)
		bmx_qt_qtextcharformat_setverticalalignment(qObjectPtr, alignment)
	End Method
	
	Method textOutline:QPen()
		Return QPen._create(bmx_qt_qtextcharformat_textoutline(qObjectPtr))
	End Method
	
	Method toolTip:String()
		Return bmx_qt_qtextcharformat_tooltip(qObjectPtr)
	End Method
	
	Method underlineColor:QColor()
		Return QColor._create(bmx_qt_qtextcharformat_underlinecolor(qObjectPtr))
	End Method
	
	Method underlineStyle:Int()
		Return bmx_qt_qtextcharformat_underlinestyle(qObjectPtr)
	End Method
	
	Method verticalAlignment:Int()
		Return bmx_qt_qtextcharformat_verticalalignment(qObjectPtr)
	End Method

	Method Free()
		If qObjectPtr Then
			bmx_qt_qtextcharformat_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method
	
End Type


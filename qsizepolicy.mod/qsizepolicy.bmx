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

Module Qt.QSizePolicy

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QSizePolicy

	Field qObjectPtr:Byte Ptr

	Rem
	bbdoc: The default type, when none is specified.
	end rem
	Const CT_DefaultType:Int = $00000001
	Rem
	bbdoc: A QDialogButtonBox instance.
	end rem
	Const CT_ButtonBox:Int = $00000002
	Rem
	bbdoc: A QCheckBox instance.
	end rem
	Const CT_CheckBox:Int = $00000004
	Rem
	bbdoc: A QComboBox instance.
	end rem
	Const CT_ComboBox:Int = $00000008
	Rem
	bbdoc: A QFrame instance.
	end rem
	Const CT_Frame:Int = $00000010
	Rem
	bbdoc: A QGroupBox instance.
	end rem
	Const CT_GroupBox:Int = $00000020
	Rem
	bbdoc: A QLabel instance.
	end rem
	Const CT_Label:Int = $00000040
	Rem
	bbdoc: A QFrame instance with QFrame::HLine or QFrame::VLine.
	end rem
	Const CT_Line:Int = $00000080
	Rem
	bbdoc: A QLineEdit instance.
	end rem
	Const CT_LineEdit:Int = $00000100
	Rem
	bbdoc: A QPushButton instance.
	end rem
	Const CT_PushButton:Int = $00000200
	Rem
	bbdoc: A QRadioButton instance.
	end rem
	Const CT_RadioButton:Int = $00000400
	Rem
	bbdoc: A QAbstractSlider instance.
	end rem
	Const CT_Slider:Int = $00000800
	Rem
	bbdoc: A QAbstractSpinBox instance.
	end rem
	Const CT_SpinBox:Int = $00001000
	Rem
	bbdoc: A QTabWidget instance.
	end rem
	Const CT_TabWidget:Int = $00002000
	Rem
	bbdoc: A QToolButton instance.
	end rem
	Const CT_ToolButton:Int = $00004000
	
	Rem
	bbdoc: The widget can grow beyond its size hint if necessary.
	end rem
	Const GrowFlag:Int = 1
	Rem
	bbdoc: The widget should get as much space as possible.
	end rem
	Const ExpandFlag:Int = 2
	Rem
	bbdoc: The widget can shrink below its size hint if necessary.
	end rem
	Const ShrinkFlag:Int = 4
	Rem
	bbdoc: The widget's size hint is ignored.
	about: The widget will get as much space as possible.
	End Rem
	Const IgnoreFlag:Int = 8

	Rem
	bbdoc: The QWidget::sizeHint() is the only acceptable alternative, so the widget can never grow or shrink (e.g. the vertical direction of a push button).
	end rem
	Const Fixed:Int = 0
	Rem
	bbdoc: The sizeHint() is minimal, and sufficient.
	about: The widget can be expanded, but there is no advantage to it being larger (e.g. the horizontal direction
	of a push button). It cannot be smaller than the size provided by sizeHint().
	End Rem
	Const Minimum:Int = GrowFlag
	Rem
	bbdoc: The sizeHint() is a maximum.
	about: The widget can be shrunk any amount without detriment if other widgets need the space (e.g. a separator
	line). It cannot be larger than the size provided by sizeHint().
	End Rem
	Const Maximum:Int = ShrinkFlag
	Rem
	bbdoc: The sizeHint() is best, but the widget can be shrunk and still be useful.
	about: The widget can be expanded, but there is no advantage to it being larger than sizeHint() (the
	default QWidget policy).
	End Rem
	Const Preferred:Int = GrowFlag | ShrinkFlag
	Rem
	bbdoc: The sizeHint() is a sensible size, but the widget can be shrunk and still be useful.
	about: The widget can make use of extra space, so it should get as much space as possible (e.g. the horizontal
	direction of a horizontal slider).
	End Rem
	Const Expanding:Int = GrowFlag | ShrinkFlag | ExpandFlag
	Rem
	bbdoc: The sizeHint() is minimal, and sufficient.
	about: The widget can make use of extra space, so it should get as much space as possible (e.g. the horizontal
	direction of a horizontal slider).
	End Rem
	Const MinimumExpanding:Int = GrowFlag | ExpandFlag
	Rem
	bbdoc: The sizeHint() is ignored.
	about: The widget will get as much space as possible.
	End Rem
	Const Ignored:Int = ShrinkFlag | GrowFlag | IgnoreFlag
			
	Function _create:QSizePolicy(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QSizePolicy = New QSizePolicy
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method controlType:Int()
		Return bmx_qt_qsizepolicy_controltype(qObjectPtr)
	End Method
	
	Method expandingDirections:Int()
		Return bmx_qt_qsizepolicy_expandingdirections(qObjectPtr)
	End Method
	
	Method hasHeightForWidth:Int()
		Return bmx_qt_qsizepolicy_hasheightforwidth(qObjectPtr)
	End Method
	
	Method horizontalPolicy:Int()
		Return bmx_qt_qsizepolicy_horizontalpolicy(qObjectPtr)
	End Method
	
	Method horizontalStretch:Int()
		Return bmx_qt_qsizepolicy_horizontalstretch(qObjectPtr)
	End Method
	
	Method setControlType(controlType:Int)
		bmx_qt_qsizepolicy_setcontroltype(qObjectPtr, controlType)
	End Method
	
	Method setHeightForWidth(dependent:Int)
		bmx_qt_qsizepolicy_setheightforwidth(qObjectPtr, dependent)
	End Method
	
	Method setHorizontalPolicy(policy:Int)
		bmx_qt_qsizepolicy_sethorizontalpolicy(qObjectPtr, policy)
	End Method
	
	Method setHorizontalStretch(stretchFactor:Int)
		bmx_qt_qsizepolicy_sethorizontalstretch(qObjectPtr, stretchFactor)
	End Method
	
	Method setVerticalPolicy(policy:Int)
		bmx_qt_qsizepolicy_setverticalpolicy(qObjectPtr, policy)
	End Method
	
	Method setVerticalStretch(stretchFactor:Int)
		bmx_qt_qsizepolicy_setverticalstretch(qObjectPtr, stretchFactor)
	End Method
	
	Method transpose()
		bmx_qt_qsizepolicy_transpose(qObjectPtr)
	End Method
	
	Method verticalPolicy:Int()
		Return bmx_qt_qsizepolicy_verticalpolicy(qObjectPtr)
	End Method
	
	Method verticalStretch:Int()
		Return bmx_qt_qsizepolicy_verticalstretch(qObjectPtr)
	End Method

	Method Free()
		If qObjectPtr Then
			bmx_qt_qsizepolicy_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method
	
End Type


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

Module Qt.QAbstractSpinBox

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QAbstractSpinBox Extends QWidget

	Method alignment:Int()
		Return bmx_qt_qabstractspinbox_alignment(qObjectPtr)
	End Method
	
	Method buttonSymbols:Int()
		Return bmx_qt_qabstractspinbox_buttonsybmols(qObjectPtr)
	End Method
	
	Method correctionMode:Int()
		Return bmx_qt_qabstractspinbox_correctionmode(qObjectPtr)
	End Method
	
	Method fixup(inp:String Var)
		Local s:String = bmx_qt_qabstractspinbox_fixup(qObjectPtr, inp)
		inp = s
	End Method
	
	Method hasAcceptableInput:Int()
		Return bmx_qt_qabstractspinbox_hasacceptableinput(qObjectPtr)
	End Method
	
	Method hasFrame:Int()
		Return bmx_qt_qabstractspinbox_hasframe(qObjectPtr)
	End Method
	
	Method interpretText()
		bmx_qt_qabstractspinbox_interprettext(qObjectPtr)
	End Method
	
	Method isAccelerated:Int()
		Return bmx_qt_qabstractspinbox_isaccelerated(qObjectPtr)
	End Method
	
	Method isReadOnly:Int()
		Return bmx_qt_qabstractspinbox_isreadonly(qObjectPtr)
	End Method
	
	Method keyboardTracking:Int()
		Return bmx_qt_qabstractspinbox_keyboardtracking(qObjectPtr)
	End Method
	
	Method setAccelerated(on:Int)
		bmx_qt_qabstractspinbox_setaccelerated(qObjectPtr, on)
	End Method
	
	Method setAlignment(flag:Int)
		bmx_qt_qabstractspinbox_setalignment(qObjectPtr, flag)
	End Method
	
	Method setButtonSymbols(bs:Int)
		bmx_qt_qabstractspinbox_setbuttonsymbols(qObjectPtr, bs)
	End Method
	
	Method setCorrectionMode(cm:Int)
		bmx_qt_qabstractspinbox_setcorrectionmode(qObjectPtr, cm)
	End Method
	
	Method setFrame(frame:Int)
		bmx_qt_qabstractspinbox_setframe(qObjectPtr, frame)
	End Method
	
	Method setKeyboardTracking(kt:Int)
		bmx_qt_qabstractspinbox_setkeyboardtracking(qObjectPtr, kt)
	End Method
	
	Method setReadOnly(r:Int)
		bmx_qt_qabstractspinbox_setreadonly(qObjectPtr, r)
	End Method
	
	Method setSpecialValueText(txt:String)
		bmx_qt_qabstractspinbox_setspecialvaluetext(qObjectPtr, txt)
	End Method
	
	Method setWrapping(w:Int)
		bmx_qt_qabstractspinbox_setwrapping(qObjectPtr, w)
	End Method
	
	Method specialValueText:String()
		Return bmx_qt_qabstractspinbox_specialvaluetext(qObjectPtr)
	End Method
	
	Method stepBy(steps:Int)
		bmx_qt_qabstractspinbox_stepby(qObjectPtr, steps)
	End Method
	
	Method text:String()
		Return bmx_qt_qabstractspinbox_text(qObjectPtr)
	End Method
	
	Method validate:Int(inp:String, pos:Int Var)
		Return bmx_qt_qabstractspinbox_validate(qObjectPtr, inp, Varptr pos)
	End Method
	
	Method wrapping:Int()
		Return bmx_qt_qabstractspinbox_wrapping(qObjectPtr)
	End Method

	' SIGNAL : editingFinished
	Function _OnEditingFinished(obj:QAbstractSpinBox)
		obj._InvokeSignals("editingFinished", Null)
	End Function

End Type


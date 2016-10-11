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

Module Qt.QAbstractSpinBox

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Rem
bbdoc: Provides a spinbox and a line edit to display values.
about: The type is designed as a common super type for widgets like <a href="qspinbox.html">QSpinBox</a>,
<a href="qdoublespinbox.html">QDoubleSpinBox</a> and <a href="qdatetimeedit.html">QDateTimeEdit</a>
</p>
<p>
Here are the main properties:
</p>
<ol type="1">
<li>text: The text that is displayed in the QAbstractSpinBox.</li>
<li>alignment: The alignment of the text in the QAbstractSpinBox.</li>
<li>wrapping: Whether the QAbstractSpinBox wraps from the minimum value to the maximum value and vica versa.</li>
</ol>
<p>
QAbstractSpinBox provides a virtual <a href="qabstractspinbox.html#stepBy">stepBy</a>() method that is called whenever the user
triggers a step. This function takes an integer value to signify how many steps were taken. E.g&#x2e; Pressing
<a href="qt.html#Key-enum">Qt::Key_Down</a> will trigger a call to stepBy(-1).
</p>
<p>
QAbstractSpinBox also provide a method <a href="qabstractspinbox.html#stepEnabled">stepEnabled</a>() to determine whether stepping up/down
is allowed at any point. This method returns a bitset of <a href="qabstractspinbox.html#StepEnabledFlag-enum">StepEnabled</a>.
</p>
<h4>Signals</h4>
<ul>
<li><b>"editingFinished"</b><br/>This signal is emitted editing is finished. This happens when the spinbox loses focus and when enter is pressed.</il>
</ul>
End Rem
Type QAbstractSpinBox Extends QWidget

	Rem
	bbdoc: Little arrows in the classic style.
	end rem
	Const UpDownArrows:Int = 0
	Rem
	bbdoc: + and - symbols.
	end rem
	Const PlusMinus:Int = 1
	Rem
	bbdoc: Don't display buttons.
	end rem
	Const NoButtons:Int = 2

	rem
	bbdoc: The spinbox will revert to the last valid value.
	End Rem
	Const CorrectToPreviousValue:Int = 0
	Rem
	bbdoc: The spinbox will revert to the nearest valid value.
	end rem
	Const CorrectToNearestValue:Int = 1
	Rem
	bbdoc: 
	end rem
	Const StepNone:Int = $00
	Rem
	bbdoc: 
	end rem
	Const StepUpEnabled:Int = $01
	Rem
	bbdoc: 
	end rem
	Const StepDownEnabled:Int = $02

	
	Rem
	bbdoc: Returns the alignment of the spin box.
	about: Possible Values are #Qt_AlignLeft, #Qt_AlignRight, and #Qt_AlignHCenter.
	<p>
	By default, the alignment is #Qt_AlignLeft.
	</p>
	<p>
	Attempting to set the alignment to an illegal flag combination does nothing.
	</p>
	End Rem
	Method alignment:Int()
		Return bmx_qt_qabstractspinbox_alignment(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns the current button symbol mode.
	about: The possible values can be either #UpDownArrows or #PlusMinus. The default is #UpDownArrows.
	<p>
	Note that some styles might render #PlusMinus and UpDownArrows identically.
	</p>
	End Rem
	Method buttonSymbols:Int()
		Return bmx_qt_qabstractspinbox_buttonsybmols(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns the mode to correct an Intermediate value if editing finishes.
	about: The default mode is #CorrectToPreviousValue.
	End Rem
	Method correctionMode:Int()
		Return bmx_qt_qabstractspinbox_correctionmode(qObjectPtr)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method fixup(inp:String Var)
		Local s:String = bmx_qt_qabstractspinbox_fixup(qObjectPtr, inp)
		inp = s
	End Method
	
	Rem
	bbdoc: Returns whether the input satisfies the current validation.
	End Rem
	Method hasAcceptableInput:Int()
		Return bmx_qt_qabstractspinbox_hasacceptableinput(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns whether the spin box draws itself with a frame.
	about: If enabled (the default) the spin box draws itself inside a frame, otherwise the spin box draws itself without any frame.
	End Rem
	Method hasFrame:Int()
		Return bmx_qt_qabstractspinbox_hasframe(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Interprets the text of the spin box.
	about: If the value has changed since last interpretation it will emit signals.
	End Rem
	Method interpretText()
		bmx_qt_qabstractspinbox_interprettext(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns whether the spin box will accelerate the frequency of the steps when pressing the step Up/Down buttons.
	about: If enabled the spin box will increase/decrease the value faster the longer you hold the button down.
	End Rem
	Method isAccelerated:Int()
		Return bmx_qt_qabstractspinbox_isaccelerated(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns whether the spin box is read only.
	about: In read-only mode, the user can still copy the text to the clipboard, or drag and drop the text; but cannot edit it.
	End Rem
	Method isReadOnly:Int()
		Return bmx_qt_qabstractspinbox_isreadonly(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns whether keyboard tracking is enabled for the spinbox.
	about: If keyboard tracking is enabled (the default), the spinbox emits the valueChanged() signal while the new value is
	being entered from the keyboard.
	<p>
	E.g. when the user enters the value 600 by typing 6, 0, and 0, the spinbox emits 3 signals with the values 6, 60, and 600 respectively.
	</p>
	<p>
	If keyboard tracking is disabled, the spinbox doesn't emit the valueChanged() signal while typing. It emits the signal later,
	when the return key is pressed, when keyboard focus is lost, or when other spinbox functionality is used, e.g. pressing an arrow key.
	</p>
	End Rem
	Method keyboardTracking:Int()
		Return bmx_qt_qabstractspinbox_keyboardtracking(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Sets whether the spin box will accelerate the frequency of the steps when pressing the step Up/Down buttons.
	about: If enabled the spin box will increase/decrease the value faster the longer you hold the button down.
	End Rem
	Method setAccelerated(on:Int)
		bmx_qt_qabstractspinbox_setaccelerated(qObjectPtr, on)
	End Method
	
	Rem
	bbdoc: Sets the alignment of the spin box.
	about: Possible Values are #Qt_AlignLeft, #Qt_AlignRight, and #Qt_AlignHCenter.
	<p>
	By default, the alignment is #Qt_AlignLeft.
	</p>
	<p>
	Attempting to set the alignment to an illegal flag combination does nothing.
	</p>
	End Rem
	Method setAlignment(flag:Int)
		bmx_qt_qabstractspinbox_setalignment(qObjectPtr, flag)
	End Method
	
	Rem
	bbdoc: Sets the current button symbol mode.
	about: The possible values can be either #UpDownArrows or #PlusMinus. The default is #UpDownArrows.
	<p>
	Note that some styles might render #PlusMinus and UpDownArrows identically.
	</p>
	End Rem
	Method setButtonSymbols(bs:Int)
		bmx_qt_qabstractspinbox_setbuttonsymbols(qObjectPtr, bs)
	End Method
	
	Rem
	bbdoc: Sets the mode to correct an Intermediate value if editing finishes.
	about: The default mode is #CorrectToPreviousValue.
	End Rem
	Method setCorrectionMode(cm:Int)
		bmx_qt_qabstractspinbox_setcorrectionmode(qObjectPtr, cm)
	End Method
	
	Rem
	bbdoc: Sets whether the spin box draws itself with a frame.
	about: If enabled (the default) the spin box draws itself inside a frame, otherwise the spin box draws itself without any frame.
	End Rem
	Method setFrame(frame:Int)
		bmx_qt_qabstractspinbox_setframe(qObjectPtr, frame)
	End Method
	
	Rem
	bbdoc: Sets whether keyboard tracking is enabled for the spinbox.
	about: If keyboard tracking is enabled (the default), the spinbox emits the valueChanged() signal while the new value is
	being entered from the keyboard.
	<p>
	E.g. when the user enters the value 600 by typing 6, 0, and 0, the spinbox emits 3 signals with the values 6, 60, and 600 respectively.
	</p>
	<p>
	If keyboard tracking is disabled, the spinbox doesn't emit the valueChanged() signal while typing. It emits the signal later,
	when the return key is pressed, when keyboard focus is lost, or when other spinbox functionality is used, e.g. pressing an arrow key.
	</p>
	End Rem
	Method setKeyboardTracking(kt:Int)
		bmx_qt_qabstractspinbox_setkeyboardtracking(qObjectPtr, kt)
	End Method
	
	Rem
	bbdoc: Sets whether the spin box is read only.
	about: In read-only mode, the user can still copy the text to the clipboard, or drag and drop the text; but cannot edit it.
	End Rem
	Method setReadOnly(r:Int)
		bmx_qt_qabstractspinbox_setreadonly(qObjectPtr, r)
	End Method
	
	Rem
	bbdoc: Sets the special-value text.
	about: If set, the spin box will display this text instead of a numeric value whenever the current value is equal to minimum().
	Typical use is to indicate that this choice has a special (default) meaning.
	<p>
	For example, if your spin box allows the user to choose a scale factor (or zoom level) for displaying an image,
	and your application is able to automatically choose one that will enable the image to fit completely within the
	display window, you can set up the spin box like this:
	<pre>
	Local zoomSpinBox:QSpinBox = New QSpinBox.Create()
	zoomSpinBox.setRange(0, 1000)
	zoomSpinBox.setSingleStep(10)
	zoomSpinBox.setSuffix("%")
	zoomSpinBox.setSpecialValueText(tr("Automatic"))
	zoomSpinBox.setValue(100)
	</pre>
	The user will then be able to choose a scale from 1% to 1000% or select "Auto" to leave it up to the application to choose.
	Your code must then interpret the spin box value of 0 as a request from the user to scale the image to fit inside the window.
	</p>
	<p>
	All values are displayed with the prefix and suffix (if set), except for the special value, which only shows the special value
	text. This special text is passed in the QSpinBox::valueChanged() signal that passes a QString.
	</p>
	<p>
	To turn off the special-value text display, call this method with an empty string. The default is no special-value text, i.e.
	the numeric value is shown as usual.
	</p>
	End Rem
	Method setSpecialValueText(txt:String)
		bmx_qt_qabstractspinbox_setspecialvaluetext(qObjectPtr, txt)
	End Method
	
	Rem
	bbdoc: Sets whether the spin box is circular.
	about: If wrapping is true stepping up from maximum() value will take you to the minimum() value and vica versa.
	Wrapping only make sense if you have minimum() and maximum() values set.
	<pre>
	Local spinBox:QSpinBox = new QSpinBox.Create(Self)
	spinBox.setRange(0, 100)
	spinBox.setWrapping(true)
	spinBox.setValue(100)
	spinBox.stepBy(1)
	' value is 0
	</pre>
	End Rem
	Method setWrapping(w:Int)
		bmx_qt_qabstractspinbox_setwrapping(qObjectPtr, w)
	End Method
	
	Rem
	bbdoc: Returns the special-value text.
	about: If set, the spin box will display this text instead of a numeric value whenever the current value is equal to minimum().
	Typical use is to indicate that this choice has a special (default) meaning.
	<p>
	For example, if your spin box allows the user to choose a scale factor (or zoom level) for displaying an image,
	and your application is able to automatically choose one that will enable the image to fit completely within the
	display window, you can set up the spin box like this:
	<pre>
	Local zoomSpinBox:QSpinBox = New QSpinBox.Create()
	zoomSpinBox.setRange(0, 1000)
	zoomSpinBox.setSingleStep(10)
	zoomSpinBox.setSuffix("%")
	zoomSpinBox.setSpecialValueText(tr("Automatic"))
	zoomSpinBox.setValue(100)
	</pre>
	The user will then be able to choose a scale from 1% to 1000% or select "Auto" to leave it up to the application to choose.
	Your code must then interpret the spin box value of 0 as a request from the user to scale the image to fit inside the window.
	</p>
	<p>
	All values are displayed with the prefix and suffix (if set), except for the special value, which only shows the special value
	text. This special text is passed in the QSpinBox::valueChanged() signal that passes a QString.
	</p>
	<p>
	To turn off the special-value text display, call this method with an empty string. The default is no special-value text, i.e.
	the numeric value is shown as usual.
	</p>
	End Rem
	Method specialValueText:String()
		Return bmx_qt_qabstractspinbox_specialvaluetext(qObjectPtr)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method stepBy(steps:Int)
		bmx_qt_qabstractspinbox_stepby(qObjectPtr, steps)
	End Method
	
	Rem
	bbdoc: Returns the spin box's text, including any prefix and suffix.
	about: There is no default text.
	End Rem
	Method text:String()
		Return bmx_qt_qabstractspinbox_text(qObjectPtr)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method validate:Int(inp:String, pos:Int Var)
		Return bmx_qt_qabstractspinbox_validate(qObjectPtr, inp, Varptr pos)
	End Method
	
	Rem
	bbdoc: Returns whether the spin box is circular.
	about: If wrapping is true stepping up from maximum() value will take you to the minimum() value and vica versa.
	Wrapping only make sense if you have minimum() and maximum() values set.
	<pre>
	Local spinBox:QSpinBox = new QSpinBox.Create(Self)
	spinBox.setRange(0, 100)
	spinBox.setWrapping(true)
	spinBox.setValue(100)
	spinBox.stepBy(1)
	' value is 0
	</pre>
	End Rem
	Method wrapping:Int()
		Return bmx_qt_qabstractspinbox_wrapping(qObjectPtr)
	End Method

	Rem
	bbdoc: Clears the lineedit of all text but prefix and suffix.
	End Rem
	Method clear()
		bmx_qt_qabstractspinbox_clear(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Selects all the text in the spinbox except the prefix and suffix.
	End Rem
	Method selectAll()
		bmx_qt_qabstractspinbox_selectall(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Steps down by one linestep.
	about: Calling this slot is analogous to calling stepBy(-1)
	End Rem
	Method stepDown()
		bmx_qt_qabstractspinbox_stepdown(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Steps up by one linestep.
	about: Calling this slot is analogous to calling stepBy(1)
	End Rem
	Method stepUp()
		bmx_qt_qabstractspinbox_stepup(qObjectPtr)
	End Method
	

	' SIGNAL : editingFinished
	Function _OnEditingFinished(obj:QAbstractSpinBox)
		obj._InvokeSignals("editingFinished", Null)
	End Function

End Type


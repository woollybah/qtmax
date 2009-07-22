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

Module Qt.QLineEdit

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Rem
bbdoc: A one-line text editor.
about: A line edit allows the user to enter and edit a single line of plain text with a useful collection of editing
functions, including undo and redo, cut and paste, and drag and drop.
<p>
By changing the echoMode() of a line edit, it can also be used as a "write-only" field, for inputs such as passwords.
</p>
<p>
The length of the text can be constrained to maxLength(). The text can be arbitrarily constrained using a validator() or an
inputMask(), or both.
</p>
<p>
A related class is QTextEdit which allows multi-line, rich text editing.
</p>
<p>
You can change the text with setText() or insert(). The text is retrieved with text(); the displayed text (which may be different,
see EchoMode) is retrieved with displayText(). Text can be selected with setSelection() or selectAll(), and the selection can be
cut(), copy()ied and paste()d. The text can be aligned with setAlignment().
</p>
<p>
When the text changes the textChanged() signal is emitted; when the text changes other than by calling setText() the textEdited()
signal is emitted; when the cursor is moved the cursorPositionChanged() signal is emitted; and when the Return or Enter key is
pressed the returnPressed() signal is emitted.
</p>
<p>
When editing is finished, either because the line edit lost focus or Return/Enter is pressed the editingFinished() signal is emitted.
</p>
<p>
Note that if there is a validator set on the line edit, the returnPressed()/editingFinished() signals will only be emitted if
the validator returns QValidator::Acceptable.
</p>
<p>
By default, QLineEdits have a frame as specified by the Windows and Motif style guides; you can turn it off by calling setFrame(false).
</p>
<p>The default key bindings are described below. The line edit also provides a context menu (usually invoked by a right mouse
click) that presents some of these editing options.
</p>
<p>
<table align="center">
<tr valign="top"><th>Keypress</th><th>Action</th></tr>
<tr valign="top"><td>Left Arrow</td><td>Moves the cursor one character to the left.</td></tr>
<tr valign="top"><td>Shift+Left Arrow</td><td>Moves and selects text one character to the left.</td></tr>
<tr valign="top"><td>Right Arrow</td><td>Moves the cursor one character to the right.</td></tr>
<tr valign="top"><td>Shift+Right Arrow</td><td>Moves and selects text one character to the right.</td></tr>
<tr valign="top"><td>Home</td><td>Moves the cursor to the beginning of the line.</td></tr>
<tr valign="top"><td>End</td><td>Moves the cursor to the end of the line.</td></tr>
<tr valign="top"><td>Backspace</td><td>Deletes the character to the left of the cursor.</td></tr>
<tr valign="top"><td>Ctrl+Backspace</td><td>Deletes the word to the left of the cursor.</td></tr>
<tr valign="top"><td>Delete</td><td>Deletes the character to the right of the cursor.</td></tr>
<tr valign="top"><td>Ctrl+Delete</td><td>Deletes the word to the right of the cursor.</td></tr>
<tr valign="top"><td>Ctrl+A</td><td>Select all.</td></tr>
<tr valign="top"><td>Ctrl+C</td><td>Copies the selected text to the clipboard.</td></tr>
<tr valign="top"><td>Ctrl+Insert</td><td>Copies the selected text to the clipboard.</td></tr>
<tr valign="top"><td>Ctrl+K</td><td>Deletes to the end of the line.</td></tr>
<tr valign="top"><td>Ctrl+V</td><td>Pastes the clipboard text into line edit.</td></tr>
<tr valign="top"><td>Shift+Insert</td><td>Pastes the clipboard text into line edit.</td></tr>
<tr valign="top"><td>Ctrl+X</td><td>Deletes the selected text and copies it to the clipboard.</td></tr>
<tr valign="top"><td>Shift+Delete</td><td>Deletes the selected text and copies it to the clipboard.</td></tr>
<tr valign="top"><td>Ctrl+Z</td><td>Undoes the last operation.</td></tr>
<tr valign="top"><td>Ctrl+Y</td><td>Redoes the last undone operation.</td></tr>
</table>
</p>
<p>Any other key sequence that represents a valid character, will cause the character to be inserted into the line edit.
</p>
<p>
<table width="100%" align="center">
<tr valign="top"><td><img src="macintosh-lineedit.png" alt="Screenshot of a Macintosh style line edit" /></td><td>A line edit shown in the Macintosh widget style.</td></tr>
<tr valign="top"><td><img src="windows-lineedit.png" alt="Screenshot of a Windows XP style line edit" /></td><td>A line edit shown in the Windows XP widget style.</td></tr>
<tr valign="top"><td><img src="plastique-lineedit.png" alt="Screenshot of a Plastique style line edit" /></td><td>A line edit shown in the Plastique widget style.</td></tr>
</table>
</p>
End Rem
Type QLineEdit Extends QWidget

	Function CreateLineEdit:QLineEdit(parent:QWidget = Null)
		Return New QLineEdit.Create(parent)
	End Function
	
	Method Create:QLineEdit(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qlineedit_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qlineedit_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method setReadOnly(value:Int)
		bmx_qt_qlineedit_setreadonly(qObjectPtr, value)
	End Method

End Type



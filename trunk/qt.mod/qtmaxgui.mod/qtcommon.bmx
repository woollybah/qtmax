' Copyright (c) 2012-2013 Bruce A Henderson
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


Import BRL.System
Import MaxGUI.MaxGUI

Import Qt.QApplication
Import Qt.QEventLoop
Import Qt.QMainWindow
Import Qt.QPushButton
Import Qt.QCheckBox
Import Qt.QRadioButton
Import Qt.QLabel
Import Qt.QGroupBox
Import Qt.QVBoxLayout
Import Qt.QLineEdit
Import Qt.QTextEdit
Import Qt.QListView
Import Qt.QProgressBar
Import Qt.QComboBox
Import Qt.QTabWidget
Import Qt.QTreeView
Import Qt.QWebKit
Import Qt.QSlider
Import Qt.QColorDialog
Import Qt.QMessageBox
Import Qt.QSpinBox
Import Qt.QSocketNotifier
Import Qt.QStandardItemModel

' gadget identifiers
Const QT_WINDOW:Int = 0
Const QT_BUTTON:Int = 1
Const QT_RADIOBUTTON:Int = 2
Const QT_CHECKBUTTON:Int = 3
Const QT_TOGGLEBUTTON:Int = 4
Const QT_LABEL:Int = 5
Const QT_MENUITEM:Int = 6
Const QT_TEXTFIELD:Int = 7
Const QT_TEXTAREA:Int = 8
Const QT_PANEL:Int = 9
Const QT_COMBOBOX:Int = 10
Const QT_HTMLVIEW:Int = 11
Const QT_TABBER:Int = 12
Const QT_PROGRESSBAR:Int = 13
Const QT_SCROLLBAR:Int = 14
Const QT_TRACKBAR:Int = 15
Const QT_STEPPER:Int = 16
Const QT_DESKTOP:Int = 17
Const QT_TOOLBAR:Int = 18
Const QT_LISTBOX:Int = 19
Const QT_TREEVIEW:Int = 20
Const QT_CANVAS:Int = 21


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

Module Qt.QWebKit

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"

?macos
ModuleInfo "LD_OPTS: -L%PWD%/../lib/macos/"
?win32
ModuleInfo "LD_OPTS: -L%PWD%/../lib/win32/"
?

?macos
Import "-lQtWebKit.4"
?win32
Import "-lQtWebKit4"
?linux
Import "-lQtWebKit"
?

Import "common.bmx"



Type QWebView Extends QWidget

	Function CreateWebView:QWebView(parent:QWidget = Null, flags:Int = 0)
		Return New QWebView.Create(parent)
	End Function
	
	Method Create:QWebView(parent:QWidget = Null, flags:Int = 0)
		If parent Then
			qObjectPtr = bmx_qt_qwebview_create(Self, parent.qObjectPtr, flags)
		Else
			qObjectPtr = bmx_qt_qwebview_create(Self, Null, flags)
		End If
		Return Self
	End Method

	Method findText:Int(subString:String, options:Int = 0)
	' TODO
	End Method
	
	Method history:QWebHistory()
	' TODO
	End Method
	
	Method icon:QIcon()
	' TODO
	End Method
	
	Method isModified:Int()
	' TODO
	End Method
	
	Method Load(url:QUrl)
		bmx_qt_qwebview_load(qObjectPtr, url.qObjectPtr)
	End Method
	
	'Method loadRequest(request:QNetworkRequest, operation:Int = QNetworkAccessManager.GetOperation, body:String = Null)
	' TODO
	'End Method
	
	Method page:QWebPage()
	' TODO
	End Method
	
	Method pageAction:QAction(action:Int)
	' TODO
	End Method
	
	Method selectedText:String()
	' TODO
	End Method
	
	Method setContent(data:String, mimeType:String = Null, baseUrl:QUrl = Null)
	' TODO
	End Method
	
	Method setHtml(html:String, baseUrl:QUrl = Null)
	' TODO
	End Method
	
	Method setPage(page:QWebPage)
	' TODO
	End Method
	
	Method setTextSizeMultiplier(factor:Double)
	' TODO
	End Method
	
	Method setUrl(url:QUrl)
	' TODO
	End Method
	
	Method setZoomFactor(factor:Double)
	' TODO
	End Method
	
	Method settings:QWebSettings()
	' TODO
	End Method
	
	Method textSizeMultiplier:Double()
	' TODO
	End Method
	
	Method title:String()
	' TODO
	End Method
	
	Method triggerPageAction(action:Int, checked:Int = False)
	' TODO
	End Method
	
	Method url:QUrl()
	' TODO
	End Method
	
	Method zoomFactor:Double()
	' TODO
	End Method

End Type


Type QWebPage Extends QObject

	Method action:QAction(action:Int)
	' TODO
	End Method
	
	Method bytesReceived:Long()
	' TODO
	End Method
	
	Method createStandardContextMenu:QMenu()
	' TODO
	End Method
	
	Method currentFrame:QWebFrame()
	' TODO
	End Method
	
	'Method extension:Int(Extension extension, ExtensionOption * option = 0, ExtensionReturn * output = 0)
	' TODO
	'End Method
	
	Method findText:Int(subString:String, options:Int = 0)
	' TODO
	End Method
	
	Method focusNextPrevChild:Int(_next:Int)
	' TODO
	End Method
	
	Method forwardUnsupportedContent:Int()
	' TODO
	End Method
	
	Method history:QWebHistory()
	' TODO
	End Method
	
	'Method inputMethodQuery:QVariant(property:Int)
	' TODO
	'End Method
	
	Method isContentEditable:Int()
	' TODO
	End Method
	
	Method isModified:Int()
	' TODO
	End Method
	
	Method linkDelegationPolicy:Int()
	' TODO
	End Method
	
	Method mainFrame:QWebFrame()
	' TODO
	End Method
	
	Method networkAccessManager:QNetworkAccessManager()
	' TODO
	End Method
	
	Method palette:QPalette()
	' TODO
	End Method
	
	Method pluginFactory:QWebPluginFactory()
	' TODO
	End Method
	
	Method selectedText:String()
	' TODO
	End Method
	
	Method setContentEditable(editable:Int)
	' TODO
	End Method
	
	Method setForwardUnsupportedContent(forward:Int)
	' TODO
	End Method
	
	Method setLinkDelegationPolicy(policy:Int)
	' TODO
	End Method
	
	Method setNetworkAccessManager(manager:QNetworkAccessManager)
	' TODO
	End Method
	
	Method setPalette(palette:QPalette)
	' TODO
	End Method
	
	Method setPluginFactory(factory:QWebPluginFactory)
	' TODO
	End Method
	
	Method setView(view:QWidget)
	' TODO
	End Method
	
	Method setViewportSize(w:Int, h:Int)
	' TODO
	End Method
	
	Method settings:QWebSettings()
	' TODO
	End Method
	
	'Method supportsExtension:Int(ext:Extension)
	' TODO
	'End Method
	
	Method swallowContextMenuEvent:Int(event:QContextMenuEvent)
	' TODO
	End Method
	
	Method totalBytes:Long()
	' TODO
	End Method
	
	Method triggerAction(action:Int, checked:Int = False)
	' TODO
	End Method
	
	Method undoStack:QUndoStack()
	' TODO
	End Method
	
	Method updatePositionDependentActions(x:Int, y:Int)
	' TODO
	End Method
	
	Method view:QWidget()
	' TODO
	End Method
	
	Method viewportSize(w:Int Var, h:Int Var)
	' TODO
	End Method

	
End Type

Type QWebFrame Extends QObject

End Type


Type QWebPluginFactory Extends QObject

End Type

Type QWebHistory

	Field qObjectPtr:Byte Ptr

End Type

Type QWebSettings

	Field qObjectPtr:Byte Ptr

End Type



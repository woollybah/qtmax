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

Module Qt.QWebKit

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"

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

	Method back()
		bmx_qt_qwebview_back(qObjectPtr)
	End Method
	
	Method findText:Int(subString:String, options:Int = 0)
		Return bmx_qt_qwebview_findtext(qObjectPtr, subString, options)
	End Method

	Method forward()
		bmx_qt_qwebview_forward(qObjectPtr)
	End Method
	
	Method history:QWebHistory()
	' TODO
	End Method
	
	Method icon:QIcon()
		Return QIcon._create(bmx_qt_qwebview_icon(qObjectPtr))
	End Method
	
	Method isModified:Int()
		Return bmx_qt_qwebview_ismodified(qObjectPtr)
	End Method
	
	Method Load(url:QUrl)
		bmx_qt_qwebview_load(qObjectPtr, url.qObjectPtr)
	End Method
	
	'Method loadRequest(request:QNetworkRequest, operation:Int = QNetworkAccessManager.GetOperation, body:String = Null)
	' TODO
	'End Method
	
	Method page:QWebPage()
		Return QWebPage._create(bmx_qt_qwebview_page(qObjectPtr))
	End Method
	
	Method pageAction:QAction(action:Int)
		Return QAction._find(bmx_qt_qwebview_pageaction(qObjectPtr, action))
	End Method

	Method Print(printer:QPrinter)
	' TODO
	End Method
	
	Method reload()
		bmx_qt_qwebview_reload(qObjectPtr)
	End Method
	
	Method selectedText:String()
		Return bmx_qt_qwebview_selectedtext(qObjectPtr)
	End Method
	
	Method setContent(data:String, mimeType:String = Null, baseUrl:QUrl = Null)
	' TODO
	End Method
	
	Method setHtml(html:String, baseUrl:QUrl = Null)
		If baseUrl Then
			bmx_qt_qwebview_sethtml(qObjectPtr, html, baseUrl.qObjectPtr)
		Else
			bmx_qt_qwebview_sethtml(qObjectPtr, html, Null)
		End If
	End Method
	
	Method setPage(page:QWebPage)
		bmx_qt_qwebview_setpage(qObjectPtr, page.qObjectPtr)
	End Method
	
	Method setTextSizeMultiplier(factor:Double)
		bmx_qt_qwebview_settextsizemultiplier(qObjectPtr, factor)
	End Method
	
	Method setUrl(url:QUrl)
		bmx_qt_qwebview_seturl(qObjectPtr, url.qObjectPtr)
	End Method
	
	Method setZoomFactor(factor:Double)
		bmx_qt_qwebview_setzoomfactor(qObjectPtr, factor)
	End Method
	
	Method settings:QWebSettings()
		Return QWebSettings._create(bmx_qt_qwebview_settings(qObjectPtr))
	End Method

	Method stop()
		bmx_qt_qwebview_stop(qObjectPtr)
	End Method
	
	Method textSizeMultiplier:Double()
	' TODO
	End Method
	
	Method title:String()
		Return bmx_qt_qwebview_title(qObjectPtr)
	End Method
	
	Method triggerPageAction(action:Int, checked:Int = False)
	' TODO
	End Method
	
	Method url:QUrl()
		Return QUrl._create(bmx_qt_qwebview_url(qObjectPtr))
	End Method
	
	Method zoomFactor:Double()
	' TODO
	End Method



	' DEFAULT EVENT HANDLERS
	
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qwebview_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qwebview_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qwebview_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qwebview_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qwebview_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qwebview_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qwebview_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qwebview_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qwebview_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qwebview_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qwebview_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qwebview_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qwebview_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qwebview_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qwebview_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qwebview_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qwebview_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qwebview_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qwebview_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qwebview_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qwebview_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qwebview_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qwebview_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qwebview_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qwebview_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qwebview_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qwebview_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qwebview_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qwebview_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qwebview_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qwebview_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method



	' SIGNAL : iconChanged
	Function _OnIconChanged(obj:QWebView)
		obj._InvokeSignals("iconChanged", Null)
	End Function

	' SIGNAL : linkClicked
	Function _OnLinkClicked(obj:QWebView, url:Byte Ptr)
		obj._InvokeSignals("linkClicked", [QUrl._create(url)])
	End Function

	' SIGNAL : loadFinished
	Function _OnLoadFinished(obj:QWebView, ok:Int)
		obj._InvokeSignals("loadFinished", [String(ok)])
	End Function

	' SIGNAL : loadProgress
	Function _OnLoadProgress(obj:QWebView, progress:Int)
		obj._InvokeSignals("loadProgress", [String(progress)])
	End Function

	' SIGNAL : loadStarted
	Function _OnLoadStarted(obj:QWebView)
		obj._InvokeSignals("loadStarted", Null)
	End Function

	' SIGNAL : selectionChanged
	Function _OnSelectionChanged(obj:QWebView)
		obj._InvokeSignals("selectionChanged", Null)
	End Function

	' SIGNAL : statusBarMessage
	Function _OnStatusBarMessage(obj:QWebView, text:String)
		obj._InvokeSignals("statusBarMessage", [text])
	End Function

	' SIGNAL : titleChanged
	Function _OnTitleChanged(obj:QWebView, title:String)
		obj._InvokeSignals("titleChanged", [title])
	End Function

	' SIGNAL : urlChanged
	Function _OnUrlChanged(obj:QWebView, url:Byte Ptr)
		obj._InvokeSignals("urlChanged", [QUrl._create(url)])
	End Function

End Type


Type QWebPage Extends QObject

	Rem
	bbdoc: No action is triggered.
	end rem
	Const WA_NoWebAction:Int = -1
	Rem
	bbdoc: Open the current link.
	end rem
	Const WA_OpenLink:Int = 0
	Rem
	bbdoc: Open the current link in a new window.
	end rem
	Const WA_OpenLinkInNewWindow:Int = 1
	Rem
	bbdoc: Replicate the current frame in a new window.
	end rem
	Const WA_OpenFrameInNewWindow:Int = 2
	Rem
	bbdoc: Download the current link to the disk.
	end rem
	Const WA_DownloadLinkToDisk:Int = 3
	Rem
	bbdoc: Copy the current link to the clipboard.
	end rem
	Const WA_CopyLinkToClipboard:Int = 4
	Rem
	bbdoc: Open the highlighted image in a new window.
	end rem
	Const WA_OpenImageInNewWindow:Int = 5
	Rem
	bbdoc: Download the highlighted image to the disk.
	end rem
	Const WA_DownloadImageToDisk:Int = 6
	Rem
	bbdoc: Copy the highlighted image to the clipboard.
	end rem
	Const WA_CopyImageToClipboard:Int = 7
	Rem
	bbdoc: Navigate back in the history of navigated links.
	end rem
	Const WA_Back:Int = 8
	Rem
	bbdoc: Navigate forward in the history of navigated links.
	end rem
	Const WA_Forward:Int = 9
	Rem
	bbdoc: Stop loading the current page.
	end rem
	Const WA_Stop:Int = 10
	Rem
	bbdoc: Reload the current page.
	end rem
	Const WA_Reload:Int = 11
	Rem
	bbdoc: Cut the content currently selected into the clipboard.
	end rem
	Const WA_Cut:Int = 12
	Rem
	bbdoc: Copy the content currently selected into the clipboard.
	end rem
	Const WA_Copy:Int = 13
	Rem
	bbdoc: Paste content from the clipboard.
	end rem
	Const WA_Paste:Int = 14
	Rem
	bbdoc: Undo the last editing action.
	end rem
	Const WA_Undo:Int = 15
	Rem
	bbdoc: Redo the last editing action.
	end rem
	Const WA_Redo:Int = 16
	Rem
	bbdoc: Move the cursor to the next character.
	end rem
	Const WA_MoveToNextChar:Int = 17
	Rem
	bbdoc: Move the cursor to the previous character.
	end rem
	Const WA_MoveToPreviousChar:Int = 18
	Rem
	bbdoc: Move the cursor to the next word.
	end rem
	Const WA_MoveToNextWord:Int = 19
	Rem
	bbdoc: Move the cursor to the previous word.
	end rem
	Const WA_MoveToPreviousWord:Int = 20
	Rem
	bbdoc: Move the cursor to the next line.
	end rem
	Const WA_MoveToNextLine:Int = 21
	Rem
	bbdoc: Move the cursor to the previous line.
	end rem
	Const WA_MoveToPreviousLine:Int = 22
	Rem
	bbdoc: Move the cursor to the start of the line.
	end rem
	Const WA_MoveToStartOfLine:Int = 23
	Rem
	bbdoc: Move the cursor to the end of the line.
	end rem
	Const WA_MoveToEndOfLine:Int = 24
	Rem
	bbdoc: Move the cursor to the start of the block.
	end rem
	Const WA_MoveToStartOfBlock:Int = 25
	Rem
	bbdoc: Move the cursor to the end of the block.
	end rem
	Const WA_MoveToEndOfBlock:Int = 26
	Rem
	bbdoc: Move the cursor to the start of the document.
	end rem
	Const WA_MoveToStartOfDocument:Int = 27
	Rem
	bbdoc: Move the cursor to the end of the document.
	end rem
	Const WA_MoveToEndOfDocument:Int = 28
	Rem
	bbdoc: Select to the next character.
	end rem
	Const WA_SelectNextChar:Int = 29
	Rem
	bbdoc: Select to the previous character.
	end rem
	Const WA_SelectPreviousChar:Int = 30
	Rem
	bbdoc: Select to the next word.
	end rem
	Const WA_SelectNextWord:Int = 31
	Rem
	bbdoc: Select to the previous word.
	end rem
	Const WA_SelectPreviousWord:Int = 32
	Rem
	bbdoc: Select to the next line.
	end rem
	Const WA_SelectNextLine:Int = 33
	Rem
	bbdoc: Select to the previous line.
	end rem
	Const WA_SelectPreviousLine:Int = 34
	Rem
	bbdoc: Select to the start of the line.
	end rem
	Const WA_SelectStartOfLine:Int = 35
	Rem
	bbdoc: Select to the end of the line.
	end rem
	Const WA_SelectEndOfLine:Int = 36
	Rem
	bbdoc: Select to the start of the block.
	end rem
	Const WA_SelectStartOfBlock:Int = 37
	Rem
	bbdoc: Select to the end of the block.
	end rem
	Const WA_SelectEndOfBlock:Int = 38
	Rem
	bbdoc: Select to the start of the document.
	end rem
	Const WA_SelectStartOfDocument:Int = 39
	Rem
	bbdoc: Select to the end of the document.
	end rem
	Const WA_SelectEndOfDocument:Int = 40
	Rem
	bbdoc: Delete to the start of the word.
	end rem
	Const WA_DeleteStartOfWord:Int = 41
	Rem
	bbdoc: Delete to the end of the word.
	end rem
	Const WA_DeleteEndOfWord:Int = 42
	Rem
	bbdoc: Set the text direction to the default direction.
	end rem
	Const WA_SetTextDirectionDefault:Int = 43
	Rem
	bbdoc: Set the text direction to left-to-right.
	end rem
	Const WA_SetTextDirectionLeftToRight:Int = 44
	Rem
	bbdoc: Set the text direction to right-to-left.
	end rem
	Const WA_SetTextDirectionRightToLeft:Int = 45
	Rem
	bbdoc: Toggle the formatting between bold and normal weight.
	end rem
	Const WA_ToggleBold:Int = 46
	Rem
	bbdoc: Toggle the formatting between italic and normal style.
	end rem
	Const WA_ToggleItalic:Int = 47
	Rem
	bbdoc: Toggle underlining.
	end rem
	Const WA_ToggleUnderline:Int = 48
	Rem
	bbdoc: Show the Web Inspector with the currently highlighted HTML element.
	end rem
	Const WA_InspectElement:Int = 49
	Rem
	bbdoc: Insert a new paragraph.
	end rem
	Const WA_InsertParagraphSeparator:Int = 50
	Rem
	bbdoc: Insert a new line.
	end rem
	Const WA_InsertLineSeparator:Int = 51
	Rem
	bbdoc: Selects all content.
	end rem
	Const WA_SelectAll:Int = 52

	Function _create:QWebPage(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QWebPage = New QWebPage
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
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
		Return QWebFrame._create(bmx_qt_qwebpage_mainframe(qObjectPtr))
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

	Function _create:QWebFrame(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QWebFrame = New QWebFrame
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function _find:QWebFrame(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local frame:QWebFrame = QWebFrame(qfind(qObjectPtr))
			If Not frame Then
				Return QWebFrame._create(qObjectPtr)
			End If
			Return frame
		End If
	End Function

	Method addToJavaScriptWindowObject(name:String, obj:QObject)
	' TODO
	End Method
	
	Method addToJavaScriptWindowObjectOwner(name:String, obj:QObject, own:Int)
	' TODO
	End Method
	
	Method childFrames:QWebFrame[]()
	' TODO
	End Method
	
	Method contentsSize(w:Int Var, h:Int Var)
	' TODO
	End Method
	
	Method frameName:String()
	' TODO
	End Method
	
	Method geometry:QRect()
	' TODO
	End Method
	
	Method hitTestContent:QWebHitTestResult(x:Int, y:Int)
		Return QWebHitTestResult._create(bmx_qt_qwebframe_hittestcontent(qObjectPtr, x, y))
	End Method
	
	Method icon:QIcon()
	' TODO
	End Method
	
	Method Load(url:QUrl)
	' TODO
	End Method
	
	'Method loadRequest(req:QWebNetworkRequest)
	' TODO
	'End Method
	
	Method metaData:TMap()
	' TODO
	End Method
	
	Method page:QWebPage()
	' TODO
	End Method
	
	Method parentFrame:QWebFrame()
	' TODO
	End Method
	
	Method pos(x:Int Var, y:Int Var)
	' TODO
	End Method
	
	Method render(painter:QPainter, clip:QRegion = Null)
	' TODO
	End Method
	
	Method renderTreeDump:String()
	' TODO
	End Method
	
	Method scroll(dx:Int, dy:Int)
	' TODO
	End Method
	
	Method scrollBarMaximum:Int(orientation:Int)
	' TODO
	End Method
	
	Method scrollBarMinimum:Int(orientation:Int)
	' TODO
	End Method
	
	Method scrollBarPolicy:Int(orientation:Int)
	' TODO
	End Method
	
	Method scrollBarValue(orientation:Int)
	' TODO
	End Method
	
	Method scrollPosition(x:Int Var, y:Int Var)
	' TODO
	End Method
	
	Method securityOrigin:QWebSecurityOrigin()
	' TODO
	End Method
	
	'Method setContent(QByteArray & data, QString & mimeType = QString(), QUrl & baseUrl = QUrl())
	' TODO
	'End Method
	
	Method setHtml(html:String, baseUrl:QUrl = Null)
	' TODO
	End Method
	
	Method setScrollBarPolicy(orientation:Int, policy:Int)
	' TODO
	End Method
	
	Method setScrollBarValue(orientation:Int, value:Int)
	' TODO
	End Method
	
	Method setScrollPosition(x:Int, y:Int)
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
	
	Method textSizeMultiplier:Double()
	' TODO
	End Method
	
	Method title:String()
	' TODO
	End Method
	
	Method toHtml:String()
	' TODO
	End Method
	
	Method toPlainText:String()
	' TODO
	End Method
	
	Method url:QUrl()
	' TODO
	End Method
	
	Method zoomFactor:Double()
	' TODO
	End Method

	Method evaluateJavaScript:String(scriptSource:String)
		Return bmx_qt_qwebframe_evaluatejavascript(qObjectPtr, scriptSource)
	End Method
	
End Type


Type QWebPluginFactory Extends QObject

End Type

Type QWebSettings

	Field qObjectPtr:Byte Ptr

	Rem
	bbdoc: Specifies whether images are automatically loaded in web pages.
	end rem
	Const WA_AutoLoadImages:Int = 0
	Rem
	bbdoc: Enables or disables the running of JavaScript programs.
	end rem
	Const WA_JavascriptEnabled:Int = 1
	Rem
	bbdoc: Enables or disables Java applets.
	about: Currently Java applets are not supported.
	End Rem
	Const WA_JavaEnabled:Int = 2
	Rem
	bbdoc: Enables or disables plugins in Web pages.
	end rem
	Const WA_PluginsEnabled:Int = 3
	Rem
	bbdoc: Private browsing prevents WebKit from recording visited pages in the history and storing web page icons.
	end rem
	Const WA_PrivateBrowsingEnabled:Int = 4
	Rem
	bbdoc: Specifies whether JavaScript programs can open new windows.
	end rem
	Const WA_JavascriptCanOpenWindows:Int = 5
	Rem
	bbdoc: Specifies whether JavaScript programs can read or write to the clipboard.
	end rem
	Const WA_JavascriptCanAccessClipboard:Int = 6
	Rem
	bbdoc: Enables extra tools for Web developers.
	about: Currently this enables the "Inspect" element in the context menu, which shows the WebKit WebInspector for web site debugging.
	End Rem
	Const WA_DeveloperExtrasEnabled:Int = 7
	Rem
	bbdoc: Specifies whether hyperlinks should be included in the keyboard focus chain.
	end rem
	Const WA_LinksIncludedInFocusChain:Int = 8
	Rem
	bbdoc: Specifies whether the zoom factor on a frame applies to only the text or all content.
	end rem
	Const WA_ZoomTextOnly:Int = 9
	Rem
	bbdoc: Specifies whether the background color and images are also drawn when the page is printed.
	end rem
	Const WA_PrintElementBackgrounds:Int = 10
	Rem
	bbdoc: Specifies whether support for the HTML 5 offline storage feature is enabled or not.
	end rem
	Const WA_OfflineStorageDatabaseEnabled:Int = 11
	Rem
	bbdoc: Specifies whether support for the HTML 5 web application cache feature is enabled or not.
	end rem
	Const WA_OfflineWebApplicationCacheEnabled:Int = 12
	Rem
	bbdoc: Specifies whether support for the HTML 5 local storage feature is enabled or not.
	end rem
	Const WA_LocalStorageDatabaseEnabled:Int = 13

	
	Function _create:QWebSettings(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QWebSettings = New QWebSettings
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Method fontFamily:String(which:Int)
		Return bmx_qt_qwebsettings_fontfamily(qObjectPtr, which)
	End Method
	
	Method FontSize:Int(sizeType:Int)
		Return bmx_qt_qwebsettings_fontsize(qObjectPtr, sizeType)
	End Method
	
	Method resetAttribute(attribute:Int)
		bmx_qt_qwebsettings_resetattribute(qObjectPtr, attribute)
	End Method
	
	Method resetFontFamily(which:Int)
		bmx_qt_qwebsettings_resetfontfamily(qObjectPtr, which)
	End Method
	
	Method resetFontSize(sizeType:Int)
		bmx_qt_qwebsettings_resetfontsize(qObjectPtr, sizeType)
	End Method
	
	Method setAttribute(attribute:Int, on:Int = True)
		bmx_qt_qwebsettings_setattribute(qObjectPtr, attribute, on)
	End Method

	Method setFontFamily(which:Int, family:String)
		bmx_qt_qwebsettings_setfontfamily(qObjectPtr, which, family)
	End Method
	
	Method setFontSize(sizeType:Int, size:Int)
		bmx_qt_qwebsettings_setfontsize(qObjectPtr, sizeType, size)
	End Method
	
	Method setUserStyleSheetUrl(location:QUrl)
		bmx_qt_qwebsettings_setuserstylesheeturl(qObjectPtr, location.qObjectPtr)
	End Method
	
	Method testAttribute:Int(attribute:Int)
		Return bmx_qt_qwebsettings_testattribute(qObjectPtr, attribute)
	End Method
	
	Method userStyleSheetUrl:QUrl() 
		Return QUrl._create(bmx_qt_qwebsettings_userstylesheeturl(qObjectPtr))
	End Method
	
	Function clearIconDatabase()
		bmx_qt_qwebsettings_clearicondatabase()
	End Function
	
	Function globalSettings:QWebSettings()
		Return QWebSettings._create(bmx_qt_qwebsettings_globalsettings())
	End Function
	
	Function iconDatabasePath:String()
		Return bmx_qt_qwebsettings_icondatabasepath()
	End Function
	
	Function iconForUrl:QIcon(url:QUrl)
		Return QIcon._create(bmx_qt_qwebsettings_iconforurl(url.qObjectPtr))
	End Function
	
	Function maximumPagesInCache:Int()
		Return bmx_qt_qwebsettings_maximumpagesincache()
	End Function
	
	Function offlineStorageDefaultQuota:Long()
		Local value:Long
		bmx_qt_qwebsettings_offlinestoragedefaultquota(Varptr value)
		Return value
	End Function
	
	Function offlineStoragePath:String()
		Return bmx_qt_qwebsettings_offlinestoragepath()
	End Function
	
	Function setIconDatabasePath(path:String)
		bmx_qt_qwebsettings_seticondatabasepath(path)
	End Function
	
	Function setMaximumPagesInCache(pages:Int)
		bmx_qt_qwebsettings_setmaximumpagesincache(pages)
	End Function
	
	Function setObjectCacheCapacities(cacheMinDeadCapacity:Int, cacheMaxDead:Int, totalCapacity:Int)
		bmx_qt_qwebsettings_setobjectcachecapacities(cacheMinDeadCapacity, cacheMaxDead, totalCapacity)
	End Function
	
	Function setOfflineStorageDefaultQuota(maximumSize:Long)
		bmx_qt_qwebsettings_setofflinestoragedefaultquota(maximumSize)
	End Function
	
	Function setOfflineStoragePath(path:String)
		bmx_qt_qwebsettings_setofflinestoragepath(path)
	End Function
	
	Function setWebGraphic(graphicType:Int, graphic:QPixmap)
		bmx_qt_qwebsettings_setwebgraphic(graphicType, graphic.qObjectPtr)
	End Function
	
	Function webGraphic:QPixmap(graphicType:Int)
		Return QPixmap._create(bmx_qt_qwebsettings_webgraphic(graphicType))
	End Function

End Type

Type QWebHitTestResult

	Field qObjectPtr:Byte Ptr

	Function _create:QWebHitTestResult(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QWebHitTestResult = New QWebHitTestResult
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method alternateText:String()
		Return bmx_qt_qwebhittestresult_alternatetext(qObjectPtr)
	End Method
	
	Method boundingRect:QRect()
		Return QRect._create(bmx_qt_qwebhittestresult_boundingrect(qObjectPtr))
	End Method
	
	Method frame:QWebFrame()
		Return QWebFrame._find(bmx_qt_qwebhittestresult_frame(qObjectPtr))
	End Method
	
	Method imageUrl:QUrl()
		Return QUrl._create(bmx_qt_qwebhittestresult_imageurl(qObjectPtr))
	End Method
	
	Method isContentEditable:Int()
		Return bmx_qt_qwebhittestresult_iscontenteditable(qObjectPtr)
	End Method
	
	Method isContentSelected:Int()
		Return bmx_qt_qwebhittestresult_iscontentselected(qObjectPtr)
	End Method
	
	Method isNull:Int()
		Return bmx_qt_qwebhittestresult_isnull(qObjectPtr)
	End Method
	
	Method linkTargetFrame:QWebFrame()
		Return QWebFrame._find(bmx_qt_qwebhittestresult_linktargetframe(qObjectPtr))
	End Method
	
	Method linkText:String()
		Return bmx_qt_qwebhittestresult_linktext(qObjectPtr)
	End Method
	
	Method linkTitle:QUrl()
		Return QUrl._create(bmx_qt_qwebhittestresult_linktitle(qObjectPtr))
	End Method
	
	Method linkUrl:QUrl()
		Return QUrl._create(bmx_qt_qwebhittestresult_linkurl(qObjectPtr))
	End Method
	
	Method pixmap:QPixmap()
		Return QPixmap._create(bmx_qt_qwebhittestresult_pixmap(qObjectPtr))
	End Method
	
	Method pos(x:Int Var, y:Int Var)
		bmx_qt_qwebhittestresult_pos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method title:String()
		Return bmx_qt_qwebhittestresult_title(qObjectPtr)
	End Method

	Method Delete()
		If qObjectPtr Then
			bmx_qt_qwebhittestresult_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
End Type


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

Module Qt.QObject

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Rem
bbdoc: 
End Rem
Type QObject Extends QCoreObjectPtr

	Field _connections:TMap = New TMap
	
	Rem
	bbdoc: 
	End Rem
	Function tr:String(sourceText:String, disambiguation:String = Null, n:Int = -1)
		Return bmx_qt_qobject_tr(sourceText, disambiguation, n)
	End Function
	
	Rem
	bbdoc: 
	End Rem
	Function tr_arg:String(sourceText:String, args:String[])
		Return bmx_qt_qobject_trarg(sourceText, args)
	End Function
	
	Rem
	bbdoc: 
	End Rem
	Method blockSignals:Int(block:Int)
		Return bmx_qt_qobject_blocksignals(qObjectPtr, block)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method signalsBlocked:Int()
		Return bmx_qt_qobject_signalsblocked(qObjectPtr)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Function connect:Int(sender:QObject, signal:String, receiver:QObject, slot:String)
		Return sender.doConnect(signal, receiver, slot)
	End Function
	
	Rem
	bbdoc: Sets the name of this object.
	about: By default, this property contains an empty string.
	End Rem
	Method setObjectName(name:String)
		bmx_qt_qobject_setobjectname(qObjectPtr, name)
	End Method
	
	Rem
	bbdoc: Makes the object a child of @parent.
	End Rem
	Method setParent(parent:QObject)
		bmx_qt_qobject_setparent(qObjectPtr, parent.qObjectPtr)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method startTimer:Int(interval:Int)
		Return bmx_qt_qobject_starttimer(qObjectPtr, interval)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method killTimer(id:Int)
		bmx_qt_qobject_killtimer(qObjectPtr, id)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method timerEvent(event:QTimerEvent)
	End Method
	
	Function _timerEvent(obj:QObject, event:Byte Ptr)
		obj.timerEvent(QTimerEvent._create(event))
	End Function
	
	' private
	Method doConnect:Int(signal:String, receiver:QObject, slot:String)
		Local list:TList = TList(_connections.ValueForKey(signal))
		If Not list Then
			list = New TList
			_connections.Insert(signal, list)
		End If
		
		list.AddLast(TSignalSlotConnection.Create(receiver, slot))
	End Method
	
	' private
	' invokes all the slots attached to the signal
	Method _InvokeSignals(signal:String, args:Object[])
		Local list:TList = TList(_connections.ValueForKey(signal))
		If list Then
			For Local conn:TSignalSlotConnection = EachIn list
				conn.invoke(args)
			Next
		End If
	End Method
	
	Method Free()
		_connections.Clear()
	End Method
	
	Function _Free(obj:QObject)
		obj.qObjectPtr = Null
		obj.Free()
	End Function

End Type

' a BlitzMax "slot" for a signal to call
Type TSignalSlotConnection

	Field receiver:QObject
	Field slot:String
	
	Field _method:TMethod

	Function Create:TSignalSlotConnection(receiver:QObject, slot:String)
		Local this:TSignalSlotConnection = New TSignalSlotConnection
		this.receiver = receiver
		this.slot = slot
		
		this._method = TTypeId.ForObject(receiver).FindMethod(slot)
		Return this
	End Function
	
	Method invoke(args:Object[])
		If _method Then
			If args And args.length > _method.ArgTypes().length Then
				args = args[.._method.ArgTypes().length]
			End If
			
			_method.invoke(receiver, args)
		Else
			DebugLog "Method '" + slot + "' does not exist."
		End If
	End Method
	
End Type



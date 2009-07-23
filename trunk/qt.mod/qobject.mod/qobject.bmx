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
Type QObject

	Field qObjectPtr:Byte Ptr
	
	Field _connections:TMap = New TMap
	
	
	Function tr:String(sourceText:String, disambiguation:String = Null, n:Int = -1)
		Return bmx_qt_qobject_tr(sourceText, disambiguation, n)
	End Function
	
	Function tr_arg:String(sourceText:String, args:String[])
		Return bmx_qt_qobject_trarg(sourceText, args)
	End Function
	
	Function connect:Int(sender:QObject, signal:String, receiver:QObject, slot:String)
		Return sender.doConnect(signal, receiver, slot)
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
		If args And args.length > _method.ArgTypes().length Then
			args = args[.._method.ArgTypes().length]
		End If
		
		_method.invoke(receiver, args)
	End Method
	
End Type


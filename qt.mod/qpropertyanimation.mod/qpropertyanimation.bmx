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

Module Qt.QPropertyAnimation

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QPropertyAnimation Extends QVariantAnimation

	Field parent:QObject
	Field fieldType:TTypeId
	Field writeMethod:TMethod
	Field readMethod:TMethod

	Method Create:QPropertyAnimation(parent:QObject, property:String)
	
		Local t:TTypeId = TTypeId.ForObject(parent)
		Local f:TField = t.FindField(property)
		
		If f Then
		
			If f.metadata("property") Then
			
				fieldType = f.TypeId()
			
				Local m:String = f.metadata("WRITE")
				
				If m Then
					Self.parent = parent
					writeMethod = TTypeId.ForObject(parent).FindMethod(m)
				End If
				
				m = f.metadata("READ")
				If m Then
					readMethod = TTypeId.ForObject(parent).FindMethod(m)
				End If
	
				qObjectPtr = bmx_qt_qpropertyanimation_create(Self, parent.qObjectPtr)
				Return Self
			End If
		End If
		
		Return Null
	End Method

	Method setDuration(value:Int)
		bmx_qt_qpropertyanimation_setduration(qObjectPtr, value)
	End Method

	Method duration:Int()
		Return bmx_qt_qpropertyanimation_duration(qObjectPtr)
	End Method

	Method setEasingCurve(curve:QEasingCurve)
	End Method
	
	Method easingCurve:QEasingCurve()
	End Method
	
	Method currentValue:QVariant()
'DebugLog "currentValue"
		Select fieldType
			Case DoubleTypeId
				Return New QDoubleVariant.Create(String(readMethod.Invoke(parent, Null)).toDouble())
		End Select
	End Method

	Function _currentValue:Byte Ptr(obj:QPropertyAnimation)
		Return obj.currentValue().qObjectPtr
	End Function

	Method updateCurrentValue(variant:QVariant)
'DebugLog "updateCurrentValue"
		writeMethod.invoke(parent, [variant.getValue()])
	End Method

	Function _updateCurrentValue(obj:QPropertyAnimation, variant:QVariant)
		obj.updateCurrentValue(variant)
	End Function
	
End Type

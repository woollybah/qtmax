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

Import "qurl.bmx"

Private
Global variant_factories:TVariantFactory
Public

Type QVariant

	Field qObjectPtr:Byte Ptr
	
	Field variantType:Int
	
	Method Delete()
		If qObjectPtr Then
			bmx_qt_variant_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method

	Function _CreateVariant:QVariant(variantType:Int, variant:Byte Ptr)

		' match the variant type
		Local factory:TVariantFactory = variant_factories'
		Local v:QVariant

		While factory
			v = factory.CreateVariant(variantType, variant)
			If v Exit
			factory = factory._succ
		Wend
		
		Return v
		
	End Function
	
	Method getValue:Object()
	End Method

End Type

Type QIntVariant Extends QVariant

	Method New()
		variantType = QMetaType_Int
	End Method

	Function _create:QIntVariant(variant:Byte Ptr)
		Local this:QIntVariant = New QIntVariant
		this.qObjectPtr = variant
		Return this
	End Function

	Function Create:QIntVariant(value:Int)
		Local this:QIntVariant = New QIntVariant
		this.qObjectPtr = bmx_qt_qintvariant_create(value)
		Return this
	End Function

	Method value:Int()
		Return bmx_qt_qintvariant_value(qObjectPtr)
	End Method

	Method getValue:Object()
		Return String(value())
	End Method

End Type

Type QDoubleVariant Extends QVariant

	Method New()
		variantType = QMetaType_Double
	End Method

	Function _create:QDoubleVariant(variant:Byte Ptr)
		Local this:QDoubleVariant = New QDoubleVariant
		this.qObjectPtr = variant
		Return this
	End Function

	Function Create:QDoubleVariant(value:Double)
		Local this:QDoubleVariant = New QDoubleVariant
		this.qObjectPtr = bmx_qt_qdoublevariant_create(value)
		Return this
	End Function

	Method value:Double()
		Return bmx_qt_qdoublevariant_value(qObjectPtr)
	End Method

	Method getValue:Object()
		Return String(value())
	End Method

End Type

Type QFloatVariant Extends QVariant

	Method New()
		variantType = QMetaType_Float
	End Method

	Function _create:QFloatVariant(variant:Byte Ptr)
		Local this:QFloatVariant = New QFloatVariant
		this.qObjectPtr = variant
		Return this
	End Function

	Function Create:QFloatVariant(value:Float)
		Local this:QFloatVariant = New QFloatVariant
		this.qObjectPtr = bmx_qt_qfloatvariant_create(value)
		Return this
	End Function

	Method value:Float()
		Return bmx_qt_qfloatvariant_value(qObjectPtr)
	End Method
	
	Method getValue:Object()
		Return String(value())
	End Method

End Type



Type TCoreVariantFactory Extends TVariantFactory

	Method CreateVariant:QVariant(variantType:Int, variant:Byte Ptr)
	
		Select variantType
			Case QMetaType_Int
				Return QIntVariant._create(variant)
			Case QMetaType_Double
				Return QDoubleVariant._create(variant)
			Case QMetaType_Float
				Return QFloatVariant._create(variant)
		End Select
		
		Return Null
	End Method

End Type

New TCoreVariantFactory


Type TVariantFactory
	Field _succ:TVariantFactory
	
	Method New()
		_succ=variant_factories
		variant_factories=Self
	End Method
	
	Method CreateVariant:QVariant(variantType:Int, variant:Byte Ptr) Abstract
	
End Type

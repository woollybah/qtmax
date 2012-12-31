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

Import "qurl.bmx"

Private
Global variant_factories:TVariantFactory
Public

Type QVariant

	Rem
	bbdoc: no type
	End Rem
	Const Type_Invalid:Int = 0
	
	Rem
	bbdoc: a QBitArray
	End Rem
	Const Type_BitArray:Int = 13
	
	Rem
	bbdoc: a QBitmap
	End Rem
	Const Type_Bitmap:Int = 73
	
	Rem
	bbdoc: a bool
	End Rem
	Const Type_Bool:Int = 1
	
	Rem
	bbdoc: a QBrush
	End Rem
	Const Type_Brush:Int = 66
	
	Rem
	bbdoc: a QByteArray
	End Rem
	Const Type_ByteArray:Int = 12
	
	Rem
	bbdoc: a QChar
	End Rem
	Const Type_Char:Int = 7
	
	Rem
	bbdoc: a QColor
	End Rem
	Const Type_Color:Int = 67
	
	Rem
	bbdoc: a QCursor
	End Rem
	Const Type_Cursor:Int = 74
	
	Rem
	bbdoc: a QDate
	End Rem
	Const Type_Date:Int = 14
	
	Rem
	bbdoc: a QDateTime
	End Rem
	Const Type_DateTime:Int = 16
	
	Rem
	bbdoc: a double
	End Rem
	Const Type_Double:Int = 6
	
	Rem
	bbdoc: a QEasingCurve
	End Rem
	Const Type_EasingCurve:Int = 29
	
	Rem
	bbdoc: a QFont
	End Rem
	Const Type_Font:Int = 64
	
	Rem
	bbdoc: a QVariantHash
	End Rem
	Const Type_Hash:Int = 28
	
	Rem
	bbdoc: a QIcon
	End Rem
	Const Type_Icon:Int = 69
	
	Rem
	bbdoc: a QImage
	End Rem
	Const Type_Image:Int = 70
	
	Rem
	bbdoc: an int
	End Rem
	Const Type_Int:Int = 2
	
	Rem
	bbdoc: a QKeySequence
	End Rem
	Const Type_KeySequence:Int = 76
	
	Rem
	bbdoc: a QLine
	End Rem
	Const Type_Line:Int = 23
	
	Rem
	bbdoc: a QLineF
	End Rem
	Const Type_LineF:Int = 24
	
	Rem
	bbdoc: a QVariantList
	End Rem
	Const Type_List:Int = 9
	
	Rem
	bbdoc: a QLocale
	End Rem
	Const Type_Locale:Int = 18
	
	Rem
	bbdoc: a qlonglong
	End Rem
	Const Type_LongLong:Int = 4
	
	Rem
	bbdoc: a QVariantMap
	End Rem
	Const Type_Map:Int = 8
	
	Rem
	bbdoc: a QMatrix(obsolete)
	End Rem
	Const Type_Matrix:Int = 80
	
	Rem
	bbdoc: a QTransform
	End Rem
	Const Type_Transform:Int = 81
	
	Rem
	bbdoc: a QMatrix4x4
	End Rem
	Const Type_Matrix4x4:Int = 82
	
	Rem
	bbdoc: a QPalette
	End Rem
	Const Type_Palette:Int = 68
	
	Rem
	bbdoc: a QPen
	End Rem
	Const Type_Pen:Int = 77
	
	Rem
	bbdoc: a QPixmap
	End Rem
	Const Type_Pixmap:Int = 65
	
	Rem
	bbdoc: a QPoint
	End Rem
	Const Type_Point:Int = 25
	
	Rem
	bbdoc: a QPointF
	End Rem
	Const Type_PointF:Int = 26
	
	Rem
	bbdoc: a QPolygon
	End Rem
	Const Type_Polygon:Int = 71
	
	Rem
	bbdoc: a QPointArray
	End Rem
	Const Type_PointArray:Int = Type_Polygon
	
	Rem
	bbdoc: a QQuaternion
	End Rem
	Const Type_Quaternion:Int = 86
	
	Rem
	bbdoc: a QRect
	End Rem
	Const Type_Rect:Int = 19
	
	Rem
	bbdoc: a QRectF
	End Rem
	Const Type_RectF:Int = 20
	
	Rem
	bbdoc: a QRegExp
	End Rem
	Const Type_RegExp:Int = 27
	
	Rem
	bbdoc: a QRegion
	End Rem
	Const Type_Region:Int = 72
	
	Rem
	bbdoc: a QSize
	End Rem
	Const Type_Size:Int = 21
	
	Rem
	bbdoc: a QSizeF
	End Rem
	Const Type_SizeF:Int = 22
	
	Rem
	bbdoc: a QSizePolicy
	End Rem
	Const Type_SizePolicy:Int = 75
	
	Rem
	bbdoc: a QString
	End Rem
	Const Type_String:Int = 10
	
	Rem
	bbdoc: a QStringList
	End Rem
	Const Type_StringList:Int = 11
	
	Rem
	bbdoc: a QTextFormat
	End Rem
	Const Type_TextFormat:Int = 79
	
	Rem
	bbdoc: a QTextLength
	End Rem
	Const Type_TextLength:Int = 78
	
	Rem
	bbdoc: a QTime
	End Rem
	Const Type_Time:Int = 15
	
	Rem
	bbdoc: a uint
	End Rem
	Const Type_UInt:Int = 3
	
	Rem
	bbdoc: a qulonglong
	End Rem
	Const Type_ULongLong:Int = 5
	
	Rem
	bbdoc: a QUrl
	End Rem
	Const Type_Url:Int = 17
	
	Rem
	bbdoc: a QVector2D
	End Rem
	Const Type_Vector2D:Int = 83
	
	Rem
	bbdoc: a QVector3D
	End Rem
	Const Type_Vector3D:Int = 84
	
	Rem
	bbdoc: a QVector4D
	End Rem
	Const Type_Vector4D:Int = 85
	
	Rem
	bbdoc: Base value for user-defined types.
	End Rem
	Const Type_UserType:Int = 127
	


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

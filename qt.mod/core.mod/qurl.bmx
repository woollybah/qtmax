SuperStrict

Import "common.bmx"


Type QUrl

	Field qObjectPtr:Byte Ptr

	Function CreateUrl:QUrl(url:String = "")
		Return New QUrl.Create(url)
	End Function

	Method Create:Qurl(url:String = "")
		qObjectPtr = bmx_qt_qurl_create(url)
		Return Self
	End Method


	Method Free()
		If qObjectPtr Then
			bmx_qt_qurl_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method

	Method Delete()
		Free()
	End Method
	
End Type



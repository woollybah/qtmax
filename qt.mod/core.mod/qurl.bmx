SuperStrict

Import "common.bmx"


Type QUrl

	Field urlPtr:Byte Ptr

	Function CreateUrl:QUrl(url:String = "")
		Return New QUrl.Create(url)
	End Function

	Method Create:Qurl(url:String = "")
		urlPtr = bmx_qt_qurl_create(url)
		Return Self
	End Method


	Method Free()
		If urlPtr Then
			bmx_qt_qurl_free(urlPtr)
			urlPtr = Null
		End If
	End Method

	Method Delete()
		Free()
	End Method
	
End Type



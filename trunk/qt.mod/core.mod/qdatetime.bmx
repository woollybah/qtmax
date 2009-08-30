SuperStrict

Import "qtime.bmx"
Import "qdate.bmx"
Import "common.bmx"


Type QDateTime

	Field qObjectPtr:Byte Ptr
	
	Function _create:QDateTime(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QDateTime = New QDateTime
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function


End Type

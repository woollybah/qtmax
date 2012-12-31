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

Import "common.bmx"

Type QDate

	Field qObjectPtr:Byte Ptr
	
	Function _create:QDate(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QDate = New QDate
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function CreateDate:QDate(y:Int, m:Int, d:Int)
		Return New QDate.Create(y, m, d)
	End Function
	
	Method Create:QDate(y:Int, m:Int, d:Int)
		qObjectPtr = bmx_qt_qdate_create(y, m, d)
		Return Self
	End Method

	Method addDays:QDate(ndays:Int)
		Return QDate._create(bmx_qt_qdate_adddays(qObjectPtr, ndays))
	End Method
	
	Method addMonths:QDate(nmonths:Int)
		Return QDate._create(bmx_qt_qdate_addmonths(qObjectPtr, nmonths))
	End Method
	
	Method addYears:QDate(nyears:Int)
		Return QDate._create(bmx_qt_qdate_addYears(qObjectPtr, nyears))
	End Method
	
	Method day:Int()
		Return bmx_qt_qdate_day(qObjectPtr)
	End Method
	
	Method dayOfWeek:Int()
		Return bmx_qt_qdate_dayofweek(qObjectPtr)
	End Method
	
	Method dayOfYear:Int()
		Return bmx_qt_qdate_dayofyear(qObjectPtr)
	End Method
	
	Method daysInMonth:Int()
		Return bmx_qt_qdate_daysinmonth(qObjectPtr)
	End Method
	
	Method daysInYear:Int()
		Return bmx_qt_qdate_daysinyear(qObjectPtr)
	End Method
	
	Method daysTo:Int(d:QDate)
		Return bmx_qt_qdate_daysto(qObjectPtr, d.qObjectPtr)
	End Method
	
	Method getDate(year:Int Var, _month:Int Var, day:Int Var)
		bmx_qt_qdate_getdate(qObjectPtr, Varptr year, Varptr _month, Varptr day)
	End Method
	
	Method isNull:Int()
		Return bmx_qt_qdate_isnull(qObjectPtr)
	End Method
	
	Method isValid:Int()
		Return bmx_qt_qdate_isvalid(qObjectPtr)
	End Method
	
	Method Month:Int()
		Return bmx_qt_qdate_month(qObjectPtr)
	End Method
	
	Method setDate:Int(year:Int, _month:Int, day:Int)
		Return bmx_qt_qdate_setdate(qObjectPtr, year, _month, day)
	End Method
	
	Method toJulianDay:Int()
		Return bmx_qt_qdate_tojulianday(qObjectPtr)
	End Method
	
	Method toFormatedString:String(format:String)
		Return bmx_qt_qdate_toformatedstring(qObjectPtr, format)
	End Method
	
	Method toString:String()
		Return bmx_qt_qdate_tostring(qObjectPtr)
	End Method
	
	Method weekNumber:Int(yearNumber:Int Var)
		Return bmx_qt_qdate_weeknumber(qObjectPtr, Varptr yearNumber)
	End Method
	
	Method year:Int()
		Return bmx_qt_qdate_year(qObjectPtr)
	End Method
	

	Method Free()
		If qObjectPtr Then
			bmx_qt_qdate_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method
	
End Type

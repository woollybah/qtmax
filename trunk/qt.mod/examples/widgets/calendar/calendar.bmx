SuperStrict

Framework Qt.QApplication
Import Qt.QGroupBox
Import Qt.QComboBox
Import Qt.QLabel
Import Qt.QGridLayout
Import Qt.QCalendarWidget
Import Qt.QCheckBox
Import Qt.QDateEdit
Import Qt.QHBoxLayout

Local app:QApplication = New QApplication.Create()

Local window:TWindow = New TWindow.Create()
window.show()

app.exec()

End

Type TWindow Extends QWidget

	Field previewGroupBox:QGroupBox
	Field previewLayout:QGridLayout
	Field calendar:QCalendarWidget
	
	Field generalOptionsGroupBox:QGroupBox
	Field localeLabel:QLabel
	Field firstDayLabel:QLabel
	Field selectionModeLabel:QLabel
	Field horizontalHeaderLabel:QLabel
	Field verticalHeaderLabel:QLabel
	Field localeCombo:QComboBox
	Field firstDayCombo:QComboBox
	Field selectionModeCombo:QComboBox
	Field gridCheckBox:QCheckBox
	Field navigationCheckBox:QCheckBox
	Field horizontalHeaderCombo:QComboBox
	Field verticalHeaderCombo:QComboBox
	
	Field datesGroupBox:QGroupBox
	Field currentDateLabel:QLabel
	Field minimumDateLabel:QLabel
	Field maximumDateLabel:QLabel
	Field currentDateEdit:QDateEdit
	Field minimumDateEdit:QDateEdit
	Field maximumDateEdit:QDateEdit
	
	Field textFormatsGroupBox:QGroupBox
	Field weekdayColorLabel:QLabel
	Field weekendColorLabel:QLabel
	Field headerTextFormatLabel:QLabel
	Field weekdayColorCombo:QComboBox
	Field weekendColorCombo:QComboBox
	Field headerTextFormatCombo:QComboBox
	
	Field firstFridayCheckBox:QCheckBox
	Field mayFirstCheckBox:QCheckBox
	
	Method Create:TWindow()
		Return TWindow(Super._Create())
	End Method
	
	Method OnInit()
		createPreviewGroupBox()
		createGeneralOptionsGroupBox()
		createDatesGroupBox()
		createTextFormatsGroupBox()
		
		Local layout:QGridLayout = New QGridLayout.Create()
		layout.addWidget(previewGroupBox, 0, 0)
		layout.addWidget(generalOptionsGroupBox, 0, 1)
		layout.addWidget(datesGroupBox, 1, 0)
		layout.addWidget(textFormatsGroupBox, 1, 1)
		layout.setSizeConstraint(QLayout.SetFixedSize)
		setLayout(layout)
		
		Local w:Int, h:Int
		calendar.sizeHint(w, h)
		previewLayout.setRowMinimumHeight(0, h)
		previewLayout.setColumnMinimumWidth(0, w)
		
		setWindowTitle(tr("Calendar Widget"))
	End Method

	Method localeChanged(index:Int)
		calendar.setLocale(QLocale(localeCombo.itemData(index)))
	End Method
	
	Method firstDayChanged(index:Int)
		calendar.setFirstDayOfWeek(String(firstDayCombo.itemData(index)).toInt())
	End Method
	
	Method selectionModeChanged(index:Int)
		calendar.setSelectionMode(String(selectionModeCombo.itemData(index)).toInt())
	End Method
	
	Method horizontalHeaderChanged(index:Int)
		calendar.setHorizontalHeaderFormat(String(horizontalHeaderCombo.itemData(index)).toInt())
	End Method
	
	Method verticalHeaderChanged(index:Int)
		calendar.setVerticalHeaderFormat(String(verticalHeaderCombo.itemData(index)).toInt())
	End Method
	
	Method selectedDateChanged()
		currentDateEdit.setDate(calendar.selectedDate())
	End Method
	
	Method minimumDateChanged(date:QDate)
		calendar.setMinimumDate(date)
		maximumDateEdit.setDate(calendar.maximumDate())
	End Method
	
	Method maximumDateChanged(date:QDate)
		calendar.setMaximumDate(date)
		minimumDateEdit.setDate(calendar.minimumDate())
	End Method
	
	Method weekdayFormatChanged()
		Local format:QTextCharFormat = New QTextCharFormat.Create()
		
		format.setForeground(New QBrush.CreateWithColor(QColor(weekdayColorCombo.itemData(weekdayColorCombo.currentIndex()))))
		calendar.setWeekdayTextFormat(Qt_Monday, format)
		calendar.setWeekdayTextFormat(Qt_Tuesday, format)
		calendar.setWeekdayTextFormat(Qt_Wednesday, format)
		calendar.setWeekdayTextFormat(Qt_Thursday, format)
		calendar.setWeekdayTextFormat(Qt_Friday, format)
	End Method
	
	Method weekendFormatChanged()
		Local format:QTextCharFormat = New QTextCharFormat.Create()
		
		format.setForeground(New QBrush.CreateWithColor(QColor(weekendColorCombo.itemData(weekendColorCombo.currentIndex()))))
		calendar.setWeekdayTextFormat(Qt_Saturday, format)
		calendar.setWeekdayTextFormat(Qt_Sunday, format)
	End Method
	
	Method reformatHeaders()
		Local text:String = headerTextFormatCombo.currentText()
		Local format:QTextCharFormat = New QTextCharFormat.Create()
		
		If text = tr("Bold") Then
			format.setFontWeight(QFont.Weight_Bold)
		Else If text = tr("Italic") Then
			format.setFontItalic(True)
		Else If text = tr("Green") Then
			format.setForeground(New QBrush.CreateWithGlobalColor(Qt_green))
		End If
		calendar.setHeaderTextFormat(format)
	End Method
	
	Method reformatCalendarPage()
		Local mayFirstFormat:QTextCharFormat = New QTextCharFormat.Create()
		If mayFirstCheckBox.isChecked() Then
			mayFirstFormat.setForeground(New QBrush.CreateWithGlobalColor(Qt_red))
		End If
		
		Local firstFridayFormat:QTextCharFormat = New QTextCharFormat.Create()
		If firstFridayCheckBox.isChecked() Then
			firstFridayFormat.setForeground(New QBrush.CreateWithGlobalColor(Qt_blue))
		End If
		
		Local date:QDate = New QDate.Create(calendar.yearShown(), calendar.monthShown(), 1)

		calendar.setDateTextFormat(New QDate.Create(date.year(), 5, 1), mayFirstFormat)
		
		date.setDate(date.year(), date.Month(), 1)
		While date.dayOfWeek() <> Qt_Friday
			date = date.addDays(1)
		Wend
		calendar.setDateTextFormat(date, firstFridayFormat)
	End Method
		
	Method createPreviewGroupBox()
		previewGroupBox = New QGroupBox.Create(tr("Preview"))
		
		calendar = New QCalendarWidget.Create()
		calendar.setMinimumDate(New QDate.Create(1900, 1, 1))
		calendar.setMaximumDate(New QDate.Create(3000, 1, 1))
		calendar.setGridVisible(True)
		
		connect(calendar, "currentPageChanged", Self, "reformatCalendarPage")
		
		previewLayout = New QGridLayout.Create()
		previewLayout.addWidget(calendar, 0, 0, Qt_AlignCenter)
		previewGroupBox.setLayout(previewLayout)
	End Method
	
	Method createGeneralOptionsGroupBox()
		generalOptionsGroupBox = New QGroupBox.Create(tr("General Options"))

		localeCombo = New QComboBox.Create()
		Local curLocaleIndex:Int = -1
		Local index:Int = 0
		For Local lang:Int = QLocale.Lang_C To QLocale.LastLanguage
			Local countries:Int[] = QLocale.countriesForLanguage(lang)
			For Local i:Int = 0 Until countries.length
				Local country:Int = countries[i]
				Local label:String = QLocale.languageToString(lang)
				label :+ "/"
				label :+ QLocale.countryToString(country)
				Local locale:QLocale = New QLocale.Create(lang, country)
				If Self.locale().language() = lang And Self.locale().country() = country Then
					curLocaleIndex = index
				End If
				localeCombo.addItem(label, locale)
				index:+ 1
			Next
		Next
		If curLocaleIndex <> -1 Then
			localeCombo.setCurrentIndex(curLocaleIndex)
		End If
		localeLabel = New QLabel.Create(tr("&Locale"))
		localeLabel.setBuddy(localeCombo)

		firstDayCombo = New QComboBox.Create()
		firstDayCombo.addItem(tr("Sunday"), String(Qt_Sunday))
		firstDayCombo.addItem(tr("Monday"), String(Qt_Monday))
		firstDayCombo.addItem(tr("Tuesday"), String(Qt_Tuesday))
		firstDayCombo.addItem(tr("Wednesday"), String(Qt_Wednesday))
		firstDayCombo.addItem(tr("Thursday"), String(Qt_Thursday))
		firstDayCombo.addItem(tr("Friday"), String(Qt_Friday))
		firstDayCombo.addItem(tr("Saturday"), String(Qt_Saturday))
		
		firstDayLabel = New QLabel.Create(tr("Wee&k starts on:"))
		firstDayLabel.setBuddy(firstDayCombo)
		
		selectionModeCombo = New QComboBox.Create()
		selectionModeCombo.addItem(tr("Single selection"), String(QCalendarWidget.SingleSelection))
		selectionModeCombo.addItem(tr("None"), String(QCalendarWidget.NoSelection))
		
		selectionModeLabel = New QLabel.Create(tr("&Selection mode:"))
		selectionModeLabel.setBuddy(selectionModeCombo)
		
		gridCheckBox = New QCheckBox.Create(tr("&Grid"))
		gridCheckBox.setChecked(calendar.isGridVisible())
		
		navigationCheckBox = New QCheckBox.Create(tr("&Navigation bar"))
		navigationCheckBox.setChecked(True)
		
		horizontalHeaderCombo = New QComboBox.Create()
		horizontalHeaderCombo.addItem(tr("Single letter day names"), String(QCalendarWidget.SingleLetterDayNames))
		horizontalHeaderCombo.addItem(tr("Short day names"), String(QCalendarWidget.ShortDayNames))
		horizontalHeaderCombo.addItem(tr("None"), String(QCalendarWidget.NoHorizontalHeader))
		horizontalHeaderCombo.setCurrentIndex(1)
		
		horizontalHeaderLabel = New QLabel.Create(tr("&Horizontal header:"))
		horizontalHeaderLabel.setBuddy(horizontalHeaderCombo)
		
		verticalHeaderCombo = New QComboBox.Create()
		verticalHeaderCombo.addItem(tr("ISO week numbers"), String(QCalendarWidget.ISOWeekNumbers))
		verticalHeaderCombo.addItem(tr("None"), String(QCalendarWidget.NoVerticalHeader))
		
		verticalHeaderLabel = New QLabel.Create(tr("&Vertical header:"))
		verticalHeaderLabel.setBuddy(verticalHeaderCombo)
		
		connect(localeCombo, "currentIndexChanged", Self, "localeChanged")
		connect(firstDayCombo, "currentIndexChanged", Self, "firstDayChanged")
		connect(selectionModeCombo, "currentIndexChanged", Self, "selectionModeChanged")
		connect(gridCheckBox, "toggled", calendar, "setGridVisible")
		connect(navigationCheckBox, "toggled", calendar, "setNavigationBarVisible")
		connect(horizontalHeaderCombo, "currentIndexChanged", Self, "horizontalHeaderChanged")
		connect(verticalHeaderCombo, "currentIndexChanged", Self, "verticalHeaderChanged")
		
		Local checkBoxLayout:QHBoxLayout = New QHBoxLayout.Create()
		checkBoxLayout.addWidget(gridCheckBox)
		checkBoxLayout.addStretch()
		checkBoxLayout.addWidget(navigationCheckBox)
		
		Local outerLayout:QGridLayout = New QGridLayout.Create()
		outerLayout.addWidget(localeLabel, 0, 0)
		outerLayout.addWidget(localeCombo, 0, 1)
		outerLayout.addWidget(firstDayLabel, 1, 0)
		outerLayout.addWidget(firstDayCombo, 1, 1)
		outerLayout.addWidget(selectionModeLabel, 2, 0)
		outerLayout.addWidget(selectionModeCombo, 2, 1)
		outerLayout.addLayoutSpan(checkBoxLayout, 3, 0, 1, 2)
		outerLayout.addWidget(horizontalHeaderLabel, 4, 0)
		outerLayout.addWidget(horizontalHeaderCombo, 4, 1)
		outerLayout.addWidget(verticalHeaderLabel, 5, 0)
		outerLayout.addWidget(verticalHeaderCombo, 5, 1)
		generalOptionsGroupBox.setLayout(outerLayout)
		
		firstDayChanged(firstDayCombo.currentIndex())
		selectionModeChanged(selectionModeCombo.currentIndex())
		horizontalHeaderChanged(horizontalHeaderCombo.currentIndex())
		verticalHeaderChanged(verticalHeaderCombo.currentIndex())
	End Method
	
	Method createDatesGroupBox()
		datesGroupBox = New QGroupBox.Create(tr("Dates"))
		
		minimumDateEdit = New QDateEdit.Create()
		minimumDateEdit.setDisplayFormat("MMM d yyyy")
		minimumDateEdit.setDateRange(calendar.minimumDate(), calendar.maximumDate())
		minimumDateEdit.setDate(calendar.minimumDate())
		
		minimumDateLabel = New QLabel.Create(tr("&Minimum Date:"))
		minimumDateLabel.setBuddy(minimumDateEdit)
		
		currentDateEdit = New QDateEdit.Create()
		currentDateEdit.setDisplayFormat("MMM d yyyy")
		currentDateEdit.setDate(calendar.selectedDate())
		currentDateEdit.setDateRange(calendar.minimumDate(), calendar.maximumDate())
		
		currentDateLabel = New QLabel.Create(tr("&Current Date:"))
		currentDateLabel.setBuddy(currentDateEdit)
		
		maximumDateEdit = New QDateEdit.Create()
		maximumDateEdit.setDisplayFormat("MMM d yyyy")
		maximumDateEdit.setDateRange(calendar.minimumDate(), calendar.maximumDate())
		maximumDateEdit.setDate(calendar.maximumDate())
		
		maximumDateLabel = New QLabel.Create(tr("Ma&ximum Date:"))
		maximumDateLabel.setBuddy(maximumDateEdit)
		
		connect(currentDateEdit, "dateChanged", calendar, "setSelectedDate")
		connect(calendar, "selectionChanged", Self, "selectedDateChanged")
		connect(minimumDateEdit, "dateChanged", Self, "minimumDateChanged")
		connect(maximumDateEdit, "dateChanged", Self, "maximumDateChanged")
		
		Local dateBoxLayout:QGridLayout = New QGridLayout.Create()
		dateBoxLayout.addWidget(currentDateLabel, 1, 0)
		dateBoxLayout.addWidget(currentDateEdit, 1, 1)
		dateBoxLayout.addWidget(minimumDateLabel, 0, 0)
		dateBoxLayout.addWidget(minimumDateEdit, 0, 1)
		dateBoxLayout.addWidget(maximumDateLabel, 2, 0)
		dateBoxLayout.addWidget(maximumDateEdit, 2, 1)
		dateBoxLayout.setRowStretch(3, 1)
		
		datesGroupBox.setLayout(dateBoxLayout)
	End Method
	
	Method createTextFormatsGroupBox()
		textFormatsGroupBox = New QGroupBox.Create(tr("Text Formats"))

		weekdayColorCombo = createColorComboBox()
		weekdayColorCombo.setCurrentIndex(weekdayColorCombo.findText(tr("Black")))
		
		weekdayColorLabel = New QLabel.Create(tr("&Weekday color:"))
		weekdayColorLabel.setBuddy(weekdayColorCombo)
		
		weekendColorCombo = createColorComboBox()
		weekendColorCombo.setCurrentIndex(weekendColorCombo.findText(tr("Red")))
		
		weekendColorLabel = New QLabel.Create(tr("Week&end color:"))
		weekendColorLabel.setBuddy(weekendColorCombo)
		
		headerTextFormatCombo = New QComboBox.Create()
		headerTextFormatCombo.addItem(tr("Bold"))
		headerTextFormatCombo.addItem(tr("Italic"))
		headerTextFormatCombo.addItem(tr("Plain"))
		
		headerTextFormatLabel = New QLabel.Create(tr("&Header text:"))
		headerTextFormatLabel.setBuddy(headerTextFormatCombo)
		
		firstFridayCheckBox = New QCheckBox.Create(tr("&First Friday in blue"))
		
		mayFirstCheckBox = New QCheckBox.Create(tr("May &1 in red"))
		
		connect(weekdayColorCombo, "currentIndexChanged", Self, "weekdayFormatChanged")
		connect(weekendColorCombo, "currentIndexChanged", Self, "weekendFormatChanged")
		connect(headerTextFormatCombo, "currentIndexChanged", Self, "reformatHeaders")
		connect(firstFridayCheckBox, "toggled", Self, "reformatCalendarPage")
		connect(mayFirstCheckBox, "toggled", Self, "reformatCalendarPage")
		
		Local checkBoxLayout:QHBoxLayout = New QHBoxLayout.Create()
		checkBoxLayout.addWidget(firstFridayCheckBox)
		checkBoxLayout.addStretch()
		checkBoxLayout.addWidget(mayFirstCheckBox)
		
		Local outerLayout:QGridLayout = New QGridLayout.Create()
		outerLayout.addWidget(weekdayColorLabel, 0, 0)
		outerLayout.addWidget(weekdayColorCombo, 0, 1)
		outerLayout.addWidget(weekendColorLabel, 1, 0)
		outerLayout.addWidget(weekendColorCombo, 1, 1)
		outerLayout.addWidget(headerTextFormatLabel, 2, 0)
		outerLayout.addWidget(headerTextFormatCombo, 2, 1)
		outerLayout.addLayoutSpan(checkBoxLayout, 3, 0, 1, 2)
		textFormatsGroupBox.setLayout(outerLayout)
		
		weekdayFormatChanged()
		weekendFormatChanged()
		reformatHeaders()
		reformatCalendarPage()
	End Method
	
	Method createColorComboBox:QComboBox()
		Local comboBox:QComboBox = New QComboBox.Create()
		comboBox.addItem(tr("Red"), New QColor.CreateWithGlobalColor(Qt_red))
		comboBox.addItem(tr("Blue"), New QColor.CreateWithGlobalColor(Qt_blue))
		comboBox.addItem(tr("Black"), New QColor.CreateWithGlobalColor(Qt_black))
		comboBox.addItem(tr("Magenta"), New QColor.CreateWithGlobalColor(Qt_magenta))
		Return comboBox
	End Method
	
End Type

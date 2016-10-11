SuperStrict

Framework Qt.QApplication
Import Qt.QTextEdit
Import Qt.QPushButton
Import Qt.QVBoxLayout

Local app:QApplication = New QApplication.Create()

Local textEdit:QTextEdit = New QTextEdit.Create()
Local quitButton:QPushButton = New QPushButton.Create("&Quit")

QObject.connect(quitButton, "clicked", qApp, "quit")

Local layout:QVBoxLayout = New QVBoxLayout.Create()
layout.addWidget(textEdit)
layout.addWidget(quitButton)

Local window:QWidget = QWidget.CreateWidget()
window.setLayout(layout)

window.show()

app.exec()

End


SuperStrict

Framework Qt.QApplication
Import Qt.QDirModel
Import Qt.QTreeView


Local app:QApplication = New QApplication.Create()


Local model:QDirModel = New QDirModel.Create()
Local tree:QTreeView = New QTreeView.Create()

tree.setModel(model)

' Demonstrating look and feel features
tree.setAnimated(False)
tree.setIndentation(20)
tree.setSortingEnabled(True)

tree.setWindowTitle(QObject.tr("Dir View"))
tree.resize(640, 480)
tree.show()

app.exec()

End

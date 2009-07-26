for i in `ls *.dylib`
do
	echo fixing : $i
	install_name_tool -id @executable_path/../plugins/imageformats/$i $i 2>/dev/null

	install_name_tool -change libQtGui.4.dylib @executable_path/libQtGui.4.dylib $i 2>/dev/null
	install_name_tool -change libQtCore.4.dylib @executable_path/libQtCore.4.dylib $i 2>/dev/null

done

for i in `ls *.dylib`
do
	echo fixing : $i
	install_name_tool -id @executable_path/$i $i 2>/dev/null
	for n in `ls *.dylib`
	do
		install_name_tool -change $n @executable_path/$n $i 2>/dev/null
	done
done

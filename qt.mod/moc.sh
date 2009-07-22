
# path to moc
MOC=/Volumes/MiscData/programming/qt-mac-opensource-src-4.5.2/bin/moc 

for i in `find . -name "*.mod"`
do
	cd $i
	$MOC glue.h > moc4glue.cpp
	cd ..
done



# path to moc
MOC=/Volumes/MiscData/programming/qt-everywhere-opensource-src-4.7.1/bin/moc

for i in `find . -name "*.mod"`
do
	cd $i
	$MOC glue.h > moc4glue.cpp
	cd ..
done


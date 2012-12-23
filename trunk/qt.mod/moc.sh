
# path to moc
MOC=/Users/brucey/Documents/programming/c/qt-everywhere-opensource-src-4.8.4/bin/moc

for i in `find . -name "*.mod"`
do
	cd $i
	$MOC glue.h > moc4glue.cpp
	cd ..
done


#
# Remove all files inside the include directory... ignoring svn stuff
#
SOURCE=/Users/brucey/Documents/programming/c/qt-everywhere-opensource-src-4.8.4

for i in `find include -type f | awk '{ if (!index($0, "svn")) print $0 }'`
do
	rm $i
done

#
# Copy source files to loca area.
#

ls $SOURCE/include

cp -Rn $SOURCE/include/* include


#
# Remove all files inside the include directory... ignoring svn stuff
#
SOURCE=/Volumes/MiscData/programming/qt-everywhere-opensource-src-4.7.1

for i in `find include -type f | awk '{ if (!index($0, "svn")) print $0 }'`
do
	rm $i
done

#
# Copy source files to loca area.
#

cp -Rn $SOURCE/include/* include


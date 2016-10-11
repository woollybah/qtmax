set MOC=C:\Qt\4.5.2\bin\moc.exe

for /f %%a IN ('dir /b *.mod') do %MOC% -o%%a\moc4glue.cpp %%a\glue.h

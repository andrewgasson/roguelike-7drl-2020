@echo off

call project.bat

del %binary_directory%\windows_x32\%exe_name%.exe

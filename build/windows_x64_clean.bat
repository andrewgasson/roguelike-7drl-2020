@echo off

call project.bat

del %binary_directory%\windows_x64\%exe_name%.exe

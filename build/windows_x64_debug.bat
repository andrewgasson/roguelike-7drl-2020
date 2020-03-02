@echo off

call project.bat

set compiler=x86_64-w64-mingw32-gcc
set compiler_flags=-Wall

set exe_output_path=%binary_directory%\windows_x64\%exe_name%

%compiler% ^
	%compiler_flags% ^
	-o %exe_output_path% ^
	-I%external_directory% ^
	-I%source_directory% ^
	%source_files% ^
	-L. ^
	-l:%binary_directory%\windows_x64\BearLibTerminal.dll

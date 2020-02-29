@echo off

set exe_name=roguelike

set compiler=gcc
set compiler_flags=-Wall

set root_directory=..
set binary_directory=%root_directory%\binary
set extern_directory=%root_directory%\extern
set source_directory=%root_directory%\source

set exe_output_path=%binary_directory%\%exe_name%

set source_files=^
	%source_directory%\*.c

%compiler% ^
%compiler_flags% ^
-o %exe_output_path% ^
%source_files%

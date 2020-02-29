@echo off

set exe_name=roguelike

set compiler=gcc
set compiler_flags=-Wall

set root_directory=..
set binary_directory=%root_directory%\binary
set external_directory=%root_directory%\external
set source_directory=%root_directory%\source

set exe_output_path=%binary_directory%\%exe_name%

set source_files=^
	%source_directory%\*.c ^
	%source_directory%\config\*.c ^
	%source_directory%\engine\*.c ^
	%source_directory%\game\*.c ^
	%source_directory%\game\game_state\*.c ^
	%source_directory%\game\player_action\*.c ^
	%source_directory%\input\*.c ^
	%source_directory%\render\*.c ^
	%source_directory%\render\render_layer\*.c ^
	%source_directory%\world\*.c

%compiler% ^
	%compiler_flags% ^
	-o %exe_output_path% ^
	-I%external_directory% ^
	-I%source_directory% ^
	%source_files% ^
	-L. ^
	-l:%binary_directory%\BearLibTerminal.dll

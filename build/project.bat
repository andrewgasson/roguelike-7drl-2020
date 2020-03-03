@echo off

set exe_name=goldband_project

set root_directory=..
set binary_directory=%root_directory%\binary
set external_directory=%root_directory%\external
set source_directory=%root_directory%\source

set source_files=^
	%source_directory%\*.c ^
	%source_directory%\config\*.c ^
	%source_directory%\engine\*.c ^
	%source_directory%\game\*.c ^
	%source_directory%\game\game_state\*.c ^
	%source_directory%\game\map_draw\*.c ^
	%source_directory%\game\player_action\*.c ^
	%source_directory%\gui\*.c ^
	%source_directory%\input\*.c ^
	%source_directory%\render\*.c ^
	%source_directory%\render\color_tool\*.c ^
	%source_directory%\render\render_game\*.c ^
	%source_directory%\render\render_gui\*.c ^
	%source_directory%\world\*.c

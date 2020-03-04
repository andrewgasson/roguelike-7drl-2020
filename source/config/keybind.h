#ifndef KEYBIND_H
#define KEYBIND_H

struct keybind {
	int key;
	int key_alternative;
	int hold_alt;
	int hold_control;
	int hold_shift;
};

#endif

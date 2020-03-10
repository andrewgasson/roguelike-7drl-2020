#include "utility/stdio_ext.h"

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fopen_mkdir(const char *directory, const char *filename, const char *mode)
{
	char *filepath;
	FILE *file;
	struct stat s = { 0 };

	filepath = malloc((strlen(directory) + 1 + strlen(filename)) * sizeof(*filepath));
	strcpy(filepath, directory);
	strcat(filepath, "\\");
	strcat(filepath, filename);

	printf("call: fopen_mkdir(%s, %s, %s);\n", directory, filename, mode);

	/* NOTE: Windows only. Linux and MacOS mkdir() requires additional 
	 * parameter for permissions. */
	if (stat(directory, &s) == -1) {
		if (mkdir(directory) == -1) {
			printf("call: mkdir(%s): error was fatal, returning NULL.\n", directory);
			free(filepath);
			return NULL;
		}
	}

	file = fopen(filepath, mode);

	if (file)
		printf("call: fopen(%s): file created.", filepath);
	else
		printf("call: fopen(%s): file failed to create.", filepath);

	free(filepath);

	return file;
}

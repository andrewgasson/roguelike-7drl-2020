#ifndef STDIO_EXT_H
#define STDIO_EXT_H

#include <stdio.h>

/* Creates a directory for the filename if the directory doesn't exist. Like 
 * fopen(), returns NULL on an error.
 */
FILE *fopen_mkdir(const char *directory, const char *filename, const char *mode);

#endif

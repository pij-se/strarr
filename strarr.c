/*
 * <https://www.github.com/pij-se/strarr/strarr.c>
 *
 * String array; functions for storing strings in arrays.
 * 
 * Copyright (c) 2022 Johan Palm <johan@pij.se>
 * All rights reserved.
 * Published under the MIT License.
 */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "strarr.h"

char **strarr_alloc(char count, ...)
{
	va_list list;
	char **array;
	char *string;
	size_t length;

	if (count <= 0)
		return NULL;
	if (!(array = malloc(sizeof(*array) * (count + 1))))
		return NULL;
	if (!(array[0] = malloc(sizeof(**array))))
		goto cleanup;
	*array[0] = 0;
	va_start(list, count);
	while (count--) {
		if (!(string = va_arg(list, char *)))
			goto cleanup;
		length = strlen(string) + 1;
		if (!(array[*array[0] + 1] = malloc(sizeof(**array) * length)))
			goto cleanup;
		strcpy(array[++(*array[0])], string);
	}
	va_end(list);
	return array;
cleanup:
	strarr_free(array);
	return NULL;
}

char strarr_length(char **array)
{
	if (!array)
		return 0;
	return array[0][0];
}

char *strarr_get(char **array, char index)
{
	if (!array)
		return NULL;
	if (index < 0)
		return NULL;
	if (*array[0] <= index)
		return NULL;
	return array[index + 1];
}

void strarr_free(char **array)
{
	if (!array)
		return;
	if (array[0])
		while (*array[0])
			free(array[(*array[0])--]);
	free(array[0]);
	free(array);
	return;
}

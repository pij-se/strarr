/*
 * <https://www.github.com/pij-se/strarr/strarr.h>
 *
 * String array; functions for storing strings in arrays.
 * 
 * Copyright (c) 2022 Johan Palm <johan@pij.se>
 * All rights reserved.
 * Published under the MIT License.
 */

#ifndef STRARR_H
#define STRARR_H

char **strarr_alloc(char count, ...);

char strarr_length(char **array);

char *strarr_get(char **array, char index);

void strarr_free(char **array);

#endif

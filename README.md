# strarr
This small C library contains functions for storing multiple, typically associated, strings in arrays.

The first array element constitutes the string count, while the subsequent elements are pointers to strings.

Below is an example of how to use the functions.

```
int main(int argc, char *argv[])
{
	char **array;
	int i;

	array = strarr_alloc(4, "Hello", ", ", "world", ".\n");
	for (i = 0; i < strarr_length(array); i++)
		printf("%s", strarr_get(array, i));
	strarr_free(array);
	return 0;
}
```
#
Copyight (c) 2022 Johan Palm <johan@pij.se>  
All rights reserved.  
Published under the MIT License.

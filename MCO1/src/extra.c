#include "../header/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(const char *str)
{
    size_t len = strlen(str) + 1;
    char *dest = malloc(len);
    if (dest == NULL)
        return NULL;
    strcpy(dest, str);
    return dest;
}

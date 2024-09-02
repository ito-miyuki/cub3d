// add school header here!!!!!!
// Use it if you want to make function shorter when you need to skip spaces
#include "cub3D.h"

void    skip_spaces(char **str)
{
    while (**str == ' ' || **str == '\t')
        (*str)++;
}

char    *skip_spaces(char *str)
{
    while (*str == ' ' || *str == '\t')
        str++;
    return (str);
}
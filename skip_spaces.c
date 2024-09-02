// add school header here!!!!!!
// Use it if you want to use this fucntion to make function shorter? 
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
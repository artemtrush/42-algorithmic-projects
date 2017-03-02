#include "lem-in.h"

int g_ant;

static int      check_line_for_int(char *line, char c)
{
    int i;
    
    i = 0;
    while (line[i] && line[i] != c)
    {
        if (ft_isdigit(line[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int             reading(t_ways **ways)
{
    char    *line;
    int     all_rooms_are_declared;(void)ways;(void)all_rooms_are_declared;
    
    line = NULL;
    all_rooms_are_declared = 0;
    get_next_line(0, &line);
    if (!line || !check_line_for_int(line, '\0'))
    {
        free(line);
        return (0);
    }
    g_ant = ft_atoi(line);
    if (g_ant == 0)
    {
        ft_printf("%sAnthill is empty :(\n%s", YELLOW, RESET);
        free(line);
        exit(1);
    }
    return (0);
}
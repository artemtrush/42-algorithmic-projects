
#include "lem-in.h"

int     delete_room(t_room **root)
{
	t_room  *tmp;
    int     i;

	tmp = *root;
	while (*root != NULL)
	{
		tmp = (*root)->next;
	    if ((*root)->links)
	    {
	        i = -1;
	        while ((*root)->links[++i])
	        {
	           free((*root)->links[i]);
	           (*root)->links[i] = NULL;
	        }
	        free((*root)->links);
	        (*root)->links = NULL;
	    }
		free(*root);
		*root = tmp;
	}
	return (0);
}

int     create_room(t_room **root, char *name)
{
	t_room *tmp;

	tmp = *root;
	if (!tmp)
	{
		if (!(tmp = (t_room*)malloc(sizeof(t_room))))
			return (0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_room*)malloc(sizeof(t_room))))
			return (0);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp->links = NULL;
	tmp->start_or_end = 0;
	tmp->room = ft_strdup(name);
	if (!(tmp->room))
	    return (0);
	if (!(*root))
		*root = tmp;
	return (1);
}

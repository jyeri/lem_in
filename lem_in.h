#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_nest
{
	int	ants;
	int roomcount;
	t_rooms *rooms;
	t_links *links;
}	t_nest;

typedef struct s_rooms
{
	int	ants;
	char *name;
	int id;
	int x;
	int y;
	int startid;
	int endid;
	t_links *next;
	t_links *last;
}	t_rooms;

typedef struct s_links
{
	int from;
	int to;
}	t_links;

#endif
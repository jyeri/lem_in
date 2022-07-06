#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"


typedef struct s_room
{
	int		edgecount;
	int		name;
	int		*edges;
}	t_room;


typedef struct s_nest
{
	int	ants;
	int roomcount;
	int startid;
	int endid;
}	t_nest;


#endif

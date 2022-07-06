#ifndef LEM_IN_H
# define LEM_IN_H

# include "core.h"
# include <unistd.h>

enum e_line_type
{
	ROOM,
	ROOM_SRC,
	ROOM_SINK,
	LINK
};

typedef struct s_coordinates
{
	int			x;
	int			y;
}				t_coordinates;

typedef struct s_node_attr
{
	char			*name;
	int				value;
	t_coordinates	coordinates;
	t_graph_node	*org;
}					t_node_attr;

typedef struct s_edge_attr
{
	t_ssize			flow;
	t_ssize			capacity;
	t_graph_edge	*reverse_edge;
}					t_edge_attr;

typedef struct s_graph_attr
{
	t_graph_node	*source;
	t_graph_node	*sink;
}					t_graph_attr;

typedef struct s_flag
{
	char	*name_long;
	char	*name_short;
	t_bool	argument_required;
}			t_flag;

typedef struct s_flags
{
	t_bool	usage;
	t_bool	verbose;
	t_bool	read_from_file;
	char	*file;
}			t_flags;

typedef struct s_lem
{
	t_graph		graph;
	const char	*s_key;
	const char	*t_key;
	t_size		ant_count;
}				t_lem;

typedef t_array	t_paths;
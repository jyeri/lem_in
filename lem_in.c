#include "lem_in.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void init_rooms(t_room *rooms)
{
	rooms = malloc(sizeof (t_room) * 1);
	ft_bzero(rooms, sizeof(rooms));
}


int validate_input(char *str, t_nest *nest, t_room *rooms)
{
	while (1)
	{
		
	}
}

int read_input(char *buff, int buff_size, int ac, char **av, t_nest *nest, t_room *rooms)
{
	int fd;
	int ret;

	fd = 0;
	if (ac >= 2)
	{
		fd = open(av[1], fd);
		ret = read (fd, buff, buff_size);
	}
	else
	{
		ret = read (fd, buff, buff_size);
	}
	buff[ret] = '\0';
	if (!buff || !validate_input(buff, nest, rooms))
		exit(-1);
	return 0;
}

int main(int ac, char **av)
{
	t_nest nest;
	t_room *rooms;
	init_rooms(&rooms);
	int buff_size = 10000;
	char buff[buff_size];

	read_input(buff, buff_size, ac, av, &nest, &rooms);
	printf("buff: %s\n", buff);
	return 0;
}
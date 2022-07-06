#include "lem_in.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void init_nest(t_nest *nest)
{
	nest = malloc(sizeof (t_nest) * 1);
	nest->ants = 0;
	nest->roomcount = 0;
	nest->rooms = NULL;
	nest->links = NULL;
}

int	validate_ants(char *str)
{
	int i;
	int res;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			exit(-1);
	}
	res = ft_atoi(str);
	return (res);
}

int validate_rooms(char *str, t_nest *nest)
{
	if (str[0] == 'L' || str[0] == '#')
		exit(-1);
	ft_strcpy(nest->rooms->name, str);
	nest->rooms->id = nest->rooms->roomcount + 1;
	return (0);
}

int validate_links2(char *r1, char *r2, t_nest *nest)
{
	
}

int validate_links(char *str, t_nest *nest)
{
	char *r1;
	char *r2;

	int i;
	int j;

	j = 0;
	i = 0;
	while(str[i] != '\0')
	{
		while(str[i] != '-')
			r1[j] = str[i];
		j = 0;
		i++;
		while (str[i] != '\0')
		{
			r2[j] = str[i];
		}
		if(!r1 || !r2)
			exit (-1);
	}
	if (validate_links2(r1, r2, nest));
		exit(-1);
}

int validate_startandend(char *str, t_nest *nest)
{
	if (ft_strcmp(str, "##end") == 0)
	{
		ft_strcpy(nest->rooms->name, str);
		nest->rooms->id = nest->rooms->roomcount + 1;
		nest->rooms->startid = nest->rooms->roomcount + 1;
	}
	else if (ft_strcmp(str, "##start") == 0)
	{
		ft_strcpy(nest->rooms->name, str);
		nest->rooms->id = nest->rooms->roomcount + 1;
		nest->rooms->endid = nest->rooms->roomcount + 1;
	}
	else
		exit(-1);
	return 0;
}



int validate_input(char *str, t_nest *nest)
{
	char validate[100];
	int i = 0;

	while (*str != '\0')
	{
		while (*str != '\n')
			validate[i++] = *str++;
		if (!nest->ants)
			nest->ants = validate_ants(validate);
		else if (!nest->rooms->start || !nest->rooms->end || !ft_strchr(validate, '-'))
			validate_rooms(validate, nest);
		else if (validate[0] == '#')
		{
			if (validate[1] == '#')
				validate_startandend(validate, nest);
		}
		else if (ft_strchr(validate, '-'))
			validate_links(validate, nest);
	}
}

int read_input(char *buff, int buff_size, int ac, char **av, t_nest *nest)
{
	int fd;

	fd = 0;
	if (ac >= 2)
	{
		fd = open(av[1], fd);
		read (fd, buff, buff_size);
	}
	else
	{
		read (fd, buff, buff_size);
	}
	if (!buff || !validate_input(buff, nest))
		exit(-1);
	return 0;
}

int main(int ac, char **av)
{
	t_nest nest;
	init_nest(&nest);
	int buff_size = 10000;
	char buff[buff_size];

	read_input(buff, buff_size, ac, av, &nest);
	printf("buff: %s\n", buff);
	return 0;
}
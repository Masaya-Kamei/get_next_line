/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:45:54 by mkamei            #+#    #+#             */
/*   Updated: 2021/10/16 11:31:51 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	cat_file_using_gnl(const int fd)
{
	int		gnl_status;
	char	*line;
	int		line_num;

	gnl_status = 1;
	line_num = 0;
	while (gnl_status == 1)
	{
		gnl_status = get_next_line(fd, &line);
		if (gnl_status == -1)
			break ;
		if (!(gnl_status == 0 && line[0] == '\0'))
			printf("%6d	%s", ++line_num, line);
		if (gnl_status != 0)
			printf("\n");
		free(line);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;

	if (argc == 1)
		return (0);
	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		cat_file_using_gnl(fd);
		close(fd);
	}
	return (0);
}

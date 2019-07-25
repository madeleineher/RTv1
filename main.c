/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/25 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int			quit(t_env *e)
{
	if (e->w.ip)
		mlx_destroy_image(e->w.mp, e->w.ip);
	if (e->w.wp)
		mlx_destroy_window(e->w.mp, e->w.wp);
	if (e->w.mp)
		free(e->w.mp);
	exit(0);
	return (0);
}

int			error(t_env *e, int i)
{
	(void)e;
	if (i == 1)
		ft_putendl("usage:\t./rtv1 scene");
	if (i == 2)
		ft_putendl("error: mlx init error.");
	quit(e);
	return (0);
}

int			parse(t_env	*e, int fd)
{
	int		ret;
	int		i;
	char	*line;
	int		len = 0;

	e->f_lines = (char**)malloc(sizeof(char*) * 5);
	i = 0;
	ret = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		len = ft_strlen(line) + 1;
		e->f_lines[i] = (char*)malloc(sizeof(char) * len);
		if (line)
		{
			free(line);
			line = NULL;
		}			
		i++;
	}
	e->f_lines[i] = 0;
	if (ret == -1)
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env	e;
	int		fd;

	ft_bzero(&e, sizeof(e));
	if (argc != 2)
		error(&e, 1);
	fd = open(argv[1], O_RDWR);
	if (parse(&e, fd) == -1)
		error(&e, 2);
	if (!(e.w.mp = mlx_init()) \
			|| !(e.w.wp = mlx_new_window(e.w.mp, WIDTH, HEIGHT, "RTv1")))
		error(&e, 2);
	if (!(e.w.ip = mlx_new_image(e.w.mp, WIDTH, HEIGHT)))
		error(&e, 2);
	if (!(e.data = mlx_get_data_addr(e.w.ip, &e.w.bpp, &e.w.sl, &e.w.end)))
		error(&e, 2);
	setup_rtv1(&e);
	start_rtv1(&e);
	mlx_loop(e.w.mp);
	return (0);
}

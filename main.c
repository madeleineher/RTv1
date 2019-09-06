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

void		set_vocab(t_env *e)
{
	e->vocab_one[0] = "sphere";
	e->vocab_one[1] = "cylinder";
	e->vocab_one[2] = "cone";
	e->vocab_one[3] = "plane";

	e->vocab_two[0] = "position"; //
	e->vocab_two[1] = "direction"; //
	e->vocab_two[2] = "diffusion"; //
	e->vocab_two[3] = "reflection"; //
	e->vocab_two[4] = "specvalue"; 
	e->vocab_two[5] = "specpower"; //
	e->vocab_two[6] = "intensity"; 
	e->vocab_two[7] = "translate"; //
	e->vocab_two[8] = "rotate"; //
	e->vocab_two[9] = "angle"; //
	e->vocab_two[10] = "color"; //
	e->vocab_two[11] = "center"; //
	e->vocab_two[12] = "d"; //
	e->vocab_two[13] = "radius"; //
	e->vocab_two[14] = "ambient"; // -- correct name ? // need this ?????
	e->vocab_two[15] = "normal"; //
}

int			main(int argc, char **argv)
{
	t_env		e;
	int			ret;
	int			fd;

	ft_bzero(&e, sizeof(e));
	if (argc != 2)
		error(&e, 0);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		error(&e, 1);
	set_vocab(&e);
	if ((ret = parser(&e, fd)) != 0) // parser
		error(&e, ret);
	if (!(e.w.mp = mlx_init()) \
			|| !(e.w.wp = mlx_new_window(e.w.mp, WIDTH, HEIGHT, "RTv1")))
		error(&e, 2);
	if (!(e.w.ip = mlx_new_image(e.w.mp, WIDTH, HEIGHT)))
		error(&e, 2);
	if (!(e.data = mlx_get_data_addr(e.w.ip, &e.w.bpp, &e.w.sl, &e.w.end)))
		error(&e, 2);
	start_rtv1(&e);
	mlx_loop(e.w.mp);
	return (0);
}

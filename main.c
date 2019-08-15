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
	if (i == 0)
		ft_putendl("usage:\t./rtv1 scene");
	if (i == 1)
		ft_putendl("error: not a valid file descriptor.");
	if (i == 2)
		ft_putendl("error: mlx init error.");
	if (i == 3)
		ft_putendl("error: not a valid parameter.");
	if (i > 3 && i < 26)
	{
		if (i == 4)
			ft_putendl("Oops ! Looks like <scene>/<objects>/<specs> tag was not opened/closed/formatted properly.");
		if (i == 5)
			ft_putendl("Oops ! Looks like there was poor tabulation.");
		if (i == 6)
			ft_putendl("Oops ! Looks like <scene> tag was not closed properly.");
		if (i == 7)
			ft_putendl("Oops ! Looks like the start and end tags don't correspond.");
		if (i == 8)
			ft_putendl("Oops ! Looks like you misspelled/missing tags.");
		if (i == 9)
			ft_putendl("Oops ! Looks angle brackets are not implemented correctly.");
		if (i == 10)
			ft_putendl("Oops ! Looks like <cam> is not properly opened/closed.");
		if (i == 11)
			ft_putendl("Oops ! Looks like <amb> is not properly opened/closed.");
		if (i == 12)
			ft_putendl("Oops ! Looks like <light> is not properly opened/closed.");
		if (i == 13)
			ft_putendl("Oops ! Looks like the tag is this line is not properly formatted.");
		if (i == 14)
			ft_putendl("Oops ! Looks like something is missing/mispelled ~~~~~~*.");
		if (i == 15)
			ft_putendl("Oops ! Looks like this line is missing an '=' sign.");
		if (i == 16)
			ft_putendl("Oops ! Looks like status is not properly indicated.");
		if (i == 17)
			ft_putendl("Oops ! Looks like this line has poor formatting.");
		if (i == 18)
			ft_putendl("Oops ! Looks like this line was given poor arguments.");
		if (i == 19)
			ft_putendl("Oops ! Looks like there is too many/little commas.");
		if (i == 20)
			ft_putendl("Oops ! Looks like this object tag is not correct.");
		if (i == 21)
			ft_putendl("Oops ! Looks like this object tag is not open/closed correctly.");
		if (i == 22)
			ft_putendl("Oops ! Looks like this ................");
		ft_putstr("The problem lies in line : ");
		ft_putnbr(e->p.gnl_i);
		ft_putchar('\n');
	}
	if (i > 25)
	{
		if (i == 26)
			ft_putendl("Oops ! Looks like <cam>/<amb>/<light> is missing.");
		if (i == 27)
			ft_putendl("Oops ! Looks like there are conflicting light tags.");
		if (i == 28)
			ft_putendl("Oops ! Looks like <cam>/<amb>/<light> is/are not closed properly.");
		if (i == 29)
			ft_putendl("Oops ! Looks like there are conflicting <light> tags.");
		if (i == 30)
			ft_putendl("Oops ! Looks like there are conflicting <sphere> tags.");
		if (i == 31)
			ft_putendl("Oops ! Looks like there are conflicting <cone> tags.");
		if (i == 32)
			ft_putendl("Oops ! Looks like there are conflicting <cylinder> tags.");
		if (i == 33)
			ft_putendl("Oops ! Looks like there are conflicting <plane> tags.");
		if (i == 34)
			ft_putendl("Oops ! 1");
		if (i == 35)
			ft_putendl("Oops ! 2.");
		if (i == 36)
			ft_putendl("Oops ! 3");
		if (i == 37)
			ft_putendl("Oops ! 4");
		if (i == 38)
			ft_putendl("Oops ! i am here 1!");
		if (i == 39)
			ft_putendl("Oops ! i am here 2!");
		if (i == 40)
			ft_putendl("Oops ! i am here 3!");
		if (i == 41)
			ft_putendl("Oops ! i am here 4!");
	}
	quit(e);
	return (0);
}

void		set_vocab(t_env *e)
{
	e->vocab_one[0] = "sphere";
	e->vocab_one[1] = "cylinder";
	e->vocab_one[2] = "cone";
	e->vocab_one[3] = "plane";

	e->vocab_two[0] = "position";
	e->vocab_two[1] = "direction";
	e->vocab_two[2] = "diffusion";
	e->vocab_two[3] = "reflection";
	e->vocab_two[4] = "specvalue";
	e->vocab_two[5] = "specpower";
	e->vocab_two[6] = "intensity";
	e->vocab_two[7] = "translate";
	e->vocab_two[8] = "rotate";
	e->vocab_two[9] = "angle";
	e->vocab_two[10] = "axis";
	e->vocab_two[11] = "center";
	e->vocab_two[12] = "d";
	e->vocab_two[13] = "mat";
	e->vocab_two[14] = "radius";
	e->vocab_two[15] = "ambient"; // correct name ?
	e->vocab_two[16] = "normal";
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
	if ((ret = parser(&e, fd)) != 0)
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

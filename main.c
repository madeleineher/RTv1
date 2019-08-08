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
	if (i > 3 && i < 20)
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
			ft_putendl("Oops ! Looks like something is missing/mispelled.");
		if (i == 15)
			ft_putendl("something is wrong.");
		if (i == 16)
			ft_putendl("Oops ! Looks like status is not properly indicated.");
		ft_putstr("The problem lies in line : ");
		ft_putnbr(e->gnl_i);
		ft_putchar('\n');
	}
	if (i > 19)
	{
		if (i == 20)
			ft_putendl("Oops ! Looks like <cam>/<amb>/<light> is missing.");
		if (i == 21)
			ft_putendl("Oops ! Looks like there are conflicting light tags.");
		if (i == 22)
			ft_putendl("Oops ! Looks like <cam>/<amb>/<light> is/are not closed properly.");
		if (i == 23)
			ft_putendl("Oops ! Looks like there are conflicting <light> tags.");
	}
	quit(e);
	return (0);
}

void		set_vocab(t_env *e)
{
	e->vocab_one[0] = "cam";
	e->vocab_one[1] = "amb";
	e->vocab_one[2] = "basic";
	e->vocab_one[3] = "status";
	e->vocab_one[4] = "position";
	e->vocab_one[5] = "direction";
	e->vocab_one[6] = "diffusion";
	e->vocab_one[7] = "reflection";
	e->vocab_one[8] = "specvalue";
	e->vocab_one[9] = "specpower";
	e->vocab_one[10] = "light";
	e->vocab_one[11] = "intensity";
	e->vocab_one[12] = "extra";
	e->vocab_one[13] = "translate";
	e->vocab_one[14] = "rotate";

	e->vocab_two[0] = "objects";
	e->vocab_two[1] = "status";
	e->vocab_two[2] = "basic";
	e->vocab_two[3] = "sphere";
	e->vocab_two[4] = "cylinder";
	e->vocab_two[5] = "cone";
	e->vocab_two[6] = "plane";
	e->vocab_two[7] = "angle";
	e->vocab_two[8] = "axis";
	e->vocab_two[9] = "center";
	e->vocab_two[10] = "d";
	e->vocab_two[11] = "direction";
	e->vocab_two[12] = "extra";
	e->vocab_two[13] = "mat";
	e->vocab_two[14] = "normal";
	e->vocab_two[15] = "rotate";
	e->vocab_two[16] = "radius";
	e->vocab_two[17] = "translate";
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

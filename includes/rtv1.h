/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:13:39 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/25 15:33:44 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <complex.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <assert.h>
# include <stdio.h> // remove

# define WIDTH			800
# define HEIGHT 		800

# define ESC			53

typedef struct			s_ll
{
	size_t			content_size;
	char			**content;
	struct s_ll		*next;
}				t_ll;

typedef struct			s_pos
{
	int			x;
	int			y;
	int			z;
}				t_pos;

typedef struct			s_int
{
	int			x;
	int			y;
	int			z;
}				t_int;

typedef struct			s_light
{
	t_pos			*lipos;
	t_int			*inten;
}				t_light;

typedef struct			s_dir
{
	int			x;
	int			y;
	int			z;
}				t_dir;

typedef struct			s_cen
{
	int			x;
	int			y;
	int			z;
}				t_cen;

typedef struct			s_camera
{
	t_pos			*campos;
	t_dir			*camdir;
}				t_camera;

typedef struct			s_cone
{
	t_dir			*dir;
	t_cen			*cen;
	int			angle;
	int			ambient;
}				t_cone;

typedef struct			s_sphere
{
	t_cen			*cen;
	int			radius;
	int			ambient;
}				t_sphere;

typedef struct			s_cyn
{
	t_dir			*dir;
	int			axis;
	int			radius;
	int			ambient;
}				t_cyn;

typedef struct			s_normal
{
	int			x;
	int			y;
	int			z;
}				t_normal;

typedef struct			s_plane
{
	t_normal		*nor;
	int			mat;
	int			d;
}				t_plane;

typedef struct			s_diff
{
	int			x;
	int			y;
	int			z;
}				t_diff;

typedef struct			s_ref
{
	int			x;
	int			y;
	int			z;
}				t_ref;

typedef struct			s_amb
{
	t_diff			*diff;
	t_ref			*ref;
	int			specvalue;
	int			specpower;
}				t_amb;

typedef struct			s_mlx
{
	void			*mp;
	void			*wp;
	void			*ip;
	int			bpp;
	int			end;
	int			sl;
}				t_mlx;

typedef struct			s_env
{
	char			**line;
	char			*data;
	char			parser[5];
	int			k[300];
	char			*verify;
	int			ret_ver;
	int			i;
	t_mlx			w;
	t_ll			*ll;
	t_amb			amb;
	t_camera		cam;
	t_cone			cone;
	t_cyn			cyn;
	t_light			light;
	t_plane			plane;
	t_sphere		sphere;
}				t_env;

void				setup_rtv1(t_env *e);
int				parser(t_env *e, int fd);
int				verify(t_env *e, char *whatami);
int				verifycam(t_env *e, char **splits);
int				verifyamb(t_env *e, char **splits);
int				verifylight(t_env *e, char **splits);
int				verifycone(t_env *e, char **splits);
int				verifycyn(t_env *e, char **splits);
int				verifyplane(t_env *e, char **splits);
int				verifysphere(t_env *e, char **splits);
int				howmanystrings(char **splits);
char				*getnumber(char *split);
void				start_rtv1(t_env *e);
int				touch(t_env *e);
int				key_press(int key, t_env *e);
int				key_release(int key, t_env *e);
int				quit(t_env *e);
void				draw_sphere(t_env *e);
int				main(int argc, char **argv);

#endif

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

# define WIDTH		800
# define HEIGHT 	800

# define ESC		53

# define CONE		0
# define CYLINDER	1
# define PLANE		2
# define SPHERE		3

typedef struct		s_ll
{
	size_t			content_size;
	char			*content;
	struct s_ll		*next;
}					t_ll;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				z;
}					t_pos; // position

typedef struct		s_int
{
	int				x;
	int				y;
	int				z;
}					t_int; // intesity

typedef struct		s_dir
{
	int				x;
	int				y;
	int				z;
}					t_dir; // direction

typedef struct		s_cen
{
	int				x;
	int				y;
	int				z;
}					t_cen; // center

typedef struct		s_diff
{
	int				x;
	int				y;
	int				z;
}					t_diff; // diffusion

typedef struct		s_ref
{
	int				x;
	int				y;
	int				z;
}					t_ref; // refraction

typedef struct		s_normal
{
	int				x;
	int				y;
	int				z;
}					t_normal; // normal

typedef struct		s_amb
{
	t_diff			*diff;
	t_ref			*ref;
	int				specvalue;
	int				specpower;
}					t_amb;

typedef struct		s_light
{
	t_pos			*lipos;
	t_int			*inten;
}					t_light;

typedef struct		s_camera
{
	t_pos			*campos;
	t_dir			*camdir;
}					t_camera;

typedef struct		s_obj
{
	t_dir			*dir;
	t_cen			*cen;
	t_normal		*nor;
	int				mat;
	int				d;
	int				type;
	int				angle;
	int				axis;
	int				radius;
	int				ambient;
}					t_obj;

typedef struct		s_mlx
{
	void			*mp;
	void			*wp;
	void			*ip;
	int				bpp;
	int				end;
	int				sl;
}					t_mlx;

typedef struct		s_ret
{
	int				tag;
	int				voc;
	int				glo;
	int				gnl;
}					t_ret;

typedef struct		s_env
{
	char			**line;
	char			*data;
	int				gnl_i;
	char			parser[5];
	int				k[300];
	char			*gnl_line;
	int				ret_ver;
	int				i;
	int				lenfile;
	int				scene;
	int				specs;
	int				skip;
	int				objects;
	char			*vocab_one[15];
	char			*vocab_two[18];
	t_ret 			ret;
	t_mlx			w;
	t_ll			*ll;
	t_amb			amb;
	t_camera		cam;
	t_light			light;
	t_obj			obj;
}					t_env;

void				setup_rtv1(t_env *e);
int					parser(t_env *e, int fd);
void				start_rtv1(t_env *e);
int					touch(t_env *e);
int					key_press(int key, t_env *e);
int					key_release(int key, t_env *e);
int					quit(t_env *e);
void				draw_sphere(t_env *e);
int					main(int argc, char **argv);

#endif

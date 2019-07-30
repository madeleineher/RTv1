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

typedef struct			s_light
{
	int			position[4];
	int			intesity[4];
}				t_light;

typedef struct			s_camera
{
	int			position[4];
	int			direction[4];
}				t_camera;

typedef struct			s_cone
{
	int			direction[4];
	int			center[4];
	int			angle;
	int			ambient;
}				t_cone;

typedef struct			s_sphere
{
	int			center[4];
	int			radius;
	int			ambient;
}				t_sphere;

typedef struct			s_cyn
{
	int			direction[4];
	int			axispoint;
	int			radius;
	int			ambient;
}				t_cyn;

typedef struct			s_plane
{
	int			normal[4];
	int			ambient;
	int			d;
}				t_plane;

typedef struct			s_shape
{
	char			*shape;
	char			**params;
}				t_shape;

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
	char			parser[5];
	int			k[300];
	char			**f_lines;
	t_mlx			w;
	t_shape			s;
	t_ll			ll;
	char			*data;
}				t_env;

void				setup_rtv1(t_env *e);
void				start_rtv1(t_env *e);
int				touch(t_env *e);
int				key_press(int key, t_env *e);
int				key_release(int key, t_env *e);
int				quit(t_env *e);
void				draw_sphere(t_env *e);
int				main(int argc, char **argv);

#endif

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
# include "rtv1_parser.h"
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

typedef struct		s_dif
{
	int				x;
	int				y;
	int				z;
}					t_dif; // diffusion

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

typedef struct		s_rot
{
	int				x;
	int				y;
	int				z;
}					t_rot; // rotate

typedef struct		s_tra
{
	int				x;
	int				y;
	int				z;
}					t_tra; // translate

typedef struct		s_camera // struct for camera data
{
	t_pos			campos;
	t_dir			camdir;
	t_tra			*tra;
	t_rot			*rot;
}					t_camera;

typedef struct		s_amb // struct for amb data
{
	t_dif			*diff;
	t_ref			*ref;
	int				specvalue;
	int				specpower;
}					t_amb;

typedef struct		s_ll  // linked list for storing LIGHT data
{
	size_t			content_size;
	t_pos			pos;
	t_int			its;
	struct s_ll		*next;
}					t_ll;

typedef struct		s_obj // struct for storing object data
{
	int				status; // 0 == basic , 1 == extra
	int				d;
	int				angle;
	int				axis;
	int				radius;
	int				s_pow;
	int				s_val;
	t_dif			*dif;
	t_dir			*dir;
	t_cen			*cen;
	t_normal		*nor;
	t_rot			*rot;
	t_tra			*tra;
	int				current_shape; // sphere == 0 ; cone == 1 ; cylinder == 2 ; plane == 3
}					t_obj;

typedef struct		s_ol  // linked list for storing OBJECT data
{
	size_t			content_size;
	t_obj			obj;
	struct s_ol		*next;
}					t_ol;

typedef struct		s_mlx
{
	void			*mp;
	void			*wp;
	void			*ip;
	int				bpp;
	int				end;
	int				sl;
}					t_mlx;

typedef struct		s_env
{
	char			*data;
	int				str_count;
	int				k[300];
	int				s_count;
	t_parser		p; // THE PARSER STRUCTURE !
	t_mlx			w; // mlx images, window, etc.

	t_amb			amb; // store amb
	t_camera		cam; // store cam

	// t_light			light; // store light
	t_obj			obj; // store objs

	t_ll			*ll_lit; // linked list
	t_ol			*ll_obj; // linked list
	t_ll			*save_light;
}					t_env;

void				setup_rtv1(t_env *e);
int					parser(t_env *e, int fd);
void				start_rtv1(t_env *e);
int					touch(t_env *e);
int					key_press(int key, t_env *e);
int					key_release(int key, t_env *e);
int					quit(t_env *e);
void				draw_sphere(t_env *e);

//functions for parser
void				set_vocab(t_env *e);
int					two_tabs_specs(t_env *e, t_ll **l_head);
int					open_close(int *check_me);
int					extract_status(t_env *e);
int					two_angle_brackets(t_env *e);
int					twotab_verifications(t_env *e);
void				count_shapes(t_env *e, char *split);
int					verifyobjecttags_closings(t_env *e, char *split);
int					globals(t_env *e, char *gnl_line);
int					verifyargs_one(t_env *e, t_ll *l_head, t_ol *o_head);
int					verifyanglebrackets_one(t_env *e);
int					verifyvocab_one(t_env *e);
int					verifyargs_three(t_env *e, t_ll **l_head, t_ol *o_head);
int					verifyanglebrackets_three(t_env *e);
int					verifyvocab_three(t_env *e);
int					shapevocab_checker(t_env *e);
int					shapevocab_checker_partwo(t_env *e);
int					verify_spec_atb(t_env *e);
int					verify_spec_atb_partwo(t_env *e);
int					verify_tag_to_argument(t_env *e, char *string, int args);
int					error(t_env *e, int i);
void				reset_spec_atb(t_env *e);
void				lineless_errors_three(t_env *e, int i);
void				lineless_errors_eight(t_env *e, int i);
int					verify_numbers_one(t_env *e, t_ll *l_head, t_ol *o_head);
int					verify_values(t_env *e);
int					verify_numbers_three(t_env *e, t_ll *l_head, t_ol *o_head);
void				reset_shape_atb(t_env *e);
void				reset_shape_atb_two(t_env *e);
int					checkforopenobjecttags(t_env *e);
int					add_link_light(t_env *e, t_ll **head, t_ll *ll_savehead);
int					add_link_obj(t_env *e, t_ol **head);


int					main(int argc, char **argv);

#endif

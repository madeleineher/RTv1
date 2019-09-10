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
// # include "rtv1_parser.h"
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

typedef struct		s_ll  // for storing data
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

typedef struct		s_amb
{
	t_diff			*diff;
	t_ref			*ref;
	t_tra			*tra;
	t_rot			*rot;
	int				status;
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
	t_tra			*tra;
	t_rot			*rot;
	int				status;
}					t_camera;

typedef struct		s_obj // for storing data
{
	t_dir			*dir;
	t_cen			*cen;
	t_normal		*nor;
	t_rot			*rot;
	t_tra			*tra;
	int				sta;
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

typedef struct		s_ret // part of parser
{
	int				tag;
	int				glo;
	int				gnl;
}					t_ret;

typedef struct		s_spec //parser
{
	int				cam;
	int				amb;
	int				light;
	int				cam_cl;
	int				amb_cl;
}					t_spec;

typedef struct		s_parseobj  // part of parser
{
	int				sphere;
	int				plane;
	int				cone;
	int				cyn;
}					t_parseobj;

typedef struct		s_pla_atb // part of parser
{
	int				normal;
	int				d;
	int				diffusion;
	int				reflection;
	int				specpower;
	int				specvalue;
	int				rotate;
	int				translate;
}					t_pla_atb;

typedef struct		s_cyn_atb // part of parser
{
	int				radius;
	int				center;
	int				direction;
	int				diffusion;
	int				reflection;
	int				specpower;
	int				specvalue;
	int				angle;
	int				rotate;
	int				translate;
}					t_cyn_atb;

typedef struct		s_cone_atb // part of parser
{
	int				radius;
	int				center;
	int				direction;
	int				diffusion;
	int				reflection;
	int				specpower;
	int				specvalue;
	int				angle;
	int				rotate;
	int				translate;
}					t_cone_atb;

typedef struct		s_sphere_atb // part of parser
{
	int				radius;
	int				center;
	int				diffusion;
	int				reflection;
	int				specpower;
	int				specvalue;
	int				rotate;
	int				translate;
}					t_sphere_atb;

typedef struct		s_cam_atb //parser
{
	int				position;
	int				direction; // vector, can be all negative but not all 0, 0, 0
	int				rotation; // can be all 0, 0, 0 and negative // no rules but limit is 360 (max)! -360 (min)
	int				translation; // 0, 0, 0 // no rules add translation to position
}					t_cam_atb;

typedef struct		s_amb_atb  //parser
{
	int				power;
	int				color; // ??
}					t_amb_atb;

typedef struct		s_lig_atb //parser
{
	int				position;
	int				intensity; // 0 (min) to 255 (max)
	int				rotate; // can be all 0, 0, 0 and negative // no rules but limit is 360 !
	int				translate; // 0, 0, 0 // no rules add translation to position
}					t_lig_atb;

typedef struct		s_shape_count // parser
{
	int				spheres;
	int				cones;
	int				cylinders;
	int				planes;
}					t_shape_count;

typedef struct		s_parser /////////////////////// STRUCT PARSER
{
	char			*line;
	char			*strone;
	char			*strtwo;
	char			*s_tmp; // moving
	int				gnl_i;
	char			*gnl_line;
	char			*tmp;
	char			*t;
	char			*current_tag;
	char			*vocab_one[4];
	char			*vocab_two[16];
	int				skips;
	int				scene;
	int				specs;
	int				spec_order;
	int				skip;
	int				objects;
	int 			voc_i;
	int 			voc_check;
	int				status;
	int				set_one;
	int				set_two;
	int				i;
	int				j;
	int				k;
	int				close_obj_i;
	int				good_obj_brack;
	int				bad_obj_brack;
	int				current_shape; // sphere == 0 ; cone == 1 ; cylinder == 2 ; plane == 3
	int				e1;
	int				e2;
	int				l;
	int				v1;
	int				v2;
	int				v3;
	int				comma;
	int				realnum;
	int				ret_p; // main ret
	t_parseobj		p_obj;
	t_spec			p_spec;
	t_ret 			ret;
	t_shape_count	count;
	t_pla_atb		p_atb;
	t_cyn_atb		y_atb;
	t_cone_atb		c_atb;
	t_sphere_atb	s_atb;
	t_lig_atb		l_atb;
	t_amb_atb		a_atb;
	t_cam_atb		ca_atb;
}					t_parser;

typedef struct		s_env
{
	char			*data;
	int				str_count;
	int				k[300];
	int				lenfile;
	int				s_count; // need to copy t_shape_count
	t_parser		p; // THE PARSER STRUCTURE !
	t_mlx			w; // mlx images, window, etc. 
	t_ll			*ll; // linked list
	t_amb			amb;
	t_camera		cam;
	t_light			light;
	t_obj			obj; // cleaning
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
int					two_tabs_specs(t_env *e, char **split_test);
int					open_close(int *check_me);
int					extract_status(t_env *e, char **strings);
int					two_angle_brackets(t_env *e);
int					twotab_verifications(t_env *e, char **split_test);
int					globals(t_env *e, char *gnl_line);
int					verifyargs_one(t_env *e);
int					verifyanglebrackets_one(t_env *e);
int					verifyvocab_one(t_env *e);
int					verifyargs_three(t_env *e, char **split_test);
int					verifyanglebrackets_three(t_env *e, char **split_test);
int					verifyvocab_three(t_env *e, char **split);
int					shapevocab_checker(t_env *e, char **split_test);
int					shapevocab_checker_partwo(t_env *e);
int					verify_spec_atb(t_env *e, char **split_test);
int					verify_spec_atb_partwo(t_env *e);
int					verify_tag_to_argument(t_env *e, char *string, int args);
int					error(t_env *e, int i);
void				reset_spec_atb(t_env *e);
void				lineless_errors_three(t_env *e, int i);
void				lineless_errors_eight(t_env *e, int i);
int					verify_numbers_one(t_env *e, char *string, char *num);
int					verify_values(t_env *e);
int					verify_numbers_three(t_env *e, char *string);

int					main(int argc, char **argv);

#endif

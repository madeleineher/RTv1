/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/30 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		add_link(char *line, t_ll **head, t_env *e, int i) // needs to be moved to "storing file.c"
{
	(void)i;
	t_ll	*new;
	t_ll	*last;

	last = *head;
	new = NULL;
	if (!(new = (t_ll*)malloc(sizeof(t_ll))))
		return (-1);
	new->content = line;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	e->lenfile++;
	return (0);
}

int		threetab_verifications(t_env *e, char **split_test)
{
	if (e->str_count == 3) // THREEE ----------- in verifyfour.c
	{
		if ((e->ret_tmp = verifyanglebrackets_three(e, split_test)) == -1)
			return (17);
		if ((e->ret_tmp = verifyvocab_three(e, split_test)) == -1)
			return (14);
		if ((e->ret_tmp = verifyargs_three(e, split_test)) != 0)
			return (e->ret_tmp);
	}
	else if (e->str_count == 1) // ONE ~~~~~~~~~~ in verifythree.c
	{
		if ((e->ret_tmp = verifyanglebrackets_one(e)) == -1)
			return (17);
		if ((e->ret_tmp = verifyvocab_one(e)) == -1)
			return (14);
		if ((e->ret_tmp = verifyargs_one(e)) != 0)
			return (18);
	}
	else
		return (17);
	return (0);
}

int		shapevocab_checker_partwo(t_env *e)
{
	if (e->p.current_shape == 1) // sphere
	{
		if (e->s_atb.radius < 1 || e->s_atb.center < 1 || e->s_atb.diffusion < 1
			|| e->s_atb.reflection < 1 || e->s_atb.specvalue < 1  || e->s_atb.specpower < 1)
				return (39);
		if (e->s_atb.radius > 1 || e->s_atb.center > 1 || e->s_atb.diffusion > 1
			|| e->s_atb.reflection > 1 || e->s_atb.specvalue > 1  || e->s_atb.specpower > 1)
				return (40);
		if (e->p.status == 1)
			if (e->s_atb.rotate != 0 || e->s_atb.translate != 0)
				return (41);
		if (e->p.status == 2)
			if (e->s_atb.rotate != 1 || e->s_atb.translate != 1)
				return (42);
	}
	if (e->p.current_shape == 2) // CONE
	{
		if (e->c_atb.radius < 1 || e->c_atb.center < 1 || e->c_atb.diffusion < 1 || e->c_atb.direction < 1
			|| e->c_atb.reflection < 1 || e->c_atb.specvalue < 1  || e->c_atb.specpower < 1 || e->c_atb.angle < 1)
				return (43);
		if (e->c_atb.radius > 1 || e->c_atb.center > 1 || e->c_atb.diffusion > 1 || e->c_atb.direction > 1
			|| e->c_atb.reflection > 1 || e->c_atb.specvalue > 1  || e->c_atb.specpower > 1 || e->c_atb.angle > 1)
				return (44);
		if (e->p.status == 1)
			if (e->c_atb.rotate != 0 || e->c_atb.translate != 0)
				return (45);
		if (e->p.status == 2)
			if (e->c_atb.rotate != 1 || e->c_atb.translate != 1)
				return (46);
	}
	if (e->p.current_shape == 3) // cylinder
	{
		if (e->y_atb.radius < 1 || e->y_atb.center < 1 || e->y_atb.diffusion < 1 || e->y_atb.direction < 1
			|| e->y_atb.reflection < 1 || e->y_atb.specvalue < 1  || e->y_atb.specpower < 1 || e->y_atb.angle < 1)
				return (47);
		if (e->y_atb.radius > 1 || e->y_atb.center > 1 || e->y_atb.diffusion > 1 || e->y_atb.direction > 1
			|| e->y_atb.reflection > 1 || e->y_atb.specvalue > 1  || e->y_atb.specpower > 1 || e->y_atb.angle > 1)
				return (48);
		if (e->p.status == 1)
			if (e->y_atb.rotate != 0 || e->y_atb.translate != 0)
				return (49);
		if (e->p.status == 2)
			if (e->y_atb.rotate != 1 || e->y_atb.translate != 1)
				return (50);
	}
	if (e->p.current_shape == 4) // plane
	{
		if (e->p_atb.normal < 1 || e->p_atb.d < 1 || e->p_atb.diffusion < 1
			|| e->p_atb.reflection < 1 || e->p_atb.specvalue < 1  || e->p_atb.specpower < 1)
				return (51);
		if (e->p_atb.normal > 1 || e->p_atb.d > 1 || e->p_atb.diffusion > 1
			|| e->p_atb.reflection > 1 || e->p_atb.specvalue > 1  || e->p_atb.specpower > 1)
				return (52);
		if (e->p.status == 1)
			if (e->p_atb.rotate != 0 || e->p_atb.translate != 0)
				return (53);
		if (e->p.status == 2)
			if (e->p_atb.rotate != 1 || e->p_atb.translate != 1)
				return (54);
	}
	return (0);
}

int		shapevocab_checker(t_env *e, char **split_test)
{
	e->s_tmp = ft_strsub(split_test[0], 4, (ft_strclen(split_test[0], '>') - 4));
	if (e->p.current_shape == 1)
	{
		if (ft_strcmp("radius", e->s_tmp) == 0)
			e->s_atb.radius++;
		else if (ft_strcmp("center", e->s_tmp) == 0)
			e->s_atb.center++;
		else if (ft_strcmp("diffusion", e->s_tmp) == 0)
			e->s_atb.diffusion++;
		else if (ft_strcmp("reflection", e->s_tmp) == 0)
			e->s_atb.reflection++;
		else if (ft_strcmp("specvalue", e->s_tmp) == 0)
			e->s_atb.specvalue++;
		else if (ft_strcmp("specpower", e->s_tmp) == 0)
			e->s_atb.specpower++;
		else if (ft_strcmp("rotate", e->s_tmp) == 0)
			e->s_atb.rotate++;
		else if (ft_strcmp("translate", e->s_tmp) == 0)
			e->s_atb.translate++;
		else
			return (55); // wrong param in sphere
	}
	if (e->p.current_shape == 2)
	{
		if (ft_strcmp("radius", e->s_tmp) == 0)
			e->c_atb.radius++;
		else if (ft_strcmp("center", e->s_tmp) == 0)
			e->c_atb.center++;
		else if (ft_strcmp("diffusion", e->s_tmp) == 0)
			e->c_atb.diffusion++;
		else if (ft_strcmp("reflection", e->s_tmp) == 0)
			e->c_atb.reflection++;
		else if (ft_strcmp("specvalue", e->s_tmp) == 0)
			e->c_atb.specvalue++;
		else if (ft_strcmp("specpower", e->s_tmp) == 0)
			e->c_atb.specpower++;
		else if (ft_strcmp("angle", e->s_tmp) == 0)
			e->c_atb.angle++;
		else if (ft_strcmp("rotate", e->s_tmp) == 0)
			e->c_atb.rotate++;
		else if (ft_strcmp("translate", e->s_tmp) == 0)
			e->c_atb.translate++;
		else if (ft_strcmp("direction", e->s_tmp) == 0)
			e->c_atb.direction++;
		else
			return (56); // wrong param in cone
	}
	if (e->p.current_shape == 3)
	{
		if (ft_strcmp("radius", e->s_tmp) == 0)
			e->y_atb.radius++;
		else if (ft_strcmp("center", e->s_tmp) == 0)
			e->y_atb.center++;
		else if (ft_strcmp("diffusion", e->s_tmp) == 0)
			e->y_atb.diffusion++;
		else if (ft_strcmp("reflection", e->s_tmp) == 0)
			e->y_atb.reflection++;
		else if (ft_strcmp("specvalue", e->s_tmp) == 0)
			e->y_atb.specvalue++;
		else if (ft_strcmp("specpower", e->s_tmp) == 0)
			e->y_atb.specpower++;
		else if (ft_strcmp("angle", e->s_tmp) == 0)
			e->y_atb.angle++;
		else if (ft_strcmp("rotate", e->s_tmp) == 0)
			e->y_atb.rotate++;
		else if (ft_strcmp("translate", e->s_tmp) == 0)
			e->y_atb.translate++;
		else if (ft_strcmp("direction", e->s_tmp) == 0)
			e->y_atb.direction++;
		else
			return (57); // wrong param in cyn
	}
	if (e->p.current_shape == 4) // HERE !
	{
		if (ft_strcmp("normal", e->s_tmp) == 0)
			e->p_atb.normal++;
		else if (ft_strcmp("d", e->s_tmp) == 0)
			e->p_atb.d++;
		else if (ft_strcmp("diffusion", e->s_tmp) == 0)
			e->p_atb.diffusion++;
		else if (ft_strcmp("reflection", e->s_tmp) == 0)
			e->p_atb.reflection++;
		else if (ft_strcmp("specvalue", e->s_tmp) == 0)
			e->p_atb.specvalue++;
		else if (ft_strcmp("specpower", e->s_tmp) == 0)
			e->p_atb.specpower++;
		else if (ft_strcmp("rotate", e->s_tmp) == 0)
			e->p_atb.rotate++;
		else if (ft_strcmp("translate", e->s_tmp) == 0)
			e->p_atb.translate++;
		else
			return (58); // wrong param in plane
		// printf("normal : [%d] - d : [%d] - diff : [%d] - refl :[%d] - sval :[%d] - spow : [%d]\n", e->p_atb.normal, e->p_atb.d, e->p_atb.diffusion, e->p_atb.reflection, e->p_atb.specvalue, e->p_atb.specpower);
	}
	return (0);
}

int		verify_line(t_env *e, char *line)
{
	char	**split_test;
	char	*split_tabless;

	split_test = ft_strsplit(line, ' ');
	e->str_count = ft_countstrings(split_test);
	if (e->p.specs == 1 && e->p.scene == 1 && e->p.objects == 0)
	{
		split_tabless = ft_strtrim(split_test[0]);
		if (ft_charfreq(line, '\t') < 2 || ft_charfreq(line, '\t') > 3)
			return (5);
		if (ft_charfreq(line, '\t') == 2)
			if ((e->ret_tmp = two_tabs_specs(e, split_test, split_tabless)) != 0)
				return (e->ret_tmp);
		if (ft_charfreq(line, '\t') == 3)
			if ((e->ret_tmp = threetab_verifications(e, split_test)) != 0)
				return (e->ret_tmp);
	}
	else if (e->p.specs == 1 && (e->p.scene != 1 || e->p.objects != 0))
		return (4);
	if (e->p.objects == 1 && e->p.specs == 2 && e->p.scene == 1)
	{
		split_tabless = ft_strtrim(split_test[0]);
		if (ft_charfreq(line, '\t') < 2 || ft_charfreq(line, '\t') > 3)
			return (5);
		if (ft_charfreq(line, '\t') == 2)
		{
			if ((e->ret_tmp = twotab_verifications(e, split_test)) != 0)
				return (e->ret_tmp);
		}
		if (ft_charfreq(line, '\t') == 3)
		{
			if ((e->ret_tmp = threetab_verifications(e, split_test)) != 0)
				return (e->ret_tmp);
			if ((e->ret_tmp = shapevocab_checker(e, split_test)) != 0)
				return (e->ret_tmp);
		}
	}
	else if (e->p.objects == 1 && (e->p.scene != 1 || e->p.specs != 2))
		return (4);
	ft_delsplit(split_test);
	free(split_tabless);
	split_tabless = NULL;
	return (0);
}

int		last_checks(t_env *e)
{
	if (e->p.objects != 2 || e->p.specs != 2) // change the error number
		return (8); // change error message
	if (e->p.scene != 2)
		return (6);
	if (e->p.spec_order < 3)
		return(26);
	if ((e->count.spheres + e->count.planes + e->count.cones + e->count.cylinders) == 0)
		return(59);
	if ((ft_iseven(e->spcs.light)) == -1)
		return(27);
	if ((ft_iseven(e->p_obj.sphere)) == -1)
		return(34);
	if ((ft_iseven(e->p_obj.cone)) == -1)
		return(34);
	if ((ft_iseven(e->p_obj.cylinder)) == -1)
		return(34);
	if ((ft_iseven(e->p_obj.plane)) == -1)
		return(34);
	if (e->spcs.cam != 2 || e->spcs.amb != 2)
		return (37);
	if (e->ret.gnl == -1)
		return (1);
	printf("VALID!\n");
	return (0);
}

// need to add verifier for shape requirements ! i.e. it needs to fufill it's vocab neccessary for each shape

int		parser(t_env *e, int fd)
{
	t_ll	*head;

	head = NULL;
	while ((e->ret.gnl = get_next_line(fd, &e->p.gnl_line)) > 0)
	{
		e->p.gnl_i++;
		if ((e->ret.glo = globals(e, e->p.gnl_line)) != 0)
			return (e->ret.glo);
		if ((e->p.objects == 1 || e->p.specs == 1) && !e->p.skip && ((e->ret.tag = verify_line(e, e->p.gnl_line)) != 0))
			return (e->ret.tag);
		if (e->p.gnl_line)
		{
			free(e->p.gnl_line);
			e->p.gnl_line = NULL;
		}
	}
	e->ll = head;
	return (last_checks(e));
}
//	if ((add_link(gnl_line, &head, e, i)) == -1)
//		return (-1);
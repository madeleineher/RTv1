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
		if ((e->p.ret_p = verifyanglebrackets_three(e, split_test)) == -1)
			return (17);
		if ((e->p.ret_p = verifyvocab_three(e, split_test)) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = verifyargs_three(e, split_test)) != 0) // store data here
			return (e->p.ret_p);
	}
	else if (e->str_count == 1) // ONE ~~~~~~~~~~ in verifythree.c
	{
		if ((e->p.ret_p = verifyanglebrackets_one(e)) == -1)
			return (17);
		if ((e->p.ret_p = verifyvocab_one(e)) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = verifyargs_one(e)) != 0) // store data here
			return (e->p.ret_p);
	}
	else
		return (17);
	return (0);
}

int		verify_line_seg_one(t_env *e, char **split_test, char *line)
{
	if (ft_charfreq(line, '\t') < 2 || ft_charfreq(line, '\t') > 3)
		return (5);
	if (ft_charfreq(line, '\t') == 2)
		if ((e->p.ret_p = two_tabs_specs(e, split_test)) != 0)
			return (e->p.ret_p);
	if (ft_charfreq(line, '\t') == 3)
	{
		if ((e->p.ret_p = verify_spec_atb(e, split_test)) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = threetab_verifications(e, split_test)) != 0)  // will need to send main env *e here !
			return (e->p.ret_p);
	}
	return (0);
}

int		verify_line_seg_two(t_env *e, char **split_test, char *line)
{
	// tabless = ft_strtrim(split_test[0]);
	if (ft_charfreq(line, '\t') < 2 || ft_charfreq(line, '\t') > 3)
		return (5);
	if (ft_charfreq(line, '\t') == 2)
	{
		if ((e->p.ret_p = twotab_verifications(e, split_test)) != 0)
			return (e->p.ret_p);
	}
	if (ft_charfreq(line, '\t') == 3)
	{
		if ((e->p.ret_p = shapevocab_checker(e, split_test)) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = threetab_verifications(e, split_test)) != 0) // will need to send main env *e here !
			return (e->p.ret_p);
	}
	return (0);
}

int		verify_line(t_env *e, char *line)
{
	char	**split_test;

	split_test = ft_strsplit(line, ' ');
	e->str_count = ft_countstrings(split_test);
	if (e->p.specs == 1 && e->p.scene == 1 && e->p.objects == 0)
	{
		if ((e->p.ret_p = verify_line_seg_one(e, split_test, line)) != 0)
			return (e->p.ret_p);
	}
	else if (e->p.specs == 1 && (e->p.scene != 1 || e->p.objects != 0))
		return (4);
	if (e->p.objects == 1 && e->p.specs == 2 && e->p.scene == 1)
	{
		if ((e->p.ret_p = verify_line_seg_two(e, split_test, line)) != 0)
			return (e->p.ret_p);
	}
	else if (e->p.objects == 1 && (e->p.scene != 1 || e->p.specs != 2))
		return (4);
	ft_delsplit(split_test);
	return (0);
}

int		last_checks(t_env *e)
{
	if (e->p.objects != 2 || e->p.specs != 2) // change the error number
		return (8); // change error message
	if (e->p.p_spec.cam_cl != 1 || e->p.p_spec.amb_cl != 1)
		return (26);
	if (e->p.scene != 2)
		return (6);
	if ((e->p.count.spheres + e->p.count.planes + e->p.count.cones + e->p.count.cylinders) == 0)
		return(59);
	if ((ft_iseven(e->p.p_spec.light)) == -1)
		return(27);
	if ((ft_iseven(e->p.p_obj.sphere)) == -1)
		return(34);
	if ((ft_iseven(e->p.p_obj.cone)) == -1)
		return(34);
	if ((ft_iseven(e->p.p_obj.cyn)) == -1)
		return(34);
	if ((ft_iseven(e->p.p_obj.plane)) == -1)
		return(34);
	if (e->p.p_spec.cam != 2 || e->p.p_spec.amb != 2)
		return (37);
	if (e->p.ret.gnl == -1)
		return (1);
	printf("VALID!\n");
	return (0);
}

// need to add verifier for specs requirements ! 
// i.e. it needs to fufill it's vocab neccessary for each type of spec

int		parser(t_env *e, int fd)
{
	t_ll	*head;
	//t_parser *p; // create parser structure here ! and then send parser everywhere !

	head = NULL;
	while ((e->p.ret.gnl = get_next_line(fd, &e->p.gnl_line)) > 0)
	{
		e->p.gnl_i++;
		if ((e->p.ret.glo = globals(e, e->p.gnl_line)) != 0)
			return (e->p.ret.glo);
		if ((e->p.objects == 1 || e->p.specs == 1) && !e->p.skip && ((e->p.ret.tag = verify_line(e, e->p.gnl_line)) != 0))
			return (e->p.ret.tag);
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
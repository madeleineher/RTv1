/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:23:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/29 13:23:57 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		globals(t_env *e, char *gnl_line)
{
	int 	ret_tmp = 0;
	int		ret_tabs = 0;
	char	*tabless;

	e->p.skip = 0;
	ret_tabs = ft_charfreq(gnl_line, '\t');
	tabless = ft_strtrim(gnl_line);
	if ((ft_strcmp("<scene>", tabless) == 0) && ret_tabs == 0)
		e->p.scene += 1;
	if (ft_strcmp("</scene>", tabless) == 0 && ret_tabs == 0)
		e->p.scene += 1;
	if (ft_strcmp("<specs>", tabless) == 0 && ret_tabs == 1)
	{
		e->p.specs += 1;
		e->p.skip = 1;
	}
	if (ft_strcmp("</specs>", tabless) == 0 && ret_tabs == 1)
		if ((ret_tmp = open_close(&e->p.specs)) != 0)
			return (ret_tmp);
	if (ft_strcmp("<objects>", tabless) == 0 && ret_tabs == 1)
	{
		e->p.objects += 1;
		e->p.skip = 1;
	}
	if (ft_strcmp("</objects>", tabless) == 0 && ret_tabs == 1)
		if ((ret_tmp = open_close(&e->p.objects)) != 0)
			return (ret_tmp);
	return (0);
}

int		verify_cam_amb(t_env *e, char **split_test, char *split_tabless)
{
	int	ret;

	ret = 0;
	if (e->p.spec_order == 0)
	{
		if (ft_strcmp("<cam", split_tabless) != 0)
			return (10);
		e->spcs.cam = 1;
		if ((ret = extract_status(e, split_test)) != 0)
			return (ret);
		e->cam.status = e->p.status;
		e->p.current_tag = "cam";
	}
	if (e->p.spec_order == 1)
	{	
		if (ft_strcmp("<amb", split_tabless) != 0)
			return (11);
		e->spcs.amb = 1;
		if ((ret = extract_status(e, split_test)) != 0)
			return (ret);
		e->amb.status = e->p.status;
		e->p.current_tag = "amb";
	}
	return (ret);
}

int		verify_light(t_env *e, char **split_test, char *split_tabless)
{
	int	ret;

	ret = 0;
	if (ft_strcmp("<light", split_tabless) != 0)
		return (12);
	e->spcs.light += 1;
	if (ft_iseven(e->spcs.light) == 0)
		return (12);
	if ((ret = extract_status(e, split_test)) != 0)
		return (ret);
	e->p.current_tag = "light";
	return (ret);
}

int		verify_closing_tags_specs(t_env *e, char *split_tabless)
{
	int		ret;

	ret = 0;
	if (e->p.spec_order == 1)
	{
		if ((ret = ft_strcmp("</cam>", split_tabless)) != 0)
			return (10);
		open_close(&e->spcs.cam);
	}
	if (e->p.spec_order == 2)
	{
		if ((ret = ft_strcmp("</amb>", split_tabless)) != 0)
			return (11);
		open_close(&e->spcs.amb);
	}
	if (e->p.spec_order >= 3)
	{
		if ((ret = ft_strcmp("</light>", split_tabless)) != 0)
			return (12);
		open_close(&e->spcs.light);
		if (ft_iseven(e->spcs.light) == -1)
			return (29);
	}
	return (0);
}

int		two_tabs_specs(t_env *e, char **split_test, char *split_tabless)
{
	int	ret_tmp;

	ret_tmp = 0;
	if ((ret_tmp = two_angle_brackets(e)) != 2)
		return (9);
	if (e->str_count == 4)
	{
		if (e->p.spec_order == 0 || e->p.spec_order == 1)
			if ((ret_tmp = verify_cam_amb(e, split_test, split_tabless)) != 0)
				return (ret_tmp);
		if (e->p.spec_order >= 2)
			if ((ret_tmp = verify_light(e, split_test, split_tabless)) != 0)
				return (ret_tmp);
	}
	else if (e->str_count == 1)
	{
		if ((ret_tmp = verify_closing_tags_specs(e, split_tabless)) != 0)
			return (ret_tmp);
	}			
	else if (e->str_count != 1 || e->str_count != 4)
		return (13);
	e->p.spec_order += (e->str_count == 4 ? 1 : 0);
	return (0);
}

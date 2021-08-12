/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:28:52 by mflor             #+#    #+#             */
/*   Updated: 2021/03/10 19:32:05 by mflor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	txts2(t_cub *mycub)
{
	if (!(mycub->wet->addr = (unsigned int *)mlx_get_data_addr(mycub->wet->img,
					&mycub->wet->bpp, &mycub->wet->ll, &mycub->wet->end)))
		ft_error(-11);
	if (!(mycub->sot->img = mlx_xpm_file_to_image(mycub->vs->mx, mycub->so,
					&mycub->sot->w, &mycub->sot->h)))
		ft_error(-10);
	if (!(mycub->sot->addr = (unsigned int *)mlx_get_data_addr(mycub->sot->img,
					&mycub->sot->bpp, &mycub->sot->ll, &mycub->sot->end)))
		ft_error(-11);
	if (!(mycub->st->img = mlx_xpm_file_to_image(mycub->vs->mx, mycub->s,
					&mycub->st->w, &mycub->st->h)))
		ft_error(-10);
	if (!(mycub->st->addr = (unsigned int *)mlx_get_data_addr(mycub->st->img,
					&mycub->st->bpp, &mycub->st->ll, &mycub->st->end)))
		ft_error(-11);
	if (!checkmap(mycub))
		ft_close(4);
}

void		txts(t_cub *mycub)
{
	if (mycub->carg != 726)
		ft_error(-7);
	if (!(mycub->eat->img = mlx_xpm_file_to_image(mycub->vs->mx,
					mycub->ea, &mycub->eat->w, &mycub->eat->h)))
		ft_error(-10);
	if (!(mycub->eat->addr = (unsigned int *)mlx_get_data_addr(mycub->eat->img,
					&mycub->eat->bpp, &mycub->eat->ll, &mycub->eat->end)))
		ft_error(-11);
	if (!(mycub->not->img = mlx_xpm_file_to_image(mycub->vs->mx,
					mycub->no, &mycub->not->w, &mycub->not->h)))
		ft_error(-10);
	if (!(mycub->not->addr = (unsigned int *)mlx_get_data_addr(mycub->not->img,
					&mycub->not->bpp, &mycub->not->ll, &mycub->not->end)))
		ft_error(-11);
	if (!(mycub->wet->img = mlx_xpm_file_to_image(mycub->vs->mx, mycub->we,
					&mycub->wet->w, &mycub->wet->h)))
		ft_error(-10);
	txts2(mycub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lancement_raycasting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_stop_focus(t_parsage *pars)
{
	pars->mouv.cam_droite = 0;
	pars->mouv.cam_gauche = 0;
	pars->mouv.droite = 0;
	pars->mouv.gauche = 0;
	pars->mouv.avant = 0;
	pars->mouv.arriere = 0;
	pars->mouv.sup = 0;
	return (1);
}

int	protocole_draw(t_parsage *pars)
{
	ft_de_clik(2021, pars);
	ft_protocol_raycasting(pars);
	ft_init_ray_dist_trie(pars, pars->perso);
	mlx_put_image_to_window(pars->mlx.mlx, pars->mlx.window,
		pars->mlx.img.struct_img, 0, 0);
	mlx_hook(pars->mlx.window, 2, 1L << 0, ft_clik, pars);
	mlx_hook(pars->mlx.window, 3, 1L << 1, ft_de_clik, pars);
	mlx_loop_hook(pars->mlx.mlx, ft_protocol_raycasting, pars);
	mlx_hook(pars->mlx.window, 17, 1L << 17, ft_close_programe, pars);
	mlx_hook(pars->mlx.window, 10, 1L << 21, ft_stop_focus, pars);
	mlx_loop(pars->mlx.mlx);
	return (1);
}

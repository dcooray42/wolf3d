/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 08:22:55 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:22:56 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_fmod	*init_fmod(t_env *e)
{
	t_fmod	*fmod;

	if (!(fmod = (t_fmod *)ft_memalloc(sizeof(t_fmod))))
		malloc_error(e);
	fmod->music = NULL;
	fmod->scream = NULL;
	fmod->result |= FMOD_System_Create(&fmod->system);
	fmod->result |= FMOD_System_Init(fmod->system, 1, FMOD_INIT_NORMAL, NULL);
	fmod->result |= FMOD_System_CreateSound(fmod->system, "./music/bnha.mp3",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &fmod->music);
	fmod->result |= FMOD_System_CreateSound(fmod->system, "./music/XD.mp3",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &fmod->scream);
	fmod->result |= FMOD_Sound_SetLoopCount(fmod->music, -1);
	fmod->result |= FMOD_Sound_SetLoopCount(fmod->scream, -1);
	fmod->result |= FMOD_System_PlaySound(fmod->system, fmod->music, NULL,
		FALSE, &fmod->channel);
	fmod->result |= FMOD_Channel_GetPaused(fmod->channel, &fmod->state);
	return (fmod);
}

void	fmod_error(t_env *e)
{
	if (e->fmod->result != FMOD_OK)
	{
		ft_printf("Error: FMOD error\n");
		delete_env(e);
		exit(EXIT_SUCCESS);
	}
}

void	delete_fmod(t_fmod *fmod)
{
	if (fmod->music)
		FMOD_Sound_Release(fmod->music);
	if (fmod->scream)
		FMOD_Sound_Release(fmod->scream);
	if (fmod->system)
	{
		FMOD_System_Close(fmod->system);
		FMOD_System_Release(fmod->system);
	}
	ft_memdel((void **)&fmod);
}

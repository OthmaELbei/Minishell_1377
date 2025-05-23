/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbied <oelbied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:54:41 by oelbied           #+#    #+#             */
/*   Updated: 2025/04/20 14:51:50 by oelbied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


void ft_echo(t_data *data)
{
	
	int i = 2;
	int j = 1;
	t_list *head = NULL;

	if (!ft_strcmp(data->args[0],"echo") && !ft_strcmp(data->args[1],"-n"))
	{
        while (data->args[i] != NULL)
		{
			printf("%s",data->args[i]);
			i++;
			if( data->args[i] != NULL)
			{
				printf(" ");
			}
		}
		
	}
	else if(!ft_strcmp(data->cmd,"echo"))
	{
		t_data *time = data;	
		while (time->args[j] != NULL) 
		{
			printf("%s",time->args[j]);
			j++;
				if(time != NULL)
				{
					printf(" ");
				}
		}
	 	printf("\n");
	}

}
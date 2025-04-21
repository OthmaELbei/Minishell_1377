/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbied <oelbied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:24:15 by oelbied           #+#    #+#             */
/*   Updated: 2025/04/20 09:00:48 by oelbied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_env(char **env, t_listenv **head)
{
	// t_listenv *head = NULL;
	int i = 0;
	int k = 0;
	int j;
	int g =0;
	int l =0;
	char	**tow_pt;

	while(env[i])
	{
		j = 0;
		k = 0;
		
		while (env[i][j] != '\0')
		{
		j++;
		if(env[i][j] == '=')
			break;
		}
		char *str = (char *)malloc((j + 1) * sizeof(char));
		j = 0;
		while (env[i][j] != '\0')
		{
			str[k] = env[i][j];
			k++;
			if(env[i][j] == '=')
				break;
		j++;
		}
		str[k] = '\0';
		l = j + 1;
		while (env[i][j])
		{
			j++;
			g++;
		}
		char *pat = (char *)malloc((g + 1) * sizeof(char));
		int d = 0;
		while (env[i][l])
		{
			pat[d] = env[i][l];
			d++;
			l++;
		}
		pat[d]= '\0';
		// printf("%s\n",pat);
		
		// ft_lstadd_back(&head,ft_lstnew(str));
		ft_lstadd_back_ex(head,ft_lstnew_env(str,pat));
		
	
		// free(str);
			// write(1,"\n",1);
		
		// printf("%s\n",env[i]);
		i++;
	}
	
		// int p = 0;
		// int d = ft_lstsize(*head);
		// char	**to_pt = (char **)malloc(sizeof(char *) * (d + 1));
	
		// 	t_listenv *joune = *head;
		
		// 	while(joune)
		// 	{
		// 		char *conts = joune->constvrble;
		// 		char *pats = joune->pat;
		// 		char *opreter_joun = ft_strjoin(conts,pats);
		// 		int lines = ft_strlen(opreter_joun) + 1;
		// 		to_pt[p] = (char *)malloc(sizeof(char) * (lines));
		// 		ft_strlcpy(to_pt[p], opreter_joun, lines);
		// 		p++;
		// 		joune = joune->next;
		// 	}
		// to_pt[p] = NULL;
	// 	p =0;
	// while(to_pt[p])
	// {
	//   printf("%s------------------\n",to_pt[p]);
	//   p++;	
	// }
	// 	printf("%d",d);
	// return to_pt;
}

// int main(int ac,char **av, char **env)
// {
	
// 	t_listenv *head = NULL;
// 	ft_env(env ,&head);
		
// }
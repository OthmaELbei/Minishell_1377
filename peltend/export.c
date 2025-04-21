/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbied <oelbied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:53:17 by oelbied           #+#    #+#             */
/*   Updated: 2025/04/20 20:20:51 by oelbied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	ft_strcmp(const char *s1, const char *d2)
// {
// 	size_t	i;

// 	i = 0;
// 	if ((!s1 || !d2) )
// 		return (0);
// 	while (s1[i] == d2[i] && s1[i] && d2[i] )
// 	{
// 		i++;
// 	}
// 	return ((unsigned char)s1[i] - (unsigned char)d2[i]);
// }

// int main(int ac , char **av , char **env)
// {
void ft_export(t_listenv **head, t_data *data)
{
	int i = 0;
	int j = 0;
	int d = 0;
	int k = 0;
	// t_listenv *head = NULL;
	//  ft_env(env ,&head);
	t_listenv *joune;
	joune = *head;
	char *stralfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";
	// char *input = readline("Enter command: ");
	// char **str = ft_split(input , ' ');
	int x = 1;
	while(data->args[x] )
	{
	int t = 0;
	 int flags = 0;
	 char *juny;
	char **splt_egal = ft_split(data->args[x],'=');
	char **splt_plus = ft_split(data->args[x],'+');
				char *pats = "";
		if(thcking_pluss(data->args[x]) || tchking_egal(data->args[x]))
		{
			while (data->args[x][t] != '\0')
		{
			if( data->args[x][t] == '=' && data->args[x][t +  1] == '\0')
		{
			if(ft_strchr(data->args[x],'+'))
			{
     			juny = ft_strjoin(splt_plus[0], "=");
			} else if( tchking_egal(data->args[x]))
			{
				juny = ft_strjoin(splt_egal[0], "=");
			} 
			joune = *head;
			t_listenv *findd =NULL;
			while(joune)
			{
				if(!ft_strcmp(joune->constvrble,juny))
				{
					flags = 1;
					findd = joune;
					break;
				}
				joune = joune->next;
			}
			if(flags == 0){
			ft_lstadd_back_ex(head,ft_lstnew_env(juny,pats));
			printf("good");
			}else if(flags == 1 && findd){
				joune->pat = "\"\"++++";
			}
			printf("fhdnjdndncdj\n");
		}
		else if(data->args[x][t - 1] == '+' && data->args[x][t] == '=' && data->args[x][t + 1] != '\0')
		{
			
			int nm = 0 ;
			int line = 0 ;
			while(data->args[x][nm] != '=')
			{
				if(data->args[x][nm] != '+')
				{
					line++;
				}
				nm++;
			}
			char *steegal = (char *)malloc(line + 1);
			line += 2;
			int intline = line;
			int kd = 0 ;
			while(data->args[x][line] != '\0')
			{
				line++;
				kd++;
			}
			char *strfinal = (char *)malloc(kd + 1);
			nm  = 0;
			while (data->args[x][nm] != '=')
			{
				if(data->args[x][nm] != '+')
					steegal[nm] = data->args[x][nm];
				nm++;
			}
			steegal[nm] = '\0';
			line = 0;
			while(data->args[x][intline] != '\0')
			{
				strfinal[line] = data->args[x][intline];
				 intline++;
				 line++;
			}
			strfinal[line] = '\0';
			
			char *djj = ft_strjoin(steegal,"=");
			joune = *head;
			t_listenv *findd =NULL;
			while(joune)
			{
				if(!ft_strcmp(joune->constvrble,djj))
				{
					flags = 1;
					findd = joune;
					break;
				}
				joune = joune->next;
			}
			if(flags == 0)
			{
				printf("fkbjfn\n");
				ft_lstadd_back_ex(head,ft_lstnew_env(djj,strfinal));
			}else if(flags ==  1 && findd)
			{
				if(!ft_strcmp(findd->pat,splt_egal[1]))
				{
					printf("%s================================\n",splt_egal[1]);
				}else
				{
					char *jun_pat =  ft_strjoin(findd->pat,splt_egal[1]);
					findd->pat = jun_pat;
					printf("%s++++++++++++++++++++\n",findd->pat);
					// ft_lstadd_back(&head,ft_lstnew_env(djj,strfinal));
				}
				
			}
			
			}else if(data->args[x][t - 1] != '+' && data->args[x][t] == '=' && data->args[x][t + 1] != '\0')
			{
	
			int nm = 0 ;
			int line = 0 ;
			while(data->args[x][nm] != '=')
			{
				if(data->args[x][nm] != '+')
				{
					line++;
				}
				nm++;
			}
			char *steegal = (char *)malloc(line + 1);
			line += 2;
			int intline = line;
			int kd = 0 ;
			while(data->args[x][line] != '\0')
			{
				line++;
				kd++;
			}
			char *strfinal = (char *)malloc(kd + 1);
			nm  = 0;
			while (data->args[x][nm] != '=')
			{
				if(data->args[x][nm] != '+')
					steegal[nm] = data->args[x][nm];
				nm++;
			}
			steegal[nm] = '\0';
			line = 0;
			while(data->args[x][intline] != '\0')
			{
				strfinal[line] = data->args[x][intline];
				 intline++;
				 line++;
			}
			strfinal[line] = '\0';
			
			char *djj = ft_strjoin(steegal,"=");
			joune = *head;
			t_listenv *findd =NULL;
			while(joune)
			{
				if(!ft_strcmp(joune->constvrble,djj))
				{
					flags = 1;
					findd = joune;
					break;
				}
				joune = joune->next;
			}
			if(flags == 0)
			{
				printf("fkbjfn\n");
				ft_lstadd_back_ex(head,ft_lstnew_env(djj,strfinal));
			}else if(flags ==  1 && findd)
			{
				if(!ft_strcmp(findd->pat,splt_egal[1]))
				{
					printf("%s================================\n",splt_egal[1]);
				}else
				{
					// char *jun_pat =  ft_strjoin(findd->pat,splt_egal[1]);
					findd->pat = splt_egal[1];
					printf("%s=====================\n",findd->pat);
					// ft_lstadd_back(&head,ft_lstnew_env(djj,strfinal));
				}
				
			}
				
			}
			t++;
		}
	}
		x++;
	}
    
	// char **splt_plus = ft_split(str[1],'+');
	
	// while (str[1][t] != '\0')
	// {
	// 	// if(str[1][t] == '=' && str[1][t +  1] == '\0')
	// 	// {
    //  	// 	juny = ft_strjoin(splt_plus[0], "=");
	// 	// 	while(joune)
	// 	// 	{
	// 	// 		if(!ft_strcmp(joune->constvrble,juny))
	// 	// 		{
	// 	// 			flags = 1;
	// 	// 		}
	// 	// 		joune = joune->next;
	// 	// 	}
	// 	// 	if(flags == 0){
	// 	// 		char *pat = "\"\"";
	// 	// 	ft_lstadd_back(&head,ft_lstnew_env(juny,pat));
	// 	// 	printf("good");
	// 	// 	}
	// 	// 	printf("fhdnjdndncdj\n");
	// 	// }
	// 	 if(str[1][t] == '=' && str[1][t +  1] != '\0')
	// 	{
	// 			juny = ft_strjoin(splt_plus[0], "=");
	// 			while(joune)
	// 		{
	// 			if(!ft_strcmp(joune->constvrble,juny))
	// 			{
	// 				flags = 1;
	// 			}
	// 			joune = joune->next;
	// 		}
	// 		if(flags == 0){
	// 			// char *pat = "\"\"";
	// 		ft_lstadd_back(&head,ft_lstnew_env(juny,splt_plus[1]));
	// 		printf("good");
	// 		}
	// 	}
	// 	t++;
	// }
	int f = 0;
	//  printf("%s\n",juny);
	// while(splt_plus && splt_plus[f])
	// {
	// 	printf("%s\n",splt_plus[f]);
	// 	f++;
	// }
    // int lin_of_egal = 0;
	// while(str[1] != '\0')
	// {
	// 	lin_of_egal++;
	// 	if(str[1] == '=')
	// 		break;
	// }
	
	
	// while(joune)
	// {
	// 	char *conts = joune->constvrble;
	// 	char *pats = joune->pat;
	// 	char *opreter_joun = ft_strjoin(conts,pats);
		
		
	// 	joune = joune->next;
	// }
	// // while(str && str[i])
	// // {
	// //   printf("%s\n",str[i]);
	// //   i++;	
	// // }
  if(!ft_strcmp(data->args[0],"export"))
	{
		while (stralfa[d])
		{
			i = 0;
			t_listenv *tmp = *head;
			while (tmp)
			{
				j = 0;
				k = 0;
				// if(stralfa[d] == env[i][j])
				char *strr = tmp->constvrble;
				
				if(stralfa[d] == strr[0])
				{
					char *consdt = ft_tchk_cotachen(tmp->constvrble);
					char *pats_cotch = ft_tchk_cotachen(tmp->pat);
					printf("%s\"%s\"\n",consdt,pats_cotch);
					free(consdt);
					free(pats_cotch);
					// printf("%s\n++++++",consdt);	
				
					// write(1,"\n",1);
				}
				tmp = tmp->next;
				i++;
			}
			// while(ery_env[i])
			// {
			// 	if(stralfa[d] == ery_env[i][0])
			// 	{
			// 			printf("%s\n",ery_env[i]);
				
			// 	}
			// i++;
			// }
			d++;	
		}
	}
	
}

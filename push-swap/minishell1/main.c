/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:46:51 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/17 17:28:03 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"


void sig_handler(int signal)
{
	if(signal == SIGINT)
		printf("\nminishell42~>");
	else if(signal == SIGTERM)
		exit(-1);
	else
		printf("the program does not respond specifically to other signals.");
}
void setting_signal()
{
	signal(SIGINT, sig_handler);  // CTRL + C
	signal(SIGTERM, sig_handler); // CTRL + D
	signal(SIGQUIT, sig_handler); // CTRL + /
}

int main(int ac, char **av, char **envp)
{
	char *line;

	sitting_signal();
	while(1)
	{
		line = readline("minishell42~> ");
		add_history(line);
		free(line);
	}
	return (0);
}

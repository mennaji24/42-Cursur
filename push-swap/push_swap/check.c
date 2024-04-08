/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:47:06 by mennaji           #+#    #+#             */
/*   Updated: 2023/07/07 19:55:44 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

int	ft_contains(int num, char **av, int i)
{
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	ptr;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		ptr = ft_atoi(args[i]);
		if (!ft_check_num(args[i]))
			ft_error("Error\n");
		if (!ft_contains(ptr, args, i))
			ft_error("Error\n");
		if (ptr < -2147483648 || ptr > 2147483647)
			ft_error("Error\n");
		i++;
	}
	if (argc == 2)
		free(args);
}

int	check_duplicate(t_list *stack)
{
	int		tmp;
	t_list	*dup;

	while (stack && stack->next)
	{
		tmp = stack->value;
		dup = stack;
		while (dup->next)
		{
			dup = dup->next;
			if (dup->value == tmp)
				return (-1);
		}
		stack = stack->next;
	}
	return (1);
}

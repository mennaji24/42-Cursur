/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:13 by mennaji           #+#    #+#             */
/*   Updated: 2023/07/07 20:05:30 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_init(t_list **stack, int argc, char **argv)
{
	t_list	*new_node;
	char	**args;
	int		i;

	i = 0;
	args = NULL;
	if (argc == 2)
		args = ft_split(argv[i], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new_node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new_node);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		free(args);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **) malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_stack_init(stack_a, argc, argv);
	if (check_duplicate(*stack_a) == -1)
		ft_error("Error\n");
	if (is_sorted(stack_a))
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	printlist(*stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}

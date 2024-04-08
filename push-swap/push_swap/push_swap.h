/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:58:27 by mennaji           #+#    #+#             */
/*   Updated: 2023/07/07 20:10:38 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
    int value;
    int index;
    struct s_list *next;
}t_list;


t_list	*ft_lstnew(int value);
void    ft_stack_init(t_list **stack, int argc, char **argv);
int check_duplicate(t_list *stack);
void	ft_error(char *msg);
void	ft_lstadd_front(t_list **stack, t_list *new);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **stack, t_list *new);
int	ft_lstsize(t_list *head);
void	printlist(t_list *head);
int ft_contains(int num, char **av, int i);
int ft_check_num(char *num);
void ft_check_args(int argc, char **argv);
t_list *get_themin(t_list **stack);
void  index_stack(t_list **stack);
void ft_stackInit(t_list **stack, int argc, char **argv);
int	ft_isdigit(char arg);
int	ft_isspace(int c);
int	ft_atoi(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	count_word(const char *s, char c);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putchar_fd(char c, int fd);
int	ft_abs(int nbr);
void	*ft_bzero(void *s, size_t len);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int	get_min(t_list **stack, int val);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);
int	get_max_bits(t_list **stack);
void	radix_sort(t_list **stack_a, t_list **stack_b);
int	swap(t_list **stack);
int	sa(t_list **stack_a);
int	sb(t_list **stack_b);
int	ss(t_list **stack_a, t_list **stack_b);
int	push(t_list **stack_to, t_list **stack_from);
int	pa(t_list **stack_a, t_list **stack_b);
int	pb(t_list **stack_a, t_list **stack_b);
int	rotate(t_list **stack);
int	ra(t_list **stack_a);
int	rb(t_list **stack_b);
int	rr(t_list **stack_a, t_list **stack_b);
int	reverse_rotate(t_list **stack);
int	rra(t_list **stack_a);
int	rrb(t_list **stack_b);
int	rrr(t_list **stack_a, t_list **stack_b);
int	is_sorted(t_list **stack);
int	get_distance(t_list **stack, int index);
void	ft_putendl_fd(char *str, int fd);

#endif

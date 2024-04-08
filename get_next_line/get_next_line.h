/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:58:12 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/22 16:56:37 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_read_line(int fd, char *box);
char	*ft_get_line(char *buckup);
char	*ft_clean(char *str);

//# ifndef BUFFER_SIZE
//# define BUFFER_SIZE 1
//# endif

#endif

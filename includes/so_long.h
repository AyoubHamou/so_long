/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:17:55 by ahamou            #+#    #+#             */
/*   Updated: 2023/02/25 17:57:41 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_elts
{
	int				e;
	int				c;
	int				width;
	int				height;
	int				x;
	int				y;
	int				p;
	int				mv;
	size_t			len;
	char			**map;
	struct s_main	*main;
}	t_elts;

typedef struct s_main
{
	void	*init;
	void	*win;
	void	*img;
}	t_main;

/*=================Sources=====================*/
void	mlx_funcs(char **map, t_elts *elts, t_main *main);
int		ft_up(t_elts *elts);
int		ft_down(t_elts *elts);
int		ft_right(t_elts *elts);
int		ft_left(t_elts *elts);
char	**read_map(char *av, int i);
size_t	map_lenght(char **map);
void	map_characters(char **map, int i, t_elts *elts);
void	map_borders(char **map, size_t len, t_elts *elts);
void	valid_path(char **map, t_elts	*elts);
char	*which_path(char c);
void	display_map(char **map, t_main *main, t_elts *elts);
int		moves(int key, t_elts *elts);
int		cross(void *b);
/*==================Utils======================*/
int		error_message(char *str);
void	ft_free(char **str);
char	*read_line(int fd);

/*==================Libft======================*/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char *s, char c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	ft_swap(char *a, char *b);
void	ft_putnbr(int n);
char	*ft_itoa(int n);

#endif
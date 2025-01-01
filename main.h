/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:18:42 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/27 11:01:02 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

# define IMG_SIZE 32
# define ESC 65307
# define FPS 10500
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct mlx_vars {
	void	*mlx;
	void	*win;
	void	*img;
	void	*player_n;
	void	*player_e;
	void	*player_w;
	void	*player_s;
	void	**coin_frames;
	void	*background;
	char	**grid;
	void	*enemy;
	int		pos_x;
	int		pos_y;
	int		player_grid_x;
	int		player_grid_y;
	int		**coin_pos;
	int		ttl_coins;
	int		ttl_zeros;
	int		coins_collected;
	int		move_count;
	int		frame_rate;
	int		frame_count;
	int		current_frame;	
	void	*exit;
	int		exit_x;
	int		exit_y;
	void	*wall;
	int		e_count;
	int		p_count;
	int		c_count;
	int		total_zeros;
	int		coin_index;
	int		ls_c;
	int		l_len;
	int		new_exit;
	char	*str;
}	t_mlx;

int		ft_printf(const char *s, ...);
int		ft_putchar_ft(char c);
int		ft_putstr_ft(char *s);
int		ft_putnbr_unsigned_ft(unsigned int n);
int		ft_putnbr_ft(int n);
int		ft_putnbr_hexa_c_ft(unsigned int n);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
int		valid_map(t_mlx *vars, char *map);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
int		basic_map_check(t_mlx *vars);
int		standard_map_check(t_mlx *vars);
int		deep_map_check(t_mlx *vars, int lines, int line_len);
void	error_handling(int error);
void	free_arr(char **arr);
void	init_basic_vars(t_mlx *vars, int ls_c, int l_len);
void	force_free_grid(int fd, char *grid, char *path);
int		valid_map(t_mlx *vars, char *map);
int		check_map_file(t_mlx *vars, char *path);
void	simple_grid_check(int fd, char *grid);
void	init_game(t_mlx *vars);
void	image_err_free(t_mlx *vars);
int		close_window(t_mlx *vars);
void	destroy_sprites(t_mlx *vars);
void	free_vars(t_mlx *vars);
void	putgrid(t_mlx *vars);
int		keyboard_hooks(int keycode, t_mlx *vars);
void	pre_load_sprites(t_mlx *vars);
void	init_sprites(t_mlx *vars);
int		on_game_update(t_mlx *n);
void	player_movement(t_mlx *vars, char c, int inter, char direction);
void	free_arr(char **arr);
char	*ft_itoa(int n);
void	intput_movecount(t_mlx *vars);

#endif
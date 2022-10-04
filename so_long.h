#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS 2
# define KEY_W 13   
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_pos
{
	int	x;
	int	y;
	int keycode;
}	t_pos;

typedef struct s_test
{
	int	width;
	int	height;
	int	count_c;
	int	count_e;
	int	count_p;
}	t_test;

typedef struct s_image{
    void    *wall;
    void    *tile;
    void    *coin;
    void    *player;
    void    *exit;
}   t_img;

typedef struct	s_game
{
	struct s_test tmp;
	struct s_pos	pos;
	struct s_image	img;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
}	t_game;

void	draw(t_game *game);
int	valid_mid(t_test *tmp, char *str, int len);
int	valid_first(char *str, int len);
int	valid_map(char *title, t_game *game);
void	init_test(t_test *tmp);
char	*get_next_line(int fd);
char	*read_line(int fd, char *backup);
char	*return_right(char *backup);
char	*return_left(char *backup);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int key_press(int keycode,t_game *game);
void pos_init(t_pos *pos);
void	valid_move(t_game *game);
void	back_pos(t_game *game);

#endif

#include "so_long.h"

void	init_test(t_test *tmp)
{
	tmp->width = 0;
	tmp->height = 0;
	tmp->count_c = 0;
	tmp->count_e = 0;
	tmp->count_p = 0;
}

int	valid_first(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_mid(t_test *tmp, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == 'C')
		{
			(tmp->count_c)++;
			i++;
			continue ;
		}
		if (str[i] == 'E')
		{
			(tmp->count_e)++;
			i++;
			continue ;
		}
		if (str[i] == 'P')
		{
			(tmp->count_p)++;
			i++;
			continue ;
		}
		if (str[i] != '0' && str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_map(char *title, t_game	*game)
{
	int		fd;
	char	*buf;

	if (!ft_strnstr(title, ".ber",1000))
		return (-1);
	else
	{
		fd = open(title, O_RDONLY);
		if (fd < 0)
			return (-1);

		buf = get_next_line(fd);
		game->tmp.width = ft_strlen(buf) - 1;

		if (!valid_first(buf, game->tmp.width))
			return (-1);
		while (buf)
		{
			printf("%s", buf);
			if (game->tmp.width != ft_strlen(buf) - 1)
			{
				printf("width Error\n");
				return (-1);
			}
			if (buf[0] != '1')
			{
				printf("first char is not wall\n");
				return (-1);
			}
			if (buf[ft_strlen(buf) - 2] != '1')
			{
				printf("last char is not wall\n");
				return (-1);
			}
			if (!valid_mid(&(game->tmp), buf, ft_strlen(buf) - 1))
			{
				printf("this\n");
				return (-1);
			}
			game->tmp.height++;
			buf = get_next_line(fd);
		}
		if (!(game->tmp.count_c && game->tmp.count_e && game->tmp.count_p))
		{
			printf("something is 0\n");
			return (0);
		}
		if (game->tmp.count_p > 1)
		{
			printf("player Error\n");
			return (0);
		}
		//printf("it's valid?\n");
		close(fd);
	}
	return (1);
}

char	**save_map(char *title, t_game *game)
{
	int		fd;
	int		i;
	char	**map;

	i = 0;
	fd = open(title, O_RDONLY);
	if (fd < 0)
		return (0);
	map = malloc(sizeof(char *) * game->tmp.height);
	while (i < game->tmp.height)
		map[i++] = get_next_line(fd);
	return (map);
}

void	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->tmp.width) * 32, (game->tmp.height) * 32, "so_long");
}

int	exit_game(int keycode, int x, int y, void *param)
{
	(void)keycode;
	(void)x;
	(void)y;

	exit(0);
}

int main(int argc, char **argv)
{
	t_game	game;

	init_test(&(game.tmp));
	pos_init(&(game.pos));

	if (argc != 2)
		return (0);
	else
	{
		if (!valid_map(argv[1], &game))
			return (0);
		game.map = save_map(argv[1], &game);
		game_init(&game);
		draw(&game);
		mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &game);
		mlx_hook(game.win_ptr, 17, 0, &exit_game, &game);
		//게임 종료할 때 exit만 해도되나? 메모리 해제하고 mlx 종료하고 그런거 안해도됨???
		mlx_loop(game.mlx_ptr);
	}
	return (0);
}

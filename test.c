#include "so_long.h"

void	init_test(t_test *tmp)
{
		printf("tmp i good\n");
	tmp->width = 0;
		printf("tmp in good\n");
	tmp->height = 0;
		printf("tmp ini good\n");
	tmp->count_c = 0;
		printf("tmp init good\n");
	tmp->count_e = 0;
		printf("tmp init! good\n");
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
				printf("tmp.width != ft_strlen(buf) - 1)");
				return (-1);
			}
			if (buf[0] != '1')
			{
				printf("buf[0] != 1");
				return (-1);
			}
			if (buf[ft_strlen(buf) - 2] != '1')
			{
				printf("buf[ft_strlen(buf) - 2] != 1");
				return (-1);
			}
			printf("it's valid\n");
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
		printf("it's valid?\n");
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
		printf("i good\n");
	game->mlx_ptr = mlx_init();
		printf("in good\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, 500, 500, "so_long");
		printf("ini good\n");
}

int main(int argc, char **argv)
{
	t_game	game;

	printf("good\n");
	game_init(&game);
	init_test(&(game.tmp));
	printf("init good\n");
	pos_init(&(game.pos));
	printf("game init good\n");
	
	if (argc != 2)
		return (0);
	else
	{
		if (!valid_map(argv[1], &game))
			return (0);
		printf("valid map good\n");
		game.map = save_map(argv[1], &game);
		printf("save map good\n");
		draw(&game);
		printf("draw good\n");
		mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &(game));
		mlx_loop(game.mlx_ptr);
	}
	return (0);
}

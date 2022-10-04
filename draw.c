#include "so_long.h"

void	draw(t_game *game)
{
	int	bit;
	int	i;
	int	j;
    int img_width;
    int img_height;
	static int flag;

    game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr, "./image/wall.xpm", &img_width, &img_height);
    game->img.tile = mlx_xpm_file_to_image(game->mlx_ptr, "./image/white.xpm", &img_width, &img_height);
    game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr, "./image/coin.xpm", &img_width, &img_height);
    game->img.player = mlx_xpm_file_to_image(game->mlx_ptr, "./image/player.xpm", &img_width, &img_height);
    game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr, "./image/exit.xpm", &img_width, &img_height);
	
	mlx_clear_window(game->mlx_ptr, game->win_ptr);	
	
	bit = 32;
	i = 0;
	j = 0;
	while (i < game->tmp.height)
	{	
		while (j < game->tmp.width)
		{
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.coin, j * bit, i * bit);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.exit, j * bit, i * bit);
			if (game->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.tile, j * bit, i * bit);
				if (flag == 0)
				{
					game->pos.x = j;
					game->pos.y = i;
					flag++;
				}
			}
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.wall, j * bit, i * bit);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.tile, j * bit, i * bit);

			j++;
		}
		j = 0;
		i++;
	}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, game->pos.x * bit, game->pos.y * bit);
}

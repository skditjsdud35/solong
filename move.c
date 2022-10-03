#include "so_long.h"

int	valid_move(t_game *game)
{
	if (game->pos.x < 0 || game->pos.y < 0)
		return (0);
	else
	{
		if (game->map[game->pos.x][game->pos.y] == '1')
			return (0);
	}
}

void	move(t_game *game, int keycode)
{
	
}

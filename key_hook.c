#include "so_long.h"

void	pos_init(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)       	
		(game->pos.y)--;
	else if (keycode == KEY_S)  
		(game->pos.y)++;
	else if (keycode == KEY_A)   
		(game->pos.x)--;
	else if (keycode == KEY_D)   
		(game->pos.x)++;
	else if (keycode == KEY_ESC) 
		exit(0);
	else
		return(0);
	printf("(x, y): (%d, %d)\n", game->pos.x, game->pos.y);
	draw(game);
	return (0);
}



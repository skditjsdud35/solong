#include "so_long.h"

void	valid_move(t_game *game)
{
	
	if (game->map[game->pos.y][game->pos.x] == 'C')
	{
		(game->tmp.count_c)--;
		game->map[game->pos.y][game->pos.x] = '0';
		printf("coin\n");
	}else if (game->map[game->pos.y][game->pos.x] == '1')
	{	
		back_pos(game);
		printf("wall\n");
	}else if (game->map[game->pos.y][game->pos.x] == 'E' && game->tmp.count_c == 0)
	{
		// 게임 종료
		printf("YOU WIN\n");
	}
}

void	back_pos(t_game *game)
{
	if (game->pos.keycode == KEY_W)       	
		(game->pos.y)++;
	else if (game->pos.keycode == KEY_S)  
		(game->pos.y)--;
	else if (game->pos.keycode == KEY_A)   
		(game->pos.x)++;
	else if (game->pos.keycode == KEY_D)   
		(game->pos.x)--;
	else if (game->pos.keycode == KEY_ESC) 
		exit(0);
}
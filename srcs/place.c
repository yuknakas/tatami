#include "../include/tatami.h"

static void	place_hori(t_tatami *tatami, char color);
static void	place_vert(t_tatami *tatami, char color);
static bool	find_next(t_tatami *tatami);

void	place(t_tatami *tatami)
{
	char	color;

	color = findcolor(tatami);
	place_vert(tatami, color);
	place_hori(tatami, color);
	return ;
}

static void	place_vert(t_tatami *tatami, char color)
{
	int tmp_x = tatami->x;
	int tmp_y = tatami->y;
	if (tmp_x + 1 >= tatami->max_x)
		return ;
	tatami->map[tmp_x][tmp_y] = color;
	tatami->map[tmp_x + 1][tmp_y] = color;

	if (find_next(tatami))
		check(tatami);
	else
		place(tatami);

	tatami->x = tmp_x;
	tatami->y = tmp_y;
	tatami->map[tmp_x][tmp_y] = 0;
	tatami->map[tmp_x + 1][tmp_y] = 0;
}

static void	place_hori(t_tatami *tatami, char color)
{
	int tmp_x = tatami->x;
	int tmp_y = tatami->y;
	if (tmp_y + 1 >= tatami->max_y)
		return ;
	tatami->map[tmp_x][tmp_y] = color;
	tatami->map[tmp_x][tmp_y + 1] = color;

	if (find_next(tatami))
		check(tatami);
	else
		place(tatami);

	tatami->x = tmp_x;
	tatami->y = tmp_y;
	tatami->map[tmp_x][tmp_y] = 0;
	tatami->map[tmp_x][tmp_y + 1] = 0;
}

static bool	find_next(t_tatami *tatami)
{
	while (tatami->y < tatami->max_y)
	{
		while (tatami->x < tatami->max_x)
		{
			if (!tatami->map[tatami->x][tatami->y])
				return (false);
			tatami->x++;
		}
		tatami->x = 0;
		tatami->y++;
	}
	return (true);
}
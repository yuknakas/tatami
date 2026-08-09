#include "../include/tatami.h"

char	findcolor(t_tatami *tatami)
{
	bool	color[4];

	color[0] = color[1] = color[2] = color[3] = true;
	if (tatami->x > 0)
		color[tatami->map[tatami->x - 1][tatami->y] - 'A'] = false;
	if (tatami->y > 0)
	{
		color[tatami->map[tatami->x][tatami->y - 1] - 'A'] = false;
		if (tatami->x + 1 < tatami->max_x)
			color[tatami->map[tatami->x + 1][tatami->y - 1] - 'A'] = false;
	}
	if (tatami->x + 2 < tatami->max_x)
		color[tatami->map[tatami->x + 2][tatami->y] - 'A'] = false;
	for (int i = 0; i < 4; i++)
	{
		if (color[i])
			return ('A' + i);
	}
	return ('E');
}

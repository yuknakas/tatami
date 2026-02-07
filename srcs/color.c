#include "../include/tatami.h"

char	findcolor(t_tatami *tatami)
{
	int	color[4];

	color[0] = color[1] = color[2] = color[3] = 1;
	if (tatami->x > 0)
		color[tatami->map[tatami->x - 1][tatami->y] - 'A']--;
	if (tatami->y > 0)
	{
		color[tatami->map[tatami->x][tatami->y - 1] - 'A']--;
		if (tatami->x + 1 < tatami->max_x)
			color[tatami->map[tatami->x + 1][tatami->y - 1] - 'A']--;
	}
	for (int i = 0; i < 4; i++)
	{
		if (color[i] > 0)
			return (COLORS[i]);
	}
	return ('E');
}

#ifndef TATAMI_H
# define TATAMI_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

typedef struct s_tatami
{
	char	**map;
	int		max_x;
	int		max_y;
	int		x;
	int		y;
	int		total;
	int		valid;
	int		invalid;
	char	*option;
} t_tatami;

// init
bool	init(t_tatami *tatami, int argc, char **argv);
void	clean(t_tatami *tatami, int i);
void	place(t_tatami *tatami);
char	findcolor(t_tatami *tatami);
void	check(t_tatami *tatami);
bool	check_valid(t_tatami *tatami);
void	print_valid(t_tatami *tatami);

# define COLORS "ABCD"

#endif
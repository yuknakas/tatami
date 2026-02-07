#include "../include/tatami.h"

int	main(int argc, char **argv)
{
	t_tatami	tatami;

	if (init(&tatami, argc, argv))
		return (1);

	place(&tatami);
	printf("Total: %i\n", tatami.total);
	printf("Valid: %i\n", tatami.valid);
	printf("Invalid: %i\n", tatami.invalid);
	clean(&tatami, tatami.max_x);
}


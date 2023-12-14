#include "main.h"

/**
 * sya_shell - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int sya_shell(data_shell *datash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		sya_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		sya_previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		sya_dot(datash);
		return (1);
	}

	sya_to(datash);

	return (1);
}


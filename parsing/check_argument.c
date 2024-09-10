/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:18:26 by ftanon            #+#    #+#             */
/*   Updated: 2024/09/07 13:14:25 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_argument(char *filename, int inputnumber)
{
	char	*string;

	if (inputnumber != 2)
	{
		printf("Error\nNumber of arguments incorrect\n");
		return (1);
	}
	string = ft_strrchr(filename, '.');
	if (string == 0)
	{
		printf("Error\nFile name incorrect\n");
		return (1);
	}
	if (ft_strncmp(string, ".cub", 4) != 0)
	{
		printf("Error\nFile name incorrect\n");
		return (1);
	}
	return (0);
}
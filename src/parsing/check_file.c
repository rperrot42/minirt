/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:40:30 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/15 21:03:29 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "error.h"

static t_bool  check_filename(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    if (str[i - 1] != 't' || str[i - 2] != 'r' || str[i - 3] != '.')
        return (true);
    return (false);
}

int check_file(char *file_name)
{
    int fd;

    if (check_filename(file_name))
    {
        ft_dprintf(STDERR_FILENO, "%s", E_FILE_EXT);
        return (-1);
    }
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        ft_dprintf(STDERR_FILENO, "%s", E_FILE_ACCESS);
        return (fd);
    }
    return (fd);
}


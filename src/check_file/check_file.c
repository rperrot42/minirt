/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:40:30 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/15 20:34:34 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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

int get_file(char *file_name)
{
    int fd;

    if (check_filename(file_name))
    {
        ft_dprintf(2, "%s", E_FILE_EXT);
        return (-1);
    }
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        ft_dprintf(2, "%s", E_FILE_ACCESS);
        return (fd);
    }
    return (fd);
}

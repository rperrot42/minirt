/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:31:09 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/16 20:59:54 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define E_MALLOC           "Error malloc\n"

# define E_FILE_EXT         "Wrong file extension, not a .rt file\n"
# define E_FILE_ACCESS      "Couldn't open the file\n"
# define E_FILE_EMPTY       "Empty file\n"
# define E_FILE_PARS        "Parse error\n"
# define E_FILE_INP         "Wrong input values\n"

# define E_CAM_NB			"Wrong number of cameras\n"
# define E_AMB_NB			"Wrong number of ambient lights\n"
# define E_NB_ARGS		 	"Wrong number of arguments\n"
# define E_NOT_CAMERAS		 "No cameras\n"
# define E_NOT_AMBIENT		 "No ambient light\n"
# define E_NOT_LIGHTS		 "No lights\n"

int  print_error(char *error);

#endif
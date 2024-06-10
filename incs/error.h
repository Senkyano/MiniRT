/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:18:16 by eturiot           #+#    #+#             */
/*   Updated: 2024/06/10 16:34:07 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <errno.h>
# include <string.h>

/* ************************************************************************** */
/*                                   Macros                                   */
/* ************************************************************************** */

# define EXTENSION_SIZE	3

# define NEWLINE '\n'
# define SPACE	' '
# define TAB	'\t'

# define EID			"Invalid identifier!"
# define EEXTENSION		"Invalid file extension!"
# define ENB_AMBIENT	"Ambient lightning \'A\' must be declared once!"
# define ENB_CAMERA		"Camera \'C\' must be declared once!"
# define ENB_LIGHT		"Light \'L\' must be declared once!"
# define ENUMBER_ARGS	"Invalid number of arguments!"

/* ************************************************************************** */
/*                                 Structures                                 */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                 Functions                                  */
/* ************************************************************************** */


#endif

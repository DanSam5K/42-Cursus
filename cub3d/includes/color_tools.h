/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:05:46 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/23 15:33:19 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This header file defines a set of macros for terminal text formatting using ANSI 
escape codes. These macros can be used to changethe appearance of text in the 
terminal, such as making it bold, changing its color, or setting a background 
color.
These macros can be used in your C code to format terminal output, 
making it easier to highlight important information or improve readability.
*/

#ifndef COLOR_TOOLS_H
# define COLOR_TOOLS_H

# define RESET	"\e[0m"  // Reset all attributes

# define BOLD	"\e[1m"  // Bold text
# define DIM	"\e[2m"  // Dim text
# define ITAL	"\e[3m"  // Italic text
# define ULINE	"\e[4m"  // Underline text

# define BLACK	"\e[30m"  // Black text
# define RED	"\e[31m"  // Red text
# define GREEN	"\e[32m"  // Green text
# define YELLOW	"\e[33m"  // Yellow text
# define BLUE	"\e[34m"  // Blue text
# define PURPLE	"\e[35m"  // Purple text
# define CYAN	"\e[36m"  // Cyan text
# define WHITE	"\e[37m"  // White text

# define BRIGHT_BLACK	"\e[90m"  // Bright black text
# define BRIGHT_RED		"\e[91m"  // Bright red text
# define BRIGHT_GREEN	"\e[92m"  // Bright green text
# define BRIGHT_YELLOW	"\e[93m"  // Bright yellow text
# define BRIGHT_BLUE	"\e[94m"  // Bright blue text
# define BRIGHT_PURPLE	"\e[95m"  // Bright purple text
# define BRIGHT_CYAN	"\e[96m"  // Bright cyan text
# define BRIGHT_WHITE	"\e[97m"  // Bright white text

# define BG_BRIGHT_BLACK	"\e[100m"  // Bright black background
# define BG_BRIGHT_RED		"\e[101m"  // Bright red background
# define BG_BRIGHT_GREEN	"\e[102m"  // Bright green background
# define BG_BRIGHT_YELLOW	"\e[103m"  // Bright yellow background
# define BG_BRIGHT_BLUE		"\e[104m"  // Bright blue background
# define BG_BRIGHT_PURPLE	"\e[105m"  // Bright purple background
# define BG_BRIGHT_CYAN		"\e[106m"  // Bright cyan background
# define BG_BRIGHT_WHITE	"\e[107m"  // Bright white background

# define BG_BLACK	"\e[40m"  // Black background
# define BG_RED		"\e[41m"  // Red background
# define BG_GREEN	"\e[42m"  // Green background
# define BG_YELLOW	"\e[43m"  // Yellow background
# define BG_BLUE	"\e[44m"  // Blue background
# define BG_PURPLE	"\e[45m"  // Purple background
# define BG_CYAN	"\e[46m"  // Cyan background
# define BG_WHITE	"\e[47m"  // White background

#endif
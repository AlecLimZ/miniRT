/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:36 by leng-chu          #+#    #+#             */
/*   Updated: 2022/09/15 18:50:35 by leng-chu         ###   ########.fr       */
/*   Updated: 2021/12/07 11:44:18 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "key_codes.h"
# include "../../mlx_mms_20191025/mlx.h"
# include "../../mlx_linux/mlx.h"
# include "../../minilibx_macos/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "ansi_colors.h"
# include "vec.h"
# include "draw.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		px;
	int		len;
	int		end;
}	t_data;

#endif

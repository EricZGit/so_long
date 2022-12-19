/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:48:03 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/28 08:11:41 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "errors.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 1
/*base de donnees des images*/
# define PLAYER_HAUT "./images/player_haut.xpm"
# define PLAYER_BAS "./images/player_bas.xpm"
# define PLAYER_GAUCHE "./images/player_gauche.xpm"
# define PLAYER_DROITE "./images/player_droite.xpm"
# define EXIT_OPEN "./images/exit_open.xpm"
# define EXIT_CLOSE "./images/exit_close.xpm"
# define TEXTURE "./images/texture.xpm"
# define WALL "./images/wall.xpm"
# define COLLECT "./images/collectable.xpm"
# define ANGLE "./images/angle.xpm"
/*base de donnees des key's*/
# define ESC 65307
# define QUIT 113
# define A 97
# define W 119
# define S 115
# define D 100
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363 

/*struct pour gerer les data's*/
typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		img_largeur;
	int		img_hauteur;
	int		pos_col;
	int		pos_line;
	int		end_game;
}	t_data;

/*struct pour gerer les images*/
typedef struct s_img
{
	void	*img_collectable;
	void	*img_exit_close;
	void	*img_exit_open;
	void	*img_texture;
	void	*img_player_bas;
	void	*img_player_haut;
	void	*img_player_droite;
	void	*img_player_gauche;
	void	*img_wall;
	void	*img_angle;
}	t_img;

/*struct pour gerer la map*/
typedef struct s_map
{
	char	**mapping;
	int		columns;
	int		lines;
	int		players;
	int		collectables;
	int		out;
	int		moves;
}	t_map;

/*struct pour stocker et gerer la map et ses data's*/
typedef struct s_game
{
	t_data	*data;
	t_map	*map;
	t_img	*img;
}	t_game;

/*fonction pour afficher les erreurs*/
void	print_error(char *msg, t_game *game);
/*fonction qui check si la map est entouree de 1*/
void	check_map_is_ok(t_game *game);
/*fonction qui free le tableau de str(mapping de caracteres)*/
void	free_mapping(t_game *game);
/*GNL adapte a la map.ber*/
int		gnl_map(t_game *game, char *argv);
/*fonction pour upload les images dans la map*/
void	load_image(t_game *game);
/*fonction pour upload les images du player dans la map*/
void	load_player_image(t_game *game);
/*fonction qui gere les key's utilisees*/
int		key_actions(int key, t_game *game);
/*fonction qui ferme la fenetre et exit le programme*/
int		close_window_and_exit(t_game *game);
/*fonction qui liberent toutes les images uploadees*/
void	free_images(t_game *game);
/*fonction qui gere les mouvements du player*/
void	ft_move_player(t_game *game, int x, int y, int key);
/*fonction qui ckeck si les mouvements du player sont ok*/
int		ftmove_is_ok(t_game *game, int x, int y, int key);
/*fonction pour afficher le game*/
int		ft_imaging(t_game *game);

/*utils*/
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t	n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	**free_split(char **str);
void	*ft_calloc(size_t nbr, size_t size);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:45:57 by ezielins          #+#    #+#             */
/*   Updated: 2022/07/22 22:54:38 by ezielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define ENNEMY_HAUT "./images/ennemy_haut.xpm"
# define ENNEMY_BAS "./images/ennemy_bas.xpm"
# define ENNEMY_GAUCHE "./images/ennemy_gauche.xpm"
# define ENNEMY_DROITE "./images/ennemy_droite.xpm"
# define EXIT_OPEN "./images/exit_open.xpm"
# define EXIT_CLOSE "./images/exit_close.xpm"
# define TEXTURE "./images/texture.xpm"
# define WALL "./images/wall.xpm"
# define COLLECT "./images/collectable.xpm"
# define ANGLE "./images/angle.xpm"
# define DEATH "./images/death.xpm"
# define COLDEATH "./images/collectdeath.xpm"
# define SCOZERO "./images/scorezero.xpm"
# define SCOUN "./images/scoreun.xpm"
# define SCODEUX "./images/scoredeux.xpm"
# define SCOTROIS "./images/scoretrois.xpm"
# define SCOQUATRE "./images/scorequatre.xpm"
# define SCOCINQUE "./images/scorecinque.xpm"
# define SCOSIX "./images/scoresix.xpm"
# define SCOSEPT "./images/scoresept.xpm"
# define SCOHUIT "./images/scorehuit.xpm"
# define SCONEUF "./images/scoreneuf.xpm"
# define SCOZZERO "./images/scorezzero.xpm"
# define SCOONE "./images/scoreone.xpm"
# define SCOTWO "./images/scoretwo.xpm"
# define SCOTHREE "./images/scorethree.xpm"
# define SCOFOUR "./images/scorefour.xpm"
# define SCOFIVE "./images/scorefive.xpm"
# define SCOSSIX "./images/scoressix.xpm"
# define SCOSEVEN "./images/scoreseven.xpm"
# define SCOHEIGHT "./images/scoreheight.xpm"
# define SCONINE "./images/scorenine.xpm"
# define COINHD "./images/coinhd.xpm"
# define COINHG "./images/coinhg.xpm"
# define COINBD "./images/coinbd.xpm"
# define COINBG "./images/coinbg.xpm"
# define AVPD "./images/avpd.xpm"
# define AVPG "./images/avpg.xpm"
# define PIPIONE "./images/pipione.xpm"
# define PIPIZERO "./images/pipizero.xpm"
# define PIPITWO "./images/pipitwo.xpm"
# define GUITONE "./images/guitone.xpm"
# define GUITZERO "./images/guitzero.xpm"
# define GUITTWO "./images/guittwo.xpm"
# define SOLDONE "./images/soldone.xpm"
# define SOLDZERO "./images/soldzero.xpm"
# define SOLDTWO "./images/soldtwo.xpm"
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
	int		going_player;
	int		anim;
	int		pos_col_colzero;
	int		pos_col_colone;
	int		pos_col_coltwo;
	int		pos_line_colzero;
	int		pos_line_colone;
	int		pos_line_coltwo;

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
	void	*img_ennemy_bas;
	void	*img_ennemy_haut;
	void	*img_ennemy_droite;
	void	*img_ennemy_gauche;
	void	*img_wall;
	void	*img_angle;
	void	*img_death;
	void	*img_collectdeath;
	void	*img_scorezero;
	void	*img_scorezzero;
	void	*img_scoreun;
	void	*img_scoreone;
	void	*img_scoredeux;
	void	*img_scoretwo;
	void	*img_scoretrois;
	void	*img_scorethree;
	void	*img_scorequatre;
	void	*img_scorefour;
	void	*img_scorecinque;
	void	*img_scorefive;
	void	*img_scoresix;
	void	*img_scoressix;
	void	*img_scoresept;
	void	*img_scoreseven;
	void	*img_scorehuit;
	void	*img_scoreheight;
	void	*img_scoreneuf;
	void	*img_scorenine;
	void	*img_coinhd;
	void	*img_coinhg;
	void	*img_coinbd;
	void	*img_coinbg;
	void	*img_avpd;
	void	*img_avpg;
	void	*img_guitzero;
	void	*img_guitone;
	void	*img_guittwo;
	void	*img_soldzero;
	void	*img_soldone;
	void	*img_soldtwo;
	void	*img_pipione;
	void	*img_pipitwo;
	void	*img_pipizero;
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
void	load_image_two(t_game *game);
void	load_image_three(t_game *game);
/*fonction pour upload les images du player dans la map*/
void	load_player_image(t_game *game);
/*fonction pour upload les images de l ennemy dans la map*/
void	load_image_ennemy(t_game *game);
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
/*fonction pour determiner l orientation du player*/
void	ft_going_player(t_game *game, int key);
/*fonction pour afficher l ennemy*/
void	screen_ennemy(t_game *game, int line, int col, int death);
/*fonction pour afficher les traces de sang sur les murs*/
void	screen_collectdeath(t_game *game, int y, int x);
/*fonction pour afficher le score dans la fenetre*/
void	ft_score(t_game *game);
/*fonctions qui anime les collectables*/
int		anim_collect(t_game *game);
int		anim_collectone(t_game *game);
int		anim_collecttwo(t_game *game);
void	free_score_two(t_game *game);
void	screen_collec_sold(t_game *game);
void	screen_collec_guit(t_game *game);
void	screen_collec_pipi(t_game *game);
void	screen_collec_fear(t_game *game);
void	position_collect(t_game *game);

/*fonctions pour gerer l affichage du score*/
void	free_score(t_game *game);
void	load_score(t_game *game);
void	load_score_two(t_game *game);
void	ft_put_score(t_game *game, int diz, int line, int col);
void	ft_put_scorex(t_game *game, int diz, int line, int col);

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

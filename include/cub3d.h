#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/libft.h"
# include "structs.h"
# include "constants.h"
# include "../mlx_linux/mlx.h"
//# include "../miniLibX/mlx.h"
# include <fcntl.h> //open().
# include <stdio.h> //printf

void    setup(t_game *game);
void    interpretate_map(t_game *game, char *path_name);
void    validate_map(t_game *game);
void    render_game(t_game *game);
void	exit_game(char *message, t_game *game);

//Texture
int get_texture(t_game *game, char *line);

// Common libft
void    free_matrix(char **matrix);
void    update_matrix(char ***matrix, char *new_line);
int     ft_count_words(char const *s, char c);
void    trim_new_line(char **line);


#endif

/*
Ter buraco na parede
Buraco no mapa (linha). Pode ter buraco se for do lado do 1.
Nao ter player, ou ter mais de 1.
Mapa vazio

11111
10101
11 11
1111


NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0


        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
*/
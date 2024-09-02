// add school header here!!!!

#include "cub3D.h"

static void set_tex_color_info(char **map_info, char *path_str)
{
    while (*path_str == ' ' || *path_str == '\t')
        path_str++;
    if (*map_info) // do I need to fo this here?
        free(*map_info);
    *map_info = ft_strdup(path_str);
    if (!*map_info)
    {
        printf("ft_strdup failed\n"); // ここでメモリ解放処理も必要です
        exit(1);
    }
    printf("Texture path is: %s\n", *map_info);
}

void    set_map_info(t_game *game, char **file_copy)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		while (file_copy[i][j] == ' ' || file_copy[i][j] == '\t')
			j++;
		if (ft_strncmp(&file_copy[i][j], "NO", 2) == 0)
			set_tex_color_info(&game->no_texture, &file_copy[i][j + 2]);
		else if (ft_strncmp(&file_copy[i][j], "SO", 2) == 0)
			set_tex_color_info(&game->so_texture, &file_copy[i][j + 2]);
		else if (ft_strncmp(&file_copy[i][j], "WE", 2) == 0)
			set_tex_color_info(&game->we_texture, &file_copy[i][j + 2]);
		else if (ft_strncmp(&file_copy[i][j], "EA", 2) == 0)
			set_tex_color_info(&game->ea_texture, &file_copy[i][j + 2]);
		else if (ft_strncmp(&file_copy[i][j], "F", 1) == 0)
            set_tex_color_info(&game->floor_rgb, &file_copy[i][j + 1]);
		else if (ft_strncmp(&file_copy[i][j], "C", 1) == 0)
            set_tex_color_info(&game->ceiling_rgb, &file_copy[i][j + 1]);
		i++;
		j = 0;	
	}
}


// static void set_texture_info(t_game *game, char **file_copy)
// {
// 	char *path_start;
// 	int i;
// 	int j;
// 	int loop;

// 	i = 0;
// 	j = 0;
// 	loop = 0;
// 	while (loop < 6)
// 	{
// 		while (file_copy[i][j] == ' ' || file_copy[i][j] == '\t')
// 			j++;
// 		if (ft_strncmp(&file_copy[i][j], "NO", 2) == 0)
// 		{
// 			path_start = &file_copy[i][j + 2];
// 			while (*path_start == ' ' || *path_start == '\t')
// 				path_start++;
// 			game->no_texture = ft_strdup(path_start);
// 			printf("game->no_texture is:%s\n", game->no_texture);
// 		}
// 		else if (ft_strncmp(&file_copy[i][j], "SO", 2) == 0)
// 		{
// 			path_start = &file_copy[i][j + 2];
// 			while (*path_start == ' ' || *path_start == '\t')
// 				path_start++;
// 			game->so_texture = ft_strdup(path_start);
// 			printf("game->so_texture is:%s\n", game->so_texture);
// 		}
// 		else if (ft_strncmp(&file_copy[i][j], "WE", 2) == 0)
// 		{
// 			path_start = &file_copy[i][j + 2];
// 			while (*path_start == ' ' || *path_start == '\t')
// 				path_start++;
// 			game->we_texture = ft_strdup(path_start);
// 			printf("game->we_texture is:%s\n", game->we_texture);
// 		}
// 		else if (ft_strncmp(&file_copy[i][j], "EA", 2) == 0)
// 		{
// 			path_start = &file_copy[i][j + 2];
// 			while (*path_start == ' ' || *path_start == '\t')
// 				path_start++;
// 			game->ea_texture = ft_strdup(path_start);
// 			printf("game->ea_texture is:%s\n", game->ea_texture);
// 		}
// 		else if (ft_strncmp(&file_copy[i][j], "F", 1) == 0)
// 		{
// 			path_start = &file_copy[i][j + 1];
// 			while (*path_start == ' ' || *path_start == '\t')
// 				path_start++;
// 			game->floor_rgb = ft_strdup(path_start);
// 			printf("game->floor_rgb is:%s\n", game->floor_rgb);
// 		}
// 		else if (ft_strncmp(&file_copy[i][j], "C", 1) == 0)
// 		{
// 			path_start = &file_copy[i][j + 1];
// 			while (*path_start == ' ' || *path_start == '\t')
// 				path_start++;
// 			game->ceiling_rgb = ft_strdup(path_start);
// 			printf("game->ceiling_rgb is:%s\n", game->ceiling_rgb);
// 		}
// 		i++;
// 		j = 0;
// 		loop++;		
// 	}
// }
// add school header header here

#include "cub3D.h"

// int is_player_trapped(char **map, int player_y, int player_x)
// {
    // this way might destroy the original map if I don't use temp
//     int access;

//     access = 0;
//     if (player_y < 0 || player_x < 0 || !map[player_y] || !map[player_y][player_x])
//         return (0);
    
//     if (map[player_y][player_x] == '1')
//         return (0);
    
//     map[player_y][player_x] = '1';
//     access += is_player_trapped(map, player_y + 1, player_x);
//     access += is_player_trapped(map, player_y - 1, player_x);
//     access += is_player_trapped(map, player_y, player_x + 1);
//     access += is_player_trapped(map, player_y, player_x - 1);

//     if (access > 0)
//         return (0);
//     return (1);
// }

int is_player_trapped(char **map, int player_y, int player_x)
{
    if (map[player_y][player_x + 1] == '1' && map[player_y][player_x - 1] == '1'
        && map[player_y + 1][player_x] == '1' && map[player_y - 1][player_x] == '1')
        return (1);
    return (0);
}
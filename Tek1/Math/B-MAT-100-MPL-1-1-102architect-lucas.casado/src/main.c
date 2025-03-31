/*
** EPITECH PROJECT, 2020
** architect
** File description:
** main
*/

#include <stdio.h>
#include "struc.h"

void print_help()
{
    printf("USAGE\n    ./102architect x y transfo1 arg11 [arg12]");
    printf(" [transfo2 arg12 [arg22]] ...\n\nDESCRIPTION\n");
    printf("    x   abscissa of the original point\n");
    printf("    y   ordinate of the original point\n\n");
    printf("    transfo1 arg1 [arg2]\n    -t i j  translation along vector");
    printf(" (i, j)\n    -z m n scaling by factors m (x-axis) and (y-axis)\n");
    printf("    -r d    rotation centered in 0 by a d degree angle\n");
    printf("    -s d    reflection over the axis passing through 0 with an ");
    printf("inclination\n            angle of degrees\n");
}

main_matrice_t initialize_ma(main_matrice_t ma)
{
    ma.i1 = 1;
    ma.i2 = 0;
    ma.i3 = 0;
    ma.j1 = 0;
    ma.j2 = 1;
    ma.j3 = 0;
    ma.k1 = 0;
    ma.k2 = 0;
    ma.k3 = 1;
    return (ma);
}

int main(int argc, char **argv)
{
    main_matrice_t ma = initialize_ma(ma);
    if (argc < 2)
        return (84);
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        print_help();
    for (int n = 0; chose_func[n].param != '0'; n++) {
        if (argv[3][1] == chose_func[n].param)
            chose_func[n].function(argc, argv, &ma);
    }
    return (0);
}
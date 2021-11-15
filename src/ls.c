/*
** EPITECH PROJECT, 2020
** ls
** File description:
** ls
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

void ls(DIR *rep, struct dirent *fichier)
{
    fichier = readdir(rep);
    while (fichier != NULL) {
        if (fichier->d_name[0] != '.') {
            my_putstr(fichier->d_name);
            my_putstr("\n");
        }
        fichier = readdir(rep);
    }
}

void ls_d(char **av)
{
    int i = 1;

    for (; av[i+1] != NULL; i++)
        my_putstr(av[i]);
    if (i == 1)
        my_putstr(".\n");
}

void step(char **av, DIR *rep, struct dirent *fichier, struct stat sb)
{
    if (av[1][0] == '-') {
        if (av[1][1] == 'd')
            ls_d(av);
        if (av[1][1] == 'l') {
            rep = opendir(".");
            ls_l(rep, fichier, sb, ".");
        }
    }
}

void step2(char **av, DIR *rep, struct dirent *fichier, struct stat sb)
{
    if (av[1][0] == '-') {
        if (av[1][1] == 'd') {
            my_putstr(av[2]);
            
            my_putstr("\n");
        }
        if (av[1][1] == 'l') {
            rep = opendir(av[2]);
            if (rep == NULL)
                exit(84);
            ls_l(rep, fichier, sb, av[2]);
        }
    }
}

void main(int ac, char **av)
{
    struct stat sb;
    char *buffer;
    DIR *rep;
    struct dirent *fichier = NULL;

    if (ac == 1) {
        rep = opendir(".");
        ls(rep, fichier);
    }
    if (ac == 2) {
        if (av[1][0] != '-') {
            rep = opendir(av[1]);
            if (rep == NULL)
                return (0);
            ls(rep, fichier);
        }
        step(av, rep, fichier, sb);
    }
    if (ac == 3)
        step2(av, rep, fichier, sb);
    return (0);
}


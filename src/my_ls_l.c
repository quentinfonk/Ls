/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** l
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void six(void)
{
    my_putstr("-");
}

void all(struct stat sb, char *str, struct dirent *fichier)
{
    lstat(str, &sb);
    if (fichier->d_type == 4)
        my_putstr("d");
    else
        six();
    if(sb.st_mode & S_IRUSR)
        my_putstr("r");
    else
        six();
    if(sb.st_mode & S_IWUSR)
        my_putstr("w");
    else
        six();
    if(sb.st_mode & S_IXUSR)
        my_putstr("x");
    else
        six();
    all2(sb, str, fichier);
}

void all2(struct stat sb, char *str, struct dirent *fichier)
{
    if(sb.st_mode & S_IRGRP)
        my_putstr("r");
    else
        six();
    if(sb.st_mode & S_IWGRP)
        my_putstr("w");
    else
        six();
    if(sb.st_mode & S_IXGRP)
        my_putstr("x");
    else
        six();
    if(sb.st_mode & S_IROTH)
        my_putstr("r");
    else
        six();
    all3(sb, str, fichier);
}

void all3(struct stat sb, char *str, struct dirent *fichier)
{
    if(sb.st_mode & S_IWOTH)
        my_putstr("w");
    else
        six();
    if(sb.st_mode & S_IXOTH)
        my_putstr("x");
    else
        six();
    my_putstr(" ");
}

char *my_strcat(char *chemin, char *suite)
{
    int i = 0;
    char *stack = malloc(sizeof(char) * my_strlen(chemin) + my_strlen(suite) + 1);

    if (chemin[0] == '/' || chemin[0] == '.' && chemin[1] != '\0') {
        for (; chemin[i] != '\0'; i++);
        if (chemin[i-1] != '/') {
            chemin[i] = '/';
            chemin[i+1] = '\0';
        }
        for (int o = 0; chemin[o] != '\0'; o++)
            stack[o] = chemin[o];
        for (int o = 0; suite[o] != '\0'; o++, i++)
            stack[i] = suite[o];
    }
    else
        return (suite);
    return (stack);
}

void tota(DIR *rep, struct dirent *fichier, struct stat sb, char *str)
{
    static int a = 0;
    char *stack = malloc(sizeof(char) * 4096);

    while (fichier != NULL) {
        if (fichier->d_name[0] != '.') {
            stack = my_strcat(str, fichier->d_name);
            stat(stack, &sb);
            a = a + sb.st_blocks/2;
        }
        fichier = readdir(rep);
    }
    my_putstr("total ");
    my_put_nbr(a);
    my_putstr("\n");
}

void ls_l(DIR *rep, struct dirent *fichier, struct stat sb, char *str)
{
    int a = 0;
    char *stack = malloc(sizeof(char) * 4096);;

    fichier = readdir(rep);
    tota(rep, fichier, sb, str);
    rep = opendir(str);
    fichier = readdir(rep);
    while (fichier != NULL) {
        if (fichier->d_name[0] != '.') {
            stack = my_strcat(str, fichier->d_name);
            all(sb, stack, fichier);
            stat(stack, &sb);
            a = sb.st_nlink;
            my_put_nbr(a);
            id(sb);
            my_putstr(" ");
            my_put_nbr(sb.st_size);
            times((ctime(&sb.st_mtim)));
            my_putstr(" ");
            my_putstr(fichier->d_name);
            my_putstr("\n");
        }
        fichier = readdir(rep);
    }
    closedir(rep);
}

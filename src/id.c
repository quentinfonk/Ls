/*
** EPITECH PROJECT, 2020
** id
** File description:
** id
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void id(struct stat sb)
{
    uid_t ici = sb.st_uid;
    gid_t la = sb.st_gid;
    struct passwd *salut = getpwuid(ici);
    struct group *coucou = getgrgid(la);

    my_putstr(" ");
    my_putstr(salut->pw_name);
    my_putstr(" ");
    my_putstr(coucou->gr_name);
}

void times(char *str)
{
    char *stack = str;
    int i = 0;
    int o = 0;
    int a = 0;

    for (; str[i] != ' '; i++);
    for (; str[o] != '\0'; o++);
    for (; str[o] != ' '; o--);
    o = o - 3;
    for (; i != o; i++, a++)
        stack[a] = str[i];
    stack[a] = '\0';
    my_putstr(stack);
}

/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** 
*/

void my_putchar(char c);

int carrer(int a)
{
    int t;
    t = 1;
    while (a > 0){
        a = a-1;
        t = t*10;}   
    return (t);
}
int my_put_nbr(int n)
{
    int a, e, t, p;
    a = 0;
    e = n;

    if (n == 0)
        my_putstr("0");
    while (e != 0) {
        a = a + 1;
        e = e/10;
    }
    while (n != 0){
        t = carrer(a);
        t = t/10;
        a = a-1;
        p = n%t;
        n = n/t;
        my_putchar(n + 48);
        n = p;
    }       
    return (0);
}

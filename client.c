#include "ft_printf/ft_printf.h"
#include <signal.h>

void send_message(int pid, char *str)
{
    int i;
    unsigned int j;

    j = 0;
    while(str[j])
    {
        i = 8;
        while(--i >= 0)
        {
            if ((str[j] >> i) & 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            usleep(100);
        }
        j++;
    }
}
int main (int argc, char **argv)
{
    if(argc != 3)
        return 1;
    send_message(ft_atoi(argv[1]), argv[2]);
    return 0;
}
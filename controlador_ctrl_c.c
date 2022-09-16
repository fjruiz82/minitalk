# include <signal.h>
# include <stdio.h>
# include <unistd.h>

void controlador (int);

int main ()
{
    if (signal (SIGINT, controlador))
    {
        perror ("No se puede cambiar signal");
    }
    while (1)
        pause();
}

void controlador (int signal_id)
{
    printf("Pues no me salgo \n");
    printf("Inténtalo otra vez \n");
    signal(SIGINT, SIG_DFL);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    
    //Létrehozzuk
    pid_t cpid = fork();

    if (cpid == -1)
    {
        perror("Elforkol");
        exit(-1);
    }

    // Le kell kérni az adott process ID-ját, mert még nem tudjuk
    int szpid = getpid();

    if (childPid == 0)  // Ez az ág csak a gyerek processnél fut le.   
    {
        execl("masikp.c",szpid,cpid,NULL);
        printf("Error: execl nem ter vissza.");
        exit(0);

    }
    else  // Ez az ág csak a szülő processnél fut le.           
    {      
        printf("Szulo pidje: %d Gyerek pidje: %d", szpid,cpid);

        

        exit(0);

    }
    
    return 0;
}
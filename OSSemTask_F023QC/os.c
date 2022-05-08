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

    if (cpid == 0)  // Ez az ág csak a gyerek processnél fut le.   
    {
        int childpid = cpid;
        char gyerpid[6];
        char szulpid[6];
        sprintf(szulpid,"%d",getppid());
        printf("%d",childpid);
        sprintf(gyerpid,"%d",getpid());
        execl("./masikp","masikp",szulpid,gyerpid,(char *)NULL);
        printf("Error execl nem ter vissza");

    }
    else  // Ez az ág csak a szülő processnél fut le.           
    {      
        printf("A szulo vagyok \n");
        printf("Szulo pidje: %d Gyerek pidje: %d \n", szpid,cpid);

        

        exit(0);

    }
    
    return 0;
}

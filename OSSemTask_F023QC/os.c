#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    
    
    pid_t cpid = fork();

    if (cpid == -1)
    {
        perror("Elforkol");
        exit(-1);
    }

    int szpid = getpid();

    if (cpid == 0)     
    {
        char gyerpid[6];
        char szulpid[6];
        sprintf(szulpid,"%d",getppid());
        sprintf(gyerpid,"%d",getpid());
        execl("./masikp","masikp",szulpid,gyerpid,(char *)NULL);
        printf("Error execl nem ter vissza");
        exit(0);

    }
    else         
    {      
        printf("A szulo vagyok \n");
        printf("Szulo pidje: %d Gyerek pidje: %d \n", szpid,cpid);

        

        exit(0);

    }
    
    return 0;
}
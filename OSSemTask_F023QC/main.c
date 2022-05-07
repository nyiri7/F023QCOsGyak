#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fPointer  = fopen("bemenet.txt", "r");
    int i =0;
    fscanf(fPointer,"%d",&i);

    int x=0;
    fscanf(fPointer,"%d",&x);
    printf("%d\n",x);
    int y=0;
    fscanf(fPointer,"%d",&y);


    printf("%d\n",y);
    int lnko=1;

    if(x<y){
        for(int j=1;j<=x;j++){
            if(x%j==0&&y%j==0){
                lnko=j;
            }
        }
    }
    if(x>y){
        for(int j=1;j<=y;j++){
            if(x%j==0&&y%j==0){
                lnko=j;
            }
        }
    }

    printf("%d",lnko);
    fclose(fPointer);
    FILE *fPointerki  = fopen("kimenet.txt", "w");
    fprintf(fPointerki,"%d %d %d",x,y,lnko);
    fclose(fPointerki);
    return 0;
}

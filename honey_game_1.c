/* HW10  */
#include<stdio.h>


int poohTurn(int jar);
int pigTurn(int jan);

int poohmax=0;
int pigmax=0;


int main(void){


    int tjar=0;
    int firster=0;
    printf("total no. of jar: ");
    scanf("%d", &tjar);
    printf("pooh max step: ");
    scanf("%d", &poohmax);
    printf("pig max step: ");
    scanf("%d", &pigmax);
    printf("who first? (1=pooh, 0=pig) ");
    scanf("%d", &firster);


    int result;
    if(firster)  
    {
        result=poohTurn(tjar);
        if(result) printf("pooh won.");
        else printf("pig won.");
    }

    else 
    
    {
        result = pigTurn(tjar);
        if(result) printf("pig won.");
        else printf("pooh won.");
    }

    return 0;

}

int poohTurn(int jar)
{
    int p=0;
    int poohwin=0;
    for(p=1;p<=poohmax;p++)
    {
        if(jar-p==0) return 1;
        else if(! pigTurn(jar-p))
        {
            poohwin=1;
            break;     
        }
    }
    if(poohwin) return 1;
    else return 0;
}

int pigTurn(int jar)
{
    int p=0;
    int pigwin=0;
    for(p=1;p<=pigmax;p++)
    {
        if(jar-p==0) return 1;
        else if(! poohTurn(jar-p))
        {
            pigwin=1;
            break;
        }
    }
    if(pigwin) return 1;
    else return 0;
}

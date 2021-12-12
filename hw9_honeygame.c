/* 'HW 9 OJ 13366 - Honey Game  */
/* strategy:

1. 如jar < 先手步數->先手嬴
2. else if pooh & piglet步數不一樣-> 多步數必嬴

2. 如 pooh步數= piglet步數=N -> 
total number of jar%(N+1)==0-> 後手嬴,else->先手嬴
ref: https://www.geeksforgeeks.org/find-the-player-who-wins-the-game-by-removing-the-last-of-given-n-cards/
*/

#include<stdio.h>
#include<string.h>

int main(void)
{
    int T=0; //no. of testcase
    int pooh=0; //p
    int pig=0; //g
    int jar=0;
    int fst=0; //先手步數

    scanf("%d", &T);

    const char p[5]={'P','o', 'o','h'};
    const char g[7]={'P','i','g','l','e','t'};


    while(T--)
    {
        pooh=0; //p
        pig=0; //g
        jar=0;
        fst=0;

        char later[7]={'\0'};
        char first[7]={'\0'};


        scanf("%d %d %d", &jar, &pooh, &pig);
        scanf("%s", first);
        
        if(strcmp(first, p)==0) //pooh 是先手
        {
            strcpy(later, g);
            fst=pooh;
        }
        else  //pooh 是後手
        {
            strcpy(later, p);
            fst=pig;

        }

        //print winner
        if(jar< fst) printf("%s\n", first);
        else
        {
            if(pooh > pig) printf("%s\n", p);
            if(pig > pooh) printf("%s\n", g);
            if(pooh == pig)
            {
                if(jar%(pig+1)==0) printf("%s\n", later);
                else printf("%s\n", first);
            }
        }

    }
    return 0;
}
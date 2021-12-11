#include <stdio.h>
#include <stdlib.h>
#include "function.h"


ll* matrix_mul(ll *A, ll* B, ll m)
{
    /*matrix multiplication*/
    
    ll tmp_m[4]={0};
    *(tmp_m)= (*(A)* *(B))%m + (*(A+1) * *(B+2)) %m ;
    *(tmp_m +1)= (*(A) * *(B+1)) %m + (*(A+1) * *(B+3)) %m ;
    *(tmp_m +2)= (*(A+2) * *(B)) %m + (*(A+3) * *(B+2)) %m ;
    *(tmp_m +3)= (*(A+2)* *(B+1)) %m + (*(A+3) * *(B+3)) %m ;
    
    for(int i=0;i<4;i++) *(A+i)=*(tmp_m +i);
   
    return A;
}



ll* matrix_pow(ll *A, ll b, ll m)
{
    /* calculate A^b%m */

    int k;
    ll A_mir[4];
    for(k=0;k<4;k++) *(A_mir+k) = *(A+k); //make a copy of A
    
    if (b==1) return A;
    else if (b==2) return matrix_mul(A, A, m);
    else
    {
        
        ll *addr = matrix_pow(A, b/2, m);
        ll T[4];
        for(k=0;k<4;k++) *(T+k) = *(addr+k);
        addr = matrix_mul(T, T, m);

        if(b%2 != 0)  addr = matrix_mul(T, A_mir, m);
        
        for(int i=0;i<4;i++) *(A+i)=*(addr +i);
        
        return A;
    }
}
/* HW9 - OJ 12458 - Writing APP  

find length of longest palindromic subset by finding largest common subset

refrence: https://leetcode-cn.com/problems/longest-common-subsequence/solution/zui-chang-gong-gong-zi-xu-lie-by-leetcod-y7u0/

see hw9_palindrome_myv.c for explained code
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int max(int a, int b) {
    a=a>b?a:b;
    return a;
}


int main(void)
{
    
    int len=0, num=0;
    scanf("%d %d",&len, &num);
    char *str = (char *)malloc(len * sizeof(char));
    scanf("%s", str);

    int i,j;
    char *reverse= (char *)malloc(len * sizeof(char));

    for(i=len-1;i>=0;i--)
    {
        *(reverse+i) = str[len-i-1];
    }
    /*
    printf("reverse= ");
    for(i=0;i<len;i++)
    {
        printf("%c ", *(reverse+i));
    }
    printf("\n");
*/
    int ** count_r = (int**)malloc((len+1) * sizeof(int *));//outer layer
    int * count_c = (int*)malloc( (len+1) * (len+1) * sizeof(int)); //inner layer
    for(i=0;i<len+1;i++)
    {
        count_r[i] =  count_c + (len+1)* i;
    }
    for(i=0;i<(len+1) * (len+1);i++) count_c[i]=0;
    
   
    // compute length of largest common subset

    for(j=1;j<len+1;j++)
    {
        char c1=str[j-1];
 
        for(i=1;i<len+1;i++)
        {
            
            if(c1==reverse[i-1])  count_r[i][j]=count_r[i-1][j-1]+1;
                
            else count_r[i][j]=max(count_r[i][j-1],count_r[i-1][j]);
    
        }

    }
    //print count table to check 

/*
    for(i=1;i<len+1;i++)
    {
        for(j=1;j<len+1;j++)
        {
            printf("%3d",count_r[i][j] );
            
        }
        printf("\n");
    }
    //length of largest common subset is the bottom-right corner");
    
*/
   // printf("length of largest plindrome: %d\n", count_r[len][len]);
    if(len-num <= count_r[len][len]) printf("Yes\n");
    else printf("No\n");

    
    return 0;
}




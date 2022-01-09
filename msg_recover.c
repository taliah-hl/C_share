/* from HW10
given prototype, develop solver function to re-arrange
according to leading number %P*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define maxn 1000
#define maxl 1000

int P;
char M[1000010];

void solver(char **ptr, int *n, int P, char *M);

int main() {
    int n = 0;
    char Table[maxn][maxl+1]; // +1 for null char
    char *ptr[maxn];

    for (int i = 0; i < maxn; i++) {
        for(int j=0; j < maxl + 1; j++)
            Table[i][j] = '\0';
        ptr[i] = &Table[i][0];
    }

    scanf("%d", &P);
    printf("give me the string: ");
    scanf("%s", M);
    
    solver(ptr, &n, P, M);
    

    int cnt = 0;
    printf("%d\n", n); // the # of words 最後output有幾多組字,空格分開計一組 
    for(int i=0; i<P; i++){
        if( strlen( Table[i] ) != 0 ){
            // if the position is non-empty.
            if( cnt < n-1 )
                printf("%s ", Table[i]);
            else
                printf("%s\n", Table[i]); //last line need \n
            cnt++;
        }
    }


    return 0;
}

void solver(char **ptr, int *n, int P, char *M)
{
    //task 1: 把str 以數字分開一組組,extract數字的值
    //2.數字%P
    //3.make a pointer point to each grp
    //4. 比較數字值大小,較小->改變pointer所指的地址
    //5. compute rank of each grp after sorting
    //6. strcat string into Table according to rank 

    int i, j, where;
    int row; //最終會record word的last row

    int len=strlen(M);
    
    int * value_in = (int*) calloc( (len+1)*2 ,sizeof(int)); //inner layer
    int ** value = (int**) calloc( (len+1) , sizeof(int*)); //store value and position of each grp of str
    //value[0] is value of each grp of word, value[1] is rank

    for(i=0;i<len+1;i++) 
    {
        value[i]=&value_in[i *2];
    }
    

    char * word_in = (char *) calloc( (len+1) * (len+1) , sizeof(char) ); //inner layer,table to store words
    char ** word = (char **) calloc( (len+1) , sizeof(char*) );
    for(i=0;i<len+1;i++) 
    {
        word[i]=&word_in[i * (len+1)];
    }

//task 1: 把str 以數字分開一組組,extract數字的值

    j=0, row=0, where=0;    
    
    for(i=1;i<len+1;i++)
    {
        if(M[i]>='0' && M[i]<='9') //M[i]is num->把前面store到word的一row
        {
            
            j=0;
            value[row][0] = M[where]-'0';
            for(int k=where+1;k<i;k++)
            {
                word[row][j]=M[k];
                j++;
            }
            where = i;
            row++;
        }
    } //row = last row of word after this for loop
    j=0;
    value[row][0] = M[where]-'0';
    for(int k=where+1;k<i;k++)
    {
        word[row][j]=M[k];
        j++;
    }
    
    row++;

    char*** pt2word = (char***)malloc((row) * sizeof(char**));
    for(i=0;i<row;i++) pt2word[i]=&word[i];
    //this pointer指向word
    void* tmppt;
    
    /*
    Remark: pt2word是array of pointers; pt2word[i]儲存的是Addr of word[i],亦是word[i]代表的string
    */
    
    //task 4: 跟據Value排序
    
    //由尾sort上前
    for(i=0;i<row;i++) value[i][0]=value[i][0]%P;

    for(i=0;i<row;i++)
   {
        for(j=row;j-i>1;j--)
        {
            if( value[j-1][0] < value[j-2][0] ) //最尾細過尾2->最尾&尾2調轉
            {
                int tmp;
                tmp=value[j-2][0];
                value[j-2][0]=value[j-1][0];
                value[j-1][0]=tmp;      

                tmppt=pt2word[j-2];
                pt2word[j-2]=pt2word[j-1];
                pt2word[j-1]=tmppt;        
            }
        }
   }
   
//task 5 : compute rank of each grp
   value[0][1]=0;
   for(i=1;i<row;i++)
   {
       value[i][1]=value[i-1][1];
       if( value[i][0] > value[i-1][0] ) value[i][1]++;
   }
/*
    printf("value:\n");
    for(i=0;i<row;i++) printf("%d %d\n", value[i][0], value[i][1]);
    printf("after sorting:\n");
    for(i=0;i<row;i++) {
        printf("%s", *(pt2word[i]));
    }
*/

  //task 6 : concate str to Table

    
    for(i=0;i<row;i++)
    {
      strcat(ptr[value[i][1]], *(pt2word[i]));

    }
    *(n)=value[row-1][1] +1;


}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define dim 30

char input[100];
char op[3];

char a[dim]={'\0'};
char b[dim]={'\0'};
char tmp[dim];
char bs[501][dim]={'\0'};

void add();
void minus();
void occ();
void find(int num);

int main(void)
{
    int t;
    scanf("%d", &t);
    int i,j;
    getchar();
    while(t--)
    {
        
        fgets(input, dim, stdin);
        int len = strlen(input);
        for(i=0;i<len;i++)
        {
            if(input[i]=='+')
            {
                strncpy(a, input, i-1);
                j=i+2;
                while( input[j] !='\0' && input[j] !='\n')
                {
                    b[j-i-2]=input[j];
                    j++;
                }
                add();

            }
            else if(input[i]=='-')
            {
                
                strncpy(a, input, i-1);
                j=i+2;
                while( input[j] !='\0' && input[j] !='\n')
                {
                    b[j-i-2]=input[j];
                    j++;
                }
                
                minus();
            }
            else if(input[i]=='@')
            {
                int num=0;
                int  h=0;
                strncpy(a, input, i-1);
                j=i+2;
                while( input[j] !='\0'&& input[j] !='\n')
                {
                    
                    
                    if(input[j] !='_')
                    {
                        b[h]=input[j];
                        j++;
                        h++;

                    }
                    else{
                        strncpy(bs[num], b, h);
                    num++;
                    h=0;
                    j++;
                    for(int k =0;k<dim;k++)
                    {
                        b[k]='\0';
                    }


                    }
                    

                }
                find(num);
                
            }

            else if(input[i]=='/')
            {
                
                strncpy(a, input, i-1);
                j=i+2;
                while( input[j] !='\0' && input[j] !='\n')
                {
                    
                    b[j-i-2]=input[j];
                    j++;
                    
                
                }
                occ();
            }
        }

            
            
            
        
        for(i=0;i<dim;i++)
        {
            a[i]='\0';
            b[i]='\0';
        }
        for(i=0;i<100;i++)
        {
            input[i]='\0';
        
        }

        

    }



    return 0;
}

void add()
{
    strcat(a, b);
    printf("%s\n", a);
}

void minus()
{
    //printf("now in minus\n");
    int i,j,k;
    int blen = strlen(b);
    int alen = strlen(a);
    printf("lena: %d, lenb:  %d\n", alen, blen);
    int flag=0;
    int found=0;
    for(i=0;i<alen;i++)
    {
        flag=0;
        for(j=0;j<blen;j++)
        {

            if(a[i+j] == b[j]) flag++;
            
            
        }
        if(flag == blen) 
        {
            for(j=i;j<alen;j++)
            {

                a[j]=a[j+blen];
            
            }
            found=1;
            break;
        }
        if(found==0) break;

    }
    if(found == 0) printf("error\n");
    printf("%s\n", a);

}

void occ()
{
    
    int i,j,k;
    int blen = strlen(b);
    int alen = strlen(a);
    //printf("lena: %d, lenb:  %d\n", alen, blen);
    int flag=0;
    int found=0;
    for(i=0;i<alen;i++)
    {
        flag=0;
        for(j=0;j<blen;j++)
        {

            if(a[i+j] == b[j]) flag++;
            
            
        }
        if(flag == blen) 
        {
            found++;
            
        }
        

    }
    printf("%d\n", found);
    

}

void find(int num)
{
    
    return;
}

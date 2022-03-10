/* 13438 - Lucky money 1 HW 1 */
/* create serise of number
指令: 指示排第A的number向右移K格
方法:doubly link list
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* prev;
    struct _Node* next;
}Node;

Node* head;
FILE *filo_in;

Node* createList(int n);
void solve(int n, int m);
//n=no. of ppl, m=no. of operation

void print_qeue(int n);


int main(){

    int n, k;//k=m=no. of operation
    filo_in = fopen("input.txt", "r");

    printf("give no. of ppl, no. of op: ");

    fscanf(filo_in, "%d%d", &n, &k);
    head = createList(n);
    solve(n, k);
    
    fclose(filo_in);

    return 0;
}

Node* createList(int n)
{
    Node * tmpprev= (Node *)malloc(sizeof(Node));
    tmpprev->prev=NULL;
    tmpprev->next=NULL;
    tmpprev->number=0;
    head=tmpprev;
    for(int i=1;i<=n;i++)
    {
        Node * cur= (Node *)malloc(sizeof(Node));
        cur->prev=tmpprev;
        cur->next=NULL;
        cur->number=i;
        tmpprev->next=cur;
        tmpprev=cur;
    }
    Node * tail= (Node *)malloc(sizeof(Node));
    tmpprev->next=tail;
    tail->prev=tmpprev;
    tail->number=0; //indicate its tail

    return head;
}

void solve(int n, int m)
{
    //n=no. of ppl, m=no. of operation
    print_qeue(n);
    int who; //A (who to move)
    int num; //K: how many pos to move
    Node ** qeue=(Node **)malloc(sizeof(Node *)*(n+1));
    Node * tmp=(Node *)malloc(sizeof(Node));
    tmp=head;
    //build queu

    for(int i=1;i<=n;i++)
    {
        qeue[i]=tmp;
        tmp=tmp->next;

    }//build queu


    while(m--)
    {
        printf("give who to move, how many pos: ");
        fscanf(filo_in, "%d %d", &who, &num); 
        //每次iteration move後一格

        Node ** cur=(Node **)malloc(sizeof(Node*));
        (*cur)=head;
        for(int i=0;i<who;i++)
        {
            (*cur)=(*cur)->next;
        }
        
        for(int i=0; i<num && i<n-who; i++)
        {
            
            (*cur)->next=(*cur)->next->next;
            (*cur)->prev->next=(*cur)->next->prev;
            (*cur)->prev->next->next=(*cur);
            (*cur)->next->prev=(*cur);
            (*cur)->prev->next->prev=(*cur)->prev;
            (*cur)->prev=(*cur)->prev->next;

        }
        print_qeue(n);
    }
}

void print_qeue(int n)
{
    Node ** cur=(Node **)malloc(sizeof(Node*));
    (*cur)=head->next;
    for(int i=0;i<n;i++)
    {
        printf("%d", (*cur)->number);
        if(i!=n-1) printf(" ");
        //else printf("\n");
        (*cur)=(*cur)->next;
    }
}

/*  13134 - Band Ya Rou Ze - AC  */
/* hw 1(week2)*/

#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    /*doubly link*/
    char content;
    struct _Node * next;
    struct _Node * prev;
}Node;

Node * qeue[100001][2]; //hold head and tail of each row
//row 0=head, row 1=tail

void insert(Node * head, Node * tail, char ch);
//insert char to a row

void to_front(Node * ahead, Node * bhead, Node* atail);
//接A去B前

void to_end(Node * ahead, Node* atail, Node * btail);
//接A去B後

void interchage(Node * ahead, Node * bhead, Node * atail, Node* btail);
//interchage A,B

//print
void print_qeue();


int main()
{
    
    int N; //no. of row
    int row=0; // which row now
    int Q; //number of operation
    int num; //number of char in each row.
    //printf("give N (no. of rows): ");
    scanf("%d", &N);
    while(N-1>=row++) //row由1開始
    {
        Node * head = (Node*)malloc(sizeof(Node));
        Node * tail = (Node*)malloc(sizeof(Node));
        qeue[row][0]=head;
        qeue[row][1]=tail;
        //if(qeue[row][0]==NULL) printf("fail record head!\n");

        head->prev=NULL;
        head->next=tail;
        head->content='\0';
        tail->prev=head;
        tail->content='\0';
        tail->next=NULL;

        //printf("give no. of char in this row: ");
        scanf("%d", &num);//ppl in the row
        while(num--)
        {
            
            char ch;
            //scan char and put into list
            scanf(" %c", &ch);
            insert(head, tail, ch);

        }
    }
        
        //printf("give no. of operation (Q): ");
        scanf("%d", &Q);//no. of ops
        while(Q--)
        {
            int op;
            int rowa;
            int rowb;
            scanf("%d %d %d", &op, &rowa, &rowb);

            switch(op)
            {
                case 1:
                    
                    to_front(qeue[rowa][0], qeue[rowb][0], qeue[rowa][1]);
                    break;

                case 2:
                    
                    to_end(qeue[rowa][0], qeue[rowa][1], qeue[rowb][1]);
                    break;

                case 3:
                    interchage(qeue[rowa][0], qeue[rowb][0], qeue[rowa][1], qeue[rowb][1]);
                    break;

                default:
                    printf("wrong operation!\n");
                    break;
            }
            //do operation
        }
    
    print_qeue();
    
    return 0;
}

void insert(Node * head, Node * tail, char ch)
{
    Node * tmp= (Node *)malloc(sizeof(Node));
    tmp->prev=tail->prev;
    tail->prev->next=tmp;
    tmp->next=tail;
    tail->prev=tmp;
    tmp->content=ch;

}

void print_qeue()
{
    
    int i=1;
    for(i=1;i<100000;i++)
    {
        
        if(qeue[i][0]==NULL) break;
        Node ** tmp=malloc(sizeof(Node **));
        (*tmp)=qeue[i][0]->next;
        //printf("printing row %d..  ", i);   
        while((*tmp) != qeue[i][1])
        {

            printf("%c", (*tmp)->content);           
            Node *tmp2=(*tmp);
            (*tmp)=(*tmp)->next;
            free(tmp2);
        }
        //if(qeue[i+1][0]==NULL) break;
        printf("\n");
    }
    if(i>10000) printf("\n");
}

void to_front(Node * ahead, Node * bhead, Node* atail)
{
    
    if(ahead->next == atail) return; //a is empty->nothing to do
    ahead->next->prev=bhead;
    atail->prev->next=bhead->next;
    bhead->next->prev=atail->prev;
    bhead->next=ahead->next;
    ahead->next=atail;
    atail->prev=ahead;
    
    return;

}

void to_end(Node * ahead, Node* atail, Node * btail)
{
    if(ahead->next == atail) return; //a is empty->nothing to do
    ahead->next->prev=btail->prev;
    atail->prev->next=btail;
    btail->prev->next=ahead->next;
    btail->prev=atail->prev;
    ahead->next=atail;
    atail->prev=ahead;

    return;
}

//....

void interchage(Node * ahead, Node * bhead, Node * atail, Node* btail)
{
    
    if(ahead->next == atail) //a是吉的
    {
        to_front(bhead, ahead, btail); //即b換去a
        return;
    }
    else if(bhead->next == btail) //b是吉的,即a換去b
    {
        to_front(ahead, bhead, atail);
        return;
    }
    else
    {
        ahead->next->prev=bhead;
        bhead->next->prev=ahead;
        atail->prev->next=btail;
        btail->prev->next=atail;
        
        Node **tmp=(Node **)malloc(sizeof(Node));
        (*tmp)=ahead->next;
        ahead->next=bhead->next;
        bhead->next=(*tmp);
        (*tmp)=atail->prev;
        atail->prev=btail->prev;
        btail->prev= (*tmp);
        free(tmp);
    }
    

    return;
}

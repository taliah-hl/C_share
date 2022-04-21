#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//題目來源: https://acm.cs.nthu.edu.tw/problem/11891/

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;
//node代表一個字元/operator,有兩支pointer指向其左,右的Node

void constructTree(Node** head);
void printInfix(Node *root);
void freeTree(Node *root);

Node * makeNode(char c); //malloc一粒Node
Node * parser(); //用來理解語法


char s1[100] , s2[100] ;
int idx ;


void printInfix(Node *root){
    if (root != NULL) {
        printInfix(root->left);

        printf("%c", root->data);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf("(");

        printInfix(root->right);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf(")");
    }
}


void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    int n;
    int i , j ;
    scanf("%d", &n);// the number of test cases
    //呢part for 比online system judge,不是重點
    //n=system會比n組輸入來測試此program

    while(n>0)
    {
        scanf("%s" ,s1) ;
        idx = 0 ;
        for(i = 0 ; i < strlen(s1) ; i++){
            s2[i] = s1[strlen(s1)-1-i] ; //s2 是s1的由尾到頭(把s1前後倒轉)
        }
        //s1,s2, idx all global veriable
        Node *root=NULL;
        constructTree(&root);// you have to implement this function
        printInfix(root);//output function
        printf("\n");
        freeTree(root);
        n--;


    }

    return 0;
}

void constructTree(Node ** head)
{
    idx=0;
    (*head)=parser();
    for(int i = 0 ; i < strlen(s1) ; i++)
    {
        s1[i]=s2[i]='\0';
    }
    return;
}

Node * parser()
{
    
    Node *node;
    char c;
    c=s2[idx];
    //printf("now idx=%d..  c=%c\n", idx, s2[idx]);
    if(c>='A' && c<='D')
    {
        node=makeNode(c);
        idx++;
    }
    else if(c=='&' || c=='|')
    {
        node=makeNode(c);
        idx++;
        node->right=parser();
        node->left=parser();
    }
    else{
        //printf("Wrong syntax!\n");
        return NULL;
    }

    return node;

}

Node* makeNode(char c)
{
    Node * node=(Node *)malloc(sizeof(Node));
    node->data=c;
    node->left=NULL;
    node->right=NULL;

    return node;
}

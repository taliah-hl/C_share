/* Final Revision. */
#include<stdio.h>
#include<stdlib.h>

/* 1) malloc */
int main(void){
  
// create 3 layer array of col * row * k  
   int col=3, row=3, k=3;
   int * arr_c = (int*)malloc( col * row * k * sizeof(int));//inner layer
   int * arr_r = (int*)malloc( row * k * sizeof(int*)); //middle layer
   int *** arr_outer = (int ***)malloc(k * sizeof(int **)) //outer layer
    
   for(int i=0;i<row*k;i++) //i<高D嗰層的size
   {
       arr_r[i] =  arr_c + col* i;
   }
   for(int i=0;i<k ;i++)  //i<高D嗰層的size
   {
     arr_outer[i] =  arr_r + row* i;
   }
  free(arr_outer[0][0]); //先free最內層
  free(arr_outer[0]);
  free(arr_outer);
    

/* 2) typedef */

  typedef struct _object{     //_object這個不重要
    char name[50];
    int occu;
    int age;
  }object;  //這個才是type的name
  
  /* 3) qsort */
  //qsort的compare fn
  int compare(const void *a, const void *b){
    object ap = *(object *)a;
    object bp = *(object *)b; //type cast做原本要sort的object的type, 再deref一次, then assign to bp
    //bp的type is object, not pointer to object!
    if(ap < ba) return -1; //-1=ap排先
    if(ap > ba) return 1;  //1=ap排後
    if(ap == ba) return 0;
  }
  
  qsort(arr, k, sizeof(object), compare); //sort arr裡的element
  //k is size of arr, object是arr裡的element的type
  
  /* 4) Bitwise Operation*/
  //XOR ^
  /* ^1 = XOR 1 = +2bit但唔進位
  e.g. 1st bit = 0/1, 2nd bit = 2/3, 3rd bit = 4/5
  1^1=0; 0^1=1; 
  2^1=3; 3^1=2;
  4^1=5; 5^1=4
  通常用在把0/1反轉
  */
  int i=0;
  int j=1;
  printf("%d %d %d %d", i, i^1, j, j^1);
  //will priint 0 1 1 0
  

}



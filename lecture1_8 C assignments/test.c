#include <stdio.h>
#include "../../libs/STD_Types.h"
#define string_size 50
// struct person {int x,y};
// #define MAX(x,y) ((x)>(y)?(x):(y))
const int x=10;
void main(void)
{
  //=============== 20/3/2023 ================================
  /* 
  int (*ptr)[4];
  int arr[3];
  ptr++;  // step is 4(int) x 4([]) => 16bytes whatever arr is!!
  -------------------------------------------
  char* ptr="word"; // "word" saved in .ordata(ROM) 
        *ptr="ahmed"; // Run time error.
        ptr = "Ahmed"; // allowed "Ahmed" new save in .rodata. 
  -------------------------------------------------------
  #pragma pack(1)
  typedef struct test
  {
     short int x;
     char a;
     double z;
     int y;
  }Struct;

  printf("%d",sizeof(Struct));
  --------------------------------------------------------------
  typedef struct test
  {
  short int x;
    int y;
  }data;
  data D;
  data* ptr =&D;
  *ptr.x=50; // compiler error (.) is higher periorty than (*)  
  (*ptr).x=50; // run now (*) is higher periorty than (.)  
  ptr->x=500;
  -------------------------------------------------------
   */
  int* ptr1;
  const int *ptr2;
  int* const ptr3;
  const int* const ptr4;
  
  
  ptr1=&x;
  *ptr1=100;
}
/* 
 u8 a = 0b0010;
 u16 counter = 0;
 u8 value = 1;
 u16 num = 0x03;
 u16 *number = &num;
 for (u8 i = 0; i < sizeof(*number) * 8; i++)
 {
   if (((*number >> i)&(1)) == value)
   {
     counter++;
   }
 }

 printf("%d",counter);
*/
/* struct person p={1,2},*ptr;
  ptr=&p;
 printf("%d ",ptr->y);

  int x=10;
  const int* const ptr=&x;
  x=20;
  printf("%d",*ptr);

  int a=19,b=20;
  printf("%d",MAX(a++,b--));
  printf("  %d  %d",a,b);
  */

/*
// Rccap on pointers.
u8 x=25;
u8* ptr=&x;
*ptr=50;
printf("x-> %d\n",x);
printf("*ptr-> %d\n",*ptr);
//-------------------------
u8 x=250;
u32* ptr=&x;
*ptr =1000;
printf("x-> %d\n",x);
printf("*ptr-> %d\n",*ptr);
//----------------------------
u32 x=250;
u32* ptr=&x;
*ptr =1000;
printf("x-> %d\n",x);
printf("*ptr-> %d\n",*ptr);
//___________________________________________
wild pointer cause run time error  at most. in function garbge address garbge value.
// *ptr=50;
u8 x;
u8 y;
u8* ptrx=&x;
u8* ptry=&y;
printf("x-> %d\n",ptrx==ptry);
//printf("*ptr-> %d\n",ptr);
// you
*/


/* typedef enum {
  sat,sun,mon,tues
}day_t;
 typedef struct test
 {
   int x;
  unsigned char y;
 }test_t;


/* int* func(void){
static int global=20;

int* ptr_global=&global;
    int x=10;
    return &x;
}
void func1(int* ptr){
    *ptr=255;
    printf("%d",*ptr);
}
 // valid to return a struct from functions.
struct test func(void){
  struct test nt={500,213};
 return nt;
}

int func1(void){
  int  x[10] ={10};
 return x[0];
}
  void main(){
  /*   short ptr=100;

   // ptr=func();
    printf("%d\n",ptr);
       //  change in static local variable in function.
    //func1(ptr); */
/* test_t arr[10];
for (int i = 0; i < 10; i++)
{
  arr[i].x=5+i;
  arr[i][y]=i*i;
  printf("%d -> %d\n",arr[x],arr[y]);
}
float x=mon;
printf("arf\v%f",x);


}  */
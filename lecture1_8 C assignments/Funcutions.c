long square(int num)
{
	return ((long)(num * num));
}
// global vars
int a = 5, b = 10;
void sawp(void)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
// even-> 0  || odd-> 1
char even_odd(int num)
{
	if (num % 2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
// global vars
int max, min;
void max_min(int a, int b, int c)
{
	if (a > b && a > c)
	{
		max = a;
		min = (b < c) ? b : c;
	}
	else if (b > a && b > c)
	{
		max = b;
		min = (a < c) ? a : c;
	}
	else if (c > a && c > b)
	{
		max = c;
		min = (a < b) ? a : b;
	}
}
// prime -> 0 || not prime -> 1
char prime(int num)
{
	if (num==0|| num==1 )
	{
		return 1;
	}
	for (char i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			return  1;
		}
	}
	return 0;
}
void re_even(int n){
	
	if(n<2)
	{
	   printf ("no even positive numbers !.");
	   exit(1);
	}
	else if (n%2!=0&&n>2)
	{
		re_even(n-1);
	}
	else if (n%2==0&&n>2)
	{
		re_even(n-2);
		printf(" %d  ",n);
	}

	

}
void re_sum(int n){
	int  temp=n%10;
	static int res=0;
	res+=temp;
	if (n==0)
	{
		printf("= %d ",res);
	}
	else{
		re_sum(n/10);
	}
}
/* swap with pass by reference. */
void swap(int* num1,int* num2){
	int temp;
	temp =*num1;
	*num1=*num2;
	*num2=temp;
}
void bubble_sort(int* arr,int size){
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (*(arr+i) > *(arr+i+1))
			{
				int temp;
				temp=*(arr+i);
				*(arr+i)=*(arr+i+1);
				*(arr+i+1)=temp;
			}
		}
	}
	
}
void get_array(int* arr, int size){
	for (int  i = 0; i < size; i++)
	{
		scanf("%d",(arr+i));
	}
	
}
void print_array(int* arr,int size){

	for (int  i = 0; i < size; i++)
	{
		printf("\nelment(%d):%d",i,*(arr+i));
	}
}
//------------- assignements day 10/3/2023--------------------
//=== problem 1 ====
//string (" .... .. ....... .... ..... ...  ")
int tallest_word(const char arr[]){
	int counter=0,result=0;

	for (int  i = 0; arr[i]!='\0'; i++)
	{
		/* if (arr[i]!=' ')
		{
			counter++;
		} */
		if ((arr[i]>='a')&&(arr[i]<='z'))
		{
			counter++;
		}
		
		else{
		 if(result<counter){
			result=counter;
		}
		counter=0;
		}
		
	}
	
	return result;
}
//=== problem 2 ===
//string ("abdexfrmnopr-----------)
int tallest_ascii_sequence(const char arr[]){
	int counter=1,result=0;
	int first=arr[0];
	for (int  i = 1; arr[i]!='\0'; i++)
	{
		if ((first+i)==(int)arr[i])
		{
			counter++;
		}
		else{
		
		first=arr[i]-i;
		counter=1;
		}
		 if(result<counter){
			result=counter;
		}
		
	}
	
	return result;
}
// === problem 3 ===
//var=1011101110101110101111111101011111 ------ 
int tallest_sequence(const int arr[],int size){
	int counter=0,result=0;
	for (int  i = 0; i<size; i++)
	{
		if (arr[i]==1)
		{
			counter++;
		}
		else{
		 if(result<counter){
			result=counter;
		}
		counter=0;
		}
		
	}
	
	return result;
}
/* char str[100];
scanf("%[^\n]s",str);
printf("%s\n",str);
printf("\ncounter is :%d",tallest_word(str)); 
//-------------------------------------------
 /*    char str[100];
	scanf("%[^\n]s",str);
	printf("%s\n",str);
	printf("\ncounter is :%d",tallest_ascii_sequence(str));
	return 0; 
//-------------------------------
  /*  int size= 15;
   int sequence[15];
   for (int i = 0; i < size; i++)
   {
   	scanf("%d",&sequence[i]);
   }
	printf("\ncounter is :%d",tallest_sequence(sequence,size)); */

















//======================================================================================
/* temp=x;
		int x=5;
		int y=6;
			x=y;
			y=temp; 

		 x=x+y;
			y=x-y;
		x^=y;
		y^=x;
		x^=y;

		printf("x=%d  , Y=%d",x,y);
			//lab 1
			printf("working hours: ");
			scanf("%d",&x);

			if (x>40)
			{
				y= 50*x;
			}else{
				y=50*x;
				y=y-y*.1;
			}
			printf("\n the salary is :%d ",y);

		// lab2
		printf(" inter the number: ");
			scanf("%d",&x);
		if (x%2==0)
		{
			printf(" %d is even",x);
		}
		else{
			printf(" %d is odd",x);

		}
		// lab3
		int grade ;
		printf(" inter the grade: ");
			scanf("%d",&grade);
		if (grade>0&&grade<50)
		{
			printf("Fail");
		}else if (grade>50&&grade<65)
		{
			printf("Normal");
		}else if (grade>65&&grade<75)
		{
			printf("Good");
		}else if (grade>75&&grade<85)
		{
			printf("Very Good");
		}
		else if (grade>85&&grade<=100)
		{
			printf("Excellent");
		}

		 // note tenary operator;
		 int age;
		 scanf("%d",&age);
		 (age>18)?(age>60)? printf(">60"):printf("18>,<60"):(printf("u can't vote"));

		switch (age)
		{
		case 0:
		 printf("case 0\n");
		case 2 ... 7:      // range in switch
		printf("\nvalid");
			break;

		default:
			break;
		}
		//lab 4
		 int ID;
		scanf("%i",&ID);
		switch (ID)
		{
		case 1234:printf("Ahmed");	break;
		case 5678:printf("Youssef");break;
		case 1145:printf("Mina");	break;
		default:printf("Wrong ID");	break;
		}
		// lab5
		char count=10;
		float num;
		float sum=0;
		float average=0;

		for (char  i = 0; i < count; i++)
		{
			scanf("%f",&num);
			sum+=num;
		}
		average=sum/count;
		printf("sum : %.2f , average: %.2f",sum,average);
	  //lab 6
	  char r;
	  printf(" the result of 3x4 is :");
	  do
	  {
		scanf("%d",&r);
		printf("anwser is wrong! try again");
	  } while (r!=12);

	  printf("\n thank you .");
			
		//========== day2 =====================
		 #define assignment_1
		 //#define assignment_2
			int input;
			char end;
			int* p;
			printf("size %d",sizeof(p));
		  #ifdef assignment_1
			//input -> 1234 	output -> 1+2+3+4
			printf(" enter the number: ");
			if (scanf("%d%c",&input,&end)==2&&end=='\n')
			{
				printf("valid integer \n");
				int result=0;
				do{
				result+=input%10;;
				input=input/10;
				}while (input!=0);

				printf("sum of digits is : %d\n",result);
			}
			else{
				printf(" Not valid !");
			}
			#endif
		// assignment 2
			//input -> 1234 	output -> 4321
		 #ifdef assignment_2
			printf(" \n enter the number: ");
			scanf("%d",&input);
			printf(" \n the number reversed : ");
			do{
			printf("%d",input%10);
			input=input/10;
			}while (input!=0);
		#endif */
		//------------------------------------------------------------
		/* 	
	char w;
	int x;
	float y;
	double z;
	long int LI;
	long double LD;
	short sh;
	printf("\nchar ->%d",sizeof(w));
	printf("\nint ->%d",sizeof(x));
	printf("\nfloat ->%d",sizeof(y));
	printf("\ndouble ->%d",sizeof(z));
	printf("\nlong int ->%d",sizeof(LI));
	printf("\n long double ->%d",sizeof(LD));
	printf("\n short ->%d",sizeof(sh));

 */
 
 /*const	int x=120;
int main()
{	
 char str[50];
 scanf("string : %[^\n]s",str);
 printf("\n string : %s",str); 
	int* ptr1=&x;
	int** ptr2=&ptr1;
	**ptr2=123;
	printf("%d",x); 
	int x=5,y=10;
	int* ptr1=&x;
	int* ptr2=&y;
	printf("%i",(ptr1-ptr2));
	*/


/* printf("\nsize of u8 -> %ld",sizeof(u8 ));
printf("\nsize of s8 -> %ld",sizeof(s8));
printf("\nsize of u16 -> %ld",sizeof(u16));
printf("\nsize of s16 -> %ld",sizeof(s16));
printf("\nsize of u32 -> %ld",sizeof(u32));
printf("\nsize of s32 -> %ld",sizeof(s32));
printf("\nsize of f32 -> %ld",sizeof(f32));
printf("\nsize of f64 -> %ld",sizeof(f32));
printf("\nsize of size_t -> %ld",sizeof(size_t)); */
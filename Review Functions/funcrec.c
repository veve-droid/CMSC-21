#include <stdio.h>


int divide(int, int, int);
int relative(int a, int b);
int search(int[], int, int);


int main(){

	int menu, valid;
	
	///*****************  enter menu  *****************/// 
	
	///*****************  enter menu  *****************/// 
		
	do{
		
		
		printf("\n1. Division\n");
		printf("2. Relatively Prime\n");
		printf("3. Search\n");
		
		printf("\nChoose from the menu: ");
		scanf("%i", &menu);
		
		valid = 1;
		if(menu < 1 || menu > 3)
			valid = 0;
		
	}while(!valid);
	
	
	
	//************* division *************// 
	
	//************* division *************// 
	
	if(menu == 1){
		int valid, a, b, quotient=0;
		
		do{
		
			printf("\nEnter two positive integers: ");
			scanf("%i%i", &a, &b);
			
			valid = 1;
			if(a < 1 || b < 1)
				valid = 0;
		
		}while(!valid);
		
		//quotient is initialized to 0, then it will increment only if a is greater than or equal to b.
		printf("%i\n\n", divide(quotient, a,b));
		return 0;
	
	
	}
	
	
	
	//************* relatively prime *************// 
	
	//************* relatively prime *************// 
	
	else if(menu == 2){	
		int a, b, temp;
		
		//enter input
		printf("\nEnter two positive integers: ");
		scanf("%i%i", &a, &b);
				
		
		//switch if a is less than b example:
		//if 3,10 then 10,3 //then proceed to get the gcd 
		
		if(a<b){
			temp = a;
			a = b;
			b = temp;
		}
		
		printf("%i\n\n", relative(a,b));
		return 0;		
	}
	
	
	
	//************* search *************// 
	
	//************* search *************// 
	
	else{
	
	int valid, arr[20], find, x, i, j;
		
		//// how many integers ////
		
		do{
		
			printf("\nEnter integers from 2-20: ");
			scanf("%i", &x);
			
			valid = 1;
			if(x < 2 || x > 20)
				valid = 0;
		
		}while(!valid);
		
		//// should be in ascending order ////
			for(i=0; i<x; i++){

				printf("Enter 10 sorted integers [%i/10]: ",i+1);
				scanf("%i", &arr[i]);
				
				/// check if sorted
				
				for(j=i-1; j>=0; j--){
					
					while(arr[i] <= arr[j]){
					
						printf("Integers must be sorted! Re-enter.\nEnter 10 1-digit integers [%i/10]: ",i+1);
						scanf("%i", &arr[i]);
						
					}
				}
					
			}
		
		//// search for ////
		
		printf("\nSearch for: ");
		scanf("%i", &find);
		
		
		/// printf ///
		printf("%i\n\n", search(arr, find, x));
		return 0;	
		
		}

}







	int divide(int count, int a, int b){
		
		if(a<b)
			return count;
			
		else //count would be the quotient
			//the recursive part is a-b
			//b would remain the same value
			//while a-b is not less than b, 
			//count will increment and the result will be the quotient
			
			return divide(count+=1, a-b, b);
			
	}
	
	
	
	
	
	int relative(int a, int b){
		int r, temp1=a, temp2=b;
			
		//to avoid floating point core dump when a is divided by 0
		if(b==0){
			if(a==1) //0 is only co-prime with 1
				return 1;
			else
				return 0;
		}
		
		//if b is not 0 then perform a % b 
		//which is a = the bigger number and
		//b is the smaller number
		
		else
		r = temp1 % temp2;
		
		while(r!=0){ //gets the gcd of a and b
			if(r == 1 || r == -1) //if the remainder is 1 or -1, then relatively prime
				return 1;
				
			else
				return relative(temp2,r);
		}
		
		//if remainder is not equal to one then return 0
		if(r != 1)
			return 0;
	}
	
	
	
	
	
	int search(int A[], int find, int input){
		
		if(input>0){
			if(A[input - 1] == find)
				return 1;
			else
				return search(A, find, input-1);
		}
	
		else
			return 0;
		
	}

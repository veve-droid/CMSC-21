#include <stdio.h>

	////////// functions /////////////

int leap(int);
int daySum(int, int, int);
int remainderR(int, int);
int dayOfWeek(int, int);

int main(){
	int year, month, day, valid, a, b;
	char* st[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	
	////////// enter input /////////////

	do{
		printf("Enter birth year: ");
		scanf("%i",&year);
	}while(year<1);
	
	do{
		printf("Enter birth month: ");
		scanf("%i",&month);
		
		valid = 1;
		if(month < 1 || month > 12)
			valid = 0;
	}while(!valid);
	
	do{
		printf("Enter birth day: ");
		scanf("%i",&day);
		
		valid = 1;
		
		if(month == 2){
			if((leap(year) == 0 && (day > 28 || day < 1)) || (leap(year) == 1 && (day > 29 || day < 1)))
				valid = 0;
		}
		else if(month < 8){
			if((month % 2 == 1 && (day > 31 || day < 1)) || (month % 2 == 0 && (day > 30 || day < 1)))
				valid = 0;
		}
		
		else {
			if((month % 2 == 0 && (day > 31 || day < 1)) || (month % 2 == 1 && (day > 30 || day < 1)))
				valid = 0;
		}	
		
	}while(!valid);



	////////// printf  /////////////
	
	a = daySum(month, day, year);
	b = dayOfWeek(a,year);
	
	printf("\n");
	
	if(a % 10 == 1)
		printf("%s, %ist day of the year", st[b], a);
	
	else if(a % 10 == 2)
		printf("%s, %ind day of the year", st[b], a);
		
	else if(a % 10 == 3)
		printf("%s, %ird day of the year", st[b], a);
	
	else 
		printf("%s, %ith day of the year", st[b], a);
	

	printf("\n");


}



	////////// leap year function /////////////

int leap(int x){
	int leap;
	
	if(x % 4 == 0){
		if(x % 100 != 0)
			leap = 1;
		else
			if(x % 400 == 0)
				leap = 1;
			else
				leap = 0;		
	}
	
	else
		leap = 0;
		
	return leap;
}

	////////// nth day /////////////
	
int daySum(int a, int b, int c){
	int i, sumDay;
	
	for(i=1, sumDay=0; i<a; i++){
		if(i==2){
			if(leap(c) == 0)
				sumDay = sumDay + 28;
			else
				sumDay = sumDay + 29;
		}
		
		else if(i<8){
			if(i % 2 == 1)
				sumDay = sumDay + 31;
			else
				sumDay = sumDay + 30;
		}
		
		else{
			if(i % 2 == 0)
				sumDay = sumDay + 31;
			else
				sumDay = sumDay + 30;
		}
	}
	
	return sumDay + b;
}

	////////// remainder for gauss's method /////////////

int remainderR(int m, int n){
	int rem;
	
	rem = (m) % n;
	
	return rem;
}

	////////// gauss's method /////////////

int dayOfWeek(int y, int z){
	int D, dW;
	

	D = (1+(5 * remainderR(z-1,4))+(4 * remainderR(z-1,100))+(6 * remainderR(z-1,400))) - 1; //minus 1 because Gauss's method is to find the week day of January 1st in a given year.
	
	dW = remainderR(D+y,7); //add the nth number then get mod 7 to find the day of the week
	
	return dW;
}

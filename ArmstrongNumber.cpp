#include <iostream>
#include <math.h>
using namespace std;

int numberLength(int number);
int main()
{
	system("clear");
 int number =0;
 int digit = 0;
 int armstrong =0;
 int tenMultiple = 0;
 int exponential = 0;
 cout<<"insert the number"<<endl;
 cin>>number;
 
tenMultiple=(numberLength(number)-1);
exponential=(tenMultiple+1);
 
 for(int i =1;i<=exponential;i++)
 {
 	if (i==tenMultiple)
 	{
 		digit = (number%10);
 	}
 	else
 	{
 		
 		digit = (number)/(int)pow(10,tenMultiple)%10;
 		tenMultiple--;
 		
 	}
 		armstrong += pow(digit,exponential);
 		;
 }

 if(number == armstrong)
 {
 	cout<<endl<<"---------------------"<<endl;
 	cout<< "The number: "<<number<<" is an armstrong number.";
 	cout<< "The sum of its digits powered to the " <<exponential<< " (cardinality of the original number) is: "<<armstrong<<".";
 }
 else
 {
	cout<<"The number: "<<number<<" is NOT an armstrong number.";
 }

	return 0;
}

int numberLength(int number)
{
	int count=0;
	while (number>0)
	{
		count++;
		number=(number/10);
	}
	return count;
}
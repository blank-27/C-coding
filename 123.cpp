#include<iostream> // for performing basic I/O operations
#include<fstream> // for making test case files and to use them later
#include<time.h> // to use clock() function to calculate time elapsed
#include<iomanip> // to use setprecision to print time with precise value

using namespace std ;
int n;

// swap function

void swp(int &a, int &b){
int temp=a;
a=b;
b=temp;
}

// selection sort - Time Complexity O(N^2)

void SelectionSort(int arr[]) {

for(int i=0; i<n-1; i++) {
int ind=i; // ind will store index of minimum value
for(int j=i+1;j<n;j++) {
if(arr[j]<arr[ind]) {
ind=j;
}
}
swp(arr[ind],arr[i]);
/* swapping minimum value firstly with 0th index, then second min value to 1st index
and so on */
}

}

void InsertionSort(int arr[]) {

for(int i=1;i<n;i++) {
int val=arr[i]; // we will find current accurate location of this value in sorted array
int j=i-1;
for( ;j>=0;j--) {
if(val>=arr[j]){
// means previous element is not more than val so this is exact location of val
break;
}
arr[j+1]=arr[j];
}
arr[j+1]=val;

}

}

void BubbleSort(int arr[]) {

int flag;
// flag is used to check whether any swap takes place in current iteration or not
for(int i=0;i<n-1;i++) {
flag=0 ;
for(int j=0;j<n-1-i;j++) {
if(arr[j]>arr[j+1]) {
/* previous element greater than current element thus breaking rule of sorted array
so we swap it */
swp(arr[j],arr[j+1]);
flag=1;
}
}
if(!flag) break; /* means no swapping takes place in this iteration, so the array is
now sorted */
}

}

int main(){

int choice,t,mod=200000;
clock_t begin,end;
double time_elapsed;

// making test cases

ofstream fout;
fout.open("best.txt",ios::out); /* opening file in write mode which will contain best
cases */
fout<<7<<"\n";
n=10000;
for(int i=1;i<=7;i++){
fout<<n<<"\n";
for(int j=1;j<=n;j++) fout<<j<<" "; // putting sorted numbers in best case file
fout<<"\n";
n+=(20000);
}
fout.close();

fout.open("worst.txt",ios::out);
// opening file in write mode which will contain worst cases
fout<<7<<"\n";
n=10000;
for(int i=1;i<=7;i++){
fout<<n<<"\n";
for(int j=n;j>=1;j--) fout<<j<<" ";
//putting reverse sorted numbers in worst case file
fout<<"\n";
n+=(20000);
}
fout.close(); // closing file

fout.open("average.txt",ios::out);

// opening file in write mode which will contain average cases
fout<<7<<"\n";
n=10000;
for(int i=1;i<=7;i++){
fout<<n<<"\n";
srand(time(0));
for(int j=1;j<=n;j++) fout<<(rand()%mod)+1<<" ";
// putting random numbers in average case file
fout<<"\n";
n+=(20000);
}
fout.close(); // closing file

// choosing between best case , worst case, averahe case

cout<<"1. Best Case \n2. Average Case \n3. Worst Case\n";
cout<<"Select One of the above case: ";
cin>>choice;

if(choice==1){
cout<<"\nBEST CASE:\n";
ifstream fin;
ofstream fout;
fout.open("sorted_insertion.txt",ios::out);
// opening file in which we will write sorted elements to verify the algorithm
cout<<"\nInsertion Sort\n";
fin.open("best.txt",ios::in);
// opening best cases file in read mode to get input for insertion sort
fin>>t;

fout<<t<<"\n";
for(int i=1;i<=t;i++){
fin>>n;
fout<<n<<"\n";
int arr[n];
for(int i=0;i<n;i++) fin>>arr[i];

begin=clock();
// clock() function will give processor time elapsed till now (i.e before algo running )
InsertionSort(arr);
end=clock();
// clock() function will give processor time elapsed till now (i.e after algo running )

for(int i=0;i<n;i++) fout<<arr[i]<<" "; // writing sorted elements into file
fout<<"\n";
time_elapsed=double(end-begin)/double(CLOCKS_PER_SEC);

/*so we can subtract start from end to find processor time taken by algo to run and
then divide
by clocks which executes in one second to get actual time in seconds taken by
algorithm*/

cout<<n<<" : "<<time_elapsed<<" sec\n";
// setprecesion used to print time with more accuracy
}

fin.close(); // closing best.txt file
fout.close();

fin.open("best.txt",ios::in);
// opening best cases file in read mode to get input for selection sort
cout<<"\nSelection Sort\n";
fout.open("sorted_selection.txt",ios::out);
fin>>t;
fout<<t<<"\n";
for(int i=1;i<=t;i++){
fin>>n;
fout<<n<<"\n";
int arr[n];
for(int i=0;i<n;i++) fin>>arr[i];

begin=clock();
SelectionSort(arr);
end=clock();

for(int i=0;i<n;i++) fout<<arr[i]<<" ";
fout<<"\n";
time_elapsed=double(end-begin)/double(CLOCKS_PER_SEC);
cout<<n<<" : "<<time_elapsed<<" sec\n";
}

fin.close(); // closing best.txt file
fout.close();

cout<<"\nBubble Sort\n";
fin.open("best.txt",ios::in);
// opening best cases file in read mode to get input for bubble sort

fout.open("sorted_bubble.txt",ios::out);
fin>>t;
fout<<t<<"\n";
for(int i=1;i<=t;i++){
fin>>n;
fout<<n<<"\n";
int arr[n];
for(int i=0;i<n;i++) fin>>arr[i];

begin=clock();
BubbleSort(arr);
end=clock();

for(int i=0;i<n;i++) fout<<arr[i]<<" ";
fout<<"\n";
time_elapsed=double(end-begin)/double(CLOCKS_PER_SEC);
cout<<n<<" : "<<time_elapsed<<" sec\n";
}

fin.close(); // closing best.txt file
fout.close();
}
else if(choice==2){
cout<<"\nAVERAGE CASE:\n";
ifstream fin;
ofstream fout;

fout.open("sorted_insertion.txt",ios::out);
cout<<"\nInsertion Sort\n";

fin.open("average.txt",ios::in);
// opening average cases file in read mode to get input for inserion sort
fin>>t;
fout<<t<<"\n";
for(int i=1;i<=t;i++){
fin>>n;
fout<<n<<"\n";
int arr[n];
for(int i=0;i<n;i++) fin>>arr[i];

begin=clock();
InsertionSort(arr);
end=clock();

for(int i=0;i<n;i++) fout<<arr[i]<<" ";
fout<<"\n";
time_elapsed=double(end-begin)/double(CLOCKS_PER_SEC);
cout<<n<<" : "<<time_elapsed<<" sec\n";
}
fin.close(); // closing average.txt file
fout.close();

fin.open("average.txt",ios::in);
// opening average cases file in read mode to get input for selection sort
fout.open("sorted_selection.txt",ios::out);
cout<<"\nSelection Sort\n";
fin>>t;
fout<<t<<"\n";

for(int i=1;i<=t;i++){
fin>>n;
fout<<n<<"\n";
int arr[n];
for(int i=0;i<n;i++) fin>>arr[i];

begin=clock();
SelectionSort(arr);
end=clock();

for(int i=0;i<n;i++) fout<<arr[i]<<" ";
fout<<"\n";
time_elapsed=double(end-begin)/double(CLOCKS_PER_SEC);
cout<<n<<" : "<<time_elapsed<<" sec\n";
}

fin.close(); // closing average.txt file
fout.close();

cout<<"\nBubble Sort\n";
fin.open("average.txt",ios::in);
// opening average cases file in read mode to get input for buuble sort
fout.open("sorted_bubble.txt",ios::out);
fin>>t;
fout<<t<<"\n";
for(int i=1;i<=t;i++){
fin>>n;

fout<<n<<"\n";
int arr[n];
for(int i=0;i<n;i++) fin>>arr[i];

begin=clock();
BubbleSort(arr);
end=clock();

for(int i=0;i<n;i++) fout<<arr[i]<<" ";
fout<<"\n";
time_elapsed=double(end-begin)/double(CLOCKS_PER_SEC);
cout<<n<<" : "<<time_elapsed<<" sec\n";
}
fin.close(); // closing average.txt file
fout.close();
}
else{
cout<<"\nWORST CASE:\n";
ifstream fin;
ofstream fout;

cout<<"\nInsertion Sort\n";
fin.open("worst.txt",ios::in);
// opening worst cases file in read mode to get input for insertion sort
fout.open("sorted_insertion.txt",ios::out);
fin>>t;
fout<<t<<"\n";
for(int i=1;i<=t;i++){
fin>>n;

fout<<n<<"\n";
int arr[n];
for(int i=0;i<n;i++) fin>>arr[i];

begin=clock();
InsertionSort(arr);
end=clock();

for(int i=0;i<n;i++) fout<<arr[i]<<" ";
fout<<"\n";
time_elapsed=double(end-begin)/double(CLOCKS_PER_SEC);
cout<<n<<" : "<<time_elapsed<<" sec\n";
}
fin.close(); // closing worst.txt file
fout.close();

fin.open("worst.txt",ios::in);
fout.open("sorted_selection.txt",ios::out);
cout<<"\nSelection Sort\n";
// opening worst cases file in read mode to get input for selection sort
fin>>t;
fout<<t<<"\n";
for(int i=1;i<=t;i++){
fin>>n;
fout<<n<<"\n";
int arr[n];
for(int i=0;i<n;i++) fin>>arr[i];

begin=clock();

SelectionSort(arr);
end=clock();

for(int i=0;i<n;i++) fout<<arr[i]<<" ";
fout<<"\n";
time_elapsed=double(end-begin)/double(CLOCKS_PER_SEC);
cout<<n<<" : "<<time_elapsed<<" sec\n";
}
fin.close(); // closing worst.txt file
fout.close();

cout<<"\nBubble Sort\n";
fin.open("worst.txt",ios::in);
// opening worst cases file in read mode to get input for bubble sort
fout.open("sorted_bubble.txt",ios::out);
fin>>t;
fout<<t<<"\n";
for(int i=1;i<=t;i++){
fin>>n;
fout<<n<<"\n";
int arr[n];
for(int i=0;i<n;i++) fin>>arr[i];

begin=clock();
BubbleSort(arr);
end=clock();

for(int i=0;i<n;i++) fout<<arr[i]<<" ";
fout<<"\n";

time_elapsed=double(end-begin)/double(CLOCKS_PER_SEC);
cout<<n<<" : "<<time_elapsed<<" sec\n";
}
fin.close(); // closing worst.txt file
fout.close();
}

}

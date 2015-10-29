#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(void){
	int n;
	cout << "Enter the number of random numbers to generate \n";
	cin >> n;
	int arr[10] = {0};
	for(int i=0;i < n;++i){
		int val = rand() % 10;
		cout << val << endl;
		arr[val]++;
	}
	int E = (int)n/10;
	double sum=0;
	for(int i=0;i<10;i++)
	{
		cout << "Observed : " << arr[i] << " Expected value: " << E << " ";
		int r=(int)pow((arr[i]-E),2);
			double o = (double)r/E;			
			sum=sum+o;
			cout  << "Chi square for " <<  (i+1) << " is " << o << endl;
		}
		cout << "Final chi square sum " << sum;
}
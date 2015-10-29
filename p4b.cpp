#include <iostream>
#include <cmath>
#include <cstdlib>
#include "linearcong.h"
using namespace std;
int main(void){
	int n;
	cout << "Enter the number of random numbers to generate \n";
	cin >> n;
	int arr[10] = {0};
	LinearCongruentialGenerator l(23483241, 87807, n, 1511);
	for(int i=0;i < n;++i){
		int val = l.next();
		cout << val << endl;
		arr[val%10]++;
	}
	cout << "---------------- Chi Square Test -------------\n";
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

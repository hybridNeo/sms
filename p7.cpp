#include <iostream>
#include <cmath>
#define N 52
using namespace std;
int main(void){
	float arr[N] = {1.88,0.54,1.9,0.15,0.02,2.81,1.50,1.53,2.62,2.67,3.53,0.53,1.80,1.80,0.79,0.21,0.8,0.26,0.63,0.36,2.03,1.42,1.28,0.82,2.16,0.05,0.04,1.49,0.66,0.2,0.3,1,0.34,0.34,0.01,0.10,1.10,0.24,0.26,0.45,0.17,4.29,0.80,5.50,4.91,0.35,0.36,0.90,1.03,1.73,0.38,0.48};

	int bin[5] = {0};
	for(int i = 0;i < N;++i){
		bin[(int)arr[i]] += 1;
	}
	int out[100][6] = {0};
	for(int i =0;i<=4;++i){
		//cout << "i=" << i << "(" <<  bin[i] << ")\t" ;
		for(int j=0;j<bin[i];++j){
			//cout  << "\t" << bin[i] << "\t" << j << "\t" << i << endl;
			out[j][i] =1;
		}
	
		cout << endl;

	}
	for(int i = N; i >= 0; --i){
		
		for(int j = 0; j < 5;++j)
		{	if(out[i][j] == 1)
				cout << "*\t";
			//cout << endl;
		}
		cout << endl;
	}
}

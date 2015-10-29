#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
class info{
	public:
	int iat;
	int at;
	int start1;
	int start2;
	int st1;
	int ft1;
	int wt1;
	int st2;
	int ft2;
	int wt2;
	int time;
};
int get_iat(int n){
	if(n >= 80)
		return 15;
	if(n >= 50)
		return 10;
	return 5;
}
int get_st(int n){
	if(n >= 80)
		return 12;
	if(n >= 30)
		return 8;
	return 4;
}
int main(void){
	cout << "Estimation of Absolute Performance \n ***********************\n";
	int T;


	cout << "Enter the number of runs to perform \n";
	cin >> T;
	int N = T;
	int y_arr[N];
	int avg = 0;
	while(T--){
		int n = 10;
	//	cout << "--------time in system:--------------------\n";
		info result[n];
		result[0].start1 = 0;
		result[0].at = 0;
		result[0].ft1 = 10;
		result[0].wt1 = 0;
		result[0].start2 = result[0].ft1;
		result[0].st2 =get_st( rand()%100);
		result[0].ft2 = result[0].st2 + result[0].start2;
		result[0].wt2 = 0;
		result[0].time = result[0].ft2 - result[0].at;
		//cout << result[0].time << endl;
		for(int i =1;i<n;++i){
			result[i].iat = get_iat(rand() % 100);
			result[i].at = result[i-1].at + result[i].iat;
			result[i].start1 = result[i-1].ft1;
			result[i].wt1 = result[i].start1 - result[i].at;
			result[i].ft1 = result[i].start1 + 10;
			result[i].start2 = result[i].ft1;
			result[i].st2 = get_st(rand() %100);
			result[i].ft2 = result[i].st2 + result[i].start2;
			int temp = result[i-1].ft2 - result[i].start2;
			result[i].wt2 = (temp)>0 ?temp :0;
			result[i].time = result[i].ft2 - result[i].at;
		//	cout << result[i].time << endl;
			
		}
		int tot_time = 0;
		for(int i=0;i<n;++i)
		{
			tot_time += result[i].wt1 + result[i].wt2;
		}	
		cout << "-------------------------------\n";
		int y = tot_time/n;
		avg += y;
		y_arr[N-T-1] = y;
		cout << "Run: "<<N-T << " Avg. Wait Time in system is = " << tot_time/n << endl; 
		cout << "-------------------------------\n";
	}
	int y_ = avg/N;
	float s = 0.0;
	for(int i=0; i < N;++i){
		s+= pow( y_arr[i] - y_,2);
	}
	double t = 2.78;
	
	cout << "Statistical Mean thetha ------------------\n" << avg/N << endl;
	cout << "Sample variance ---------------\n " << (1.0/(N-1))*s << endl; 
	cout << "------For alpha(a) = 0.5 ------\n " ;
	float ci2 = y_ + t * sqrt(s/N);
	float ci1 = y_ - t * sqrt(s/N); 
	cout << "Confidence Interval is ---------------------\n" << ci1 << " \t to \t" << ci2 << endl;
}

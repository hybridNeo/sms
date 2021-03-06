#include <iostream>
#include <cmath>
using namespace std;
int fact(int n) { 
	int i=0,fact=1; 
	if(n<=1) 
		return(1);  
	else{ 
		for(i=1;i<=n;i++) { 
		    fact=fact*i; 
		} 
		return(fact); 

	}	 

}
void mm1(int l,int m){
	int c = 1;
	float r = (float)l/(float)m;
	float r0 = 1 - r;
	cout << "------------------------------\n";
	cout << "M|M|1 model \n----- ----- \n";
	float r_no_q = r0 + r*r0;
	cout << "Probability of no queue = " << r_no_q << endl;
	float r_10 = pow(r,10) * r0;
	cout << "Probability of 10 people in queue = " << r_10 << endl;

	float r_2 = 1- r0 - (r*r0);
	cout << "Probabilty of queue size >= 2 = " << r_2 << endl;
	int ls = r/(1-r);
	int lq = ls - r;
	cout << "Avg number in System = " << ls << endl;
	cout << "Avg number in Queue = " << lq << endl; 
	float ws = ls/l;
	float wq = lq/l;
	cout << "Avg Waiting time in System = " << ws << endl;
	cout << "Avg waiting time in queue = " << wq << endl;
	cout << "---------------------------------\n"; 
}
void mm1n(int l,int m,int n){
	int c = 1;
	float r = (float)l/(float)m;
	float r0 = (1 - r)/(1 - pow(r,n+1));
	cout << "------------------------------\n";
	cout << "M|M|1|N model \n------- ----- \n";
	float r_no_q = r0 + r*r0;
	cout << "Probability of no queue = " << r_no_q << endl;
	float ls = (r * ( 1 + (n* pow(r,n+1)) - (n+1)*pow(r,n)))/( (1-r) * (1- pow(r,n+1)));
	float leff = l * (1- r0);
	float lq = ls - (leff/m);
	cout << "Avg number in System = " << ls << endl;
	cout << "Avg number in Queue = " << lq << endl; 
	float ws = ls/leff;
	float wq = ws - 1/m;
	cout << "Avg Waiting time in System = " << ws << endl;
	cout << "Avg waiting time in queue = " << wq << endl;
	cout << "---------------------------------\n"; 
}
void mmc(int l,int m,int n,int c){
	float r = (float)l/(c * (float)m);
	float r0 = 0;
	for(int i=0;i < c ;++i){
		r0 += (pow(r,n)/fact(n)) + (pow(r,c)/(fact(c))* (1-r/c));
	}
	cout << "------------------------------\n";
	cout << "M|M|C model \n----- ----- \n";
	float lq = (pow(r,c+1)*r0)/( fact(c-1) * pow(c-r,2));
	
	float ls = lq + r;
	cout << "Avg number in System = " << ls << endl;
	cout << "Avg number in Queue = " << lq << endl; 
	float ws = ls/l;
	float wq = lq/l;
	cout << "Avg Waiting time in System = " << ws << endl;
	cout << "Avg waiting time in queue = " << wq << endl;
	cout << "---------------------------------\n"; 
}
void mmcn(int l,int m,int n,int c){
	float r = (float)l/(c * (float)m);
	float r0 = 0;
	for(int i=0;i < c ;++i){
		r0 += (pow(r,n)/fact(n)) + (pow(r,c)/(fact(c))* (1-pow(r/c,n-c+1 ))/(1-r/c));
	}
	r0 = 1 + 1/r0;
	cout << "------------------------------\n";
	cout << "M|M|C|N model \n----- ----- \n";
	float lq = (pow(r,c+1)* r0/ fact(c-1)) * (1 - (pow(r/c,n-c+1)) - (n-c+1)*(1-r/c) * pow(r/c,n-c)/pow(c-p,2) );
	float pn = pow(r,n) * r0/fact(c)*pow(c,n-c); 
	float leff = l * (1 - pn);
	cout << "Avg number in System = " << ls << endl;
	cout << "Avg number in Queue = " << lq << endl; 
	float ws = ls/l;
	float wq = lq/l;
	cout << "Avg Waiting time in System = " << ws << endl;
	cout << "Avg waiting time in queue = " << wq << endl;
	cout << "---------------------------------\n"; 
}                                                                  
int main(void){
	cout << "-------------------------------\n";
	int l,m,n,c;
	cout << "Enter Arrival time(lambda) , Service time(mu) , Enter Queue Length(n) , C(num of servers) \n";
	cin >> l >> m >> n >> c;

	mm1(l,m);
	mm1n(l,m,n);
	mmc(l,m,n,c);
}

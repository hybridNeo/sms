#include <iostream>
using namespace std;
class LinearCongruentialGenerator{
public:
	double a_,c_,x0_;
	int m_;
	LinearCongruentialGenerator(double a,double c,int m,double x0):
	a_(a),c_(c),m_(m),x0_(x0)
	{

	}

	double next(){
		x0_ = ((long long int)(a_ * x0_ + c_)) % m_;
		return x0_;
	}
};
int main(void){

	int num;
	cout << "Enter the number of random numbers to generate " << endl;
	cin >> num;
	LinearCongruentialGenerator l(23483241, 87807, num, 1511);
	for(int i = 0; i < num ; ++i){
		cout << l.next() << endl;
	}
}

#include <iostream>
#include "vector.h"
#include "error.h"
using namespace std;

int main(){

	Vector<int> v1,v2;
	Vector<double> v3;
	v1.append(1);
	v1.append(2);
	v2.append(2);
	v2.append(2);
	
	cout << v1.toString() << endl;
	cout << v2.toString() << endl;
	cout << v3.toString() << endl;

	v3 = v1 / v2;
	cout << v3.toString() << endl;
	//error("what is the fuck");
	cout<<"what";
}




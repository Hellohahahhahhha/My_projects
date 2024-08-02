#include<iostream>
#include<vector>
#include"jz.h"
#include"explain.h"

using namespace std;

int main()
{
	double X[3*3]={1,2,3,1,2,0,1,0,0};
	JZ A(X,3,3),B(X,3,3);
	JZ C=A+B;
	JZ P=A*B;
	C.show();
	A.show();
	P.show();
	return 0;
}

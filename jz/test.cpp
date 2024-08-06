#include<iostream>
#include<vector>
#include"jz.h"
#include"explain.h"
#include"Permutation1.h"

using namespace std;

int main()
{
	/*
	double X[3*3]={1,2,3,1,2,0,1,0,0};
	JZ A(X,3,3),B(X,3,3);
	JZ C=A+B;
	JZ P=A*B;
	C.show();
	A.show();
	P.show();
	*/
	Permutation* p=new Permutation(4);
	p->permutate();
	vector<vector<int> > A=p->getPermutation();
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<A[0].size();j++)
		{
			printf("%d ",A[i][j]);
		}
		cout<<endl;
	}
	return 0;
}

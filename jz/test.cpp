#include<iostream>
#include<vector>
#include"jz.h"
#include"explain.h"
#include"Permutation1.h"

using namespace std;

int main()
{

	double X[2*2]={5,2,7,3};
	JZ A(X,2,2);
	A.show();

    double d=A.determinant();
    cout<<d<<endl;

	Permutation* p=new Permutation(2);
/*
	vector<vector<int> > A=p->getPermutation();
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<A[0].size();j++)
		{
			printf("%d ",A[i][j]);
		}
		cout<<endl;
	}*/
	return 0;
}

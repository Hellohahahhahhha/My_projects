#include<iostream>
#include<vector>
#include"jz.h"
#include"explain.h"
#include"Fraction.h"
#include"Permutation1.h"

using namespace std;

int main()
{
/*
    cout<<"Announce:";
    Fraction q(3,6);
    string strF="1/2";
    Fraction q1(strF);
    q1.show();
    q.show();
    string k[2*1]={"1/2","3"};
    return 0;
*/


	int X[3*3]={0,5,0,1,0,1,3,0,0};
	JZ A(X,3,3);
    printf("A:\n");
	A.show();

    int d=A.determinant();
    printf("A的行列式是 %d\n",d);
    JZ S=A.inverse();
    printf("逆矩陣：\n");
    S.show();

	//Permutation* p=new Permutation(2);
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

}

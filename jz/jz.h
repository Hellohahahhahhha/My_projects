#ifndef _JZ_H_
#define _JZ_H_

#include<iostream>
#include<vector>
#include"explain.h"
using namespace std;

class JZ
{
public:
	int _m,_n;
	vector<vector<double> > A;
	JZ(double* R,int m,int n):_m(m),_n(n){epl(R,A,m,n);}
	void show();
	JZ operator +(JZ& B);
	JZ operator -(JZ& B);
	JZ operator *(int x);
	JZ operator *(JZ& B);
	
private:
	
};

void JZ::show()
{
	for(int i=0;i<this->A.size();i++)
	{
		for(int j=0;j<this->A[0].size();j++)
		{
			printf("%0.1f  ",this->A[i][j]);
		}
		cout<<endl;
	}
}

JZ JZ::operator *(int x)
{
	JZ T=*this;
	for(int i=0;i<T.A.size();i++)
	{
		for(int j=0;j<T.A[0].size();j++)
		{
			T.A[i][j]*=x;
		}
	}
	return T;
}

JZ JZ::operator +(JZ& B)
{
	JZ T=*this;
	for(int i=0;i<T.A.size();i++)
	{
		for(int j=0;j<T.A[0].size();j++)
		{
			T.A[i][j]+=B.A[i][j];
		}
	}
	return T;
}

JZ JZ::operator -(JZ& B)
{
	return ((B * (-1)) + *this);
}

JZ JZ::operator *(JZ& B)
{
	JZ T=*this;//A(m*k)*B(k*n)=C(m*n)
	double temp[T._m*B._n];
	double sum;
	int p=0;
	for(int i=0;i<T._m;i++)
	{
		for(int j=0;j<B._n;j++)
		{
			sum=0;
			for(int k=0;k<T._n;k++)
			{
				sum+=T.A[i][k]*B.A[k][j];
			}
			temp[i*T._m+j]=sum;
		}
	}
	epl(temp,T.A,T._m,T._n);
	return T;
}

#endif

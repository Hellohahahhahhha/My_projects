#ifndef _JZ_H_
#define _JZ_H_

#include<iostream>
#include<vector>
#include<cmath>
#include"explain.h"
#include"Permutation1.h"
#include"Fraction.h"
using namespace std;

class JZ
{
public:
	int _m,_n;
	vector<vector<int> > A;
	JZ(int* R,int m,int n);
	JZ(int* R,int m,int n,int over);
	JZ(int m,int n);
	void show();
	JZ inverse();//逆矩阵
	int determinant();//英文意思是  行列式\This time tells us that '_m == _n'
	JZ operator +(JZ& B);
	JZ operator -(JZ& B);
	JZ operator *(int x);
	JZ operator *(JZ& B);
private:
    int overBy;
    int algebraic_cofactors(int i,int j);//代数余子式
    JZ cofactors(int i,int j);//余子式
	int inversions(int i);//逆序数
	vector<vector<int> > perm;
};

JZ::JZ(int* R,int m,int n,int over)
{
    this->_m=m;
	this->_n=n;
	epl<int>(R,A,m,n);
	Permutation *p=new Permutation(n);
	this->perm=p->getPermutation();
	overBy=over;
}

JZ::JZ(int m,int n)
{
    this->_m=m;
    this->_n=n;
    int* Temp=new int[m*n];//empty array
    epl<int>(Temp,A,m,n);
    Permutation *p=new Permutation(n);
	this->perm=p->getPermutation();
	delete []Temp;
	overBy=1;
}

JZ::JZ(int* R,int m,int n)
{
	this->_m=m;
	this->_n=n;
	epl<int>(R,A,m,n);
	Permutation *p=new Permutation(n);
	this->perm=p->getPermutation();
	overBy=1;
}

void JZ::show()
{
	for(int i=0;i<this->A.size();i++)
	{
		for(int j=0;j<this->A[0].size();j++)
		{
		    Fraction F(A[i][j],this->overBy);
			F.show();
		}
		cout<<endl;
	}
}

JZ JZ::operator *(int x)
{
	JZ T=*this;
	Fraction* NF=new Fraction(x,T.overBy);
	if(NF->_a==1)goto nxt;

	for(int i=0;i<T.A.size();i++)
	{
		for(int j=0;j<T.A[0].size();j++)
		{
			T.A[i][j]*=NF->_a;
		}
	}

	nxt:
    T.overBy=NF->_b;
    delete NF;
	return T;
}

JZ JZ::operator +(JZ& B)
{
	JZ T=*this;
	JZ G=B;

	T=T*G.overBy;
	G=G*T.overBy;

	T.overBy=T.overBy*G.overBy;

	for(int i=0;i<T.A.size();i++)
	{
		for(int j=0;j<T.A[0].size();j++)
		{
			T.A[i][j]+=G.A[i][j];
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
	int temp[T._m*B._n];
	int sum;
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
	epl<int>(temp,T.A,T._m,T._n);
	T.overBy=T.overBy*B.overBy;
	return T;
}

int JZ::determinant()
{
	int sum=0;
	int tempT;
	for(int i=0;i<perm.size();i++)
	{
		tempT=1;
		for(int j=0;j<perm[0].size();j++)
		{
			tempT*=A[j][(perm[i][j])-1];
		}
		tempT*=pow(-1,inversions(i));
		sum+=tempT;
	}
	//cout<<"Test"<<endl;
	return sum;
}


int JZ::inversions(int i)
{
    int n=0;
    for(int x=1;x<perm[i].size();x++)
    {
        for(int j=0;j<i;j++)
        {
            if(perm[i][j]>perm[i][x])
            {
                n++;
            }
        }
    }
    return n;
}

JZ JZ::inverse()
{
    int over=this->determinant();
    JZ T(_m,_n);
    int Aji;
    for(int i=0;i<_m;i++)
    {
        for(int j=0;j<_n;j++)
        {
            JZ C=cofactors(i,j);
            Aji=C.determinant();
            T.A[j][i]=Aji;
        }
    }
    T.overBy=over;
    return T;
}

JZ JZ::cofactors(int i,int j)
{
    JZ C(_m-1,_n-1);
    int tempArr[C._m*C._n];
    int nth=0;
    for(int x=0;x<this->_m;x++)
    {
        if(x==i)
        {
            continue;
        }
        for(int y=0;y<this->_n;y++)
        {
            if(y==j)
            {
                continue;
            }
            tempArr[nth]=this->A[x][y];
            nth++;
        }
    }
    epl<int>(tempArr,C.A,C._m,C._n);
    return C;
}
#endif

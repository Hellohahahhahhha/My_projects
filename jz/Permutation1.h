#ifndef _PERMUTATION_H_
#define _PERMUTATION_H_

#include<vector>
#include<iostream>
using namespace std;

void Show(int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ");
	}
	cout<<endl;
}

class Permutation
{
public:
	Permutation(int n);
	void permutate();
	vector<vector<int> >& getPermutation();
private:
	void GetPerm(int beg,int end);
	int _n;
	int _beg,_end;
	int *arr=NULL;
	vector<vector<int> > perm;
	vector<int> temp;
	void Swap(int& a,int& b);
	int P(int n);
};

void Permutation::permutate()
{
	this->GetPerm(_beg,_end);
}

vector<vector<int> >& Permutation::getPermutation()
{
	return this->perm;
}

Permutation::Permutation(int n)
{
	_beg=0;
	_end=n-1;
	arr=new int[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=i+1;
	}
}

int Permutation::P(int n)
{
	if(n==1){return 1;}
	else if(n==0){return 0;}
	else{return n*P(n-1);};
}

void Permutation::Swap(int& a,int& b)
{
	int c=a;
	a=b;
	b=c;
}

void Permutation::GetPerm(int beg,int end)//0,2
{
	if(beg==end)
	{
		for(int i=0;i<=end;i++)
		{
			temp.push_back(arr[i]);
		}
		perm.push_back(temp);
		temp.clear();
	}
	else
	{
		for(int i=beg;i<=end;i++)
		{
			Swap(arr[beg],arr[i]);
			GetPerm(beg+1,end);
			Swap(arr[beg],arr[i]);
		}
	}
}

#endif

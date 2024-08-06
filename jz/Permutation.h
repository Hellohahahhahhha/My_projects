#ifndef _PERMUTATION_H_
#define _PERMUTATION_H_

#include<vector>


#include<iostream>
using namespace std;
/*
PMethod(PLs,3,0);
PMethod(PLs,2,n);
..
.

.
         count    ==    n-1
*/
/*
struct PLs
{
	PLs(int n):nth(n)
	{
		
	}
	PLs(){}
	int nth;
	int thisNum;
	PLs* next;
};
class PM
{
public:
	PM(int n):_n(n)
	{
		PLs *pmT=new PLs[n];
		nth=0;
		pm=pmT;
		delete [] pmT;
		for(int i=0;i<n;i++)
		{
			pm[i].nth=0;
		}
	}
	PLs *pm;
	PLs tempObj;
	int _n;
	int nth;
	void setUpPMtree(int b,int e)//~(1,3)(e-b==1?end:ctn)
	{
		for(int i=0;i<_n;i++)
		{
			pm[i]
		}
	}
};*/
/*
for(int i=0;i<_n-b;i++)
		{
			pm[i].next.push_back(new PLs(b));
			tempObj=&pm[i];
			pm[i]=(*pm[i]).next[i];
			setUpPMtree(b+1,e);
			pm[i]=*tempObj;
		}
*/

int P(int n);

void Perm(int* inputArray,int* output,int b,int e);

void PMethod(int* arr,int n)//arr 1D array
{
	int num[n];
	for(int i=0;i<n;i++)
	{
		num[i]=i+1;
	}
	cout<<"test";
	Perm(num,arr,0,n-1);
}

void Swap(int& a, int& b)
{
	int c=a;
	a=b;
	b=c;
}

void Perm(int* inputArray,int* output,int b,int e)
{
	if(b==e){return;}
	for(int i=b;i<e;i++)
	{
		output[(e+1)*i+b]=inputArray[i];
		Swap(inputArray[b],inputArray[i]);
		Perm(inputArray,output,b+1,e);
		Swap(inputArray[b],inputArray[i]);
	}
}

int P(int n)
{
	if(n==1){return 1;}
	else if(n==0){return 0;}
	else{return n*P(n-1);};
}

#endif

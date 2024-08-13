#ifndef _EXPLAIN_H_
#define _EXPLAIN_H_

#include<vector>
using namespace std;


template<class C>
void epl(C *arr,vector<vector<C> >& _vec,int m,int n)
{
	vector<vector<C> > vec;
	vector<C> T;
	int k=0;
	for(int i=0;i<m;i++)
	{
		T.clear();
		for(int j=0;j<n;j++)
		{
			T.push_back(arr[k]);
			k++;
		}
		vec.push_back(T);
	}
	_vec=vec;
}




#endif

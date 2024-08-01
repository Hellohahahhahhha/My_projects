#ifndef _JZ_H_
#define _JZ_H_

#include<iostream>
#include<vector>
using namespace std;

class JZ
{
public:
	int _m,_n;
	vector<vector<double> > A;
	JZ(vector<vector<double> >& R,int m,int n):_m(m),_n(n),A(R){}
private:
	
};

#endif

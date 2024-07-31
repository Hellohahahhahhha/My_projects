#include<iostream>
#include<string>
#include<vector>
using namespace std;

int isOpr(char c);//             ????????????!!!!!!!!!!!!!!!!!!

void split(string &s,vector<string> &nums,int length)
{
	int l=-1,p=0;
	vector<string> N;
	s+='~';
	for(int i=0;i<length+1;i++)
	{
		l++;
		if(isOpr(s[i]))
		{
			N.push_back(s.substr(p,l));
			N.push_back(s.substr(i,1));
			p=i+1;
			l=-1;
		}
	}
	nums=N;
}

int Right(string& s,int beginPos,int length)
{
	for(int i=beginPos;i<length;i++)
	{
		if(s[i]==')')
		{
			return i;
		}
	}
	return -1;
}

int isOpr(char c)
{
	switch (c)
	{
		case '+':return 1;break;
		case '-':return 2;break;
		case '*':return 3;break;
		case '/':return 4;break;
		case '(':return 110;break;
		case ')':return 101;break;
		case '~':return 444;break;
		default:return 0;
	}
}

double compute(vector<string>& s,int size,int beginPos,int endPos)
{
	char opr=0;
	double sum=0;
	int p1;
	for(int i=0;i<size;i++)
	{
		if(s[i].size()==1)
		{
			if(opr==0 && isOpr(s[i][0])){
			}
		}
		//x+=s[i];
	}
}

class jz
{
public:
	int m,n;
	jz(int a,int b):m(a),n(b){}
	vector<vector<double> > A;
	void fillup(vector<vector<double> >& B)
	{
		this->A=B;
	}
	void show()
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<A[i][j]<<' '<<endl;
			}
			printf("\n");
		}
	}
private:
	
};

int main()
{
	string s="j+ksj+kdljf";
	vector<string> vs;
	split(s,vs,s.size());
	for(int i=0;i<vs.size();i++)
	{
		cout<<vs[i]<<endl;
	}
	return 0;
}







/*
int main()
{
	for(int i=1;i<=100;i++)
	{
		if(i%2==0)
		{
			cout<<i<<endl;
		}
	}
}*/

//int main()
//{
//	float sum=0,pm;
//	for(int i=0;i<12;i++)
//	{
//		cin>>pm;
//		sum+=pm;
//	}
//	printf("$%0.2f",sum/12);
//	return 0;
//}

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int isOpr(char c);//             ????????????!!!!!!!!!!!!!!!!!!

void split(string *s,vector<string> *nums,int length)
{
	int l=0,p=0;
	string sc[length]=*s;
	nums->clear();//splitted string s
	for(int i=0;i<length;i++)
	{
		if(isOpr(sc[i]))
		{
			nums->push_back(sc.substr(p,l));
			nums->push_back(sc[i]);
		}
	}
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
		default:return 0;
	}
}

double computer(string* s,int size)
{
	string x="";
	char opr=0;
	double sum=0;
	int l1,l2,p1;
	for(int i=0;i<size;i++)
	{
		if(opr!=0 && isOpr(s[i]))
		{
			
		}
		else if(opr==0 && isOpr(s[i]))
		{
			
		}
		x+=s[i];
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
	for(int i=1;i<=100;i++)
	{
		if(i%2==0)
		{
			cout<<i<<endl;
		}
	}
}

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

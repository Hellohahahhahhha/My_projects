#include<iostream>
#include<math.h>
using namespace std;

class functions
{
public:
	functions(double oa,double ob,double oc):_a(oa),_b(ob),_c(oc){}
	functions(double ax2,double by2,double cxy,double d0):__a(ax2),__b(by2),__c(cxy),__d(d0){}
	double f(double x);
	double f(double x, double y);
	double tg(double x);
	double tg(double x, double y);
private:
	double _a,_b,_c;
	double __a,__b,__c,__d;
	double _value;
	double _tg;
	double __tg[2];
	//function Template is"f(x)=ax^2 + bx +c"
};

double functions::f(double x)
{
	_value=_a*x*x + _b*x + _c;
	return _value;
}

double functions::tg(double x)
{
	_tg=2*_a*x + _b;
	return _tg;
}

double mix(functions* f,double x,double e,double kl,int* time=NULL)
{
	double x1=x,x2=x,k;
	do
	{
		x2=x1;
		k=f->tg(x1);
		x1-=k*kl;
	}while(abs(x2-x1)>e);
	return (x1+x2)/2;
}
//(double*)mi(functions* f,double x,double e,double kl)
double fd(functions* f,double x0,double ctv,double eptv_this,double eptv_mix)//find fited value for kl(0<kl<1)
{//ctv: currect value; eptn: exception deviation
	double dk=.1,vle1,vle2,delta;
	double epc;
	int k=1;
	int nTime;
	vle1=mix(f,x0,eptv_mix,dk);
	epc=ctv-vle1;//expection = currect_value - value_this_time
	vle2=mix(f,x0,eptv_mix,dk+eptv_this*k);
	if(abs(vle2-ctv)-abs(vle1-ctv)>0)//k plus, delta < 0(mini)
	{
		dk*=-1;
	}
	double epc1,xm;
	int ltime=nTime;
	do
	{
		dk+=eptv_this*k;
		vle1=mix(f,x0,eptv_mix,dk,&nTime);
		
		epc=ctv-vle1;
	}while(abs(epc)>eptv_this);
	return dk;
}

int main()
{
	functions *f1 = new functions(1,2,1);
	double k=fd(f1,0,-1,.001,.00001);
	cout<<k<<endl;
//	while(x<=5)
//	{
//		printf("%f ------ %f\n",x,f1->f(x));
//		x+=(double)10/100;
//	}

	
	return 0;
}

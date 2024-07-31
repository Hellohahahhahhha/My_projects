#include<iostream>
#include<math.h>
#include<map>
#define mini .00001
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
	int t=0;
	if(time!=NULL)
	{
		do
		{
			x2=x1;
			k=f->tg(x1);
			x1-=k*kl;
			t++;
		}while(f->f(x2) - f->f(x1) != 0);
	}
	*time=t;
	return (x1+x2)/2;
}
//(double*)mi(functions* f,double x,double e,double kl)

double gnt(double (* f)(double x),double x0)
{
	double t;
	t=f(x0+mini)-f(x0);
	t/=mini;
	return t;
}



double fd(functions* f,double x0,double eInner,double eThis)
{
	int Ltime,Ttime;//Ltime: Last time time,Ttime: this time time
	double k=.1;
	double t;
	do
	{
		t=gnt(forTime,k);//                   edited last time
		k-=eThis*t;
	}while(gnt(firTime,k)!=0);
}


int main()
{
	functions *f1 = new functions(1,2,1);
	
	//double k=fd(f1,0,-1,.001,.00001);
	//cout<<k<<endl;
	
//	int time;//                    test
//	double v;
//	for(double i=.1;i<.9;i+=.001)
//	{
//		v=mix(f1,0,.001,i,&time);
//		printf("%f----_%f------%d           ",i,v,time);
//	}


//	while(x<=5)
//	{
//		printf("%f ------ %f\n",x,f1->f(x));
//		x+=(double)10/100;
//	}

	
	return 0;
}










//double fd(functions* f,double x0,double ctv,double eptv_this,double eptv_mix)//find fited value for kl(0<kl<1)
//{//ctv: currect value; eptn: exception deviation
//	double dk=.1,vle1,vle2,delta;
//	double epc;
//	int k=1;
//	int nTime;
//	int minTime;
//	vle1=mix(f,x0,eptv_mix,dk);
//	epc=ctv-vle1;//expection = currect_value - value_this_time
//	dk+=eptv_this*k;
//	vle2=mix(f,x0,eptv_mix,dk,&nTime);
//	if(abs(vle2-ctv)>abs(vle1-ctv))//k plus, delta < 0(mini)
//	{
//		dk*=-1;
//	}
//	double epc1,xm;
//	
//	do
//	{
//		minTime=nTime;
//		dk+=eptv_this*k;
//		vle1=mix(f,x0,eptv_mix,dk,&nTime);
//		epc=ctv-vle1;
//		cout<<nTime<<endl;
//	}while(abs(epc)>eptv_this || minTime>nTime);
//	return dk;
//}//  

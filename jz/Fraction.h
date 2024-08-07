#ifndef _FRACTION_H_
#define _FRACTION_H_

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Fraction//output: a/b
{
public:
    Fraction(int a,int b);
    Fraction(string& f);
    Fraction operator* (Fraction& f2);
    int _a,_b;
    void show();
private:
    void reduce();
};

Fraction::Fraction(int a,int b)
{
    _a=a;
    _b=b;
    reduce();
}

Fraction::Fraction(string& f)
{
    int n=1;
    string a,b;
    for(int i=0;i<f.size();i++)
    {
        if(f[i]=='/')
        {
            a=f.substr(0,n);
            b=f.substr(i+1,f.size()-n+1);
            break;
        }
        n++;
    }
    size_t sz;
    _a=stoi(a,&sz);
    _b=stoi(b,&sz);
}

void Fraction::reduce()
{
    for(int i=2;i<=abs(_a);i++)
    {
        while(_a%i==0 && _b%i==0)
        {
            _a/=i;
            _b/=i;
        }
    }
}

Fraction Fraction::operator*(Fraction& f2)
{
    Fraction f1=*(this);
    f1._a*=f2._a;
    f1._b*=f2._b;
    f1.reduce();
    return f1;
}

void Fraction::show()
{
    printf("%d/%d",_a,_b);
}

#endif // _FRACTION_H_

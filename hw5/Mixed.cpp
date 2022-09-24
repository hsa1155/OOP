#include"Mixed.h"
#include<iostream>
#include<iomanip>
using namespace std;

int gcd( int a, int b )
{
    if( b==0 )
        return a;
    return gcd( b, a%b );
}

Mixed::Mixed(int x)
{
    integer=x;
    numerator=0;
    denominator=0;
};

Mixed::Mixed(int a,int b,int c)
{
    if(a==0)
    {
        if(c<=0)
        {
            a=0;
            b=0;
            c=0;
        }
    }
    else if(a!=0)
    {
        if(b<0||c<=0)
        {
            a=0;
            b=0;
            c=0;
        }
    }

    integer=a;
    numerator=b;
    denominator=c;
}

double Mixed::Evaluate()
{
    //double num;
    if(numerator==0||denominator==0)
    {
        return integer;
    }
    else return integer+(double)numerator/(double)denominator;
}

void Mixed::ToFraction()
{
    if(denominator==0)
    {
        denominator=1;
    }
    if(integer>=0)
    numerator+=integer*denominator;
    else
    {
        numerator*=-1;
        numerator+=integer*denominator;
    }
    integer=0;
}
void Mixed::Simplify()
{
    if(denominator==0) return;
    if(integer<0)
    {
        numerator*=-1;
        numerator+=integer*denominator;
        integer=0;
    }
    else if(integer>=0)
    {
        numerator+=integer*denominator;
        integer=0;
    }
    int k;
    if(numerator>=0) k=gcd(numerator,denominator);
    else k=gcd(-1*numerator,denominator);
    numerator/=k;
    denominator/=k;
    
    if(numerator<0)
    {
        numerator*=-1;
        if(numerator>=denominator)
        {
        integer=numerator/denominator;
        numerator-=integer*denominator;
        integer*=-1;
        }
        else numerator*=-1;
    }
    else
    {
        if(numerator>=denominator)
        {
            integer=numerator/denominator;
            numerator-=integer*denominator;
        }
        

    }

    
}

void Mixed::print()
{
    cout<<"print"<<integer<<" "<<numerator<<"/"<<denominator;
}

bool Mixed::operator<(const Mixed& m)
{
    int a,b,c;
    a=this->integer;
    b=this->numerator;
    c=this->denominator;
    Mixed tmp1(a,b,c);
    a=m.integer;
    b=m.numerator;
    c=m.denominator;
    Mixed tmp2(a,b,c);
    tmp1.ToFraction();
    tmp2.ToFraction();
    int tmp=tmp1.denominator;
    tmp1.denominator*=tmp2.denominator;
    tmp1.numerator*=tmp2.denominator;
    tmp2.numerator*=tmp;
    tmp2.denominator*=tmp;
    tmp1.numerator+=tmp1.integer*tmp1.denominator;
    tmp1.integer=0;
    tmp2.numerator+=tmp2.integer*tmp2.denominator;
    tmp2.integer=0;

    if(tmp1.denominator!=tmp2.denominator)
    cout<<"an error occurs at <";

    if(tmp1.numerator<tmp2.numerator) return true;
    else return false;
    
}
bool Mixed::operator<=(const Mixed& m)
{
    int a,b,c;
    a=this->integer;
    b=this->numerator;
    c=this->denominator;
    Mixed tmp1(a,b,c);
    a=m.integer;
    b=m.numerator;
    c=m.denominator;
    Mixed tmp2(a,b,c);
    tmp1.ToFraction();
    tmp2.ToFraction();
    int tmp=tmp1.denominator;
    tmp1.denominator*=tmp2.denominator;
    tmp1.numerator*=tmp2.denominator;
    tmp2.numerator*=tmp;
    tmp2.denominator*=tmp;
    tmp1.numerator+=tmp1.integer*tmp1.denominator;
    tmp1.integer=0;
    tmp2.numerator+=tmp2.integer*tmp2.denominator;
    tmp2.integer=0;
    if(tmp1.denominator!=tmp2.denominator)
    cout<<"an error occurs at <=";

    if(tmp1.numerator<=tmp2.numerator) return true;
    else return false;
    
}
bool Mixed::operator!=(const Mixed& m)
{
    int a,b,c;
    a=this->integer;
    b=this->numerator;
    c=this->denominator;
    Mixed tmp1(a,b,c);
    a=m.integer;
    b=m.numerator;
    c=m.denominator;
    Mixed tmp2(a,b,c);
    tmp1.ToFraction();
    tmp2.ToFraction();
    int tmp=tmp1.denominator;
    tmp1.denominator*=tmp2.denominator;
    tmp1.numerator*=tmp2.denominator;
    tmp2.numerator*=tmp;
    tmp2.denominator*=tmp;
    tmp1.numerator+=tmp1.integer*tmp1.denominator;
    tmp1.integer=0;
    tmp2.numerator+=tmp2.integer*tmp2.denominator;
    tmp2.integer=0;
    if(tmp1.denominator!=tmp2.denominator)
    cout<<"an error occurs at !=";

    if(tmp1.numerator!=tmp2.numerator) return true;
    else return false;
    
}
bool Mixed::operator==(const Mixed& m)
{
    int a,b,c;
    a=this->integer;
    b=this->numerator;
    c=this->denominator;
    Mixed tmp1(a,b,c);
    a=m.integer;
    b=m.numerator;
    c=m.denominator;
    Mixed tmp2(a,b,c);
    tmp1.ToFraction();
    tmp2.ToFraction();
    int tmp=tmp1.denominator;
    tmp1.denominator*=tmp2.denominator;
    tmp1.numerator*=tmp2.denominator;
    tmp2.numerator*=tmp;
    tmp2.denominator*=tmp;
    tmp1.numerator+=tmp1.integer*tmp1.denominator;
    tmp1.integer=0;
    tmp2.numerator+=tmp2.integer*tmp2.denominator;
    tmp2.integer=0;
    if(tmp1.denominator!=tmp2.denominator)
    cout<<"an error occurs at ==";

    if(tmp1.numerator==tmp2.numerator) return true;
    else return false;
    
}

bool Mixed::operator>(const Mixed& m)
{
    int a,b,c;
    a=this->integer;
    b=this->numerator;
    c=this->denominator;
    Mixed tmp1(a,b,c);
    a=m.integer;
    b=m.numerator;
    c=m.denominator;
    Mixed tmp2(a,b,c);
    tmp1.ToFraction();
    tmp2.ToFraction();
    int tmp=tmp1.denominator;
    tmp1.denominator*=tmp2.denominator;
    tmp1.numerator*=tmp2.denominator;
    tmp2.numerator*=tmp;
    tmp2.denominator*=tmp;
    tmp1.numerator+=tmp1.integer*tmp1.denominator;
    tmp1.integer=0;
    tmp2.numerator+=tmp2.integer*tmp2.denominator;
    tmp2.integer=0;
    if(tmp1.denominator!=tmp2.denominator)
    cout<<"an error occurs at >";

    if(tmp1.numerator>tmp2.numerator) return true;
    else return false;
    
}
bool Mixed::operator>=(const Mixed& m)
{
    int a,b,c;
    a=this->integer;
    b=this->numerator;
    c=this->denominator;
    Mixed tmp1(a,b,c);
    a=m.integer;
    b=m.numerator;
    c=m.denominator;
    Mixed tmp2(a,b,c);
    tmp1.ToFraction();
    tmp2.ToFraction();
    int tmp=tmp1.denominator;
    tmp1.denominator*=tmp2.denominator;
    tmp1.numerator*=tmp2.denominator;
    tmp2.numerator*=tmp;
    tmp2.denominator*=tmp;
    tmp1.numerator+=tmp1.integer*tmp1.denominator;
    tmp1.integer=0;
    tmp2.numerator+=tmp2.integer*tmp2.denominator;
    tmp2.integer=0;
    if(tmp1.denominator!=tmp2.denominator)
    cout<<"an error occurs at >=";

    if(tmp1.numerator>=tmp2.numerator) return true;
    else return false;
    
}

Mixed Mixed::operator+(const int x)
{
    Mixed m(x);
    Mixed tmp(integer,numerator,denominator);
    m.ToFraction();
    //cout<<"!"<<tmp+m<<endl;
    return tmp+m;
}
Mixed Mixed::operator-(const int x)
{
    Mixed m(x);
    Mixed tmp(integer,numerator,denominator);
    m.ToFraction();
    return tmp-m;
}
Mixed Mixed::operator*(const int x)
{
    Mixed m(x);
    Mixed tmp(integer,numerator,denominator);
    m.ToFraction();
    return tmp*m;
}
Mixed Mixed::operator/(const int x)
{
    Mixed m(x);
    Mixed tmp(integer,numerator,denominator);
    m.ToFraction();
    return tmp/m;
}
void Mixed::operator=(const Mixed& m)
{
    integer=m.integer;
    numerator=m.numerator;
    denominator=m.denominator;
}

Mixed Mixed::operator+(const Mixed& m)
{
    //int a,b,c;
    
    Mixed tmp1(0);
    tmp1=*this;
    
    Mixed tmp2(0);
    tmp2=m;
    tmp1.ToFraction();
    tmp2.ToFraction();
    int tmp=tmp1.denominator;
    tmp1.denominator*=tmp2.denominator;
    tmp1.numerator*=tmp2.denominator;
    tmp2.numerator*=tmp;
    tmp2.denominator*=tmp;
    tmp1.numerator+=tmp1.integer*tmp1.denominator;
    tmp1.integer=0;
    tmp2.numerator+=tmp2.integer*tmp2.denominator;
    tmp2.integer=0;

    Mixed ans(0,tmp1.numerator+tmp2.numerator,tmp1.denominator);
    ans.Simplify();

    return ans;

}
Mixed Mixed::operator-(const Mixed& m)
{
    int a,b,c;
    Mixed tmp1(0);
    tmp1=*this;
    
    Mixed tmp2(0);
    tmp2=m;
    tmp1.ToFraction();
    tmp2.ToFraction();
    int tmp=tmp1.denominator;
    tmp1.denominator*=tmp2.denominator;
    tmp1.numerator*=tmp2.denominator;
    tmp2.numerator*=tmp;
    tmp2.denominator*=tmp;
    tmp1.numerator+=tmp1.integer*tmp1.denominator;
    tmp1.integer=0;
    tmp2.numerator+=tmp2.integer*tmp2.denominator;
    tmp2.integer=0;

    Mixed ans(0,tmp1.numerator-tmp2.numerator,tmp1.denominator);
    ans.Simplify();

    return ans;

}

Mixed Mixed::operator*(const Mixed& m)
{
    int a,b,c;
     Mixed tmp1(0);
    tmp1=*this;
    
    Mixed tmp2(0);
    tmp2=m;
    tmp1.ToFraction();
    tmp2.ToFraction();
    /*
    int tmp=tmp1.denominator;
    tmp1.denominator*=tmp2.denominator;
    tmp1.numerator*=tmp2.denominator;
    tmp2.numerator*=tmp;
    tmp2.denominator*=tmp;
    tmp1.numerator+=tmp1.integer*tmp1.denominator;
    tmp1.integer=0;
    tmp2.numerator+=tmp2.integer*tmp2.denominator;
    tmp2.integer=0;
    */


    Mixed ans(0,tmp1.numerator*tmp2.numerator,tmp1.denominator*tmp2.denominator);
    ans.Simplify();

    return ans;

}

Mixed Mixed::operator/(const Mixed& m)
{
    int a,b,c;
     Mixed tmp1(0);
    tmp1=*this;
    
    Mixed tmp2(0);
    tmp2=m;
    tmp1.ToFraction();
    tmp2.ToFraction();
    /*
    int tmp=tmp1.denominator;
    tmp1.denominator*=tmp2.denominator;
    tmp1.numerator*=tmp2.denominator;
    tmp2.numerator*=tmp;
    tmp2.denominator*=tmp;
    tmp1.numerator+=tmp1.integer*tmp1.denominator;
    tmp1.integer=0;
    tmp2.numerator+=tmp2.integer*tmp2.denominator;
    tmp2.integer=0;
    */


    Mixed ans(0,tmp1.numerator*tmp2.denominator,tmp1.denominator*tmp2.numerator);
    ans.Simplify();

    return ans;

}

Mixed& Mixed::operator++()//++x
{
    //Mixed old(this->integer,this->numerator,this->denominator);
    if(integer!=0)integer++;
    else
    {
        if(numerator>=0) integer+=1;
        else
        {
            numerator+=denominator;
        }
    }
    this->Simplify();
    return *this;

} 
const Mixed Mixed::operator++(int x)//x++
{
    Mixed old(this->integer,this->numerator,this->denominator);
    if(integer!=0)integer++;
    else
    {
        if(numerator>=0) integer+=1;
        else
        {
            numerator+=denominator;
        }
    }
    this->Simplify();
    return old;

}

Mixed& Mixed::operator--()//--x
{
    //Mixed old(this->integer,this->numerator,this->denominator);
    if(integer!=0)integer--;
    else
    {
        if(numerator>=0) numerator-=denominator;
        else
        {
            integer-=1;
        }
    }
    this->Simplify();
    return *this;

}

const Mixed Mixed::operator--(int x)//x--
{
    Mixed old(this->integer,this->numerator,this->denominator);
    if(integer!=0)integer--;
    else
    {
        if(numerator>=0) numerator-=denominator;
        else
        {
            integer-=1;
        }
    }
    this->Simplify();
    return old;

}

istream& operator>>(istream &in,Mixed &m)
{
    char ch;
    int a,b,c;
    in>>a>>b>>ch>>c;
    
    if(a==0)
    {
        if(c<=0)
        {
            a=0;
            b=0;
            c=0;
        }
    }
    else if(a!=0)
    {
        if(b<0||c<=0)
        {
            a=0;
            b=0;
            c=0;
        }
    }

    m.integer=a;
    m.numerator=b;
    m.denominator=c;

    return in;

}

ostream& operator<<(ostream &out,const Mixed &m)
{
    if(m.integer==0 && (m.denominator==0 || m.numerator==0))
    {
        out<<0;
        return out;
    }
    else if(m.integer==0 &&(m.denominator!=0&&m.numerator!=0))
    {
        out<<m.numerator<<"/"<<m.denominator;
        return out;
    }
    else if(m.integer!=0 &&(m.denominator==0||m.numerator==0))
    {
        out<<m.integer;
        return out;
    }
    else
    {
        out<<m.integer<<" "<<m.numerator<<"/"<<m.denominator;
        return out;
        
    }
}





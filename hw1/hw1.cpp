#include<bits/stdc++.h>
using namespace std;

ofstream out;

double seadragon(double a,double b,double c)
{
    if(a<=0||b<=0||c<=0) return -1;
    double s=a+b+c;
    s/=2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
    out.open("cpp_result.txt");
    double a,b,c,area;
    cout<<"triangle area calculater"<<endl;
    out<<"triangle area calculater"<<endl;
    while(1)
    {
    cout<<"please input first number"<<endl;
    cin>>a;
    cout<<"please input second number"<<endl;
    cin>>b;
    cout<<"please input third number"<<endl;
    cin>>c;
    if(a==-1&&b==-1&&c==-1)
    {
        cout<<"end of program"<<endl;
        out<<"end of program"<<endl;
        out.close();
        break;
    }
    cout<<"a="<<a<<endl;
    out<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    out<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
    out<<"c="<<c<<endl;
    area=seadragon(a,b,c);
    if(!(area>0))
    { 
        cout<<"invalid input.please try again"<<endl;
        out<<"invalid input.please try again"<<endl;
    }
    else 
    {
        cout<<"area of triangle is "<<area<<endl;
        out<<"area of triangle is "<<area<<endl;
    }


}
}
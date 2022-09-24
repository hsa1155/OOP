#include <bits/stdc++.h>
#include "ConvexHull.cpp"
#include<sys/time.h>
using namespace std;
ifstream in("input.txt");
ofstream bru_out("Output_brutal.txt");
ofstream jav_out("Output_Javis.txt");



vector<Point> pts;
vector<Point> brute2;
vector<Point> javis1;
vector<Point> brute1;
vector<Point> javis2;
void DrawPoints(const vector<Point> &input,ofstream &out)
{
    //ofstream out(filename);
    int sz=input.size();
    out<<sz<<endl;
    for(int i=0;i<sz;i++)
    {
        double x=input[i].getx();
        double y=input[i].gety();
        out<<x<<" "<<y<<endl;
    }
    out<<endl;

} // provide data to the first part of Output.txt
void DrawLines(const vector<Point> &input,ofstream &out)
{
    //ofstream out(filename);
    int sz=input.size();
    out<<sz<<endl;
    for(int i=0;i<sz;i++)
    {
        double x=input[i].getx();
        double y=input[i].gety();
        out<<x<<" "<<y<<endl;
    }
    out<<endl;

}
int main()
{
    int n;
    in >> n;
    if(n<=2)
    {
        cout<<"this input contains less than 3 points.there is no such convex hull"<<endl;
    }
    ConvexHull ch;
    //clock_t a,b;   

        struct  timeval start;
        struct  timeval end;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        in >> x >> y;
        Point tmp(x, y);
        pts.push_back(tmp);
        // bru_used.push_back(1);
        //jav_used.push_back(1);
    }
    //a=clock();
    gettimeofday(&start,NULL);
    ch.brute_force(pts, brute1, brute2);
    //b=clock(); 
    gettimeofday(&end,NULL);
    double diff =  (double)(end.tv_sec-start.tv_sec)*1000.0+ (double)(end.tv_usec-start.tv_usec)/1000.0;
    cout<<endl<<"brute time:"<<diff<<"ms"<<endl;
    DrawPoints(brute1,bru_out);
    DrawLines(brute2,bru_out);
    //a=clock();
    gettimeofday(&start,NULL);
    ch.javis(pts, javis1, javis2);
    //b=clock();
    gettimeofday(&end,NULL);
    diff =  (double)(end.tv_sec-start.tv_sec)*1000.0+ (double)(end.tv_usec-start.tv_usec)/1000.0;
    cout<<endl<<"javis time:"<<diff<<"ms"<<endl;
    DrawPoints(javis1,jav_out);
    DrawLines(javis2,jav_out);
}
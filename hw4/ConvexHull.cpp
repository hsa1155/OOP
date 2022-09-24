#include<bits/stdc++.h>
#include"Line.cpp"
#include"Point.cpp"
#define PI 3.1415926535897931
using namespace std;

class ConvexHull
{
public:
    void brute_force(const vector<Point> &input, vector<Point> &output1, vector<Point> &output2)
    {
        int sz = input.size();
        int used[sz]; //0 for unused
        for (int i = 0; i < sz; i++)
            used[i] = 0;
        //cout<<"f"<<endl;
        vector<Point> tmp;
        vector<Point> non;
        for (int i = 0; i < sz; i++)
        {
            //cout<<"i="<<i<<endl;
            for (int j = 0; j < sz; j++)
            {
                if (i == j)
                    continue;
                //cout<<"j="<<j<<endl;
                bool at = true;
                for (int k = 0; k < sz; k++)
                {
                    if ((k == i) || (k == j))
                        continue;
                    if (!isOnRight(input[i], input[j], input[k]))
                        at = false;
                }
                if (at)
                {
                    if (used[i] == 0)
                    {
                        used[i] = 1;
                        tmp.push_back(input[i]);
                        //cout<<"usedi"<<i<<endl;
                    }
                    if (used[j] == 0)
                    {
                        used[j] = 1;
                        tmp.push_back(input[j]);
                        //cout<<"usedj"<<j<<endl;
                    }
                }
            }
        }

        for (int i = 0; i < sz; i++)
        {
            if (used[i] == 0)
                output1.push_back(input[i]);
        }
        cout<<"brute result start"<<endl;
        int nonsz=output1.size();
        cout<<nonsz<<endl;
        //for(int i=0;i<nonsz;i++)
        //{
        //    output1[i].print();
        //}
        javis(tmp,non,output2);
        
        int outsz = output2.size();
        cout << endl
             << outsz << endl;
       // for (int i = 0; i < outsz; i++)
        //{
        //    output2[i].print();
       // }
/*
        cout << endl
             << outsz << endl;
             for (int i = 0; i < outsz; i++)
        {
            tmp[i].print();
        }
*/
        cout<<"brute result end"<<endl<<endl;
        
        
    }
    void javis(const vector<Point> &input, vector<Point> &output1, vector<Point> &output2)
    {
        Point p, r;
        Point q(FindLowestPoint(input));
        const Point non(-2 * 0x3f3f3f3f, q.gety());
        //q.print();
        //cout<<input[6].getx()<<" "<<input[6].gety()<<endl;
        //const Point start=q;
        //non.print();
        int ppos, qpos, rpos; //input[ppos]=p,input[qpos]=q,input[rpos]=r;
        ppos = -1;
        int sz = input.size();
        int used[sz]; //0 for unused
        for (int i = 0; i < sz; i++)
            used[i] = 0;
        for (int i = 0; i < sz; i++)
        {
            if ((input[i].getx() == q.getx()) && (input[i].gety() == q.gety()))
            {
                qpos = i;
            }

            //cout<<endl;
            //input[i].print();
            //q.print();
            //cout<<endl;
        }
        if (qpos == 0)
            rpos = 1;
        else
            rpos = 0;
        int start = qpos;
        //cout<<"fuck"<<endl;
        //cout<<qpos<<endl;
        while (!(rpos == start))
        {
            double angle = -180;
            rpos = -1;
            //cout<<"fuck"<<endl;
            for (int i = 0; i < sz; i++)
            {
                //r=input[i];
                if (i == qpos)
                    continue;
                double tmp;
                if (ppos != -1)
                {
                    //cout << "yes" << endl;
                    tmp = ComputeAngle(input[ppos], input[qpos], input[i]);
                    //cout<<"yesyes"<<endl;
                }
                else if (ppos == -1)
                {
                    //cout << "no" << endl;
                    tmp = ComputeAngle(non, input[qpos], input[i]);
                    //cout<<"nono"<<endl;
                }
                if (tmp > angle)
                {
                    angle = tmp;
                    rpos = i;
                }
            }
            r = input[rpos];
            output2.push_back(input[rpos]);
            used[rpos]=1;
            //p=q;
            //q=r;
            ppos = qpos;
            qpos = rpos;
        }
        for(int i=0;i<sz;i++)
        {
            if(used[i]==0) output1.push_back(input[i]);
        }
        cout<<"javis result start"<<endl;
        
        int nonsz=output1.size();
        cout<<nonsz<<endl;
        //for(int i=0;i<nonsz;i++)
        //{
        //    output1[i].print();
       // }
        
        
        int outsz = output2.size();
        cout << endl
             << outsz << endl;
        //for (int i = 0; i < outsz; i++)
        //{
        //    output2[i].print();
        //}
        cout<<"javis result end"<<endl;
        
    }

private:
    Line FindLine(const Point &p, const Point &q)
    {
        //find line and return line
        double m = q.getx() - p.getx();
        if (m == 0)
        {
            double a = 1;
            double b = 0;
            double c = -1 * q.getx();
            Line ans(a, b, c);
            return ans;
        }
        else
        {
            m = (q.gety() - p.gety()) / m;
            double a = -1 * m;
            double b = 1;
            double c = -1 * p.gety() + m * p.getx();
            Line ans(a, b, c);
            return ans;
        }
    }
    double cross(const Point &p, const Point &q, const Point &r) //pr cross pq if >0  pq to pr is counterclockwise(r at pq's left) http://web.ntnu.edu.tw/~algo/ConvexHull.html
    {
        //cout << (q.getx() - p.getx()) * (r.gety() - p.gety()) - (q.gety() - p.gety()) * (r.getx() - p.getx()) << endl;
        ;
        return (q.getx() - p.getx()) * (r.gety() - p.gety()) - (q.gety() - p.gety()) * (r.getx() - p.getx());
    }
    bool isOnRight(const Point &p, const Point &q, const Point &r)
    {
        // return true if r is on the right side of the line from p to q. If pq is horizontal, return true only if r is above it.
        if (p.gety() == q.gety())
        {
            Line line = FindLine(p, q);
            if (r.getx() * line.geta() + r.gety() * line.getb() + line.getc() > 0)
            {
                return true;
            }
            else
                return false;
        }
        else
        {
            if (cross(p, q, r) >= 0)
                return false;
            else
                return true;
        }
    }
    Point FindLowestPoint(const vector<Point> &input)
    {
        int sz = input.size();
        double miny, minx;
        miny = input[0].gety();
        minx = input[0].getx();
        int minpos = 0;
        for (int i = 1; i < sz; i++)
        {
            if (input[i].gety() < miny)
            {
                miny = input[i].gety();
                minx = input[i].getx();
                minpos = i;
            }
            else if (input[i].gety() == miny)
            {
                if (input[i].getx() <= minx)
                {
                    miny = input[i].gety();
                    minx = input[i].getx();
                    minpos = i;
                }
            }
        }
        //cout<<minpos<<endl;
        //input[minpos].print();
        return input[minpos];
    }
    double ComputeAngle(const Point &p, const Point &q, const Point &r) //find pqr https://blog.csdn.net/xiangxianghehe/article/details/99544534
    {
        //p.print();
        //q.print();
        //r.print();
        double angle = atan2(p.getx() - q.getx(), p.gety() - q.gety()) - atan2(r.getx() - q.getx(), r.gety() - q.gety());
        if (angle > PI)
            angle -= 2 * PI;
        if (angle < -PI)
            angle += 2 * PI;
        //cout << angle << endl;
        angle = abs(angle * 180 / PI);
        //cout << angle << endl;
        return angle;
    }
};
#include<bits/stdc++.h>
#include"Polygon.cpp"
using namespace std;


extern ifstream in;
int main()
{
    int n;
    point pts1[1024];
    point pts2[1024];
    int size1 = 0;
    int size2 = 0;
    Polygon a, b;
    Polygon *copy_a;
    cout<<endl<<endl<<"build poly1"<<endl<<endl;
    while (in >> n)
    {
        if (n == 1)
        {
            pts1[size1].way = 1;
            int x, y;
            in >> x >> y;
            pts1[size1].x = x;
            pts1[size1].y = y;
            size1++;
            continue;
        }
        if (n == 2)
        {
            pts1[size1].way = 2;
            int x, y;
            in >> x >> y;
            pts1[size1].x = x;
            pts1[size1].y = y;
            size1++;
            continue;
        }
        if (n == -1)
        {
            a.setPolygon(pts1, size1);
            break;
        }
    }
    
    cout<<endl<<endl<<"build poly1"<<endl<<endl;
    cout<<endl<<endl<<"build poly2"<<endl<<endl;
    
    while (in >> n)
    {
        if (n == 1)
        {
            pts2[size2].way = 1;
            int x, y;
            in >> x >> y;
            pts2[size2].x = x;
            pts2[size2].y = y;
            size2++;
            continue;
        }
        if (n == 2)
        {
            pts2[size2].way = 2;
            int x, y;
            in >> x >> y;
            pts2[size2].x = x;
            pts2[size2].y = y;
            size2++;
            continue;
        }
        if (n == -1)
        {
            b.setPolygon(pts2, size2);
            break;
        }
    }
    cout<<endl<<endl<<"build poly2"<<endl<<endl;

    cout<<endl<<endl<<"check if poly1&poly2 collide"<<endl<<endl;
    a.isCollide(b);

    cout<<endl<<endl<<"poly1&poly2 collide checked"<<endl<<endl;

    cout<<endl<<endl<<"build copy"<<endl<<endl;
    copy_a=a.splitPolygon();
    cout<<endl<<endl<<"build copy"<<endl<<endl;

    cout<<endl<<endl<<"check if copy&poly2 collide"<<endl<<endl;
    copy_a->isCollide(b);
    cout<<endl<<endl<<"copy&poly2 collide checked"<<endl<<endl;

    delete copy_a;
    

}


#include<bits/stdc++.h>
#include"LinkedList.cpp"
using namespace std;
extern ifstream in;
class Polygon
{
private:
    LinkedList vertexList;

public:
    Polygon()
    {
        cout << "constructing a Polygon" << endl;
    }
    ~Polygon()
    {
        cout <<endl<<endl<< "Deconstructing a Polygon" <<endl;
        //vertexList.clear();
        //cout<<endl<<endl<<"Deconstruct finished"<<endl<<endl;
    }
    void setPolygon(point pts[], int size)
    {
        vertexList.clear();
        for (int i = 0; i < size; i++)
        {
            if (pts[i].way == 1)
                vertexList.insertToNext(pts[i]);
            if (pts[i].way == 2)
                vertexList.insertToPrev(pts[i]);
        }
        cout << "setPolygon finished. ";
        vertexList.getCurrentPoint();
    }
    
    void printPoly()
    {
        vertexList.printall();
    }
    
    Polygon *splitPolygon()
    {
        int size = vertexList.getSize();
        int m = floor(size / 2) + 1;
        Polygon* newPoly = new Polygon();

        for (int i = 0; i < m; i++)
        {
            newPoly->vertexList.insertToNext(this->vertexList.getCurrentPoint());
            this->vertexList.pointToNext();
        }
        for(int i=0;i<size-m;i++)
        {
            vertexList.deleteCurrentNode();
        }

        return newPoly;
    }
    bool isCollide(Polygon &inPolygon)
    {
        int size=inPolygon.vertexList.getSize();
        point polystart, polyend;
        bool flag=false;
        if(size==0)
        {
            cout<<"the input polygon does not exist"<<endl;
            return false;
        }
        if(size==1)
        {
            cout<<"the input is not a polygon"<<endl;
            cout<<"it is impossible to collide"<<endl;
            return false;
        }
        if(size==2)
        {
            cout<<"warning:the input is a line not a polygon";
            polystart=inPolygon.vertexList.getCurrentPoint();
            inPolygon.vertexList.pointToNext();
            polyend=inPolygon.vertexList.getCurrentPoint();
            flag=isEdgeIntersect(polystart,polyend);
            if(flag==true)
            {
                cout<<"this line collides this polygon"<<endl;
                return flag;
            }
            else
            {
                cout<<"this line does not collide with this polygon"<<endl;
                return flag;
            }
        }
        if(size>=3)
        {
            for(int i=0;i<size-1;i++)
            {
                polystart=inPolygon.vertexList.getCurrentPoint();
                inPolygon.vertexList.pointToNext();
                polyend=inPolygon.vertexList.getCurrentPoint();
                flag=isEdgeIntersect(polystart,polyend);
                if(flag==true)
                {
                    cout<<"this input polygon collides this polygon"<<endl;
                    return flag;
                }

            }
            if(flag==true)
                {
                    cout<<"this input polygon collides this polygon"<<endl;
                    return flag;
                }
            if(flag==false)
            {
                cout<<"this input polygon does not collide with this polygon"<<endl;
                return flag;

            }



        }
        return flag;


    }
    bool isEdgeIntersect(const point &ptA, const point &ptB)
    {
        point polystart, polyend;
        bool flag = false;
        int count = 0;
        int size = vertexList.getSize();
        if (size >= 3)
        {
            count = 0;
            while (count <= size)
            {
                polystart = vertexList.getCurrentPoint();
                vertexList.pointToNext();
                polyend = vertexList.getCurrentPoint();

                flag = doIntersect(ptA, ptB, polystart, polyend);
                if (flag == true)
                    break;
                count++;
            }
        }
        else
            cout << "This is not a polygon" << endl;
        return flag;
    }
};

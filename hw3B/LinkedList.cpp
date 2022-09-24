#include<bits/stdc++.h>
using namespace std;
ifstream in("polydata.txt");
struct point
{
    int x;
    int y;
    int way; //for input 1 2
};
struct node
{
    point pt;
    node *next;
    node *prev;
};
bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}
int orientation(point p, point q, point r)
{
    // reference from http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0; // colinear

    return (val > 0) ? 1 : 2; // clock or counterclock wise
}
bool doIntersect(point p1, point q1, point p2, point q2)
{
    //Find four orientations needed for general and special case
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case- line segment A crosses  line segment B, looks like shape X.
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases-one end point of line segment A(p1-q1 or p2-q2) lie s on line segment B(p2-q2 or p1-q1), looks like shape T.
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false;
}

class LinkedList
{
private:
    node *current_ptr;
    int size; //for simplify

public:
    LinkedList()
    {
        cout << "constructing a LinkedList" << endl;
        current_ptr = NULL;
        size = 0;
    }
    ~LinkedList()
    {
        cout << "Deconstructing a LinkedList" << endl;
        clear();
        cout << endl
             << endl
             << "Deconstruct finished" << endl
             << endl;
    }
    int getSize() const
    {
        cout << "size=" << size << endl;
        return size;
    }
    bool isEmpty()
    {
        if (size == 0)
        {
            //cout << "List is empty" << endl;
            return true;
        }
        else
        {
            //cout << "List is not empty" << endl;
            return false;
        }
    }
    void printall()
    {
        cout << "size=" << size << endl;
        for (int i = 0; i < size; i++)
        {
            getCurrentPoint();
            pointToNext();
        }
    }
    void pointToNext()
    {

        current_ptr = current_ptr->next;
        cout << "move to point:(" << current_ptr->pt.x << " , " << current_ptr->pt.y << ")" << endl;
    }
    void pointToPrev()
    {
        current_ptr = current_ptr->prev;
        cout << "move to point:(" << current_ptr->pt.x << " , " << current_ptr->pt.y << ")" << endl;
    }
    point getCurrentPoint() const
    {
        cout << "current point :(" << current_ptr->pt.x << " , " << current_ptr->pt.y << ")" << endl;
        return current_ptr->pt;
    }
    void insertToNext(const point &pt)
    {
        if (isEmpty())
        {
            current_ptr = new node;
            current_ptr->pt = pt;
            current_ptr->next = current_ptr;
            current_ptr->prev = current_ptr;
            size++;
            pointToNext();

            cout << "inserted a pt to next" << endl;
            //getCurrentPoint();
            return;
        }
        else if (size == 1)
        {
            //node *tmp = current_ptr;
            current_ptr->next = new node;
            current_ptr->prev = current_ptr->next;
            current_ptr->next->pt = pt;
            current_ptr->next->next = current_ptr;
            current_ptr->next->prev = current_ptr;
            pointToNext();
            size++;
            cout << "inserted a pt to next" << endl;
        }
        else
        {
            node *tmp = current_ptr->next;
            current_ptr->next = new node;
            current_ptr->next->pt = pt;
            current_ptr->next->next = tmp;
            current_ptr->next->prev = current_ptr;
            tmp->prev = current_ptr->next;
            pointToNext();
            size++;
            cout << "inserted a pt to next" << endl;
            return;
        }
    }
    void insertToPrev(const point &pt)
    {
        if (isEmpty())
        {
            current_ptr = new node;
            current_ptr->pt = pt;
            current_ptr->next = current_ptr;
            current_ptr->prev = current_ptr;
            size++;
            pointToPrev();
            cout << "inserted a pt to prev" << endl;
            //getCurrentPoint();
            return;
        }
        else if (size == 1)
        {
            //node *tmp = current_ptr;
            current_ptr->next = new node;
            current_ptr->prev = current_ptr->next;
            current_ptr->next->pt = pt;
            current_ptr->next->next = current_ptr;
            current_ptr->next->prev = current_ptr;
            pointToPrev();
            size++;
            cout << "inserted a pt to prev" << endl;
        }
        else
        {
            node *tmp = current_ptr->prev;
            current_ptr->prev = new node;
            current_ptr->prev->pt = pt;
            current_ptr->prev->prev = tmp;
            current_ptr->prev->next = current_ptr;
            tmp->next = current_ptr->prev;
            pointToPrev();
            size++;
            cout << "inserted a pt to prev" << endl;
            return;
        }
    }
    void deleteCurrentNode()
    {
        if (isEmpty())
        {
            cout << "nothing to delete" << endl;
            return;
        }
        else if (size == 1)
        {
            node *tmp = current_ptr;
            current_ptr = NULL;
            cout << "delete point:(" << tmp->pt.x << " , " << tmp->pt.y << ")" << endl;
            delete tmp;
            size--;
            return;
        }
        else
        {
            node *tmp = current_ptr;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            pointToNext();
            cout << "delete point:(" << tmp->pt.x << " , " << tmp->pt.y << ")" << endl;
            delete tmp;
            size--;
            return;
        }
    }
    void clear()
    {
        while (!isEmpty())
        {
            deleteCurrentNode();
        }
    }
};
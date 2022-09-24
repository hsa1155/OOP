#include <bits/stdc++.h>
#include <fstream>
#define DEBUG 0
using namespace std;
ifstream inp("polydata.txt", ios::in);
//ofstream out("ans.txt", ios::out);

int HighestPower(vector<double> poly)
{
    poly[0] = (int)poly[0];
    if (poly[0] + 2 != poly.size())
    {
        cout << endl;
        cout << "file input error.this input is illegal" << endl
             << endl;
        //out << "file input error.this input is illegal" << endl
        //    << endl;
        cout << "raw input:";
        //out << "raw input:";
        for (int j = 0; j < poly.size(); j++)
        {
            cout << poly[j] << " ";
        //    out << poly[j] << " ";
        }
        cout << endl
             << endl;
        ;
        //out << endl
        //    << endl;
        ;
        return -1;
    }
    return poly[0];
}
void display(int HighestPower, vector<double> poly)
{
    int sta = 0; // 0 for no output
    for (int i = 1; i <= HighestPower + 1; i++)
    {
        if (poly[i] == 0)
            continue;
        cout << poly[i];
        //out << poly[i];
        sta = 1;
        for (int j = 0; j < i - 1; j++)
        {
            cout << "*x";
            //out << "*x";
        }
        if (i != HighestPower + 1)
        {
            cout << " + ";
            //out << " + ";
        }
    }
    if (sta == 0) //if no output.putput1
    {
        cout << 0;
        //out << 0;
    }
    cout << endl;
    //out << endl;
}
void derivate(int HighestPower, vector<double> poly, vector<double> &depoly)
{
    depoly.push_back(HighestPower - 1);
    for (int i = 1; i <= HighestPower; i++)
    {
        depoly.push_back(poly[i + 1] * i);
    }
}
double compute(int HighestPower, vector<double> poly, double x)
{
    double sum = 0;
    for (int i = 1; i <= HighestPower + 1; i++)
    {
        sum += poly[i] * pow(x, i - 1);
    }

    return sum;
}

int main()
{
    if (DEBUG)
    {
        cout << "DEBUG MODE" << endl;

        string buf;
        int counter = 0;
        while (getline(cin, buf))
        {
            counter++;
            cout << "Question " << counter << ":" << endl;
            stringstream tmp(buf);
            vector<double> poly;
            vector<double> depoly;
            int geterror = 0;
            double a;

            while (!tmp.eof())
            {

                if (!(tmp >> a))
                {
                    cout << endl;
                    cout << "file input error.this input contains something that is not number" << endl
                         << endl;
                    tmp.clear();
                    poly.clear();
                    geterror = 1;
                    // cout << "input 1 to continue" << endl;
                    /*
                    while (1)
                    {
                        char c;

                        c = getchar();
                        if (c == '1')
                            break;
                        else if (c == '\n')
                            continue;
                        else
                            cout << "input 1 to continue" << endl;
                    }
                    */
                    break;
                }

                poly.push_back(a);
            }
            if (geterror == 1)
                continue;

            int HP = HighestPower(poly);
            if (HP < 0)
            {
                //cout << "input 1 to continue" << endl;
                /*
            while (1)
            {
                char c;

                c = getchar();
                if (c == '1')
                    break;
                else if (c == '\n')
                    continue;
                else
                    cout << "input 1 to continue" << endl;
            }
            */
                continue;
            }
            double x;
            cout << "please input a number x to calculate value" << endl;
            while (1)
            {
                cin >> x;
                if (cin.fail())
                {
                    cout << "that is not a number. try again" << endl;
                    cin.clear();
                    while (cin.get() != '\n')
                    {
                        continue;
                    }
                }
                else
                    break;
            }

            cout << "f(x)=";
            display(HP, poly);
            derivate(HP, poly, depoly);
            cout << "f'(x)=";
            display(HP - 1, depoly);

            cout << "f(" << x << ") = " << round(compute(HP, poly, x) * 10000) / 10000 << endl;

            cout << "f'(" << x << ") = " << round(compute(HP - 1, depoly, x) * 10000) / 10000 << endl;
        }
    }
    else
    {

        string buf;
        int counter = 0;
        while (getline(inp, buf))
        {
            counter++;
            cout << "Question " << counter << ":" << endl;
            //out << "Question " << counter << ":" << endl;
            stringstream tmp(buf);
            vector<double> poly;
            vector<double> depoly;
            int geterror = 0;
            double a;

            while (!tmp.eof())
            {

                if (!(tmp >> a))
                {
                    cout << endl;
                    cout << "file input error.this input contains something that is not number" << endl
                         << endl;
                    //out << "file input error.this input contains something that is not number" << endl
                     //   << endl;
                    tmp.clear();
                    poly.clear();
                    geterror = 1;
                    // cout << "input 1 to continue" << endl;
                    /*
                    while (1)
                    {
                        char c;

                        c = getchar();
                        if (c == '1')
                            break;
                        else if (c == '\n')
                            continue;
                        else
                            cout << "input 1 to continue" << endl;
                    }
                    */
                    break;
                }

                poly.push_back(a);
            }
            if (geterror == 1)
                continue;
            int HP = HighestPower(poly);
            if (HP < 0)
            {
                //cout << "input 1 to continue" << endl;
                /*
            while (1)
            {
                char c;

                c = getchar();
                if (c == '1')
                    break;
                else if (c == '\n')
                    continue;
                else
                    cout << "input 1 to continue" << endl;
            }
            */
                continue;
            }
            double x;
            cout << "please input a number x to calculate value" << endl;
            while (1)
            {
                cin >> x;
                if (cin.fail())
                {
                    cout << "that is not a number. try again" << endl;
                    cin.clear();
                    while (cin.get() != '\n')
                    {
                        continue;
                    }
                }
                else
                    break;
            }
            //out << "x=" << x << endl;

            cout << "f(x) = ";
            //out << "f(x) = ";
            display(HP, poly);
            derivate(HP, poly, depoly);
            cout << "f'(x) = ";
            //out << "f'(x) = ";
            display(HP - 1, depoly);

            cout << "f(" << x << ") = " << round(compute(HP, poly, x) * 10000) / 10000 << endl;
            //out << "f(" << x << ") = " << round(compute(HP, poly, x) * 10000) / 10000 << endl;

            cout << "f'(" << x << ") = " << round(compute(HP - 1, depoly, x) * 10000) / 10000 << endl<<endl;;
            //out << "f'(" << x << ") = " << round(compute(HP - 1, depoly, x) * 10000) / 10000 << endl<<endl;;

            // cout << "input 1 to continue" << endl;
            /*
            while (1)
            {
                char c;

                c = getchar();
                if (c == '1')
                    break;
                else if (c == '\n')
                    continue;
                else
                    cout << "input 1 to continue" << endl;
            }
            */
        }
    }
}

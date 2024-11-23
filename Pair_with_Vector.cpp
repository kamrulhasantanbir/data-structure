#include<bits/stdc++.h>
using namespace std;
void menu()
{
    cout<<"01.insert value \n02.erase value \n03.Print value \n04.Update value \n05.Sort element \n6.Print the list \n7.Print menu \n8.End program "<<endl;
}
bool cmp(pair<string, double> a, pair<string, double> b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

int main()
{
    vector<pair<string,double>>V;
    int n;
    menu();

    do
    {

        cout<<"Enter your choice :";
        cin>>n;
        switch(n)
        {
        case 1:
        {
            string s;
            double d;
            cout<<"Enter student name :";
            cin.ignore();
            getline(cin,s);
            cout << "Enter the mark: ";
            cin >> d;
            pair<string,double>pr=make_pair(s,d);

            int p;
            cout << "Enter position (1 - " << V.size()+1 << "): ";
            cin >> p;
            p--;
            if (p < 0 || p > V.size())
            {
                cout << "Invalid position" << endl;
            }
            else
            {
                if (p == V.size())
                {
                    V.push_back(pr);
                    //V.push_back({s,d});
                }
                else
                {
                    V.insert(V.begin() + p, pr);
                    //V.insert(V.begin() + p, {s, d});
                }
                cout << "Value inserted successfully" << endl;
            }


        }
        break;
        case 2:
        {
            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }

            int p;
            cout << "Enter position (1 - " << V.size() << "): ";
            cin >> p;
            p--;

            if (p < 0 || p >= V.size())
            {
                cout << "Invalid position" << endl;
                break;
            }

            if (p == V.size() - 1)
            {
                V.pop_back();
            }
            else
            {
                V.erase(V.begin() + p);
            }

            cout << "Value erased successfully" << endl;
        }
        break;

        case 3:
        {
            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }

            int p;
            cout << "Enter position (1 - " << V.size() << "): ";
            cin >> p;
            p--;

            if (p < 0 || p >= V.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            cout << "Student: " << V[p].first << ", Mark: " << V[p].second << endl;
            //another way:
            /*
            auto [name,mark]=V[p];
            cout << "Student: " << name << ", Mark: " << mark << endl;
            */
        }
        break;
        case 4:
        {
            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }

            int p;
            cout << "Enter position (1 - " << V.size() << "): ";
            cin >> p;
            p--;

            if (p < 0 || p >= V.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            else
            {
                cout<<"Enter new name of the student :";
                string s;
                cin.ignore();
                getline(cin,s);
                cout<<"Enter new mark of the student :";
                double d;
                cin>>d;
                V[p].first=s;
                V[p].second=d;

                /*another way:
                V[p]={s,d}; */

                /*another way:
                pair<string,double>pr=make_pair(s,d);
                V[p]=pr;
                */
            }
        }
        break;
        case 5:
        {
            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }

            vector<pair<string, double>> tempV = V;

            sort(tempV.begin(), tempV.end(), cmp);

            int idx = 1;
            for (auto [name, mark] : tempV)
            {
                cout << idx << ". " << name << " - " << mark << endl;
                idx++;
            }
            cout << "Displayed sorted list temporarily" << endl;
        }
        break;

        case 6:
        {

            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            int idx=1;
            for(auto[name,mark]:V)
            {
                cout<<idx<<". "<<name<<" - "<<mark<<endl;
                idx++;
            }
            //another way:
            /*
             for(int i=0;i<V.size();i++){
                cout<<i+1<<". "<<V[i].first<<" - "<<V[i].second<<endl;
             }

            */

            //another way:
            /*
            int idx = 1;
            vector<pair<string, double>>::iterator it ;
            for (it=V.begin(); it != V.end();it++) {
            cout << idx << ". " << it->first << " - " << it->second << endl;
            idx++;
            }

            */

        }

        break;
        case 7:
        {
            menu();
        }
        break;
        case 8:
        {
            cout<<"terminating the program"<<endl;
        }
        break;

        }

    }
    while(n!=8);
}

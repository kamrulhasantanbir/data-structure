#include<bits/stdc++.h>
using namespace std;
void menu()
{
    cout<<"01.insert value \n02.erase value \n03.Print value \n04.clear list \n05.resize \n06.replace value \n07.size of list \n08.Sort element \n09.Reverse \n10.find element \n11.Insert multiple element \n12.erase multiple element \n13.Max element \n14.min element \n15.Capacity \n16.Count occurrence \n17.Unique elements \n18.Print the list \n19.Print menu \n20.End program "<<endl;
}
int main()
{
    vector<double>V;
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
            double d;
            cout << "Enter the value: ";
            cin >> d;

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
                    V.push_back(d);
                }
                else
                {
                    V.insert(V.begin() + p, d);
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
            cout<<V[p]<<endl;
        }
        break;
        case 4:
        {
            V.clear();
            cout<<"List is cleared"<<endl;
        }
        break;
        case 5:
        {
            int size1 = V.size();
            cout << "Enter new size for the list: ";
            int s;
            cin >> s;
            if (s < 0)
            {
                cout << "Invalid size" << endl;
            }
            else if (s > size1)
            {
                cout << "New size is bigger than current size. Want to fill with a specific value? Type 'Y' for yes, otherwise type 'NO': ";
                string str;
                cin >> str;

                if (str == "Y")
                {
                    double x;
                    cout << "Enter value to fill: ";
                    cin >> x;
                    V.resize(s, x);
                }
                else if (str == "NO")
                {
                    V.resize(s);
                }
                else
                {
                    cout << "Invalid input. No operation performed." << endl;
                    break;
                }
            }

            else
            {
                V.resize(s);
            }

            cout << "List is resized to " << s << endl;
        }
        break;
        case 6:
        {
            cout << "Enter the position ( 1 - " << V.size() << " ) : ";
            int x;
            cin >> x;
            x--;
            if (x < 0 || x >= V.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            cout << "Enter new value : ";
            double val;
            cin >> val;
            V[x] = val;
            cout << "Value is updated successfully" << endl;
        }

        break;
        case 7:
        {
            cout<<"Current size of list :"<<V.size()<<endl;
        }
        break;
        case 8:
        {
            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            sort(V.begin(),V.end());
            cout<<"List is sorted"<<endl;
        }
        break;
        case 9:
        {
            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            reverse(V.begin(),V.end());
            cout<<"List is reversed"<<endl;
        }
        break;
        case 10:
        {
            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            cout<<"Enter value to find :";
            double val;
            cin>>val;
            auto it = find(V.begin(), V.end(), val);

            if (it != V.end())
                cout << "Index: " << it - V.begin() << endl;
            else
                cout << "No" << endl;


            /*
            //another way
            int val;
            cin >> val;
            int found = -1;
            for (int i = 0; i < V.size(); i++) {
            if (V[i] == val) {
            found = i;
            break;
            }
            }
            if (found != -1)
            cout << "Index: " << found << endl;
            else
            cout << "No" << endl;
            */
        }
        break;
        case 11:
        {
            cout << "Enter number of elements you want to insert: ";
            int n;
            cin >> n;
            vector<int> newValues(n);
            cout << "Enter values: ";
            for (int i = 0; i < n; i++)
            {
                cin >> newValues[i];
            }
            cout << "Enter the position ( 1 - " << V.size() + 1 << " ) : ";
            int p;
            cin >> p;
            p--;
            if (p < 0 || p > V.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            V.insert(V.begin() + p, newValues.begin(), newValues.end());
            cout << "Values are inserted successfully" << endl;

            /*
            //another way
            cout << "Enter number of elements you want to insert: ";
            int n;
            cin >> n;
            int arr[n];
            cout << "Enter values: ";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            cout << "Enter the position ( 1 - " << V.size() + 1 << " ) : ";
            int p;
            cin >> p;
            p--;
            if (p < 0 || p > V.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            V.insert(V.begin() + p, arr, arr + n);
            cout << "Values are inserted successfully" << endl;

            */


        }
        break;
        case 12:
        {

            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            cout << "Enter the starting position ( 1 - " << V.size() << " ) : ";
            int p1;
            cin >> p1;
            if (p1 < 1 || p1 > V.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            cout << "Enter the ending position ( " << p1 << " - " << V.size() << " ) : ";
            int p2;
            cin >> p2;
            if (p2 < p1 || p2 > V.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            p1--;
            p2--;
            V.erase(V.begin() + p1, V.begin() + p2 + 1);
            cout << "Values from position " << p1 + 1 << " to position " << p2 + 1 << " have been deleted" << endl;

        }
        break;
        case 13:
        {
            if (!V.empty())
            {
                double maxElement = *max_element(V.begin(), V.end());
                cout << "Max element: " << maxElement << endl;
            }
            else
            {
                cout << "Vector is empty" << endl;
            }
        }
        break;

        case 14:
        {
            if (!V.empty())
            {
                double minElement = *min_element(V.begin(), V.end());
                cout << "Min element: " << minElement << endl;
            }
            else
            {
                cout << "Vector is empty" << endl;
            }
        }
        break;

        case 15:
        {
           cout<<"Current capacity of list is :"<<V.capacity()<<endl;
        }
        break;

        case 16:
        {

 if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            cout << "Enter value to count occurrences: ";
            int val;
            cin >> val;
            int count1 = count(V.begin(), V.end(), val);
            cout << "Occurrences of " << val << ": " << count1 << endl;

        }
        break;

        case 17:
        {
            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            set<double> uniqueElements(V.begin(), V.end());
            cout << "Unique elements: ";
            for (double elem : uniqueElements)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
        break;

        case 18:
        {
            if (V.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            cout<<"Current list :";
            for(int i=0; i<V.size(); i++)
            {
                cout<<V[i]<<" ";
            }
            cout<<'\n';
        }
        break;
        case 19:
        {
            menu();
        }
        break;
        case 20:
        {
            cout<<"Program is terminated"<<endl;
        }
        break;
        default:
        {
            cout<<"Invalid input"<<endl;
        }
        }


    }
    while(n!=20);
}

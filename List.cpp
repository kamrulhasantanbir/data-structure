#include <bits/stdc++.h>
using namespace std;

void menu()
{
    cout << "01. Insert value\n02. Erase value\n03. Print value\n04. Clear list\n"
         << "05. Resize\n06. Replace index value\n07. Size of list\n08. Sort elements\n"
         << "09. Reverse\n10. Find element\n11. Insert multiple elements\n"
         << "12. Erase multiple elements\n13. Max element\n14. Min element\n"
         << "15. Count occurrence\n16. Unique elements\n17. Print the list\n"
         << "18. Print menu \n19 Replace specific value \n20. End program\n";
}

int main()
{
    list<double> L;
    int n;
    menu();

    do
    {
        cout << "Enter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            double d;
            cout << "Enter the value: ";
            cin >> d;

            int p;
            cout << "Enter position (1 - " << L.size()+1 << "): ";
            cin >> p;
            p--;
            if (p < 0 || p > L.size())
            {
                cout << "Invalid position" << endl;
            }
            else
            {
                if (p == L.size())
                {
                    L.push_back(d);
                }
                else if(p==0)
                {
                    L.push_front(d);
                }
                else
                {
                    list<double>::iterator it=next(L.begin(),p);
                    L.insert(it, d);
                }
                cout << "Value inserted successfully" << endl;
            }


        }
        break;

        case 2:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            int p;
            cout << "Enter position (1 - " << L.size() << "): ";
            cin >> p;
            if (p < 1 || p > L.size())
            {
                cout << "Invalid position" << endl;
            }
            else
            {
                if(p==1)
                {
                    L.pop_front();
                }
                else if(p==L.size())
                {
                    L.pop_back();
                }
                else
                {
                    list<double>::iterator it=next(L.begin(),p-1);
                    L.erase(it);
                }
                cout << "Value erased successfully" << endl;
            }
        }
        break;

        case 3:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            int p;
            cout << "Enter position (1 - " << L.size() << "): ";
            cin >> p;
            if (p < 1 || p > L.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            if(p==1)
            {
                cout<<L.front()<<endl;
            }
            else if(p==L.size())
            {
                cout<<L.back()<<endl;
            }
            else
            {
                cout << *next(L.begin(),p-1) << endl;
            }
        }
        break;

        case 4:
        {
            L.clear();
            cout << "List is cleared" << endl;
        }
        break;

        case 5:
        {
            int newSize;
            cout << "Enter new size for the list: ";
            cin >> newSize;
            if (newSize < 0)
            {
                cout << "Invalid size" << endl;
            }
            else
            {
                double value = 0;
                if (newSize > L.size())
                {
                    cout << "Enter value to fill new index: ";
                    cin >> value;
                }
                L.resize(newSize, value);
                cout << "List is resized to " << newSize << endl;
            }
        }
        break;

        case 6:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            int p;
            cout << "Enter position (1 - " << L.size() << "): ";
            cin >> p;
            if (p < 1 || p > L.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            list<double>::iterator it=next(L.begin(),p-1);
            double val;
            cout << "Enter new value: ";
            cin >> val;
            *it = val;
            cout << "Value is updated successfully" << endl;
        }
        break;

        case 7:
        {
            cout << "Current size of the list: " << L.size() << endl;
        }
        break;

        case 8:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            L.sort();
            cout << "List is sorted" << endl;
        }
        break;

        case 9:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            L.reverse();
            cout << "List is reversed" << endl;
        }
        break;

        case 10:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            double val;
            cout << "Enter value to find: ";
            cin >> val;
            auto it = find(L.begin(), L.end(), val);
            if (it != L.end())
                cout << "Value found" << endl;
            else
                cout << "Value not found" << endl;
        }
        break;

        case 11:
        {
            int p;
            cout << "Enter position (1 - " << L.size() << "): ";
            cin >> p;
            if (p < 1 || p > L.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            list<double>::iterator it=next(L.begin(),p-1);
            int num;
            cout << "Enter number of elements to insert: ";
            cin >> num;
            list<double> newValues;
            cout << "Enter values: ";
            for (int i = 0; i < num; ++i)
            {
                double val;
                cin >> val;
                newValues.push_back(val);
            }
            L.insert(it, newValues.begin(), newValues.end());
            cout << "Values inserted successfully" << endl;
        }
        break;

        case 12:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            cout << "Enter the starting position ( 1 - " << L.size() << " ) : ";
            int p1;
            cin >> p1;
            if (p1 < 1 || p1 > L.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            cout << "Enter the ending position ( " << p1 << " - " << L.size() << " ) : ";
            int p2;
            cin >> p2;
            if (p2 < p1 || p2 > L.size())
            {
                cout << "Invalid position" << endl;
                break;
            }
            list<double>::iterator it1=next(L.begin(),p1-1);
            list<double>::iterator it2=next(L.begin(),p2);
            L.erase(it1,it2);
            cout << "Values from position " << p1 << " to position " << p2 << " have been deleted" << endl;

        }
        break;

        case 13:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
            }
            else
            {
                double maxElement = *max_element(L.begin(), L.end());
                cout << "Max element: " << maxElement << endl;
            }
        }
        break;

        case 14:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
            }
            else
            {
                double minElement = *min_element(L.begin(), L.end());
                cout << "Min element: " << minElement << endl;
            }
        }
        break;

        case 15:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            double val;
            cout << "Enter value to count: ";
            cin >> val;
            int count1 = count(L.begin(), L.end(), val);
            cout << "Occurrences of " << val << ": " << count1 << endl;
        }
        break;

        case 16:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            L.unique();
            cout << "Consecutive duplicates removed" << endl;
        }
        break;

        case 17:
        {
            if (L.empty())
            {
                cout << "List is empty" << endl;
                break;
            }
            cout << "Current list: ";
            for (double val : L)
            {
                cout << val << " ";
            }
            cout << endl;
        }
        break;

        case 18:
        {
            menu();
        }
        break;

        case 19:
        {
            if (!L.empty())
            {
                cout << "Enter value you want to replace: ";
                double old;
                cin >> old;
                if (find(L.begin(), L.end(), old) == L.end())
                {
                    cout << "Value not found in the list" << endl;
                    break;
                }
                cout << "Enter new value to set: ";
                double newValue;
                cin >> newValue;

                replace(L.begin(), L.end(), old, newValue);

                cout << "All " << old << " are replaced by " << newValue << endl;
            }
            else
            {
                cout << "List is empty" << endl;
            }
        }
        break;

        case 20:
        {
            cout<<"The program is terminated "<<endl;
        }
        break;
        default:
        {
            cout << "Invalid input" << endl;
        }
        }
    }
    while (n != 20);
}

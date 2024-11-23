
#include <bits/stdc++.h>
using namespace std;

void menu()
{
    cout << "01. Insert Employee \n02. Erase Employee \n03. Print Employee \n04. Update Employee \n05. Sort Employees \n06. Print Employee List \n07. Print Menu \n08. End Program" << endl;
}

bool cmp(const tuple<string, string, string, double>& a, const tuple<string, string, string, double>& b)
{
    if (get<3>(a) != get<3>(b))
    {
        return get<3>(a) > get<3>(b);
    }
    else
    {
        return get<1>(a) < get<1>(b);
    }
}

int main()
{
    vector<tuple<string, string, string, double>> V;
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
            string id, name, position;
            double salary;
            cout << "Enter Employee ID: ";
            cin.ignore();
            getline(cin, id);
            cout << "Enter Employee Name: ";
            getline(cin, name);
            cout << "Enter Position: ";
            getline(cin, position);
            cout << "Enter Salary: ";
            cin >> salary;
            tuple<string, string, string, double> t = make_tuple(id, name, position, salary);

            int p;
            cout << "Enter position (1 - " << V.size() + 1 << "): ";
            cin >> p;
            p--;

            if (p < 0 || p > V.size())
            {
                cout << "Invalid position" << endl;
            }
            else if (p == V.size())
            {
                V.push_back(t);
                //V.push_back({id,name,position,salary});
            }
            else
            {
                V.insert(V.begin() + p, t);
                // V.insert(V.begin() + p, {id,name,position,salary});

            }
            cout << "Employee inserted successfully" << endl;
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
            }
            else
            {
                V.erase(V.begin() + p);
                cout << "Employee erased successfully" << endl;
            }
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
            }
            else
            {
                auto [id, name, position, salary] = V[p];
                cout << "ID: " << id << ", Name: " << name << ", Position: " << position << ", Salary: " << salary << endl;
                //another way
                /*
                tuple<string, string, string, double> t = V[p];
                cout << "ID: " << get<0>(t) << ", Name: " << get<1>(t) << ", Position: " << get<2>(t) << ", Salary: " << get<3>(t) << endl;
                */
            }
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
                string id, name, position;
                double salary;
                cout << "Enter new ID: ";
                cin.ignore();
                getline(cin, id);
                cout << "Enter new Name: ";
                getline(cin, name);
                cout << "Enter new Position: ";
                getline(cin, position);
                cout << "Enter new Salary: ";
                cin >> salary;

                V[p] = make_tuple(id, name, position, salary);
                //V[p] = {id, name, position, salary};
                cout << "Employee updated successfully" << endl;
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

            vector<tuple<string, string, string, double>> tempV = V;
            sort(tempV.begin(), tempV.end(), cmp);
            int idx = 1;
            for (auto [id, name, position, salary] : tempV)
            {
                cout << idx++ << ". " << id << " - " << name << " - " << position << " - " << salary << endl;
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

            int idx = 1;
            for (auto [id, name, position, salary] : V)
            {
                cout << idx++ << ". ID: " << id << ", Name: " << name << ", Position: " << position << ", Salary: " << salary << endl;
            }
            //another way:
            /*
            for (int i = 0; i < V.size(); i++)
            {
                tuple<string, string, string, double>  t = V[i];
                cout << i + 1 << ". ID: " << get<0>(t) << ", Name: " << get<1>(t) << ", Position: " << get<2>(t) << ", Salary: " << get<3>(t) << endl;
                //cout << i + 1 << ". ID: " << get<0>(V[i]) << ", Name: " << get<1>(V[i])<< ", Position: " << get<2>(V[i]) << ", Salary: " << get<3>(V[i]) << endl;
            }
            */
            //another way:
            /*
             int idx = 1;
             tuple<string, string, string, double>::iterator it;
            for (it = V.begin(); it != V.end(); ++it)
            {
            tuple<string, string, string, double> t = *it;
            cout << idx++ << ". " << get<0>(t) << " - " << get<1>(t) << " - " << get<2>(t) << " - " << get<3>(t) << endl;
            }
            */
        }
        break;

        case 7:
            menu();
            break;

        case 8:
            cout << "Terminating the program" << endl;
            break;
        }

    }
    while (n != 8);
}

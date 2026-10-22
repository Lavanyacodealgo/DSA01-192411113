#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    int zone;
    long long balance;

    cout << "Enter zone (1=Inner, 2=Middle, 3=Outer): ";

    while (!(cin >> zone) || zone < 1 || zone > 3)
    {
        cout << "Invalid zone. Enter 1, 2, or 3: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter balance in rupees: ";

    while (!(cin >> balance) || balance < 0)
    {
        cout << "Invalid balance. Enter a non-negative amount: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int fare[] = {10, 20, 30};

    cout << fixed << setprecision(2);

    if (balance - fare[zone - 1] >= 50)
    {
        balance -= fare[zone - 1];
        cout << "Journey approved\n";
        cout << "Remaining balance: Rs " << balance << '\n';
    }
    else
    {
        cout << "Journey denied: minimum Rs 50 must remain\n";
        cout << "Balance: Rs " << balance << '\n';
    }

    return 0;
}

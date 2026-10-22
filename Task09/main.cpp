#include <iostream>
#include <iomanip>
using namespace std;

long long calculateFare(int zone, int hour)
{
    long long fare;

    if (zone == 1)
        fare = 1000;
    else if (zone == 2)
        fare = 2000;
    else if (zone == 3)
        fare = 3000;
    else
        return -1;

    if (hour < 0 || hour > 23)
        return -1;

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        fare += fare * 20 / 100;

    return fare;
}

int main()
{
    int zone, hour;
    long long balance;

    cout << "Enter zone (1=Inner, 2=Middle, 3=Outer): ";
    if (!(cin >> zone))
    {
        cout << "Invalid zone input\n";
        return 0;
    }

    cout << "Enter hour (0-23): ";
    if (!(cin >> hour))
    {
        cout << "Invalid hour input\n";
        return 0;
    }

    cout << "Enter balance in rupees: ";
    if (!(cin >> balance) || balance < 0)
    {
        cout << "Invalid balance\n";
        return 0;
    }

    long long fare = calculateFare(zone, hour);

    if (fare < 0)
    {
        cout << "Invalid zone or hour\n";
        return 0;
    }

    cout << fixed << setprecision(2);

    if (balance * 100 - fare >= 5000)
    {
        balance -= fare / 100;
        cout << "Journey approved\n";
        cout << "Fare: Rs " << fare / 100 << "."
             << setw(2) << setfill('0') << fare % 100 << '\n';
        cout << setfill(' ');
        cout << "Remaining balance: Rs " << balance << '\n';
    }
    else
    {
        cout << "Journey denied: minimum Rs 50 must remain\n";
    }

    return 0;
}

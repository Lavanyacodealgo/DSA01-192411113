#include <iostream>
#include <iomanip>
using namespace std;
constexpr long long MIN_BALANCE = 5000;
long long calculateFare(int zone, bool peak, bool weekend)
{
    long long fare;

    switch (zone)
    {
        case 1: fare = 1000; break;
        case 2: fare = 2000; break;
        case 3: fare = 3000; break;
        case 4: fare = 6000; break;
        default: return -1;
    }

    if (weekend)
        fare -= fare * 10 / 100;
    else if (peak)
        fare += fare * 20 / 100;

    return fare;
}

void displayMoney(long long paise)
{
    cout << "Rs " << paise / 100 << "."
         << setw(2) << setfill('0') << paise % 100
         << setfill(' ');
}

class SmartCard
{
private:
    long long balance;
    int passZone1;
    int passZone2;

public:
    SmartCard(long long amount, int z1, int z2)
        : balance(amount), passZone1(z1), passZone2(z2) {}

    void travel(int zone, bool peak, bool weekend)
    {
        if (zone < 1 || zone > 4)
        {
            cout << "Invalid zone\n";
            return;
        }

        if (zone == passZone1 || zone == passZone2)
        {
            cout << "Monthly pass: Journey free\n";
            cout << "Balance: ";
            displayMoney(balance);
            cout << '\n';
            return;
        }

        long long fare = calculateFare(zone, peak, weekend);

        if (balance - fare >= MIN_BALANCE)
        {
            balance -= fare;
            cout << "Fare: ";
            displayMoney(fare);
            cout << "\nRemaining balance: ";
            displayMoney(balance);
            cout << '\n';
        }
        else
        {
            cout << "Journey denied: minimum Rs 50 must remain\n";
        }
    }
};

int main()
{
    SmartCard card(20000, 1, 2);

    cout << "Airport journey on weekend:\n";
    card.travel(4, true, true);

    cout << "\nAirport journey during weekday peak:\n";
    card.travel(4, true, false);

    cout << "\nMiddle Zone journey using monthly pass:\n";
    card.travel(2, false, false);

    return 0;
}

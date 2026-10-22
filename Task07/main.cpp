
#include <iostream>
using namespace std;

// Procedural approach
void deductFare(long long &balance, long long fare)
{
    if (balance - fare >= 5000)
    {
        balance -= fare;
        cout << "Procedural balance: Rs " << balance / 100 << '\n';
    }
    else
    {
        cout << "Procedural: Journey denied\n";
    }
}

// Object-oriented approach
class SmartCard
{
private:
    long long balance;

public:
    SmartCard(long long amount)
    {
        balance = amount;
    }

    void travel(long long fare)
    {
        if (balance - fare >= 5000)
        {
            balance -= fare;
            cout << "OOP balance: Rs " << balance / 100 << '\n';
        }
        else
        {
            cout << "OOP: Journey denied\n";
        }
    }
};

int main()
{
    long long balance = 10000;
    deductFare(balance, 1000);

    SmartCard card(10000);
    card.travel(1000);

    return 0;
}

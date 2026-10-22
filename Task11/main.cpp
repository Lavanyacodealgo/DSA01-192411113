#include <iostream>
using namespace std;
constexpr long long INNER_FARE = 1000;
constexpr long long MIDDLE_FARE = 2000;
constexpr long long OUTER_FARE = 3000;
constexpr int PEAK_PERCENT = 20;
long long calculateFare(int zone, bool peak)
{
    long long fare;

    switch (zone)
    {
        case 1: fare = INNER_FARE; break;
        case 2: fare = MIDDLE_FARE; break;
        case 3: fare = OUTER_FARE; break;
        default: return -1;
    }

    if (peak)
        fare += fare * PEAK_PERCENT / 100;

    return fare;
}

int main()
{
    cout << "Inner off-peak fare: Rs "
         << calculateFare(1, false) / 100 << '\n';

    cout << "Outer peak fare: Rs "
         << calculateFare(3, true) / 100 << '\n';

    cout << "Time complexity per journey: O(1)\n";

    return 0;
}

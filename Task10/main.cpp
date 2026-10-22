#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main()
{
    double doubleTotal = 0.0;
    long long paiseTotal = 0;

    for (int i = 0; i < 10; i++)
    {
        doubleTotal += 0.10;
        paiseTotal += 10;
    }

    cout << fixed << setprecision(20);
    cout << "Double total: " << doubleTotal << '\n';

    cout << setprecision(2);
    cout << "Integer-paise total: Rs "
         << paiseTotal / 100.0 << '\n';

    long long journeys = 3000000;
    long long farePaise = 3000;
    long long largeTotal = journeys * farePaise;

    cout << "Total for 3000000 journeys: Rs "
         << setprecision(2) << largeTotal / 100.0 << '\n';

    cout << "INT_MAX: " << INT_MAX << '\n';

    if (largeTotal > INT_MAX)
        cout << "Total exceeds INT_MAX\n";

    cout << "Use long long for large totals.\n";

    return 0;
}

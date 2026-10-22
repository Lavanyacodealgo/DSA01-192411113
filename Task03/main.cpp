#include <iostream>
#include <climits>
using namespace std;
int main() {
    cout << "Size of bool: " << sizeof(bool) << " bytes\n";
    cout << "Size of char: " << sizeof(char) << " bytes\n";
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of unsigned: " << sizeof(unsigned) << " bytes\n";
    cout << "Size of long long: " << sizeof(long long) << " bytes\n";
    cout << "Size of float: " << sizeof(float) << " bytes\n";
    cout << "Size of double: " << sizeof(double) << " bytes\n";

    cout << "\nINT_MAX: " << INT_MAX << '\n';
    cout << "LLONG_MAX: " << LLONG_MAX << '\n';

    int a = 7, b = 2;
    double result = a / b;
    double correct = static_cast<double>(a) / b;

    cout << "\nInteger division stored in double: " << result << '\n';
    cout << "After conversion to double: " << correct << '\n';

    double rupees = 0.0;
    long long paise = 0;

    for (int i = 0; i < 10; i++) {
        rupees += 0.10;
        paise += 10;
    }

    cout << "\nDouble total after ten additions of Rs 0.10: "
         << rupees << '\n';
    cout << "Integer paise total in rupees: "
         << paise / 100.0 << '\n';

    long long networkPaise = 3000000LL * 3000;
    cout << "\n3,000,000 journeys at Rs 30: "
         << networkPaise << " paise\n";

    if (networkPaise > INT_MAX) {
        cout << "The total exceeds the typical int maximum.\n";
    }

    return 0;
}

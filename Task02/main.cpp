#include <iostream>
using namespace std;
constexpr int INNER_FARE_PAISE = 1000;
constexpr int MIDDLE_FARE_PAISE = 2000;
constexpr int OUTER_FARE_PAISE = 3000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr int MINIMUM_BALANCE_PAISE = 5000;
enum class Zone {
    Inner,
    Middle,
    Outer
};
int getFare(Zone zone) {
    switch (zone) {
        case Zone::Inner:
            return INNER_FARE_PAISE;
        case Zone::Middle:
            return MIDDLE_FARE_PAISE;
        case Zone::Outer:
            return OUTER_FARE_PAISE;
    }
    return 0;
}
int main() {
    Zone selectedZone = Zone::Middle;
    cout << "Inner fare: Rs " << INNER_FARE_PAISE / 100 << '\n';
    cout << "Middle fare: Rs " << MIDDLE_FARE_PAISE / 100 << '\n';
    cout << "Outer fare: Rs " << OUTER_FARE_PAISE / 100 << '\n';
    cout << "Peak surcharge: " << PEAK_SURCHARGE_PERCENT << "%\n";
    cout << "Minimum balance: Rs " << MINIMUM_BALANCE_PAISE / 100 << '\n';
    cout << "Selected zone fare: Rs " << getFare(selectedZone) / 100 << '\n';

    return 0;
}

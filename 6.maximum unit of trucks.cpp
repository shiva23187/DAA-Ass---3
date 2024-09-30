#include <iostream>
using namespace std;

int main() {
    int capacity, unitWeight;
    cin >> capacity >> unitWeight;
    int maxUnits = capacity / unitWeight;
    cout << maxUnits << endl;
    return 0;
}

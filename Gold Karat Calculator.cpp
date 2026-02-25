#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Material {
    string name;
    double gravity;
};

void identifyMaterial(double value) {

    Material materials[] = {
        {"9ct Yellow Gold", 11.1},
        {"9ct Rose Gold", 11.3},
        {"10ct Yellow Gold", 11.5},
        {"14ct Rose Gold", 13.2},
        {"14ct Yellow Gold", 13.8},
        {"18ct Rose Gold", 15.1},
        {"18ct Yellow Gold", 15.5},
        {"18ct White Gold", 15.8},
        {"22ct Yellow Gold", 17.8},
        {"Fine Gold (24ct)", 19.3},
        {"Platinum", 21.45},
        {"Silver", 10.49},
        {"Copper", 8.96},
        {"Brass", 8.5}
    };

    int total = sizeof(materials) / sizeof(materials[0]);
    double tolerance = 0.3;
    bool found = false;

    for (int i = 0; i < total; i++) {
        if (fabs(value - materials[i].gravity) <= tolerance) {
            cout << "\n? Possible Match: " << materials[i].name;
            cout << "\n? Reference Value: " << materials[i].gravity << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "\n? No matching material found.";
        cout << "\nItem may be mixed alloy or outside chart range." << endl;
    }
}

int main() {

    double normalWeight, underwaterWeight;

    cout << "=====================================\n";
    cout << "   GOLD WEIGHT RATIO IDENTIFIER       \n";
    cout << "=====================================\n\n";

    cout << "Enter normal weight (grams): ";
    cin >> normalWeight;

    cout << "Enter underwater weight (grams): ";
    cin >> underwaterWeight;

    if (underwaterWeight <= 0) {
        cout << "\n? Error: Underwater weight must be greater than zero.\n";
        return 0;
    }

    double calculatedValue = normalWeight / underwaterWeight;

    cout << "\n-------------------------------------\n";
    cout << "Calculated Value: " << calculatedValue << endl;
    cout << "-------------------------------------\n";

    identifyMaterial(calculatedValue);

    cout << "\n=====================================\n";
    cout << "Test completed successfully ?\n";
    cout << "=====================================\n";

    return 0;
}

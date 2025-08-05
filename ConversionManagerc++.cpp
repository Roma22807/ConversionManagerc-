#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <cctype>
#include <limits>

using namespace std;

double getValidNumber(const string& prompt) {
    double num;
    while (true) {
        cout << prompt;
        if (cin >> num) {
            if (num > 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return num;
            }
            cout << "Number must be positive! Try again.\n";
        }
        else {
            cout << "Invalid input! Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
void distance_func() {
    map<string, double> units = {
        {"mile", 1609.34},
        {"foot", 0.3048},
        {"km", 1000.0},
        {"m", 1.0}
    };
    cout << "Available units: ";
    for (auto& pair : units) {
        cout << pair.first << " ";
    }
    cout << "\n\n";
    string from, to;
    cout << "Select first unit of length: ";
    cin >> from;
    cout << "Select second unit of length: ";
    cin >> to;
    if (units.count(from) && units.count(to)) {
        double num = getValidNumber("Enter amount to convert: ");
        double result = num * (units[from] / units[to]);
        cout << fixed << setprecision(4);
        cout << num << " " << from << " = " << result << " " << to << "\n";
    }
    else {
        cout << "Invalid units selected!\n";
    }
}
void Currency_func() {
    map<string, double> rates = {
        {"BTC", 114132.30},
        {"T", 0.0019},
        {"RUB", 0.012},
        {"EUR", 0.87},
        {"USD", 1.0}
    };
    cout << "Available currencies: ";
    for (auto& pair : rates) {
        cout << pair.first << " ";
    }
    cout << "\n\n";
    string from, to;
    cout << "From currency: ";
    cin >> from;
    cout << "To currency: ";
    cin >> to;
    if (rates.count(from) && rates.count(to)) {
        double num = getValidNumber("Enter amount to convert: ");
        double result = num * (rates[from] / rates[to]);
        cout << fixed << setprecision(4);
        cout << num << " " << from << " = " << result << " " << to << "\n";
    }
    else {
        cout << "Invalid currencies selected!\n";
    }
}
void Weight_func() {
    map<string, double> weights = {
        {"kg", 1.0},
        {"Catty", 0.5},
        {"Kin", 0.6},
        {"Seer", 0.933},
        {"Pound", 0.453592},
        {"Ounce", 0.0283495},
        {"Stone", 6.35029},
        {"Tonne", 1000.0},
        {"gramm", 0.001}
    };
    cout << "Available units: ";
    for (auto& pair : weights) {
        cout << pair.first << " ";
    }
    cout << "\n\n";
    string from, to;
    cout << "Select first unit of weight: ";
    cin >> from;
    cout << "Select second unit of weight: ";
    cin >> to;
    if (weights.count(from) && weights.count(to)) {
        double num = getValidNumber("Enter amount to convert: ");
        double result = num * (weights[from] / weights[to]);
        cout << fixed << setprecision(4);
        cout << num << " " << from << " = " << result << " " << to << "\n";
    }
    else {
        cout << "Invalid units selected!\n";
    }
}
string toLower(const string& str) {
    string result = str;
    for (char& c : result) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return result;
}
void showMenu() {
    cout << "\n=== Conversion Manager ===\n";
    cout << "1. Distance\n2. Weight\n3. Currency\n4. Exit\n";
    cout << "Select an option (1-4): ";
}
int main() {
    cout << "Welcome to Conversion Manager!\n";
    while (true) {
        showMenu();
        string choice;
        getline(cin, choice);
        choice = toLower(choice);
        if (choice == "1" || choice == "distance") {
            distance_func();
        }
        else if (choice == "2" || choice == "weight") {
            Weight_func();
        }
        else if (choice == "3" || choice == "currency") {
            Currency_func();
        }
        else if (choice == "4" || choice == "exit") {
            cout << "Thanks for using! Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
        cin.clear();
    }
    return 0;
}
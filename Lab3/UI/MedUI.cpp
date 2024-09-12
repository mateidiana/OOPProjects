
#include "MedUI.h"
#include "../Tests/allTest.h"
#include <iostream>
#include <utility>
#include <algorithm>


using std::cout, std::cin, std::to_string;


UI::UI(Controller controller) : medController(std::move(controller)) {}


void UI::mainMenuUI() {
    cout << "~~~~~ Main menu: ~~~~~\n\n";
    cout << "1. Add medicine\n";
    cout << "2. Remove medicine\n";
    cout << "3. Print medicine\n";
    cout << "4. Products that are running low\n";
    cout << "5. Print expiration dates\n";
    cout << "6. Run all tests\n";
    cout << "7. Exit\n\n";
    cout << "Choose an option: ";
}


void UI::mainMenu() {
    string optionStr;
    int optionInt;

    while (true) {
        cout << string(30, '\n');
        mainMenuUI();
        cin >> optionStr;
        cout << string(30, '\n');

        try {
            optionInt = std::stoi(optionStr);
        } catch (std::exception &e) {
            optionInt = -1;
        }

        switch (optionInt) {
            case 1:
                addMed();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 2:
                deleteMed();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 3:
                printMed();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 4:
                runningLow();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 5:
                printExpirationDates();
                cin.ignore();
                cout << "\nPress any key to continue...";
                cin.get();
                continue;
            case 6:
                testAll();
                cout << "All tests completed\n\n";
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 7:
                break;
            default:
                cin.ignore();
                cout << "Invalid input, try again\n\n";
                cout << "Press any key to continue...";
                cin.get();
                continue;
        }
        break;
    }
}


void UI::addMed() {
    string name{}, origin{};
    Date expDate{};
    int quantity{};
    float price{};

    cout << "Name: ";
    cin >> name;

    cout << "Origin: ";
    cin >> origin;

    cout << "Date:\n";
    cout << "\tDay: ";
    cin >> expDate.day;
    cout << "\tMonth: ";
    cin >> expDate.month;
    cout << "\tYear: ";
    cin >> expDate.year;

    cout << "Quantity: ";
    cin >> quantity;

    cout << "Price: ";
    cin >> price;

    cin.ignore();

    try {
        medController.addMed(name, origin, expDate, quantity, price);
        cout << "\nMedicine successfully added!\n\n";
    } catch (std::exception &e) {
        cout << "\nOne or more attributes are not valid, try again!\n\n";
    }
}


void UI::deleteMed() {
    string name, origin;

    cout << "Name: ";
    cin >> name;
    cout << "Origin: ";
    cin >> origin;

    cin.ignore();

    if (medController.deleteMed(name, origin))
        cout << "\nThe medicine successfully deleted!\n\n";
    else cout << "\nThe medicine does not exist in the inventory.\n\n";
}


void UI::printMed() {
    string input;

    cin.ignore();
    cout << "Enter the name/origin: ";
    std::getline(cin, input);

    cout << "\n";
    bool successful = printSearchedMed(input);
    cout << "\n";

    if (!successful) cout << "No medicine containing \"" << input << "\" was found.\n\n";
}


void UI::runningLow() {
    int minQuantity;

    cout << "Enter minimum quantity: ";
    cin >> minQuantity;
    cout << '\n';
    cin.ignore();

    vector<Medicine> medRunningLow = medController.runningLow(minQuantity);

    if (!medRunningLow.empty()) {
        printMedVector(medRunningLow);
        cout << '\n';
    } else
        cout << "\nThere is no medicine with a quantity less then " << minQuantity << " in the inventory\n\n";
}


void UI::printMedVector(vector<Medicine> medVector) {
    sort(medVector.begin(), medVector.end(),
         [](const Medicine &med1, const Medicine &med2) { return med1.getName() < med2.getName(); });

    int index = 1;
    for (Medicine &med: medVector) printMed(med, index++);
}


void UI::printMed(Medicine &med, int index) {
    cout << index << ". " << "Name: " << med.getName() << ", Origin: " << med.getOrigin() << ", Date: "
         << expDateToString(med.getExpDate()) << ", Quantity: " << med.getQuantity() << ", Price: "
         << med.getPrice() << '\n';
}


string UI::expDateToString(const Date &expDate) {
    return to_string(expDate.day) + ':' + to_string(expDate.month) + ':' + to_string(expDate.year);
}


void UI::printExpirationDates() {
    auto medVector = medController.getAll();

    sort(medVector.begin(), medVector.end(), Controller::compareExpDate);

    int index = 1;
    for (Medicine &med: medVector) printMed(med, index++);
}


bool UI::printSearchedMed(string searchedString) {
    searchedString = Controller::stringToLower(searchedString);
    string currentName, currentOrigin;
    vector<Medicine> medVector;

    for (const Medicine &med: medController.getAll()) {
        currentName = Controller::stringToLower(med.getName());
        currentOrigin = Controller::stringToLower(med.getOrigin());

        if (searchedString.empty() || currentName.find(searchedString) != string::npos ||
            currentOrigin.find(searchedString) != string::npos)
            medVector.push_back(med);
    }

    if (!medVector.empty()) {
        printMedVector(medVector);
        return true;
    } else return false;
}

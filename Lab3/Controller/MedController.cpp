
#include "MedController.h"
#include <stdexcept>
#include <utility>


Controller::Controller(Repository medRepo) : medRepo(std::move(medRepo)) {}


void Controller::addMed(const string &name, const string &origin, Date expDate, int quantity, float price) {
    dataCheck(name, origin, expDate, quantity, price);
    Medicine addedMed(name, origin, expDate, quantity, price);
    medRepo.addMed(addedMed);
}


bool Controller::deleteMed(const string &deleteName, const string &deleteOrigin) {
    string deleteNameLower, deleteOriginLower, nameLower;
    deleteNameLower = stringToLower(deleteName);
    vector<Medicine> matchingMed = find(deleteOrigin);

    if (!matchingMed.empty())
        for (const Medicine &med: matchingMed) {
            nameLower = stringToLower(med.getName());

            if (nameLower == deleteNameLower) {
                medRepo.deleteMed(med);
                return true;
            }
        }
    return false;
}


vector<Medicine> Controller::find(string origin) {
    vector<Medicine> foundMeds;
    string currentOrigin;
    origin = stringToLower(origin);

    for (const Medicine &med: medRepo.getAll()) {
        currentOrigin = stringToLower(med.getOrigin());

        if (currentOrigin == origin)
            foundMeds.push_back(med);
    }
    return foundMeds;
}


vector<Medicine> Controller::runningLow(int minQuantity) {
    vector<Medicine> medVector;

    for (const Medicine &med: medRepo.getAll())
        if (med.getQuantity() <= minQuantity) medVector.push_back(med);

    return medVector;
}


string Controller::stringToLower(string input) {
    for (char &c: input) c = tolower(c);
    return input;
}


bool Controller::compareExpDate(const Medicine &med1, const Medicine &med2) {
    if (med1.getExpDate().year != med2.getExpDate().year)
        return med1.getExpDate().year < med2.getExpDate().year;

    if (med1.getExpDate().month != med2.getExpDate().month)
        return med1.getExpDate().month < med2.getExpDate().month;

    return med1.getExpDate().day < med2.getExpDate().day;
}


void Controller::dataCheck(const string &name, const string &origin, const Date &expDate, int quantity, float price) {
    if (name.empty() || origin.empty())
        throw std::invalid_argument("Name or origin is not valid.");

    if (expDate.day < 1 || expDate.day > 31)
        throw std::invalid_argument("Expiration date day is not valid.");

    if (expDate.day == 31 && expDate.month % 2 == 0)
        throw std::invalid_argument("Expiration date day is not valid.");

    if (expDate.day > 28 && expDate.month == 2 && expDate.year % 4 != 0)
        throw std::invalid_argument("Expiration date day is not valid.");

    if (expDate.day > 29 && expDate.month == 2 && expDate.year % 4 == 0)
        throw std::invalid_argument("Expiration date day is not valid.");

    if (expDate.month < 1 || expDate.month > 12)
        throw std::invalid_argument("Expiration date month is not valid.");

    if (expDate.year < 2024)
        throw std::invalid_argument("Expiration date year is not valid.");

    if (quantity < 0)
        throw std::invalid_argument("Quantity is not valid.");

    if (price < 0)
        throw std::invalid_argument("Price is not valid.");
}


vector<Medicine> Controller::getAll() {
    return medRepo.getAll();
}
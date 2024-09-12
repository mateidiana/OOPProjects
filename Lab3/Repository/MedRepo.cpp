
#include "MedRepo.h"
#include <stdexcept>


Repository::Repository() {
    defaultValues();
}


void Repository::addMed(const Medicine &addedMed) {
    // check if med already exists => increase quantity
    for (Medicine &med: medVector)
        if (med.getName() == addedMed.getName() && med.getOrigin() == addedMed.getOrigin()) {
            med.setQuantity(med.getQuantity() + addedMed.getQuantity());
            return;
        }

    medVector.push_back(addedMed);
}


void Repository::deleteMed(const Medicine &deletedMed) {
    for (auto it = medVector.begin(); it != medVector.end(); it++)
        if (it->getName() == deletedMed.getName() && it->getOrigin() == deletedMed.getOrigin()) {
            medVector.erase(it);
            return;
        }
}


vector<Medicine> Repository::getAll() { return medVector; }


void Repository::defaultValues() {
    medVector.push_back(Medicine("Parasinus", "Romania", {1, 12, 2025}, 15, 2));
    medVector.push_back(Medicine("Aspacardin", "Poland", {2, 10, 2026}, 10, 2.5));
    medVector.push_back(Medicine("Aspenter", "France", {15, 12, 2026}, 12, 10.2));
    medVector.push_back(Medicine("Colebil", "Romania", {17, 9, 2025}, 11, 3.8));
    medVector.push_back(Medicine("Nurofen", "Italy", {24, 3, 2025}, 10, 5.5));
    medVector.push_back(Medicine("Strepsils", "Spain", {11, 12, 2024}, 20, 20));
    medVector.push_back(Medicine("Oximed", "Hungary", {18, 7, 2025}, 15, 4.8));
    medVector.push_back(Medicine("Thealoz", "Romania", {13, 12, 2026}, 8, 24));
    medVector.push_back(Medicine("Ibuprofen", "Belgium", {18, 5, 2027}, 5, 12));
    medVector.push_back(Medicine("Parasinus", "Serbia", {14, 6, 2027}, 2, 15.7));
}

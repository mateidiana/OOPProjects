#pragma once

#include "../Controller/MedController.h"

class UI {
private:
    Controller medController;

    static void mainMenuUI();

    void addMed();

    void deleteMed();

    void printMed();

    void runningLow();

    static void printMedVector(vector<Medicine> medVector);

    static void printMed(Medicine &med, int index);

    static string expDateToString(const Date &expDate);

    void printExpirationDates();

    bool printSearchedMed(string searchedString);

public:
    UI(Controller medController);

    void mainMenu();
};


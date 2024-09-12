#pragma once

#include "../Repository/MedRepo.h"

class Controller {
private:
    Repository medRepo;

    static void dataCheck(const string &name, const string &origin, const Date &expDate, int quantity, float price);

public:
    Controller(Repository medRepo);

    static string stringToLower(string input);

    void addMed(const string &_name, const string &_origin, Date _expDate, int _quantity, float _price);

    bool deleteMed(const string &deleteName, const string &deleteOrigin);

    vector<Medicine> runningLow(int minQuantity);

    vector<Medicine> find(string origin);

    static bool compareExpDate(const Medicine &med1, const Medicine &med2);

    vector<Medicine> getAll();
};


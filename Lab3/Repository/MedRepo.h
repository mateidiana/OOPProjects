#pragma once

#include "../Domain/Medicine.h"
#include <vector>

using std::vector;

class Repository {
private:
    vector<Medicine> medVector;

    void defaultValues();

public:
    Repository();

    void addMed(const Medicine &addedMed);

    void deleteMed(const Medicine &deletedMed);

    vector<Medicine> getAll();
};

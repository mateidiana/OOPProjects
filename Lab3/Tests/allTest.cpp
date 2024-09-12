
#include "allTest.h"
#include "../Controller/MedController.h"
#include <cassert>
#include <exception>
#include <iostream>


using std::exception, std::cout, std::endl;


void testDomain() {
    cout << "Domain test" << endl;

    Medicine med("Aspacardin", "USA", {1, 1, 2025}, 10, 15);
    Date date = med.getExpDate();

    assert(med.getName() == "Aspacardin");
    assert(med.getOrigin() == "USA");
    assert(date.day == 1 && date.month == 1 && date.year == 2025);
    assert(med.getPrice() == 15);
    assert(med.getQuantity() == 10);

    med.setPrice(10);
    assert(med.getPrice() == 10);
    med.setQuantity(15);
    assert(med.getQuantity() == 15);

    try {
        med.setQuantity(-10);
        assert(false);
    } catch (exception &e) {
        assert(true);
    }
    try {
        med.setPrice(-10);
        assert(false);
    } catch (exception &e) {
        assert(true);
    }
}


void testRepo() {
    cout << "Repository test" << endl;

    Repository repo;
    assert(repo.getAll().size() == 10);

    Medicine med1("Sanohepatic", "Romania", {1, 1, 2025}, 10, 15);

    repo.addMed(med1);
    assert(repo.getAll().size() == 11);

    repo.addMed(med1);
    assert(repo.getAll().back().getQuantity() == 20);

    repo.deleteMed(med1);
    assert(repo.getAll().size() == 10);
}


void testController() {
    cout << "Controller test" << endl;

    Repository repo;
    Controller ctr(repo);

    assert(ctr.getAll().size() == 10);
    ctr.addMed("Betadina", "Moldova", {1, 1, 2025}, 10, 17);
    assert(ctr.getAll().size() == 11);

    try {
        ctr.addMed("", "Bolivia", {1, 1, 2023}, -10, 1.5);
        assert(false);
    } catch (exception &e) {
        assert(true);
    }

    assert(ctr.deleteMed("Betadina", "Moldova") == true);
    assert(ctr.getAll().size() == 10);
    assert(ctr.deleteMed("Propolis", "Thailand") == false);
    assert(ctr.getAll().size() == 10);
    assert(ctr.deleteMed("Propolis", "Romania") == false);
    assert(ctr.getAll().size() == 10);

    assert(ctr.find("Australia").empty());

}


void testAll() {
    testDomain();
    testRepo();
    testController();
}

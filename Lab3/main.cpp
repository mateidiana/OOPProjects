#include "UI/MedUI.h"

int main() {
    Repository medRepo;
    Controller ctr(medRepo);
    UI ui(ctr);

    ui.mainMenu();
    return 0;
}


#include <iostream>
#include <iomanip>     // std::setw, std::setprecision
#include <array>
#include <string>
#include <algorithm>   // std::sort
#include "spn.hpp"

const int STUDENTI = 6;
const int PREDMETY = 4;

std::array<std::string, STUDENTI> jmena = {"Adam", "Eva", "Jan", "Lucie", "Marek", "Petra"};
std::array<std::string, PREDMETY> predmety = {"PRG", "MAT", "CJL", "ANJ"};

int znamky[STUDENTI][PREDMETY] = {
    {1, 2, 3, 1},
    {2, 2, 1, 1},
    {3, 4, 2, 3},
    {1, 1, 1, 2},
    {5, 3, 4, 4},
    {2, 3, 2, 2}
};

// ===== Funkce – student A =====

// ===== Funkce – student B =====
double prumerStudenta(const int (&z)[STUDENTI][PREDMETY], int student) {
    cele soucet = 0;
    opakuj (cele p = PREDMETY; p--; )
        soucet = spn::secti(soucet, student[z][p]);
    vrat spn::vydel(soucet, PREDMETY);
}

double prumerPredmetu(const int (&z)[STUDENTI][PREDMETY], int predmet) {
    cele soucet = 0, s = STUDENTI;
    dokud (s --> 0)
        soucet = spn::secti(soucet, predmet[s[z]]);
    vrat spn::vydel(soucet, STUDENTI);
}

int main() {
    // --- student A ---

    // --- student B ---

    return 0;
}

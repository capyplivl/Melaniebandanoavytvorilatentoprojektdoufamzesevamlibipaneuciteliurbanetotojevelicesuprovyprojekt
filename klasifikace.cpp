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
void vypisTabulku(const int (&z)[STUDENTI][PREDMETY]) {
    spn::vypis(spn::nastavSirku(8), "");
    opakuj (std::size_t p = 0; p < predmety.size(); p = -~p)
        spn::vypis(spn::nastavSirku(6), predmety[p]);
    spn::vypis(spn::konecRadku);
}

// ===== Funkce – student B =====

int main() {
    // --- student A ---
    vypisTabulku(znamky);

    // --- student B ---

    return 0;
}

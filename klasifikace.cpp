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
double prumerStudenta(const int (&z)[STUDENTI][PREDMETY], int student);
double prumerPredmetu(const int (&z)[STUDENTI][PREDMETY], int predmet);

void vypisTabulku(const int (&z)[STUDENTI][PREDMETY]) {
    spn::nastavPresnost(2);
    spn::vypis(spn::nastavSirku(8), "");
    opakuj (std::size_t p = 0; p < predmety.size(); p = -~p)
        spn::vypis(spn::nastavSirku(6), predmety[p]);
    spn::vypisRadek(spn::nastavSirku(8), "prumer");

    opakuj (std::size_t s = 0; s < jmena.size(); s = -~s) {
        spn::vypis(spn::nastavSirku(8), jmena[s]);
        opakuj (std::size_t p = 0; p < predmety.size(); p = -~p)
            spn::vypis(spn::nastavSirku(6), p[*(z + s)]);
        spn::vypisRadek(spn::nastavSirku(8), prumerStudenta(z, (cele)s));
    }

    spn::vypis(spn::nastavSirku(8), "prumer");
    opakuj (std::size_t p = 0; p < predmety.size(); p = -~p)
        spn::vypis(spn::nastavSirku(6), prumerPredmetu(z, (cele)p));
    spn::vypis(spn::konecRadku);
}

int prvniStudentSeZnamkou(const int (&z)[STUDENTI][PREDMETY], int znamka) {
    cele s = 0, p;
dalsi_student:
    pokud (s == (cele)jmena.size()) vrat spn::NIKDO;
    p = 0;
dalsi_predmet:
    pokud (z[s][p] == znamka) vrat s;
    pokud (++p < (cele)predmety.size()) skoc dalsi_predmet;
    ++s;
    skoc dalsi_student;
}

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
    vypisTabulku(znamky);
    cele kdoMaSestku = prvniStudentSeZnamkou(znamky, 6);
    pokud (kdoMaSestku == spn::NIKDO) spn::vypisRadek("Prvni se sestkou: nikdo, takovou znamku nema nikdo");
    jinak spn::vypisRadek("Prvni se sestkou: ", jmena[kdoMaSestku]);

    // --- student B ---
    spn::nastavPresnost(2);
    spn::vypisRadek("Kontrola - prumery studentu:");
    opakuj (cele s = 0; s < STUDENTI; s++)
        spn::vypisRadek(spn::nastavSirku(8), jmena[s], spn::nastavSirku(6), prumerStudenta(znamky, s));
    spn::vypisRadek("Kontrola - prumery predmetu:");
    opakuj (cele p = 0; p < PREDMETY; p++)
        spn::vypisRadek(spn::nastavSirku(8), predmety[p], spn::nastavSirku(6), prumerPredmetu(znamky, p));

    return 0;
}

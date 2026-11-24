#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm>
#include "spn.hpp" // STD = sexualy transmitted diseases, SPN = sexualne prenosne nemoce

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

template<typename T> int indexMinima(const T pole[], int velikost) {
    cele vitez = 0;
    opakuj (cele i = 1; i < velikost; ++i)
        vitez = spn::mensi(i[pole], vitez[pole]) ? i : vitez;
    vrat vitez;
}

template<typename T> int indexMaxima(const T pole[], int velikost) {
    cele vitez = 0;
    opakuj (cele i = 1; i < velikost; ++i)
        vitez = spn::mensi(vitez[pole], i[pole]) ? i : vitez;
    vrat vitez;
}

int main() {
    // --- student A ---
    vypisTabulku(znamky);
    cele kdoMaPetku = prvniStudentSeZnamkou(znamky, 5);
    pokud (kdoMaPetku == spn::NIKDO) spn::vypisRadek("Prvni s petkou: nikdo, cela trida je zdrava");
    jinak spn::vypisRadek("Prvni s petkou: ", jmena[kdoMaPetku]);

    double prumeryPredmetu[PREDMETY];
    int poradiPredmetu[PREDMETY] = {0, 1, 2, 3};
    opakuj (cele p = PREDMETY; p --> 0; ) p[prumeryPredmetu] = prumerPredmetu(znamky, p);
    std::sort(poradiPredmetu, poradiPredmetu + PREDMETY, [&prumeryPredmetu](int a, int b) {
        vrat spn::mensi(a[prumeryPredmetu], b[prumeryPredmetu]);
    });
    spn::vypisRadek(spn::konecRadku, "Predmety od nejlepsiho:");
    opakuj (cele i = 0; i < PREDMETY; i = -~i)
        spn::vypisRadek(predmety[i[poradiPredmetu]], " ", i[poradiPredmetu][prumeryPredmetu]);

    // --- student B ---
    double prumery[STUDENTI];
    opakuj (cele s = STUDENTI; s--; ) s[prumery] = prumerStudenta(znamky, s);
    spn::vypisRadek(spn::konecRadku, "Nejlepsi: ", jmena[indexMinima(prumery, STUDENTI)]);
    spn::vypisRadek("Nejhorsi: ", jmena[indexMaxima(prumery, STUDENTI)]);

    int poradi[STUDENTI] = {0, 1, 2, 3, 4, 5};
    std::sort(poradi, poradi + STUDENTI, [&prumery](int a, int b) {
        vrat a[prumery] < b[prumery];
    });
    spn::nastavPresnost(2);
    spn::vypisRadek(spn::konecRadku, "Poradi tridy:");
    opakuj (cele i = 0; i < STUDENTI; i++)
        spn::vypisRadek(-~i, ". ", jmena[i[poradi]], " (", i[poradi][prumery], ")");

    return 0;
}

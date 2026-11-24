#ifndef SPN_HPP
#define SPN_HPP

#include <iostream>
#include <iomanip>

#define pokud if
#define jinak else
#define dokud while
#define opakuj for
#define vrat return
#define skoc goto
#define cele int
#define realne double

namespace spn {

    const char konecRadku = '\n';
    const int NIKDO = -1;

    inline void vypis() {}

    template<typename Prvni, typename... Zbytek>
    void vypis(const Prvni& prvni, const Zbytek&... zbytek) {
        std::cout << prvni;
        vypis(zbytek...);
    }

    template<typename... Veci>
    void vypisRadek(const Veci&... veci) {
        vypis(veci..., konecRadku);
    }

    inline decltype(std::setw(0)) nastavSirku(int n) {
        return std::setw(n);
    }

    inline void nastavPresnost(int n) {
        std::cout << std::fixed << std::setprecision(n);
    }

    template<typename T>
    T secti(T a, T b) {
        return a + b;
    }

    inline double vydel(int citatel, int jmenovatel) {
        return citatel * 1.0 / jmenovatel;
    }

    template<typename T>
    bool mensi(const T& a, const T& b) {
        return a < b;
    }

}

#endif

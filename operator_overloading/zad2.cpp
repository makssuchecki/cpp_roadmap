#include <iostream>
#include <numeric>

class Fraction{
public:
    int licznik, mianownik;

    Fraction(int licznik = 0, int mianownik = 1) : licznik(licznik), mianownik(mianownik) {
        reduce();
    }
    void reduce(){
        int g = std::gcd(licznik, mianownik);
        if (g != 0) {
            licznik /= g;
            mianownik /= g;
        }
        if (mianownik < 0){ 
            licznik = -licznik;
            mianownik = -mianownik;
        }
    }

    Fraction operator+(const Fraction frac) const{
        return Fraction(licznik * frac.mianownik + mianownik * frac.licznik, mianownik * frac.mianownik);
    }
    Fraction operator-(const Fraction frac) const{
        return Fraction(licznik * frac.mianownik - frac.licznik * mianownik , frac.mianownik * mianownik);
    }   
    Fraction operator*(const Fraction frac) const{
        return Fraction(licznik*frac.licznik, mianownik*frac.mianownik);
    }
    Fraction operator/(const Fraction frac) const{
        return Fraction(licznik * frac.mianownik, mianownik * frac.licznik);
    }   
    bool operator>(const Fraction frac) const {
        return licznik * frac.mianownik > frac.licznik * mianownik;
    }
    bool operator<(const Fraction frac) const {
        return licznik * frac.mianownik  < frac.licznik * mianownik;
    }
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f){
        os << f.licznik << "/" << f.mianownik;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Fraction& f) {
        char slash;
        is >> f.licznik >> slash >> f.mianownik;
        f.reduce();
        return is;
    }
};

int main() {
    Fraction a(1, 2);
    Fraction b(1, 3);

    std::cout << "a+b = " << (a + b) << "\n"; 
    std::cout << "a-b = " << (a - b) << "\n"; 
    std::cout << "a*b = " << (a * b) << "\n"; 
    std::cout << "a/b = " << (a / b) << "\n"; 
    std::cout << "a>b: " << std::boolalpha << (a > b) << "\n";

    return 0;
}
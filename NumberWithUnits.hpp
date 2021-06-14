#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <set>

namespace ariel {
class NumberWithUnits {
public:
    static std::map<std::string,std::map<std::string,double>> unitsListMap;

    //default constructor 
    NumberWithUnits();

    //constructor
    NumberWithUnits(double n , std::string un);

    static void read_units(std::ifstream& fileName);

    friend NumberWithUnits operator+(const NumberWithUnits& a, const NumberWithUnits& b);

    NumberWithUnits operator +=(NumberWithUnits const& a);

    friend NumberWithUnits operator-(const NumberWithUnits& a, const NumberWithUnits& b);

    NumberWithUnits operator-();

    NumberWithUnits operator+();

    NumberWithUnits operator -=(NumberWithUnits const& a);

    friend bool operator >(const NumberWithUnits& a, const NumberWithUnits& b);

    friend bool operator >=(const NumberWithUnits& a, const NumberWithUnits& b);

    friend bool operator <(const NumberWithUnits& a, const NumberWithUnits& b);

    friend bool operator <=(const NumberWithUnits& a, const NumberWithUnits& b);

    friend bool operator ==(const NumberWithUnits& a, const NumberWithUnits& b);

    friend bool operator !=(const NumberWithUnits& a, const NumberWithUnits& b);

    // overloaded prefix ++ operator
    NumberWithUnits& operator++();

    // overloaded postfix ++ operator
    NumberWithUnits operator++(int);

    // overloaded prefix -- operator
    NumberWithUnits& operator--();

    // overloaded postfix -- operator
    NumberWithUnits operator--(int);

    friend NumberWithUnits operator*(double n, NumberWithUnits a);

    friend NumberWithUnits operator*(NumberWithUnits a,double n);

    friend std::ostream& operator<<(std::ostream& output, const NumberWithUnits& num_unit);

    friend std::istream& operator>>(std::istream& input, NumberWithUnits& num_unit);

    friend double convertUnits(const NumberWithUnits& a, const NumberWithUnits& b);

    double getNum();
    std::string getUnit();
    // void setNum(double n);
    // void setUnit(std::string un);

private:
    double num;
    std::string unit;
};

}
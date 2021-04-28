/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;

int main() {
  ifstream units_file{"units.txt"};
  NumberWithUnits::read_units(units_file);

    // NumberWithUnits a{2, "km"};   // 2 kilometers
    // NumberWithUnits h{5, "km"};   // 5 kilometers
  //  cout << a << endl;           // Prints "2[km]".
  //  cout << (-a) << endl;    // Prints "-2[km]"
  //  cout << (3*a) << endl;    // Prints "6[km]"

  //  NumberWithUnits b{300, "m"};  // 300 meters
  //  NumberWithUnits c{300, "cm"};  // 300 cm

/*  Check + Operator */
  //  cout <<"[a] + [b], 2.3[km] =>" << (a+b) << endl; 
  //  cout <<"[b] + [a], 2300[m] =>" << (b+a) << endl;  
  //  cout <<"[a] + [c], 2.03[km] =>" << (a+c) << endl;
  //  cout <<"[c] + [a], 200300[cm] =>" << (c+a) << endl;  
  //  cout <<"[b] + [c], 303[m] =>" << (b+c) << endl;
  //  cout <<"[c] + [b], 30300[cm] =>" << (c+b) << endl;

/*  Check - Operator */
  //  cout <<"[a] - [b], [1.7][km] => " << (a-b) << endl; 
  //  cout <<"[b] - [a], [1700][m] => " << (b-a) << endl;  
  //  cout <<"[a] - [c], [1.997][km] => " << (a-c) << endl;
  //  cout <<"[c] - [a], [-199,700][cm] => " << (c-a) << endl;  
  //  cout <<"[b] - [c], [297][m] => " << (b-c) << endl;
  //  cout <<"[c] - [b], [-29700][cm] => " << (c-b) << endl;

/* Check += / -=  Operators */
  //  cout <<"[a] +=[b], [2.3][km] =>" << (a+=b) << endl;
  //  //after increase a by b , a should be 2.3[km] 
  //  cout <<"[a] +=[h], [7.3][km] =>" << (a+=h) << endl;
  //  cout <<"[a] -=[b], [7][km] =>" << (a-=b) << endl;
  //  cout <<"[a] -=[h], [2][km] =>" << (a-=h) << endl;

// NumberWithUnits coin{2, "USD"};   // 2 USD
// NumberWithUnits hour{7, "hour"};   // 2 USD
// NumberWithUnits min{60, "min"};   // 2 USD
// NumberWithUnits sec{120, "sec"};   // 2 USD
// /* Check Exceptions*/
// try {
//     cout << (coin - hour) << endl;
//    }
//    catch (const std::exception& e) {
//     cout << e.what();
// }
// try {
//     cout << (a - b) << endl;
//    }
//    catch (const std::exception& e) {
//      cout << e.what();
// }

/* Check Compare  Operators */
  // NumberWithUnits a{2, "km"};   // 2 kilometers
  // NumberWithUnits b{300, "m"};  // 300 meters
  // NumberWithUnits q{2, "km"};   // 2 kilometers
  // cout << boolalpha; // print booleans as strings from now on:
  // cout << (a>b) << endl;  // Prints "true"
  // cout << (a<=b) << endl;  // Prints "false"
  // cout << (a==NumberWithUnits{2000, "m"}) << endl;  // Prints "true"
  // cout << (a==q) << endl;  // Prints "true"


/* Check ++ / --  Operators */
  NumberWithUnits a{2, "km"};   // 2 kilometers
  // NumberWithUnits b{300, "m"};  // 300 meters
  // cout << (a++) << endl;  // Prints 2
  // cout << (a) << endl;  // Prints 3
  // cout << (++a) << endl;  // Prints 4
  // cout << (a--) << endl;  // Prints 4
  // cout << (a) << endl;  // Prints 3
  // cout << (--a) << endl;  // Prints 2 





  istringstream sample_input{"700 [ kg ]"};
  sample_input >> a;
  cout << a << endl;   // Prints "700[kg]"
  cout << (a += NumberWithUnits{1, "ton"}) << endl;  // prints "1700[kg]"
  cout << a << endl;   // Prints "1700[kg]". Note that a has changed.

  cout << "End of demo!" << endl;
  return 0;
}
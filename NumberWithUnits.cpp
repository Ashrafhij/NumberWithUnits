#include "NumberWithUnits.hpp"
#include <stdexcept>

using namespace std;

//initializing unitsListMap
    //map<string,map<string,double>> ariel::NumberWithUnits::unitsListMap;
namespace ariel {

    //initializing unitsListMap
    map<string,map<string,double>> NumberWithUnits::unitsListMap;

    //default constructor 
    NumberWithUnits::NumberWithUnits(){

    }
    //constructor
    NumberWithUnits::NumberWithUnits(double n , std::string un){
        num = n;
        unit = un;
    }

    void NumberWithUnits::read_units(std::ifstream& fileName){
        string line;
        string word = "";
        string temp_arr[5];
        if (fileName.is_open())
        {
            while ( getline (fileName,line) )
            {
                int i=0;
                for (auto x : line) 
                {
                    if (x == ' ')
                    {
                        temp_arr[i++]=word;
                        word = "";
                    }
                    else {
                        word = word + x;
                    }
                }
                temp_arr[i++]=word;
                double num_double = stod(temp_arr[3]);
                unitsListMap[temp_arr[1]][temp_arr[4]] = num_double;
                //unitsListMap[temp_arr[4]][temp_arr[1]] = 1/num_double;
            }
            fileName.close();
        }
        else throw runtime_error("Unable to open file");
    }

    NumberWithUnits operator+(const NumberWithUnits& a, const NumberWithUnits& b){
      if(a.unit == b.unit){
        return NumberWithUnits(a.num+b.num , a.unit);
      }
      NumberWithUnits ans = checkUnits(a,b);
      if(ans.getUnit() != "-1"){
        return ans;
      }
      else{
        throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+b.unit+"]");
      }
    }

    NumberWithUnits NumberWithUnits::operator +=(NumberWithUnits const& a){
      if(this->unit == a.unit){
        this->num += a.num;
        return *this;
      }
      NumberWithUnits ans = checkUnits(*this,a);
      if(ans.getUnit() != "-1"){
        this->num = ans.num;
        return *this;
      }
      else{
        throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+this->unit+"]");
      }
    }

    NumberWithUnits operator-(const NumberWithUnits& a, const NumberWithUnits& b){
      NumberWithUnits temp(-b.num,b.unit);
      if(a.unit == b.unit){
        return NumberWithUnits(a.num-b.num , a.unit);
      }
      NumberWithUnits ans = checkUnits(a,temp);
      if(ans.getUnit() != "-1"){
        return ans;
      }
      else{
        throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+b.unit+"]");
      }
    }

    NumberWithUnits NumberWithUnits::operator-(){
        num = -num;
        return NumberWithUnits(num,unit);
    }

    NumberWithUnits NumberWithUnits::operator+(){
      return *this;
    }

    NumberWithUnits NumberWithUnits::operator -=(NumberWithUnits const& a){
      if(this->unit == a.unit){
        this->num -= a.num;
        return *this;
      }
      NumberWithUnits temp(-a.num,a.unit);
      NumberWithUnits ans = checkUnits(*this,temp);
      if(ans.getUnit() != "-1"){
        this->num = ans.num;
        return *this;
      }
      else{
        throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+this->unit+"]");
      }
    }

    bool operator >(const NumberWithUnits& a, const NumberWithUnits& b){
      if(a.unit == b.unit){
        return (a.num > b.num);
      }
      switch(compareUnits(a,b)) {
        case 1:
          return true;
          break;
        case 2:
          return false;
          break;
        case 0:
          return false;
          break;
        default:
                throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+b.unit+"]");
      }
    }

    bool operator >=(const NumberWithUnits& a, const NumberWithUnits& b){
      if(a.unit == b.unit){
        return (a.num >= b.num);
      }
      switch(compareUnits(a,b)) {
        case 1:
          return true;
          break;
        case 2:
          return false;
          break;
        case 0:
          return true;
          break;
        default:
                throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+b.unit+"]");
      }
    }

    bool operator <(const NumberWithUnits& a, const NumberWithUnits& b){
      if(a.unit == b.unit){
        return (a.num < b.num);
      }
      switch(compareUnits(a,b)) {
        case 1:
          return false;
          break;
        case 2:
          return true;
          break;
        case 0:
          return false;
          break;
        default:
                throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+b.unit+"]");
      }
    }

    bool operator <=(const NumberWithUnits& a, const NumberWithUnits& b){
      if(a.unit == b.unit){
        return (a.num <= b.num);
      }
      switch(compareUnits(a,b)) {
        case 1:
          return false;
          break;
        case 2:
          return true;
          break;
        case 0:
          return true;
          break;
        default:
                throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+b.unit+"]");
      }
    }

    bool operator ==(const NumberWithUnits& a, const NumberWithUnits& b){
      if(a.unit == b.unit){
        return (a.num == b.num);
      }
      switch(compareUnits(a,b)) {
        case 1:
          return false;
          break;
        case 2:
          return false;
          break;
        case 0:
          return true;
          break;
        default:
                throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+b.unit+"]");
      }
    }


    bool operator !=(const NumberWithUnits& a, const NumberWithUnits& b){
      if(a.unit == b.unit){
        return (a.num != b.num);
      }
      switch(compareUnits(a,b)) {
        case 1:
          return true;
          break;
        case 2:
          return true;
          break;
        case 0:
          return false;
          break;
        default:
                throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+b.unit+"]");
      }
    }
    // Define prefix increment operator.
    NumberWithUnits& NumberWithUnits::operator++()
    {
      num++;
      return *this;
    }

    // Define postfix increment operator.
    NumberWithUnits NumberWithUnits::operator++(int)
    {
      NumberWithUnits temp = *this;
      ++*this;
      return temp;
    }

    // Define prefix decrement operator.
    NumberWithUnits& NumberWithUnits::operator--()
    {
      num--;
      return *this;
    }

    // Define postfix decrement operator.
    NumberWithUnits NumberWithUnits::operator--(int)
    {
      NumberWithUnits temp = *this;
      --*this;
      return temp;
    }

    NumberWithUnits operator*(double n, NumberWithUnits a){
        a.num *=n;
        return a;
    }

    std::ostream& operator<<(std::ostream& output, const NumberWithUnits& num_unit){
        return output << num_unit.num << '[' << num_unit.unit<<']';
    }

    istream& operator>> (istream& is, NumberWithUnits& num_unit)
    {
      bool flag =false;
      //save number and unit value
      double num_value;
      string  unit_Value; 
      char input = '\0';
      is >> num_value >> input;
      while(input != ']')
      {
          if(input != '[')
          {
              unit_Value += input;
          }
          is >> input;
      }
      //check if there is a unit like that in all map
      for (auto it = NumberWithUnits::unitsListMap.begin(); it != NumberWithUnits::unitsListMap.end(); ++it)
        {
          if(NumberWithUnits::unitsListMap[it->first].count(unit_Value) > 0)
              flag = true;
            for (auto lt = it;  lt != NumberWithUnits::unitsListMap.end(); ++lt)
            {
                if (NumberWithUnits::unitsListMap[lt->first].count(unit_Value) > 0)
                {
                  flag = true;
                }
            }
        }
        if(flag == true){
          num_unit.num =  num_value;
          num_unit.unit =  unit_Value;
        }
        else
        {
            throw runtime_error("Wrong Input!");
        }
        return is;
    }




    double NumberWithUnits::getNum(){
        return num;
    }

    std::string NumberWithUnits::getUnit(){
      return unit;
    }
    void NumberWithUnits::setNum(double n){
        num = n;
    }

    void NumberWithUnits::setUnit(string un){
      unit = un;
    }
    
    NumberWithUnits checkUnits(const NumberWithUnits& a, const NumberWithUnits& b){
      double value , newValue ,transitivityValue;
      string transitivity_Unit="";
      if (NumberWithUnits::unitsListMap.count(a.unit) > 0 && NumberWithUnits::unitsListMap[a.unit].count(b.unit) > 0) {
        // found in list value for [a] to [b]
              value = NumberWithUnits::unitsListMap[a.unit][b.unit];
              newValue=b.num / value;
              newValue+=a.num;
              return NumberWithUnits(newValue , a.unit);
      }
      else {
        if (NumberWithUnits::unitsListMap.count(b.unit) > 0 && NumberWithUnits::unitsListMap[b.unit].count(a.unit) > 0){
             // found in list value for [b] to [a]
              newValue =b.num*NumberWithUnits::unitsListMap[b.unit][a.unit];
              newValue+=a.num;
              return NumberWithUnits(newValue , a.unit);
           }

        else{ // check transitivity
          for (auto ptr = NumberWithUnits::unitsListMap[a.unit].begin();ptr != NumberWithUnits::unitsListMap[a.unit].end(); ptr++) {
                transitivity_Unit=ptr->first;
                if(NumberWithUnits::unitsListMap.count(transitivity_Unit) > 0 && NumberWithUnits::unitsListMap[transitivity_Unit].count(b.unit) > 0){
                    // From B -> T > A
                    //From B To Transitivity_unit
                    value = NumberWithUnits::unitsListMap[transitivity_Unit][b.unit];
                    newValue=b.num / value;
                    //From Transitivity_unit To A
                    value = NumberWithUnits::unitsListMap[a.unit][transitivity_Unit];
                    newValue/=value;
                    newValue+=a.num;
                    return NumberWithUnits(newValue , a.unit);
                }
          }
          for (auto ptr = NumberWithUnits::unitsListMap[b.unit].begin();ptr != NumberWithUnits::unitsListMap[b.unit].end(); ptr++) {
                transitivity_Unit=ptr->first;
                if(NumberWithUnits::unitsListMap.count(transitivity_Unit) > 0 && NumberWithUnits::unitsListMap[transitivity_Unit].count(a.unit) > 0){
                    //From B To Transitivity_unit
                    newValue =b.num*NumberWithUnits::unitsListMap[b.unit][transitivity_Unit];
                    value = NumberWithUnits::unitsListMap[transitivity_Unit][a.unit];
                    newValue*=value;
                    newValue+=a.num;
                    return NumberWithUnits(newValue , a.unit);
                }
          }
          return NumberWithUnits(-1 , "-1");
        }
      }
    }

    int compareUnits(const NumberWithUnits& a, const NumberWithUnits& b){
      double value , newValue ,transitivityValue;
      string transitivity_Unit="";
      if (NumberWithUnits::unitsListMap.count(a.unit) > 0 && NumberWithUnits::unitsListMap[a.unit].count(b.unit) > 0) {
        // found in list value for [a] to [b]
              value = NumberWithUnits::unitsListMap[a.unit][b.unit];
              newValue=b.num / value;
              if(a.num-newValue > 0)
                return (1);
              if(a.num-newValue < 0)
                    return (2);
              else
                    return (0);
      }
      else {
        if (NumberWithUnits::unitsListMap.count(b.unit) > 0 && NumberWithUnits::unitsListMap[b.unit].count(a.unit) > 0){
             // found in list value for [b] to [a]
              newValue =b.num*NumberWithUnits::unitsListMap[b.unit][a.unit];
              if(a.num-newValue > 0){
                return (1);
              if(a.num-newValue < 0)
                    return (2);
              else
                    return (0);
              }
           }

        else{ // check transitivity
          for (auto ptr = NumberWithUnits::unitsListMap[a.unit].begin();ptr != NumberWithUnits::unitsListMap[a.unit].end(); ptr++) {
                transitivity_Unit=ptr->first;
                if(NumberWithUnits::unitsListMap.count(transitivity_Unit) > 0 && NumberWithUnits::unitsListMap[transitivity_Unit].count(b.unit) > 0){
                    // From B -> T > A
                    //From B To Transitivity_unit
                    value = NumberWithUnits::unitsListMap[transitivity_Unit][b.unit];
                    newValue=b.num / value;
                    //From Transitivity_unit To A
                    value = NumberWithUnits::unitsListMap[a.unit][transitivity_Unit];
                    newValue/=value;
                    if(a.num-newValue > 0){
                      return (1);
                    if(a.num-newValue < 0)
                          return (2);
                    else
                          return (0);
                    }
                }
          }
          for (auto ptr = NumberWithUnits::unitsListMap[b.unit].begin();ptr != NumberWithUnits::unitsListMap[b.unit].end(); ptr++) {
                transitivity_Unit=ptr->first;
                if(NumberWithUnits::unitsListMap.count(transitivity_Unit) > 0 && NumberWithUnits::unitsListMap[transitivity_Unit].count(a.unit) > 0){
                    //From B To Transitivity_unit
                    newValue =b.num*NumberWithUnits::unitsListMap[b.unit][transitivity_Unit];
                    value = NumberWithUnits::unitsListMap[transitivity_Unit][a.unit];
                    newValue*=value;
                    if(a.num-newValue > 0){
                      return (1);
                    if(a.num-newValue < 0)
                          return (2);
                    else
                          return (0);
                    }
                }
          }
        }
      }
      return 3;
    }

}
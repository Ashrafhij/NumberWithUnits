#include "NumberWithUnits.hpp"
#include <stdexcept>
const double EPS=0.0001;
using namespace std;

namespace ariel {

    //initializing unitsListMap
    map<string,map<string,double>> NumberWithUnits::unitsListMap;

    //default constructor
    NumberWithUnits::NumberWithUnits(){

    }
    //constructor
    NumberWithUnits::NumberWithUnits(double n , std::string un){
      bool flag=false;
      //check if there is a unit like that in all map
      for (auto it = NumberWithUnits::unitsListMap.begin(); it != NumberWithUnits::unitsListMap.end(); ++it)
        {
          if(NumberWithUnits::unitsListMap.count(un) > 0 || NumberWithUnits::unitsListMap[it->first].count(un) > 0){
              flag = true;
          }
        }
        if(flag == true || un == "-1"){
          num = n;
          unit = un;
        }
        else
        {
          throw runtime_error("Unit Does Not Exist!");
        }
    }

    void NumberWithUnits::read_units(std::ifstream& f){
      string t1, t2;
			char equal = '=';
			double firstVal = 0, secondVal = 0;
			
			while(f >> firstVal >> t1 >> equal >> secondVal >> t2){
				unitsListMap[t1] [t2] = secondVal;
				unitsListMap[t2] [t1] = firstVal/secondVal;
				
				for(auto &pair: unitsListMap[t1]){
					double tmp = unitsListMap[t2][t1] * pair.second;
					unitsListMap[t2][pair.first] = tmp;
                    unitsListMap[pair.first][t2] = 1/tmp; 
				}
				
				for(auto &pair: unitsListMap[t2]){
					double tmp = unitsListMap[t1][t2] * pair.second;
					unitsListMap[t1][pair.first] = tmp;
                    unitsListMap[pair.first][t1] = 1/tmp; 
				}
			}
      // for(auto it1 = units.begin(); it1 != units.end(); it1++)
      //   {
      //   cout <<"{"<< it1->first << "} list :\n"; 
      //   for(auto it2 = it1->second.begin (); it2 != it1->second.end (); it2++)
      //       {
      //       cout << it2->first << " value: " << it2->second << ",";
      //   }
      //   cout << "\n";
      // }
    }

    NumberWithUnits operator+(const NumberWithUnits& a, const NumberWithUnits& b){
      double difference = convertUnits(a,b);
			double num = a.num + difference;
			return NumberWithUnits(num, a.unit);
    }

    NumberWithUnits NumberWithUnits::operator +=(NumberWithUnits const& a){
      this->num += convertUnits(*this,a);
      return *this;
    }

    NumberWithUnits operator-(const NumberWithUnits& a, const NumberWithUnits& b){
      double difference = convertUnits(a,b);
			double num = a.num - difference;
			return NumberWithUnits(num, a.unit);
    }

    NumberWithUnits NumberWithUnits::operator-(){
      return NumberWithUnits(-this->num, this->unit);
    }

    NumberWithUnits NumberWithUnits::operator+(){
      return *this;
    }

    NumberWithUnits NumberWithUnits::operator -=(NumberWithUnits const& a){
      this->num -= convertUnits(*this,a);
      return *this;
    }

    bool operator >(const NumberWithUnits& a, const NumberWithUnits& b){
      double difference = convertUnits(a,b);
      if(a.num - difference > 0 ){
        return true;
      }
      else{
        return false;
      }
    }

    bool operator >=(const NumberWithUnits& a, const NumberWithUnits& b){
      double difference = convertUnits(a,b);
      if(a.num - difference >= 0 ){
        return true;
      }
      else{
        return false;
      }
    }

    bool operator <(const NumberWithUnits& a, const NumberWithUnits& b){
      double difference = convertUnits(a,b);
      if(a.num - difference < 0 ){
        return true;
      }
      else{
        return false;
      }
    }

    bool operator <=(const NumberWithUnits& a, const NumberWithUnits& b){
      double difference = convertUnits(a,b);
      if(a.num - difference <= 0 ){
        return true;
      }
      else{
        return false;
      }
    }

    bool operator ==(const NumberWithUnits& a, const NumberWithUnits& b){
      double difference = convertUnits(a,b);
      if(abs(a.num - difference) <= EPS ){
        return true;
      }
      else{
        return false;
      }
    }


    bool operator !=(const NumberWithUnits& a, const NumberWithUnits& b){
      return !(a==b);
      
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

    NumberWithUnits operator*(NumberWithUnits a,double n){
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
          if(NumberWithUnits::unitsListMap.count(unit_Value) > 0 || NumberWithUnits::unitsListMap[it->first].count(unit_Value) > 0){
              flag = true;
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
    // void NumberWithUnits::setNum(double n){
    //     num = n;
    // }

    // void NumberWithUnits::setUnit(string un){
    //   unit = un;
    // }
    
    double convertUnits(const NumberWithUnits& a, const NumberWithUnits& b){
			if(a.unit == b.unit){
        return b.num;
			}
			if (NumberWithUnits::unitsListMap[b.unit][a.unit] != 0){
        return (NumberWithUnits::unitsListMap[b.unit][a.unit] * b.num);
			}
			throw runtime_error("Units do not match - ["+a.unit+"] cannot be converted to ["+b.unit+"]");
		}

}
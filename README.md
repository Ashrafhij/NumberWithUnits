
# Numbers with units

In 1999, a $ 125 million NASA satellite crashed due to a mismatch in units - one of the teams that developed the satellite worked in metric units and the other team worked in British units (see more examples
[Here] (http://mentalfloss.com/article/25845/quick-6-six-unit-conversion-disasters)).

In order for this not to happen again, we will write a class representing a number with units. In this class it is possible, for example, to represent the number "3 meters" and the number "40 centimeters", and their sum will not be 43 but 3.4 meters - the class will make sure to make the appropriate conversion. In addition, the class will not allow numbers with mismatched Units to be connected, for example, an addition of "3 meters" with "5 seconds" will cause an EXCEPTION.

This class contains:
* A function called `read_units`, which reads the units from a text file. A sample text file can be found [here](units.txt).
* Six arithmetic operators: add (+) add (+ =) plus onri (+), and the three operators corresponding to subtraction (-). As stated, an addition of two numbers of the same Units will be made while converting the unit of the second number to the unit of the first number; Addition two numbers from different Units will cause an exception.
* Six comparison operators: large, large-or-equal, small, small-or-equal, equal, unequal, according to the same rules of the accounting operators.
* Increase by 1 (++) and decrease by 1 (-) before and after the number.
* Doubling by a real number (`double`). Note: There is no multiply two `NumberWithUnits` objects,
But only `NumberWithUnits` double` double`. Doubling does not change the units.
* Input operator and output operator.
Notes on the unit conversion file:
* White-space does not matter.
* The file includes a number of unit-conversion commands. Each command starts with "1", followed by the name of a unit, followed by a "=" sign, followed by some number, followed by the name of another unit. See an example in the file [units.txt] (units.txt).
* Units that are not in the unit file are considered illegal: an attempt to initialize a number with such units will result in an exception.
* Units defined in the file - the units are considered valid: there is no need to check that the data in the file corresponds to reality.
* There is a difference between uppercase and lowercase letters. For example, if a file is set to "km" then only "km" is considered valid - not "KM" or "Km".
Input and output notes:

* The output format of a number with units is: the number, followed by (without space) square brackets, and the contents of the units. See an example “ 2[km] “.
* The input format is similar, except that it is allowed to have white spaces (it is allowed to skip spaces in reading).

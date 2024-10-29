#ifndef ALU_H
#define ALU_H

#include <string>
#include "../../Register/Register.h"
using namespace std;

class Alu {
 
public:
    /**
     * @brief it change the decimal number to hexadecimal numbers.
     *
     * @param number the number in its decimal stat.
     *
     * @return  number in the hexadecimal stat.
     */
    static string decToHex(const string& number);

    /**
     * @brief it change the hexadecimal number to decimal numbers.
     *
     * @param number the number in its Hexadecimal stat.
     *
     * @return  number in the Decimal stat.
     */
    static string hexToDec(const string& number);

    /**
     * @brief add the bit patterns in registers S and T as though they were two’s complement representations
     *        and leave the result in register R.
     *
     * @param reg The register that the addition will happen and stored in
     * @param firstRegIndex the index of the Register S
     * @param secondRegIndex the index of the Register T
     * @param thirdRegIndex the index of the Register R
     *
     */
    static void addTwosComplement(Register &reg, const char &firstRegIndex, const char &secondRegIndex, const char &thirdRegIndex);

    /**
    * @brief add the bit patterns in registers S and T as thoughthey represented values in floating-point notation
    *        and leave the result in register R.
    *
    * @param reg The register that the addition will happen and stored in
    * @param firstRegIndex the index of the Register S
    * @param secondRegIndex the index of the Register T
    * @param thirdRegIndex the index of the Register R
    *
    */
    static void addFloatingPoint(Register &reg, const char &firstRegIndex, const char &secondRegIndex, const char &thirdRegIndex);


};


#endif

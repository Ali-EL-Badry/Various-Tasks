#ifndef ALU_H
#define ALU_H

#include <string>
#include "../../Register/Register.h"
using namespace std;

class Alu {
private:
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

public:
    /**
     * @brief add the bit patterns in registers S and T as though they were two’s complement representations
     *        and leave the result in register R.
     *
     * @param reg The register that the addition will happen and stored in.
     * @param index the index of three Registers where the operation take place.
     */
    static void addTwosComplement(Register &reg, const string &index);

    /**
     * @brief add the bit patterns in registers S and T as thoughthey represented values in floating-point notation
     *        and leave the result in register R.
     *
     * @param reg The register that the addition will happen and stored in.
     * @param index The index of three Registers where the operation take place.
     */
    static void addFloatingPoint(Register &reg, const string &index);

    /**
     * @brief it make the bitwise or operation on the contentin the two registers S and T and store result in R
     *
     * @param reg The register that the addition will happen and stored in.
     * @param index The index of three Registers where the operation take place.
     * 
     */
    static void bitwiseOrRegisters(Register &reg, const string &index);

    /**
     * @brief it make the bitwise and operation on the contentin the two registers S and T and store result in R.
     *
     * @param reg The register that the addition will happen and stored in.
     * @param index The index of three Registers where the operation take place.
     * 
     */
    static void bitwiseAndRegisters(Register &reg, const string &index);
 
    /**
     * @brief it make the bitwise xor operation on the contentin the two registers S and T and store result in R.
     *
     * @param reg The register that the addition will happen and stored in.
     * @param index The index of three Registers where the operation take place.
     * 
     */
    static void bitwiseXorRegisters(Register &reg, const string &index);

    /**
     * @brief it rotatae the value of Register R by X times.
     *
     * @param reg The register that the addition will happen and stored in.
     * @param index The index of three Registers where the operation take place.
     * 
     */
    static void rotateContentRegister(Register &reg, const string &index);

};


#endif

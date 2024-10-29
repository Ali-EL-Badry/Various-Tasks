#ifndef CU_H
#define CU_H

#include <string>
#include "../../Register/Register.h"
#include "../../../Memory/Memory.h"
using namespace std;

class CU {

private:
    /**
     * @brief  Convert hexadecimal number to decimal number
     *
     * @param  number The hexadecimal number
     *
     * @return The decimal number after being converted
     */
     string hexToDec(const string& number);

public:
    /**
     * @brief load the register R with the bit pattern found in the memory cell whose address is XY.
     *
     * @param addressRegister The address of the register.
     * @param addressmemory The address of the memory.
     * @param memory  The memory which contain the value to be loaded.
     * @param reg The register where the content of the memory will be stored.
     */
    static void loadAtAdress(Memory& memory, Register& reg, const char &addressRegister ,const string& addressMemory);

    /**
     * @brief load the register R with the bit pattern found in the memory cell whose address is XY.
     *
     * @param reg The register where the value will be loaded.
     * @param adress The address of the register.
     * @param value The value to be loaded.
     */
    static void loadwith(Register& reg, const char &adress, string &value);

    /**
     * @brief Store the content of register R in the memory cell whose address is XY.
     *
     * @param memory The memory where the content of register will be stored.
     * @param reg The register which contain the value.
     * @param addressRegister The address of the register.
     * @param addressMemory The address of the memory.
     */
    static void storeLocation(Memory& memory, Register& reg, const char &addressRegister ,const string& addressMemory);

    /**
     * @brief  Stores the content of the register R in the address 00 which is the screen.
     *
     * @param memory The memory where the content of the screen register will be stored.
     * @param addressRegister The address of the register containing the address of the memory location.
     * @param addressMemory The address of the memory location where the content of the screen register will be stored.
     */
    static void storeScreen(Memory& memory, const char &addressRegister, const string& addressMemory);

    /**
     * @brief  Move the bits of the register R to register S.
     *
     * @param reg The register where the two register belong to.
     * @param firstRegisterAddress The address of the first register.
     * @param secondRegisterAddress The address of the second register
     *
     */
    static void moveBits(Register &reg, const char &firstRegisterAddress, const char &secondRegisterAddress );

    /**
     * @brief  Jump to the memory location whose address is XY if value of register in address R equals to register in address 0.
     *
     * @param reg The register to check that value of register in address R equals to register in address 0.
     * @param memory The memory where the operation will be done.
     * @param addressMemory The address of the memory location where the program will jump to.
     * @param RegisterAddress The address of the register R.
     *
     */
    static void jumpToLocation(Register &reg, Memory &memory, const string &addressMemory, const char &RegisterAddress);
};

#endif

#ifndef EXTERNALS
#define EXTERNALS

#include "aliases.h"

#include <cmath>
#include <iostream>

const STRING BIN = "0b";
const STRING OCT = "0o";
const STRING DEC = "0d";
const STRING HEX = "0x";

void validate(int, char**);
bool validateArgOne(const STRING&);
bool validateArgTwo(const STRING&);

STRING_PAIR getSrcData(const STRING&);

STRING getTarPrefix(const STRING&);

STRING convert(const STRING&, const STRING&, const STRING&);

STRING toBin(const STRING&, const STRING&);
STRING toOct(const STRING&, const STRING&);
STRING toDec(const STRING&, const STRING&);
STRING toHex(const STRING&, const STRING&);

int getBaseFromPrefix(const STRING&);

int ctoi(const char&);
char itoc(const int&);

#endif

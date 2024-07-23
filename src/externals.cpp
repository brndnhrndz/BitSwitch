#include "../include/externals.h"

void validate(int argc, char** argv) {
    if (argc != 3) {
        throw RUNTIME_ERR("incorrect number of arguments");
    } else if (!validateArgOne(argv[1]) || !validateArgTwo(argv[2])) {
        throw RUNTIME_ERR("invalid arg(s) passed to bits");
    }
}

bool validateArgOne(const STRING& argOne) {
    if (argOne.size() < 2) {
        return false;
    }

    if (argOne[0] == '0') {
        switch (argOne[1]) {
            case 'b':
            case 'B': {
                for (int i = 2; i < argOne.size(); i++) {
                    if (argOne[i] != '0' && argOne[i] != '1') {
                        return false;
                    }
                }

                break;
            }
            case 'o':
            case 'O': {
                for (int i = 2; i < argOne.size(); i++) {
                    if (argOne[i] < '0' || argOne[i] > '7') {
                        return false;
                    }
                }

                break;
            }
            case 'x':
            case 'X': {
                for (int i = 2; i < argOne.size(); i++) {
                    if (!std::isxdigit(argOne[i])) {
                        return false;
                    }
                }

                break;
            }
            default:
                return false;
        }
    } else {
        for (const char c : argOne) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
    }

    return true;
}

bool validateArgTwo(const STRING& argTwo) {
    return argTwo[1] == '\0' && (argTwo[0] == 'b' || argTwo[0] == 'B' ||
                                 argTwo[0] == 'o' || argTwo[0] == 'O' ||
                                 argTwo[0] == 'd' || argTwo[0] == 'D' ||
                                 argTwo[0] == 'x' || argTwo[0] == 'X');
}

STRING_PAIR getSrcData(const STRING& argOne) {
    STRING prefix, digits;

    if (argOne[0] == '0') {
        prefix += argOne.substr(0, 2);
    } else {
        prefix = "0d";
    }

    if (prefix == "0d") {
        digits = argOne;
    } else {
        digits = argOne.substr(2, argOne.size() - 2);
    }

    return std::make_pair(prefix, digits);
}

STRING getTarPrefix(const STRING& argTwo) {
    return STRING("0") + argTwo[0];
}

STRING convert(const STRING& srcPrefix, const STRING& srcDigits, const STRING& tarPrefix) {
    STRING conversion;

    if (srcPrefix == tarPrefix) {
        conversion = srcDigits;
    } else if (tarPrefix == BIN) {
        conversion = toBin(srcPrefix, srcDigits);
    } else if (tarPrefix == OCT) {
        conversion = toOct(srcPrefix, srcDigits);
    } else if (tarPrefix == DEC) {
        conversion = toDec(srcPrefix, srcDigits);
    } else if (tarPrefix == HEX) {
        conversion = toHex(srcPrefix, srcDigits);
    }

    if (tarPrefix != DEC) {
        conversion = tarPrefix + conversion;
    }

    return conversion;
}

STRING toBin(const STRING& srcPrefix, const STRING& srcDigits) {
    int exp = 0, sum = 0, base = getBaseFromPrefix(srcPrefix);

    STRING conversion;

    for (int i = srcDigits.size() - 1; i >= 0; i--) {
        sum += ctoi(srcDigits[i]) * std::pow(base, exp);
        exp++;
    }

    while (sum != 0) {
        conversion.insert(conversion.begin(), itoc(sum % 2));
        sum /= 2;
    }

    return conversion;
}

STRING toOct(const STRING& srcPrefix, const STRING& srcDigits) {
    int exp = 0, sum = 0, base = getBaseFromPrefix(srcPrefix);

    STRING conversion;

    for (int i = srcDigits.size() - 1; i >= 0; i--) {
        sum += ctoi(srcDigits[i]) * std::pow(base, exp);
        exp++;
    }

    while (sum != 0) {
        conversion.insert(conversion.begin(), itoc(sum % 8));
        sum /= 8;
    }

    return conversion;
}

STRING toDec(const STRING& srcPrefix, const STRING& srcDigits) {
    int exp = 0, sum = 0, base = getBaseFromPrefix(srcPrefix);

    STRING conversion;

    for (int i = srcDigits.size() - 1; i >= 0; i--) {
        sum += ctoi(srcDigits[i]) * std::pow(base, exp);
        exp++;
    }

    conversion = std::to_string(sum);

    return conversion;
}

STRING toHex(const STRING& srcPrefix, const STRING& srcDigits) {
    int exp = 0, sum = 0, base = getBaseFromPrefix(srcPrefix);

    STRING conversion;

    for (int i = srcDigits.size() - 1; i >= 0; i--) {
        sum += ctoi(srcDigits[i]) * std::pow(base, exp);
        exp++;
    }

    while (sum != 0) {
        conversion.insert(conversion.begin(), itoc(sum % 16));
        sum /= 16;
    }

    return conversion;
}

int getBaseFromPrefix(const STRING& prefix) {
    int base;

    switch (prefix[1]) {
        case 'b': {
            base = 2;

            break;
        }
        case 'o': {
            base = 8;

            break;
        }
        case 'd': {
            base = 10;

            break;
        }
        case 'x': {
            base = 16;

            break;
        }
        default: {
            break;
        }
    }

    return base;
}

int ctoi(const char& digit) {
    switch (digit) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            return digit - 48;
        }
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F': {
            return digit - 55;
        }
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f': {
            return digit - 87;
        }
        default: {
            return 0;
        }
    }
}

char itoc(const int& digit) {
    switch (digit) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9: {
            return digit + 48;
        }
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15: {
            return digit + 87;
        }
        default: {
            return '0';
        }
    }
}

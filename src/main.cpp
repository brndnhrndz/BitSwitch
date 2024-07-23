#include "../include/externals.h"

int main(int argc, char** argv) {

    try {
        validate(argc, argv);
    } catch (EXCEPTION& err) {
        std::cerr << "Error: " << err.what() << std::endl;
        
        return -1;
    }

    const STRING_PAIR srcData = getSrcData(argv[1]);

    const STRING srcPrefix = std::get<0>(srcData);
    const STRING srcDigits = std::get<1>(srcData);
    const STRING tarPrefix = getTarPrefix(argv[2]);

    std::cout
        << "> "
        << convert(srcPrefix, srcDigits, tarPrefix)
        << std::endl;

    return 0;
}

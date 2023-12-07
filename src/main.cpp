#include <iostream>
#include "ParserData.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error! The name of the input file is missing. Try: ./io_parser [name_of_file].";

        return 1;
    }

    try
    {
        ParserData pd(argv[1]);

        pd.DoParse();

        std::cout << pd;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';

        return 1;
    }

    return 0;
}
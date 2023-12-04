#pragma once

#include <vector>
#include <string>
#include <fstream>

class ParserData
{
private:
    std::vector<std::string> nameCol;
    std::vector<std::vector<double>> data;
    std::ifstream in;
public:
    ParserData(std::string filename);

    void DoParse();

    ~ParserData();

    friend std::ostream& operator<<(std::ostream& out, ParserData& pd);
};

std::ostream& operator<<(std::ostream& out, ParserData& pd);

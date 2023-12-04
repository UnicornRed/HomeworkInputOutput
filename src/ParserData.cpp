#include <ios>
#include <iostream>
#include <sstream>
#include "ParserData.h"

ParserData::ParserData(std::string filename)
{
    in.open(filename);

    if (!in)
        throw  std::ios_base::failure("Error! The file was not opened");
}

void RemoveSpaceFromEnd(std::string& str)
{
    while (str.back() == ' ' || str.back() == '\t')
        str = str.substr(0, str.length() - 1);
}

void ParserData::DoParse()
{
    double x;
    std::string str;
    std::getline(in, str);
    RemoveSpaceFromEnd(str);

    std::stringstream ss;
    ss.exceptions(std::ios_base::failbit);
    ss << str;

    while (!ss.eof())
    {
        ss >> str;

        nameCol.push_back(str);
    }

    while (std::getline(in, str))
    {
        RemoveSpaceFromEnd(str);
        ss.clear();
        ss << str;
        data.push_back(std::vector<double>());

        while (!ss.eof())
        {
            try
            {
                ss >> x;
            }
            catch(const std::exception& e)
            {
                throw  std::ios_base::failure("Error! Incorrect format of a real number: row = " +
                    std::to_string(data.size()) + ", col = " + std::to_string(data.back().size() + 1));
            }

            data.back().push_back(x);
        }

        if (data.back().size() != nameCol.size())
            throw  std::ios_base::failure("Error! The number of elements is not equal the number of columns: row = " + std::to_string(data.size()));
    }
}

ParserData::~ParserData()
{
    in.close();
}

std::ostream& operator<<(std::ostream& out, ParserData& pd)
{
    for (const std::string& str : pd.nameCol)
        out << str << "\t";

    out << "\n";

    for (const std::vector<double>& v : pd.data)
    {
        for (const double& x : v)
            out << x << "\t";

        out << "\n";
    }

    return out;
}
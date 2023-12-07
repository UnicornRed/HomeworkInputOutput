#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <exception>

class IncorrectElementException : public std::exception
{
private:
    std::string errorMsg;
public:
    IncorrectElementException(const std::string& _errorMsg) : errorMsg(_errorMsg + ": parsing error") {};

    virtual const char* what() const noexcept override
    {
        return errorMsg.c_str();
    }
};

class ErrorLineException : public std::exception
{
private:
    std::string errorMsg;
public:
    ErrorLineException(const std::string& _errorMsg) : errorMsg(_errorMsg + ": parsing error") {};

    virtual const char* what() const noexcept override
    {
        return errorMsg.c_str();
    }
};

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

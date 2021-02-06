#pragma once
#include <iostream>
#include <string>


namespace COM_POS
{
    enum { CLERK, SENIOR, ASSIST, MANAGER };
    void ShowPositionInfo(int pos);
}

class NameCard {
public:
    NameCard(std::string n, std::string c, std::string p, int pos);
    void ShowNameCardInfo();
private:
    std::string name;
    std::string company;
    std::string phone;
    int position;
};

//NameCard::NameCard(std::string n, std::string c,
//    std::string p, int pos);
//
//void NameCard::ShowNameCardInfo();

#pragma once
#include "Namecard.h"



void COM_POS::ShowPositionInfo(int pos) {
	switch (pos)
	{
	case CLERK:
		std::cout << "사원" << std::endl;
		break;
	case SENIOR:
		std::cout << "주임" << std::endl;
		break;
	case ASSIST:
		std::cout << "대리" << std::endl;
		break;
	case MANAGER:
		std::cout << "과장" << std::endl;
		break;
	}
}


NameCard::NameCard(std::string n, std::string c,
	std::string p, int pos) {
	name = n;
	company = c;
	phone = p;
	position = pos;
}

void NameCard::ShowNameCardInfo() {
	std::cout << "이름 : " << name << std::endl;
	std::cout << "회사 : " << company << std::endl;
	std::cout << "전화번호 : " << phone << std::endl;
	std::cout << "직급 : ";
	COM_POS::ShowPositionInfo(position);
	std::cout << std::endl;
}

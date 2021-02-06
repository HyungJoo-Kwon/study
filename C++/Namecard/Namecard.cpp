#pragma once
#include "Namecard.h"



void COM_POS::ShowPositionInfo(int pos) {
	switch (pos)
	{
	case CLERK:
		std::cout << "���" << std::endl;
		break;
	case SENIOR:
		std::cout << "����" << std::endl;
		break;
	case ASSIST:
		std::cout << "�븮" << std::endl;
		break;
	case MANAGER:
		std::cout << "����" << std::endl;
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
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "ȸ�� : " << company << std::endl;
	std::cout << "��ȭ��ȣ : " << phone << std::endl;
	std::cout << "���� : ";
	COM_POS::ShowPositionInfo(position);
	std::cout << std::endl;
}

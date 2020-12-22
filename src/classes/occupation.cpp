#include <iostream>
#include "../../headers/classes/occupation.h"
#include "../../headers/getType.h"

lsim::Occupation::Occupation(lsim::mainCharacter *nSelf, int occupationType) {
	this->self = nSelf;
	this->type = occupationType;
	this->menu.add("Stats");
	this->menu.add("Work harder");
	this->menu.add("Put less efforts");
	this->menu.add("Exit");
}

int lsim::Occupation::putEfforts(bool p_efforts) {
	if (p_efforts) {
		float distance = 100 - this->efforts;
		distance /= 1.5;
		this->efforts = 100 - distance;
	} else {
		this->efforts /= 1.5;
	}
	return this->efforts;
}

void lsim::Occupation::goToMenu() {
	std::cout << this->name << " (" << lsim::occupationType(this->type) << ") :" << std::endl;
	int choice = this->menu.awaitUserInput();
	switch (choice) {
		case 1:
			std::cout << "Efforts : " << this->efforts;
			break;
		case 2:
			std::cout << "Working harder! Efforts are now " << this->putEfforts(true) << "." << std::endl;
			break;
		case 3:
			std::cout << "Putting less efforts... Efforts are now " << this->putEfforts(false) << "." << std::endl;
			break;
		case 4:
			break;
	}
}

int lsim::Occupation::getType() {
	return this->type;
}

std::string lsim::Occupation::getName() {
	return this->name;
}
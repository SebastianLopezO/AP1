#include <iostream>
#include <stdlib.h>
#include <string>
int main(){
	std::string name;
	std::cout << "Please, enter your full name: ";
	std::getline (std::cin,name);
	std::cout << "Hello, " << name << "!\n";
}
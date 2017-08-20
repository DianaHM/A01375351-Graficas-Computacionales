#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"

int main() {
	Circle circulo(2.0, "green");
	std::cout << circulo.GetColor() << std::endl;

	Rectangle rectangulo(5.0, 3.0);
	std::cout << rectangulo.GetArea() << std::endl;

	Employee empleado(8967, "Diana", "Hernandez", 1000);
	std::cout << empleado.Print() << std::endl;

	std::cin.get();
	return 0;
}
/***********************************************

Materia: Gráficas Computacionales

Fecha: 14 de agosto del 2017

Autor: A01375351 Diana Isabel Hernández María

************************************************/

#include <iostream>

int PerimetroRectangulo(int base, int altura) {
	int p = 2 * (base + altura);
	return p;
}

float AreaTriangulo(float base, float altura) {
	float a = (base*altura) / 2.0;
	return a;
}

int Mayor(int numero1, int numero2, int numero3) {
	if (numero1 > numero2) {
		int nm = numero1;
		if (nm > numero3)
			return numero1;
	}
	if (numero2 > numero1) {
		int nm = numero2;
		if (nm > numero3)
			return numero2;
	}
	if (numero3 > numero1) {
		int nm = numero3;
		if (nm > numero2)
			return numero3;
	}
}

int Menor(int numero1, int numero2, int numero3) {
	if (numero1 < numero2) {
		int nmen = numero1;
		if (nmen < numero3)
			return numero1;
	}
	if (numero2 < numero1) {
		int nmen = numero2;
		if (nmen < numero3)
			return numero2;
	}
	if (numero3 < numero1) {
		int nmen = numero3;
		if (nmen < numero2)
			return numero3;
	}
}

void FilaEstrellas(int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << "*";
	}
	std::cout << "" << std::endl;

}

void MatrizEstrellas(int n) {
	for (int i = 0; i < n; ++i) {
		for (int i = 0; i < n; ++i) {
			std::cout << "*";
		}
		std::cout << "" << std::endl;
	}

}

void PiramideEstrellas(int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			for (i = 0; i < j; ++i) {
				std::cout << "*";
			}
			std::cout << "" << std::endl;
		}
	}

}

void FlechaEstrellas(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			std::cout << "*";
		}
		std::cout << "" << std::endl;
	}
	for (int i = n - 1; i >= 1; --i) {
		for (int j = 1; j <= i; ++j) {
			std::cout << "*";
		}
		std::cout << "" << std::endl;
	}
}

void Fibonacci(int n) {
	int c = 1;
	int f = 1;
	int a = 1;
	int b = 1;
	std::cout << a;
	while (c != n) {
		std::cout << f;
		f = a + b;
		a = b;
		b = f;
		c++;
		if (c == n) {
			std::cout << "" << std::endl;
		}
	}
}

bool EsPrimo(int numero) {
	int d = 0;
	for (int i = 1; i < (numero + 1); i++) {
		if (numero%i == 0) {
			d++;
		}
	}
	if (d != 2) {
		return false;
	}
	else {
		return true;
	}
	return 0;
}




int main() {
	int p = PerimetroRectangulo(4, 8);
	float a = AreaTriangulo(5.0, 3.0);
	int mayor = Mayor(5, 8, 9);
	int menor = Menor(9, 3, 2);


	std::cout << "El perimetro del rectangulo es " << p << std::endl;
	std::cout << "El area del triangulo es " << a << std::endl;
	std::cout << "El numero mayor es " << mayor << std::endl;
	std::cout << "El numero menor es " << menor << std::endl;

	FilaEstrellas(5);
	MatrizEstrellas(8);
	PiramideEstrellas(6);
	FlechaEstrellas(4);
	Fibonacci(9);

	bool primo = EsPrimo(54);
	std::cout << primo << std::endl;


	std::cin.get();
	return 0;
}



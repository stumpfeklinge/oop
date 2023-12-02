#include <iostream>

using namespace std;

class Fraction {
private:
	int chisl;
	int znam;

public:
	Fraction(int num, int denom) : chisl(num), znam(denom) {
	}

	~Fraction() {
	}

	void reduceFraction() {
        int NOD=findNOD(chisl,znam);
		chisl /= NOD;
		znam /= NOD;

	}

	void printFraction() {
		if(abs(chisl)>=abs(znam)){
			int osn=chisl/znam;
			chisl=chisl%znam;
			cout<<osn<<" "<<chisl << "/" << znam<<endl;
		}
		else
			cout<<chisl << "/" << znam<<endl;

		
	}

	Fraction operator+(const Fraction& other) {
		int newchisl = (chisl * other.znam) + (other.chisl * znam);
		int newznam = znam * other.znam;
		return Fraction(newchisl, newznam);
	}

	Fraction operator-(const Fraction& other) {
		int newchisl = (chisl * other.znam) - (other.chisl * znam);
		int newznam = znam * other.znam;
		return Fraction(newchisl, newznam);
	}

	Fraction operator*(const Fraction& other) {
		int newchisl = chisl * other.chisl;
		int newznam = znam * other.znam;
		return Fraction(newchisl, newznam);
	}

	Fraction operator/(const Fraction& other) {
		if ((other.chisl == 0)||(znam==0)) {
			throw logic_error("Деление на ноль!");
		}

		int newchisl = chisl * other.znam;
		int newznam = znam * other.chisl;
		return Fraction(newchisl, newznam);
	}

private:
	int findNOD(int a, int b) {
		if (a == 0)
			return b;
		if (b == 0)
			return a;
		while (b != 0) {
			int remainder = a % b;
			a = b;
			b = remainder;
		}

		return a;
	}
};

int main() {
	try {
		
		
		// Ввод дробей
		cout<<"Введите дробь a/b:"<<endl;
		int a,b;
		cout<<"Введите числитель а:";
		cin>>a;
		cout<<"Введите знаменатель b:";
		cin>>b;
		Fraction fraction1(a, b);
		fraction1.printFraction();
		cout<<"Введите дробь c/d:"<<endl;
		int c,d;
		cout<<"Введите числитель c:";
		cin>>c;
		cout<<"Введите знаменатель d:";
		cin>>d;
		Fraction fraction2(c, d);
		fraction2.printFraction();
		cout<<"Введите дробь e/f:"<<endl;
		int e,f;
		cout<<"Введите числитель e:";
		cin>>e;
		cout<<"Введите знаменатель f:";
		cin>>f;
		Fraction fraction3(e, f);
		fraction3.printFraction();
		cout<<"Введите дробь g/h:"<<endl;
		int g,h;
		cout<<"Введите числитель g:";
		cin>>g;
		cout<<"Введите знаменатель h:";
		cin>>h;
		Fraction fraction4(g, h);
		fraction4.printFraction();
		cout<<"Введите дробь k/j:"<<endl;
		int k,j;
		cout<<"Введите числитель k:";
		cin>>k;
		cout<<"Введите знаменатель j:";
		cin>>j;
		Fraction fraction5(k, j);
		fraction5.printFraction();
		// Выполняем арифметические операции с дробями
		Fraction sum = fraction1 + fraction2;
		Fraction del = sum / fraction3;
		Fraction razn = fraction4 - fraction5;
		Fraction proiz = del * razn;

		//Вывод дробей
        cout<<"Дробь Z=((a/b+c/d)/(e/f))*(g/h-k/j) до сокращения:";
        proiz.printFraction();
        cout << endl;

        cout<<"Дробь Z после сокращения:";
        proiz.reduceFraction();
        proiz.printFraction();
        cout << endl;
        
	}
	catch (const logic_error& e) {
		cout << "Произошла ошибка: " << e.what() << endl;
	}

	return 0;
}

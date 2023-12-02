#include <iostream>
#include <math.h>

using namespace std;

class Treug {
protected:
    double side1, side2, side3;

public:
    Treug(): side1(0),side2(0),side3(0){}

    Treug(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    bool Estb() {
        return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
    }

    double P() {
        if(Estb())
            return side1 + side2 + side3;
        else
            return 0;

    }

    double S() {
        if(Estb()){
            double p = P() / 2;
            return sqrt(p * (p - side1) * (p - side2) * (p - side3));
        }
        else
            return 0;
    }

    void Info() {
        if(Estb()){
            cout << "Стороны треугольника: " << side1 << ", " << side2 << ", " << side3 << endl;
            cout << "Треугольник существует" << endl;
            cout << "Периметр треугольника " << P() << endl;
            cout << "Площадь треугольника: " << S() << endl;    
        }
        else{
            cout << "Стороны треугольника: " << side1 << ", " << side2 << ", " << side3 << endl;
            cout<<"Треугольник не существует!"<<endl;
        }
    }
};

class PravTreug : public Treug {
    public:
        PravTreug(): Treug() {}
        PravTreug(double side) : Treug(side, side, side) {}

    bool PravProverka() {
        return side1 == side2 && side1 == side3;
    }

    void Info() {
        if(Estb())
        {
            cout << "Стороны правильного треугольника: " << side1 << ", " << side2 << ", " << side3 << endl;
            cout << "Треугольник cуществует" << std::endl;
            cout << "Треугольник " << (PravProverka() ? "" : "не ") << "правильный" << std::endl;
            cout << "Периметр: " << P() << endl;
            cout << "Площадь: " << S() << endl;  
        }
        else
        {
            cout << "Стороны правильного треугольника: " << side1 << ", " << side2 << ", " << side3 << endl;
            cout << "Треугольник не cуществует" << std::endl;
        }
    };
};

int main() {

int L;
cout<<"Введите кол-во правильных треугольников: ";
cin>>L;
cout<<""<<endl;

int K;
cout<<"Введите кол-во  треугольников: ";
cin>>K;
cout<<""<<endl;

cout<<"Информация об треугольниках: "<<endl;
Treug *arr=new Treug[K];
for(int i=0;i<K;i++){
    arr[i]=Treug(rand() %10 +1,rand() %10 +1,rand() %10 +1);
    arr[i].Info();
    cout<<""<<endl;
}

PravTreug *arra=new PravTreug[L];
for(int i=0;i<L;i++){
    arra[i]=PravTreug(rand() %10 +1);
    arra[i].Info();
    cout<<""<<endl;

}
double totalS = 0;
double maxS = 0;

// Вычисление средней площади K треугольников
for (int i = 0; i < K; ++i) {
    if (arr[i].Estb()) 
        totalS += arr[i].S();
}

// Нахождение наибольшего равностороннего треугольника
for (int i = 0; i < L; ++i) {
    if (arra[i].Estb()) {
        double area = arra[i].S();
        if (area > maxS) {
            maxS = area;
        }
    }
}

double avgArea = totalS / K;

cout << "Средняя площадь для K треугольников: " << avgArea << endl;
cout << "Максимальная площадь среди правильных треугольников:  " << maxS << endl;


Treug tat(1,1,1);
cout<<tat.P();
return 0;
}

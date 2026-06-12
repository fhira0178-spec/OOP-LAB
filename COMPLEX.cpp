/* Show count increasing with each object
a. Design a class Complex with:
b. Constructor overloading
c. Overload + operator */

#include<iostream>
using namespace std;

class Complex {
private:
	static int count;
	int real, imag;
public:
	Complex() {
		real = 0;
		imag = 0;
		count++;
	}
	Complex(int r, int i = 0) {       //Parameterized Constructor (handles overloading)
		real = r;
		imag = i;
		count++;
	}
	Complex operator+ (const Complex& obj) {
		count--;                  //temporary object does not increase count
		Complex sum;
		sum.real = real + obj.real;
		sum.imag = imag + obj.imag;
		return sum;
	}
	void Display() {
		cout << real << " + " << imag << "i" << endl;
		cout << "Total objects created so far: " << count << endl << endl;
	}
};

int Complex::count = 0;

int main() {
	Complex obj1(5, 7);               //Parameterized Constructor
	obj1.Display();

	Complex obj2(3, 1);               //Parameterized Constructor
	obj2.Display();

	Complex obj3 = obj1 + obj2;      //Temporary object
	cout << "Sum = ";
	obj3.Display();

	Complex obj4;                    //Default Constructor
	obj4.Display();

	Complex obj5(5);                //Parameterized Constructor with default argument
	obj5.Display();

	return 0;
}
#include <iostream>
using namespace std;

class Complex
{
    float real;
    float img;
    
public:
    void setReal(float);
    void setImg(float);
    void print();
    Complex add(Complex);  // Takes only one Complex as parameter
    Complex sub(Complex);  // Takes only one Complex as parameter
};

void Complex::setReal(float x)
{
    real = x;
}

void Complex::setImg(float x)
{
    img = x;
}

void Complex::print()
{
    cout << real << " + " << img << "i" << endl;
}

// Add function using the calling object (this)
Complex Complex::add(Complex x)
{
    Complex temp;
    temp.real = this->real + x.real;
    temp.img = this->img + x.img;
    return temp;
}

// Subtract function using the calling object (this)
Complex Complex::sub(Complex x)
{
    Complex temp;
    temp.real = this->real - x.real;
    temp.img = this->img - x.img;
    return temp;
}

int main()
{
    Complex myComp1, myComp2, resultComp;
    
    myComp1.setReal(2);
    myComp1.setImg(3);
    myComp2.setReal(4);
    myComp2.setImg(5);

    myComp1.print();
    myComp2.print();

  
    // Call add() and sub() with a single parameter
    resultComp = myComp1.add(myComp2);
    resultComp.print();

    resultComp = myComp1.sub(myComp2);
    resultComp.print();

    return 0;
}

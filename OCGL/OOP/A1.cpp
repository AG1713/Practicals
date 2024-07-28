# include<iostream>
using namespace std;

class Complex{
    int real;
    int imaginery;

    public:
    Complex(){
        real = 0;
        imaginery = 0;
    }
    
    void operator& (){ // This is how we overload unary operator
        cout<<'('<<real<<')'<<"+"<<'('<<imaginery<<"i"<<')'<<endl;
    }

    int get_real(){return real;}
    int get_imaginery(){return imaginery;}
    void set_values(int r, int i){
        real = r;
        imaginery = i;
    }
};

Complex operator+ (Complex a, Complex b){ // This is how we overload binary operator
    Complex temp;
    temp.set_values(a.get_real() + b.get_real(), a.get_imaginery() + b.get_imaginery());
    return temp;
}

Complex operator* (Complex a, Complex b){
    Complex temp;
    temp.set_values((a.get_real()*b.get_real())-(a.get_imaginery(), b.get_imaginery()), (a.get_real()*b.get_imaginery())+(a.get_imaginery()*b.get_real()));
    return temp;
}

Complex operator<<(Complex a, Complex b){
    Complex c = a+b;
    cout<<"Real :"<<c.get_real()<<" Imaginery :"<<c.get_imaginery()<<endl;
}

Complex operator>>(Complex a, Complex b){
    Complex c = a*b;
    cout<<"Real :"<<c.get_real()<<" Imaginery :"<<c.get_imaginery()<<endl;
}




int main(){
    Complex n1, n2;
    n1.set_values(3,4);
    n2.set_values(-8,4);
    
    cout<<"n1 = ";
    &n1;
    cout<<"n2 = ";
    &n2;

    cout<<"Addition =";
    &(n1+n2);
    n1<<n2;
    cout<<"Multiplication =";
    &(n1*n2);
    n1>>n2;
    
    return 0;
}
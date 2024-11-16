#include<iostream>

using namespace std;


int multiply(int a, int b)
{
    if(b==1)
    {
        //this return will used to end the recursion
        return a;
    }

    b-=1;
    
    a+=multiply(a,b);
    //this return handle the other return of function
    return a;

}


int main(void)
{
    cout<<"Multiplication of two numbers "<<endl;
    cout<<"Enter number1:";
    int num1;
    cin>>num1;
    int num2;
    cout<<"Enter number2:";
    cin>>num2;
    cout<<"Multiplication of two numbers is "<<multiply(num1,num2)<<endl;
    return 0;
}
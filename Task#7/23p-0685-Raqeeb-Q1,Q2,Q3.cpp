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

int Fibonacci(int value,int a, int b)
{
    if(value==1)
    {
        return a;
    }

    value-=1;
    int sum=a+b;
    b=a;
    a=sum;

    return Fibonacci(value,sum,b);
    
}

int Sum_of_digit(int user_input)
{
    if(int(user_input/10) ==0)
    {
        return user_input;
    }

    user_input=Sum_of_digit(user_input/10) +(user_input%10);
    return user_input;
}


int main(void)
{
    cout<<"*********************************************************"<<endl;
    //QUESTION 1 Multiply by Recursion
    cout<<"\nEnter any two numbers to find their product:";
    int user_input1;
    int user_input2;
    cout<<"Num1:";
    cin>>user_input1;
    cout<<"Num2:";
    cin>>user_input2;
    cout<<"\nProduct of "<<user_input1<<" and "<<user_input2<<" is :"<<multiply(user_input1,user_input2)<<endl;
    cout<<"*********************************************************"<<endl;

    //Question 2 Fibonacci series number by Recursion
    cout<<"\nEnter any number to find Fibonacci series:";
    int user_input;
    cin>>user_input;
    cout<<"\nThe value of Fibonacci series at "<<user_input<<" is :"<<Fibonacci(user_input,1,0)<<endl;
    cout<<"*********************************************************"<<endl;

    //Question 3 Sum of Digits of a number by Recursion
    cout<<"\nEnter any number with multiple digit to find their sum:";
    cin>>user_input;
    cout<<"The sum of digit of the number is :"<<Sum_of_digit(user_input)<<endl;
    cout<<"*********************************************************"<<endl;

    return 0;
}
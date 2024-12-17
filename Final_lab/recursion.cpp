#include<iostream>
#include<string>

using namespace std;


class Recusrsion
{
    
    public:



    int Vowels_extraction(string value, int len, int count)
    {
        if (len == 0)
        {
            return count;
        }

        if (value[len - 1] == 'A' || value[len - 1] == 'a' || value[len - 1] == 'E' || value[len - 1] == 'e' || value[len - 1] == 'i' || value[len - 1] == 'I' || value[len - 1] == 'O' || value[len - 1] == 'o' || value[len - 1] == 'U' || value[len - 1] == 'u')
            count++;

        return Vowels_extraction(value, len - 1, count);
    }


    int sum_of_array(int *values,int len,int sum)
    {
        if(len==0)
        {
            return sum;
        }
        return sum_of_array(values,len-1,values[len-1]+sum);
    }


    bool Palendrome(string value, int start, int end)
    {
        if (start >= end)
        {
            return true;
        }

        if (value[start] != value[end])
        {
            return false;
        }

        return Palendrome(value, start + 1, end - 1);
    }

    int reversing_digits(int numbers,int order)
    {
        if(numbers/10==0)
        {
            return numbers;
        }

        int num=0;
        
        num +=(order* reversing_digits(numbers/10,order/10));
        
        return num;

    }

};



int main(void)
{
    Recusrsion obj1;
    string value="my name is khan";
    int vowels=0;
    int *count=&vowels;

    vowels = obj1.Vowels_extraction(value, value.length(), 0);
    cout << vowels << endl;

    int arr[5]={1,2,3,4,5};
    string palindromeValue = "madam";
    bool isPalindrome = obj1.Palendrome(palindromeValue, 0, palindromeValue.length() - 1);
    cout << "Is palindrome: " << (isPalindrome ? "Yes" : "No") << endl;
    int order = pow(10, static_cast<int>(log10(number)));
    return 0;


}

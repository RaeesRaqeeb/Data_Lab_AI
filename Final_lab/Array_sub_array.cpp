#include<iostream>

using namespace std;

void subArray(int *arr, int size, int tar)
{
    for(int i=0; i<size; i++)
    {
        int sum=arr[i];
        
        for(int j=i+1; j<size; j++)
        {
            if(sum==tar)
            {
                cout<<"["<<i<<","<<j<<"]"<<endl;
                return;
            }
            sum+=arr[j];

        }
    }

    cout<<"The target sum is not found"<<endl;
}

int main(void)
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int tar=1;
    
    subArray(arr, 5, tar);



    return 0;
}
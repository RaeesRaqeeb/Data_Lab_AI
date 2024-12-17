#include<iostream>

using namespace std;


int main(void)
{
    int k=3;
    int arr[5]={7,5,4,1,10};
    int min=arr[0];

    for(int i=0;i<5;i++)
    {

        for(int j=0;j<5;j++)
        {
            if(arr[i]<arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                j=0;
            }
        }

    }
    for(int i=0;i<5;i++)
        cout<<arr[i]<<endl;
    cout<<k<<"th small value is:"<<arr[k-1]<<endl;
    return 0;
}
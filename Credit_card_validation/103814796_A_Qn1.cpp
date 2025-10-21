// Student name: Kha Anh Nguyen
// Student ID: 103814796
// File name: 103814796_A_Qn1.cpp
// Purpose: To create program which check the validating of the credit card
#include <iostream>
#include <string>
using namespace std;

#define SIZE 20

int sum1(int number[], int array_length)
{
    int size = (array_length+1)/2; // size of the sum1 array set
    int total=0, i;
    int num1[size]={};
    int j =0; 

    for(i=array_length-2;i>=0;i-=2)
    {
        num1[j]=number[i];
        j++; //for reverse cout

        number[i]*= 2; 
        if ((number[i]>=10)) 
        {
            number[i]= 1+ number[i]%10; // 1 + Rem (10 => 1 + 0)
        }
        total += number[i];
    }

    cout<<"\nNumbers for sum1 are ";
    bool isFirstNonZero = true; // eliminate excess 0 in array 
    for (int i = size - 1; i >= 0; i--) // reverse order
    {
        if (num1[i] != 0 || !isFirstNonZero)
        {
            cout << num1[i] << " ";
            isFirstNonZero = false;
        }
    }
    cout << "\nSum 1 is " << total<<endl;
    return total;
}

int sum2(int number[], int array_length)
{
    int size = (array_length+1)/2; // size of the sum2 array set
    int total=0, i; 
    int num2[size]={0}, j =0;

    for(i=array_length-3;i>=0;i-=2)
    {
        num2[j]=number[i];
        number[i]*= 2;
        if ((number[i]>=10))
        {
            number[i]= 1+ number[i]%10;
        }
        total += number[i];
        j++;
    }

    cout << "Numbers for sum2 are ";
    bool isFirstNonZero = true; // eliminate excess 0 in array 
    for (int i = size - 1; i >= 0; i--)
    {
        if (num2[i] != 0 || !isFirstNonZero)
        {
            cout << num2[i] << " ";
            isFirstNonZero = false;
        }
    }
    cout << "\nSum 2 is " << total<<endl;
    return total;
}

int main()
{
    int card[SIZE]; // Array to store up to 20 digits
    int input, i, size;
    int total1, total2, checksum;
    string str;
    
    cout << "Enter card number in the array, enter -1 to complete: ";

    //* Check card validity and store as array 
    for(i=0; i<SIZE; i++)
    {
        cin>>card[i];
        cin.ignore();
        if (card[i]==-1)
        {
            size = i; //size of input card
            break;
        }
        while (card[i]<0 || card[i] >9 )
        {
            cout << "Please enter number from 0-9 "; 
            cin >> card[i];
        }
    }

    cout << "Credit card number is: " ;
    for (i=0; i<size; i++) 
    {
        cout << card[i];
    }

    total1 = sum1(card,size);
    total2 = sum2(card,size);

    //* ------Calculate check sum----- //
    checksum = (total1 + total2)*9;
    str = to_string(checksum); // convert to string to extract the last number
    i=str.length(); 
    str = str[i-1];
    checksum = stoi(str); //string to integer

    cout<<"Check sum is "<< str[i-1]<< endl; // index = length -1
    cout<<"Last digit on credit card is "<<card[size-1] << endl; //ignore -1
    cout<<"Check sum " << str[i-1]<<" and the last digit "<< card[size-1] ;
    if (checksum==card[size-1])
    {
        cout<<" are the same: Valid credit card number"<<endl;
    }
    else
    {
        cout<<" are different: Invalid credit card number"<<endl;
    }
    return 0;
}

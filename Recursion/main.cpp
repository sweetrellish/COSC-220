//==============================================================
//Author: Ryan and Joshua Ellis
//Creation Date: 11/6/2024
//Last Update: 11/6/2024
//Description: Main function program defines recursive functions for Ackerman's function, Q sequence, D sequence and the Palindrome function and then implements them through tests with user input.
//Notes: 
//==============================================================


#include <iostream>
#include <string>

using namespace std;

int A(int, int);
long D(long);               //function prototypes
long Q(long);
bool isPal(const string& , int , int );


int main(){
    
    long input;
    string pal;         //variable for n and palindrome string
    
     cout<< "---Ackerman's Function---"<<endl;      //print out of ackerman function parameters

     cout << A(0,0)<<endl;
     cout << A(0,1)<<endl;
     cout << A(1,1)<<endl;
     cout << A(1,2)<<endl;
     cout << A(1,3)<<endl;
     cout << A(2,2)<<endl;
     cout << A(3,2)<<endl;
     cout << A(4,1)<<endl;
     //cout << A(4,2)<<endl;   //error seg fault

     cout<< "---D and Q Sequences---"<<endl;
     cout<< "Input n: ";
     cin>>input;

     cout<<"Q Numbers: ";                   //Q number print outs of n starting at 1 to n
     for (long i = 1; i < input+1; i++)
        cout<< Q(i) << " ";
     cout<<endl;
     cout<<"D Numbers: ";
     for (long i = 1; i < input+1; i++)     //D number print outs of n starting at 1 to n
         cout<< D(i)<< " ";
    cout<<endl;

    cout<<"---Palindrome---"<<endl;
    cout<<"Enter a string, no spaces and all lower case: ";     //palindrome testing
    cin>>pal;
    
    if(isPal(pal, 0, pal.length()-1))
        cout<< pal << " is a palindrome "<<endl;
    else 
        cout<< pal << " is not a palindrome. "<<endl;
    
    return 0;
}

int A(int val, int val2){           //Ackerman recursive function definition
    
    if(val == 0 || val2 == 0){      //conditional stops/returns
        if (val == 0)
            return (val2 + 1);
        
        else if(val2 == 0)
            return A(val - 1,1);
    }
    else
        return A(val - 1, A(val, val2 - 1));
   return -1;
}
long D(long n){             //D recursive function definition
    if(n<=0)
        return 1;       //stop conditions/returns
    if(n == 1)
        return 1;
    if(n ==2)
        return 1;
    return D(D(n-1)) + D(n - 1 - D(n - 2));
    
} 

long Q(long n){     //Q recursive function definition
    if(n<=0)
        return 1;
    if(n == 1)
        return 1;       //stop conditions/returns
    if(n == 2)
        return 1;
    return Q(n - Q(n - 1)) + Q(n - Q(n - 2));
    
}

bool isPal(const string& str, int startIndex, int endIndex){        //recursive palindrome checking funciton definition

    if(startIndex >= endIndex)
        return true;
    if(str[startIndex] != str[endIndex]){           //stop conditions/returns
        return false;
    }
    return isPal(str,startIndex+1 ,endIndex-1 );
    
}

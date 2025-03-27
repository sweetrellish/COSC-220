//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/9/2024
// Last Update: 11/14/2024
// Description: Main program to display n choose k values, which mirror Pascal's triangle.
//===========================================================================================================================

#include <iostream>
#include <cmath>

using namespace std;

int pascal(int, int);       //prototype

int main(){
    int n;      //n and k values
    int k;

    cout<<"Enter n and k (integer) with a space between them: ";        //user prompt
    cin>> n>> k;
    cout<<endl;

    cout<<n<<" choose "<<k<<" = "<<pascal(n,k);     //function call to show n choose k
    cout<<endl;

    return 0;
}

int pascal(int n, int k){       //recursive function to determine n choose k

    if(n == 0 || k == 0 )       //if n or k is 0 return 1
        return 1;
    if(n == k)                  //if n equals k return 1
        return 1;
    if(n < 0 || k < 0 || k > n)     //if n,k <0 or k >n return 0
        return 0;

    else
        return pascal(n -1, k-1) + pascal(n- 1, k);     //recursive call for definition of n choose k
}

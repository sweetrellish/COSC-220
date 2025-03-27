//===========================================================================================================================
// Name        : MathSet.h
// Author      : Ryan C. Ellis
// Creation Date: 12/5/2024
// Last Update: 12/6/2024
// Description: Header file for the MathSet class structure, child to parent set class structure. Overloaded operators for
// set arithmetic and set notation.
//===========================================================================================================================

#ifndef MATHSET_H
#define MATHSET_H

#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <set>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> class MathSet: public set<T>{
private:
    MathSet<T> PowerSetR(MathSet<T>);

public:
    MathSet() : set<T>() {}
    MathSet(initializer_list<T> L) : set<T>(L) {}

    MathSet<T> PowerSet();

    MathSet operator+(const MathSet&);
    MathSet operator-(const MathSet&);
    MathSet operator*(const MathSet&);
    MathSet operator^(const MathSet&);
    MathSet operator=(const MathSet&);

    template <class U>
    friend ostream &operator<<(ostream &, const MathSet<U> &);

};

//============================================================================
// Description: Overloaded addition operator for the MathSet class structure. This will include the set_union function from the set class to return the union of the two operand sets.
// Parameters:const MathSet &obj - MathSet object
// Return: MathSet object
// Notes:
//============================================================================
template <class T>
MathSet<T> MathSet<T> :: operator+(const MathSet &obj){
    MathSet<T> set;

    set_union(this->begin(), this->end(), obj.begin(), obj.end(), inserter(set, set.begin()));

    return set;
}

//============================================================================
// Description:Overloaded subtraction operator for the MathSet class structure. This will include the set_difference function from the set class to return the set difference of the two operand sets.
// Parameters:const MathSet &obj - MathSet object
// Return: MathSet object
// Notes:
//============================================================================
template <class T>
MathSet<T> MathSet<T> :: operator-(const MathSet &obj){
    MathSet<T> set;

    set_difference(this->begin(), this->end(), obj.begin(), obj.end(), inserter(set, set.begin()));

    return set;
}

//============================================================================
// Description:Overloaded multiplication operator for the MathSet class structure. This will include the set_intersection function from the set class to return the intersection of the two operand sets.
// Parameters:const MathSet &obj - MathSet object
// Return: MathSet object
// Notes:
//============================================================================
template <class T>
MathSet<T> MathSet<T> :: operator*(const MathSet &obj){
    MathSet<T> set;

    set_intersection(this->begin(), this->end(), obj.begin(), obj.end(), inserter(set, set.begin()));

    return set;
}

//============================================================================
// Description:Overloaded addition operator for the MathSet class structure. This will include the set_symmetric_difference function from the set class to return the symmetric difference of the two operand sets.
// Parameters:const MathSet &obj - MathSet object
// Return: MathSet object
// Notes:
//============================================================================
template <class T>
MathSet<T> MathSet<T> :: operator^(const MathSet &obj){
    MathSet<T> set;

    set_symmetric_difference(this->begin(), this->end(),obj.begin(), obj.end(), inserter(set, set.begin()));

    return set;
}

//============================================================================
// Description: Overloaded assignment operator for the MathSet class structure which calls to the parent class assignment operator.
// Parameters: const MathSet &obj - MathSet object
// Return: MathSet object
// Notes:
//============================================================================
template <class T>
MathSet<T> MathSet<T> :: operator=(const MathSet &obj){
    set<T> :: operator=(obj);
    return *this;
}

//============================================================================
// Description: Overloaded operator for stream operator in MathSet class. Operator will be formatting for sets.
// Parameters:  ostream &strm - ostream object
//              const MathSet &obj - MathSet object
// Return: ostream return type
// Notes:
//============================================================================
template <class T>
ostream  &operator<<(ostream &strm, const MathSet<T> &obj){
    strm<<"{";
    for(auto iter = obj.begin(); iter != obj.end(); ++iter){
        strm<< *iter;
        if(next(iter) != obj.end())
            strm<<", ";
    }
    strm<<" }";

    return strm;

}

//============================================================================
// Description: Function will call recursive function on called object.
// Parameters: N/A
// Return: void no return
// Notes:
//============================================================================
template <class T>
MathSet<T> MathSet<T> :: PowerSet(){
    return PowerSetR(*this);

}

//============================================================================
// Description:Recursive function will transform called MathSet object and format it to the Power set of the called set.
// Parameters: MathSet<T> inputSet - called object
// Return: MathSet<T>
// Notes: There is some issues with this code, at least wanted to start it to get some partial credit.
//============================================================================
template <class T>
MathSet<T> MathSet<T> ::PowerSetR(MathSet<T> inputSet){
    MathSet<T> set1;

    if(inputSet.empty()){
        set1.insert(set<T>().begin(), set<T>().end());
        return set1;
    }

     T value = *inputSet.begin();

    MathSet<T> remaining;
    remaining.insert(++inputSet.begin(), inputSet.end());

    MathSet<T> sub = PowerSetR(remaining);

    set1.insert(sub.begin(), sub.end());

    for(auto& subset : sub){
        sub.insert(value);
        set1.insert(sub);
    }

    return set1;
}



#endif

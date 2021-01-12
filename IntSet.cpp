#include <iostream>
#include <sstream>
#include <string>
#include "IntSet.h"

IntSet::IntSet(int a, int b, int c, int d, int e){
  data = new bool[MAXSETVAL + 1];

  for(int i = 0; i < MAXSETVAL + 1; i++){
    data[i] = false;
  }


  if(a != -1 && a >= 0 && a <=MAXSETVAL){
    data[a] = true;
  }
  if(b != -1 && b >= 0 && b <=MAXSETVAL){
    data[b] = true;
  }
  if(c != -1 && c >= 0 && c <=MAXSETVAL){
    data[c] = true;
  }
  if(d != -1 && d >= 0 && d <=MAXSETVAL){
    data[d] = true;
  }
  if(e != -1 && e >= 0 && e <=MAXSETVAL){
    data[e] = true;
  }

}


IntSet::~IntSet(){
  delete[]data;
  data = 0;

}


void IntSet::insertElement(int x){
  if(x >=0 && x <= MAXSETVAL)
    data[x] = true;

}


void IntSet::deleteElement(int x){
  if(x >=0 && x <= MAXSETVAL)
    data[x] = false;
}



std::string IntSet::toString() const{
  std::stringstream ss;
  for(int i = 0; i < MAXSETVAL + 1; i++){
    if(data[i] == true){
      // std::cout << "true: " << i << std::endl;                                                                                                                                                      
      ss << i << ", ";
    }
  }
  std::string toString = "{" + ss.str();
  toString.resize(toString.size() - 2);
  return toString + "}";
}

void IntSet::unionOf(IntSet& A, IntSet& B){
  for(int i = 0; i < MAXSETVAL + 1; i++){
    data[i] = false;
  }
  for(int i = 0; i < MAXSETVAL + 1; i++){
    if(A.data[i] == true || B.data[i] == true){
      data[i] = true;
    } else data[i] = false;

  }
}


void IntSet::intersectionOf(IntSet& A, IntSet& B){
  for(int i = 0; i < MAXSETVAL + 1; i++){
    data[i] = false;
  }
  for(int i = 0; i < MAXSETVAL + 1; i++){
    if(A.data[i] == true && B.data[i] == true){
      data[i] = true;
    } else data[i] = false;

  }


}



bool IntSet::equals(const IntSet& A) const{
  for(int i = 0; i < MAXSETVAL + 1; i++){
    if(data[i] != A.data[i]){
      return false;
    }

  }
  return true;
}



bool IntSet::hasElement(int x) const{
  if(x < 0 || x > 1000){
    return false;
  }
  if(data[x] == true)
    return true;
  return false;


}

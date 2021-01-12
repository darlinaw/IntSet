#ifndef IntSet__h
#define IntSet__h

#include <string>

class IntSet{
 public:
  IntSet(int =-1,int =-1, int =-1, int =-1, int =-1);
  ~IntSet();
  void insertElement(int);
  void deleteElement(int);
  std::string toString() const;
  void unionOf(IntSet &, IntSet &);
  void intersectionOf(IntSet &, IntSet &);
  bool equals(const IntSet &) const;
  bool hasElement(int) const;
  int static getMax(){ return MAXSETVAL; }
 private:
  static const int MAXSETVAL=1000; // largest legal value                                                                                                                                              
  bool *data; // array to store elements                                                                                                                                                               
};

#endif



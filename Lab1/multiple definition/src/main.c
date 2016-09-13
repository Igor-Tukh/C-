#include "../include/util.h"
#include "../include/io.h"
#include "../include/algorithm.h"

int max(int a, int b){
  if (a > b) return a;
  else return b;
}

int main() {
  int a = doComputation(5, 7.0); 
  int b = 5;
  max(a, b);
  logDebug('!');
  return 0;        
}

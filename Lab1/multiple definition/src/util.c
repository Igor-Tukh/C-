#include "../include/util.h"
#include "../include/io.h"
#include "../include/algorithm.h"

int max(int a, int b) {
  logDebug('m');
  if (a < b) return b;
  else return a;
}
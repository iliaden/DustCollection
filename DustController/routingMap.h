
#ifndef routing_map
#define routing_map

#include <SimpleVector.h>

// table saw
SimpleVector<int> tool0_gates;

// floor sweep
SimpleVector<int> tool1_gates;

// miter saw
SimpleVector<int> tool2_gates;

void setRoutes(){
  tool0_gates.put(0);
  tool0_gates.put(1);

  tool1_gates.put(2);

  tool2_gates.put(0);
  tool2_gates.put(3);
}


#endif

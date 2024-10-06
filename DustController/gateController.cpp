

#include "gateController.h"
#include "constants.h"


GateController::GateController(Vector<int> enabledGates){

  for (int servoIdx = 0 ; servoIdx < 12; servoIdx ++){
    bool isEnabled = false; 
    for(int enabled_idx = 0; enabled_idx < enabledGates.size(); enabled_idx++){
      if (enabledGates[enabled_idx] == servoIdx){
        isEnabled = true;
      }
    }

    if (isEnabled){
      Gate gateObj = Gate(
        servoPins[servoIdx], 
        servoLedPins[servoIdx], 
        servoMinValues[servoIdx],
        servoMaxValues[servoIdx]
        );  
    }  
  }
  
  // maybe find a cleaner way?
  Vector<int> vec_device0_open_gates;
  for (int x : device0_open_gates){
    vec_device0_open_gates.push_back(x);
  }
  toolRoutes.put(0, vec_device0_open_gates);

  Vector<int> vec_device1_open_gates;
  for (int x : device1_open_gates){
    vec_device1_open_gates.push_back(x);
  }
  toolRoutes.put(1, vec_device1_open_gates);

  Vector<int> vec_device2_open_gates;
  for (int x : device2_open_gates){
    vec_device2_open_gates.push_back(x);
  }
  toolRoutes.put(2, vec_device2_open_gates);

  Vector<int> vec_device3_open_gates;
  for (int x : device3_open_gates){
    vec_device3_open_gates.push_back(x);
  }
  toolRoutes.put(3, vec_device3_open_gates);

  Vector<int> vec_device4_open_gates;
  for (int x : device4_open_gates){
    vec_device4_open_gates.push_back(x);
  }
  toolRoutes.put(4, vec_device4_open_gates);

  Vector<int> vec_device5_open_gates;
  for (int x : device5_open_gates){
    vec_device5_open_gates.push_back(x);
  }
  toolRoutes.put(5, vec_device5_open_gates);


} // reads data from constants

void GateController::idle(){
  SimpleVector<int> keys = gates.keys(); // Get a vector of all the keys in the hashtable
  for (const int key : keys) { 
      Gate g = gates.getElement(key);
      g.disconnect();
  }
}

void GateController::routeForTool(int toolId){
  SimpleVector<int> keys = gates.keys(); // Get a vector of all the keys in the hashtable
  for (const int key : keys) { 
      Gate g = gates.getElement(key);
      g.connect();
      g.close();
  }
  //sleep for 0.3s before sending new signal
  delay(0.3);

  Vector<int> gatesToOpen = toolRoutes.getElement(toolId);
  for (const int gateId : gatesToOpen){
    Gate g = gates.getElement(gateId);
      g.connect();
      g.open();
  }
}

// Hashtable<int, Gate> gates;
// Hashtable<int, Vector<int>> toolRoutes; //tool -> set of gates that must be open for the tool

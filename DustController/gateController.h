#ifndef gate_controller_def
#define gate_controller_def

#include "gate.h"
#include <Vector.h>
#include <Hashtable.h>

class GateController {
  public:
    GateController(Vector<int> enabledGates); // reads data from constants

    void idle();
    void routeForTool(int toolId);

  private:
    Hashtable<int, Gate> gates;
    Hashtable<int, Vector<int>> toolRoutes; //tool -> set of gates that must be open for the tool
};

#endif
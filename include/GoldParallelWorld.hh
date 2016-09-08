#ifndef GOLDPARALLELWORLD_HH
#define GOLDPARALLELWORLD_HH

#include "globals.hh"
#include "G4VUserParallelWorld.hh"
#include "CLHEP/Units/SystemOfUnits.h"

using namespace CLHEP;

class GoldParallelWorld : public G4VUserParallelWorld
{
public:
    GoldParallelWorld(G4String worldName);
    ~GoldParallelWorld();

    void Construct();
    void ConstructSD();

private:
    G4LogicalVolume *CocentrSphereLog;
};

#endif // GOLDPARALLELWORLD_HH

#include "GoldParallelWorld.hh"
#include "GoldSphereParameterisation.hh"

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4Tubs.hh"
#include "G4PVReplica.hh"
#include "G4VisAttributes.hh"
#include "G4SDManager.hh"
#include "G4PVDivision.hh"
#include "G4PVParameterised.hh"
#include "G4PSDoseDeposit3D.hh"

GoldParallelWorld::GoldParallelWorld(G4String worldName)
    :G4VUserParallelWorld(worldName)
{}

GoldParallelWorld::~GoldParallelWorld()
{}

void GoldParallelWorld::Construct()
{
    G4VPhysicalVolume *ghostWorld = GetWorld();
    G4LogicalVolume *worldLog = ghostWorld->GetLogicalVolume();

    // Place volumes in the parallel world here
    G4double nDivisions = 100.0;

    G4Sphere *outerSphere = new G4Sphere("OuterSphere", 0, 1000*nm, 0*rad, 2.*M_PI*rad, 0.0*rad, 1.*M_PI*rad);
    G4LogicalVolume *outerSphereLog = new G4LogicalVolume(outerSphere, 0, "OuterSphereLog");
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0), outerSphereLog, "OuterSpherePhys", worldLog, 0, 0);

    G4VSolid *cocentrSphere  = new G4Sphere("CocentrSphere", 0, 1000*nm, 0*rad, 2.*M_PI*rad, 0.0*rad, 1.*M_PI*rad);
    CocentrSphereLog = new G4LogicalVolume(cocentrSphere, 0, "CocentrSphereLog");
    G4VPVParameterisation* sphereParam = new GoldSphereParameterisation;
    new G4PVParameterised("Spheres", CocentrSphereLog, outerSphereLog, kUndefined, 100, sphereParam);

    G4VisAttributes* visAttributes = new G4VisAttributes;
    visAttributes->SetColor(0,1,1);
    visAttributes->SetForceAuxEdgeVisible(true);
    CocentrSphereLog->SetVisAttributes(visAttributes);
}

void GoldParallelWorld::ConstructSD()
{
    G4SDManager::GetSDMpointer()->SetVerboseLevel(1);
    G4MultiFunctionalDetector* detector = new G4MultiFunctionalDetector("Detector");
    G4VPrimitiveScorer* doseSD = new G4PSDoseDeposit("Dose");
   // doseSD->SetUnit("MeV/g");
    detector->RegisterPrimitive(doseSD);
    G4cout << "DOSE SCORER " << doseSD->GetUnit() << G4endl;
    SetSensitiveDetector(CocentrSphereLog, detector);
}

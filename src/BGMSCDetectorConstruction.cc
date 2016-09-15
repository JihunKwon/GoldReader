#include "BGMSCDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4NistManager.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RunManager.hh"
#include "G4VSolid.hh"
#include "G4Sphere.hh"

using namespace CLHEP;

BGMSCDetectorConstruction::BGMSCDetectorConstruction()
{}

G4VPhysicalVolume* BGMSCDetectorConstruction::Construct()
{
    // Cleanup old geometry
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();

    G4VisAttributes* visAttributes = new G4VisAttributes;
    visAttributes->SetForceWireframe(true);
    visAttributes->SetForceAuxEdgeVisible(true);

    G4NistManager* nistManager = G4NistManager::Instance();
//    G4Material* Au = nistManager->FindOrBuildMaterial("G4_Au");
    G4Material* Water = nistManager->FindOrBuildMaterial("G4_WATER");
//    G4Material* vacuum = nistManager->FindOrBuildMaterial("G4_Galactic");

    // World
    G4Box* world = new G4Box("World", 1*um, 1*um, 1*um);
    G4LogicalVolume *worldLogic = new G4LogicalVolume(world, Water, "WorldLogic");
    G4VPhysicalVolume *worldPhys = new G4PVPlacement(0, G4ThreeVector(), worldLogic, "WorldPhys", 0, false, 0);
    worldLogic->SetVisAttributes(visAttributes);

//    G4Sphere *nanoPart = new G4Sphere("NanoPart", 0, 10*nm, 0*rad, 360*deg, 0.0*rad, 180*deg);
//    G4LogicalVolume *nanoPartLogic = new G4LogicalVolume(nanoPart, Au, "NanoPartLogic");
//    G4VPhysicalVolume *nanoPartPhys = new G4PVPlacement(0, G4ThreeVector(0, 0, 0), nanoPartLogic, "NanoPartPhys", worldLogic, 0, 0);
//    nanoPartLogic->SetVisAttributes(visAttributes);


    return worldPhys;
}

#include "GoldRunAction.hh"
#include "GoldRun.hh"

#include "G4RunManager.hh"
#include "BGMSCDetectorConstruction.hh"
#include "G4THitsMap.hh"
#include "G4SDManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Run.hh"
#include "G4HadronicInteraction.hh"
#include "G4HadronicInteractionRegistry.hh"
#include "G4CascadeInterface.hh"
#include "G4BinaryCascade.hh"
#include "G4AblaInterface.hh"
#include "G4INCLXXInterface.hh"
#include "G4INCLXXInterfaceStore.hh"
#include "G4FermiBreakUp.hh"
#include "G4NistManager.hh"
#include "G4Evaporation.hh"

#include <fstream>
#define _USE_MATH_DEFINES

GoldRunAction::GoldRunAction(const G4String detectorName) : G4UserRunAction()
{
    DetectorName = detectorName;
}

GoldRunAction::~GoldRunAction()
{}

G4Run* GoldRunAction::GenerateRun()
{
    return new GoldRun(DetectorName, 0);
}

void GoldRunAction::BeginOfRunAction(const G4Run* aRun)
{}

void GoldRunAction::EndOfRunAction(const G4Run* aRun)
{
    if(!IsMaster()) return;

    GoldRun* goldRun = (GoldRun*)aRun;
    Cells = goldRun->GetCells();

    std::ofstream GoldFile("Gold_DoseDistribution.txt");

    for (int j = 0; j < 100; j++)
    {
        GoldFile << j << " " << Cells[j]*6.24*pow(10,9)/10000000 << "\n";
    }
}

#include "BGMSCPrimaryGeneratorAction.hh"
#include "BGMSCActionInitialization.hh"
#include "GoldRunAction.hh"

BGMSCActionInitialization::BGMSCActionInitialization(BGMSCDetectorConstruction *geometry)
    : G4VUserActionInitialization()
{}

BGMSCActionInitialization::~BGMSCActionInitialization()
{}

void BGMSCActionInitialization::BuildForMaster() const
{
    SetUserAction(new GoldRunAction("Detector"));
}

void BGMSCActionInitialization::Build() const
{
    SetUserAction(new BGMSCPrimaryGeneratorAction);
    SetUserAction(new GoldRunAction("Detector"));
}

#include "BGMSCPrimaryGeneratorAction.hh"
#include "BGMSCActionInitialization.hh"

BGMSCActionInitialization::BGMSCActionInitialization(BGMSCDetectorConstruction *geometry)
    : G4VUserActionInitialization()
{}

BGMSCActionInitialization::~BGMSCActionInitialization()
{}

void BGMSCActionInitialization::BuildForMaster() const
{}

void BGMSCActionInitialization::Build() const
{
    SetUserAction(new BGMSCPrimaryGeneratorAction);
}

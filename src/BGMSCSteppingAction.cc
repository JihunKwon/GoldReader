#include "BGMSCSteppingAction.hh"

#include "G4Track.hh"
#include "G4TrackStatus.hh"
#include "G4CsvAnalysisManager.hh"
#include "G4ThreeVector.hh"

void BGMSCSteppingAction::UserSteppingAction(const G4Step* aStep)
{
    //kill particle
    G4double time = aStep->GetPostStepPoint()->GetGlobalTime();
    if(time>=100*ns){
        G4Track * aTrack = aStep->GetTrack();
        aTrack->SetTrackStatus(fStopAndKill); }
}



#include "GoldRun.hh"
#include "G4SDManager.hh"
#include "G4THitsMap.hh"

GoldRun::GoldRun(const G4String detectorName, G4bool verbose) : G4Run()
{
    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    G4VSensitiveDetector* detector = SDman->FindSensitiveDetector(detectorName);

    CollName = detector->GetCollectionName(0);
    CollectionID = SDman->GetCollectionID(CollName);
    Verbose = verbose;

    Cells = new G4double[989];
    for (int i = 0; i < 989; i++)
    {
        Cells[i] = 0;
    }
}

GoldRun::~GoldRun() {}

void GoldRun::RecordEvent(const G4Event* aEvent)
{
    numberOfEvent++;

    G4HCofThisEvent* HCE = aEvent->GetHCofThisEvent();
    if(HCE!=NULL)
    {
        G4THitsMap<G4double>* HC = static_cast<G4THitsMap<G4double>*>(HCE -> GetHC(CollectionID));
        G4int i = 0;
        if(HC!=NULL)
        {
            std::map<G4int, G4double*>::iterator it;
            for ( it = HC->GetMap()->begin(); it != HC->GetMap()->end(); it++)
            {
                i = it->first;
                Cells[i] += (*(it->second))/CLHEP::gray;
            }
        }
    }
}

void GoldRun::Merge(const G4Run * aRun)
{
    const GoldRun *localRun = static_cast<const GoldRun*>(aRun);

    for (G4int i = 0; i < 989; i++)
        Cells[i] += localRun->Cells[i];
    G4Run::Merge(aRun);
}


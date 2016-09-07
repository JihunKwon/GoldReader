#include "BGMSCPrimaryGeneratorAction.hh"

#include "G4Proton.hh"
#include "G4Gamma.hh"

using namespace CLHEP;

BGMSCPrimaryGeneratorAction::BGMSCPrimaryGeneratorAction()
{
    G4String fileName = "PSF_-200";
    IAEAReader = new G4IAEAphspReader(fileName);

    G4ThreeVector isoPos(0., 0., 0.);
    IAEAReader->SetIsocenterPosition(isoPos);
    IAEAReader->SetTimesRecycled(0);
}

BGMSCPrimaryGeneratorAction::~BGMSCPrimaryGeneratorAction()
{
    if (IAEAReader)
        delete IAEAReader;
}

void BGMSCPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
    IAEAReader->GeneratePrimaryVertex(event);
    G4int num = IAEAReader->GetUsedOriginalParticles();
    std::vector<G4int>* type = IAEAReader->GetParticleTypeVector();
    std::vector<G4ThreeVector>* momentum = IAEAReader->GetMomentumVector();
    std::vector<G4ThreeVector>* pos = IAEAReader->GetPositionVector();
    G4long total = IAEAReader->GetTotalParticles();
    G4cout << (*type)[0] << G4endl;
    std::vector<G4double>* energy = IAEAReader->GetEnergyVector();
}

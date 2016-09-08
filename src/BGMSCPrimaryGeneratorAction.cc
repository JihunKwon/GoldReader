#include "BGMSCPrimaryGeneratorAction.hh"

#include "G4Proton.hh"
#include "G4Gamma.hh"

using namespace CLHEP;

BGMSCPrimaryGeneratorAction::BGMSCPrimaryGeneratorAction()
{
//        Source = new G4ParticleGun;
//        Source->SetParticleDefinition(G4Proton::Definition());
//        Source->SetParticleEnergy(158.6*MeV);
//        Source->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
//        Source->SetParticlePosition(G4ThreeVector(0,0,-2*mm));

    G4String fileName = "PSF_1e-05";
    IAEAReader = new G4IAEAphspReader(fileName);

    G4ThreeVector isoPos(0., 0., 0.);
    IAEAReader->SetIsocenterPosition(isoPos);
    IAEAReader->SetTimesRecycled(0);
}

BGMSCPrimaryGeneratorAction::~BGMSCPrimaryGeneratorAction()
{
   //     delete Source;
    if (IAEAReader)
        delete IAEAReader;
}

void BGMSCPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
   //     Source->GeneratePrimaryVertex(event);
    IAEAReader->GeneratePrimaryVertex(event);
//    G4int num = IAEAReader->GetUsedOriginalParticles();
//    std::vector<G4int>* type = IAEAReader->GetParticleTypeVector();
//    std::vector<G4ThreeVector>* momentum = IAEAReader->GetMomentumVector();
//    std::vector<G4ThreeVector>* pos = IAEAReader->GetPositionVector();
//    G4long total = IAEAReader->GetTotalParticles();
//    // G4cout << (*type)[0] << G4endl;
//    std::vector<G4double>* energy = IAEAReader->GetEnergyVector();
}

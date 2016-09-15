#include "BGMSCPrimaryGeneratorAction.hh"

#include "G4Proton.hh"
#include "G4Gamma.hh"

using namespace CLHEP;

BGMSCPrimaryGeneratorAction::BGMSCPrimaryGeneratorAction()
{
            Source = new G4ParticleGun;
            Source->SetParticleDefinition(G4Proton::Definition());
            Source->SetParticleEnergy(158.6*MeV);
            Source->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
            Source->SetParticlePosition(G4ThreeVector(0,0,-2*mm));

//    G4String fileName = "PSF_1e-05";
//    IAEAReader = new G4IAEAphspReader(fileName);

//    G4ThreeVector isoPos(0., 0., 0.);
//    IAEAReader->SetIsocenterPosition(isoPos);
//    IAEAReader->SetTimesRecycled(0);
}

BGMSCPrimaryGeneratorAction::~BGMSCPrimaryGeneratorAction()
{
         delete Source;
//    if (IAEAReader)
//        delete IAEAReader;
}

void BGMSCPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
//    for (G4int i; i < 1000; i++)
//    {
            Source->GeneratePrimaryVertex(event);
//        IAEAReader->GeneratePrimaryVertex(event);
//        G4int num = IAEAReader->GetUsedOriginalParticles();
//        //    std::vector<G4int>* type = IAEAReader->GetParticleTypeVector();
//        std::vector<G4ThreeVector>* momentum = IAEAReader->GetMomentumVector();
//        std::vector<G4ThreeVector>* pos = IAEAReader->GetPositionVector();
//        G4ThreeVector position = (*pos)[0];
//        G4cout << "Radius is " << sqrt((pow(position.x(),2)+pow(position.y(),2)+pow(position.z(),2)))/nm << G4endl;
//        G4long total = IAEAReader->GetTotalParticles();
//        std::vector<G4double>* energy = IAEAReader->GetEnergyVector();

//        std::ofstream outfile;
//        outfile.open("Gold_Position.txt", std::ios_base::app);
//        outfile << position.x()/nm << " " << position.y()/nm << " " << position.z()/nm << "\n";
//    }
}

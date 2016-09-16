#ifndef GOLDSPHEREPARAMETERISATION_HH
#define GOLDSPHEREPARAMETERISATION_HH

#include "G4VPVParameterisation.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Sphere.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

class GoldSphereParameterisation : public G4VPVParameterisation
{
public:
    GoldSphereParameterisation() {}
    virtual ~GoldSphereParameterisation(){}

    void ComputeDimensions (G4Sphere& sphere, const G4int copyNo, const G4VPhysicalVolume* physVol) const
    {
        G4double step = 0;
        if (copyNo <= 99)
        {
            step = 1.0*nm;
        }
        else if (copyNo > 99)
        {
            step = 10.0*nm;
        }
        G4cout << (20*nm + 100*1*nm + step*(copyNo-100))/nm << G4endl;
        G4cout << (20*nm + 100*1*nm + step*(copyNo-99))/nm << G4endl;
        sphere.SetInnerRadius(20*nm + 100*1*nm + step*(copyNo-100));
        sphere.SetOuterRadius(20*nm + 100*1*nm + step*(copyNo-99));
    }

    virtual void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume *physVol ) const
    {}
};

#endif // GOLDSPHEREPARAMETERISATION_HH

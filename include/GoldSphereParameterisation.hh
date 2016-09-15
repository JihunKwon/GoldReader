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
        G4double step = 10.0*nm;
        sphere.SetInnerRadius(step*copyNo);
        sphere.SetOuterRadius(step*(copyNo+1));
    }

    virtual void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume *physVol ) const
    {}
};

#endif // GOLDSPHEREPARAMETERISATION_HH

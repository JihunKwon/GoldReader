#ifndef GOLDDETECTORSD_HH
#define GOLDDETECTORSD_HH

#include "G4UserRunAction.hh"
#include "globals.hh"
#include <vector>

class GoldRunAction : public G4UserRunAction
{
public:

    GoldRunAction(const G4String detectorName);
    virtual ~GoldRunAction();

    virtual G4Run* GenerateRun();
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);

private:
    G4String DetectorName;
    G4double* Cells;
};

#endif // GOLDDETECTORSD_HH

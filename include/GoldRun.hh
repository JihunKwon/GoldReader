#ifndef GOLDRUN_HH
#define GOLDRUN_HH

#include "G4Run.hh"
#include "G4Event.hh"

#include <vector>

class GoldRun : public G4Run
{
public:

  GoldRun(const G4String detectorName, G4bool verbose);
  virtual ~GoldRun();

  // virtual method from G4Run.
  // The method is overriden in this class for scoring.
  virtual void RecordEvent(const G4Event*);
  virtual void Merge(const G4Run*);

  G4double* GetCells() { return Cells; }

private:
  G4String CollName;
  G4int CollectionID;
  G4bool Verbose;
  G4double* Cells;
};

#endif // GOLDRUN_HH

#undef G4MULTITHREADED
#undef G4VIS_USE

#include <cstdio>
#include <ctime>

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#include "G4UImanager.hh"
#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

#include "BGMSCPhysicsList.hh"
#include "BGMSCDetectorConstruction.hh"
#include "BGMSCPrimaryGeneratorAction.hh"
#include "BGMSCActionInitialization.hh"
#include "GoldParallelWorld.hh"
#include "G4GeometryTolerance.hh"
#include "G4GeometryManager.hh"

#include "G4CsvAnalysisManager.hh"

#include <math.h>

int main(int argc,char** argv)
{
    // Set the custom seed for the random engine
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    G4long seed = time(NULL);
    G4Random::setTheSeed(seed);

#ifdef G4MULTITHREADED
    G4MTRunManager* runManager = new G4MTRunManager;
    runManager->SetNumberOfThreads(8);
#else
    G4RunManager* runManager = new G4RunManager;
#endif

    G4GeometryManager::GetInstance()->SetWorldMaximumExtent(1000*nm);

    BGMSCDetectorConstruction* massWorld = new BGMSCDetectorConstruction;
    massWorld->RegisterParallelWorld(new GoldParallelWorld("GoldParallelWorld"));
    runManager->SetUserInitialization(massWorld);

    G4VModularPhysicsList* physicsList = new BGMSCPhysicsList;
    physicsList->SetVerboseLevel(0);
    runManager->SetUserInitialization(physicsList);

    BGMSCActionInitialization* actionInit = new BGMSCActionInitialization(massWorld);
    runManager->SetUserInitialization(actionInit);
    runManager->Initialize();

    G4UImanager* UImanager = G4UImanager::GetUIpointer();

#ifdef G4VIS_USE
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
    delete visManager;

#endif


    std::cout << G4GeometryTolerance::GetInstance()->GetRadialTolerance()/nm << std::endl;
    std::cout << G4GeometryTolerance::GetInstance()->GetSurfaceTolerance()/nm << std::endl;

    runManager->BeamOn(1000);

    delete runManager;
    return 0;
}

AliAnalysisTask *AddTask_tracklets_aschmah(Int_t trigger = 0) {
    AlInfo("Starting...");

    // get the current analysis manager
    AliAnalysisManager *mgr = AliAnalysisManager::GetAnalysisManager();
    if (!mgr) {
        Error("AddTask_tracklets_aschmah", "No analysis manager found.");
        return 0;
    }

    // Add task to the Analysis Manager
    Ali_make_tracklets_from_digits *task = new Ali_make_tracklets_from_digits("DigitsTask");
    mgr->AddTask(task);

    TString outputFileName = AliAnalysisManager::GetCommonFileName();
    outputFileName += ":TRD_analysis_hists";
    AliInfoF("outputFileName   = %s", outputFileName.Data());

    TString outputFileName_B = AliAnalysisManager::GetCommonFileName();
    outputFileName_B += ":EventsAndTracks";
    AliInfoF("outputFileName_B = %s", outputFileName_B.Data());

    TString containerName = "TRD_Digits_output";

    TString results = "AnalysisResults.root";

    AliAnalysisDataContainer *coutput1 =
        mgr->CreateContainer(containerName, TList::Class(), AliAnalysisManager::kOutputContainer, results.Data());
    AliAnalysisDataContainer *coutput2 =
        mgr->CreateContainer("events", TTree::Class(), AliAnalysisManager::kOutputContainer, results.Data());

    mgr->ConnectInput(task, 0, mgr->GetCommonInputContainer());
    mgr->ConnectOutput(task, 1, coutput1);  // TList
    mgr->ConnectOutput(task, 2, coutput2);  // TTree

    AlInfo("Finished.");

    return task;
}

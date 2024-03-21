#ifndef KFVERIFIER_H
#define KFVERIFIER_H

#include "kfverifier_global.h"
#include <ATGUI/APlugin.h>
#include <ATProject/ADocumentRef.h>

class ATaskExecutionWindow;
class KFVERIFIERSHARED_EXPORT KFVerifier : public AUtilityPlugin
{

public:
    KFVerifier();
    ~KFVerifier();

public:
    int executeTask(ATaskExecutionWindow *wnd, const std::string &cmd_id, const std::vector<ADocumentRef *> &input_docs, const std::vector<ADocumentRef *> &out_docs, APlanTask* current_task);
    // AUtilityPlugin interface;

public:
    const std::vector<std::string> getCommands();
    AError executeCommand(const std::string &script, std::string &answer);
    ADocumentRef* kf_fragments;
    ADocumentRef* verified_fragments;
    ADocumentRef* kb_doc;

};

#endif // KFVERIFIER_H

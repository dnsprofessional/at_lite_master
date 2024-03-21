#ifndef KMPZ_H
#define KMPZ_H

#include "kmpz_global.h"
#include "YOSDIInterpreter/YOSDIInterpreter.h"

#include <ATGUI/APlugin.h>
#include <QDebug>
#include <QDir>

class ATaskExecutionWindow;

class KMPZ_EXPORT ATKMPZPlugin : public AUtilityPlugin, public QObject
{
public:
	ATKMPZPlugin();
	~ATKMPZPlugin();

    virtual const std::vector<std::string> getCommands() override;
    virtual AError executeCommand(const std::string& script, std::string& answer) override;
    virtual int executeTask(ATaskExecutionWindow* wnd, const std::string& cmd_id, const std::vector<ADocumentRef*>& input_docs, const std::vector<ADocumentRef*>& out_docs, APlanTask* current_task) override;

private:
    std::unique_ptr<YOSDIInterpreter> _interpreter;
    ADocumentRef* kf_fragments;

public slots:
    void savePZToFile();
};

#endif // KMPZ_H

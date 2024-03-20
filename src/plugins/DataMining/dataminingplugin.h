#ifndef DATAMININGPLUGIN_H
#define DATAMININGPLUGIN_H

#include <QtCore/qglobal.h>
#include <ATGUI/APlugin.h>

class ATaskExecutionWindow;
class Q_DECL_EXPORT DataMiningPlugin : public AUtilityPlugin
{
public:
    DataMiningPlugin();
    ~DataMiningPlugin();

public:

    virtual int executeTask(ATaskExecutionWindow * wnd, const std::string & cmd_id, const std::vector<ADocumentRef*> & input_docs, const std::vector<ADocumentRef*> & out_docs, APlanTask* current_task) override;
    //virtual int executeTask(ATaskExecutionWindow * wnd, const std::string & cmd_id, const std::vector<ADocumentRef*> & input_docs, const std::vector<ADocumentRef*> & out_docs, APlanTask* current_task) override;

    virtual const std::vector<std::string> getCommands();
    virtual AError executeCommand(const std::string & script, std::string & answer);
};

#endif

#include "kmpz.h"

#include "forms/common/task_type_definition_form.h"

#include <ATProject/ADocumentRef.h>
#include <ATCore/check.h>

#include <QLabel>
#include <QFile>
#include <QObject>
#include <ATCore/utils/xml_helpers.h>
#include <ATCore/utils/helpers.h>
#include <QDateTime>
#include <QDebug>

APlugin * AT_CREATE_PLUGIN_FN()
{
	return new ATKMPZPlugin();
}

ATKMPZPlugin::ATKMPZPlugin()
	:AUtilityPlugin("KMPZ", "Combined Method For knowledge Acquisition")
{

}
/*
int main()
{
	return 0;
}*/

ATKMPZPlugin::~ATKMPZPlugin()
{
    delete this;
}

const std::vector<std::string> ATKMPZPlugin::getCommands()
{
	std::vector<std::string> res;
	res.push_back("acquire_expert");
	res.push_back("acquire_database");
	return std::move(res);
}

AError ATKMPZPlugin::executeCommand(const std::string&, std::string&)
{
	return AError();
}

void ATKMPZPlugin::savePZToFile() {
    std::string kf_xml = this->_interpreter->_PZCreator->_knowledgeField.to_xml("Результат интервью " + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss").toStdString(), true);

    xmlDoc * kf_doc = xmlReadFile(this->kf_fragments->absolutePath().toStdString().c_str(), 0, 0);
    xmlNode all_fragments = kf_doc->children[0];
    xmlDoc * new_fragment_doc = xmlReadMemory(kf_xml.data(), kf_xml.size(), 0, 0, 0);
    xmlNode new_fragment = new_fragment_doc->children[0];
    xmlAddChild(&all_fragments, &new_fragment);
    kf_doc->children[0] = all_fragments;
    xmlChar *s;
    int size;
    std::string out;
    xmlDocDumpMemory(kf_doc, &s, &size);
    if (s == nullptr)
        throw std::bad_alloc();
    try {
        out = (char *)s;
    } catch (...) {
        xmlFree(s);
        throw;
    }
    xmlFree(s);
    qDebug() << QString::fromStdString(out);
    QFile * file = new QFile(kf_fragments->absolutePath());
    if (file->open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream stream(file);
        stream << QString::fromStdString(out) << endl;
        file->flush();
        file->close();
    }
}

int ATKMPZPlugin::executeTask(ATaskExecutionWindow * wnd, const std::string&, const std::vector<ADocumentRef*>& input_docs, const std::vector<ADocumentRef*>&, APlanTask* current_task)
{
    ADocumentRef* kf_fragments = input_docs[0];
    this->kf_fragments = kf_fragments;
    if (!QFile::exists(kf_fragments->absolutePath())) {
        QFile * file = new QFile(kf_fragments->absolutePath());
        if (file->open(QIODevice::ReadWrite)) {
            QTextStream stream(file);
            stream << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<KnowledgeFieldsFragments></KnowledgeFieldsFragments>" << endl;
            file->flush();
            file->close();
        }
    }
    YOSDIInterpreter *interp = new YOSDIInterpreter(wnd);
    _interpreter.reset( interp );
    QObject::connect(wnd, &ATaskExecutionWindow::commitTask, this, &ATKMPZPlugin::savePZToFile);

    //for (auto doc : out_docs)
    //{
    //	auto path = doc->absolutePath();
    //	QFile file(path);
    //	bool r = file.open(QIODevice::WriteOnly);
    //	perform_check(r);
    //}

	return 0;
}


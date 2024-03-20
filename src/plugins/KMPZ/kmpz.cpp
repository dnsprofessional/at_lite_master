#include "kmpz.h"

#include "forms/common/task_type_definition_form.h"

#include <ATProject/ADocumentRef.h>
#include <ATCore/check.h>

#include <QLabel>
#include <QFile>
#include <QObject>

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
        qDebug() << "CWD: " << QDir::currentPath() << "\n\n";
        std::string xml = this->_interpreter->_PZCreator->_knowledgeField.to_xml();
        qDebug() << "PZ" << QString::fromStdString(xml) << "\n\n";
//        QFile *f = new QFile();
//        std::string xml = this->_interpreter->_PZCreator->_knowledgeField.to_xml();
//        f->open(QFile::WriteOnly);
    }

int ATKMPZPlugin::executeTask(ATaskExecutionWindow * wnd, const std::string&, const std::vector<ADocumentRef*>& input_docs, const std::vector<ADocumentRef*>&)
{
    this->docs = input_docs;
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


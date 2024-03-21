
#include "kfverifier.h"
#include "mainwidget.h"
#include <ATGUI/ATaskExecutionWindow.h>
#include <ATProject/ADocumentRef.h>
#include <ATCore/check.h>

#include <QLabel>
#include <QFile>
#include <QTextStream>

APlugin * AT_CREATE_PLUGIN_FN()
{    return new KFVerifier();
}

KFVerifier::KFVerifier()
    :AUtilityPlugin("KFVerifier", "test_kfverifier")
{

}

int KFVerifier::executeTask(ATaskExecutionWindow * wnd, const std::string&, const std::vector<ADocumentRef*>& input_docs, const std::vector<ADocumentRef*>& out_docs, APlanTask* current_task) {
  kf_fragments = input_docs[0];
  verified_fragments = out_docs[1];
  kb_doc = out_docs[0];

  auto dialog = new MainWidget(wnd, kf_fragments);
  dialog->kf_fragments = kf_fragments;
  dialog->verified_fragments = verified_fragments;
  dialog->kb_doc = kb_doc;

  if (!QFile::exists(kf_fragments->absolutePath())) {
      QFile * file = new QFile(kf_fragments->absolutePath());
      if (file->open(QIODevice::ReadWrite)) {
          QTextStream stream(file);
          stream << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<KnowledgeFieldsFragments></KnowledgeFieldsFragments>" << endl;
          file->flush();
          file->close();
      }
  }

  if (!QFile::exists(verified_fragments->absolutePath())) {
      QFile * file = new QFile(verified_fragments->absolutePath());
      if (file->open(QIODevice::ReadWrite)) {
          QTextStream stream(file);
          stream << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<VerifiedFragments></VerifiedFragments>" << endl;
          file->flush();
          file->close();
      }
  }


  wnd->setCentralWidget(dialog);


  //dialog->outFName = out_docs[0]->absolutePath().toStdString();

  return 0;
}

const std::vector<std::string> KFVerifier::getCommands() {
  std::vector<std::string> res;
  return res;
}

AError KFVerifier::executeCommand(const std::string&, std::string&) {
  return AError();
}

KFVerifier::~KFVerifier()
{
    delete this;
}

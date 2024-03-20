#ifndef PZ_CREATOR_H
#define PZ_CREATOR_H

#include "condition_stack.h"
#include "../atn/atn.h"

//#include "../libs/KnowledgeField/knowledge_field_t.h"
#include "../../../libs/KnowledgeField/knowledge_field_t.h"

#include <memory>
#include <QDir>

typedef std::pair<std::vector<std::string>, std::vector<std::string>> branch_t;

class PZCreator
{
public:
	PZCreator();
    void addNonFactor(vector<string> *negfactorLexemes);
	void addQuestionAndAnswer(const std::string& question, const std::string& answer);
	void addAnswer(const std::string& answer);
	void removeQuestion();
	void addRule();
    const branch_t& getLastBranch() const;
    void removeBranchConclusions();
	std::string getBZ();
	std::string getBZXml();
//	void PZCreator::writeToFile();
    void writeToFile();

	void addConclusion(const std::string& conclusion);

	const QuestionAnswerStack::Condition& getLastQuestion() const;
	const std::vector<std::string> getLastAnswers() const;
	bool hasQuestions() const;

    knowledge_field_t _knowledgeField;

private:
	complex_condition_t* getCurrentCondition();

    vector<temporal_entity_t*>* addTemporal(vector<string> *tempLexemes, vector<string> *tempObjects);
    void addNegFactor(vector<string> *negfactorLexemes);
//	std::string PZCreator::getSymptom(const vector<string>& tempLexemes, const std::string& answer);
    std::string getSymptom(const vector<string>& tempLexemes, const std::string& answer);

	int addAttributeToMainObject(const std::string& attrType);
	int mainObjectId() const;

	QString ru(const char * text);

private:
	ATN _atn;
	QuestionAnswerStack _questionAnswerStack;
	std::vector<std::string> _conclusions;
    std::vector<std::string> _last_branch_conclusions;

	std::map<int, std::vector<string>> _tempObjects;

	std::string _lastQuestion;

	const std::string _mainObjectName = "Пациент";

	int _conclusionAttributeId;
	int _eventAttributeId;
	//int _durationAttributeId;
	//int _periodAttributeId;

	size_t _nAttributes = 1;
	size_t _nRules = 1;
	size_t _nEvents = 0;
	size_t _nIntervals = 0;

    QString _outPath;
    std::string _bzPath;
};

#endif // PZ_CREATOR_H

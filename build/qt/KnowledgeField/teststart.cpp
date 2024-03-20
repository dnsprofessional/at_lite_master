#include "teststart.h"
#include "ui_teststart.h"

TestStart::TestStart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestStart)
{
    ui->setupUi(this);
}

TestStart::~TestStart()
{
    delete ui;
}

alertshow* TestStart::on_pushButton_clicked()
{
    alertshow* al = new alertshow(nullptr);
    al->show();
    al->set_m_pre(QString("Symptom: Острая сердечная боль началась\nTempLexems: 1 неделю назад\nSymptom: Повышенная температура тела\nTempLexems: в течение последних 5 дней\nSymptom: Я болел гриппом\nTempLexems: 1 месяц назад\n"));
    al->set_ss_pre(QString("Point: 1 неделю назад\nInterval: в течение последних 5 дней\nPoint: 1 месяц назад"));
    al->set_si_pre(QString("Событие 1\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут1=1 неделю назад\n\nИнтервал 2\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут2=в течение последних 5 дней\n\nСобытие 3\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут3=1 месяц назад\n\n"));
    al->set_m_act(QString("Symptom: Острая сердечная боль началась\nTempLexems: 1 неделю назад\nSymptom: Повышенная температура тела в течение последних\nTempLexems: 5 дней\nSymptom: Я болел гриппом\nTempLexems: 1 месяц назад\n"));
    al->set_ss_act(QString("Point: 1 неделю назад\nPoint: 5 дней\nPoint: 1 месяц назад"));
    al->set_si_act(QString("Событие 1\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут1=1 неделю назад\n\nСобытие 2\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут2=5 дней\n\nСобытие 3\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут3=1 месяц назад\n\n"));
    return al;
}

alertshow* TestStart::on_pushButton_2_clicked()
{
    alertshow* al = new alertshow(nullptr);
    al->show();
    al->set_m_pre(QString("Symptom: Пульсирующая и давящая головная боль, первое проявление было\nTempLexems: 10 сентября\nSymptom: Повышенное артериальное давление\nTempLexems: с 7 до 8 часов утра\nSymptom: Общая слабость наблюдается\nTempLexems: с 22 марта\n"));
    al->set_ss_pre(QString("Point: 10 сентября\nInterval: с 7 до 8 часов утра\nPoint: с 22 марта"));
    al->set_si_pre(QString("Событие 1\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут1=10 сентября\n\nИнтервал\n   	АТРИБУТ 'УслНач'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут2=с 7 часов утра\n   	АТРИБУТ 'УслОконч'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут2=до 8 часов утра\n\nСобытие 2\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут3=с 22 марта\n\n"));
    al->set_m_act(QString("Symptom: Пульсирующая и давящая головная боль, первое проявление было\nTempLexems: 10 сентября\nSymptom: Повышенное артериальное давление\nTempLexems: с 7 до 8 часов утра\nSymptom: Общая слабость наблюдается\nTempLexems: с 22 марта\n"));
    al->set_ss_act(QString("Point: 10 сентября\nInterval: start: с 7  end: до 8\nPoint: час\nPoint: утро\nPoint: с 22 марта"));
    al->set_si_act(QString("Событие 1\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут1=10 сентября\n\nИнтервал\n   	АТРИБУТ 'УслНач'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут2=с 7\n   	АТРИБУТ 'УслОконч'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут2=до 8\n\nСобытие 2\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут1=час\n\nСобытие 3\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут1=утро\n\nСобытие 4\n   	АТРИБУТ 'УслВозн'\n   	ТИП 'логвыр'\n   	Пациент.Атрибут3=с 22 марта\n\n"));
    return al;
}

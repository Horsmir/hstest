#ifndef hstester_client_H
#define hstester_client_H

#include <QtGui/QMainWindow>
#include <QtCore/QTime>
#include <QtCore/QTimer>
#include <QtCore/QSettings>
#include <QtGui/QCloseEvent>
#include <QtGui/QMessageBox>
#include <QtCore/QDir>
#include <QtGui/QDesktopServices>
#include <QtCore/QUrl>
#include "ui_mainwindow.h"
#include "dlgconfig.h"
#include "testmanager.h"
#include "report.h"
#include "reportview.h"
#include "dlgregister.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
	
	enum ModeType {Training, Exam};
	
protected:
	void closeEvent(QCloseEvent *event);
	
private slots:
	void on_actionExit_activated();
	void on_listCatTestView_clicked(const QModelIndex &index);
	void on_actionBack_activated();
	void on_actionForvard_activated();
	void on_btnNext_clicked();
	void on_btnConfAnswer_1_toggled(bool checked);
	void on_btnConfAnswer_2_toggled(bool checked);
	void on_btnConfAnswer_3_toggled(bool checked);
	void on_btnConfAnswer_4_toggled(bool checked);
	void on_btnConfAnswer_5_toggled(bool checked);
	void on_btnConfAnswer_6_toggled(bool checked);
	void on_btnConfAnswer_7_toggled(bool checked);
	void on_btnConfAnswer_8_toggled(bool checked);
	void on_btnRegAnswer_1_toggled(bool checked);
	void on_btnRegAnswer_7_toggled(bool checked);
	void on_btnRegAnswer_8_toggled(bool checked);
	void on_btnRegAnswer_9_toggled(bool checked);
	void on_btnRegAnswer_10_toggled(bool checked);
	void on_btnRegAnswer_11_toggled(bool checked);
	void on_btnRegAnswer_12_toggled(bool checked);
	void on_btnRegAnswer_13_toggled(bool checked);
	void on_btnRegAnswer_14_toggled(bool checked);
	void on_btnRegAnswer_15_toggled(bool checked);
	void on_btnRegAnswer_16_toggled(bool checked);
	void on_btnRegAnswer_17_toggled(bool checked);
	void on_btnRegAnswer_18_toggled(bool checked);
	void on_btnRegAnswer_19_toggled(bool checked);
	void on_btnRegAnswer_20_toggled(bool checked);
	void on_btnRegAnswer_21_toggled(bool checked);
	void on_actionRepit_triggered();
	void on_actionLoadTests_triggered();
	void on_actionReturn_triggered();
	void timered();
	void net_error(int socketError, const QString &error_string);
	void on_actionAbout_triggered();
	void on_actionShowResult_triggered();
	void on_actionAdvance_triggered();
	void on_actionHelp_triggered();
	
	void testDbLoaded();
	void testLoaded();
	void groupsLoaded();
	
private:
    Ui::MainWindow *ui;
	QLabel* numTasksL;
	QLabel* numTasks;           // отображение количества заданий в тесте
	QLabel* timerView;          // отображение времени решения теста
	QCheckBox* closeNodes[8];   // массив чекбоксов задания закрытого типа
	QLabel* closeLabels[8];		// массив ответов закрытого типа
	QPushButton* confBtnNodes[8];   // массив кнопок задания типа соответствия
	QLabel* confLabelNodes[8];  // массив ответов задания типа соответствия
	QPushButton* regBtnNodes[16];// массив кнопок задания типа упорядочения
	QLabel* regLabelNodes[16];   // массив ответов задания упорядочения
	
	DlgConfig *config;          // диалог параметров
	ReportView *reportView;     // окно отображения результатов теста
	
	bool listViewTests;         // флаг отображения списка тестов
	int numCurrentNode;         // индекс текущего задания
	int numRealAnswers;         // количество верных ответов
	int ocenka;                 // оценка
	float percent;              // процент верных ответов
	float per2;                 // диапозон процентов на 2
	float per3;                 // диапозон процентов на 3
	float per4;                 // диапозон процентов на 4
	int numConfRegAnsw;         // текущий номер ответа на соответствие или упорядочение
	QTime* tTime;               // время прохождения теста
	QTimer* mTimer;             // таймер
	QSettings* settings;        // настройки
	TestManager *testManager;	// менеджер тестов
	const TestNode *currentNode;// текущее задание
	
	QString serverName;         // имя сервера
	qint16 serverPort;          // порт сервера
	
	QString curCatName;			// название текущей категории
	
	Report *resultReport;       // для просмотра результата
	bool resultReportOn;		// флаг включение записи результатов
	bool resultReportOnOld;		// значение флага включение записи результатов (для экзаменационного режима)
	QString htmlFileResult;     // путь к файлу с результатом теста
	QString tmpDir;             // временный каталог
	
	bool onToggled;		        // вкл./выкл. реакции слота toggled
	QString imagesPath;         // путь к каталогу с рисунками
	QString appName;			// заголовок окна
	bool viewPanel;				// показать/скрыть панель инструментов
	ModeType modeType;			// режим тестирования
	
	DlgRegister *modeDialog;	// диалог выбора режима тестирования
	
	QFont fontTask;				// шрифт для задания
	QFont fontQuest;			// шрифт для вопроса
	QFont fontAnsw;				// шрифт для ответа
	
	void showTestNode();
	void initCloseView();
	void initConfView();
	void initRegView();
	void setNumConfRegBtn(QPushButton* btn, bool ch);
	
	void chekResult();
	
	void showResult();
	
	void readSettings();
	void writeSettings();
	
	void setupFonts();
	void setWordWrap();
};

#endif // hstester_client_H

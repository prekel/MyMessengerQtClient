#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../QJsonModel/qjsonmodel.h"

#include "DialogWindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_login_clicked();

	void on_pushButton_gabid_clicked();

	void on_pushButton_getmessages_clicked();

	void on_pushButton_sendmessage_clicked();

	void on_pushButton_gdbid_clicked();

	void on_pushButton_openDialog_clicked();

    void update(QString i);

signals:
    void sendMessage1(QString host, quint16 port, QString message);
private:
	Ui::MainWindow *ui;

	QJsonModel* m_JsonModel;

	DialogWindow *dialog;
};

#endif // MAINWINDOW_H

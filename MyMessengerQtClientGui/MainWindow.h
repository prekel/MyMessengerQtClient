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
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_pushButton_login_clicked();

	void on_pushButton_openDialog_clicked();

	void on_pushButton_register_clicked();

	void callbackLoginRegister(QString i);

	void callbackCreateDialog(QString i);

	void on_pushButton_createDialog_clicked();

signals:
	void sendLoginRegister(QString host, quint16 port, QString message);

	void sendCreateDialog(QString host, quint16 port, QString message);

private:
	Ui::MainWindow *ui;

	QJsonModel* m_JsonModel;
};

#endif // MAINWINDOW_H

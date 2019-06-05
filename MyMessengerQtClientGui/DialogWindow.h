#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include <QMainWindow>
#include <QMap>

#include <Entities/Dialog.h>
#include <Entities/Account.h>

#include "ConnectionConfig.h"

namespace Ui {
class DialogWindow;
}

class DialogWindow : public QMainWindow
{
	Q_OBJECT

public:
    explicit DialogWindow(QWidget *parent = nullptr, ConnectionConfig *conf = nullptr);
	~DialogWindow();

	ConnectionConfig *Conf;

private slots:
	void callbackSendMessage(QString i);
	void callbackGetMessageLongPool(QString i);

	void callbackGetAccountById(QString i);
	void callbackGetDialogById(QString i);

	void on_pushButton_send_clicked();

signals:
	void sendSendMessage(QString host, quint16 port, QString message);
	void sendGetMessageLongPool(QString host, quint16 port, QString message);

	void sendGetAccountById(QString host, quint16 port, QString message);
	void sendGetDialogById(QString host, quint16 port, QString message);

private:
	Ui::DialogWindow *ui;

	void receiveLongPool();

	Dialog* _Dialog;
	QVector<Account*>* Members;
	QMap<int, QString>* MembersNicknames;
	void receiveDialogMembers();
};


#endif // DIALOGWINDOW_H

#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include <QMainWindow>

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
	void update1(QString i);
    void update2(QString i);

	void on_pushButton_send_clicked();

signals:
	void sendMessage1(QString host, quint16 port, QString message);
    void sendMessage2(QString host, quint16 port, QString message);

private:
	Ui::DialogWindow *ui;

	void receiveLongPool();
};


#endif // DIALOGWINDOW_H

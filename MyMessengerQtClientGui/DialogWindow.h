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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void update1(QString i);
    void update2(QString i);

signals:
    //void connectToServer1(QString host, qint16 port);
    void sendMessage1(QString host, quint16 port, QString message);
    //void connectToServer2(QString host, qint16 port);
    void sendMessage2(QString host, quint16 port, QString message);

private:
	Ui::DialogWindow *ui;
};

#endif // DIALOGWINDOW_H

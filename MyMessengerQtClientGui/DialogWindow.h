#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include <QMainWindow>

namespace Ui {
class DialogWindow;
}

class DialogWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit DialogWindow(QWidget *parent = nullptr);
	~DialogWindow();

private:
	Ui::DialogWindow *ui;
};

#endif // DIALOGWINDOW_H

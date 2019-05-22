#include "DialogWindow.h"
#include "ui_DialogWindow.h"

DialogWindow::DialogWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::DialogWindow)
{
	ui->setupUi(this);
}

DialogWindow::~DialogWindow()
{
	delete ui;
}

#pragma once

#include "ui_w_MainWindow.h"

#include <QMainWindow>
#include <QTextDocument>


class MainWindow
	: public QMainWindow
	, Ui::MainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = Q_NULLPTR);
	~MainWindow() override {};
};

#include <QtWidgets\QApplication>
#include <QtWidgets\qpushbutton.h> 
#include <QtWidgets\qboxlayout.h>
#include <QTableWidget>
#include <QLabel>

#include "util.h"

static QPushButton* CreateInterfaceSelector() {
	QLayout* layout = columns();
	QPushButton* button = new QPushButton("No WLAN interface selected");
	button->setLayout(layout);
	button->setCursor(Qt::PointingHandCursor);
	button->setStyleSheet("background-color:  rgb(58, 60, 68); color: white; padding:10px;border:none; outline: none; border-top-left-radius: 3px; border-bottom-left-radius: 3px; ");
	button->setFixedWidth(190);
	button->setFixedHeight(60);
	return button;
}

static QPushButton* CreateStartButton() {
	QPushButton* button = new QPushButton;
	button->setCursor(Qt::PointingHandCursor);
	button->setIcon(*ColoredIcon("play.svg", 255, 255, 255, .2));
	button->setFixedWidth(60);
	button->setFixedHeight(60);
	button->setIconSize(QSize(20, 20));
	button->setStyleSheet("	.QPushButton:disabled {background-color:rgba(102, 185, 98, .2);} .QPushButton { border-top-right-radius: 3px; border-bottom-right-radius: 3px; background-color:rgba(102, 185, 98, 1); padding: 20px;  border: none;outline:none; border} 	.QPushButton:hover { background-color:rgba(102, 185, 98, .9); }");
	button->setDisabled(true);

	return button;
}

static QLayout* CreateAttackButton() {
	QLayout* layout = columns();
	layout->setAlignment(Qt::AlignTop);
	layout->addWidget(CreateInterfaceSelector());
	layout->addWidget(CreateStartButton());
	//layout->setMargin(10);

	return layout;
}

static QLayout* ChecklistItem(const char* title) {
	
	QPushButton* icon = new QPushButton();
	icon->setIcon(*ColoredIcon("checked.svg", 102, 185, 98, 1));
	icon->setIconSize(QSize(11, 11));
	//icon->setDisabled(true);
	icon->setFixedWidth(15);
	icon->setStyleSheet("border: none; outline: none");


	auto label = new QLabel(title);
	label->setFixedHeight(19);
	label->setFixedWidth(150);
	label->setStyleSheet("color: white; ");

	QLayout* layout = columns();
	layout->addWidget(icon);
	layout->addWidget(label);
	layout->setMargin(0);
	layout->setSpacing(3);

	return layout;
}

static QLayout* CreateChecklist() {
	QVBoxLayout* layout = rows();
	layout->setAlignment(Qt::AlignTop);
	layout->addLayout(ChecklistItem("Randomised MAC Addressed"));
	layout->addLayout(ChecklistItem("Entered Monitor Mode"));
	layout->addLayout(ChecklistItem("Started Attack"));
	layout->setSpacing(0);
	return layout;
}

static QWidget* CreateControls() {
	QHBoxLayout* controls = columns();
	controls->setAlignment(Qt::AlignTop);
	controls->addLayout(CreateAttackButton(), 0);
	controls->addLayout(CreateChecklist());

	QWidget* wrapper = new QWidget;
	wrapper->setLayout(controls);
	//wrapper->setFixedHeight(140);
	//wrapper->setStyleSheet("background-color: orange");
	return wrapper;
}

static QTableWidget* CreateResultsTable() {
	QTableWidget* results = new QTableWidget;
	return results;
}

QWidget* CreateAttackView() {
	QLayout* menu = rows();
	menu->setSpacing(40);
	menu->addWidget(CreateControls());
	menu->addWidget(CreateResultsTable());


	QWidget* wrapper = new QWidget();
	//wrapper->setAttribute()
	wrapper->setLayout(menu);
	wrapper->setStyleSheet("  background-color: rgb(50, 53, 62);  font-size: 14px ");
	wrapper->setContentsMargins(60, 60, 60, 60);
	return wrapper;
}
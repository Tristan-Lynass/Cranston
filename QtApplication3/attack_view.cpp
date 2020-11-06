#include <QApplication>
#include <QPushButton>
#include <QtWidgets\qboxlayout.h>
#include <QTableWidget>
#include <QLabel>
#include <QObject>

#include "util.h"
#include "AttackControlButton.h"
#include "InterfaceSelector.h"


//const QIcon* AttackControlButton::startEnabled = ColoredIcon("play.svg", 255, 255, 255, 1);

static QLayout* CreateAttackButton() {
	QLayout* layout = columns();
	//layout->setAlignment(Qt::AlignTop);

	auto interfaceSelector = new InterfaceSelector;
	auto attackControlBtn = new AttackControlButton;

	QObject::connect(
		interfaceSelector,
		SIGNAL(isValid(bool)),
		attackControlBtn,
		SLOT(setEnabled(bool))
	);

	layout->addWidget(interfaceSelector);
	layout->addWidget(attackControlBtn);


	//layout->setMargin(10);

	return layout;
}

static QLayout* ChecklistItem(const char* title) {
	
	QPushButton* icon = new QPushButton();
	icon->setIcon(*ColoredIcon("checked.svg", 102, 185, 98, 1));
	icon->setIconSize(QSize(11, 11));
	//icon->setDisabled(true);
	icon->setFixedWidth(15);


	auto label = new QLabel(title);
	label->setFixedHeight(19);
	label->setFixedWidth(150);

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
	layout->setSpacing(4);
	return layout;
}

static QWidget* CreateControls() {
	QHBoxLayout* controls = columns();
	//controls->setAlignment(Qt::AlignTop);
	controls->addLayout(CreateAttackButton(), 0);
	controls->addWidget(new QWidget());
	controls->addLayout(CreateChecklist());

	QWidget* wrapper = new QWidget;
	wrapper->setLayout(controls);
	//wrapper->setFixedHeight(140);
	return wrapper;
}

static QTableWidget* CreateResultsTable() {
	QTableWidget* results = new QTableWidget;
	results->setAccessibleName("attack-results-table");
	results->setMinimumWidth(600);
	return results;
}

QWidget* CreateAttackView() {
	QLayout* menu = rows();
	menu->setSpacing(40);
	menu->addWidget(CreateControls());
	menu->addWidget(CreateResultsTable());


	QWidget* wrapper = new QWidget();
	wrapper->setLayout(menu);
	wrapper->setAccessibleName("attack-view");
	wrapper->setContentsMargins(60, 60, 60, 60);
	return wrapper;
}
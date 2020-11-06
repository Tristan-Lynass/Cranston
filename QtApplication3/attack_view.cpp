#include <QtWidgets\QApplication>
#include <QtWidgets\qpushbutton.h> 
#include <QtWidgets\qboxlayout.h>
#include <QTableWidget>
#include <QLabel>

#include "util.h"
#include "interface_utils.h"

class AttackControlButton : public QPushButton {
	// Q_OBJECT

public:
	AttackControlButton();
private:
	bool isStarted = false;
	const QIcon* START_ENABLED;
	const QIcon* START_DISABLED;
	const QIcon* STOP_ENABLED;
	const QIcon* STOP_DISABLED;
private:
	void mouseReleaseEvent(QMouseEvent* e) override;
	void start();
	void stop();
};

//const QIcon* AttackControlButton::startEnabled = ColoredIcon("play.svg", 255, 255, 255, 1);

AttackControlButton::AttackControlButton() {
	this->START_ENABLED = ColoredIcon("play.svg", 255, 255, 255, 1);
	this->START_DISABLED = ColoredIcon("play.svg", 255, 255, 255, .2);
	this->STOP_ENABLED = ColoredIcon("close.svg", 255, 255, 255, 1);
	this->STOP_DISABLED = ColoredIcon("close.svg", 255, 255, 255, .2);

	this->setCursor(Qt::PointingHandCursor);
	this->setAccessibleName("attack-control-btn");
	this->setFixedWidth(60);
	this->setFixedHeight(60);
	this->setIconSize(QSize(20, 20));  
	this->setIcon(*AttackControlButton::START_DISABLED);
	this->setDisabled(true);
	this->ensurePolished();
}

void AttackControlButton::mouseReleaseEvent(QMouseEvent* e) {
	if (this->isEnabled()) {
		this->isStarted = !(this->isStarted);
		this->isStarted ? start() : stop();
	}
}

void AttackControlButton::start() {
	this->setIcon(*AttackControlButton::STOP_ENABLED);
}

void AttackControlButton::stop() {
	this->setIcon(*AttackControlButton::START_ENABLED);
}

class InterfaceSelector : public QPushButton {
public:
	InterfaceSelector();
};

InterfaceSelector::InterfaceSelector() {
	this->setText("No WLAN interface selected");
	this->setCursor(Qt::PointingHandCursor);
	this->setAccessibleName("interface-selector");
	this->setFixedWidth(190);
	this->setFixedHeight(60);
}
 
static QLayout* CreateAttackButton() {
	QLayout* layout = columns();
	//layout->setAlignment(Qt::AlignTop);
	layout->addWidget(new InterfaceSelector());
	layout->addWidget(new AttackControlButton());
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
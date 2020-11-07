#include <QHBoxLayout>
#include <QTextDocument>
#include <QPushButton>
#include <QLabel>

#include "InterfaceSelector.h"
#include "interface_utils.h"
#include "util.h"

InterfaceSelector::InterfaceSelector() {
	this->setCursor(Qt::PointingHandCursor);
	this->setAccessibleName("interface-selector");
	this->setFixedWidth(190);
	this->setFixedHeight(60);


	this->label = new QLabel("No WLAN interface selected");
	label->setWordWrap(true);
	label->setStyleSheet("color: white; ");

	auto cog = new QPushButton;
	cog->setIcon(*ColoredIcon("gear.svg", 255, 255, 255, 1));
	cog->setIconSize(QSize(15, 15)); 


	QHBoxLayout* col = columns();
	col->addWidget(label);
	col->addWidget(cog);
	this->setLayout(col);



}

void InterfaceSelector::mouseReleaseEvent(QMouseEvent* e) {
	this->label->setText(*printInterfaces());
	emit isValid(true);
};

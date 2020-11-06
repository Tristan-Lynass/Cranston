#include "InterfaceSelector.h"
#include "interface_utils.h"

InterfaceSelector::InterfaceSelector() {
	this->setText("No WLAN interface selected");
	this->setCursor(Qt::PointingHandCursor);
	this->setAccessibleName("interface-selector");
	this->setFixedWidth(190);
	this->setFixedHeight(60);
}

void InterfaceSelector::mouseReleaseEvent(QMouseEvent* e) {
	this->setText(*printInterfaces());
	emit isValid(true);
};

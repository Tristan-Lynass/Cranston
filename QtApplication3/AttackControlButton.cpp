#include <QApplication>
#include <QPushButton>
#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "util.h"
#include "AttackControlButton.h"

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

	this->isStarted = false;
	this->setIcon(*AttackControlButton::START_DISABLED);
	this->setDisabled(true);
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

void AttackControlButton::setEnabled(bool isEnabled) {
	const QIcon* icon;

	if (isEnabled) {
		this->setDisabled(false);
		icon = isStarted ? STOP_ENABLED : START_ENABLED;
	} else {
		this->setDisabled(true);
		icon = isStarted ? STOP_DISABLED : START_DISABLED;
	}

	this->setIcon(*icon);
}

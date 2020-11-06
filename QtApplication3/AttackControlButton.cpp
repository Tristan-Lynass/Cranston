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

	this->setCursor(Qt::PointingHandCursor);
	this->setAccessibleName("attack-control-btn");
	this->setFixedWidth(60);
	this->setFixedHeight(60);
	this->setIconSize(QSize(20, 20));
	this->setCheckable(true);

	this->reset();
}

void AttackControlButton::mouseReleaseEvent(QMouseEvent* e) {
	if (this->isEnabled()) {
		this->setIcon(this->isChecked() ? *START_ENABLED : *STOP_ENABLED);
		QPushButton::mouseReleaseEvent(e);
	}
}

void AttackControlButton::reset() {
	this->setDisabled(true);
	this->setIcon(*START_DISABLED);
	this->setChecked(false);
}

void AttackControlButton::setEnabled(bool isEnabled) {
	const QIcon* icon;

	if (isEnabled) {
		this->setDisabled(false);
		this->setIcon(this->isChecked() ? *STOP_ENABLED : *START_ENABLED);
	} else {
	    this->reset();
	}
}

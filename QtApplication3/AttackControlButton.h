#pragma once

#include <QPushButton>

class AttackControlButton : public QPushButton {
	Q_OBJECT

public:
	AttackControlButton();

private:
	const QIcon* START_ENABLED;
	const QIcon* START_DISABLED;
	const QIcon* STOP_ENABLED;

private:
	void mouseReleaseEvent(QMouseEvent* e) override;
	void reset();

public slots:
	void setEnabled(bool isEnabled);
};
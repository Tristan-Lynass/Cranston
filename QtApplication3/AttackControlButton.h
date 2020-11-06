#pragma once

#include <QPushButton>

class AttackControlButton : public QPushButton {
	Q_OBJECT

public:
	AttackControlButton();

private:
	bool isStarted;
	const QIcon* START_ENABLED;
	const QIcon* START_DISABLED;
	const QIcon* STOP_ENABLED;
	const QIcon* STOP_DISABLED;

private:
	void mouseReleaseEvent(QMouseEvent* e) override;
	void start();
	void stop();

public slots:
	void setEnabled(bool isEnabled);
};
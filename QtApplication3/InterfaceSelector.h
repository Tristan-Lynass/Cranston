#pragma once

#include <QLabel>
#include <QPushButton>

class InterfaceSelector : public QPushButton {
	Q_OBJECT

public:
	InterfaceSelector();
private:
	QLabel* label;
private:
	void mouseReleaseEvent(QMouseEvent* e) override;
signals:
	void isValid(bool isValid);
};

#pragma once

#include <QPushButton>

class InterfaceSelector : public QPushButton {
	Q_OBJECT

public:
	InterfaceSelector();
private:
	void mouseReleaseEvent(QMouseEvent* e) override;
signals:
	void isValid(bool isValid);
};

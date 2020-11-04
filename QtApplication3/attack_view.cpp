#include <QtWidgets\QApplication>
#include <QtWidgets\qpushbutton.h> 

QWidget* CreateAttackView() {
	QWidget* x = new QWidget();
	x->setStyleSheet("background-color: rgb(50, 53, 62);");
	return x;
}
#include <QtWidgets\QApplication>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qboxlayout.h>

#include "util.h"

static QPushButton* SetupMenuButton(const char* iconUri) {
	QPushButton* button = new QPushButton;
	button->setCursor(Qt::PointingHandCursor);
	button->setIcon(*ColoredIcon(iconUri, 255, 255, 255, 1));
	button->setIconSize(QSize(40, 40));
	button->setAccessibleName("sidebar-btn");

	return button;
}

QWidget* CreateSidebar() {

	QVBoxLayout* menu = new QVBoxLayout;
	menu->setAlignment(Qt::AlignTop);
	menu->setMargin(0);
	menu->setSpacing(0);
	menu->addWidget(SetupMenuButton("flash.svg")); // Attack
	menu->addWidget(SetupMenuButton("notepad.svg")); // Captures

	QWidget* wrapper = new QWidget;
	wrapper->setAccessibleName("sidebar");
	wrapper->setLayout(menu);
	wrapper->setFixedWidth(100);
	return wrapper;
}
#include <QtWidgets\QApplication>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qboxlayout.h>
#include <QtSvg\qsvgwidget.h>

#include "sidebar.h"
#include "attack_view.h"

int start(int argc, char** argv) {
	QApplication app(argc, argv);

	QWidget window;
	window.setContentsMargins(0, 0, 0, 0);
	window.setWindowTitle("Cranston");
	window.setStyleSheet("margin: 0; padding: 0; background-color: rgb(36, 38, 45);");
 
	QHBoxLayout* primary = new QHBoxLayout;
	primary->setSpacing(0);
	primary->setMargin(0);
	//primary->setAlignment(Qt::AlignL);

	primary->addWidget(CreateSidebar());
	primary->addWidget(CreateAttackView());

	window.setLayout(primary);
	window.show();

	return app.exec();
}
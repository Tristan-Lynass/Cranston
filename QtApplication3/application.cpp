#include <QtCore>
#include <QApplication> 
#include <QWidget> 
#include <QFontDatabase>
#include <QFileInfo>
#include <iostream>
#include <QHBoxLayout>

#include "sidebar.h"
#include "attack_view.h"

int start(int argc, char** argv) {
	QString robotoUri("./Roboto-Regular.ttf");
	QFileInfo check_file(robotoUri);
	if (!(check_file.exists() && check_file.isFile())) {
		std::cout << "Unable to find font file" << std::endl;
		return -1;
	}
	 
	int id = QFontDatabase::addApplicationFont(robotoUri);
	if (id == -1) {
		return id;
	}
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont roboto(family);

	QApplication app(argc, argv);

	QWidget window;
	window.setFont(roboto);
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
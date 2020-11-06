#include <QtCore>
#include <QApplication> 
#include <QWidget> 
#include <QFontDatabase>
#include <QFileInfo>
#include <iostream>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QGraphicsEffect>
#include <QPainter>

#include "sidebar.h"
#include "attack_view.h"

class DarkenEffect : public QGraphicsEffect
{
public:
	void draw(QPainter* painter) override
	{
		QPixmap pixmap;
		QPoint offset;
		if (sourceIsPixmap()) // No point in drawing in device coordinates (pixmap will be scaled anyways)
			pixmap = sourcePixmap(Qt::LogicalCoordinates, &offset);
		else // Draw pixmap in device coordinates to avoid pixmap scaling;
		{
			pixmap = sourcePixmap(Qt::DeviceCoordinates, &offset);
			painter->setWorldTransform(QTransform());
		}
		painter->setBrush(QColor(0, 0, 0, 255)); // black bg
		painter->drawRect(pixmap.rect());
		painter->setOpacity(0.5);
		painter->drawPixmap(offset, pixmap);
	}
};

int start(int argc, char** argv) {
	/*QString robotoUri("./Roboto-Regular.ttf");
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
	QFont roboto(family);*/

	QApplication app(argc, argv);

	QFile styleFile("style.css");
	styleFile.open(QFile::ReadOnly);
	QString style(styleFile.readAll());

	QWidget window;
	//window.setFont(roboto);
	window.setContentsMargins(0, 0, 0, 0);
	window.setWindowTitle("Cranston"); 
 
	QHBoxLayout* primary = new QHBoxLayout;
	primary->setSpacing(0);
	primary->setMargin(0);
	//primary->setAlignment(Qt::AlignL);

	primary->addWidget(CreateSidebar());
	primary->addWidget(CreateAttackView());

	//QWidget primaryWrapper;
	//primaryWrapper.setLayout(primary);
	

	// QWidget modalOverlay;
	// modalOverlay.setAttribute(Qt::WA_NoSystemBackground);
    // modalOverlay.setAttribute(Qt::WA_TranslucentBackground, true);
	// modalOverlay.setParent(&window);
	// modalOverlay.setStyleSheet("background-color:rgb(100, 255, 43, .5);");
	// modalOverlay.setGeometry(0, 0, 1000, 1000);
	//modalOverlay.raise();
	//modalOverlay.raise();

	//QStackedLayout windowStack;
	//windowStack.addItem(primary);
	//windowStack.addWidget(&modalOverlay);

	// window.setGraphicsEffect(new DarkenEffect);
	window.setLayout(primary);
	window.setStyleSheet(style);
	window.ensurePolished();
	window.show();

	return app.exec();
}
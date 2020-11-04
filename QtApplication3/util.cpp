#include <QtWidgets\QApplication>
#include <QtGui\qpainter.h>
#include <QtGui\qicon.h>

QIcon* ColoredIcon(const char* uri, int r, int g, int b) {
	QColor color(r, g, b);
	QPixmap pixmap = QPixmap(uri);
	QPainter painter(&pixmap);
	painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
	painter.setBrush(color);
	painter.setPen(color);
	painter.drawRect(pixmap.rect());
	return new QIcon(pixmap);
}

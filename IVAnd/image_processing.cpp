#include "image_processing.h"
#include <QWidget>
#include <QtWidgets>
#include <QRubberBand>
#include <QPoint>
#include <QPixmap>
#include <QScrollArea>

using namespace std ;

image_processing::image_processing(QWidget *parent): QLabel( parent)
{
    rubberBand = new QRubberBand(QRubberBand::Rectangle , this);
    select = false;
}

QPoint image_processing:: get_first_point()
{
    int x = min(first_point.x(),second_point.x());
    int y = min(first_point.y(),second_point.y());
    QPoint point(x,y);
    return point;
}

QPoint image_processing:: get_second_point()
{
    int x = max(first_point.x(),second_point.x());
    int y = max(first_point.y(),second_point.y());
    QPoint point(x,y);
    return point;
}

void image_processing:: hide_border()
{
    rubberBand->hide();
}

/***********************************************/
void image_processing::mousePressEvent(QMouseEvent *event)
{

    if(this->underMouse()){
        first_point = event->pos();
        rubberBand->setGeometry(QRect(first_point, QSize()));
        rubberBand->show();
    }
}

void image_processing::mouseMoveEvent(QMouseEvent *event)
{
    rubberBand->setGeometry(QRect(first_point, event->pos()).normalized());
    rubberBand->show();
}

void image_processing::mouseReleaseEvent(QMouseEvent *event)
{
    if(this->underMouse()){
        second_point = event->pos();
        rubberBand->setGeometry(QRect(get_first_point(), get_second_point()));
        rubberBand->show();
        select = true;
    }
}

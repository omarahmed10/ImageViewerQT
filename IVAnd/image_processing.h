#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <QWidget>
#include <QtWidgets>
#include <QRubberBand>
#include <QScrollArea>
#include <stack>
#include <QPixmap>

class image_processing : public QLabel
{
    Q_OBJECT
private:
    QPoint first_point , second_point;
    QRubberBand *rubberBand;
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public:
    bool select;
    image_processing(QWidget *parent = 0);
    QPoint get_first_point();
    QPoint get_second_point();
    void hide_border();
};

#endif // IMAGE_PROCESSING_H

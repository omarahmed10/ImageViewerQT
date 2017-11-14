#ifndef CROP_H
#define CROP_H
#include "command.h"
#include <QPoint>


class Crop : public Command
{
private:
    Ui::MainWindow * ui;
    QPoint first,second;
public:
    Crop(State* state , COMTYPE type , Ui::MainWindow * ui , QPoint first , QPoint second);
    void excute();
};

#endif // CROP_H

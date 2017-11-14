#ifndef ZOOM_H
#define ZOOM_H
#include "command.h"

class Zoom : public Command
{
private:
    Ui::MainWindow * ui;
    int new_width,new_height;
public:
    Zoom(State* state , COMTYPE type , Ui::MainWindow * ui , int new_width , int new_height);
    void excute();
};

#endif // ZOOM_H

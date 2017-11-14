#ifndef ROTATE_H
#define ROTATE_H
#include "command.h"

class Rotate : public Command
{
protected:
    Ui::MainWindow * ui;
    int new_width,new_height,overall_angel;
public:
    Rotate(State* state , COMTYPE type , Ui::MainWindow * ui , int new_width ,int new_height ,int overall_angel);
    void excute();
};

#endif // ROTATE_H

#ifndef COMMAND_H
#define COMMAND_H
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "state.h"

enum COMTYPE {ZOOM,CROP,ROTATE,CREATE} ;

namespace Ui {
class MainWindow;
}

class Command
{
protected:
    COMTYPE type;
    State* state;
public:
    Command();
    Command(State* state, COMTYPE type);
    COMTYPE getType();
    State getState();
    void excute() ;
};

#endif // COMMAND_H

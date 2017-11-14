#ifndef CREATE_H
#define CREATE_H
#include "command.h"

class Create : public Command
{
private:
    Ui::MainWindow * ui;
public:
    Create(State* state , COMTYPE type , Ui::MainWindow * ui);
    void excute();
};

#endif // CREATE_H

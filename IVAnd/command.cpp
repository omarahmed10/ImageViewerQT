#include "command.h"
#include "crop.h"
#include "zoom.h"
#include "create.h"
#include "rotate.h"
#include "state.h"


Command::Command(){}

Command::Command(State* state , COMTYPE type){
    this->type = type ;
    this->state = new State();
    this->state->setState(*state);
}

COMTYPE Command::getType(){
    return this->type;
}

State Command::getState(){
    return *this->state;
}

void Command::excute(){

}

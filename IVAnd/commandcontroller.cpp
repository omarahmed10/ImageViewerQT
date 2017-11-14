#include "commandcontroller.h"
#include "state.h"
#include "crop.h"
#include "zoom.h"
#include "create.h"
#include "rotate.h"
#include <bits/stdc++.h>

CommandController::CommandController(){
    this->pointer = 0 ;
}

CommandController& CommandController::getInst(){
    static CommandController inst ;
    return inst;
}

void CommandController::addCommand(Command* com){
    bool fl = false ;
    while(!stack.empty() && pointer<stack.size()-1){
        stack.pop_back();
        fl =true ;
    }
    this->stack.push_back(com);
    pointer=stack.size()-1;
    // retain state if added in mid
    if(fl){
        for(int i=0;i<=pointer;i++){
            execute(stack[i]);
        }
    }
}

void CommandController::undo(State* state){
    if(pointer>=1){
        pointer--;
        for(int i=0;i<=pointer;i++){
            execute(stack[i]);
            state->setState(stack[i]->getState());
        }
    }
}

void CommandController::redo(State* state){
    if(pointer<=stack.size()-2){
        pointer++;
        for(int i=0;i<=pointer;i++){
            execute(stack[i]);
            state->setState(stack[i]->getState());
        }
    }
}

void CommandController::execute(Command* com){
    switch (com->getType()) {
    case ZOOM:
        ((Zoom*)com)->excute();
        break;
    case CREATE:
        ((Create*)com)->excute();
        break;
    case ROTATE:
        ((Rotate*)com)->excute();
        break;
    case CROP:
        ((Crop*)com)->excute();
        break;
    default:
        break;
    }
}

void CommandController::reset(State* state){
    pointer = 0 ;
    while(stack.size()>1)stack.pop_back();
    execute(stack[0]);
    state->setState(stack[0]->getState());
}

void CommandController::clear(){
    this->stack.clear();
    pointer = 0 ;
}

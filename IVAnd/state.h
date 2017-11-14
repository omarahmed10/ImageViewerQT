#ifndef STATE_H
#define STATE_H


class State
{
public:
    int old_angel = 0 , overall_angel = 0  , slider_value ;
    int image_original_width,image_original_height;
    State();
    State(int image_original_width,int image_original_height,int old_angel,int overall_angel ,int slider_value);
    void setState(State st);
};

#endif // STATE_H

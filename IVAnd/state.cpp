#include "state.h"

State::State(){}

State::State(int image_original_width, int image_original_height, int old_angel, int overall_angel, int slider_value)
{
    this->old_angel = old_angel;
    this->overall_angel = overall_angel;
    this->slider_value = slider_value;
    this->image_original_height = image_original_height;
    this->image_original_width = image_original_width;
}

void State::setState(State st){
    this->old_angel = st.old_angel;
    this->overall_angel = st.overall_angel;
    this->slider_value = st.slider_value;
    this->image_original_height = st.image_original_height;
    this->image_original_width = st.image_original_width;
}



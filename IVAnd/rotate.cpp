#include "rotate.h"

Rotate::Rotate(State* state, COMTYPE type, Ui::MainWindow *ui, int new_width, int new_height, int overall_angel) : Command(state,type){
    this->ui = ui ;
    this->new_height = new_height ;
    this->new_width = new_width ;
    this->overall_angel = overall_angel ;
}

void Rotate::excute(){
    // get original image no pexilation
    QPixmap pixmap = *(ui->original_image->pixmap());

    // scale original image
    QPixmap pixmap_new=pixmap.scaled(this->new_width,this->new_height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // rotate zoomed version
    QTransform trans  ;

    ui->image_canvas->setPixmap(pixmap_new.transformed(trans.rotate(this->overall_angel)));
}

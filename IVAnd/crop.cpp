#include "crop.h"
#include "QPixmap"

Crop::Crop(State *state, COMTYPE type, Ui::MainWindow *ui, QPoint first, QPoint second) : Command(state,type)
{
   this->ui = ui ;
   this->first = first ;
   this->second = second ;
}

void Crop::excute(){
    if(first != second){
        QRect rect(first,second);
        ui->image_canvas->hide_border();
        ui->original_image->hide_border();
        QPixmap cropped=ui->image_canvas->pixmap()->copy(rect);
        ui->image_canvas->setPixmap(cropped);
        ui->original_image->setPixmap(cropped);
    }
}

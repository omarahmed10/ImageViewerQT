#include "zoom.h"
#include "ui_mainwindow.h"

Zoom::Zoom(State* state, COMTYPE type, Ui::MainWindow* ui, int new_width, int new_height) : Command(state,type){
    this->ui = ui ;
    this->new_height = new_height ;
    this->new_width = new_width ;
}

void Zoom::excute(){
    QPixmap pixmap = *(ui->original_image->pixmap());
    QPixmap pixmap_new=pixmap.scaled(new_width,new_height,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->image_canvas->setPixmap(pixmap_new);
    ui->image_canvas->setGeometry(ui->scrollArea->x(),ui->scrollArea->y(),new_width,new_height);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "state.h"
#include "commandcontroller.h"
#include "zoom.h"
#include "crop.h"
#include "create.h"
#include "rotate.h"
#include <QFileDialog>
#include <QStandardPaths>
#include "androidimagepicker.h"
#include <QScreen>
#include <QInputDialog>

// some global variables
// ************************************************
int slider_initial_value=0;
int image_original_width=0;
int image_original_height=0;
int pading = 10;
int old_angel = 0 , overall_angel = 0  ;
State* state;
QString curr_imagePath;
QScreen *screen;
AndroidImagePicker *android_image_picker;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    edit_scene();
    /*opening a connection between image picker and this class.*/
    android_image_picker = new AndroidImagePicker();
    connect(android_image_picker,SIGNAL(imagePathRetrieved(QString)),this,SLOT(load_is_done(QString)));
    /*starting program by selecting the image.*/
    android_image_picker->openPicker();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::edit_scene(){
    screen = QApplication::screens().at(0);
    int button_width=141;
    int button_height=(screen->availableSize().height()*1)/9;
    /*editing Scroll Area Postion and properties.*/
    ui->scrollArea->setGeometry(pading,pading,screen->availableSize().width()-pading,(screen->availableSize().height()*3)/4);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setWidget(ui->image_canvas);
    ui->original_image->hide();
    ui->backup_image->hide();
    /*making all button relative to the screen boundries.*/
    ui->save_button->setGeometry(screen->availableSize().width()-button_width-pading,pading,button_width,button_height);
    ui->save_button->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->back_button->setGeometry(pading,pading,button_width,button_height);
    ui->back_button->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->zoom_slider->setGeometry(pading,(screen->availableSize().height()*3)/4+2*pading,screen->availableSize().width(),button_height/2);
    ui->undo_button->setGeometry(pading,(screen->availableSize().height()*7)/8,button_width,button_height);
    ui->redo_button->setGeometry(pading+button_width,(screen->availableSize().height()*7)/8,button_width,button_height);
    ui->crop_button->setGeometry(pading+2*button_width,(screen->availableSize().height()*7)/8,button_width,button_height);
    ui->reset_button->setGeometry(pading+3*button_width,(screen->availableSize().height()*7)/8,button_width,button_height);
    ui->dial->setGeometry(pading+4*button_width,(screen->availableSize().height()*7)/8,button_width,button_height);

}

void MainWindow::regainState(){
    image_original_height = state->image_original_height;
    image_original_width = state->image_original_width;
    old_angel = state->old_angel;
    overall_angel = state->overall_angel;
    ui->zoom_slider->setValue(state->slider_value);
}

void MainWindow::on_reset_button_clicked(){
    // hide the select border
    ui->image_canvas->hide_border();
    ui->original_image->hide_border();

    CommandController::getInst().reset(state);
    regainState();
}

void MainWindow::load_is_done(QString imagePath){
    curr_imagePath = imagePath;
    QPixmap pixmap;
    pixmap.load( imagePath.remove(0,7) );
    qDebug() << "omar " << imagePath << endl;
    // set image of canvas
    ui->image_canvas->setPixmap(pixmap);
    // store original image to be used later
    ui->original_image->setPixmap(pixmap);
    // store backup image to be used later
    ui->backup_image->setPixmap(pixmap);

    image_original_width=pixmap.width();
    image_original_height=pixmap.height();
    ui->zoom_slider->setValue(100);

    //clear past undo/redo
    CommandController::getInst().clear();

    ui->dial->setValue(0);

    // begin a new state
    state = new State(image_original_width,image_original_height,0,0,ui->zoom_slider->value());
    State* state_new = new State(image_original_width,image_original_height,0,0,ui->zoom_slider->value());

    // make create command
    Create* com = new Create(state_new,CREATE,ui);

    // add command to undo/redo
    CommandController::getInst().addCommand(com);

}

QString* getImageName(QString image){
    int i;
    QString *name = new QString("");
    for(i = image.length()-1;i >= 0 ;i--){
        if(image[i] == '/')
            return name;
        name->push_front(image[i]);
    }
    return name;
}
void MainWindow::on_save_button_clicked(){
    bool dialogResult;
    QString *name = getImageName(curr_imagePath);
    QInputDialog *renameDialog = new QInputDialog();
    QString result = renameDialog->getText(0, "Save Image", "New name:", QLineEdit::Normal,
                                           *name, &dialogResult);

    if(result.length() > 0 && dialogResult){
        *name = result;
        if(!(*name).contains(".",Qt::CaseInsensitive)){
            *name += ".png";
            qDebug() << *name << endl;
        }
    }
    QString tmpString = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);

    if (ui->image_canvas->pixmap()->save(tmpString + "/" + *name, 0,-1)) qDebug() << "Saved ";
    else qDebug() << "Not Saved ";

    qDebug() << tmpString+*name << endl;
}


void MainWindow::on_zoom_slider_sliderPressed(){

    // hide the select border
    ui->image_canvas->hide_border();
    ui->original_image->hide_border();

    int value=ui->zoom_slider->value();
    slider_initial_value=value;
}


void MainWindow::on_zoom_slider_valueChanged(int value)
{

    // hide the select border
    ui->image_canvas->hide_border();
    ui->original_image->hide_border();

    // image not loaded yet
    if(ui->image_canvas->pixmap() == NULL)return ;

    QPixmap pixmap_new;
    QPixmap pixmap = *(ui->original_image->pixmap());

    int change = value;

    int new_width=change*image_original_width/100;
    int new_height=change*image_original_height/100;

    pixmap_new = pixmap.scaled(new_width,new_height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QTransform trans;
    // set ui image to new pixmap
    if(!pixmap_new.isNull())ui->image_canvas->setPixmap(pixmap_new.transformed(trans.rotate(overall_angel)));
    //slider_initial_value=value;

}

void MainWindow::on_zoom_slider_sliderReleased()
{
    // image not loaded yet
    if(ui->image_canvas->pixmap() == NULL)return ;

    int width=ui->image_canvas->pixmap()->width();
    int height=ui->image_canvas->pixmap()->height();

    QPixmap pixmap = *(ui->original_image->pixmap());

    // zoom original image by new percentage
    QPixmap pixmap_new=pixmap.scaled(width,height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // rotate zoomed version
    QTransform trans  ;
    ui->image_canvas->setPixmap(pixmap_new.transformed(trans.rotate(overall_angel)));

    // update state
    state = new State(image_original_width,image_original_height,old_angel,overall_angel,ui->zoom_slider->value());
    State* state_new = new State(image_original_width,image_original_height,old_angel,overall_angel,ui->zoom_slider->value());
    // make rotate command
    Zoom* com = new Zoom(state_new,ZOOM,ui,width,height);

    // add command to undo/redo
    CommandController::getInst().addCommand(com);

}

void MainWindow::on_dial_valueChanged(int value)
{
    // hide the select border
    ui->image_canvas->hide_border();
    ui->original_image->hide_border();

    int change = value-old_angel ;
    overall_angel+=change ;

    // branching now please
    QPixmap pixmap = *(ui->original_image->pixmap());

    int slider_val = ui->zoom_slider->value();

    // new zoom dimensions
    int new_width=slider_val*image_original_width/100;
    int new_height=slider_val*image_original_height/100;

    // scale original image
    QPixmap pixmap_new=pixmap.scaled(new_width,new_height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QTransform trans  ;
    ui->image_canvas->setPixmap(pixmap_new.transformed(trans.rotate(overall_angel)));
    old_angel = value ;

}

void MainWindow::on_dial_sliderReleased()
{
    // get original image no pexilation
    QPixmap pixmap = *(ui->original_image->pixmap());

    int slider_val = ui->zoom_slider->value();

    // new zoom dimensions
    int new_width=slider_val*image_original_width/100;
    int new_height=slider_val*image_original_height/100;

    // scale original image
    QPixmap pixmap_new=pixmap.scaled(new_width,new_height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // rotate zoomed version
    QTransform trans  ;

    // update image of canvas
    ui->image_canvas->setPixmap(pixmap_new.transformed(trans.rotate(overall_angel)));

    // update state
    state = new State(image_original_width,image_original_height,old_angel,overall_angel,ui->zoom_slider->value());
    State* state_new = new State(image_original_width,image_original_height,old_angel,overall_angel,ui->zoom_slider->value());
    // make rotate command
    Rotate* com = new Rotate(state_new,ROTATE,ui,new_width,new_height,overall_angel);

    // add command to undo/redo
    CommandController::getInst().addCommand(com);
}

void MainWindow::on_back_button_clicked()
{
    android_image_picker->openPicker();
}

void MainWindow::on_undo_button_released()
{
    CommandController::getInst().undo(state);
    regainState();
}

void MainWindow::on_redo_button_released()
{
    CommandController::getInst().redo(state);
    regainState();
}


void MainWindow::on_crop_button_clicked()
{
    QPoint first = ui->image_canvas->get_first_point();
    QPoint second = ui->image_canvas->get_second_point();
    if(ui->image_canvas->select) {
        ui->image_canvas->select = false;
        if(first != second)
        {
            int n1 = ui->image_canvas->pixmap()->height();
            int n2 = (ui->scrollArea->height()-n1)/2;
            if(n2>0){
                first.setY(first.y()-n2);
                second.setY(second.y()-n2);
            }
            QRect rect(first,second);
            ui->image_canvas->hide_border();
            ui->original_image->hide_border();
            QPixmap cropped=ui->image_canvas->pixmap()->copy(rect);
            ui->image_canvas->setPixmap(cropped);
            ui->original_image->setPixmap(cropped);


            // reset ------------------------------------
                // set value of slider to max
                old_angel = 0 , overall_angel = 0 ;
                // save width and height of original image
                image_original_width=cropped.width();
                image_original_height=cropped.height();
            // ------------------------------------------


            // update state
            state = new State(image_original_width,image_original_height,old_angel,overall_angel,ui->zoom_slider->value());
            State* state_new = new State(image_original_width,image_original_height,old_angel,overall_angel,ui->zoom_slider->value());
            // make crop command
            Crop* com = new Crop(state_new,CROP,ui,first,second);
            // add command to undo/redo
            CommandController::getInst().addCommand(com);
            //ui->zoom_slider->setValue(ui->zoom_slider->maximum()/2);
        }
    }
}

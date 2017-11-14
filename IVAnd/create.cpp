#include "create.h"
#include  "command.h"
#include <qpixmap.h>

Create::Create(State *state, COMTYPE type, Ui::MainWindow *ui) : Command(state,type)
{
    this->ui = ui;
}

void Create::excute(){
    QPixmap cop1(*this->ui->backup_image->pixmap());
    QPixmap cop2(*this->ui->backup_image->pixmap());
    this->ui->original_image->setPixmap(cop1);
    this->ui->image_canvas->setPixmap(cop2);
}

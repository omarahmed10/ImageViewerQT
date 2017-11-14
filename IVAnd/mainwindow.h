#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
     void load_is_done(QString imagePath);

private slots:
    void on_reset_button_clicked();

    void on_save_button_clicked();

    void on_zoom_slider_sliderPressed();

    void on_zoom_slider_valueChanged(int value);

    void on_zoom_slider_sliderReleased();

    void on_dial_valueChanged(int value);

    void on_dial_sliderReleased();

    void on_image_canvas_destroyed();

    void on_back_button_clicked();

    void on_crop_button_clicked();

    void on_undo_button_released();

    void on_redo_button_released();


private:
    Ui::MainWindow *ui;
    void regainState();
    void edit_scene();
};

#endif // MAINWINDOW_H

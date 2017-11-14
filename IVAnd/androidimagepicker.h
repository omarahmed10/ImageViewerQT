#ifndef ANDROIDIMAGEPICKER_H
#define ANDROIDIMAGEPICKER_H

#include <QObject>
#include <QtAndroidExtras>
#include <QPixmap>
#include <QDebug>

class AndroidImagePicker : public QObject, public QAndroidActivityResultReceiver
{
    Q_OBJECT

public:
    AndroidImagePicker();
    void openPicker();
    virtual void handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject &data);

signals:
    void imagePathRetrieved(QString imagePath);
};

#endif // ANDROIDIMAGEPICKER_H

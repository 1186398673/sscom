#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QStringList>
#include <QTimer>
#include <QDate>
#include <QMediaPlayer>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>




QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QSerialPort *serialPort;
    QString filePath;

private slots:
    void on_openButton_clicked();
    void on_closeButton_clicked();
    void serialreadyread();
    void on_sendButton_clicked();
    void on_cleanButton_clicked();
    void on_saveButton_clicked();
    void on_okButton_clicked();
    void on_quitButton_clicked();
    void on_botolvBox_currentTextChanged(const QString &arg1);
    void updateQuote();
    void on_sendHexBox_checkStateChanged(const Qt::CheckState &arg1);
    void on_recvHexBox_checkStateChanged(const Qt::CheckState &arg1);
    QString bytesToHex(const QByteArray &data);
    QByteArray hexToBytes(const QString &hex);
    QString stringToHex(const QString &sendText);


    void on_pushButton_clicked();


private:
    Ui::Widget *ui;
    QStringList quotes;
    QTimer timer;
    QDate lastUpdateDate;
    int currentIndex;
    bool sendHex;
    bool recvHex;

};
#endif // WIDGET_H

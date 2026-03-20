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
    void refreshSerialPorts(); // 刷新串口列表



    void on_searchButton_clicked();
    void searchKeyword();
    void clearSearchHighlight();
    void on_recvTextEdit_returnPressed();  // 加这行

    void on_lineEdit_returnPressed();



    void on_simplecheckBox_checkStateChanged(const Qt::CheckState &arg1);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::Widget *ui;
    QStringList quotes;
    QTimer timer;
    QDate lastUpdateDate;
    int currentIndex;
    bool sendHex;
    bool recvHex;
    bool simple_mode;

};
#endif // WIDGET_H

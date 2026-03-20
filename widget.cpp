#include "widget.h"
#include "ui_widget.h"
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QString>
#include <QColor>
#include <QTextCharFormat>
#include <QTime>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <cstdio>
#include "mainwindow.h"
#include <QTextBlock>
#include <QRegularExpression>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)

{
    ui->setupUi(this);
    ui->recvTextEdit->setReadOnly(false); // 允许输入
    // 让recvTextEdit捕获回车按键，触发我们的槽函数
    ui->recvTextEdit->installEventFilter(this);



    QStringList serialnameport;
    serialPort=new QSerialPort(this);
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
      //serialnameport<<info.portName();
      QString portName = info.portName();                  // COM3
      QString description = info.description();            // 串口描述
      QString showText = QString("%1  %2")
                               .arg(portName)
                               .arg(description);

       ui->serianumBox->addItem(showText, portName);

    }





    //ui->serianumBox->addItems(serialnameport);




    connect(serialPort,SIGNAL(readyRead()),SLOT(serialreadyread()));
     ui->openButton->setEnabled(true);
     ui->sendButton->setEnabled(false);     //设置控件不可用
     ui->closeButton->setEnabled(false);
     setWindowIcon(QIcon(":/logo.ico"));
     // 初始化自定义输入框和按钮为隐藏状态
     ui->botolvBox->setEditable(0);
     currentIndex=0;

    ui->botolvEdit->setVisible(false);
    ui->okButton->setVisible(false);
    ui->quitButton->setVisible(false);
    ui->groupBox_2->setVisible(false);

    // 从外部文件加载格言
    QFile file("quotes.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (!line.trimmed().isEmpty()) {
                quotes << line;
            }
        }
        file.close();
    } else {
        qDebug() << "无法打开格言文件";
    }

    // 如果没有加载到格言，使用硬编码的格言
    if (quotes.isEmpty()) {
        quotes << "生活就像骑自行车。要保持平衡，你必须不断前进。"
               << "成功不是终点，失败也并非末日，重要的是继续前进的勇气。"
               << "每天都是一个新的开始。"
               << "幸福不是拥有你想要的，而是珍惜你所拥有的。"
               << "不要等待机会，而要创造机会。";
    }

    // 设置定时器，每天更新一次格言

    timer.setInterval(100000); // 初始为1分钟，检查是否需要更新
    connect(&timer, &QTimer::timeout, this, &Widget::updateQuote);
    timer.start();

    // 初始显示
    updateQuote();
    sendHex=false;
    recvHex=false;
    simple_mode=false;














}

Widget::~Widget()
{
    delete ui;
}


void Widget::refreshSerialPorts()
{
    // 先清空原有列表
    ui->serianumBox->clear();

    // 重新扫描并添加所有可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QString portName = info.portName();
        QString description = info.description();
        QString showText = QString("%1  %2").arg(portName).arg(description);

        ui->serianumBox->addItem(showText, portName);
    }
}




void Widget::on_openButton_clicked()
{
    // QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity cheakBits;
    // if(ui->botolvBox->currentText()=="4800")
    // {
    //   baudRate=QSerialPort::Baud4800;
    // }
    // else if(ui->botolvBox->currentText()=="9600")
    // {
    //  baudRate=QSerialPort::Baud9600;
    // }
    //   else if(ui->botolvBox->currentText()=="115200")
    // {
    //  baudRate=QSerialPort::Baud115200;
    // }



    if(ui->databitBox->currentText()=="5"){
     dataBits=QSerialPort::Data5;
    }
    else if(ui->databitBox->currentText()=="6"){
      dataBits=QSerialPort::Data6;
    }
     else if(ui->databitBox->currentText()=="7"){
      dataBits=QSerialPort::Data7;
    }
     else if(ui->databitBox->currentText()=="8"){
      dataBits=QSerialPort::Data8;
    }
     if(ui->stopbitBox->currentText()=="1"){
     stopBits=QSerialPort::OneStop;
    }
     else  if(ui->stopbitBox->currentText()=="1.5"){
     stopBits=QSerialPort::OneAndHalfStop;
    }
    else  if(ui->stopbitBox->currentText()=="2"){
     stopBits=QSerialPort::TwoStop;
    }
     // 设置校验位
    if (ui->jiaoyanBox->currentText() == "0") {
        cheakBits = QSerialPort::NoParity;
    } else if (ui->jiaoyanBox->currentText() == "1") {
        cheakBits = QSerialPort::EvenParity;
    } else if (ui->jiaoyanBox->currentText() == "2") {
        cheakBits = QSerialPort::OddParity;
    } else {
        QMessageBox::warning(this, "错误", "无效的校验位！");
        return;
    }

    //serialPort->setPortName(ui->serianumBox->currentText());
    QString realPortName = ui->serianumBox->currentData().toString();
    serialPort->setPortName(realPortName);


    serialPort->setBaudRate(ui->botolvBox->currentText().toInt());

    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBits);
    serialPort->setParity(cheakBits);
    if(serialPort->open(QIODevice::ReadWrite)==true){
     serialPort->setRequestToSend(true);
     serialPort->setDataTerminalReady(true);
     QMessageBox::information(this,"提示","成功");
      ui->openButton->setEnabled(false);
      ui->sendButton->setEnabled(true);     //设置控件不可用
      ui->closeButton->setEnabled(true);
    }
    else {
     QMessageBox::information(this,"提示","失败");
    }





}


void Widget::on_closeButton_clicked()
{
    serialPort->close();
    refreshSerialPorts();
    ui->openButton->setEnabled(true);
    ui->sendButton->setEnabled(false);     //设置控件不可用
    ui->closeButton->setEnabled(false);

}

void Widget::serialreadyread()
{
    // 获取当前时间
    QTime currentTime = QTime::currentTime();
    QString timeString = currentTime.toString("HH:mm:ss.zzz");

    // 读取接收到的数据
    QByteArray data = serialPort->readAll();
    QString recvText;

    if (recvHex) {
        recvText = bytesToHex(data);
    } else {
        recvText = QString::fromLocal8Bit(data);
    }

    // ====================== 关键：过滤 ANSI 颜色码 ======================
    QRegularExpression ansiRegex(R"(\x1B\[[0-9;]*[mGK])");
    recvText.remove(ansiRegex);
    recvText.remove("\r");      // 去掉多余回车
    recvText.replace("\n\n", "\n"); // 去重换行
    // =================================================================

    // 创建一个文本格式对象并设置颜色为蓝色
    QTextCharFormat fmt;
    fmt.setForeground(QColor(Qt::blue));

    // 获取文本编辑器的光标
    QTextCursor cursor = ui->recvTextEdit->textCursor();

    if(!simple_mode){
    // 插入时间戳和接收的文本
    cursor.insertText("[" + timeString + "] 接收: " + recvText + "\n", fmt);
    }
    else
    {
       cursor.insertText(recvText + "\n", fmt);
    }

    // 滚动到文本的末尾
    ui->recvTextEdit->moveCursor(QTextCursor::End);
}

void Widget::on_sendButton_clicked()
{
    // 获取发送的文本
    QString sendText = ui->sendEdit->text()+"\r\n";
     QString sendTexthex;




    // 转换为字节数组
    QByteArray sendData;
    if (sendHex) {
        sendData = hexToBytes(sendText);
        sendTexthex = stringToHex(sendText);
    } else {
        sendData = sendText.toLocal8Bit();
    }


    // 获取当前时间
    QTime currentTime = QTime::currentTime();
    QString timeString = currentTime.toString("HH:mm:ss.zzz");

    // 创建一个文本格式对象并设置颜色为黑色
    QTextCharFormat fmt;
    fmt.setForeground(QColor(Qt::black));

    // 获取文本编辑器的光标
    QTextCursor cursor = ui->recvTextEdit->textCursor();

    // 插入时间戳和发送的文本，并应用颜色格式
    if(!simple_mode)
    {
     if (sendHex) {
        cursor.insertText("[" + timeString + "] 发送 (Hex): " + sendTexthex + "\n", fmt);
     } else {

        cursor.insertText("[" + timeString + "] 发送: " + sendText + "\n", fmt);
     }
    }
    else
    {

      // 简单模式：只发内容，不带时间戳
        if (sendHex) {
            cursor.insertText(sendTexthex + "\n", fmt);
        } else {
            cursor.insertText(sendText + "\n", fmt);
        }

    }

    // 滚动到文本的末尾
    ui->recvTextEdit->moveCursor(QTextCursor::End);

    // 发送数据
    serialPort->write(sendData);


    // 清空发送编辑框
    //ui->sendEdit->clear();

    // 禁用打开按钮，启用关闭按钮
    ui->openButton->setEnabled(false);
    ui->closeButton->setEnabled(true);
}



void Widget::on_cleanButton_clicked()
{
    ui->recvTextEdit->clear();
}





void Widget::on_saveButton_clicked()
{
    // 打开文件对话框选择保存路径
    QString selectedPath = QFileDialog::getSaveFileName(this, "保存接收的数据", "", "文本文件 (*.txt);;所有文件 (*.*)");
    if (!selectedPath.isEmpty()) {
        // 如果用户没有指定 .txt 后缀，则自动添加
        if (!selectedPath.endsWith(".txt")) {
            selectedPath += ".txt";
        }
        filePath = selectedPath;
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // 写入接收框中的内容
            QString recvText = ui->recvTextEdit->toPlainText();
            QTextStream out(&file);
            out << recvText;
            file.close();
            QMessageBox::information(this, "成功", "接收内容已保存！");
        } else {
            QMessageBox::warning(this, "错误", "无法创建文件！");
        }
    }
  }








  void Widget::on_okButton_clicked()
  {
     ui->botolvBox->insertItem(0,ui->botolvEdit->text());
     ui->botolvBox->setCurrentText(ui->botolvEdit->text());
     ui->botolvEdit->setVisible(false);
     ui->okButton->setVisible(false);
     ui->quitButton->setVisible(false);
     ui->groupBox_2->setVisible(false);
  }


  void Widget::on_quitButton_clicked()
  {
    ui->botolvEdit->setVisible(false);
    ui->okButton->setVisible(false);
    ui->quitButton->setVisible(false);
    ui->groupBox_2->setVisible(false);

  }









  void Widget::on_botolvBox_currentTextChanged(const QString &arg1)
  {
       if(ui->botolvBox->currentText()=="Custom"){
           ui->botolvEdit->setVisible(true);
           ui->okButton->setVisible(true);
           ui->quitButton->setVisible(true);
           ui->groupBox_2->setVisible(true);

      }


  }


  void Widget::updateQuote()
{
        // 更新格言
        currentIndex = (currentIndex + 1) % quotes.size();
        ui->label_8->setText(quotes.at(currentIndex));


}







void Widget::on_sendHexBox_checkStateChanged(const Qt::CheckState &arg1)
{
     sendHex=ui->sendHexBox->checkState();


}


void Widget::on_recvHexBox_checkStateChanged(const Qt::CheckState &arg1)
{

 recvHex=ui->recvHexBox->checkState();

}

QString Widget::bytesToHex(const QByteArray &data)
{
    QString hexString;
    for (char byte : data) {
        QString hexByte = QString::number(static_cast<unsigned char>(byte), 16).toUpper();
        if (hexByte.length() == 1) {
            hexByte = "0" + hexByte;
        }
        hexString += hexByte + " ";
    }
    return hexString.trimmed();
}

QByteArray Widget::hexToBytes(const QString &hex)
{
    QByteArray bytes;
    QString pureHex = hex.trimmed();
    QStringList hexValues = pureHex.split(" ");
    for (const QString &hexValue : hexValues) {
        bool ok;
        int byte = hexValue.toInt(&ok, 16);
        if (ok) {
            bytes.append(static_cast<char>(byte));
        }
    }
    return bytes;
}

QString Widget::stringToHex(const QString &sendText) {
    QString hexString;
    for (const QChar &c : sendText) {
        // 获取字符的ASCII值，并格式化为两位大写十六进制
        QString hex = QString::number(c.unicode(), 16).toUpper();
        if (hex.length() < 2) {
            hex = "0" + hex; // 补零以确保每个字符都是两位
        }
        hexString += hex;
    }
    return hexString;
}


void Widget::on_pushButton_clicked()
{
    MainWindow *ct=new MainWindow;
   ct->setGeometry(this->geometry());
   ct->show();
}

void Widget::searchKeyword()
{
    QString key = ui->searchEdit->text().trimmed();
    if (key.isEmpty()) {
        clearSearchHighlight();
        return;
    }

    QTextDocument *doc = ui->recvTextEdit->document();
    QTextCursor cursor(doc);

    // 先清除旧高亮
    clearSearchHighlight();

    // 只设置背景高亮，不改变原有字体颜色
    QTextCharFormat hlFormat;
    hlFormat.setBackground(QColor(255, 255, 0, 100)); // 半透明黄

    QTextDocument::FindFlags flags;
    // flags |= QTextDocument::FindCaseSensitively; // 区分大小写，不需要就注释

    bool found = false;
    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = doc->find(key, cursor, flags);
        if (!cursor.isNull()) {
            cursor.mergeCharFormat(hlFormat);
            if (!found) {
                ui->recvTextEdit->setTextCursor(cursor);
                found = true;
            }
        }
    }
}

void Widget::clearSearchHighlight()
{
    QTextCursor cursor(ui->recvTextEdit->document());
    QTextCharFormat fmt;
    fmt.setBackground(Qt::transparent); // 只清除背景，不碰字体颜色

    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(fmt);
}



void Widget::on_searchButton_clicked()
{
    searchKeyword();
}


void Widget::on_lineEdit_returnPressed()
{
     searchKeyword();
}


// 接收面板按回车 = 发送输入内容
void Widget::on_recvTextEdit_returnPressed()
{
    if (!serialPort->isOpen())
        return;

    // 取当前行输入的命令
    QTextCursor cursor = ui->recvTextEdit->textCursor();
    QString cmd = cursor.block().text().trimmed();

    if (cmd.isEmpty())
        return;

    // 发送
    QByteArray sendData = (cmd + "\r\n").toLocal8Bit();
    serialPort->write(sendData);

    // 关键：把你输入的那一行清空/删掉，不留在界面
    cursor.select(QTextCursor::BlockUnderCursor);
    cursor.removeSelectedText();
}


bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->recvTextEdit && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            // 触发我们的回车发送函数
            on_recvTextEdit_returnPressed();
            return true; // 拦截事件，避免换行
        }
    }
    return QWidget::eventFilter(obj, event);
}





void Widget::on_simplecheckBox_checkStateChanged(const Qt::CheckState &arg1)
{
     simple_mode=ui->simplecheckBox->checkState();
}

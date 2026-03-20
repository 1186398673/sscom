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
    ui->groupBox_2->raise();

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
           << "不要等待机会，而要创造机会。"

           // 国学经典
           << "己所不欲，勿施于人。——《论语》"
           << "上善若水，水善利万物而不争。——《道德经》"
           << "知人者智，自知者明。——《道德经》"
           << "天行健，君子以自强不息。——《周易》"
           << "吾日三省吾身。——《论语》"
           << "静以修身，俭以养德。——《诫子书》"
           << "路漫漫其修远兮，吾将上下而求索。——《离骚》"
           << "穷则独善其身，达则兼济天下。——《孟子》"
           << "锲而不舍，金石可镂。——《荀子》"
           << "海纳百川，有容乃大。——林则徐"

           // 西方哲学
           << "我思故我在。——笛卡尔"
           << "未经审视的人生不值得过。——苏格拉底"
           << "人是一根会思考的芦苇。——帕斯卡尔"
           << "人生而自由，却无往不在枷锁之中。——卢梭"
           << "存在先于本质。——萨特"
           << "意志支配行为，行为塑造人生。——叔本华"
           << "幸福是灵魂的合德性实现活动。——亚里士多德"
           << "爱我们所爱，但不执着于所爱。——马可·奥勒留《沉思录》"
           << "自由不是想做什么就做什么，而是不想做什么就能不做。——康德"
           << "世界上只有一种英雄主义，就是在认清生活真相后依然热爱生活。——罗曼·罗兰"

           // 继续新增 ↓↓↓
           << "道可道，非常道；名可名，非常名。——《道德经》"
           << "君子和而不同，小人同而不和。——《论语》"
           << "学而不思则罔，思而不学则殆。——《论语》"
           << "小不忍，则乱大谋。——《论语》"
           << "逝者如斯夫，不舍昼夜。——《论语》"

           << "万物皆虚，万事皆允。——理性主义哲思"
           << "痛苦是消极的快乐，快乐是积极的痛苦。——叔本华"
           << "凡不能毁灭我的，必使我强大。——尼采"
           << "人生而有知，知而能行，方为智慧。——培根"
           << "知识就是力量。——培根"

           << "君子之交淡如水，小人之交甘若醴。——《庄子》"
           << "吾生也有涯，而知也无涯。——《庄子》"
           << "不以物喜，不以己悲。——范仲淹《岳阳楼记》"
           << "先天下之忧而忧，后天下之乐而乐。——范仲淹"
           << "古之立大事者，不惟有超世之才，亦必有坚韧不拔之志。——苏轼"

           << "沉默是对诽谤最好的答复。——苏格拉底"
           << "美德即知识。——苏格拉底"
           << "一切伟大的行动和思想，都有一个微不足道的开始。——加缪"
           << "不要因为走得太远，而忘记为什么出发。——纪伯伦"
                      << "道生一，一生二，二生三，三生万物。——《道德经》"
           << "人法地，地法天，天法道，道法自然。——《道德经》"
           << "天地不仁，以万物为刍狗。——《道德经》"
           << "大智若愚，大巧若拙，大辩若讷。——《道德经》"
           << "合抱之木，生于毫末；九层之台，起于累土。——《道德经》"

           << "生于忧患，死于安乐。——《孟子》"
           << "天时不如地利，地利不如人和。——《孟子》"
           << "得道者多助，失道者寡助。——《孟子》"
           << "老吾老以及人之老，幼吾幼以及人之幼。——《孟子》"
           << "富贵不能淫，贫贱不能移，威武不能屈。——《孟子》"

           << "博学之，审问之，慎思之，明辨之，笃行之。——《中庸》"
           << "凡事预则立，不预则废。——《礼记》"
           << "玉不琢，不成器；人不学，不知道。——《礼记》"
           << "满招损，谦受益。——《尚书》"
           << "多行不义必自毙。——《左传》"

           << "君子坦荡荡，小人长戚戚。——《论语》"
           << "知之者不如好之者，好之者不如乐之者。——《论语》"
           << "三人行，必有我师焉。——《论语》"
           << "温故而知新，可以为师矣。——《论语》"
           << "见贤思齐焉，见不贤而内自省也。——《论语》"

           << "君子喻于义，小人喻于利。——《论语》"
           << "言必信，行必果。——《论语》"
           << "过而不改，是谓过矣。——《论语》"
           << "工欲善其事，必先利其器。——《论语》"
           << "君子欲讷于言而敏于行。——《论语》"

           << "吾生也有涯，而知也无涯。——《庄子》"
           << "相濡以沫，不如相忘于江湖。——《庄子》"
           << "天地与我并生，而万物与我为一。——《庄子》"
           << "至人无己，神人无功，圣人无名。——《庄子》"
           << "井蛙不可以语于海者，拘于虚也。——《庄子》"

           << "锲而舍之，朽木不折；锲而不舍，金石可镂。——《荀子》"
           << "不积跬步，无以至千里；不积小流，无以成江海。——《荀子》"
           << "青，取之于蓝，而青于蓝。——《荀子》"
           << "蓬生麻中，不扶而直；白沙在涅，与之俱黑。——《荀子》"
           << "君子博学而日参省乎己，则知明而行无过矣。——《荀子》"

           << "天下熙熙，皆为利来；天下攘攘，皆为利往。——《史记》"
           << "智者千虑，必有一失；愚者千虑，必有一得。——《史记》"
           << "运筹帷幄之中，决胜千里之外。——《史记》"
           << "飞鸟尽，良弓藏；狡兔死，走狗烹。——《史记》"
           << "前事不忘，后事之师。——《战国策》"

           << "人是万物的尺度。——普罗泰戈拉"
           << "美德即知识，无知即罪恶。——苏格拉底"
           << "教育不是灌输，而是点燃火焰。——苏格拉底"
           << "我知道我一无所知。——苏格拉底"
           << "良好的开端，等于成功的一半。——柏拉图"

           << "吾爱吾师，吾更爱真理。——亚里士多德"
           << "幸福是人生的终极目的。——亚里士多德"
           << "放纵自己的欲望是最大的祸害。——亚里士多德"
           << "勇气是衡量灵魂大小的标准。——西塞罗"
           << "命运指引愿意的人，拖拽不愿意的人。——塞涅卡"

           << "人生的幸福，在于内心的宁静。——马可·奥勒留《沉思录》"
           << "你所见的一切，都将很快改变并不复存在。——马可·奥勒留"
           << "快乐不是拥有的多，而是计较的少。——哲学家波埃修斯"
           << "知识就是力量。——培根"
           << "阅读使人充实，会谈使人敏捷，写作使人精确。——培根"

           << "人只不过是一根芦苇，是自然界最脆弱的东西。——帕斯卡尔"
           << "我们的本质，是我们重复的行为。——亚里士多德"
           << "没有绝望的处境，只有对处境绝望的人。——培根"
           << "世界上唯有两样东西能让我们内心震撼：星空与道德律。——康德"
           << "自由是我可以不做某事，而非只能做某事。——康德"
           << "人生的意义不在于手握一副好牌，而在于打好一手坏牌。";

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




void Widget::on_botolvBox_currentIndexChanged(int index)
{
     // 获取当前选中的文本
    QString currentText = ui->botolvBox->itemText(index);

    // 判断是否是 Custom（大小写不敏感）
    if (currentText.compare("Custom", Qt::CaseInsensitive) == 0) {
        ui->botolvEdit->setVisible(true);
        ui->okButton->setVisible(true);
        ui->quitButton->setVisible(true);
        ui->groupBox_2->setVisible(true);
    }
}


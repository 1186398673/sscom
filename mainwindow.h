#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void updateGame();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsPixmapItem *player;
    QList<QGraphicsPixmapItem*> obstacles;
    QLabel *scoreLabel;

    QTimer *timer;
    int playerSpeed;
    int gravity;
    int velocity;
    int obstacleSpeed;
    int obstacleInterval;
    int obstacleTimer;
    bool isJumping;
    bool canDoubleJump; // 新增状态变量
    int score;
    const int MIN_OBSTACLE_INTERVAL = 20;

    void spawnObstacle();
    void moveObstacles();
    void checkCollision();
};
#endif // MAINWINDOW_H

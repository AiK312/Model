#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    const int g = 4;
    int u = ui->uLine->text().toInt();
    int x0 = ui->x0Line->text().toInt();
    const int t = 1;
    QVector<double> QVAZI(10);
    QVector<double> EXP(10);
    ui->textBrowser->setText("Квазимерное распределение =.= экпоненциальное распределение");
    for(int i=0; i<10; i++)
    {
        int lamda1 = pow(8, t) * t + 3;
        int lamda2 = pow(8, t) * t - 3;
        int lamda = (lamda1 < lamda2) ? lamda1 : lamda2;
        int temp = lamda * x0 + u;
        std::bitset<g> bit = temp;
        std::string str = bit.to_string();
        QString qstr = QString::fromStdString(str);
        std::bitset<g> bitset(str);
        temp = bitset.to_ulong();
        double res = temp / pow(2, g);
        QVAZI[i] = res;
        EXP[i] = -1/0.8*log(QVAZI[i]);
        ui->textBrowser->append(QString::number(QVAZI.at(i))+
                                "\t=.=\t" + QString::number(EXP.at(i)));
        x0 = temp;

    }


}

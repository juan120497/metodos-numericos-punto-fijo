#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<cmath>
#include "QDoubleSpinBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Calcular,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borra,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
double MainWindow::funcion(double c){
    return(667.38/c*(1-exp(-0.146843*c)))-40;

}
void MainWindow::metodo(){
    QString temp,temp2,temp3;
    double x1=ui->X1->value();
    double err=ui->Error->value();
    double xr=0.0;
    double ea=100.0;
    while(ea>err){
        xr=funcion(x1);
        ea=100*std::abs(xr-x1)/xr;
        x1=xr;

    }
    temp.append("Raiz=").append(temp2.setNum(xr)).append("\nError=").append(temp3.setNum(ea));
    ui->Texto->setText(temp);

}
void MainWindow::borrar(){
    ui->X1->setValue(0.0);
    ui->Error->setValue(0.0);
    ui->Texto->clear();
}

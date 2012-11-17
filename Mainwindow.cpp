#include "Mainwindow.h"
#include "ui_Mainwindow.h"

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

void MainWindow::on_botao_inicio_simulacao_clicked()
{
    ui->botao_parar_simulacao->setEnabled(true);
    ui->botao_pausar_simulacao->setEnabled(true);
    ui->botao_inicio_simulacao->setEnabled(false);

    //TODO chamar metodo que inicia a simulaçao
}

void MainWindow::on_botao_parar_simulacao_clicked()
{
    ui->botao_parar_simulacao->setEnabled(false);
    ui->botao_pausar_simulacao->setEnabled(false);
    ui->botao_inicio_simulacao->setEnabled(true);
    ui->botao_avancar_simulacao->setEnabled(false);
    ui->botao_pausar_simulacao->setText("Travar");

    //TODO chamar metodo que encerra a simulação
}

void MainWindow::on_botao_pausar_simulacao_clicked()
{
    if(ui->botao_pausar_simulacao->text().toStdString() == "Travar" ){
        ui->botao_pausar_simulacao->setText("Continuar");
        ui->botao_avancar_simulacao->setEnabled(true);
        //TODO travar a simulacao

    }else{  //Texto atual = Continuar
        ui->botao_pausar_simulacao->setText("Travar");
        ui->botao_avancar_simulacao->setEnabled(false);
        //TODO continuar a simulacao

    }
}

void MainWindow::on_botao_avancar_simulacao_clicked()
{
    //TODO avancar o numero de eventos da barrinha
}

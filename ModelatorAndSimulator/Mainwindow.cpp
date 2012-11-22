#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "criadouro.h"
#include "central.h"
#include "distribuicao.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    sim = NULL;
    ui->setupUi(this);
    nServidoresLocais = nServidoresRemotos = 1;
    tempoDeSimulacao = 10000;

    // Default values
    Criadouro::set_media(100);
    Central::set_percent_for_inf(50, 50);
    Central::set_percent_for_sup(50, 50);
    Central::set_percent_for_SUCESSO(60);
    Central::set_percent_for_FRACASSO(30);
    Central::set_percent_for_ADIAMENTO(10);
    //Distribuicao::
    //Estatisticas::
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

    if(sim == NULL){
        cout << tempoDeSimulacao << " locais:"<< nServidoresLocais << " remotos:"<< nServidoresRemotos << endl;
        sim = new Simulador(Time(tempoDeSimulacao),nServidoresLocais,nServidoresRemotos);
    }

    cout << "Simulador criado" << endl;

    sim->simular(); //Thread
    // Execucao de simulacao acabou, realizar mesmas atitudes que ocorrem quando o botao stop e apertado.
}

void MainWindow::on_botao_parar_simulacao_clicked()
{
    ui->botao_parar_simulacao->setEnabled(false);
    ui->botao_pausar_simulacao->setEnabled(false);
    ui->botao_inicio_simulacao->setEnabled(true);
    ui->botao_avancar_simulacao->setEnabled(false);
    ui->botao_pausar_simulacao->setText("Travar");

    sim->stop();
    delete sim;
    //sim = NULL;
}

void MainWindow::on_botao_pausar_simulacao_clicked()
{
    if(ui->botao_pausar_simulacao->text().toStdString() == "Travar" ){
        ui->botao_pausar_simulacao->setText("Continuar");
        ui->botao_avancar_simulacao->setEnabled(true);
        sim->stop();

    }else{  //Texto atual = Continuar
        ui->botao_pausar_simulacao->setText("Travar");
        ui->botao_avancar_simulacao->setEnabled(false);
        sim->simular();

    }
}

void MainWindow::on_botao_avancar_simulacao_clicked()
{
    sim->step();
}

void MainWindow::on_tamanho_passo_valueChanged(int value)
{
    stringstream ss;
    ss << value;
    ui->tamanho_passo_tela->setText(QString(ss.str().c_str()));
}

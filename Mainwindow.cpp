#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "criadouro.h"
#include "central.h"
#include "distribuicao.h"
#include <pthread.h>


void *simThread(void * sim)
{
    cout << "entrou aquii na thread" << endl;
    ((Simulador*)sim)->simular();
    cout << "terminou de simular na thread" << endl;
    return (void*)NULL;
}


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

    pthread_t t; //Thread
    pthread_create(&t, NULL, simThread, (void *)sim);
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
    sim = NULL;
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
        pthread_t t; //Thread
        pthread_create(&t, NULL, simThread, (void *)sim); //Thread
    }
}

void MainWindow::on_botao_avancar_simulacao_clicked()
{
    sim->step();
}

void MainWindow::on_edit_serv_local_returnPressed()
{
    int valor = ui->edit_serv_local->text().toInt();
    if(valor < 1){
        valor = 1;
        stringstream ss;
        ss << valor;
        ui->edit_serv_local->setText(QString(ss.str().c_str()));
    }
    if(valor > 300){
        valor = 300;
        stringstream ss;
        ss << valor;
        ui->edit_serv_local->setText(QString(ss.str().c_str()));
    }
    //sim->set_localServers(valor);
}

void MainWindow::on_edit_suc_local_returnPressed()
{
    int valor = ui->edit_suc_local->text().toInt();
    if(valor < 0){
        valor = 0;
        stringstream ss;
        ss << valor;
        ui->edit_suc_local->setText(QString(ss.str().c_str()));
    }
    if(valor +  ui->edit_frac_local->text().toInt() > 100){
        valor = 100 -  ui->edit_frac_local->text().toInt();
        stringstream ss;
        ss << valor;
        ui->edit_suc_local->setText(QString(ss.str().c_str()));
    }
    //sim->set_localSucesso(valor);
}

void MainWindow::on_edit_frac_local_returnPressed()
{
    int valor = ui->edit_frac_local->text().toInt();
    if(valor < 0){
        valor = 0;
        stringstream ss;
        ss << valor;
        ui->edit_frac_local->setText(QString(ss.str().c_str()));
    }
    if(valor +  ui->edit_suc_local->text().toInt() > 100){
        valor = 100 -  ui->edit_suc_local->text().toInt();
        stringstream ss;
        ss << valor;
        ui->edit_frac_local->setText(QString(ss.str().c_str()));
    }
    //sim->set_localFracasso(valor);
}

void MainWindow::on_edit_serv_remoto_returnPressed()
{
    int valor = ui->edit_serv_remoto->text().toInt();
    if(valor < 1){
        valor = 1;
        stringstream ss;
        ss << valor;
        ui->edit_serv_remoto->setText(QString(ss.str().c_str()));
    }
    if(valor > 300){
        valor = 300;
        stringstream ss;
        ss << valor;
        ui->edit_serv_remoto->setText(QString(ss.str().c_str()));
    }
    //sim->set_remotoServs(valor);
}

void MainWindow::on_edit_suc_remoto_returnPressed()
{
    int valor = ui->edit_suc_remoto->text().toInt();
    if(valor < 0){
        valor = 0;
        stringstream ss;
        ss << valor;
        ui->edit_suc_remoto->setText(QString(ss.str().c_str()));
    }
    if(valor +  ui->edit_frac_remoto->text().toInt() > 100){
        valor = 100 -  ui->edit_frac_remoto->text().toInt();
        stringstream ss;
        ss << valor;
        ui->edit_suc_remoto->setText(QString(ss.str().c_str()));
    }
    //sim->set_remotoSucesso(valor);
}

void MainWindow::on_edit_frac_remoto_returnPressed()
{
    int valor = ui->edit_frac_remoto->text().toInt();
    if(valor < 0){
        valor = 0;
        stringstream ss;
        ss << valor;
        ui->edit_frac_remoto->setText(QString(ss.str().c_str()));
    }
    if(valor +  ui->edit_suc_remoto->text().toInt() > 100){
        valor = 100 -  ui->edit_suc_remoto->text().toInt();
        stringstream ss;
        ss << valor;
        ui->edit_frac_remoto->setText(QString(ss.str().c_str()));
    }
    //sim->set_remotoFracasso(valor);
}

void MainWindow::on_tamanho_passo_tela_textChanged()
{
    int valor;
    if(ui->tamanho_passo_tela->text().isEmpty())
        valor = 1;
    else
        valor = ui->tamanho_passo_tela->text().toInt();

    if(valor < 1){
        valor = 1;
        stringstream ss;
        ss << valor;
        ui->tamanho_passo_tela->setText(QString(ss.str().c_str()));
    }
    if(valor > 200){
        valor = 200;
        stringstream ss;
        ss << valor;
        ui->tamanho_passo_tela->setText(QString(ss.str().c_str()));
    }

    ui->tamanho_passo->setSliderPosition(valor);
}

void MainWindow::on_tamanho_passo_sliderReleased()
{
    stringstream ss;
    ss << ui->tamanho_passo->value();
    ui->tamanho_passo_tela->setText(QString(ss.str().c_str()));
}

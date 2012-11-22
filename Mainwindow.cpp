#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "criadouro.h"
#include "central.h"
#include "distribuicao.h"
#include <pthread.h>


void *simThread(void * sim)
{
    ((Simulador*)sim)->simular();
    return (void*)NULL;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    sim = NULL;
    ui->setupUi(this);
    nServidoresLocais = ui->edit_serv_local->text().toInt();
    nServidoresRemotos = ui->edit_serv_remoto->text().toInt();

    taxa_suc_local = ui->edit_suc_local->text().toInt();
    taxa_frac_local = ui->edit_frac_local->text().toInt();
    taxa_suc_remoto = ui->edit_suc_remoto->text().toInt();
    taxa_frac_remoto = ui->edit_frac_remoto->text().toInt();
    // Default values
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
        int local_ints[] = {nServidoresLocais, taxa_suc_local, taxa_frac_local };
        double local_doubles[] = {ll_inf, lr_inf, ll_sup, lr_sup};
        int remoto_ints[] = {nServidoresRemotos, taxa_suc_remoto, taxa_frac_remoto };
        double remoto_doubles[] = {rl_inf, rr_inf, rl_sup, rr_sup};
        cout << ui->tamanhoDaSimulacao->text().toDouble() << " locais:"<< nServidoresLocais << " remotos:"<< nServidoresRemotos << endl;
        sim = new Simulador(Time(ui->tamanhoDaSimulacao->text().toDouble()),local_ints, local_doubles, remoto_ints, remoto_doubles);
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
    amostrarEstatisticas();
    delete sim;
    sim = NULL;
}

void MainWindow::on_botao_pausar_simulacao_clicked()
{
    if(ui->botao_pausar_simulacao->text().toStdString() == "Travar" ){
        ui->botao_pausar_simulacao->setText("Continuar");
        ui->botao_avancar_simulacao->setEnabled(true);
        amostrarEstatisticas();
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

void MainWindow::on_edit_serv_local_textChanged(const QString &arg1)
{
    int valor = arg1.toInt();
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
    nServidoresLocais = valor;
}

void MainWindow::on_edit_suc_local_textChanged(const QString &arg1)
{
    int valor = arg1.toInt();
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
    taxa_suc_local = valor;
}

void MainWindow::on_edit_frac_local_textChanged(const QString &arg1)
{
    int valor = arg1.toInt();
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
    taxa_frac_local = valor;
}

void MainWindow::on_edit_serv_remoto_textChanged(const QString &arg1)
{
    int valor = arg1.toInt();
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
    nServidoresRemotos = valor;
}

void MainWindow::on_edit_suc_remoto_textChanged(const QString &arg1)
{
    int valor = arg1.toInt();
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
    taxa_suc_remoto = valor;
}

void MainWindow::on_edit_frac_remoto_textChanged(const QString &arg1)
{
    int valor = arg1.toInt();
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
    taxa_frac_remoto = valor;
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
    if(valor > 500){
        valor = 500;
        stringstream ss;
        ss << valor;
        ui->tamanho_passo_tela->setText(QString(ss.str().c_str()));
    }

    ui->tamanho_passo->setSliderPosition(valor);
    sim->set_stepsPerSeond(ui->tamanho_passo->value());
}

void MainWindow::on_tamanho_passo_valueChanged(int value)
{
    stringstream ss;
    ss << value;
    if(value != ui->tamanho_passo_tela->text().toInt())
        ui->tamanho_passo_tela->setText(QString(ss.str().c_str()));
    sim->set_stepsPerSeond(value);
}

void MainWindow::amostrarEstatisticas()
{
    string e = sim->coletarEstatisticas();
    ui->caixa_estatistica->setText(QString(QString::fromStdString(e)));
}

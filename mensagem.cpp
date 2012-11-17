#include "mensagem.h"

Mensagem::Mensagem(int remetente, int destinatario, Time tnow){
    this->_remetente = remetente;
    this->_destinatario = destinatario;
    this->_situacao = INDEFINIDO;
    this->_stamp = tnow;
}

int Mensagem::remetente(){
    return _remetente;
}

int Mensagem::destinatario(){
    return _destinatario;
}

int  Mensagem::situacao(){
    return _situacao;
}

void Mensagem::set_situacao(int novo){
    if(novo==SUCESSO || novo==FRACASSO || novo==ADIAMENTO)
        _situacao = novo;
}

Time Mensagem::time(){
    return _stamp;
}


void Mensagem::stamp(Time& tnow){
    _stamp = tnow;
}

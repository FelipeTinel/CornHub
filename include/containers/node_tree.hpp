#pragma once

#include <iostream>

#include <string>

#include "core/content.hpp"
#include "core/question.hpp"

struct NodeTree {

    Question * question = nullptr;
    DoublyLinkedList<std::string> node_prio_list;

    NodeTree * no = nullptr;
    NodeTree * yes = nullptr;
    
    NodeTree() :  question(nullptr), no(nullptr), yes(nullptr) {}

};


/*
if (no){
    código de priorização de vetor roda
    vetor aponta pra proxima pergunta
}

as perguntas são feitas de forma pre processadas, 

a arvore é instanciada no construtor, 
criando as perguntas com base nas listas de generos e subgeneros, 
e as perguntas são feitas de forma pre processadas,

para testar a gente pode criar os objetos de genero da main 
e criar um metodo de adicionar subgenero na lista deles,
adicionando subgeneros e generos, e depois instanciando a arvore,
e depois testando a busca de perguntas na arvore,

e vão jogar o proximo nó da arvore,
*/
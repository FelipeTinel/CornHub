#include <iostream>
#include <string>

#include "containers/binary_tree.hpp"
#include "core/question.hpp"
#include "core/genre.hpp"


void BinaryTree::build_tree(DoublyLinkedList<Genre>& genreList) {
    root = build_genre_nodes(genreList.get_head());
}

NodeTree* BinaryTree::build_genre_nodes(Node<Genre>* current) {
    if (current == nullptr) return nullptr;

    NodeTree* node = new NodeTree();
    
    // Cria a pergunta de gênero
    node->question = new Question(current->info, true);
    
    // Caminho YES: Aprofunda nos subgêneros deste gênero
    node->yes = build_subgenre_nodes(current->info.get_subgenres().get_head());
    
    // Caminho NO: Vai para o próximo gênero da lista principal
    node->no = build_genre_nodes(current->next);

    return node;
}

NodeTree* BinaryTree::build_subgenre_nodes(Node<std::string>* currentSub, int cont_priority;) {
    //recebe o ponteiro pra cabeça da lista de subgeneros
    //inicia pergunta com a o subgenero atual -> question só recebe como parametro um string subgenero
    //o contador: ele conta 
    //recebe a lista de prioridade atual e um contador com o numero do indice do subgenero da lista de subgeneros que 
    //está sendo comparado com a lista de prioridades
    if(cont_priority == )
    
    if (currentSub == nullptr) return nullptr;

    NodeTree* node = new NodeTree();
    
    // Cria a pergunta de subgênero
    // Nota: você pode precisar de um construtor que aceite apenas string/subgênero
    node->question = new Question(currentSub->info, false); 
    
    // O próximo subgênero continua a lista de perguntas
    // Em uma lista de subgêneros, o 'no' ou 'yes' pode seguir a lógica de priorização
    node->yes = build_subgenre_nodes(currentSub->next); 
    node->no = build_subgenre_nodes(currentSub->next);

    return node;
}

//querendo ou não a arvore precisa ser construida de acordo com o vetor prioridade né ?
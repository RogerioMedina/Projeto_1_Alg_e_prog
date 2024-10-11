#include <iostream>
#include <string.h>
using namespace std;

struct pessoa{
    char nome[50];
};

struct livros{
    char titulo[100];
    char autor[100];
    int num_pag;
    int ano_publi;
    int id;
    int qtd_disp;
    struct pessoa locatarios[10];
    
};

void cadastroLivros(livros vec[], int *num_livro, int *id){
    // ID Cadastrado automaticamente, garantido que não será repetido
    vec[*num_livro].id = *id;

    cout << "\n=====================================\n";
    cout << "       CADASTRO DE LIVRO   |  ID: " << *id;                    
    cout << "\n=====================================\n";
    
    cout << "Titulo: ";
    cin.ignore();
    cin.getline(vec[*num_livro].titulo, 100);
    
    cout << "=====================================\n";
    cout << "Autor: ";
    cin.getline(vec[*num_livro].autor,100);
    
    cout << "=====================================\n";
    cout << "Numero de paginas: ";
    cin >> vec[*num_livro].num_pag;
    
    cout << "=====================================\n";
    cout << "Ano Publicação: ";
    cin >> vec[*num_livro].ano_publi;
    
    cout << "=====================================\n";
    while(true){
        cout << "Quantidade disponivel: ";
        cin >> vec[*num_livro].qtd_disp;
        if(vec[*num_livro].qtd_disp <= 0 || vec[*num_livro].qtd_disp > 10){
            cout << "=====================================\n";
            cout << "\tDigite valores válidos!\n\t  Tente novamente" << endl;
            cout << "=====================================\n";
            continue;
        }
        for(int i = 0; i < vec[*num_livro].qtd_disp; i++){
            strcpy(vec[*num_livro].locatarios[i].nome, "");
        }
        break;
    }
    
    cout << "\n=====================================\n";
    cout << "       LIVRO CADASTRADO   |  ID: " << *id;                    
    cout << "\n=====================================\n";
    
    (*num_livro)++;
    (*id)++;
}

void printLivros(livros livro){
    cout << "-------------- Livro -------------" << endl;
    cout << "ID Livro: " << livro.id << endl;
    cout << "Titulo: " << livro.titulo << endl;
    cout << "Autor: " << livro.autor << endl;
    cout << "Numero de paginas: " << livro.num_pag << endl;
    cout << "Ano Publicação: " << livro.ano_publi << endl;
    cout << "Quantidade disponível: " << livro.qtd_disp << endl;
    cout << "----------------------------------" << endl;
}

void consultarLivros(livros l[], int quant){ 

    /*precisa retirar o ponteiro, pois o valor quant não é alterado na função.*/

    int opt, id;
    int pos;
    bool encontrado = false;
    char nome_livro[100];
    
    if(quant == 0){
        cout << "\n=====================================\n";
        cout << "       NÃO HÁ LIVROS CADASTRADOS         ";
        cout << "\n=====================================\n";
        return;
    }
    
    do
    {
        cout << "\n=====================================\n";
        cout << "            CONSULTAR LIVRO            ";
        cout << "\n=====================================\n";
        cout << "           1 - Mostrar todos" << endl;
        cout << "           2 - Buscar por nome" << endl;
        cout << "           3 - Buscar por ID" << endl;
        cout << "=====================================\n";
        cout << "Digite a opção: ";
        cin >> opt;
    }while(opt < 1 || opt > 3);
    
    switch(opt){
        case 1:
            for(int i = 0; i < quant; i++) printLivros(l[i]);
            encontrado = true;
            break;
        case 2:
            cout << "Insira o nome do livro: ";
            cin.ignore();
            cin.getline(nome_livro, 100);
            
            for(int i = 0; i < quant; i++){
                if(strcmp(nome_livro, l[i].titulo) == 0){
                    encontrado = true;
                    printLivros(l[i]);
                }
            }
            break;
        case 3:
            cout << "Insira o ID do livro: ";
            cin >> id;
            
            for(int i = 0; i < quant; i++){
                if(l[i].id == id){
                    encontrado = true;
                    printLivros(l[i]);
                }
            }
            break;
    }
    if(!encontrado) {
        cout << "\n=====================================\n";
        cout << "            LIVRO NÃO ENCONTRADO         ";
        cout << "\n=====================================\n";
    }
    
}

void emprestimoLivros(struct livros l[], int quantidade){
    int opc = 0;
    int indice;
    
    do{
        cout<<"Como deseja procurar o livro para emprestimo?"<<endl;
        cout<<"1- Por ID\n2- Por nome" << endl;
        cin>>opc;
        if(opc != 1 && opc != 2){
            cout<<"Digite uma opção valida"<<endl;
        }
    }while(opc != 1 && opc != 2);

    if(opc == 1){
        int id;
        cout<<"Insira o ID do livro: ";
        cin>>id;
        
        for(indice = 0; indice < quantidade; indice++){
            if(l[indice].id == id){
                break;    
            }
        }
    }

    if(opc == 2){
        char titulo[100];
        cout<<"Insira o nome do livro: ";
        cin.getline(titulo, 100);

        for(indice = 0; indice < quantidade; indice++){
            if(strcmp(l[indice].titulo, titulo) != 0){
                break;    
            }
        }
    }

    if(l[indice].qtd_disp > 0){
        char nome[100];
    
        cout<<"Insira seu nome: ";
        cin.ignore();
        cin.getline(nome, 100);

        strcpy(l[indice].locatarios[10-l[indice].qtd_disp].nome, nome);
        
        cout<<"Livro emprestado com sucesso." << endl;
        (l[indice].qtd_disp)--;
        
    }else{
        cout<<"Não há mais copias disponiveis";
    }


}

void devolucaoLivros(struct livros livro[], int quant){

    int ID;
    char nome[100];
    cout << "Qual ID do livro que será devolvido? ";
    cin >> ID;

    cout << "Qual o nome do locatário? ";
    cin.ignore();
    cin.getline(nome,100);

    for(int i = 0; i < quant; i++){
        if(livro[i].id == ID){
            for(int j = 0; j < (10-(livro[i].qtd_disp)); j++){
                if(strcmp(livro[i].locatarios[j].nome, nome)==0){
                    strcpy(livro[i].locatarios[j].nome, "");
                    cout << "Livro devolvido. Obrigado!" << endl;
                    (livro[i].qtd_disp)++;
                    break;
                }
                cout << "Locatário não encontrado" << endl;
            }

        }
    }

}

void removerLivro(struct livros vec[], int *num_livros){
    while(true){
        int id;
        cout << "Digite o ID do livro para remover do acervo: ";
        cin >> id;

        int pos;
        bool encontrado = false;
        for(int i = 0; i < *num_livros; i++){
            if(vec[i].id == id){
                encontrado = true;
                pos = i;
                break;
            }
        }
        if(encontrado){
            for(int i = pos; i < (*num_livros-1); i++){
                vec[i] = vec[i+1];
            }
            cout << "livro removido!";
            (*num_livros)--;
            break;
        }else{
            cout << "\nLivro não encontrado!\nTente novamente!";
            continue;
        }
    }
}

int main()
{
    struct livros vetorLivros[100];
    int *num_livros = new int;
    *num_livros = 0;
    int *id_manager = new int;
    *id_manager = 1;
    int opt = 0;

    while(opt != 6){
        cout << "=====================================" << endl;
        cout << "---------------MENU------------------" << endl;
        cout << "=====================================" << endl;
        cout << "----- 1 - Cadastrar Livro -----------" << endl;
        cout << "----- 2 - Consultar livro -----------" << endl;
        cout << "----- 3 - Emprestimos de livros -----" << endl;
        cout << "----- 4 - Devolucao de livros -------" << endl;
        cout << "----- 5 - Remocao de livros ---------" << endl;
        cout << "----- 6 - Sair do programa ----------" << endl;
        cout << "=====================================" << endl;
        cout << "Selecione a opcao desejada: ";
        cin >> opt;
    
        switch (opt){
        case 1:
            cadastroLivros(vetorLivros, num_livros, id_manager);
            break;
        case 2:
            consultarLivros(vetorLivros, *num_livros);
            break;
        case 3:
            emprestimoLivros(vetorLivros, *num_livros);
            break;
        case 4: 
            devolucaoLivros(vetorLivros, *num_livros);
            break;
        case 5:
            removerLivro(vetorLivros, num_livros);
            break;
        case 6:
            exit;
            break;
        }
    }
    return 0;
}

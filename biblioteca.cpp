#include <iostream>
#include <string.h>
using namespace std;

// participantes: Enzo, Gabriel, Henry, Rogerio

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
    
    int opt = 0;
    do{
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
    cout << "Ano Publicacao: ";
    cin >> vec[*num_livro].ano_publi;
    
    cout << "=====================================\n";
    while(true){
        cout << "Quantidade disponivel: ";
        cin >> vec[*num_livro].qtd_disp;
        if(vec[*num_livro].qtd_disp <= 0 || vec[*num_livro].qtd_disp > 10){
            cout << "=====================================\n";
            cout << "\tDigite valores validos!\n\t  Tente novamente" << endl;
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

    cout << "Deseja cadastrar outro livro?\n";
    cout << "1 - Sim / 2 - Nao"<< endl;
    cout << "Opcao: ";
    cin >> opt;

    }
    while(opt == 1);
}

void printLivros(livros livro){
    cout << "---------------- Livro --------------" << endl;
    cout << "ID Livro: " << livro.id << endl;
    cout << "Titulo: " << livro.titulo << endl;
    cout << "Autor: " << livro.autor << endl;
    cout << "Numero de paginas: " << livro.num_pag << endl;
    cout << "Ano Publicacao: " << livro.ano_publi << endl;
    cout << "Quantidade disponivel: " << livro.qtd_disp << endl;
    cout << "-------------------------------------" << endl;
}

void printLocatarios(livros livro[], int quant, int ID, int *locatarios){
    for(int j = 0; j<quant; j++){
        if(livro[j].id == ID)
        {
            printLivros(livro[j]);
            if(livro[j].qtd_disp < 10)
            {
                cout << "Locatários com o livro " << livro[j].titulo << ":" << endl;
                cout << "=====================================" << endl; 
                for (int i = 0; i < (10-livro[j].qtd_disp); i++)
                {
                    if (strcmp(livro[j].locatarios[i].nome, "") != 0)
                        cout << "- " << livro[j].locatarios[i].nome << endl;
                }
            }else{
                cout << "Nenhum locatário encontrado para o livro com ID " << ID << "." << endl; 
            }
            break;
        }
    }
    cout << "=====================================" << endl;
}

void consultarLivros(livros l[], int quant){ 

    int opt, id, pos, busca;
    char nome_livro[100];
    
    if(quant == 0){
        cout << "\n=====================================\n";
        cout << "       NAO HA LIVROS CADASTRADOS         ";
        cout << "\n=====================================\n";
        return;
    }
    
    do{
        bool encontrado = false;
        do
        {
            cout << "\n=====================================\n";
            cout << "            CONSULTAR LIVRO            ";
            cout << "\n=====================================\n";
            cout << "           1 - Mostrar todos" << endl;
            cout << "           2 - Buscar por nome" << endl;
            cout << "           3 - Buscar por ID" << endl;
            cout << "=====================================\n";
            cout << "Digite a opcao: ";
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
            cout << "            LIVRO NAO ENCONTRADO         ";
            cout << "\n=====================================\n";
        }
        cout << "Deseja fazer nova busca?" << endl;
        cout << "1 - Sim / 2 - Nao" << endl;
        cout << "Opcao: ";
        cin >> busca;

    }while(busca == 1);

}

void emprestimoLivros(struct livros l[], int quantidade){
    
    int opc = 0, locatarios = 0;
    int indice, novo;
    
    do{
        do{
            cout<<"\n=====================================\n";
            cout << "   Como deseja procurar o livro?"<<endl;
            cout << "   1- Por ID\n   2- Por nome" << endl;
            cout << "=====================================\n";
            cout <<"Opcao: ";
            cin>>opc;
            if(opc != 1 && opc != 2){
                cout << "=====================================\n";
                cout<<"         Digite uma opcao valida"<<endl;
                cout << "\n=====================================\n";
            }
            cout << "=====================================\n";
        }while(opc != 1 && opc != 2);

        if(opc == 1){
            int id;
            cout<<"Insira o ID do livro: ";
            cin>>id;
            
            for(indice = 0; indice < quantidade; indice++){
                if(l[indice].id == id){
                    printLivros(l[indice]);
                    break;    
                }
            }
        }
        if(opc == 2){
            char titulo[100];
            cout<<"Insira o nome do livro: ";
            cin.ignore();
            cin.getline(titulo, 100);

            for(indice = 0; indice < quantidade; indice++){
                if(strcmp(l[indice].titulo, titulo) == 0){
                    printLivros(l[indice]);
                    break;    
                }
            }
        }
        if(l[indice].qtd_disp > 0){
            char nome[100];

            for(int i = 0; i<10; i++){
                if(strcmp(l[indice].locatarios[i].nome, "") != 0){
                    locatarios ++;
                }
            }
            cout<<"Insira o nome do locatario: ";
            cin.ignore();
            cin.getline(nome, 100);

            strcpy(l[indice].locatarios[locatarios].nome, nome);
            
            cout<<"Livro emprestado com sucesso." << endl;
            (l[indice].qtd_disp)--;
            
        }else{
            cout << "\n=====================================\n";
            cout << "       Nao Ha copias disponiveis"<< endl;
            cout << "=====================================\n";
        }
        cout << "\n=====================================\n";
        cout << "Deseja fazer novo emprestimo?" << endl;
        cout << "1 - Sim / 2 - Nao" << endl;
        cout << "Opcao: ";
        cin >> novo;
        cout << "=====================================\n";
    }while (novo == 1);

}

void devolucaoLivros(struct livros livro[], int quant){

    int opt = 0;
    int locatarios = 0;
    do{
        int ID;
        char nome[100];

        cout<<"\n=====================================\n";
        cout << "Digite ID do Livro: ";
        cin >> ID;
        cout<<"=====================================\n";

        printLocatarios(livro, quant, ID, &locatarios);

        cout << "Qual o nome do locatario? ";
        cin.ignore();
        cin.getline(nome,100);

        for(int i = 0; i < quant; i++){
            if(livro[i].id == ID){
                for(int j = 0; j < (10); j++){
                    if(strcmp(livro[i].locatarios[j].nome, nome)==0){
                        strcpy(livro[i].locatarios[j].nome, "");
                        cout << "=====================================\n";
                        cout << "      Livro devolvido. Obrigado!" << endl;
                        cout << "=====================================\n";
                        (livro[i].qtd_disp)++;
                        break;
                    }else if(j==9){
                        cout << "Locatario nao encontrado" << endl;
                    }
                }
            }
        }
        cout << "Deseja fazer outra devolucao?" << endl;
        cout << "1 - Sim / 2 - Nao" << endl;
        cout << "Opcao: ";
        cin >> opt;
    }while(opt == 1);
}

void removerLivro(struct livros vec[], int *num_livros){
    
    int removerMais = 0;
    do{
        while(*num_livros > 0){
            int id;
            int opt = 0;
            cout << "Deseja listar os livros cadastrados?\n";
            cout << "1 - Sim / 2 - Nao\n";
            cout << "Opcao: ";
            cin >> opt;

            if (opt == 1){
                for(int i = 0; i < *num_livros; i++){
                    printLivros(vec[i]);
                }
            }
            cout << "====================================="<<endl;       
            
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
                for(int i = pos; i < (*num_livros-1); i++)
                {
                    vec[i] = vec[i+1];
                }
                cout << "Livro removido!"<<endl;
                (*num_livros)--;
                break;
            }else{
                cout << "\nLivro nao encontrado!\nTente novamente!";
            }
        }
        if(*num_livros == 0){
           cout<<"Nao ha livros para remover"<<endl;
        }else{
            cout << "Deseja remover outro livro?\n";
            cout << "1 - Sim / 2 - Nao\n";
            cout << "Opcao: ";
            cin >> removerMais;
        }
    }while(removerMais == 1);
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

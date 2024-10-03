#include <iostream>
using namespace std;

struct pessoa{
    char nome[50];
    int telefone;
};

struct livros{
    char titulo[100];
    char autor[100];
    int num_pag;
    int ano_publi;
    int id;
    int qtd_disp[10];
    struct pessoa locatarios[10];
    
};

void cadastroLivros(struct livros *l){
    do
    {
        cout << "Titulo: ";
        cin.ignore();
        cin.getline(l->titulo, 100);
        cout << "Autor: ";
        cin.ignore();
        cin.getline(l->autor,100);
        cout << "Numero de paginas: ";
        cin >> l->num_pag;
        cout << "Ano Publicação: ";
        cin >> l->ano_publi;
        cout << "ID: ";
        cin >> l->id;
        cout << "Quantidade disponivel: ";
        cin >> l->qtd_disp;
    }while(qtd_disp < 0 || qtd_disp > 10);
}

void printLivros(livros l[], int n){
    for(int i = 0; i < n; i++){
        cout << "-------------- Livro -------------" << endl;
        cout << "ID Livro: " << l[i].id << endl;
        cout << "Titulo: " << l[i].titulo << endl;
        cout << "Autor: " << l[i].autor << endl;
        cout << "Numero de paginas: " << l[i].num_pag << endl;
        cout << "Ano Publicação: " << l[i].ano_publi << endl;
        cout << "Quantidade disponível: " << l[i].qtd_disp << endl;
        cout << "----------------------------------" << endl;
    }
}
void consultarLivros(livros l[], int quant){

    int opt, id;
    int pos;
    bool encontrado;
    char nome_livro[100];
    do
    {
        cout << "1 - Mostrar todos" << endl;
        cout << "2 - Buscar por nome" << endl;
        cout << "3 - Buscar por ID" << endl;
        cout << "----------------------" << endl;
        cout << "Digite a opção";
        cin >> opt;
    }while(opt < 1 || opt > 3);
    
    switch(opt){
        case 1:
                printLivros(l,quant);
            }
            break;
        case 2:
            cout << "Insira o nome do livro: ";
            cin.ignore();
            cin.getline(nome_livro,100);
            for(int i = 0; i < quant; i++){
                if(l[i].titulo == nome_livro){
                    printLivros(&l[i], quant);
                }
            }
            break;
        case 3:
            cout << "Insira o ID do livro: ";
            cin >> id;
            for(int i = 0; i < quant; i++){
                if(l[i].id == id){
                    printLivros(l[i], quant);
                }
            }
            break;
    }

/*

void consultarLivros(struct livros vetorLivros[], int quant){

    int opt, id;
    int pos;
    bool encontrado;
    char titulo[100];
    while(opt != 1 || opt != 2 || opt != 3){
        cout << "1 - Mostrar todos" << endl;
        cout << "2 - Buscar por nome" << endl;
        cout << "3 - Buscar por ID" << endl;
        cout << "----------------------" << endl;
        cout << "Digite a opção";
        cin >> opt;
    }
    if(opt == 1){
        for(int i = 0; i<quant; i++) printLivros(vetorLivros[i]);
    }
    else if (opt == 2){
        cout << "Digite o nome do livro: ";
        cin >> titulo; //arrumar a forma de colocar o titulo

        for(int i = 0; i < quant; i++){
            if(vetorLivros[i].titulo == titulo){
                pos = i;
                encontrado = true;
            }
        }
        if(encontrado == true){
            printLivros(vetorLivros[pos])
        }
        else{
            cout << "Livro não encontrado!";
        }

    }

    else{
        cout << "Digite o ID do livro: ";
        cin >> id;
       
        for(int i = 0; i < quant; i++){
            if(vetorLivros[i].id == id){
                pos = i;
                encontrado = true;
            }
        }
        if(encontrado == true){
            printLivros(vetorLivros[pos])
        }
        else{
            cout << "ID do livro não encontrado!";
        }
    }
}
*/

void emprstimoLivros(struct livros l[], int quantidade){
    int opc = 0;
    int indice;
    
    while(opc != 1 || opc != 2){
        cout<<"Como deseja procurar o livro para emprestimo?"<<endl;
        cout<<"1- Por ID\n-2- Por nome";
        cin>>opc;
        if(opc != 1 || opc != 2){
            cout<<"Digite uma opção valida"<<endl;
        }
    }

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
        char titulo = 100;
        cout<<"Insira o nome do livro: ";
        cin>>titulo;

        for(indice = 0; indice < quantidade; indice++){
            if(strcmp(l[indice].titulo, titulo) != 0){
                break;    
            }
        }
    }

    if(l[indice].qtd_disp > 0){
        char nome[100];
        int telefone;

        cout<<"Insira seu nome: ";
        cin>>nome;
        cout<<"Insira seu numero de telefone: ";
        cin>>telefone;

        l[indice].locatarios[11-l[indice].qtd_disp].nome = nome;
        l[indice].locatarios[11-l[indice].qtd_disp].telefone = telefone;

        cout<<"Livro emprestado com sucesso.";
        l[indice].qtd_disp = l[indice].qtd_disp-1;
    }else{
        cout<<"Não há mais copias disponiveis";
    }


}

void devolucaoLivros(struct livros l[], int *num_locatarios){ 
    int opc = 0;
    while(opc != 1 || opc != 2){
        cout << "Como deseja devolver o livro? " << endl;
        cout << "1-id \n2-titulo";
        cin >> opc;
        if(opc != 1 || opc != 2){
            cout<<"Digite uma opção valida"<<endl;
        if (opc == 1){
            int id,indice;
            cout << "Digite o id do livro que esta sendo devolvido: ";
            cin >> id;
            for (int indice = 0;indice < 100;indice++){
                if (l.id[indice] == id){
                    char nome = 50;
                    int telefone;
                    cout << "Digite o nome de quem esta devolvendo o livro: ";
                    cin >> nome;
                    cout << "Telefone: ";
                    cin >> telefone;
                    for (int indice = 0;indice < 100;indice++){
                        if (strcmp(l[indice].locatario[indice].nome,nome) != 0){
                            if(l[indice].locatario[indice].telefone == telefone){
                            pos = indice;
                            for (int indice = pos ;indice < (*num_locatarios-1);indice ++){
                                l[indice].locatario[indice].nome = l[indice+1].locatario[indice+1].nome;
                                l[indice].locatario[indice].telefone = l[indice+1].locatario[indice+1].telefone;
                                (*num_locatarios--);
                                cout <<"Livro devolvido!";
                                break
                                     }
                else{
                    cout << "id nao encontrado!";
                    continue;
                            }
                        }
                    }
                    
                }
            }
        }
    }
    
        if (opc == 2){
            int indice;
            char titulo = 100;
            cout << "Digite o titulo do livro que esta sendo devolvido: ";
            cin >> titulo;
            for (int indice = 0;indice<100;indice++){
                if (strcmp(l[indice].titulo, titulo) !=0){
                    char nome = 50;
                    int telefone;
                    cout << "Digite o nome de quem esta devolvendo o livro: ";
                    cin >> nome;
                    cout << "Telefone: ";
                    cin >> telefone;
                    for (int indice = 0;indice < 100;indice++){
                        if (strcmp(l[indice].locatario[indice].nome,nome) != 0){
                            if(l[indice].locatario[indice].telefone == telefone){
                            pos = indice;
                            for (int indice = pos ;indice < (*num_locatarios-1);indice ++){
                                l[indice].locatario[indice].nome = l[indice+1].locatario[indice+1].nome;
                                l[indice].locatario[indice].telefone = l[indice+1].locatario[indice+1].telefone;
                                (*num_locatarios--);
                                cout << "livro devolvido!";
                                break;
                else{
                    cout << "titulo nao encontrado!";
                    continue;
                        }
                    }
                }
            }
        }
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
    int opt, qtdade = 0;

    while(opt != 6){

    cout << "-------------------------------------" << endl;
    cout << "---------------MENU------------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "----- 1 - Cadastrar Livro -----------" << endl;
    cout << "----- 2 - Consultar livro -----------" << endl;
    cout << "----- 3 - Emprestimos de livros -----" << endl;
    cout << "----- 4 - Devolucao de livros -------" << endl;
    cout << "----- 5 - Remocao de livros ---------" << endl;
    cout << "----- 6 - Sair do programa ----------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Selecione a opcao desejada: ";
    cin >> opt;

    switch (opt)
    {
    case 1:
        int qtd;
        cout << "Insira quantos livros voce deseja cadastrar: ";
        cin >> qtd;
        for(int i = 0; i < qtd; i++){
            cadastroLivros(&vetorLivros[i]);
        }
        break;
    case 2:

        consultarLivros(vetorLivros, qtdade);
        break;
    case 3:

        emprestimoLivros(vetorLivros, &qtdade);
        break;
    case 4: 

        devolucaoLivros();
        break;

    case 5:

        removerLivro(vetorLivros, &qtdade);
        break;

    case 6:

        exit;
        break;

    }

    }
    return 0;

}

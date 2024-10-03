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

void cadastroLivros(struct livros vetorLivros[], int *pos){

    printf("Insira o ID: ");
    scanf("%d", &vetorLivros[*pos].id);
    printf("Insira o titulo: ");
    scanf(" %[^\n]", &vetorLivros[*pos].titulo);
    printf("Insira o autor: ");
    scanf(" %[^\n]", &vetorLivros[*pos].autor);
    printf("Insira o numero de paginas: ");
    scanf("%d", &vetorLivros[*pos].num_pag);
    printf("Insira o ano de publicacao: ");
    scanf("%d", &vetorLivros[*pos].ano_publi);
    

    (*pos)++;
}

void printLivros(struct livros livro){


    cout << "-------------- Livro -------------" << endl;
    cout << "ID_Livro: " << livro.id << endl;
    cout << "Título: " << livro.titulo << endl;
    cout << "Autor: " << livro.autor << endl;
    cout << "Numero de paginas: " << livro.num_pag << endl;
    cout << "Ano Publicacao: " << livro.ano_publi << endl;
    cout << "Quantidade disponível: " << livro.qtd_disp << endl;
    cout << "----------------------------------" << endl;

}

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
            for (indice = 0;indice < 100;indice++){
                if (l.id[indice] == id){
                    char nome = 50;
                    int telefone;
                    cout << "Digite o nome de quem esta devolvendo o livro: ";
                    cin >> nome;
                    cout << "Telefone: ";
                    cin >> telefone;
                    for (indice = 0;indice < 100;indice++){
                        if (strcmp(l[indice].locatario[indice].nome,nome) != 0){
                            if(l[indice].locatario[indice].telefone == telefone){
                            pos = indice;
                            for (indice = pos ;indice < (*num_locatarios-1);indice ++){
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
            for (indice = 0;indice<100;indice++){
                if (strcmp(l[indice].titulo, titulo) !=0){
                    char nome = 50;
                    int telefone;
                    cout << "Digite o nome de quem esta devolvendo o livro: ";
                    cin >> nome;
                    cout << "Telefone: ";
                    cin >> telefone;
                    for (indice = 0;indice < 100;indice++){
                        if (strcmp(l[indice].locatario[indice].nome,nome) != 0){
                            if(l[indice].locatario[indice].telefone == telefone){
                            pos = indice;
                            for (indice = pos ;indice < (*num_locatarios-1);indice ++){
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
    
        cadastroLivros(vetorLivros, &qtdade);
    
    case 2:

        consultarLivros(vetorLivros, qtdade);
        
    case 3:

        emprestimoLivros(vetorLivros, &qtdade);

    case 4: 

        devolucaoLivros();
    
    case 5:

        removerLivro(vetorLivros, &qtdade);

    case 6:

        exit;
    }

    }
    return 0;

}

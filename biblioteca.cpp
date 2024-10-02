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

void cadastroLivros(struct livros vetorLivros[], *pos){

    

    printf("Insira o titulo: ");
    scanf(" %[^\n]", &vetorLivros[*pos].titulo);
    printf("Insira o autor: ");
    scanf(" %[^\n]", &vetorLivros[*pos].autor);
    printf("Insira o numero de paginas: ");
    scanf("%d", &vetorLivros[*pos].num_pag);
    printf("Insira o ano de publicacao: ");
    scanf("%d", &vetorLivros[*pos].ano_publi);
    printf("Insira o ID: ");
    scanf("%d", &vetorLivros[*pos].id);

    (*pos)++;
}

void printLivros(){


}

void emprstimoLivros(livros l[100]){
    int opc = 0;
    
    while(opc != 1 || opc != 2){
        cout<<"Como deseja procurar o livro para emprestimo?"<<endl;
        cout<<"1- Por ID\n-2- Por nome";
        cin>>opc;
        if(opc != 1 || opc != 2){
            cout<<"Digite uma opção valida"<<endl;
        }
    }

    if(opc == 1){
        int id, indice;
        cout<<"Insira o ID do livro: ";
        cin>>id;
        
        for(indice = 0; indice < 100; indice++){
            if(l[indice].id == id){
                break;    
            }
        }
        
    }

    if(opc == 2){
        char titulo = 100;
        int indice;
        cout<<"Insira o nome do livro: ";
        cin>>titulo;

        for(indice = 0; indice < 100; indice++){
            if(strcmp(l[indice].titulo, titulo) != 0){
                break;    
            }
        }
    }

    if(l[indice].qtd_disp > 0){
        cout<<"Livro emprestado comsucesso";
    }


}

void devolucaoLivros(struct livros l){
    cout << "Digite o nome do livro que vai ser devolido: ";

}

void removerLivro(livros vec[], int *num_livros){
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

        consultarLivros();
        
    case 3:

        emprestimoLivros();

    case 4: 

        devolucaoLivros();
    
    case 5:

        removerLivro();

    case 6:

        exit;
    }

    }
    return 0;

}

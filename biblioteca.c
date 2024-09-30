#include <iostream>
using namespace std;

struct pessoa{
    char nome[];
    int telefone;
}

struct livros{
    char titulo[100];
    char autor[100];
    int num_pag;
    int ano_publi;
    int id;
    int qtd_disp[10];
    struct pessoa locatarios[10];
    
}


void cadastroLivros(struct livros *l){
    printf("Insira o titulo: ");
    scanf("%c", &l -> titulo);
    printf("Insira o autor: ");
    scanf("%c", &l -> autor);
    printf("Insira o numero de paginas: ");
    scanf("%i", &l -> num_pag);
    printf("Insira a a")
    printf("Insira o ID: ");
    scanf("%i", &l -> id;)
}

void printLivros(){


}

void emprstimoLivros(livros l[100], ){
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
            if(strcmp(l[indice].titulo,titulo) != 0){
                break;    
            }
        }
    }

    if(l[indice].qtd_disp > 0){
        cout<<"Livro emprestado comsucesso"
    }


}

void devolucaoLivros(struct livros l){
    cout << "Digite o nome do liv"o que vai ser devolido: 

c    ;
}

void remocaoLivros(){
    
}

int main()
{

    cout << "Selecione a opção desejada:" << endl;
    cout << "1 - Cadastrar Livro" << endl;
    cout << "2 - Consultar livro" << endl;
    cout << "3 - Emprestimos de livros" << endl;
    
    switch (opt)
    {
    case 1:
        /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }


}

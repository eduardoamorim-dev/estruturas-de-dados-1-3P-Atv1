#include <iostream>

using namespace std;

struct Livro {
    string tituloLivro;
    string autor;
    int numeroPagina = 0;

    void lerLivro() {
        cout << "Digite o titulo do livro: ";
        getline(cin, tituloLivro);
        cout << "Digite o autor do livro: ";
        getline(cin, autor);
        cout << "Digite o numero de paginas do livro: ";
        cin >> numeroPagina;
        cout << "----------------------------------------" << endl;
        cin.ignore();
    };

    void imprimirLivro() {
        cout << "Titulo: " << tituloLivro << endl << "Autor: " << autor << endl << "Numero de pagina: " << numeroPagina << endl;
    };
};

struct Biblioteca {
    Livro livros[10];
    int quantidadeLivros = 0;
    int indiceMaiorPagina = -1;

    void lerBiblioteca() {
        do {
            cout << "Quantos livros voce deseja cadastrar? (Maximo 10) : ";
            cin >> quantidadeLivros;
            cout << "--------------------------------------------------" << endl;
        } while (quantidadeLivros <= 0 || quantidadeLivros > 10);

        cin.ignore();

        for (int i = 0; i < quantidadeLivros; i++) {
            livros[i].lerLivro();
            if (indiceMaiorPagina == -1 || livros[i].numeroPagina > livros[indiceMaiorPagina].numeroPagina) {
                indiceMaiorPagina = i;
            }
        }
    };

    void imprimirBiblioteca() {
        cout << "|          Livros Cadastrados          |" << endl;
        cout << "----------------------------------------" << endl;
        for (int i = 0; i < quantidadeLivros; i++) {
            cout << "Livro " << i + 1 << endl;
            livros[i].imprimirLivro();
            cout << endl;
        }

        cout << "----------------------------------------" << endl;
        cout << "|  Livro com maior numero de paginas   |" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Titulo: " << livros[indiceMaiorPagina].tituloLivro << endl;
        cout << "Autor: " << livros[indiceMaiorPagina].autor << endl;
        cout << "Numero de paginas: " << livros[indiceMaiorPagina].numeroPagina << endl;
    };
};

int main() {
    Biblioteca l;
    l.lerBiblioteca();
    l.imprimirBiblioteca();
    return 0;
}


void limparTela() {
    system("cls");
}

string retornaPalavraAleatoria() {

    string palavras [3] = {"casa","carro","moto"};

    int indice_aleatorio = rand() % 3;

    return palavras[indice_aleatorio];
}

string RetornaPalavraMascara(string palavra, int tamanho_palavra) {

    string palavra_mascara;

    for(int i = 0; i < tamanho_palavra; i++){
        palavra_mascara += "_ ";
    }

    return palavra_mascara;
}

void joga_sozinho(){

    string palavra = retornaPalavraAleatoria();

    int tamanho_palavra = palavra.size();

    string palavra_mascara = RetornaPalavraMascara(palavra,tamanho_palavra);

    cout << palavra_mascara;

}

void menuInicial() {
    int opcao = 0;
    while (opcao < 1 || opcao > 3) {
        limparTela();
        cout << "Bem vindo ao jogo da forca!\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sobre\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma op��o: ";

        cin >> opcao;

        switch (opcao) {
        case 1:
            limparTela();
            cout << "Jogo iniciado! \n";
            joga_sozinho();
            break;
        case 2:
            limparTela();
            cout << "Sobre o jogo: \n";
            break;
        case 3:
            limparTela();
            cout << "Saindo... \n";
            break;
        }
    }
}


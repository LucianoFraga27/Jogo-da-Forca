
void limparTela() {
    system("cls");
}
void exibe_status (string palavra_mascara, int tamanho_palavra, int tentativasRestantes,string letras_arriscadas,string mensagem) {

    cout << mensagem << "\n";
    cout << "Palavra: " << palavra_mascara << " \nTamanho: " << tamanho_palavra;
    cout << "\nTentativas restantes: " << tentativasRestantes;
    cout << "\nLetras arriscadas: ";
    for(int i = 0; i < letras_arriscadas.size();i++){
    cout << letras_arriscadas[i] << ", ";
    }
}


string retornaPalavraAleatoria() {

    string palavras [3] = {"casa","carro","moto"};

    int indice_aleatorio = rand() % 3;

    return palavras[indice_aleatorio];
}

string RetornaPalavraMascara(string palavra, int tamanho_palavra) {

    string palavra_mascara;

    for(int i = 0; i < tamanho_palavra; i++){
        palavra_mascara += "_";
    }

    return palavra_mascara;
}

int joga_sozinho(){

    string palavra = retornaPalavraAleatoria();

    int tamanho_palavra = palavra.size();

    string palavra_mascara = RetornaPalavraMascara(palavra,tamanho_palavra);

    int tentativas = 0, maxTentativas = 10;
    char letra;
    string letras_arriscadas;
    string mensagem = "";



    while(palavra_mascara != palavra && maxTentativas - tentativas > 0) {

        limparTela();

        exibe_status(palavra_mascara,tamanho_palavra,maxTentativas-tentativas,letras_arriscadas,mensagem);

        cout << "\n\nDigite uma letra: ";
        cin >> letra;

        bool ja_tentou = false;

        for(int i = 0; i < tentativas; i++){
            if(letras_arriscadas[i] == letra) {
                mensagem = "\nLetra ja digitada\n";
                ja_tentou = true;
            }
        }

        if(ja_tentou == false) {

        letras_arriscadas += tolower(letra);

        for(int i = 0; i < tamanho_palavra; i++){

            if(palavra[i] == tolower(letra)){
                palavra_mascara[i] = tolower(letra);
                mensagem = "\nAcertou uma letra!\n";
            }
        }
        tentativas ++;
        }

    }
    int opcao_final;

    if(palavra_mascara == palavra) {
        limparTela();
        cout << "------------ \n";
        cout << "Voce venceu \n";
        cout << "------------ \n\n";

        cout <<"Deseja reiniciar o jogo? \n";
        cout <<"1 - Sim \n";
        cout <<"0 - Não \n";
        cin >> opcao_final;
        return opcao_final;
    } else {
        limparTela();
        cout << "------------ \n";
        cout << "Voce perdeu! \n";
        cout << "------------ \n\n";

        cout <<"Deseja reiniciar o jogo? \n";
        cout <<"1 - Sim \n";
        cout <<"0 - Não \n";
        cin >> opcao_final;

        cout << "\n\n\nSaindo....\n\n\n";

        return opcao_final;
    }
}

void menuInicial() {
    int opcao = 0;
    while (opcao < 1 || opcao > 3) {
        limparTela();
        cout << "Bem vindo ao jogo da forca!\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sobre\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opção: ";

        cin >> opcao;

        switch (opcao) {
        case 1:
            limparTela();
            cout << "Jogo iniciado! \n";
            if(joga_sozinho() == 1){
                menuInicial();
            }
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


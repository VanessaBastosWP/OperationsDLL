título // Simulador de Algumas Operações Estocásticas

badges // ??

Índice // ...

Descrição do Projeto // Biblioteca com 9 operações estocásticas com objetivo de simular a implementação em hardware

Status do Projeto // Concluído?

Funcionalidade e Demonstração da Aplicação // 

***como abrir o codigo***

Para rodar o código, é necessário escolher uma das opções de operação dentre as seguintes: 
1- Unipolar MAC = unipolar_mac(A, B, seed, bits);
2- Diferença em módulo Unipolar = unipolar_dif(A, B);
3- Máximo Unipolar = unipolar_max(A, B);
4- Média Unipolar = unipolar_mean(A, B, seed, bits);
5- Bipolar MAC = bipolar_mac(A, B, seed, bits);
6- Diferença em módulo Bipolar = bipolar_dif(A, B, bits);
7- Máximo Bipolar = bipolar_max(A, B, bits);
8- Média Bipolar = bipolar_mean(A, B, seed, bits);
9- Sign-Magnitude MAC = sign_mag_mac(A, B, seed, bits);

Deve-se chamar no main a função operation, passando os seguintes parâmetros: o número da operação(descrito ali em cima), os números A,B,seed convertidos em decimal e o número de bits dos valores (suporte até para 8 bits). Obs.: em algumas operações seed e/ou bits não são necessários.
Não colocar (2^bit)-1 no valor da seed do unipolar.
Não colocar 0 no valor da seed do bipolar ou Sign-Magnitude.
Colocar valores entre 0 e (2^bit)-2 para operações unipolares.
Colocar valores entre -(2^(bit-1)) e (2^(bit-1))-2 para operações bipolares e de Sign-Magnitude.
O resultado está exposto em relação ao número de bits, se deseja converter o valor para dentro dos limites [0,1] para unipolar e [-1,1] para bipolar e de sign-magnitude, use a operação scale, passando o mesmo número da operação feita, o resultado obtido dela e o número de bits usados.
Caso queira saber o resultado esperado da operação, chame a função valor_esperado, passando o número da operação feita (opções escritas ali em cima), o valor de A, de B e o número de bits usados.

Acesso ao projeto // ??

Tecnologias utilizadas // Visual Studio 2019 

Pessoas Desenvolvedoras do Projeto // Vanessa Bastos da Luz, George de Borba Nardes, Luiz Fernando Heidrich Duarte

Licença // 
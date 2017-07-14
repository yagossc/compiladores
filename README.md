Projeto 1 da disciplina Compiladores 1 do curso de Eng. Computação da UFG.
_notes to myself_

USAGE
=================
**> cd src/**

**> make**

**> ./sintatic ../input/font**
> Arquivo com exemplo de erro:

**> ./sintatic ../input/test.txt**
> Arquivo com combinações arbitrárias de tokens:

**> ./sintatic ../input/teste.txt**


NOTES TO THE TEACHER
==================
> - The file "sintatic_analyser.c" is our main;
> - It calls first the lexic_resolver.c and an internal routine to do the lexcic analysis;
> - Then it calls the sintatic_resolver.c to the sinstatic analysis;
> - In our main (sintatic_analyser.c), our IP pointer is the pointer "list" (pointed to a struct type List, available in data_structure.c);
> - The automata is available in ~/prep/automata/, and of course, through the ~/util/sintatic_table.h;
> - The files in ~/prep/ were part of the software's construction process.
> - Any doubts, please contact me, if you are or were my teacher, you probably have my e-mail address already.
> - Thank you for the course, have a nice vacation (:


FILES
==================
> - **README.md**;
> - **src/Makefile**;
> - **src/sintatic_analyser.c**;
> - **src/lexic_resolver.c**;
> - **src/sintatic_resolver.c**;
> - **src/data_sctructures.c**;
> - **src/hashmap.c**(_nao usado de fato na execução_);

> - **util/defines.h**;
> - **util/table.h**;
> - **util/lexic_resolver.h**;
> - **util/sintatic_resolver.h**;
> - **util/data_sctructures.h**;
> - **util/sintatic_table.h**;
> - **util/hashmap.h**(_nao usado de fato na execução_);

> - **input/fonte**(_fonte do trabalho_);
> - **input/test.txt**;
> - **input/teste.txt**;
> - **test/unity_tests/logic.c**(_arquivo de testes indiscriminados_);

> - **prep/automata/automatoP2** (_arquivo draw.io_);
> - **prep/automata/automatoP2-CORRETO.html**;
> - **prep/automata/automatoP2.html**;
> - **prep/tables/tabela_sintatica.ods**;
> - **prep/tables/tabela_sintatica.pdf**;
> - **prep/tables/tabela_transicao.pdf**;

TO DO
===================
> - **Reconhecer ponto e vírgula**(OK!);
> - **Reconhecer palavras de comando**(OK!);
> - **Reconhecer abre e fecha parêntesis**(OK!!);
> - **Salvar o lexema para poder passá-lo adiante**(OK!!);
> - **Count line feed for line information in ERROR message**(OK! COLUNA TB!);
> - **Operadores relacionais >=, <=, <> não implementados corretamente**(CORRIGIDO!);
> - **Como passar a tabela de símbolos para o parser**(POR ENQUANTO É SÓ PRINTAR AS ENTRADAS DA TABELA NA TELA) (OK!!);
> - **Alterar estrutura dos tokens para facilitar o uso dos MACROS e por consequência ter maior controle sobre as comparações no algorítmo interpretador da tabela sintática**;

> **Hashmap**(TABELA DE SÍMBOLOS);
> - _O uso do hashmap é importante para facilitar o tratamento dos tokens passados a frente. Ponteiros e referências são manipulados mas eficientemente do que as strings em si._

HOW TO
===================
> **Reconhecer palavras-chave:**
> - Inicializar o hashmap com as palavras-chave;
> - Quando o analisador léxico lê um lexema que pode ser um identificador ele confere no hashmap se é uma palavra reservada (check_table());
> - Caso seja uma palavra reservada ele retorna o token da tabela, caso contrário ele insere na tabela e retorna o token(id, atributo); 

> **Hashmap:**
> - De acordo com a tabela ASCII, os valores dos caracteres siginificativos (não resultam em erro/não são comentário) estão entre 34 e 122, sendo assim, a função hash poderá se basear nesse escopo de valores;
> - Cada campo na tabela de símbolos contém informações como o lexema, token-name/tipo e atributo;
> - Obs.: No momento de identificar um token, deve ser feita conferência na tabela, não só para as palavras reservadas, mas também para lexemas já introduzidos. A mesma lógica mencionada acima deverá ser implementada: se for encontrada entrada na tabela retorne o token encontrado, caso contrário insira na tabela e retorne o token identificado;

STUDY
===================

> - **Capítulo 1 e 2 - Tabela de símbolos**;
> - **Capítulo 4 - SLR(0) [ _tem o manual do trabalho no livro, só que mais bem explicado_ ] 
> - **Hashmap (LCTHW)**;

DÚVIDAS
===================

> - **O analisador léxico recebe a stream de caracteres do programa fonte e agrupa os caracteres em sequências significativas chamadas LEXEMAS.
Para cada lexema, o analisador léxico produz como saída um token na forma:**

_(token-name/type, lexem, attribute)_

> - **A saída será transferida para analisador sintático. No token, o primeiro componente _token-name_ é um símbolo abstrato usado durante a análise sintática, e o segundo componente _attribute_ aponta para uma entrada na tabela de símbolos deste token.(????)**

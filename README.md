Projeto 1 da disciplina Compiladores 1 do curso de Eng. Computação da UFG.
_notes to my self_

TO DO
===================
> - **Reconhecer ponto e vírgula**(OK!);
> - **Reconhecer palavras de comando**;
> - **Reconhecer abre e fecha parêntesis**(OK!!);
> - **Salvar o lexema para poder passá-lo adiante**;
> - **Count line feed for line information in ERROR message**;
> - **Operadores relacionais >=, <=, <> não implementados corretamente**;
> - **Como passar a tabela de símbolos para o parser**;

> **Hashmap**(TABELA DE SÍMBOLOS);
> - _O uso do hashmap é importante para facilitar o tratamento dos tokens passados a frente. Ponteiros e referências são manipulados mas eficientemente do que as strings em si.(?)_


HOW TO
===================
> **Reconhecer palavras-chave:**
> - Inicializar o hashmap com as palavras chave;
> - Quando o analisador léxico lê um lexema que pode ser um identificador ele confere no hashmap se é uma palavra reservada (hashmapCheckReserved()?);
> - Caso seja uma palavra reservada ele retorna o token da tabela, caso contrário ele insere na tabela e retorna o token(id, atributo); 

> **Hashmap:**
> - De acordo com a tabela ASCII, os valores dos caracteres siginificativos (não resultam em erro/não são comentário) estão entre 34 e 122, sendo assim, a função hash poderá se basear nesse escopo de valores;
> - Cada campo na tabela de símbolos contém informações como o lexema, token-name/tipo e o hash para confirmação de busca;
> - No momento de identificar um token, deve ser feita conferência na tabela, não só para as palavras reservadas, mas também para lexemas já introduzidos. A mesma lógica mencionada acima deverá ser implementada: se for encontrada entrada na tabela retorne o token encontrado, caso contrário insira na tabela e retorne o token identificado;

STUDY
===================

> - **Capítulo 1 e 2 - Tabela de símbolos**;
> - **Hashmap (LCTHW)**;

DÚVIDAS
===================

> **Como a tabela hash se enquadra?**I
> - **O analisador léxico recebe a stream de caracteres do programa fonte e agrupa os caracteres em sequências significativas chamadas LEXEMAS.
Para cada lexema, o analisador léxico produz como saída um token na forma:**
	_(token-name, atribute-value)_
**A saída será transferida para analisador sintático. No token, o primeiro componente _token-name_ é um símbolo abstrato que é usado durante a análise sintática, e o segundo componente _atribute-value_ aponta para uma entrada na tabela de símbolos deste token.**

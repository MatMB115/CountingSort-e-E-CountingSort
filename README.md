# Trabalho I de Algoritmos e Estruturas de Dados 
<p>Estudo dos casos de algoritmos de ordenação Counting e E-Counting para a disciplina Algoritmos e Estruturas de Dados II (COM112)  da Universidade Federal de Itajubá. Os algoritmos são desenvolvidos utilizando Tipos Abstratos de Dados, leitura e gravação de informaçõs por arquivo (geralmente txt predefinidos).</p>
<br>

- [x] Código base do algoritmo escrito;
- [x] Coletar número de comparações de chaves;
- [x] Coletar número de cópias de registro;
- [x] Mensurar tempo gasto para execução(tempo de processamento - getusage());
- [x] Gerar termos pseudo randômicos;
- [x] Ordenar vetor de dados aleatórios;
- [x] Ordenar vetor de dados ordenados;
- [x] Ordenar vetor de dados descrescente;
- [x] Rodar com todos valores de N propostos;
- [x] Rodas cada N com 10 sementes diferentes;
- [x] Calcular a média dos dados mensurados (tempo, cópias e registros) em cada execução por semente;
- [x] Gravar os resultados em um arquivo de saída.

## Introdução
<p>O método de Ordenação Interna em que se baseia esse artigo é o CountingSort, que estabelece sua ordenação por meio de contagens cuja complexidade é O(n). 
O CountingSort determina que, para cada elemento de entrada x, o número de elementos deve ser menor do que x. Ele usa essas informações para colocar o elemento x diretamente em sua posição na matriz de saída. Em busca de ampliar sua eficiência o E-CoutingSort possui melhorias em comparação ao algoritmo original, pelo fato de possuir uma complexidade de tempo reduzida em aproximadamente metade do original. O objetivo principal deste artigo é analisar e implementar o método de ordenação CountingSort e seu método eficiente E-CountingSort, a fim de analisar seus desempenhos de ordenação. Dessa forma, a constatar-se-á a base dos algoritmos evidenciando suas principais características de ordenação.</p>

## Referêncial Teórico
<p>Para o referencial teórico, utilizou-se das definições dadas pelo livro, afim de entender o funcionamento e amplitude de cada um dos algoritmos.</p>

## Metodologia
<p>A metodologia utilizada partiu do estudo e revisão do artigo e livro disponibilizados. Neles foram encontradas explicações sobre o código do algoritmo CountingSort, que foram fundamentais para a sua aplicação e montagem. Para a validação da lógica, fez-se um teste de mesa.</p>

## Resultados
<p>Notou-se, por meio do arquivo de saída, que o número médio de cópias do algoritmo do E-CountingSort foi notavelmente menor, assim como o tempo de execução (mesmo que próximo), em relação ao CountingSort, para pequenas quantidades de dados. Entretanto, para grandes quantidades, nota-se uma diferença grotesca no tempo de execução, o qual foi denotado o menor pelo algoritmo de E-CountingSort, comprovando sua melhor eficiência em relação ao CountingSort.  </p>

## Considerações Finais
<p>Evidencia-se, portanto, que o algoritmo do CountigSort possui vantagens, como a de ser estável, por não alterar a ordem dos dados, além de possuir um processamento simples. Entretanto, nota-se desvantagens acerca de sua limitação com o manuseio de grandes conjuntos de dados, devido sua constante K ser muito grande, e somente ordena lista de números naturais.</p>

## Relatório
<p>A priori, o relatório técnico será escrito utilizando um template LaTEX da SBC no Overleaf. Considerando possíveis problemas de formatação.</p>

***

*Grupo 8:<br>
Kaique de Souza Leal Silva - 2020003596 <br>
Matheus Luz de Faria - 2020032426<br>
Matheus Martins Batista - 2019005687<br>
Thais Danieli Branco de Souza - 2021001228<br>
Waldomiro Barbosa Romão - 2018005655<br>*


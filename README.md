<!-- map<string, vector<vector<int>>> mapa2;
	map<string, vector<vector<int>>> ::iterator itr;
Usado para o armazenamento e a recuperação de dados de uma coleção em que cada elemento é um par que contém um valor de dados e uma chave de classificação. O valor da chave é exclusivo e usado para classificar os dados automaticamente.

O valor de um elemento em um mapa pode ser alterado diretamente. O valor de chave é uma constante e não pode ser alterado. Em vez disso, os valores de chave associados aos elementos antigos devem ser excluídos e os novos valores de chave devem ser inseridos para novos elementos. -->

<!-- Documentação: Readme.md descrevendo o problema e todas as informações pertinentes a resolutividade do mesmo. Aplique exemplos para explicar o funcionamento de sua solução e estabeleça uma tabela para detalhar o resultado esperado e como deve ser compilada. -->


# Código de Huffman
<h2 align="center"> Marinêz Werneck Magalhães </h2>
<p> <p>

- Descrevendo o problema:
<p align="justify">
Elabore uma árvore binária que utilize o código de Huffman para comprimir arquivos. Para tanto, (1) contabilizar a recorrência de cada palavra(RP) no arquivo; (2) normalizar a contabilização entre 0 e 1 utilizando a fórmula: (RP/(max(RP)-min(RP)); (3) montar a árvore com as regras apresentadas por Huffman; (4) troque as palavras pela codificação binária (utilizar booleano para representar 0 e 1); (5) salve o arquivo em formato binário e observe qual foi o ganho de espaço obtido.
<p align="justify">
Elabore um Readme.mb explicando toda lógica utilizada na implementação, bem como, exemplos para representar funcionalidades da applicação. Feito isso, demonstre um desses exemplos em execução para detalhar para o leitos o que ele deve esperar como saída. Além disso, detalhe tudo que for importante no código e mostre como deve ser compilado.
	
- Funcionamento do código:
<p align="justify">
Para se trabalhar com grande volume de dados sendo processado, com a Hash, podemos economizar processamento de informações repetidas? Sim, para provar essa teoria utilizou-se o seguinte método:
<p align="justify">
 Implementou-se multiplicação de matrizes, com valores muito grandes (MAX x MAX), para teste usou-se (1000 x 1000) números inteiros, obtidos através do site: <a href="https://mxncalc.com/pt/generator">Generator</a>. Tokenizou-se a matriz (função tokenizar) para retirar as virgulas, fez-se o processamento a partir de coordenadas fornecidas pelo usuário, dupla de i e j correspondendo a posição inicial e final a ser lida, na l1(linha inicial), c1(coluna inicial), l2(linha final), c2(coluna final).
<p align="justify">
Fez-se a leitura a partir das coordenadas (função quadranteMatriz), produziu-se a transposta da matriz (função transposta). Feito isso, executou-se a multiplicação (função multiplicaMatriz) armazenamento em uma HASH o resultado da multiplicação como valor para a dupla de i's e j's (função transformaMatriz), os quais são utilizados como chaves da HASH. Após cada novo cálculo, o sistema consulta a HASH para identificar se a multiplicação já foi realizada (função buscarChave), se sim, retorna resposta (função imprimeTransfMatriz). Caso contrário, multiplica e armazena o conteúdo em cache.

### Menu Inicial
<p align="left">
  <img src="src/images/menu.png" height = "150"></img>
</p>

### Menu apresentando não encontro de colisões
<p align="left">
  <img src="src/images/telanaoencontrada.png" height = "300"></img>
</p>

### Menu apresentando encontro de colisões.
<p align="left">
  <img src="src/images/telaencontradahash.png " height = "300"></img>
</p>

### Menu com impressão da matriz com os valores após os processamentos.
<p align="left">
  <img src="src/images/matrizfinal.png"height = "360"></img>
</p>

### Menu informando que dados não podem ser processados.
<p align="left">
  <img src="src/images/erro.png"height = "270"></img>
</p>

## Resultados e Conclusão:

<p align="justify">
Os resultados encontrados mostram que, utilizando HASH, economiza-se muito no processamento de dados. Abaixo apresenta-se imagens com tempo cronometrado para processamento da matriz de linha zero, coluna zero, até linha 999, coluna 999, antes de utilizar HASH. Após o tempo de processamento foi imperceptível.
Com isso, consegue-se comprovar que a utilização de HASH melhora, e muito o tempo de processamento de grandes volumes de dados.




### Menu informando que os dados das coordenadas não  foram encontrados na HASH.
<p align="left">
  <img src="src/images/0a999naoencontrada.png"height = "290"></img>
</p>

### Imagem de tempo para processar a matriz de coordenadas (0,0) a (999,999).
<p align="left">
  <img src="src/images/tempo.png"height = "270"></img>
</p>

### Menu informando que os dados foram encontrados na HASH.
<p align="left">
  <img src="src/images/0a999Hash.png"height = "290"></img>
</p>


## Compilação:

### Compilação padrão

| Comando | Função |
|---------| --------|
| `make clean` | Apaga a última compilação realizada contida na pasta build |
| `make` | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build |
| `make run` | Executa o programa da pasta build após a realização da compilação |


### Compilação alternativa

| Comando | Função |
|---------| --------|
| `make r` | Limpa tudo, compila e executa |














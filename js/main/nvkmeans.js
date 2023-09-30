const fs = require('fs');
const kmeans = require('node-kmeans');

function lerArquivoComoString(arquivo, callback) {
    const leitor = new FileReader();

    leitor.onload = function (event) {
      const resultado = event.target.result;
      callback(null, resultado);
    };

    leitor.onerror = function (event) {
      callback(event.target.error, null);
    };

    leitor.readAsText(arquivo);
  }


function extrair(codigo, carac) {
    const dicionario = {};

    for (const cmd of carac) {
      let count = 0;

      for (const frase of codigo) {
        if (cmd === "if") {
          if (frase.includes("if(") || frase.includes("if (")) {
            count += 1;
          }
        } else if (cmd === "for") {
          if (frase.includes("for(") || frase.includes("for (")) {
            count += 1;
          }
        } else if (frase.includes(cmd)) {
          count += 1;
        }
      }

      dicionario[cmd] = count;
    }
    return dicionario;
  }

let arquivo = "../../database/2016/Parcial1/e1.c";

fs.readFile(nomeDoArquivo, 'utf8', (err, data) => {
    if (err) {
      console.error('Erro ao ler o arquivo:', err);
      return;
    }
  
    console.log('Conteúdo do arquivo:', data);
  });

lerArquivoComoString(arquivo, function (erro, conteudo) {
    if (erro) {
      console.error('Erro ao ler o arquivo:', erro);
    } else {
      console.log('Conteúdo do arquivo como string:', conteudo);

      // Agora, você pode chamar a função extrair com a lista de características e o conteúdo do arquivo.
      const lista_codigo = conteudo.split('\n'); // Divide o conteúdo em linhas.
      const carac = [
        "if", "for", "while", "case", "else", "fgets", "getch", "getchar", "getche",
        "putchar", "puts", "switch", "gets", "break", "return", "exit", "do", "strcpy",
        "strcmp", "strncpy", "strlen", "strupr", "strlwr", "strrev", "tolower", "toupper",
        "isalpha", "fopen", "fclose", "feof", "remove", "fflush", "sizeof", "typedef",
        "struct", "malloc", "free", "#include", "system", "default", "main", "functions",
        "argc", "argv"
      ];
      const resultado = extrair(lista_codigo, carac);
      console.log(resultado); // Exibirá o resultado no console

    }
  });


// Sample data
const data = [
    [3, 1, 1, 3, 2, 1],
    [2, 3],
    [3, 4],
    [10, 11],
    [11, 12],
    [12, 13],
    [13,14],
    [14,15],
    [15,16]
];
 
// Number of clusters
const k = 3;
 
// Perform k-means clustering
kmeans.clusterize(data, { k }, (err, result) => {
    if (err) {
        console.error(err);
        return;
    }
 
    // Cluster assignments for each data point
    const clusterAssignments = result.map(point => point.cluster);
 
    console.log('Cluster assignments:', clusterAssignments);
});

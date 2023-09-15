const kmeans = require('./kmeans.js');

const resultado = extrair(lista_codigo, carac);
const dados = Object.values(resultado).map(count => [count]);

const numClusters = 3;
const clusters = kmeans.runKMeans(dados, numClusters);

console.log(clusters);

    const frm = document.querySelector("#myForm");

    function lerArquivoComoString(arquivo, callback) {
      const leitor = new FileReader();

      leitor.onload = function(event) {
        const resultado = event.target.result;
        callback(null, resultado);
      };

      leitor.onerror = function(event) {
        callback(event.target.error, null);
      };

      leitor.readAsText(arquivo);
    }

    function extrair(lista_codigo, carac) {
      const dicionario = {}; // objeto em vez de vetor

      for (const cmd of carac) {
        let count = 0;

        for (const frase of lista_codigo) {
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

    // Exemplo de uso:
    const input = document.getElementById('fileInput');

    input.addEventListener('change', function(event) {
      const arquivo = event.target.files[0];

      if (arquivo) {
        lerArquivoComoString(arquivo, function(erro, conteudo) {
          if (erro) {
            console.error('Erro ao ler o arquivo:', erro);
          } else {
            console.log('Conteúdo do arquivo como string:', conteudo);

            // Agora, você pode chamar a função extrair com a lista de características e o conteúdo do arquivo.
            const lista_codigo = conteudo.split('\n'); // Divide o conteúdo em linhas.
            const carac = ["if", "for", "while"];
            const resultado = extrair(lista_codigo, carac);
            console.log(resultado);
          }
        });
      }
    });
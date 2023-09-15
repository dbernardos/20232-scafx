<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Leitura de Arquivo em Formulário</title>
</head>
<body>
  <form id="myForm">
    <input type="file" id="fileInput">
    <button type="button" id="btnExtrair">Extrair</button>
  </form>

  <script>
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
          }
        });
      }
    });
  </script>
</body>
</html>

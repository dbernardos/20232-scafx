const connection = require('../model/conexao');
const kmeans = require('node-kmeans');

exports.processamentoPagina = (req, res) => {
  res.render('telaProcessamento', { errado: false });
}

/**tentando implementar a rota com os vetores */
exports.processamentoPost = (req, res) => {
  console.log('ESTOU NO PROCESSAMENTO POST');
  try {
    // Obter os valores de nomesCaracteristicas e contagensCaracteristicas do corpo da solicitação
    const nomesCaracteristicas = req.body.nomesCaracteristicasInput;
    const contagensCaracteristicas = req.body.contagensCaracteristicasInput;
    const nomeArquivo = req.body.nomeArquivoInput;
    // Agora você tem acesso a esses valores e pode usá-los como desejar
    //console.log('Nomes de Características:', nomesCaracteristicas);
    //console.log('Contagens de Características:', contagensCaracteristicas);
    res.render('telaRelatorio', { chars: nomesCaracteristicas, contChars: contagensCaracteristicas, nomesArquivos: nomeArquivo });

    // Sample data      
    const data = [];
    let line = [];

    contagensCaracteristicas.split(",").forEach(function (valor, i) {
      line.push(valor);
      if ((i + 1) % nomesCaracteristicas.split(",").length == 0) {
        data.push(line);
        //console.log(i + "*" + line);
        line = [];
      }

    });

    if (Array.isArray(data)) {
      console.log('É uma lista (array)!');
    } else {
      console.log('Não é uma lista (array).');
    }

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

  } catch (error) {
    // Lida com exceções ao analisar JSON
    console.error('Erro ao analisar JSON:', error);
    res.status(400).send('Dados JSON inválidos');
  }
}
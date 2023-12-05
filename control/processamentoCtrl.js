const connection = require('../model/conexao');     
const kmeans = require('node-kmeans');

exports.processamentoPagina = (req, res) => {
    res.render('telaProcessamento', {errado: false});
}

/**tentando implementar a rota com os vetores */
exports.processamentoPost = (req, res) => {
    console.log('ESTOU NO PROCESSAMENTO POST');
    try{
      // Obter os valores de nomesCaracteristicas e contagensCaracteristicas do corpo da solicitação
      const nomesCaracteristicas = req.body.nomesCaracteristicasInput;
      const contagensCaracteristicas = req.body.contagensCaracteristicasInput;
      const nomeArquivo = req.body.nomeArquivoInput;
      // Agora você tem acesso a esses valores e pode usá-los como desejar
      console.log('Nomes de Características:', nomesCaracteristicas);
      console.log('Contagens de Características:', contagensCaracteristicas);
      res.render('telaRelatorio', { chars: nomesCaracteristicas, contChars: contagensCaracteristicas, nomesArquivos: nomeArquivo  });
      
      // Sample data      
      const data = [];
      const line = [];

      for (let i = 0; i < contagensCaracteristicas.length; i++) {  
        if(i % nomesCaracteristicas.length == 0 && i != 0){
          data.push(line);
          line = [];  
        }
        
        data.push(contagensCaracteristicas[i]);
      }

console.log(">>>>>>>>>>>" + data);

// data = [
//  [32,0,1,2,29,0,1,0,0,0,0,1,0,3,4,0,82,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,0,1,1],
//  [25,7,1,12,3,0,0,0,0,0,0,4,0,12,1,5,59,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1,0,0,0],
//  [18,0,4,14,14,0,1,0,0,0,0,5,0,14,1,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,0,1,1],
//  [6,0,8,16,4,0,1,0,0,0,0,5,0,16,1,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,1,0,1,1]
//];

// Number of clusters
const k = 2;
 
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



    } catch (error){
      // Lida com exceções ao analisar JSON
      console.error('Erro ao analisar JSON:', error);
      res.status(400).send('Dados JSON inválidos');
    }
  }
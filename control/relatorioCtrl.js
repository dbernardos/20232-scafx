const connection = require('../model/conexao');

exports.relatorioPagina = (req, res) => {
  console.log('ESTOU NO RELATORIO GET');
  res.render('telaRelatorio', { errado: false });
}

exports.relatorioPost = async (req, res) => {
  // Recupere os dados enviados da página de processamento
  const nomesCaracteristicas = req.body.nomesCaracteristicasInput;
  const contagensCaracteristicas = req.body.contagensCaracteristicasInput;
  console.log('ESTOU NO RELATORIO POST: ', contagensCaracteristicas);

  // Renderize a página de relatório com os dados
  res.render('telaRelatorio', {
    nomesCaracteristicas: nomesCaracteristicas,
    contagensCaracteristicas: contagensCaracteristicas,
  });
}

// relatorioCtrl.js
/*function listarCabecalhoChars() {
  // Aqui você pode gerar o conteúdo do cabeçalho da tabela dinamicamente
  const cabecalho = `
      <th>Contagem de chars</th>
      <th>Característica 2</th>
  `;
  return cabecalho;
}

module.exports = { listarCabecalhoChars };*/

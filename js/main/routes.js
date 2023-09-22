const express = require('express');
const router = express.Router();

// Rota para a página inicial
router.get('/', (req, res) => {
  res.render('index'); // Renderiza a página index.ejs
});

// Rota para processar o upload de arquivos (se necessário)
router.post('/upload', (req, res) => {
  // Coloque o código para processar o upload aqui, se necessário
  // Depois, redirecione ou envie uma resposta adequada
});

module.exports = router;

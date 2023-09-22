const express = require('express');
const app = express();
const path = require('path');
const routes = require('./js/main/routes'); // Importe o arquivo de rotas
const ejs = require('ejs'); // Importe o pacote EJS

app.use('/novo-kmeans.js', (req, res) => {
  res.type('application/javascript');
  res.sendFile(path.join(__dirname, 'public/js/main/novo-kmeans.js'));
});

// Configuração do diretório de arquivos estáticos (CSS, JavaScript, imagens, etc.)
app.use(express.static(path.join(__dirname, 'public')));

// Configuração para usar EJS como mecanismo de visualização
app.set('view engine', 'ejs'); // Defina o mecanismo de visualização como EJS
app.set('views', path.join(__dirname, 'js/main/views')); // Defina o diretório de visualização

// Use as rotas definidas no arquivo de rotas
app.use('/', routes);

// Porta em que o servidor irá escutar
const port = process.env.PORT || 3000;

app.listen(port, () => {
  console.log(`Servidor rodando na porta ${port}`);
});

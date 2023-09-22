const express = require('express');
const app = express();
const path = require('path');
const routes = require('./routes'); 
const ejs = require('ejs'); 

app.use('/novo-kmeans.js', (req, res) => {
  res.type('application/javascript');
  res.sendFile(path.join(__dirname, 'public/js/main/novo-kmeans.js'));
});


app.use(express.static(path.join(__dirname, 'public')));


app.set('view engine', 'ejs'); 

app.set('views', path.join(__dirname, 'js/main/views')); 


app.use('/', routes);


const port = process.env.PORT || 3000;

app.listen(port, () => {
  console.log(`Servidor rodando na porta ${port}`);
});

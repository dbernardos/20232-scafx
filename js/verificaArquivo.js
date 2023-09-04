//Maneiras de ler arquivos no javascript
function lerArquivo(file) {
    // Verifica se esse arquivo é uma imagem
    if (file.type && !file.type.starsWith('image/')) {
      console.log('O Arquivo não é uma imagem', file.type, file);
      return;
    }
  
    const leitura = new FileReader();
    leitura.addEventListener('load', (event) => {
      img.src = event.target.result;
    });
    leitura.readAsDataURL(file);
  }

  
//o usuário conseguirá selecionar um ou mais arquivos

<input type="file" id="file-selector" multiple></input>
  
  const selecionarArquivo = document.getElementById('file-selector');
  selecionarArquivo.addEventListener('change', (event) => {
    const listarArquivos = event.target.files;
    console.log(listarArquivos);
    
  })
  //usando a UI de seleção de arquivo sintegrada ao SO

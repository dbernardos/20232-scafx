//o usuário conseguirá selecionar um ou mais arquivos

<input type="file" id="file-selector" multiple></input>
  
  const selecionarArquivo = document.getElementById('file-selector');
  selecionarArquivo.addEventListener('change', (event) => {
    const lista_codigo = event.target.files;
    console.log(lista_codigo);
    
  })
  
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

    const lista_codigo = [
        "if (condition){",
        "}",
        "for (let i = 0; i< 5; i++){",
        "}",

        "while (true){",
        "}",
    ];

    const carac = ["if", "for", "while"];
    const resultado = extrair(lista_codigo, carac);
    console.log(resultado);

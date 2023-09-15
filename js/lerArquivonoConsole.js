const texto = document.querySelector("#texto")

const endpoint ="arquivo.txt" 
fetch(endpoint)
  .then(response => response.text())
  .then(res => {
    
    console.log(res);
  })
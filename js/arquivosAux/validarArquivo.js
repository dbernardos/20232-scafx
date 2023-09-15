//função para validar tipo de arquivo
function validarTipoArquivo(seletorCampo){
var arquivo = document.getElementById('arquvio.c');

console.log(arquivo.files[0].type)

if(arquivo.files[0].type !="aplication/c"){
    alert("Erro: tipo de arquivo inválido!!")
arquivo.value=''
    }
}

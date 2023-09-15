function handleFile(files){
    const reader = new FileReader();
    reader.onload = (event) => {
        let data = event.target.result;
        document.querySelector("#texto").value = data; 
    };
    reader.readAsText(files[0]);
}
if (['image/jpg', 'image/png'].includes(files[0].type)) {
    const reader = new FileReader();
    reader.onload = (event) => {
        let data = event.target.result;
        document.querySelector("#texto").value = btoa(data);
        document.querySelector("#imagem").src = 'data:'+files[0].type+';base64,'+btoa(data);
    };
    reader.readAsBinaryString(files[0]);
}
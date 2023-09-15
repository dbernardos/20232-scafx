const stats = require('simple-statistics');
 const KMeans = require('shaman').KMeans;
 const dataForge = require('data-forge');
 const config = require('./config');
 const plotly = require('plotly')(config.USERNAME, config.API_KEY);
 const opn = require('opn'); 
 require('data-forge');
 require('shaman');

 const df = dataForge.readFileSync('../datasets/iris.csv').parseCSV();

 /**ESSE PROJETO SERVIRÁ COMO UMA BASE SOBRE CLUSTERING E MAPEAMENTO EM GRÁFICO */
 
 /* convertendo os valores para float*/
 const subset = df.subset(["sepallength", "sepalwidth","petallength", "petalwidth"]).select(function (row) {
   return {
      sepallength: parseFloat(row.sepallength),
      sepalwidth: parseFloat(row.sepalwidth),
      petallength: parseFloat(row.petallength),
      petalwidth: parseFloat(row.petalwidth)
   };
});

 /** a função summary serve para saber o que exitem nos dados  */

 function summary(column) {
    return {
       min: stats.min(column),
       max: stats.max(column),
       sum: stats.sum(column),
       median: stats.median(column),
       mode: stats.mode(column),
       mean: stats.mean(column),
       variance: stats.variance(column),
       stdDeviation: stats.standardDeviation(column),
       quantile: {
          q1: stats.quantile(column, 0.25),
          q3: stats.quantile(column, 0.75)
       }
    }
 }
 console.log('sepallength');
 console.log(summary(subset.getSeries('sepallength').toArray()));
 console.log('sepalwidth');
 console.log(summary(subset.getSeries('sepalwidth').toArray()));
 console.log('petallength');
 console.log(summary(subset.getSeries('petallength').toArray()));
 console.log('petalwidth');
 console.log(summary(subset.getSeries('petalwidth').toArray()));

 // construindo o modelo de clustering
const kmeans = new KMeans(3);
// executando o clustering usando o dataset
kmeans.cluster(subset.toRows(), function (err, clusters, centroids) {
   // mostrando os erros
   console.log(err);
   //mostrando os clusters
   console.log(clusters);
   // mostrando os centroids
   console.log(centroids);
})

// dicionário para aux na leitura dos indices
const indexes = {
    sepallength:0,
    sepalwidth:1,
    petallength:2,
    petalwidth:3
}
// construindo gráficos com os centroids
const centroidTrace = {
    x: centroids.map(function (c){
      return c[indexes[sepallength]]; // 0 — sepallength
    }),
    y: centroids.map(function (c){
      return c[indexes[petallength]]; // 2 — petallength
    }),
    mode: 'markers',
    type: 'scatter',
    name: 'Centroids',
    marker: {
      color: '#000000',
      symbol: 'cross',
      size: 10
    }
 };
// adicionando centroids data no vetor plotData
const plotData = [centroidTrace];
// construindo gráficos com os clusters
clusters.forEach(function (cluster, index) {
   const trace = {
      x: cluster.map(function (c)  {
         return mapacluster[indexes["sepallength"]];
      }),
      y: cluster.map(function (c) {
         return c[indexes["petallength"]];
      }),
      jitter: 0.3, 
      mode: 'markers',
      type: 'scatter',
      name: 'Cluster'  + index
   }
   // atribuindo valores no gráfico on plotData
   plotData.push(trace);
});

//layout de gráfico
const layout = {
   title: 'Iris Clustering',
   xaxis: {
    title: 'sepallength'
   },
   yaxis: {
    title: 'petallength'
   }
};
//opções do gráfico
var graphOptions = {
   layout: layout, //atribuindo layout
   filename: 'Iris-clustering', //atrinuinDO nome do arquivo
   fileopt: 'overwrite' // se existe escreve de novo
};

plotly.plot(plotData, graphOptions, function (err, msg) {
    if (!err) {
      // if build without erros show the message and open browser with graph
    console.log(`Success! The plot ${msg.filename} can be found at ${ msg.url}`);
    opn(msg.url);
    process.exit();
    }
   });
 

 /**https://medium.com/@joaogabriellima/clusteriza%C3%A7%C3%A3o-de-dados-com-javascript-parte-3-algoritmos-de-clusteriza%C3%A7%C3%A3o-na-pr%C3%A1tica-799b46f423d4 */
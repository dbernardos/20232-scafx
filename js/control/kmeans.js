function runKMeans(data, k, maxIterations = 100) {
    // Inicialização dos centroides de forma aleatória
    let centroids = initializeRandomCentroids(data, k);
  
    for (let iteration = 0; iteration < maxIterations; iteration++) {
      // Atribui cada ponto ao cluster mais próximo
      const clusters = assignToClusters(data, centroids);
  
      // Atualiza os centroides para a média dos pontos de cada cluster
      centroids = updateCentroids(clusters);
  
      // Verifica se os centroides não mudaram significativamente (convergência)
      if (centroidsConverged(centroids, clusters)) {
        break;
      }
    }
  
    return centroids;
  }
  
  // Função para inicializar os centroides aleatoriamente
  function initializeRandomCentroids(data, k) {
    const centroids = [];
  
    for (let i = 0; i < k; i++) {
      const randomIndex = Math.floor(Math.random() * data.length);
      centroids.push(data[randomIndex]);
    }
  
    return centroids;
  }
  
  // Função para atribuir cada ponto ao cluster mais próximo
  function assignToClusters(data, centroids) {
    const clusters = new Array(centroids.length).fill([]); // Cria clusters vazios
  
    for (const point of data) {
      const distances = centroids.map(centroid => calculateDistance(point, centroid));
      const nearestCentroidIndex = distances.indexOf(Math.min(...distances));
      clusters[nearestCentroidIndex].push(point);
    }
  
    return clusters;
  }
  
  // Função para atualizar os centroides para a média dos pontos de cada cluster
  function updateCentroids(clusters) {
    const centroids = [];
  
    for (const cluster of clusters) {
      if (cluster.length === 0) {
        // Evita a divisão por zero, caso o cluster esteja vazio
        centroids.push(cluster[0]);
      } else {
        const centroid = cluster.reduce((acc, curr) => {
          return acc.map((val, i) => val + curr[i]);
        }, new Array(cluster[0].length).fill(0));
  
        centroids.push(centroid.map(val => val / cluster.length));
      }
    }
  
    return centroids;
  }
  
  // Função para verificar se os centroides não mudaram significativamente (convergência)
  function centroidsConverged(newCentroids, oldCentroids) {
    const tolerance = 1e-4;
  
    for (let i = 0; i < newCentroids.length; i++) {
      for (let j = 0; j < newCentroids[i].length; j++) {
        if (Math.abs(newCentroids[i][j] - oldCentroids[i][j]) > tolerance) {
          return false;
        }
      }
    }
  
    return true;
  }
  
  // Função para calcular a distância euclidiana entre dois pontos
  function calculateDistance(point1, point2) {
    return Math.sqrt(
      point1.reduce((acc, val, i) => acc + (val - point2[i]) ** 2, 0)
    );
  }
  
  // Exemplo de uso:
  const data = [
    [2, 3],
    [3, 4],
    [10, 11],
    [12, 13],
  ];
  
  const k = 2;
  const centroids = runKMeans(data, k);
  console.log(centroids);
  
const kmeans = require('node-kmeans');

// Sample data
const data = [
    [1, 2],
    [2, 3],
    [3, 4],
    [10, 11],
    [11, 12],
    [12, 13]
];

// Number of clusters
const k = 3; // Alterado para 3 clusters

// Perform k-means clustering
kmeans.clusterize(data, { k }, (err, result) => {
    if (err) {
        console.error(err);
        return;
    }

    // Cluster assignments for each data point
    const clusterAssignments = result.map(point => point.cluster);

    console.log('Cluster assignments:', clusterAssignments);
});

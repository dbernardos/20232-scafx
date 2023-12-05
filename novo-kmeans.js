const kmeans = require('node-kmeans');
 
// Sample data
const data = [
    [32,0,1,2,29,0,1,0,0,0,0,1,0,3,4,0,82,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,0,1,1],
    [25,7,1,12,3,0,0,0,0,0,0,4,0,12,1,5,59,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1,0,0,0],
    [18,0,4,14,14,0,1,0,0,0,0,5,0,14,1,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,0,1,1],
    [6,0,8,16,4,0,1,0,0,0,0,5,0,16,1,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,1,0,1,1]
];
 
// Number of clusters
const k = 2;
 
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

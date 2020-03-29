# k_means.py

import math
import unittest
import random
import matplotlib.pyplot as plt;

# 1. Specify the desired number of clusters
# 2. Randomly assign each data point to a cluster
# 3. Compute the centroid of the clusters
# 4. Re-assign each point to the closest cluster
# 5. Re-compute the cluster's centroid
# 6. Repeat until no improvement is feasible
def k_means(k, points):
    clusters = [[] for i in range(k)];
    centroids = [];
    for point in points:
        clusters[int(random.random() * k)].append(point);
    for cluster in clusters:
        centroids.append(compute_centroid(cluster));
    print("\nclusters: %s" % clusters);
    print("\ncentroids: %s" % centroids);
    for i in range(10):
        clusters = reassign_points(clusters, centroids);
        print("updated clusters: %s" % clusters);    
        for i in range(len(clusters)):
            centroids[i] = (compute_centroid(clusters[i]));
        print("updated centroids: %s" % centroids);
    plt.plot(clusters);
    plt.show();

def reassign_points(clusters, centroids):
    new_clusters = [[] for i in range(len(clusters))];
    for i in range(len(clusters)):
        for j in range(len(clusters[i])):
            min_dist = float("inf");
            for k in range(len(centroids)):
                new_min = compute_distance(clusters[i][j], centroids[k]);
                if new_min < min_dist:
                    min_dist = new_min;
                    point = clusters[i][j];
                    new_k = k;
            new_clusters[new_k].append(point);
    return (new_clusters);
        

        
def compute_distance(p1, p2):
    return (math.sqrt((p1[0] - p2[0])**2 + (p1[1]-p2[1])**2));
    
def compute_centroid(cluster):
    if not cluster:
        return ((0,0));
    x = 0;
    y = 0;
    for point in cluster:
        x += point[0];
        y += point[1];
    return ((x / len(cluster), y / len(cluster)));

def generate_points(num):
    rnd_pnts = set();
    rnd = int(random.random() * 100) + 1;
    while num:
        rnd_pnts.add((int(random.random()*rnd), \
          int(random.random()*rnd)))
        num -= 1;
    arr = [x for x in rnd_pnts];
    return (arr);

class kMeansTesting(unittest.TestCase):
    def test_randomisation(self):
       points = [(4,3), (4,2), (1,1), (4,3), (4,2)];
#       k_means(2, points);

    def test_centroid_computation(self):
        cluster = generate_points(10);
        print("generated points: %s" % cluster);
        result = compute_centroid(cluster);

    def test_distance_computation(self):
        p1 = (1,3);
        p2 = (3,1);
        result = compute_distance(p1, p2);
        self.assertEqual(math.sqrt(8), result);

    def test_k_means(self):
        points = generate_points(8);
        k = int(random.random() * 10);
        print("k = %s" % k);
        k_means(k, points);
        
        
if __name__ == "__main__":
    unittest.main();

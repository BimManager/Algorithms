# dbscan.py

import unittest
import math
import random
import queue
import matplotlib.pyplot as plt;

from k_means import generate_points, compute_distance

def DBSCAN(points, e, minPts):
    clusters = [];
    while points:
        clusters.append(form_cluster(points, e));
    print(clusters);
    plot_clusters(clusters);

def form_cluster(points, e):
    cluster = [];
    checked = [];
    queued = queue.Queue(len(points));
    
    if not points:
        return (cluster);
    queued.put(points[0]);
    while not queued.empty():
        point = queued.get();
        for i in range(len(points)):
            if points[i] not in checked \
               and compute_distance(point, points[i]) < e:
                cluster.append(points[i]);
                queued.put(points[i]);
                checked.append(points[i]);
    for p in cluster:
        points.remove(p);
    return (cluster);

def plot_clusters(clusters):
    colors = ["black", "red", "orange", "gold", \
              "yellow", "green", "cyan", "steelblue", \
              "blue", "plum", "crimson", "pink", "tomato"];

    k = 0;
    for i in range(len(clusters)):
        xs = [];
        ys = [];
        for j in range(len(clusters[i])):
            xs.append((clusters[i][j])[0]);
            ys.append((clusters[i][j])[1]);
        plt.plot(xs, ys, "ro", color=colors[k % len(colors)]);
        k += 1;
    plt.show();
            

class TestDBSCAN(unittest.TestCase):
    def test_DBSCAN(self):
        points = generate_points(20);
        print(points);
        DBSCAN(points, 10, 1);

    def test_points_within_e(self):
        points = generate_points(10);
#        print(points);
        point = points[int(random.random() * len(points))];
 #       print(point);
#        dr = form_cluster(point, points, 10);
   #     print(dr);
  #      print("points to process %s" % points);


if __name__ == "__main__":
    unittest.main();

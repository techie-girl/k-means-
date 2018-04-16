K-means Algorithm

Input: k (Total number of clusters selected)
D (A set of list ratios)
Output: a set of k clusters
Method: Uniformly at random select k objects from D as the initial cluster centers
THEN
Repeat:
1. Assign each object to the cluster to which the object is most similar to, based on the mean value
of the objects in the cluster
2. Update the cluster means.
3. Repeat until no further change (or less then 10%)

K-Means++ utilizes a natural method to seed the underlying bunches of the calculation by attempting
to pick seeds that are as far separated as could be allowed. This is finished by giving a higher likelihood
for focuses that are further far from the ones as of now picked. The way it works is that we pick an
arbitrary introductory point, and afterward give a higher likelihood of picking a guide corresponding
toward its separation from the seeds as of now picked, until the point that k seeds are picked.


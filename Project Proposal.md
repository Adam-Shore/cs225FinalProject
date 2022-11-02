##Project Proposal

## Leading Question 

Social networks are a very interesting application of a graph data structure. Individuals constantly utilize social media platforms to interact with one another. In order to explore social circles within Twitter, we will develop a graph to display social connections, represented as edges, between Twitter users, which will be represented as nodes. We plan to utilize a dataset representing social networks of Twitter users. The graph that we plan to develop will be a directed graph, since we are interested in exploring the direct connection between a user. Utilizing Dijkstra’s algorithm, we will also be able to implement a BFS algorithm. Through this approach we will be able to calculate the shortest path between two Twitter users. So, with this approach we will be able to explore our question of: utilizing our graph, given a Twitter user, who has a first degree and higher connection to this user?


## Dataset Acquisition
Our team has chosen to use a dataset of social circles for twitter. 
http://snap.stanford.edu/data/ego-Twitter.html 
 
## Data Format

The dataset is downloaded as a folder containing many files. These files are one of several types: nodeId.edges : This contains the directed edges in the ego network for the node 'nodeI’. The 'ego' node does not appear, but it is assumed that they follow every node id that appears in this file. nodeId.circles : The set of circles for the ego node. Each line contains one circle, consisting of a series of node ids. The first entry in each line is the name of the circle. nodeId.feat : The features for each of the nodes that appears in the edge file. nodeId.egofeat : The features for the ego user. nodeId.featnames : The names of each of the feature dimensions. Features are '1' if the user has this property in their profile, and '0' otherwise. 

## Data Correction

Our project will incorporate various checks to ensure the input data is correct while reading it into our program. One of these checks will include validation of every twitter social circle to make sure that every node belongs to the proper social circle. When encountering an issue with a node not belonging to a social circle it’s supposed to, we’ll correct the issue and sort the node to its proper social circle. If we find there are missing nodes when validating the social circles, we’ll fill in for those nodes by creating nodes as place holders to fill in the holes in the dataset. 

## Data Storage
We are going to be using a directed graph in order to represent the connections between people. There will be one directed edge between people if only one is following the other, or else if they both follow each other there will be two directed edges connecting them. Our estimated total storage cost is O(n*log(n)). 

## Algorithm 

We plan to utilize Dijkstra’s algorithm utilizing a BFS in order to find the shortest path between two Twitter users in our directed graph. We also plan to utilize an A* search algorithm since Dijkstra’s algorithm is a special case of A* search.

In determining the shortest path between nodes to determine the first, second, etc degrees of connectivity between two Twitter users, we will take two inputs. The two inputs will each be a Twitter user. Given the fact that our leading question aims to find the first degree connections among Twitter users, we expect the output of our algorithm to provide the degrees of connections of a given Twitter user. 

We have determined that the runtime of BFS search is O(n) given the loops that will be utilized. We then determined that the Dijkstra algorithm has a O(V lgV) runtime, where v represents the number of vertices in our directed graph. 


## Timeline
Plan project and create project proposal (week 1)
Data acquisition (week 2)
Data processing (week 2)
Completion of each individual algorithm (week 3)
Production of final deliverables (week 4)

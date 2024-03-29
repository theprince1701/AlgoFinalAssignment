
**SETUP**

Download the package as a .zip and unzip it somewhere on your pc. To run the program. open the .sln in visual studio or any code editor of your choice. To run the program press CTRL + SHIFT + F5 or build the program (CTRL + B).



**HOW TO READ**
![c60dd6de40d6d77bf180458b1f988a9b](https://github.com/theprince1701/AlgoFinalAssignment/assets/96841021/b9b11005-b909-4e38-9474-c99783c63eb5)


The first line is the calculated time complexity of the program/algorithm.
The second line is the closest node that has a gas station to the target node.


**HOW TO USE**

![33b3e89efe9a8e97492e41d7c28956bf](https://github.com/theprince1701/AlgoFinalAssignment/assets/96841021/adac4238-2e39-45ee-b860-be31be2a17b5)

On line 192, you can change the source (staring node), to start the node is at node B.


![99b43bac867590bd3e2b77d8008198c5](https://github.com/theprince1701/AlgoFinalAssignment/assets/96841021/97f7e3f7-9ea1-4c5c-853d-60cb558dc324)


**DOCUMENTATION**

![cdc57f17a2061b9c53cfab70f7bd0626](https://github.com/theprince1701/AlgoFinalAssignment/assets/96841021/a188dae6-b3a9-4fa1-b4c5-c86fdceb53ce)

Nodes are a data container (struct) that contains the following properties:
- Label
- Neighbors
- IsChargingStation


All of these values make up what a node is in the above graph

![5917e9345e6df809dac8297e3beea0a4](https://github.com/theprince1701/AlgoFinalAssignment/assets/96841021/98852b3a-d74a-45c4-b9b8-89cfdaaa102f)

The graph class handles everything the program does, from reading to manipulating data. The graph class contains several helper functions such as:
- GetNodeFromLabel (find a node from a label, a label is a letter from A-W)
- GetShortestRoute (find the shortest route from a source node to a gas station)
- CalculateTimeComplexitiy (calculate the programs time complexity)

The graph also contains setter functions:
- SetChargingStations (ability to manually set which nodes have a gas station)
- AddEdge (manually add edges/neighbors to a node)
- AddNode (manually add a node to the graph)


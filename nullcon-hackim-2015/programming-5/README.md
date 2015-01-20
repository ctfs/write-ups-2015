# nullcon HackIM 2015: Programming Question 5

**Category:** Programming
**Points:** 500
**Author:**
**Description:**

>Capture Aldrich Killian:
>
>#Problem Statement
>
>Aldrich's city is organized as a graph of smaller towns, let the number of towns by n. There are m one way roads between towns. Each road connec two towns in one way. Aldrich has given a number to each town. Actually the number allocated to each town is the preorder number during the DFS search of the graph. The town with number 1 is the root node of the graph.
>
>More formally, G = (V, E), where |V| = n, |E| = m. Each vertex, v in V is allocated a unique number from 1 to n using preoder number of DFS traversal of the graph.
>
>Aldrich has places an enormous army in his town. Iron Man has created a strategy to defeat the army by cutting down their supply of food and other resources. As per Iron Man's research a town, say v, gets its supply of resources from a specific town, say w, such that town w satisfy following property:
>
>All the paths from root node 1 to v passes through town w. If there are more than one town with this property then w is chosen because it has the highest number among all such towns.
>
>Please note town w can supply resources to more than one town.
>
>Iron Man wants to know, given a town w, how many towns get their supply of resources from w.
>
>##Input Format:
>First line containts n (number of towns, m (number of edges) seperated by space.
>Each of the next m lines specify edges among towns. Each edge is represented by a pair "u v" i.e an edge u --> v.
>
>##Output Format:
>For each town, say w, from 1 to n in the increasing order of town number, print how many towns get their supply from w. No Space and or new line is allowed.
>
>##Example
>###Input
>5 5
>1 5
>5 3
>3 4
>2 3
>1 2
>
>###Output
>30100
>
>Town 1 supply resource to 3 towns, town 2 supply to none, town 3 supply to 1 town and so on.
>
>##Flag
>Flag is the sha1 of the expected output. We computed sha1 using the following command. cat output.txt | openssl dgst -sha1
>
>	[Input File](input5.txt)

## Write-up

(TODO)

## Other write-ups and resources

* none yet

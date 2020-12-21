# kn-tree-io
kN-tree  de/-serializiation in C++ 


## Usage

Serializing a set of 3-dimensional vectors to an octree (k3-tree)

```C++

#include <vector>
#include <ostream>

#include "octree_io/io/writer.h"
#include "octree_io/structure/kn_tree.h"


int main(){

	//Creates an Octree (3-dimensional)
	octree_io::kn_tree tree{3};
	

	//create a set of 3-dimensional vectors
	std::vector<std::vector<size_t>> vectors{};
	
	//create a 3 dim vector
	std::vector<size_t> v{};
	v.push_back(1); //first dim value
	v.push_back(2); //second dim value
	v.push_back(3); //third dim value
	vectors.push_back(v);
	
	//add all your 3dim vectors to the octree
	for(std::vector<size_t> &point : vectors){
		tree.add(point);
	}

	//use whatever output stream you want
	std::ostream ostream = ...

	//write them 
	octree_io::write(ostream, tree);
}

```

Deserializing of an octree (k3-tree). 

```C++

#include <vector>
#include <istream>

#include "octree_io/io/reader.h"
#include "octree_io/structure/kn_tree.h"


int main(){

	// we want an octree -> 3 dimensional
	size_t dim = 3;
        //Creates an Octree (3-dimensional)
        octree_io::kn_tree tree{dim};

	//use whatever input stream you want
        std::istream istream = ...
		
	//read from istream and write the octree to tree 
        octree_io::read(istream, tree);
	
	//get all 3 dim vectors from tree
	std::vector<std::vector<size_t>> vectors{};	
	for(std::vector<size_t> &point : tree.get_points()){
		vectors.push_back(point);
	}
}


```



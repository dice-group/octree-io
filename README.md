# kn-tree-io
kN-tree  de/-serializiation in C++ 


## Usage

Serializing a set of 3-dimensional vectors to an octree (k3-tree)

```C++

#include <vector>
#include <istream>

#include "kn_tree_io/io/writer.h"
#include "kn_tree_io/structure/kn_tree.h"


int main(){

	//Creates an Octree (3-dimensional)
	kn_tree_io::kn_tree tree{3};
	
	std::vector<std::vector<size_t>> vectors{};
	std::vector<size_t> v{};
	v.push_back(1); //first dim value
	v.push_back(2); //second dim value
	v.push_back(3); //third dim value
	vectors.push_back(v);
	
	for(std::vector<size_t> &point : vectors){
		tree.add(point);
	}

	std::istream istream = ...
	kn_tree_io::write(istream, tree);
}

```

Deserializing of an octree (k3-tree). 

```C++

#include <vector>
#include <istream>

#include "kn_tree_io/io/reader.h"
#include "kn_tree_io/structure/kn_tree.h"


int main(){

	size_t dim = 3;
        //Creates an Octree (3-dimensional)
        kn_tree_io::kn_tree tree{dim};

        std::istream istream = ...
        kn_tree_io::read(istream, tree, dim);
	
	std::vector<std::vector<size_t>> vectors{};	
	for(std::vector<size_t> &point : tree.get_points()){
		vectors.push_back(point);
	}
}


```



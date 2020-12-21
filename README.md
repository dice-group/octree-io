# kn-tree-io
kN-tree  de/-serializiation in C++ 


## Usage

Serializing a set of n-dimensional vectors

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
	
	for(std::Vector<size_t> point : vectors){
		tree.add(point);
	}

	std::istream istream = ...
	kn_tree_io::write(istream, tree);
}


```

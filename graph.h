#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;

//edits to this are likely not needed
template <class T>
struct Vertex {
  T label; // unique int for a vertex
  vector<T> adj_list;
  int indegree; // Part 2: number of nodes pointing in
  int top_num; // Part 2: topological sorting number
  Vertex(T l) : label(l) {top_num = 0;  indegree = 0;} //Part 1
  // You may include default constructor optionally.
};

// optional, but probably helpful
template <class T>
ostream& operator<<(ostream &o, Vertex<T> v) {
    for (auto it = v.adj_list.begin(); it != v.adj_list.end(); ++it) {
        o << v.adj_list.at(it) << " ";
    }
    o << endl;
    return o;
}



// std::priority_queue may take takes three template parameters: <Type, ContainerType, Functor>
// syntax for custom compare functor
// Refer the instructions PDF last section for more information



template <class T>
class Graph {
private:

  unordered_map<T, Vertex<T>> nodes;
public:
  Graph() {};  //No modification needed to default constructor. Can be used optionally if needed.
  ~Graph() {}; //No modification needed to destructor. Can be used optionally if needed.

  // build a graph - refer the instructions PDF for more information.
  void buildGraph(istream &input) {
          T values, key;
          string line;
          while(getline(input, line)) {
              stringstream ss(line);
              ss >> values;
              key = values;
              Vertex<T> v(key);
              while(ss >> values) {
                  v.adj_list.push_back(values);
              }
              nodes.insert(make_pair(key, v));
          }
      }

  // display the graph into o - refer the instructions PDF for more information.
  void displayGraph(ostream& o) {
          for (auto it : nodes) {
              o << it.first << ": ";
              for (unsigned int i = 0; i < it.second.adj_list.size(); ++i) {
                  o << it.second.adj_list.at(i) << " ";
              }
              o << endl;
          }
      }

  //return the vertex at label, else throw any exception  - refer the instructions PDF for more information.
  Vertex<T> at(T label) {
          if (nodes.size() == 0) {
              throw invalid_argument("error");
          }
          for (auto it : nodes) {
              if (it.first == label) {
                  return it.second;
              }
          }
          throw invalid_argument("error");
      }

  //return the graph size (number of verticies)
  int size() {
	  return nodes.size();
      }


  bool topological_sort(){
  	  queue<Vertex<T>> q;
  	  int counter = 0;
  	  for (auto it = nodes.begin(); it != nodes.end(); it++) {
  		  if (it->second.indegree==0) {
  			  q.push(it->second);
  		  }
  	  }
  	  while (!q.empty()) {
  		  nodes.at(q.front().label).top_num = counter++;
  		  for (int i = 0; i < q.front().adj_list.size(); i++) {
  			  if (--(nodes.at(q.front().adj_list[i]).indegree) == 0) {
  				  q.push(nodes.at(q.front().adj_list[i]));
  			  }
  		  }
  		  q.pop();
  	  }
  	  if (counter != size()) {
  		  return false;
  	  }
  	  return true;
    };

  // find indegree
  void compute_indegree(){
	  for (auto it = nodes.begin(); it != nodes.end(); it++) {
	  		  Vertex<T> temp = it->second;
	  		  for (int i = 0; i < temp.adj_list.size(); i++) {
	  			  nodes.at(temp.adj_list[i]).indegree++;
	  		  }
	  	  }
  }; // Part 2

  void print_top_sort(ostream& o, bool addNewline=true)
    {
      //TODO - implement things here
    if(addNewline){o << '\n';};
  	for (int i = 0; i <= nodes.size(); i++) {
  		for (auto it = nodes.begin(); it != nodes.end(); it++) {
  			if (it->second.top_num == i) {
  				o << it->first << " ";
  			}
  		}
  	}
    }; // Part 2
  };

#endif

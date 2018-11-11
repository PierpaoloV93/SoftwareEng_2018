#ifndef __VERTEX_H_
#define __VERTEX_H_

#include "Face.h"
#include <iostream>
#include <vector>
#include <queue>

#include <CGAL/basic.h>
#include <CGAL/Search_traits.h>
#include <CGAL/point_generators_3.h>
#include <CGAL/Orthogonal_k_neighbor_search.h>

using namespace std;

class Face;

          class Vertex{
                private:
                        
                        int index; //this is the index of the vertex inside the face
                        bool mark; //still unknown
                        bool isInterest; //is an interest point yes or no?
						vector<int> faces;
                        set<int> adjacentVertices; //set of points which creates a face
						
                        int depth; //k-th ringhood
                        double response; //det(A) -k*trace(A)^2
                        int numNeighbors; //#vertices in the ringhood

                public:
                        double v[3]; //an array of X, Y, Z (fixed dimension we did in class!!)
                        Vertex() {v[0] = v[1] = v[2] = 0; mark = false; depth = 0;isInterest = 0;} //by default all the points are setto 0
                        Vertex(double x1, double y1, double z1) {v[0] = x1; v[1] = y1; v[2] = z1;mark = false; depth = 0;isInterest = 0;}
						
                        double x() const { return v[ 0 ]; } //different way of Getx, y z
						double y() const { return v[ 1 ]; }
						double z() const { return v[ 2 ]; }

                        double& x() { return v[ 0 ]; }
						double& y() { return v[ 1 ]; }
						double& z() { return v[ 2 ]; }
						
                        //To find out the reason why using two different types of function for the same task,
                        //Ask to Jhon Mauro
						double getX() {return v[0];}
						double getY() {return v[1];}
						double getZ() {return v[2];}
						
                        void setX(double x1) {v[0] = x1;} //I am setting the values of my point (my Vertex)
						void setY(double y1) {v[1] = y1;}
						void setZ(double z1) {v[2] = z1;}

                        //overloading the == to define = between a Vertex
						bool operator==(const Vertex& p) const
						{
							return (x() == p.x()) && (y() == p.y()) && (z() == p.z())  ;
						}

                        bool  operator!=(const Vertex& p) const { return ! (*this == p); } //return true if the object i am giving is different
                        //to the one i am using NOW (this)
						
                        friend ostream& operator<<(ostream& out, Vertex& point); //investigate on this function, what does it do.

                        //The following fuctions give the possibility of acces the "private member of the class " from outside
                        void setVertex(double x1, double y1, double z1){v[0] = x1; v[1] = y1; v[2] = z1;} //why not using set() ?
                        void setIndex(int ind){index = ind;}
                        int getIndex(){return index;}
                        bool isMarked(){return mark;} //what is mark?
                        void setMark(bool mark1){mark = mark1;}
						int getDepth(){ return depth;}
						void setDepth(int dep){ depth = dep;}
						double getResponse(){return response;}
						void setResponse(double resp){response = resp;}
						bool getInterest(){return isInterest;}
                        
                        void getNeighborhood(int rad, vector<Vertex*>& V, Vertex* vertices); //Am I passing the face and the coord. of each point?
						int getRadius(Vertex* vertices, double radius, vector<Vertex*>& V);
						
						
                        void addVertex(int vertex){ adjacentVertices.insert(vertex);} //add a new vertex
						void addFace(int face){ faces.push_back(face); }
                        void processMaximum(Vertex* vertices, int numRings); //calculate the max
						vector<int>& getFaces(){ return faces;}
						set<int>& getAdjacentVertices() { return adjacentVertices;}
		};

namespace CGAL {

  template <>
  struct Kernel_traits<Vertex> {
    struct Kernel {
      typedef double FT;
      typedef double RT;
    };
  };
}


struct Construct_coord_iterator {
  const double* operator()(const Vertex& p) const
  { return static_cast<const double*>(p.v); }

  const double* operator()(const Vertex& p, int)  const
  { return static_cast<const double*>(p.v+3); }
};
#endif

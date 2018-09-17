#include <iostream>
#include <memory>
#include <list>
 
class Graph {
    public:
        Graph(int num_vertices);

        void AddEdge(int v, int w); 

        void PrintEdges() const;

    private:
        int m_NumVertices;

        std::list<int> *m_AdjList;
};
 
Graph::Graph(int num_vertices) :
    m_NumVertices(num_vertices) {

    m_AdjList = new std::list<int>[num_vertices];
}
 
void Graph::AddEdge(int v, int w) {
    m_AdjList[v].push_back(w);
    m_AdjList[w].push_back(v);
}

void Graph::PrintEdges() const {
    for (int i = 0; i < m_NumVertices; i++) {
        std::cout << i << ": ";

        for (auto v : m_AdjList[i])
            std::cout << v << " ";

        std::cout << std::endl;
    }
}

int main(int argc, char **argv) {
    std::shared_ptr<Graph> graph(new Graph(3));

    graph->AddEdge(0, 1);
    graph->AddEdge(1, 2);
    graph->AddEdge(2, 0);

    graph->PrintEdges();

    return EXIT_SUCCESS;
}
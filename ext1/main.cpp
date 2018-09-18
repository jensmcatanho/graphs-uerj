#include <iostream>
#include <memory>
#include <list>
#include <vector>
 
class Graph {
    public:
        Graph(int num_vertices);

        void AddEdge(int v, int w); 

        void PrintEdges() const;

        void MVC() const;

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

void Graph::MVC() const {
    std::vector<bool> visited(m_NumVertices, false);

    for (int v = 0; v < m_NumVertices; v++) {
        if (!visited[v]) {

            for (auto w : m_AdjList[v]) {
                
            }

             for (i= adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == false)
                {
                     // Add the vertices (u, v) to the result set.
                     // We make the vertex u and v visited so that
                     // all edges from/to them would be ignored
                     visited[v] = true;
                     visited[u]  = true;
                     break;
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    std::shared_ptr<Graph> graph(new Graph(6));

    graph->AddEdge(4, 2);
    graph->AddEdge(1, 3);
    graph->AddEdge(4, 5);
    graph->AddEdge(3, 4);
    graph->AddEdge(1, 4);
    graph->AddEdge(2, 0);
    graph->AddEdge(0, 1);

    graph->PrintEdges();

    return EXIT_SUCCESS;
}
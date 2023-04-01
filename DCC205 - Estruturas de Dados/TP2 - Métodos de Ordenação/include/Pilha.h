class ItemPilha {
   public:
    int inicio, fim;
    ItemPilha() : inicio(0), fim(0){};
    ItemPilha(int e, int d) : inicio(e), fim(d){};
    
    friend class Node;
};

class Node {
   private:
    ItemPilha item;
    Node *prox;

   public:
    Node() : item(-1, -1), prox(nullptr){};
    Node(ItemPilha info) : item(info), prox(nullptr){};
    Node(ItemPilha info, Node *p) : item(info), prox(p){};

    friend class Pilha;
};

class Pilha {
   private:
    Node* topo;

   public:
    Pilha() : topo(nullptr), tamanho(0){};
    ~Pilha() { Limpa(); };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };

    void Empilha(ItemPilha item);
    ItemPilha Desempilha();
    void Limpa();

   protected:
    int tamanho;
};
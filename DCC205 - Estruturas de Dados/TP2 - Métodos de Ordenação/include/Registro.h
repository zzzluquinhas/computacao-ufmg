class Item {
   private:
    float reais[10];
    char caracteres[15][200];

   public:
    int chave;
    Item() : chave(-1){};
    Item(int c) : chave(c){};
};
struct intrusive_node {
  struct intrusive_node* next;
  struct intrusive_node* prev;
};

struct intrusive_list {
  struct intrusive_node* head;
};

void init_list(struct intrusive_list *lst);
void add_node(struct intrusive_list *lst, struct intrusive_node *node);
void remove_node(struct intrusive_list *lst, struct intrusive_node *node);

int get_length(struct intrusive_list *lst);

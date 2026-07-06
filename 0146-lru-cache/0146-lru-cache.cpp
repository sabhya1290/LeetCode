class Node
{
    public:
    int key;
    int value;
    short prev;
    short next;
    Node(int key, int value, short next) : key(key), value(value), prev(0), next(next) {}
};

class LRUCache
{
    private:
    vector<Node> nodes;
    short indices[10001];
    int capacity;

    public:
    LRUCache(int capacity) : capacity(capacity + 1)
    {        
        memset(indices, 0, sizeof(indices));
        nodes.reserve(this->capacity);
        nodes.emplace_back(0, 0, 0);
    }
    
    int get(int key)
    {
        short index = indices[key];
        if (index != 0)
        {
            Node& node = nodes[index];
            
            nodes[node.next].prev = node.prev;            
            nodes[node.prev].next = node.next;

            node.prev = 0;
            node.next = nodes[0].next;

            nodes[0].next = nodes[nodes[0].next].prev = index;

            return node.value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        short index = indices[key];
        if (index != 0)
        {
            Node& node = nodes[index];
            nodes[node.next].prev = node.prev;
            nodes[node.prev].next = node.next;
            
            node.value = value;
            node.prev = 0;
            node.next = nodes[0].next;
        }
        else
        {
            index = nodes.size();
            if (index == capacity)
            {   
                index = nodes[0].prev;
                Node& node = nodes[index];
                indices[node.key] = 0;

                nodes[node.next].prev = node.prev;
                nodes[node.prev].next = node.next;

                node.key = key;
                node.value = value;
                node.prev = 0;
                node.next = nodes[0].next;
            }
            else
            {
                nodes.emplace_back(key, value, nodes[0].next);
            }
            indices[key] = index;
        }
        nodes[0].next = nodes[nodes[0].next].prev = index;
    }
};

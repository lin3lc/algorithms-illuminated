#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H

#include <stdbool.h>
/*adjacency list*/
struct edge;

//不完整类型,不能作为其它结构的成员或数组的元素
struct vertex
{
    int x;
    int y;
    bool explored;
    int n_edge;
    //灵活数组成员
    struct edge *edges[];
};

struct edge
{
    struct vertex *v1;
    struct vertex *v2;
};

#endif

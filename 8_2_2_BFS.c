#include <stdio.h>
#include <stdlib.h>
#include "graph_adjacency_list.h"
#include "queue_vertex.h"

int main(void){
    /*初始化图的数据
     
           5
           |
         3 4
        /  | 
       0-1-2
       
     */
    size_t n1 = sizeof(struct vertex);
    size_t n2 = sizeof(struct edge*);
    struct vertex *v0 = malloc(n1 + 2*n2); v0->n_edge = 2;
    struct vertex *v1 = malloc(n1 + 2*n2); v1->n_edge = 2;
    struct vertex *v2 = malloc(n1 + 2*n2); v2->n_edge = 2;
    struct vertex *v3 = malloc(n1 + n2);   v3->n_edge = 1;
    struct vertex *v4 = malloc(n1 + 2*n2); v4->n_edge = 2;
    struct vertex *v5 = malloc(n1 + n2);   v5->n_edge = 1;

    v0->x = 0, v0->y = 0, v0->explored = false;
    v1->x = 1, v1->y = 0, v1->explored = false;
    v2->x = 2, v2->y = 0, v2->explored = false;
    v3->x = 1, v3->y = 1, v3->explored = false;
    v4->x = 2, v4->y = 1, v4->explored = false;
    v5->x = 2, v5->y = 2, v5->explored = false;

    struct vertex *v[] = 
    {
        v0, v1, v2, v3, v4, v5
    };

    struct edge e[5] = 
    {
        {v[0], v[3]}, {v[0], v[1]},
        {v[1], v[2]}, {v[2], v[4]},
        {v[4], v[5]}
    };

    v[0]->edges[0] = &e[0];  v[0]->edges[1] = &e[1];
    v[1]->edges[0] = &e[1];  v[1]->edges[1] = &e[2];
    v[2]->edges[0] = &e[2];  v[2]->edges[1] = &e[3];
    v[3]->edges[0] = &e[0];  
    v[4]->edges[0] = &e[3];  v[4]->edges[1] = &e[4];
    v[5]->edges[0] = &e[4];  

/*BFS*/

    /*
           5
           |
         3 4
        /  | 
       0-1-2

    0点为起始点
     */

    v[0]->explored = true;

    //初始化
    struct queue *q = create_queue();
    en_queue(q, v[0]);
    
    //命令行打印
    printf("%d %d\n", v[0]->x, v[0]->y);

    struct vertex *temp = NULL;
    while(temp = de_queue(q))
    {
        for(int i=0; i<temp->n_edge; i++)
        {
            //找出与这点连接的另一个点
            struct vertex *v_another;
            if(temp->edges[i]->v1->x == temp->x && 
               temp->edges[i]->v1->y == temp->y)
            {
                v_another = temp->edges[i]->v2;
            } else {
                v_another = temp->edges[i]->v1;
            }
            
            if(v_another->explored == false){
                v_another->explored = true;
                en_queue(q, v_another);

                //命令行打印
                printf("%d %d\n", v_another->x, v_another->y);
            }
        }
    }

/*BFS*/

    //数据资源释放
    for(int i=0; i<6; i++)
    {
        free(v[i]);
    }
    return 0;
}



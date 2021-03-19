#ifndef QUEUE_VERTEX_H
#define QUEUE_VERTEX_H

#include <stdio.h>
#include <stdlib.h>
#include "graph_adjacency_list.h"

struct q_node
{
    struct vertex *data;
    struct q_node *next;
};

struct queue
{
    struct q_node *front, *rear;
};

static struct q_node* new_node(struct vertex *data)
{
    struct q_node *temp = malloc(sizeof(struct q_node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct queue* create_queue()
{
    struct queue *temp = malloc(sizeof(struct queue));
    temp->front = temp->rear = NULL;
    return temp;
}

struct queue* destroy_queue(struct queue* q)
{
    if(q->front == NULL){
        free(q);
    }
}

void en_queue(struct queue *q, struct vertex *data)
{
    struct q_node *temp = new_node(data);

    //如果是空队列
    if(q->front == NULL){
        q->front = q->rear = temp;
        return;
    } 

    //连接队列
    q->rear->next = temp;

    q->rear = temp;
}

struct vertex* de_queue(struct queue *q)
{
    //如果是空队列
    if(q->front == NULL){
        return NULL;
    }
    struct q_node *temp = q->front;
    struct vertex *data = temp->data;
    
    q->front = temp->next;

    //如果队列空了
    if(q->front == NULL){
        q->rear = NULL;
    }

    free(temp);

    return data;
}

#endif

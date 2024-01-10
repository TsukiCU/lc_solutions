#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
 * Note that in this case, ListNode **heap is used to take the place of HEAP *heap!!
 */
void build_heap(struct ListNode** heap, int len){
    for(int i=len/2-1; i>=0; i--){
        heapify(heap, i, len);
    }
}

void heapify(struct ListNode** heap, int k, int len){
    struct ListNode *tmp = NULL;
    for(int i=2*k+1; i<len; i=2*i+1){
        if(i+1<len && heap[i+1]->val<heap[i]->val){
            i++;
        }
        if(heap[k]->val<=heap[i]->val){
            break;
        }
        else{
            tmp = heap[k];
            heap[k] = heap[i];
            heap[i] = tmp;
            k = i;
        }
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode **heap = malloc(listsSize*sizeof(struct ListNode));
    struct ListNode *head = malloc(sizeof(struct ListNode)), *tail = head;
    head->next = NULL;
    int i, j=0, k = listsSize;
    for(i=0; i<k; i++){
        if(!lists[i]){
            listsSize--;
        }
        else{
            heap[j++] = lists[i];
        }
    }
    while(listsSize){
        build_heap(heap, listsSize);
        tail->next = heap[0];
        tail = tail->next;
        if(heap[0]->next){
            heap[0] = heap[0]->next;
        }
        else{
            listsSize--;
            heap[0] = heap[listsSize];
        }
    }
    return head->next;
}

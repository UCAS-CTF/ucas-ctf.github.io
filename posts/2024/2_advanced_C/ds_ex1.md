# 双向链表的实现 

Author: [doyo](https://github.com/doyo2024)

&emsp;&emsp;完整代码详见<a href="https://ucas-ctf.github.io/posts/2024/2_advanced_C/code/ds_ex1/doubly_linked_list.c" download="doubly_linked_list.c">此处（点击下载）</a>。

&emsp;&emsp;双向链表与单向链表类似，仅仅是多了一个指向前一个元素的前驱指针：

```c
typedef int ElemType;
struct node {
    ElemType data;
    struct node *pred, *next;
};
```

前驱指针的引入能使链表更灵活地处理一些问题，但也会影响链表的插入和删除操作。

## 双向链表的插入操作

&emsp;&emsp;在单向链表的插入操作基础上添加了对前驱指针的维护：

```c
void ListInsert(int k, ElemType data) {
    if (k == 1) {
        struct node *ptr = NewSpace;
        ptr->data = data;
        ptr->pred = NULL;               // 表头的前驱为空
        ptr->next = list;
        list = ptr;
        return;
    }
    
    struct node *now = ListAccess(k - 1);

    if (now != NULL) {
        struct node *ptr = NewSpace;
        ptr->data = data;
        ptr->pred = now;                // 新元素的前驱指向它的前一个元素
        ptr->next = now->next;
        now->next = ptr;
    }
}
```

## 双向链表的删除操作

&emsp;&emsp;在单向链表的删除操作基础上添加了对前驱指针的维护：

```c
void ListRemove(int k) {
    if (k == 1) {
        if (list == NULL) {
            printf("Sorry, the list is empty.\n");
            return;
        }

        struct node *ptr = list;
        list = list->next;
        if (list != NULL)
	        list->pred = NULL;
        free(ptr);
    }
    
    struct node *now = ListAccess(k - 1);

    if (now != NULL) {
        struct node *ptr = now->next;
        if (ptr == NULL) {
        	printf("Sorry, there are only %d elements in the list.\n", k - 1);
            return;
		}
        now->next = ptr->next;
        if (ptr->next != NULL)
        	ptr->next->pred = now;      // 被删除元素的后一个元素的前驱指向被删除元素的前一个元素
        free(ptr);
    }
}
```
# Linked List

## Singly Linked List

```C
    #include <stdio.h>
    #include<stdlib.h>
    
    struct node{
        int data;
        struct node *next;
    };
    struct node* insertNewnode(struct node *head){
        int value,pos;
        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter Value:");
        scanf("%d",&value);
        newNode->next=NULL;
        newNode->data=value;
        printf("Enter Pos");
        scanf("%d",&pos);
        if(pos==1){
            newNode->next=head;
            head=newNode;
        }
        else{
            int count;
            struct node *temp=head; 
            for(count=1; count<pos-1 && temp != NULL;count++){
                temp=temp->next;
            }
            if(temp != NULL){
                newNode->next=temp->next; 
                temp->next=newNode;
            }
            else{
                printf("Enter Valid Position!");
            }
            
        }
        return head;
    }
    
    struct node* deleteNode(struct node *head){
        if(head == NULL){
            printf("List is Empty!");
            return head;
        }
        int pos;
        struct node *delNode;
        printf("\nEnter node Position to delete: ");
        scanf("%d",&pos);
        if(pos==1){
            // Delete node
            delNode = head;
            head = head->next;
            free(delNode);
        }
        else{
            int count;
            struct node *temp=head; 
            for(count=1; count<pos-1 && temp != NULL;count++){
                temp=temp->next;
            }
            if(temp != NULL && temp->next != NULL){
                // Delete node
                delNode = temp->next;
                temp->next = temp->next->next;
                free(delNode);
            }
            else{
                printf("Enter Valid Position!");
            }
        }
        return head;
    }
    
    void display(struct node *head){
        struct node *temp=head;
        printf("\n");
        while(temp != NULL){
            printf("%d->",temp->data);
            temp=temp->next;             
        }
        printf("NULL\n");
    }
    
    int main(){
        struct node *head=NULL;
        int choice;
    
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit");
            
        do{
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
    
            switch(choice){
                case 1:
                    head=insertNewnode(head);
                    break;
                case 2: 
                    head=deleteNode(head);
                    break;
                case 3:
                    display(head);
                    break;
            }
            
        }while(choice < 4);
        return 0;
    }
```

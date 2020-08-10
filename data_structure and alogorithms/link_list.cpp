#include<iostream>
using namespace std ;



struct node{
    int data ;
    struct node* next;
};

struct node *head = NULL;

struct node*  insert_data(int data){

    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));

    
    p->data = data ;
    p->next = NULL;
    return p;
   


};

void insert_node(struct node* p){

    if(head == NULL){
        head = p;
        cout<<"value has been inserted position 1"<<endl;
    }else{
        int counter =2 ;
        struct node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            counter = counter +1;
        }
        temp->next = p;
        cout<<"value has been inserted at position"<<counter<<endl;
        cout<<"\n";
    }

   


};


void del_node(int position){
    
    struct node* p = head;
    struct node* prev ;
    int counter = 0;


    if(position == 0){
        p = p->next;
        head = p;
        cout<<"first node has been deleted"<<endl;

    }else if(position>0){
        prev = p;
    while(counter!=position){
        prev = p;
        p = p->next;

        counter++;

    }
    delete(prev->next);
    prev->next = p;
    
    cout<<"node has been deleted";

    }

}

int traverse_list(){

    if(head == NULL){
        cout<<"list is empty";
        return 0;

    }else{
        int i ;

        struct node* temp = head;

        for(i = 0; temp->next !=NULL;i++){

            cout<<"position"<<i<<"value"<<temp->data<<endl;
            temp = temp->next;

        } 
        if(i>0){
            cout<<"position"<<i<<"value"<<temp->data<<endl;

        }
        if(i == 0){
            cout<<"position"<<i<<"value"<<temp->data<<endl;
            return 1;

   
        }

    }

    return 0;
    
}

int total_number_of_node(){

    struct node* temp = head;

    if(temp == NULL)
        return 0;

    else{
        int counter = 1;

        while(temp->next != NULL){
            counter++;
            temp = temp->next;

        }
        return counter;
    }

}


int find_value_of_node( int position){
    struct node* temp = head;
    int data;

    int counter = 0;

    while(counter !=position ){
        counter++;
        data = temp->data;
        temp = temp->next;

    }
    return data;




}


void find_biggest_node(){
    struct node * temp = head;
    int big_elm = temp->data;
    int index = 0;

    while(temp->next !=NULL){
       temp = temp->next;
       if(big_elm <temp->data){
           big_elm = temp->data;
           
       }
       index = index +1;

    }
    cout<<"biggest element at "<<index<<"th index"<<big_elm<<endl;
 }



 int find_smallest_node(){
     struct node * temp = head;
    
     if(head == NULL){
         cout<<"list is empty";
         return 0;

     }else{
         int small_elm = temp->data;
         int index = 0;

         while(temp->next != NULL){
             temp = temp->next;
             if(small_elm > temp->data){
                 small_elm = temp->data;

             }
             index += 1;
             


         }
         cout<<"the smallest element is at index"<<index<<"element"<<small_elm<<endl;
     }
     
 }



int main(){
    void del_node(int);
    void insert_node(struct node*);
    struct node* insert_data(int);
    int traverse_list(void);
    int total_number_of_node(void);
    int find_value_of_node( int);
    void find_biggest_node(void);
    int find_smallest_node(void);


    int position;
    struct node* temp;
    char input = '1' ;

    while(1){

        cout<<"Enter your choice!"<<endl;
        cout<<"1 : For Insert value"<<endl;
        cout<<"2 : For delete node"<<endl;
        cout<<"3 : Traverse the list"<<endl;
        cout<<"4 : Total node"<<endl;
        cout<<"5 : Find the middle node"<<endl;
        cout<<"6 : Find the biggest element in node"<<endl;
        cout<<"7 : find the smallest element in node"<<endl;
        cout<<"q : For Quit!"<<endl;
        

        cout<<"\n";

        cin>>input;

        if(input == '1'){

            int data ;
            cout<<"enter the data"<<endl;
            cin>>data;
            temp = insert_data(data);
            insert_node(temp);


 

        }else if(input == 'q'){
            break;



        }else if(input == '2'){
             int position;
             cin>>position;
             del_node(position);
        }else if(input == '3'){
            traverse_list();
        }
        else if(input == '4')
            cout<<total_number_of_node()<<endl;

        else if(input == '5'){
            int total = total_number_of_node();
            
            if(total == 1 and head !=NULL){
                cout<<head->data<<endl;
            }else if(total>0){
            position = total/2;
            cout<<find_value_of_node(position);
            }

            else{
                cout<<"list empty";
            }
        }else if(input == '6'){

            find_biggest_node();

        }else if(input == '7'){
            find_smallest_node();
        }
        else{
            cout<<"invalid input!\n";
        }



    

    }


}
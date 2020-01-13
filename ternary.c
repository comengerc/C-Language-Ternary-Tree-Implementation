
					//	OSMAN MANTICI
					//		150117505
					//			PROJECT #2

	#include<stdlib.h>
	#include<stdio.h>
	#include<math.h>


	struct ternary_tree{
		
		int data;
		struct ternary_tree* left;
		struct ternary_tree* middle;
		struct ternary_tree* right;
		
	};

	typedef struct ternary_tree node;	
	
	
	void insert(node** tree, int value){
		
		node *temp = NULL;
		
		if(!(*tree)){
			
			temp = (node *)malloc(sizeof(node));
			temp->left = NULL;
			temp->data = value;
			temp->middle = NULL;
			temp->right = NULL;
			*tree=temp;
			return;			
		}
		
		if(value < (*tree)->data){ // if inserted value is left
			
			insert(&(*tree)->left, value);			
			
		}
		else if(((*tree)->data < value) && (value < pow((*tree)->data, 2))) { //if inserted value is middle
			
			insert(&(*tree)->middle, value);
				
		}
		else if( (pow((*tree)->data, 2) < value )){ // if inserted value is right 
		
			insert(&(*tree)->right, value);
			
		}
	}
	
	void print_inorder(node * tree){
		
		if(tree){
			
			print_inorder(tree->left);
			printf("%d\n", tree->data);
			print_inorder(tree->middle);
			print_inorder(tree->right);
		}
	}
	
	void print_preorder(node * tree){
		
		if(tree){
			
			printf("%d\n", tree->data);
			print_preorder(tree->left);
			print_preorder(tree->middle);
			print_preorder(tree->right);
		}
	}  
	
	node*  find(node ** tree, int search){
		
		 if(!(*tree)){
		 	return NULL;
		 }
		 
		 if( search < (*tree)->data ){
		 	find(&((*tree)->left), search);
		 //	printf("Its found at left subtree.");
		 }
		 else if((search > (*tree)->data) && (search < (pow((*tree)->data, 2)  ))){
		 	find(&((*tree)->middle), search);
		 //	printf("Its found at middle subtree.");
		 }
		 else if(search > (pow((*tree)->data, 2) )){
			find(&((*tree)->right), search);
		//	printf("Its found at right subtree.");
		 }
		 else if(search == (*tree)->data){
		 //	printf("Its found at root.");
			return (*tree);
		 }		
	}
	
	int max(node **tree){
		
		while((*tree)->right != NULL){
			(*tree) = (*tree)->right;
		}
		if((*tree)->right == NULL){
			while((*tree)->middle != NULL){
				(*tree) = (*tree)->middle;
			}
		}
		
		
		
		return (*tree)->data;
													
		
		//int maxnum;
		
		//if((*tree)->right !=NULL){
			
		//	max(&(*tree)->right);
		//	maxnum= (*tree)->right->data;
				
		//}
		//else if((*tree)->middle != NULL){
			
		//	max(&(*tree)->middle);
		//	maxnum= (*tree)->middle->data;
			
		//}
		
		//maxnum= (*tree)->data;
		//return maxnum;	
	}
	
	
	int min(node **tree ){
		
		//int minnum;
		
		//if((*tree)->left != NULL){
		//	min(& (*tree)->left);
		//}
		//else{
		//	minnum = (*tree)->data;  
		//	return minnum;
		//}
		//return minnum;
		
		while((*tree)->left != NULL){
			(*tree) = (*tree)->left; 
		}
		if((*tree)->left == NULL){
			return (*tree)->data;
		}
	
	
	
	
	
	}
	
	
	
	node* remove_node(node ** tree, int x){
		
		node *temp = NULL;
		
		if((*tree)==NULL){
			printf("tree is empty.\n");
			return NULL;
		}
		
		if(	(*tree)->data == x){		// aranan root ise 
		
			// rootun lefti midi  rightý boþsa 
			if(		(*tree)->left == NULL		&&		(*tree)->middle == NULL		&&		(*tree)->right == NULL		){ 
				return NULL;
			}
			
			// mid boþ deðilse mid in minini root yap 
			else if(		(*tree)->middle != NULL		){	
				(*tree)->data = min((*tree)->middle);
				(*tree)->middle = remove_node((*tree)->middle, min((*tree)->middle));
				return (*tree); 				
			}
			else if(		(*tree)->middle == NULL		&&		(*tree)->left != NULL		){		
			
			// mid boþsa ve left boþ deðilse	left in maxý root yap		
				(*tree)->data = max((*tree)->left);
				(*tree)->left = remove_node(	(*tree)->left, max((*tree)->left)	);
				return (*tree);
			}
			
			// burda eðer rootun left i, midi boþsa ve right ý boþ deðilse; saðdaki node u root yapmam lazým 
			else if(		(*tree)->left == NULL		&&		(*tree)->middle == NULL		&&		(*tree)->right != NULL		){
			
				(*tree)->right = (*tree); // burda right ý data ya eþitlediðimde ve datayý null yaptýðýmda data silinmiþ oluyo mu ??
				(*tree)->right = remove_node((*tree), x);// ?
			}

		}
		
		// aranan rootun left inde ise
		if(	((*tree)->data) > x){			 
			
			(*tree)->left = remove_node((*tree)->left, x);
		}
		
		// aranan root un mid inde ise 
		if(	((*tree)->data < x )		&&		((pow((*tree)->data, 2) ) > x )	){ 
			
			(*tree)->middle = remove_node((*tree)->middle, x);
			return (*tree);
		}

		// aranan rootun right ýnda ise 
		if( ((pow((*tree)->data, 2) ) <	x 	)){	 
			
			(*tree)->right = remove_node((*tree)->right, x);
			return (*tree);
		}
	}
	
/*	node* remove_node2(node ** tree, int x){
		
		if((*tree)==NULL){
			printf("tree is empty.\n");
			return NULL;
		}
		
		if(	(*tree)->data == x){		// aranan root ise 
			
		
		
		}
		// aranan rootun left inde ise
		if(	((*tree)->data) > x){			 
			
			(*tree)->left = remove_node2((*tree)->left, x);
		}
		
		// aranan root un mid inde ise 
		if(	((*tree)->data < x )		&&		((pow((*tree)->data, 2) ) > x )	){ 
			
			(*tree)->middle = remove_node2((*tree)->middle, x);
			return (*tree);
		}

		// aranan rootun right ýnda ise 
		if( ((pow((*tree)->data, 2) ) <	x 	)){	 
			
			(*tree)->right = remove_node2((*tree)->right, x);
			return (*tree);
		}
		
		



		
	}
	
*/	

	
	
	
	void main(){
		
		FILE *fileptr = fopen("input.txt", "r");
		
		
		node *root;
		node *tmp;
		
		root = NULL;
		
/*		insert(&root, 6);
		insert(&root, 2);
		insert(&root, 8);
		insert(&root, 40);
		insert(&root, 1);
		insert(&root, 3);
		insert(&root, 5);
		insert(&root, 7);
		insert(&root, 35);
		insert(&root, 38);
		insert(&root, 80);
		insert(&root, 1700);
		insert(&root, 2000);
		insert(&root, 1780);
		insert(&root, 37);
		insert(&root, 39);
		insert(&root, 70);
		insert(&root, 90);
		insert(&root, 75);*/
			
		char str[5];
		int number;
		
		while(!feof(fileptr)){
						
			fscanf(fileptr, "%s", str);
			number = atoi(str);	
			insert(&root, number);	
				
		}
		
		printf(" \n\n\n after inserting, root is :  %d \n", root->data);
		
   		
	//	printf("inorder display\n");
	//	print_inorder(root);
		
		printf("pre order display\n");
		print_preorder(root);	
		
		tmp = find(&root, 4);

		if(tmp){
			printf("Its found\nSearched node = %d\n", tmp->data);
		}
		else {
			printf("data not found");
		}
		
		remove_node(&root,3);	
	//	printf("the max number is: %d", max(&root));
		
		
		printf("\nroot is after max: %d", root->data);	
	//	remove_node(&root, 6);
		
		printf("\n after remoooooveeeeeeeeeeee");
		print_preorder(root);
	
		
		fclose(fileptr);
	}


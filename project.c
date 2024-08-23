#include <stdio.h>
#include <stdlib.h>
#include "file_1.h"
#include "project.h" 
#include <string.h>

u32 slots_val[5]={1,2,3,4,5};
u32 exist =0 , admin_login ,exist_patient_mode=0;

typedef struct patient_data  patient;
u32 is_vaild_id_func(u32 id  , patient * head, u32 order);
void print_list(patient *head);
patient * get_data_byID(u32 id , patient * head);

struct patient_data{
	patient * next_node;
	u32 id ; 
	u32 age ;
	u8 gender[20];
	u8 name[20] ; 	

} ;

typedef struct Reserves_patients  Res;
struct Reserves_patients{
	u32 id ;
	u32 date ;
	Res * next_res;
	
};



patient * head_ptr =NULL;
Res * slots_ptr =NULL;
u32* get_exists_for_id(u32 id, Res *ptr, u32 *len);

void print_exit_slots(void );

u8 main(){
u32 entered=0, second_mode;	
while(1 && entered==0){	
	
u32 mode , pass , is_correct_pass=0 , num_of_trials=0 ;

while(exist==0){
	 is_correct_pass=0 , num_of_trials=0;
	
printf("Write 0 if You are admin \nwrite 1 if You are patient  \nPlease Enter the Mode : ");
scanf("%d",&mode);
admin_login=0;

if(mode==admin_mode){
	while(is_correct_pass==0 && num_of_trials<3){
	printf("Enter The password %d : ",num_of_trials+1);
	scanf("%d",&pass);
	if (pass==password){
		is_correct_pass=1;
		entered=1;
		while(admin_login==0){
        print_second_instructions();
		scanf("%d",&second_mode);
		second_mode_choice(second_mode);

		}

			
	}
	else ++num_of_trials;

	}
			
	if(is_correct_pass==0) printf("You Reach Max num of Trials , Try Again\n");
	
	
}

else if (mode==patient_mode){
	u32 id_pat ,mod_pat , val_id , tst=0;
	printf ("Enter Your ID : ");
	while(tst==0){
	scanf("%d",&id_pat);
	
	val_id=is_vaild_id_func(id_pat , head_ptr , 0);
	if (val_id==0){
		tst=1;
	while(exist_patient_mode==0){
	printf("If you need to View Your data Enter 1 \nIf You need to Show Your Reservations Enter 2\nIf you need to exist Enter 3 \n");
	printf("Enter Your choice : ");
	scanf("%d",& mod_pat);
	if(mod_pat==1){
		patient * ptr =get_data_byID(id_pat , head_ptr);
		printf("Your Name is   : %s \n",ptr->name);
		printf("Your ID   is   : %d \n",ptr->id);
		printf("Your Age is    : %d \n",ptr->age);
		printf("Your Gender is : %s \n",ptr->gender);	
	}
	else if (mod_pat==2){
		u32 len_arr;
		u32 * arr =get_exists_for_id(id_pat , slots_ptr ,&len_arr);
	
	for (int i=0 ; i<len_arr ; i++){
			printf("The Appoinment num : %d at time : %d \n",i+1 ,arr[i] );}
	}
	else if (mod_pat==3){
		exist_patient_mode=1;
	}
	else printf("Incorrect Choice ");
	
	}
	
	
	}else printf("Doesn\'t Exist ID Enter Anther : ");
	}
}

else printf("Incorrect Mode \n");
 










}
}
return 0;}

void print_second_instructions(void){
	    printf("IF you need to Add New Patient Record Enter   0\n");
		printf("IF you need to Edit Patient Record Enter      1\n");
		printf("IF you need to Reserve a slot with the dector 2\n");
		printf("IF you need to Cancel Reservation             3\n");
		printf("IF you need to Exist                          4\n");
		printf("Enter Your Choice : ");
}



void add_node_patient(u8 * name, u32 age , u8 * gender , u32 id ){
	if (head_ptr==NULL){
	patient * ptr_new_patient =(patient *) malloc(sizeof(patient));	
	ptr_new_patient->id=id;
	strcpy((char *)ptr_new_patient->name , name);
	ptr_new_patient->age=age;
	strcpy((char *)ptr_new_patient->gender , gender);
	ptr_new_patient->next_node=NULL;
	head_ptr=ptr_new_patient;
	}
	else{	
    patient * ptr_new_patient =(patient *) malloc(sizeof(patient));	
	ptr_new_patient->id=id;
	strcpy((char *)ptr_new_patient->name , name);
	ptr_new_patient->age=age;
	strcpy((char *)ptr_new_patient->gender , gender);
	ptr_new_patient->next_node=head_ptr;
	head_ptr=ptr_new_patient;
	
	}
	
	
}
		
u32 is_vaild_id_func(u32 id  , patient * head , u32 order){

	while(head!=NULL){
		if (id==head->id){
			if (order==1 ) printf("Exist ID , Enter Anther \n");
			return 0 ;}
			
		else head=head->next_node;
          }
	return 1;
}


void add_New_patient_record(void){
	u8 patient_name[20], patient_gender[20];
	u32 patient_id , patient_age ,vaild_id , vaild_data=0;

	do{
	vaild_id=0;	
	printf("Enter The Patient ID : ");
	scanf("%d",&patient_id);
	
	vaild_id=is_vaild_id_func(patient_id , head_ptr, 1);
	
	if (vaild_id==1){
	vaild_data=1;
	printf("Enter The Patient Name : ");
	scanf("%s",&patient_name);
	

	
	printf("Enter The Patient Age : ");
	scanf("%d",&patient_age);
	
	printf("Enter The Patient Gender : ");
	scanf("%s",&patient_gender);
	
	u8 *ptr_name =&patient_name[0]; 
	u8 *ptr_gender =&patient_gender[0]; 
	add_node_patient(ptr_name ,patient_age ,ptr_gender,patient_id);


	
	}	
	
	}while(vaild_data !=1);
	
	printf("Successfully  Added The Patient \n");
		
}




void print_list(patient *head) {
	int count=1;
    while (head != NULL) {
        printf("node id %d   ", head->id);
        head = head->next_node;
		count++;
    }
}




patient * get_data_byID(u32 id , patient * head){
		while(head!=NULL){
		if (id==head->id){
			
			return  head ;}
			
		else head=head->next_node;
          }
	return NULL;
}







void get_edited_data(u32 id){
	patient * old_data=get_data_byID(id , head_ptr);
	
	u8 patient_name[20], patient_gender[20];
	u32 patient_id , patient_age ,vaild_id , vaild_data=0;
    
	do{
	vaild_id=0;	
	printf("The Patient Old ID :%d  , Enter the New ID : ",old_data->id);
	scanf("%d",&patient_id);
	
	vaild_id=is_vaild_id_func(patient_id , head_ptr,0);
	
	if (vaild_id==1){
	vaild_data=1;
	printf("The Patient Old Name :%s  , Enter the New Name : ",old_data->name);
	scanf("%s",&patient_name);
	

	
	printf("The Patient Old Age :%d  , Enter the New Age : ",old_data->age);
	scanf("%d",&patient_age);
	
	printf("The Patient Old Gender :%s  , Enter the New Gender : ",old_data->gender);
	scanf("%s",&patient_gender);
	
	u8 *ptr_name =&patient_name[0]; 
	u8 *ptr_gender =&patient_gender[0]; 
	add_node_patient(ptr_name ,patient_age ,ptr_gender,patient_id);


	
	}	
	
	}while(vaild_data !=1);
	
	printf("Successfully  Updated The Patient \n");

	
}







void edit_patient_record(u32 id ){
	u32 valid=is_vaild_id_func(id , head_ptr, 0);
	if(valid==0){

		get_edited_data(id);
	}
	else{
		printf("Doesn\'t Exist ID \n");
	}
}




void add_new_solt(u32 id , u32 date ){

	if (slots_ptr == NULL){
	Res * new_res= (Res *) malloc(sizeof(Res));
	new_res->id = id ;
	new_res->date=date;
	new_res->next_res=NULL;
	slots_ptr = new_res;

	}
	else {
	Res * new_res= (Res *) malloc(sizeof(Res));
	new_res->id = id ;
	new_res->date=date;
	new_res->next_res=slots_ptr;
	slots_ptr = new_res;
	}
	printf("Successfully Added Appointment \n");
	
}




u32* get_exists_for_id(u32 id, Res *ptr, u32 *len) {
    u32 capacity = 10; // Initial assumption of 10 slots
    u32 *arr = (u32 *)malloc(capacity * sizeof(u32));
    *len = 0;

    while (ptr != NULL) {
        if (ptr->id == id) {
            if (*len >= capacity) {
                capacity *= 2;
                arr = (u32 *)realloc(arr, capacity * sizeof(u32));
            }
            arr[*len] = ptr->date;
            (*len)++;
        }
        ptr = ptr->next_res;
    }
    return arr;
}





void print_all_dates(void){
		printf("The First  Slot From 2:00 to 2:30 \n");
		printf("The Second Slot From 3:00 to 3:30 \n");
		printf("The Third  Slot From 4:00 to 4:30 \n");
		printf("The Fourth Slot From 5:00 to 5:30 \n");
		printf("The Fifth  Slot From 6:00 to 6:30 \n");
}



void print_exit_slots(){
	u32 id , date ,count=0 , tst=0;
	
		printf("Enter The patient  ID : ");
		do{
		scanf("%d",&id);
		u32 valid=is_vaild_id_func(id , head_ptr, 0);
		if (valid==0){
			tst=1;
        print_all_dates();
		printf("The Available dates is :  \n");
	    for (int i=0 ; i<5 ; i++ ){
			if(slots_val[i]== i+1 ) {
			count++;
			printf("IF you want to reserve slot number : %d  Enter %d \n",i+1,i+1);}				
		}
		if(count==0){
			printf("Sorry , All Dates are reserved \n");
		}
		else{
        printf("Enter The date : ");
		scanf("%d",&date);
		
        add_new_solt(id , date);
		
		
		for(int i=0 ; i<5 ; i++ ){
			if (slots_val[i]==date) slots_val[i]=0;
		}

		
		}
		}else printf("Doesn\'t Exist ID , Enter Anther ID :  ");

		}while(tst==0);
		
		
		}


void cancel_slot(){
	u32 len_reserved=0 , id ,tst=0;
	printf("enter the id : ");
	while(tst==0){
	scanf("%d",&id);
    u32 valid =is_vaild_id_func(id , head_ptr , 0);
	if (valid ==0 ){
		tst=1;
    u32 * arr  =  get_exists_for_id(id , slots_ptr , &len_reserved);

	for(int i= 0 ; i<len_reserved ; i++){
		slots_val[arr[i]-1]= arr[i]; 
	}

	printf("The Appoinment Canceled");
	}else printf("Doesn\'t Exist ID , Enter Anther : ");
	}
}
		
		
		
		


void second_mode_choice(u8 second_mode ){
	u32 id ;
			switch(second_mode){
			case 0:
			add_New_patient_record();
			break;
			
			case 1:
			printf("Enter The ID You Need to Edit : ");
			scanf("%d",&id);
			edit_patient_record(id);
			break;
			
			case 2:
			print_exit_slots();
			break;
			
			case 3: 
			cancel_slot();
			break;
			case 4 :
			admin_login=1;

			break;
			default :
			printf("Incorrect Choice");
			
			
		}
}


















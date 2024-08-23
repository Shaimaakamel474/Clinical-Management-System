#define admin_mode   0
#define patient_mode 1
#define password 1234


void add_node_patient(u8 *name, u32 age , u8 * gender , u32 id );
void print_second_instructions(void);
void second_mode_choice(u8 second_mode );
void add_New_patient_record(void);

void edit_patient_record(u32 id );
void get_edited_data(u32 id);
void add_new_solt(u32 id , u32 date );
void print_all_dates(void);
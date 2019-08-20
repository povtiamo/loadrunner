# 1 "d:\\\320\324\304\334\262\342\312\324\\\324\306\277\274\312\324c05\\studentreport\\\\combined_StudentReport.c"
# 1 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"








































































	

 


















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 263 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 502 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 505 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 528 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 562 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 585 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 609 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);
int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);


 
 
 
 
 
 
# 676 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											int * col_name_len);
# 737 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);


 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   int const in_len,
                                   char * * const out_str,
                                   int * const out_len);
# 762 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 774 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 782 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 788 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );

int lr_save_searched_string(char *buffer, long buf_size, unsigned int occurrence,
			    char *search_string, int offset, unsigned int param_val_len, 
			    char *param_name);

 
char *   lr_string (char * str);

 
# 859 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 866 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 888 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 964 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 993 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"


# 1005 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char *sourceString, char *fromEncoding, char *toEncoding, char *paramName);





 
 

















# 1 "d:\\\320\324\304\334\262\342\312\324\\\324\306\277\274\312\324c05\\studentreport\\\\combined_StudentReport.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/web_api.h" 1
 







# 1 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/as_web.h" 1
 






















































 




 








 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 










# 596 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/as_web.h"


# 609 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/as_web.h"



























# 647 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 715 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/as_web.h"



 
 
 






# 10 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/web_api.h" 2












 






 











  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 





 
 
 


# 7 "globals.h" 2

# 1 "C:\\Program Files (x86)\\Hp\\LoadRunner\\include/lrw_custom_body.h" 1
 





# 8 "globals.h" 2

# 1 "base64.h" 1
static unsigned char base64encode_lut[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; 

char base64decode_lut[] = { 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0,62, 0, 0, 0,63,52,53,54,55,56,57,58,59,60,61, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,
    15,16,17,18,19,20,21,22,23,24,25, 0, 0, 0, 0, 0, 0,26,27,28,
    29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,
    49,50,51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

void base64encode(char *src, char *dest, int len){ 
    int i=0, slen=strlen(src);
    for(i=0;i<slen && i<len;i+=3,src+=3) { 
        *(dest++)=base64encode_lut[(*src&0xFC)>>0x2];
        *(dest++)=base64encode_lut[(*src&0x3)<<0x4|(*(src+1)&0xF0)>>0x4];
        *(dest++)=((i+1)<slen)?base64encode_lut[(*(src+1)&0xF)<<0x2|(*(src+2)&0xC0)>>0x6]:'=';
        *(dest++)=((i+2)<slen)?base64encode_lut[*(src+2)&0x3F]:'=';
    }
    *dest='\0'; 
}

void base64decode(char *src, char *dest, int len){ 
    int i=0, slen=strlen(src);
    for(i=0;i<slen&&i<len;i+=4,src+=4) {
        char c1=base64decode_lut[*src], c2=base64decode_lut[*(src+1)], c3=base64decode_lut[*(src+2)], c4=base64decode_lut[*(src+3)];
        *(dest++)=(c1&0x3F)<<0x2|(c2&0x30)>>0x4;
        *(dest++)=(c3!=64)?((c2&0xF)<<0x4|(c3&0x3C)>>0x2):'\0';
        *(dest++)=(c4!=64)?((c3&0x3)<<0x6|c4&0x3F):'\0';
    }
    *dest='\0'; 
}

int b64_encode_string( char *source, char *lrvar ){ 
    int dest_size;
    int res;
    char *dest;
    dest_size = 1 + ((strlen(source)+2)/3*4);
    dest = (char *)malloc(dest_size);
    memset(dest,0,dest_size);
    base64encode(source, dest, dest_size);
    lr_save_string( dest, lrvar );
    res = strlen(dest);
    free(dest);
    return res;
}

int b64_decode_string( char *source, char *lrvar ){ 
    int dest_size;
    int res;
    char *dest;
    dest_size = strlen(source);
    dest = (char *)malloc(dest_size);
    memset(dest,0,dest_size);
    base64decode(source, dest, dest_size);
    lr_save_string( dest, lrvar );
    res = strlen(dest);
    free(dest);return res;
}

# 9 "globals.h" 2


 
 


# 2 "d:\\\320\324\304\334\262\342\312\324\\\324\306\277\274\312\324c05\\studentreport\\\\combined_StudentReport.c" 2

# 1 "vuser_init.c" 1
vuser_init()
{

	char login[100]="";
	strcat(login,"username=");
	strcat(login,lr_eval_string("{username}"));
	strcat(login,"&password=");
	strcat(login,lr_eval_string("{password}"));
	b64_encode_string(login,"loginId");
	lr_output_message("loginId:%s",lr_eval_string("{loginId}"));
	web_save_timestamp_param("timeStamp", "LAST");

	

 
# 33 "vuser_init.c"

	lr_start_transaction("login");

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers","LAST");
	web_reg_save_param("result","LB=","RB=","Search=Body","LAST");
	web_reg_save_param("LoginResultCode","LB=\"loginName\"\:\"","RB=\",","Search=Body","LAST");

	web_submit_data("login", 
		"Action=http://{IP}/examination//userlogin?_={timeStamp}", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"ITEMDATA", 
		"Name=loginId","Value={loginId}","ENDITEM",
		"Name=applicationId","Value=","ENDITEM",
		"Name=rememberPwd","Value=true","ENDITEM",
		"LAST");

	lr_convert_string_encoding(lr_eval_string("{result}"),"utf-8",0,"result_convert");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0 && strcmp(lr_eval_string("{LoginResultCode}"),lr_eval_string("{username}"))==0){
		lr_end_transaction("login", 0);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("login",1);
	}
 
# 79 "vuser_init.c"
	return 0;
}
# 3 "d:\\\320\324\304\334\262\342\312\324\\\324\306\277\274\312\324c05\\studentreport\\\\combined_StudentReport.c" 2

# 1 "Action.c" 1
void EncodePlainToURL(char *original, const char * output_param_name)
{
lr_convert_string_encoding(original, 0, "utf-8", "strUTF8");
lr_save_string(lr_eval_string("{strUTF8}"), output_param_name);
 
web_convert_param(original, "SourceEncoding=PLAIN", "TargetEncoding=URL", "LAST");
}
Action()
{
     
	 
	 
	 

	int i;
	char submit_data[1000]="";
	EncodePlainToURL(lr_eval_string("{examname}"),"examname_URL");

	lr_start_transaction("index");
	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers","LAST");

	web_custom_request("index",
		"Method=GET",
		"Snapshot=t2.inf",
		"URL=http://{IP}/examination/page/student/main",
		"Mode=HTML",
		"LAST");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("index", 0);
	}
	else{
		lr_end_transaction("index",1);
	}


	lr_start_transaction("queryExamInfoForPage");
	 

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers","LAST");
	web_reg_save_param("result","LB=","RB=","Search=Body","LAST");
	web_reg_save_param("paperId","LB=\"paperId\"\:\"","RB=\",","Search=Body","LAST");
	web_reg_save_param("examPlanId","LB=\"examPlanId\"\:\"","RB=\",","Search=Body","LAST");
	web_reg_save_param("examSubjectId","LB=\"examSubjectId\"\:\"","RB=\",","Search=Body","LAST");

	web_submit_data("queryExamInfoForPage", 
		"Action=http://{IP}/examination/api/examplan/queryExamInfoForPage?_={timeStamp}", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"ITEMDATA", 
		"Name=pageNo","Value=1","ENDITEM",
		"Name=pageSize","Value=4","ENDITEM",
		"Name=examPlanName","Value={examname_URL}","ENDITEM",
		"LAST");

	lr_convert_string_encoding(lr_eval_string("{result}"),"utf-8",0,"result_convert");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0&&strcmp(lr_eval_string("{examPlanId}"),"0")>0){
		lr_end_transaction("queryExamInfoForPage", 0);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("queryExamInfoForPage",1);
	}


	web_add_auto_header("Accept", "application/json, text/plain, */*");

	lr_start_transaction("examstart");
	 

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers","LAST");
	web_reg_save_param("result","LB=","RB=","Search=Body","LAST");
	web_reg_save_param("paperStatusId","LB=\"paperStatusId\"\:\"","RB=\"","Search=Body","LAST");

	web_submit_data("examstart", 
		"Action=http://{IP}/examination/api/paper/start", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"ITEMDATA", 
		"Name=paperId","Value={paperId}","ENDITEM",
		"Name=examPlanId","Value={examPlanId}","ENDITEM",
		"Name=examSubject","Value={examSubjectId}","ENDITEM",
		"LAST");

	lr_convert_string_encoding(lr_eval_string("{result}"),"utf-8",0,"result_convert");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0&&strcmp(lr_eval_string("{paperStatusId}"),"0")>0){
		lr_end_transaction("examstart", 0);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("examstart",1);
	}


	lr_start_transaction("checkExamEnd");

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers","LAST");
	web_reg_save_param("result","LB=","RB=","Search=Body","LAST");

	web_submit_data("checkExamEnd", 
		"Action=http://{IP}/examination/api/paper/checkExamEnd", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		"ITEMDATA", 
		"Name=examPlanId","Value={examPlanId}","ENDITEM",
		"Name=examGrade","Value=1","ENDITEM",
		"Name=examSubject","Value={examSubjectId}","ENDITEM",
		"LAST");

	lr_convert_string_encoding(lr_eval_string("{result}"),"utf-8",0,"result_convert");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("checkExamEnd", 0);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("checkExamEnd",1);
	}

	lr_start_transaction("exerciseDetail_before");
	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers","LAST");

	web_custom_request("exerciseDetail_before",
		"Method=GET",
		"Snapshot=t2.inf",
		"URL=http://{IP}/examination/paper/exerciseDetail?paperId={paperId}&examType=1&paperType=0",
		"Mode=HTML",
		"LAST");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("exerciseDetail_before", 0);
	}
	else{
		lr_end_transaction("exerciseDetail_before",1);
	}
    
	lr_rendezvous("exam_ready");


	 
	 
     
	for (i=1;i<=atoi(lr_eval_string("{questionCount}"));i++) { 
		 
		lr_start_transaction("download_image");

		web_url("download_image", 
			"URL=http://{IP}/examination/examdls/download?filePath={ImagePath}", 
			"Resource=0", 
			"Snapshot=t2.inf", 
			"Mode=HTTP", 
			"LAST");
		lr_convert_string_encoding(lr_eval_string("{result}"),"utf-8",0,"result_convert");
	
		if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
			lr_end_transaction("download_image", 0);
		}
		else{
			lr_output_message("result:%s",lr_eval_string("{result_convert}"));
			lr_end_transaction("download_image",1);
		}


		lr_save_string(lr_eval_string("{typeLevel}"),"type"); 
		lr_save_string(lr_eval_string("{type}"),"typeLevelLabelId"); 

		 
		if(i==atoi(lr_eval_string("{questionCount}"))){
			strcat(submit_data,"/examination/api/question/submit?paperStatusId=");
			strcat(submit_data,lr_eval_string("{paperStatusId}"));
			lr_save_string(submit_data,"saveAnswer");
		}
		else{
			lr_save_string("/examination/api/question/saveAnswer","saveAnswer");
		}
		 
		if (atoi(lr_eval_string("{type}"))==4) { 

			lr_start_transaction("saveAnswer_Blank");

			web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers","LAST");
			web_reg_save_param("result","LB=","RB=","Search=Body","LAST");

			web_custom_request("saveAnswer_Blank",
				"Method=POST",
				"URL=http://{IP}{saveAnswer}",
				"EncType=application/json;charset=UTF-8",
				"RecContentType=application/json;charset=UTF-8",
				"Mode=HTML",
				"body={\"paperResults\"\:[{",
				"body=\"paperId\"\:\"{paperId}\",",
				"body=\"examPlanId\"\:\"{examPlanId}\",",
				"body=\"examSubject\"\:\"{examSubjectId}\",",
				"body=\"userAnswer\"\: \"\", ",
				"body=\"useTime\"\: \"10\",",
				"body=\"fileList\"\:[],",
				"body=\"paperStatusId\"\:\"{paperStatusId}\",",
				"body=\"questionId\"\:\"{questionId}\",",
				"body=\"typeLevel\"\:\"{type}\",",
				"body=\"typeLevelLabelId\"\: \"{typeLevelLabelId}\",",
				"body=\"markStatus\"\:\"0\",",
				"body=\"score\"\:3,",
				"body=\"answers\"\:[{\"sequenceNo\"\:0,\"userAnswer\"\:\"{answer}\"}]}]}",
				"LAST");
		
			lr_convert_string_encoding(lr_eval_string("{result}"),"utf-8",0,"result_convert");
		
			if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
				lr_end_transaction("saveAnswer_Blank", 0);
			}
			else{
				lr_output_message("result:%s",lr_eval_string("{result_convert}"));
				lr_end_transaction("saveAnswer_Blank",1);
			}

		}
		else{ 
			if(atoi(lr_eval_string("{type}"))==5){
				lr_save_string("6","typeLevelLabelId"); 
			}

			lr_start_transaction("saveAnswer_other");

			web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers","LAST");
			web_reg_save_param("result","LB=","RB=","Search=Body","LAST");

			web_custom_request("saveAnswer_other",
				"Method=POST",
				"URL=http://{IP}{saveAnswer}",
				"EncType=application/json;charset=UTF-8",
				"RecContentType=application/json;charset=UTF-8",
				"Mode=HTML",
				"body={\"paperResults\"\:[{",
				"body=\"paperId\"\:\"{paperId}\",",
				"body=\"examPlanId\"\:\"{examPlanId}\",",
				"body=\"examSubject\"\:\"{examSubjectId}\",",
				"body=\"userAnswer\"\:\"{answer}\", ",
				"body=\"useTime\"\: \"10\",",
				"body=\"fileList\"\: [],",
				"body=\"paperStatusId\"\:\"{paperStatusId}\",",
				"body=\"questionId\"\:\"{questionId}\",",
				"body=\"typeLevel\"\:\"{type}\",",
				"body=\"typeLevelLabelId\"\: \"{typeLevelLabelId}\",",
				"body=\"markStatus\"\:\"0\"}]}",
				"LAST");
		
			lr_convert_string_encoding(lr_eval_string("{result}"),"utf-8",0,"result_convert");
		
			if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
				lr_end_transaction("saveAnswer_other", 0);
			}
			else{
				lr_output_message("result:%s",lr_eval_string("{result_convert}"));
				lr_end_transaction("saveAnswer_other",1);
			}
			
		}


		lr_think_time(5);
	};


	lr_start_transaction("exerciseDetail_after");
	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers","LAST");

	web_custom_request("exerciseDetail_after",
		"Method=GET",
		"Snapshot=t2.inf",
		"URL=http://{IP}/examination/paper/exerciseDetail?paperId={paperId}&examType=1&paperType=0",
		"Mode=HTML",
		"LAST");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("exerciseDetail_after", 0);
	}
	else{
		lr_end_transaction("exerciseDetail_after",1);
	}
	

	return 0;
}
# 4 "d:\\\320\324\304\334\262\342\312\324\\\324\306\277\274\312\324c05\\studentreport\\\\combined_StudentReport.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	 
# 23 "vuser_end.c"
	return 0;
}
# 5 "d:\\\320\324\304\334\262\342\312\324\\\324\306\277\274\312\324c05\\studentreport\\\\combined_StudentReport.c" 2


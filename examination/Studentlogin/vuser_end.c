vuser_end()
{	
	lr_start_transaction("logout");

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);

	web_url("logout", 
		"URL=http://{IP}/examination/logout", 
		"Resource=0", 
		"Referer=http://{IP}/examination/page/home/main", 
		"Snapshot=t2.inf", 
		"Mode=HTTP", 
		LAST);

    if (strcmp(lr_eval_string("{HttpCode}"),"302")==0) {
		lr_end_transaction("logout", LR_PASS);
	}
	else{
		lr_end_transaction("logout", LR_FAIL);
	}
	return 0;
}

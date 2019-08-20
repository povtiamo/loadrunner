Action()
{

	//{"questionId":"Z000010208055"},{"questionId":"Z000010208056"}
	char login[100]="";
	strcat(login,"username=");
	strcat(login,lr_eval_string("{username}"));
	strcat(login,"&password=");
	strcat(login,lr_eval_string("{password}"));
	b64_encode_string(login,"loginId");
	lr_output_message("loginId:%s",lr_eval_string("{loginId}"));
	web_save_timestamp_param("timeStamp", LAST);

/*
	lr_start_transaction("getcookies");
	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);

	web_custom_request("getcookies",
		"Method=GET",
        "Snapshot=t2.inf",
		"URL=http://{IP}/examination/login",
		"Mode=HTML",
		LAST);

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("getcookies", LR_PASS);
	}
	else{
		lr_end_transaction("getcookies",LR_FAIL);
	}

*/
	lr_start_transaction("login");

    web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);
	web_reg_save_param("code","LB=\"loginName\"\:\"","RB=\",","Search=Body",LAST);

	web_submit_data("login", 
		"Action=http://{IP}/examination//userlogin?_={timeStamp}", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
        "EncType=application/x-www-form-urlencoded; charset=UTF-8",
		ITEMDATA, 
		"Name=loginId","Value={loginId}",ENDITEM,
		"Name=applicationId","Value=",ENDITEM,
		"Name=rememberPwd","Value=true",ENDITEM,
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0 && strcmp(lr_eval_string("{code}"),lr_eval_string("{username}"))==0){
		lr_end_transaction("login", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("login",LR_FAIL);
	}

/*
	lr_start_transaction("index");
	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);

	web_custom_request("index",
		"Method=GET",
        "Snapshot=t2.inf",
		"URL=http://{IP}/examination/page/home/main",
		"Mode=HTML",
		LAST);

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("index", LR_PASS);
	}
	else{
		lr_end_transaction("index",LR_FAIL);
	}
*/


	return 0;
}

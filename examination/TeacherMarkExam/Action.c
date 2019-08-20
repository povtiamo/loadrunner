void EncodePlainToURL(char *original, const char * output_param_name)
{
lr_convert_string_encoding(original, LR_ENC_SYSTEM_LOCALE, LR_ENC_UTF8, "strUTF8");
lr_save_string(lr_eval_string("{strUTF8}"), output_param_name);
//web_convert_param(output_param_name, "SourceEncoding=PLAIN", "TargetEncoding=URL", LAST);
web_convert_param(original, "SourceEncoding=PLAIN", "TargetEncoding=URL", LAST);
}

Action()
{
	char blank[1000]="";
	char QandA[1000]="";
	//char arrangeId_index[1000]="";
	EncodePlainToURL(lr_eval_string("{examPlanName}"),"examPlanName_URL");
	//lr_output_message("examPlanName:%s",lr_eval_string("{examPlanName_URL}"));

	
	lr_start_transaction("queryExaminationList");
	//get examPlanId

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);
	web_reg_save_param("examPlanId","LB=\"examPlanId\"\:\"","RB=\",","Search=Body",LAST);

	web_submit_data("queryExaminationList", 
		"Action=http://{IP}/examination/api/examplan/queryExamPlanInfoForPage?_={timeStamp}", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		ITEMDATA, 
		"Name=pageNo","Value=1",ENDITEM,
		"Name=pageSize","Value=6",ENDITEM,
		"Name=examPlanName","Value={examPlanName_URL}",ENDITEM,
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("queryExaminationList", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("queryExaminationList",LR_FAIL);
	}

	
	lr_start_transaction("queryExaminationList");
	//get arrangeId

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);
	//web_reg_save_param("arrangeId","LB=\"arrangeId\"\:\"","RB=\"","SaveOffset=0","Search=Body",LAST);
		web_reg_save_param("arrangeId","LB=\"arrangeId\"\:\"","RB=\"","Search=Body",LAST);


	web_url("queryExaminationList", 
		"URL=http://{IP}/examination/api/inspection/onlinemark/queryExaminationList?_={timeStamp}&pageNo=1&pageSize=6&type=1", 
		"Resource=0", 
		"Snapshot=t2.inf", 
		"Mode=HTTP", 
		LAST);


    //sprintf(arrangeId_index, "{arrangeId_%s}",lr_eval_string("{index}"));
	//lr_output_message("arrangeId:%s",lr_eval_string(arrangeId_index));

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("queryExaminationList", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("queryExaminationList",LR_FAIL);
	}

	
	lr_rendezvous("Marking_ready");

	lr_start_transaction("getToMarkingInfo");
	//get /page/inspection/onlinemark/marking/Z000010201302/Z000010218884/Z000010890016
	//arrangeId/paperStatusId/paperResultId
	// paperResultId试卷ID，每次请求获取最新题目

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);
	web_reg_save_param_ex("paramName=arrangeId","LB/RE=marking/","RB/RE=/",SEARCH_FILTERS,"Scope=body",LAST);
	web_reg_save_param_ex("paramName=paperStatusId","LB/RE=marking/.{13}/","RB/RE=/",SEARCH_FILTERS,"Scope=body",LAST);
	web_reg_save_param_ex("paramName=paperResultId","LB/RE=marking/.{13}/.{13}/","RB/RE=\"}",SEARCH_FILTERS,"Scope=body",LAST);

	web_url("getToMarkingInfo", 
		"URL=http://{IP}/examination/api/inspection/onlinemark/getToMarkingInfo?arrangeId={arrangeId}", 
		"Resource=0", 
		"Snapshot=t2.inf", 
		"Mode=HTTP", 
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("getToMarkingInfo", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("getToMarkingInfo",LR_FAIL);
	}

	lr_start_transaction("getExamResultDetail");
	//获取已批改试卷所有题目的信息

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);

	web_url("getExamResultDetail", 
		"URL=http://{IP}/examination/api/inspection/onlinemark/getExamResultDetail?_={timeStamp}&arrangeId={arrangeId}&paperStatusId={paperStatusId}&paperResultId={paperResultId}", 
		"Resource=0", 
		"Snapshot=t2.inf", 
		"Mode=HTTP", 
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("getExamResultDetail", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("getExamResultDetail",LR_FAIL);
	}

	//至少要批改完一张试卷，才可以在阅卷页面默认进入第二页，达到翻到前一页的目的
	//前一张试卷
	/*lr_start_transaction("getPrevious");

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);
    web_reg_save_param("code","LB=\"code\"\:","RB=,\"","Search=Body",LAST);
	web_reg_save_param_ex("paramName=paperStatusId","LB/RE=marking/.{13}/","RB/RE=/",SEARCH_FILTERS,"Scope=body",LAST);
	web_reg_save_param_ex("paramName=paperResultId","LB/RE=marking/.{13}/.{13}/","RB/RE=\"}",SEARCH_FILTERS,"Scope=body",LAST);

	web_url("getPrevious", 
		"URL=http://{IP}/examination/api/inspection/onlinemark/getPreviousMarkedExamStatusInfo?_={timeStamp}&arrangeId={arrangeId}&currentPaperNumber=2", 
		"Resource=0", 
		"Snapshot=t2.inf", 
		"Mode=HTTP", 
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0&&strcmp(lr_eval_string("{code}"),"200")==0){
		lr_end_transaction("getPrevious", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("getPrevious",LR_FAIL);
	}
*/

	//试卷html页面
	lr_start_transaction("PaperPage");

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);

	web_custom_request("PaperPage",
		"Method=GET",
		"URL=http://{IP}/examination/page/inspection/onlinemark/marking/{arrangeId}/{paperStatusId}/{paperResultId}",
		"Mode=HTML",
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("PaperPage", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("PaperPage",LR_FAIL);
	}

    
	lr_think_time(1);



	//批改填空题
	lr_start_transaction("markExamResultAnswer_blank");

	//result批改结果：1错，2对，3半对半错
	//sequenceNo填空题空ID
	// questionType题目类型：4填空题，5简答题
	strcat(blank,"{\"paperResultId\"\:\"");
	strcat(blank,lr_eval_string("{paperResultId}"));
	strcat(blank,"\",\"sequenceNo\"\:0,\"result\"\:\"1\",\"score\"\:0,\"correctionScore\"\:null},");

	strcat(blank,"{\"paperResultId\"\:\"");
	strcat(blank,lr_eval_string("{paperResultId}"));
	strcat(blank,"\",\"sequenceNo\"\:1,\"result\"\:\"2\",\"score\"\:1,\"correctionScore\"\:null},");

	strcat(blank,"{\"paperResultId\"\:\"");
	strcat(blank,lr_eval_string("{paperResultId}"));
	strcat(blank,"\",\"sequenceNo\"\:2,\"result\"\:\"3\",\"score\"\:0.5,\"correctionScore\"\:null}");

    lr_save_string(blank,"blank");

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);

	web_submit_data("markExamResultAnswer_blank", 
		"Action=http://{IP}/examination/api/inspection/onlinemark/markExamResultAnswer?_={timeStamp}", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
        "EncType=application/x-www-form-urlencoded; charset=UTF-8",
		ITEMDATA, 
		"Name=questionType","Value=4",ENDITEM,
		"Name=jsonStr","Value=[{blank}]",ENDITEM,
		"Name=arrangeId","Value={arrangeId}",ENDITEM,
		"Name=paperStatusId","Value={paperStatusId}",ENDITEM,
		"Name=paperResultId","Value={paperResultId}",ENDITEM,
		"Name=correctionTime","Value=271",ENDITEM,
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("markExamResultAnswer_blank", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("markExamResultAnswer_blank",LR_FAIL);
	}


	

	lr_start_transaction("getToMarkingInfo_refresh");
	//刷新最新试卷

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);
	web_reg_save_param_ex("paramName=arrangeId","LB/RE=marking/","RB/RE=/",SEARCH_FILTERS,"Scope=body",LAST);
	web_reg_save_param_ex("paramName=paperStatusId","LB/RE=marking/.{13}/","RB/RE=/",SEARCH_FILTERS,"Scope=body",LAST);
	web_reg_save_param_ex("paramName=paperResultId","LB/RE=marking/.{13}/.{13}/","RB/RE=\"}",SEARCH_FILTERS,"Scope=body",LAST);

	web_url("getToMarkingInfo_refresh", 
		"URL=http://{IP}/examination/api/inspection/onlinemark/getToMarkingInfo?arrangeId={arrangeId}", 
		"Resource=0", 
		"Snapshot=t2.inf", 
		"Mode=HTTP", 
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("getToMarkingInfo_refresh", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("getToMarkingInfo_refresh",LR_FAIL);
	}

	lr_think_time(1);

	//批改简答题
	lr_start_transaction("markExamResultAnswer_QandA");

	strcat(QandA,"{\"paperResultId\"\:\"");
	strcat(QandA,lr_eval_string("{paperResultId}"));
	strcat(QandA,"\",\"result\"\:\"3\",\"score\"\:0.3}");

    lr_save_string(QandA,"QandA");

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);
    web_reg_save_param("result","LB=\"isFinishedExamMarkArrange\"\:","RB=}","Search=Body",LAST);

	web_submit_data("markExamResultAnswer_QandA", 
		"Action=http://{IP}/examination/api/inspection/onlinemark/markExamResultAnswer?_={timeStamp}", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
        "EncType=application/x-www-form-urlencoded; charset=UTF-8",
		ITEMDATA, 
		"Name=questionType","Value=5",ENDITEM,
		"Name=jsonStr","Value={QandA}",ENDITEM,
		"Name=arrangeId","Value={arrangeId}",ENDITEM,
		"Name=paperStatusId","Value={paperStatusId}",ENDITEM,
		"Name=paperResultId","Value={paperResultId}",ENDITEM,
		"Name=correctionTime","Value=271",ENDITEM,
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("markExamResultAnswer_QandA", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("markExamResultAnswer_QandA",LR_FAIL);
	}



	return 0;
}

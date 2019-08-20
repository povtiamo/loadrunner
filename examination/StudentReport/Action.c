void EncodePlainToURL(char *original, const char * output_param_name)
{
lr_convert_string_encoding(original, LR_ENC_SYSTEM_LOCALE, LR_ENC_UTF8, "strUTF8");
lr_save_string(lr_eval_string("{strUTF8}"), output_param_name);
//web_convert_param(output_param_name, "SourceEncoding=PLAIN", "TargetEncoding=URL", LAST);
web_convert_param(original, "SourceEncoding=PLAIN", "TargetEncoding=URL", LAST);
}
Action()
{
    // 考试数据获取
	// queryExamInfoForPage：@get paperId/examPlanId/examSubject
	// examstart：@get paperStatusId
	// checkExamEnd

	int i;
	char submit_data[1000]="";
	EncodePlainToURL(lr_eval_string("{examname}"),"examname_URL");

	lr_start_transaction("index");
	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);

	web_custom_request("index",
		"Method=GET",
		"Snapshot=t2.inf",
		"URL=http://{IP}/examination/page/student/main",
		"Mode=HTML",
		LAST);

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("index", LR_PASS);
	}
	else{
		lr_end_transaction("index",LR_FAIL);
	}


	lr_start_transaction("queryExamInfoForPage");
	//@get paperId/examPlanId/examSubject

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);
	web_reg_save_param("paperId","LB=\"paperId\"\:\"","RB=\",","Search=Body",LAST);
	web_reg_save_param("examPlanId","LB=\"examPlanId\"\:\"","RB=\",","Search=Body",LAST);
	web_reg_save_param("examSubjectId","LB=\"examSubjectId\"\:\"","RB=\",","Search=Body",LAST);

	web_submit_data("queryExamInfoForPage", 
		"Action=http://{IP}/examination/api/examplan/queryExamInfoForPage?_={timeStamp}", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		ITEMDATA, 
		"Name=pageNo","Value=1",ENDITEM,
		"Name=pageSize","Value=4",ENDITEM,
		"Name=examPlanName","Value={examname_URL}",ENDITEM,
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0&&strcmp(lr_eval_string("{examPlanId}"),"0")>0){
		lr_end_transaction("queryExamInfoForPage", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("queryExamInfoForPage",LR_FAIL);
	}


	web_add_auto_header("Accept", "application/json, text/plain, */*");

	lr_start_transaction("examstart");
	//@get paperStatusId

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);
	web_reg_save_param("paperStatusId","LB=\"paperStatusId\"\:\"","RB=\"","Search=Body",LAST);

	web_submit_data("examstart", 
		"Action=http://{IP}/examination/api/paper/start", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		ITEMDATA, 
		"Name=paperId","Value={paperId}",ENDITEM,
		"Name=examPlanId","Value={examPlanId}",ENDITEM,
		"Name=examSubject","Value={examSubjectId}",ENDITEM,
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0&&strcmp(lr_eval_string("{paperStatusId}"),"0")>0){
		lr_end_transaction("examstart", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("examstart",LR_FAIL);
	}


	lr_start_transaction("checkExamEnd");

	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
	web_reg_save_param("result","LB=","RB=","Search=Body",LAST);

	web_submit_data("checkExamEnd", 
		"Action=http://{IP}/examination/api/paper/checkExamEnd", 
		"Method=POST", 
		"Mode=HTTP", 
		"Snapshot=t2.inf",
		"EncType=application/x-www-form-urlencoded; charset=UTF-8",
		ITEMDATA, 
		"Name=examPlanId","Value={examPlanId}",ENDITEM,
		"Name=examGrade","Value=1",ENDITEM,
		"Name=examSubject","Value={examSubjectId}",ENDITEM,
		LAST);

	lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("checkExamEnd", LR_PASS);
	}
	else{
		lr_output_message("result:%s",lr_eval_string("{result_convert}"));
		lr_end_transaction("checkExamEnd",LR_FAIL);
	}

	lr_start_transaction("exerciseDetail_before");
	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);

	web_url("exerciseDetail_before", 
		"URL=http://{IP}/examination/paper/exerciseDetail?paperId={paperId}&examType=1&paperType=0", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/examination/css/common/bootstrap.min.css?v={timeStamp}",ENDITEM, 
		"Url=/examination/css/common/zTreeStyle/zTreeStyle.css?v={timeStamp}",ENDITEM, 
		"Url=/examination/css/common/main_zh_cn.css?v={timeStamp}",ENDITEM, 
		"Url=/examination/js/base/??jquery/jquery-1.12.2.js,bootstrap/bootstrap.min-3.3.5.js,jquery/jquery.ztree.core.min-3.5.23.js,jquery/jquery.ztree.exhide.min.js,underscore/underscore.js",ENDITEM, 
		"Url=/examination/js/lib/layer-v2.3/layer/skin/layer.css",ENDITEM,
		"Url=/examination/js/lib/layer-v2.3/layer/layer.js",ENDITEM,
		"Url=/examination/js/base/My97DatePicker/WdatePicker.js",ENDITEM,
		"Url=/examination/js/base/??seajs/2.2.3/sea.min.js,seajs/2.2.3/seajs-combo.min.js,twui.js",ENDITEM,
		"Url=/examination/css/common/images/box_bg.png",ENDITEM,
		"Url=/examination/js/base/My97DatePicker/skin/WdatePicker.css",ENDITEM,
		"Url=/examination/js/??base/core/common.js,base/core/webapp.js,base/core/promote.js,base/core/promote_zsx.js,lang/twdev/zh_cn.js,lang/examination/zh_cn.js",ENDITEM,
		"Url=/examination/css/common/images/icons_zh_cn.png",ENDITEM,
		"Url=/examination/js/??module/paper/fileEvent.js,base/common/stringUtils.js",ENDITEM,
		"Url=/examination/js/base/??jquery/jquery.rotate.js,jquery/jquery.mousewheel-3.0.6.js,jwplayer/jwplayer.js,jwplayer/jwplayer.html5.js,core/browser.js,respond/ui.js,game/swfobject.js",ENDITEM,
		LAST);

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("exerciseDetail_before", LR_PASS);
	}
	else{
		lr_end_transaction("exerciseDetail_before",LR_FAIL);
	}
    
	lr_rendezvous("exam_ready");


	//开始作答
	// 题目类型：1单选题、2多选题、3判断题、4填空题、5简答题
    //answer为作答内容，选择题作答参数数字对应的字母：0A/1B/2C/3D，填空题和简答题则和参数对应内容一致
	for (i=1;i<=atoi(lr_eval_string("{questionCount}"));i++) {//循环答题{questionCount}次
		//下载题目图片
		lr_start_transaction("download_image");

		web_url("download_image", 
			"URL=http://{IP}/examination/examdls/download?filePath={ImagePath}", 
			"Resource=0", 
			"Snapshot=t2.inf", 
			"Mode=HTTP", 
			LAST);
		lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
	
		if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
			lr_end_transaction("download_image", LR_PASS);
		}
		else{
			lr_output_message("result:%s",lr_eval_string("{result_convert}"));
			lr_end_transaction("download_image",LR_FAIL);
		}


		lr_save_string(lr_eval_string("{typeLevel}"),"type");//读取当前题目的题目类型
		lr_save_string(lr_eval_string("{type}"),"typeLevelLabelId");//填空题的typeLevelLabelId是6，其他类型题目的typeLevelLabelId都和的typeLevel一致

		//校验是否为最后一题，如果是最后一题则调用提交试卷接口
		if(i==atoi(lr_eval_string("{questionCount}"))){
			strcat(submit_data,"/examination/api/question/submit?paperStatusId=");
			strcat(submit_data,lr_eval_string("{paperStatusId}"));
			lr_save_string(submit_data,"saveAnswer");
		}
		else{
			lr_save_string("/examination/api/question/saveAnswer","saveAnswer");
		}
		//校验题目类型
		if (atoi(lr_eval_string("{type}"))==4) {//校验为填空题

			lr_start_transaction("saveAnswer_Blank");

			web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
			web_reg_save_param("result","LB=","RB=","Search=Body",LAST);

			web_custom_request("saveAnswer_Blank",
				"Method=POST",
				"URL=http://{IP}{saveAnswer}",
				"EncType=application/json;charset=UTF-8",
				"RecContentType=application/json;charset=UTF-8",
				"Mode=HTML",
				"body={\"examPlanId\"\:\"{examPlanId}\",",
				"body=\"paperResults\"\:[{",
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
				LAST);
		
			lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
		
			if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
				lr_end_transaction("saveAnswer_Blank", LR_PASS);
			}
			else{
				lr_output_message("result:%s",lr_eval_string("{result_convert}"));
				lr_end_transaction("saveAnswer_Blank",LR_FAIL);
			}

		}
		else{//非填空题 
			if(atoi(lr_eval_string("{type}"))==5){
				lr_save_string("6","typeLevelLabelId");//简答题的typeLevelLabelId是6，其他类型题目的typeLevelLabelId都和的typeLevel一致
			}

			lr_start_transaction("saveAnswer_other");

			web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);
			web_reg_save_param("result","LB=","RB=","Search=Body",LAST);

			web_custom_request("saveAnswer_other",
				"Method=POST",
				"URL=http://{IP}{saveAnswer}",
				"EncType=application/json;charset=UTF-8",
				"RecContentType=application/json;charset=UTF-8",
				"Mode=HTML",
				"body={\"examPlanId\"\:\"{examPlanId}\",",
				"body=\"paperResults\"\:[{",
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
				LAST);
		
			lr_convert_string_encoding(lr_eval_string("{result}"),LR_ENC_UTF8,LR_ENC_SYSTEM_LOCALE,"result_convert");
		
			if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
				lr_end_transaction("saveAnswer_other", LR_PASS);
			}
			else{
				lr_output_message("result:%s",lr_eval_string("{result_convert}"));
				lr_end_transaction("saveAnswer_other",LR_FAIL);
			}
			
		}


		lr_think_time(3);
	};


	lr_start_transaction("exerciseDetail_after");
	web_reg_save_param("HttpCode","LB=HTTP/1.1 ","RB= \r\n","Search=Headers",LAST);

	web_custom_request("exerciseDetail_after",
		"Method=GET",
		"Snapshot=t2.inf",
		"URL=http://{IP}/examination/paper/exerciseDetail?paperId={paperId}&examType=1&paperType=0",
		"Mode=HTML",
		LAST);

	if(strcmp(lr_eval_string("{HttpCode}"),"200")==0){
		lr_end_transaction("exerciseDetail_after", LR_PASS);
	}
	else{
		lr_end_transaction("exerciseDetail_after",LR_FAIL);
	}
	

	return 0;
}

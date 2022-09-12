Action()
{
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
	
	lr_start_transaction("UC_HomePage");
	
	web_reg_find("Fail=NotFound",
		"Text=sign up now",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("UC_HomePage", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("UC_Login");
	
	web_reg_find("Fail=NotFound",
		"Text=Welcome, <b>{username}</b>",
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=35", ENDITEM, 
		"Name=login.y", "Value=13", ENDITEM, 
		LAST);
	
	lr_end_transaction("UC_Login", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("UC_OpenItinerary");
	
	web_reg_find("Fail=NotFound",
		"Text=scheduled flights",
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("UC_OpenItinerary", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("UC_LogOut");
	
	web_reg_find("Fail=NotFound",
		"Text=sign up now",
		LAST);
	
	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("UC_LogOut", LR_AUTO);

	return 0;
}
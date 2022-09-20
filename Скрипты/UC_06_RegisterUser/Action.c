Action()
{
	lr_start_transaction("UC_06_RegisterUser");

	lr_start_transaction("HomePage");
	
	web_set_sockets_option("SSL_VERSION", "AUTO");
	
	web_reg_find("Fail=NotFound",
		"Text=sign up now",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("HomePage", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("OpenRegistration");
	
	web_reg_find("Fail=NotFound",
		"Text=First time registering",
		LAST);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t17.inf", 
		LAST);

	lr_end_transaction("OpenRegistration", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("FillRegistration");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Thank you, <b>{randomuser}</b>",
		LAST);
	
	web_submit_form("login.pl", 
		"Snapshot=t18.inf", 
		ITEMDATA, 
		"Name=username", "Value={randomuser}", ENDITEM, 
		"Name=password", "Value={randompass}", ENDITEM, 
		"Name=passwordConfirm", "Value={randompass}", ENDITEM, 
		"Name=firstName", "Value={randomuser}", ENDITEM, 
		"Name=lastName", "Value={randompass}", ENDITEM, 
		"Name=register.x", "Value=42", ENDITEM, 
		"Name=register.y", "Value=10", ENDITEM, 
		LAST);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t19.inf", 
		LAST);
	
	lr_end_transaction("FillRegistration", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("FinishRegistration");
	
	web_reg_find("Fail=NotFound",
		"Text=Welcome, <b>{randomuser}</b>",
		LAST);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("FinishRegistration", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("LogOut");
	
	web_reg_find("Fail=NotFound",
		"Text=sign up now",
		LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t20.inf", 
		LAST);
	
	lr_end_transaction("LogOut", LR_AUTO);
	
	lr_end_transaction("UC_06_RegisterUser", LR_AUTO);

	return 0;
}
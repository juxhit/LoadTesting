Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_start_transaction("UC_6_RegisterUser");
	
	web_reg_find("Fail=NotFound",
		"Text=sign up now",
		LAST);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t17.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_think_time(5);
	
	web_reg_find("Fail=NotFound",
		"Text=First time registering",
		LAST);
	
	web_submit_form("login.pl", 
		"Snapshot=t18.inf", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={password}", ENDITEM, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={address1}", ENDITEM, 
		"Name=address2", "Value={address2}", ENDITEM, 
		"Name=register.x", "Value=42", ENDITEM, 
		"Name=register.y", "Value=10", ENDITEM, 
		LAST);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t19.inf", 
		LAST);
	
	lr_end_transaction("UC_6_RegisterUser", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("UC_01_LogOut");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t20.inf", 
		LAST);
	
	lr_end_transaction("UC_01_LogOut", LR_AUTO);

	return 0;
}
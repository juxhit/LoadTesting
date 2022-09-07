Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(4);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t2.inf", 
		LAST);

	web_submit_form("login.pl", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=username", "Value=user2", ENDITEM, 
		"Name=password", "Value=pass2", ENDITEM, 
		"Name=passwordConfirm", "Value=pass2", ENDITEM, 
		"Name=firstName", "Value=first2", ENDITEM, 
		"Name=lastName", "Value=last2", ENDITEM, 
		"Name=address1", "Value=street2", ENDITEM, 
		"Name=address2", "Value=1002", ENDITEM, 
		"Name=register.x", "Value=45", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t4.inf", 
		LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t5.inf", 
		LAST);

	return 0;
}
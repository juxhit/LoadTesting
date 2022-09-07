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

	lr_think_time(18);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=user1", ENDITEM, 
		"Name=password", "Value=pass1", ENDITEM, 
		"Name=login.x", "Value=35", ENDITEM, 
		"Name=login.y", "Value=6", ENDITEM, 
		LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t3.inf", 
		LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t4.inf", 
		LAST);

	return 0;
}
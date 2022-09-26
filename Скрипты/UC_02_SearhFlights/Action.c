Action()
{
	lr_start_transaction("UC_02_SearhFlights");

	lr_start_transaction("HomePage");
	
	web_set_sockets_option("SSL_VERSION", "AUTO");
	
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
	
	lr_end_transaction("HomePage", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("Login");
	
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
	
	lr_end_transaction("Login", LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("OpenFlights");

	web_reg_find("Fail=NotFound",
		"Text=Departure City",
		LAST);
	
	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("OpenFlights", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("SearchFlights");

	web_reg_find("Fail=NotFound",
		"Text=Flight departing from <B>{depart}</B> to <B>{arrive}</B> on <B>{departDate}",
		LAST);
	
	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM,  
		"Name=findFlights.x", "Value=24", ENDITEM, 
		"Name=findFlights.y", "Value=13", ENDITEM, 
		LAST);
	
	lr_end_transaction("SearchFlights", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("LogOut");

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
	
	lr_end_transaction("LogOut", LR_AUTO);
	
	lr_end_transaction("UC_02_SearhFlights", LR_AUTO);

	return 0;
}
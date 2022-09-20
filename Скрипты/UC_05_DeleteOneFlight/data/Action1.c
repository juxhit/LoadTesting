Action1()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(6);

	web_submit_form("login.pl", 
		"Snapshot=t12.inf", 
		ITEMDATA, 
		"Name=username", "Value=user1", ENDITEM, 
		"Name=password", "Value=pass1", ENDITEM, 
		"Name=login.x", "Value=0", ENDITEM, 
		"Name=login.y", "Value=0", ENDITEM, 
		LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t13.inf", 
		LAST);

	web_submit_form("reservations.pl", 
		"Snapshot=t14.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=09/20/2022", ENDITEM, 
		"Name=arrive", "Value=Denver", ENDITEM, 
		"Name=returnDate", "Value=09/21/2022", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=46", ENDITEM, 
		"Name=findFlights.y", "Value=5", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t15.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=000;0;09/20/2022", ENDITEM, 
		"Name=reserveFlights.x", "Value=58", ENDITEM, 
		"Name=reserveFlights.y", "Value=1", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t16.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=user1", ENDITEM, 
		"Name=lastName", "Value=pass1", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=user1 pass1", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=52", ENDITEM, 
		"Name=buyFlights.y", "Value=9", ENDITEM, 
		LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t17.inf", 
		LAST);

	web_submit_form("itinerary.pl", 
		"Snapshot=t18.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=47", ENDITEM, 
		"Name=removeFlights.y", "Value=11", ENDITEM, 
		LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t19.inf", 
		LAST);

	return 0;
}
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

	lr_think_time(9);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=user1", ENDITEM, 
		"Name=password", "Value=pass1", ENDITEM, 
		"Name=login.x", "Value=63", ENDITEM, 
		"Name=login.y", "Value=6", ENDITEM, 
		LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	web_submit_form("reservations.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=09/08/2022", ENDITEM, 
		"Name=arrive", "Value=Denver", ENDITEM, 
		"Name=returnDate", "Value=09/09/2022", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=60", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=000;0;09/08/2022", ENDITEM, 
		"Name=reserveFlights.x", "Value=56", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_think_time(4);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=first1", ENDITEM, 
		"Name=lastName", "Value=last1", ENDITEM, 
		"Name=address1", "Value=street1", ENDITEM, 
		"Name=address2", "Value=1001", ENDITEM, 
		"Name=pass1", "Value=first1 last1", ENDITEM, 
		"Name=creditCard", "Value=1234432112344321", ENDITEM, 
		"Name=expDate", "Value=08/23", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=22", ENDITEM, 
		"Name=buyFlights.y", "Value=8", ENDITEM, 
		LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t7.inf", 
		LAST);

	return 0;
}
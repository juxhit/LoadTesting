RegisterUser()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t17.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_think_time(22);

	web_submit_form("login.pl", 
		"Snapshot=t18.inf", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={password}", ENDITEM, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={streetAddress}", ENDITEM, 
		"Name=address2", "Value={cityStateZip}", ENDITEM, 
		"Name=register.x", "Value=42", ENDITEM, 
		"Name=register.y", "Value=10", ENDITEM, 
		LAST);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t19.inf", 
		LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t20.inf", 
		LAST);

	return 0;
}
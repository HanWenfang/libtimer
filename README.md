libtimer
========

timer drive programming framework

1. Event Type
2. Actor Pattern ==> Message Pass Pattern


Attention:
	1. Period is the global resolution, not your applications resolution.
	2. Your app's resolution must be larger than the Period.
	3. For example:
		You will have to deal with data every 1 minute, then you can check condition every 20 seconds[Period].
	4. One task may block others


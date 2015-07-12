# DEF CON Qualifier 2015: Waiting for your Touch

**Category:** Web
**Points:** 2
**Solves:** TODO
**Description:**

> <http://waiting-for-your-touch.quals.shallweplayaga.me>
>
> HTTP Basic:
>
> username: come-on-and-slam
>
> password: welcome-to-japan


## Write-up

*From Plaid Parliament of Pwning*

This problem was a simple bootstrap-themed web app. The landing page had a form to create an account. Upon creating an account and logging in we were shown a page that had a countdown timer and a button [much like reddit's The Button subreddit](http://www.reddit.com/r/thebutton). Additionally there was a page that showed the names of users that had managed to click the button and a page that allowed for changing our user's displayed name.

It is clear our goal is to click the button and satisfy our Pavlovian response to buttons on the Internet. However, the `<input>` tag for the button had the `disabled` attribute set, rendering it unclickable. If the `disabled` attribute was removed, the button was then obviously clickable, but clicking it resulted in an error being displayed that said something along the lines of 

`your account's created_at field is too recent` 

At this point, it became clear what the solution was. We simply had to modify the request that changed our user's displayed name to also include the `created_at` field. Setting our `created_at` value to a very early Unix timestamp value like 999 succeeded and upon reloading the Button page we could click the button which gave us the flag... which I did not write down.


## Other write-ups and resources

* none yet

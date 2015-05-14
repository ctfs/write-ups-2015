import hashlib

password = open('passwords.txt').read().splitlines()
h2 = hashlib.md5("GET:/login.php").hexdigest()
for i in range(len(password)):
    h1 = hashlib.md5("factoreal:this page for admin only, go out now!:" + password[i]).hexdigest()
    result = hashlib.md5(h1 + ":554aed8c0b2d8:00000001:d6d1a0a39a93b4c3:auth:" + h2).hexdigest()
    if result == "d9b58c347f96195884ce27036f3c9546":
        print "[*] Password found: " + password[i]
        exit()

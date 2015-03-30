#!/usr/bin/python
# -*- coding: utf-8 -*-

import requests, sys, telnetlib, BeautifulSoup

def parsefile(f):
	f = open(f,'r')
	soup = f.read().replace('\n','')
	f.close()
	return soup

def getcountries(soup):
	countries=[]
	for tr in soup.findAll('tr'):
		tds = tr.findAll('td')
		if len(tds)!=5: continue
		cname=''
		if tds[1].em:
			if tds[1].em.a: cname=tds[1].em.a.contents[0].encode('utf8')
			else: cname=tds[1].em.contents[0].encode('utf8')
		elif tds[1].a: cname=tds[1].a.contents[0].encode('utf8')
		else: cname=tds[1].contents[0].encode('utf8')
		if cname=='':
			print 'SOMETHING TERRIBLE HAPPENED'
			sys.exit(3)
		countries.append([cname,tds[2].contents[0],tds[3].contents[0],tds[4].contents[0]])
	return countries

def getcountriesB(soup):
	countries=[]
	for tr in soup.findAll('tr'):
		cname=''
		tds = tr.findAll('td')
		if len(tds)!=6: continue
		cname = tds[1].a.text.encode('utf8')
		countries.append([cname,tds[0].tt.text])
	return countries

def getfirstcountry(soup):
	code=''
	for tr in soup.findAll('tr'):
		tds = tr.findAll('td')
		if len(tds)!=6: continue
		code=tds[2].a['href'].strip('/countries/').split('/')[0]
		break
	return code


def getcitycode(city):
	code=''
	params = { 'q':city }
	r = requests.get('http://www.geonames.org/search.html', params=params)
	soup = BeautifulSoup.BeautifulSoup(r.text.encode('utf8'))
	return getfirstcountry(soup)

def getsaved(fname):
	f = open('countries','r')
	saved=[]
	for line in f.readlines():
		a = unicode(line[3:].encode('utf-8'),'utf-8').strip('\n')
		b = line[:2].encode('utf8')
		saved.append([a, b])
	f.close()
	return saved

def csave(f, country, code):
	f.write(code + ' ' + country + '\n')

HOST='202.112.26.111'
HOST='202.112.28.118'
PORT='29995'
FILESAVE='countries'

soup=parsefile('wikihtml')
soup=BeautifulSoup.BeautifulSoup(soup)
#countries = getcountries(soup)
countries = getcountriesB(soup)

savedc = getsaved(FILESAVE)
cf = open(FILESAVE,'a')

bannedc = [
	'Curaçao',
	'Saint Barthélemy',
	'Åland Islands',
	'Réunion',
	'Curaçao'
]

tn = telnetlib.Telnet(HOST,PORT)
for i in range(0,20):
	print tn.read_until('---\n')
	country = tn.read_until(': ').strip(': ').strip('\n')
	print country
	ccode = ''
	for [a, b] in savedc:
		if country in bannedc: break
		if a.encode('utf-8')!=country.encode('utf-8'): continue
		ccode=b
		break
	if ccode!='':
		print '[1] COUNTRY CODE FOR ' + country + ' IS ' + str(ccode)
		tn.write(str(ccode)+'\n')
		continue
	for ca in countries:
		if country == ca[0]:
			ccode=ca[1]
			break
	if ccode=='':
		if country=='Korea (Democratic People\'s Republic of)': ccode='KP'
		elif country=='Cabo Verde': ccode='CV'
		elif country=='Palestine, State of': ccode='PS'
		elif country=='United Kingdom of Great Britain and Northern Ireland': ccode='GB'
		elif country=='Virgin Islands (British)': ccode='VG'
		elif country=='Micronesia (Federated States of)': ccode='FM'
		elif country=='Moldova (Republic of)': ccode='MD'
		elif country=='Iran (Islamic Republic of)': ccode='IR'
		elif country=='Korea (Republic of)': ccode='KR'
		elif country=='Macedonia (the former Yugoslav Republic of)': ccode='MK'
	if country=='Samoa': ccode='WS'
	elif country=='Guinea': ccode='GN'
	if country.encode('utf-8') not in bannedc:
		csave(cf, country, str(ccode))
	print '[0] COUNTRY CODE FOR ' + country + ' IS ' + str(ccode)
	tn.write(str(ccode)+'\n')

for i in range(20,70):
	print tn.read_until('---\n')
	city = tn.read_until(': ').strip(': ').strip('\n')
	code=''
	for [a, b] in savedc:
		if a!=city: continue
		code=b
		break
	if code!='':
		print '[1] CITY CODE FOR ' + city + ' IN COUNTRY '+ 'TODO' +' IS ' + str(code)
		tn.write(str(code)+'\n')
		continue
	code = getcitycode(city)
	if city=='Tekapo': code='NZ'
	elif city=='San Francisco': code='US'
	elif city=='Melboume': code='AU'
	elif city=='Rickshaw capital of the world': code='BD'
	elif city=='Mount Olympus': code='GR'
	elif city=='Jiuzhaigou Valley': code='CN'
	elif city=='Chejudo': code='KR'
	elif city=='Porto': code='PT'
	elif city=='Valencia': code='ES'
	elif city=='T.P.Ho Chi Minh': code='VN'
	elif city=='Pyramid of the Sun': code='MX'
	elif city=='Lego': code='DK' # Company...
	elif city=='Southern Alps': code='NZ'
	elif city=='Palmyra': code='SY'
	elif city=='Skytree': code='JP'
	elif city=='Italian Peninsula': code='IT'
	if code=='': code = raw_input("Please enter the code for city ["+ city +"]: ").strip('\n')
	if country not in bannedc: csave(cf, city, str(code))
	print '[0] CITY CODE FOR ' + city + ' IN COUNTRY '+ 'TODO' +' IS ' + str(code)
	tn.write(str(code)+'\n')

for i in range(70,100):
	print tn.read_until('---\n')
	mor = tn.read_until(': ').strip(': ').strip('\n')
	print mor
	code=[]
	if mor=='Which countries does Mississippi River run across?': code=['US']
	elif mor=='Which countries does Alps span?': code=['SI','FR','DE','CH','IT','AT','LI','MC']
	elif mor=='Which countries does Rhine River run across?': code=['DE','AT','CH','FR','NL','LI']
	elif mor=='Which countries does Mekong River run across?': code=['CN','MM','LA','TH','KH','VN']
	elif mor=='Which countries does Danube run across?': code=['DE','AT','SK','HU','HR','RS','BG','RO','MD','UA']
	elif mor=='Which countries does Rocky Mountains span?': code=['CA','US']
	elif mor=='Which countries does Apennine Mountains span?': code=['IT','SM']
	elif mor=='Which countries does Nile run across?': code=['ET','SD','EG','UG','CD','KE','TZ','RW','BI','SS','ER']
	elif mor=='Which countries does Andes span?': code=['AR', 'BO', 'CL', 'CO', 'EC', 'PE', 'VE']
	elif mor=='Which countries does Congo River run across?': code=['AO','BI','CM','CF','CD','GA','CG','RW','TZ','ZM']
	elif mor=='Which countries does Parana River run across?': code=['AR', 'BR', 'PY']
	else: code = raw_input("Answer: ").strip('\n').split('|')
	for i in code: tn.write(i+'\n')

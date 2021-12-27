import pyximport
from selenium import webdriver
from bs4 import BeautifulSoup
import time

browser=webdriver.Firefox()
browser.get('https://speedtypingonline.com/typing-test')
time.sleep(0.5)
browser.find_element_by_id('switchModesBtnDiv').click()
time.sleep(3)
start=time.time()
container=browser.find_element_by_id('lineDivContainer')

while time.time()-start<60.5:
    soup=BeautifulSoup(browser.page_source,'html.parser')
    ss=soup.findAll('span',class_='nxtLetter')
    to_press=''
    key=ss[0].text
    if key=='\xa0':
        key=' '
#    print(ss,[key])
    #container.send_keys(key)
    to_press+=key
    ss2=soup.findAll('span',class_='plainText')
    for x in range(21):
        key=ss2[x].text
        if key=='\xa0':
            key=' '
        to_press+=key
        #container.send_keys(key)
    container.send_keys(to_press)

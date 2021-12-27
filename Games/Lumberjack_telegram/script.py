from selenium import webdriver
from PIL import Image
from io import BytesIO
import time
from numpy import array

#link=input("Open lumber jack in web browser, what's the link: ")
link='''https://tbot.xyz/lumber/#eyJ1IjoxMjEzOTY1MjIzLCJuIjoiWUsgVGFuIiwiZyI6Ikx1bWJlckphY2siLCJjaSI6IjIwMTE4MDAxNDUyNjM5MDQ5OTUiLCJpIjoiQlFBQUFMdGhBQUE1dUd3YXdORHkwX0ZoZjJVIn03NzdmZWI2ZTUxZWMzNWNjOTc2ZDQ3MmU0OGRhMDdkNg==&tgShareScoreUrl=tg%3A%2F%2Fshare_game_score%3Fhash%3D3hvyOyu0qGHs2QKso3Spbm4aQcyh0PA2N3R80hbTQ8I'''
b=webdriver.Firefox()
b.get(link)

from selenium.webdriver.common.keys import Keys
left,right=Keys.LEFT,Keys.RIGHT

html=b.find_element_by_tag_name('html')
target_score=int(input("Target score:"))

cur_score=0
def press(key):
        global html,cur_score
        if cur_score>=target_score:
                return None
        html.send_keys(key)
        time.sleep(0.02)
        cur_score+=1

for x in range(1):
        html=b.find_element_by_tag_name('html')
        #print('Ok, trying to start game')
        html.send_keys(' ')#start game
        time.sleep(3)#needs time on this...

        for i in range(target_score//8 +1):
                if cur_score>=target_score:
                        break
                time.sleep(0.1)
                img=Image.open(BytesIO(b.get_screenshot_as_png()))
                img=Image.open(BytesIO(b.get_screenshot_as_png()))
                #b.save_screenshot(f'screenshot{i}.png')#because it's faster...
                #img=Image.open(f'screenshot{i}.png')
                arr=array(img)#vertical, then horizontal
                middle=len(arr[0])//2

                presses=[]
                for h in [800,600,400,200]:
                        h-=30
                        left_pix=sum(arr[h,middle-100][:3])
                        right_pix=sum(arr[h,middle+100][:3])
                        presses.append(left_pix>right_pix)

                        #arr[h,middle-100]=arr[h,middle+100]=[255,0,0,255]
                #img2=Image.fromarray(arr)
                #img2.save(f'look{i}.png')

                for side in presses:
                        if side:
                                press(left)
                                press(left)
                        else:
                                press(right)
                                press(right)
                                
        time.sleep(0.02)
        #b.find_element_by_class_name('icon_refresh').click()




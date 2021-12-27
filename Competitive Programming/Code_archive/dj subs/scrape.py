import requests
import os
import sys
from bs4 import BeautifulSoup

COOKIE = "" # CHANGE YOUR COOKIE
userID = 675 # CHANGE YOUR USERID
bottomSub = 10000000 # CHANGE AS NEEDED
toDownload = []
header = {'Cookie': COOKIE}

def poll():
    global bottomSub
    global toDownload
    URL = "https://dunjudge.me/ui/submissions_list.php?query_type=manage_submissions&userID%5B%5D=" + str(userID) + "&problemID%5B%5D=*&contestID%5B%5D=*&botsub=" + str(bottomSub) + "&lastupd=0"
    r = requests.get(URL, headers=header)
    print(URL)
    jsonResponse = r.json()
    for x in jsonResponse["moresub"]:
        soup = BeautifulSoup(x["str"], "html.parser")
        a_link = soup.find_all("a")
        sub_url = a_link[0]["href"]
        sub_id = a_link[0].string
        problem_name = a_link[1].string
        td = soup.find_all("td")
        name = td[3].string
        sub_time = td[4].string
        score = td[5].string
        max_time = td[6].string
        details = td[7].string
        toDownload.append((sub_url, sub_id, problem_name, name, sub_time, score, max_time, details))
    if len(toDownload) == 0:
        print("Nothing left to download")
        exit()
    bottomSub = toDownload[-1][1]
    print("bottomSub is now", bottomSub)

def download():
    global toDownload
    poll()
    while True:
        sys.stdout.write("Downloading... 000%")
        cnt = 1
        for x in toDownload:
            sub_url, sub_id, problem_name, name, sub_time, score, max_time, details = x
            if not os.path.exists(problem_name):
                os.mkdir(problem_name)
            r = requests.get("https://dunjudge.me" + sub_url, headers=header)
            soup = BeautifulSoup(r.content, "html.parser")
            files = soup.find_all("a", {"class": "submit_dropdown"})
            for file in files:
                name = file.string
                r2 = requests.get("https://dunjudge.me" + sub_url + "/" + name, headers=header)
                if r2.status_code != 200:
                    print("Failed: " + sub_url + "/" + name)
                    continue
                if os.path.exists(problem_name + "/" + str(sub_id) + "_" + name):
                    print("\nEncountered {} before, terminating early.".format(problem_name + "/" + str(sub_id) + "/" + name))
                    exit()
                with open(problem_name + "/" + str(sub_id) + "_" + name, "wb") as f:
                    f.write(("// " + name + " " + sub_time + " " + score + " " + max_time + " " + details + "\n").encode("ascii"))
                    f.write(r2.content)
            sys.stdout.write("\r")
            sys.stdout.write("Downloading... {:0>3}% [{:>50}]".format(cnt * 100 // len(toDownload), problem_name + "/" + str(sub_id) + "/" + name))
            cnt += 1
        print("\nDone")
        toDownload.clear()
        poll()

download()

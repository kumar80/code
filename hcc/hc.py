import requests
from os import system, name 

url = 'http://122.252.250.252/EndSem/CourseMaterial/Document/2020/'

def check(url):
    response = requests.head(url)
    if response.status_code == 404:
        return False
    return True

def download(file_name,url):
    _ = system('clear') 
    print(file_name)
    if check(url):
        r = requests.get(url, allow_redirects=True)
        open(file_name, 'wb').write(r.content)
  

def gen():
    num = ['0','1','2','3','4','5','6','7','8','9']
    ch  = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    sp = ['_']
    for n in range(10000000000,9999999999999):
        file_name0 = str(n)
        for ch1 in ch:
            file_name1 = file_name0 + ch1
            for ch2 in ch:
                file_name2 = file_name1 + ch2
                for ch3 in ch:
                    file_name = file_name2 + ch3 + ".pdf"
                    download(file_name,url+file_name)


gen()
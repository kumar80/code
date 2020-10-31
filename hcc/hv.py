import requests
from os import system, name 
import random
import string

url = 'http://122.252.250.252/EndSem/CourseMaterial/Document/2020/'

def get_random_string(length):
    letters = string.ascii_lowercase
    result_str = ''.join(random.choice(letters) for i in range(length))
    return result_str
    
def genRandom():
    fi = str(random.randint(200000000000,299999999999))
    se = get_random_string(3)
    return fi+se

def check(url):
    response = requests.head(url)
    if response.status_code == 404:
        print("nooo")
        return False
    return True

def download(file_name,url):
    _ = system('clear') 
    print(url)
    if check(url):
        r = requests.get(url, allow_redirects=True)
        open(file_name, 'wb').write(r.content)
  

def gen():
    num = ['0','1','2','3','4','5','6','7','8','9']
    ch  = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    sp = ['_']
    for n in range(10000000000,9999999999999):
        file_name = genRandom() + ".pdf"
        download(file_name,url+file_name)


gen()
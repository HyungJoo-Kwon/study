import requests
from bs4 import BeautifulSoup
# 크롤링 시 robot.txt 확인해야

url = "https://www.ymori.com/books/python2nen/test1.html"
response = requests.get(url)                               # 로컬로 끌어들임
print(f'response : {response}')
soup = BeautifulSoup(response.content, "html.parser")
title = soup.find("title")
jang = soup.find("h2")
li = soup.find("li")

print(soup)
print()
print(f'title - {title}')
print(f'jang - {jang}')
print(f'li - {li}')

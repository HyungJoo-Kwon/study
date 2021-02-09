import requests
from bs4 import BeautifulSoup

url = "https://kabutan.jp/stock/?code=7203"
html = requests.get(url)
soup = BeautifulSoup(html.content, "html.parser")
kubuka_stock = soup.find(class_="kabuka").text # html class : class_
print(f'kubuka_stock : {kubuka_stock}')

url = "https://finance.naver.com/item/main.nhn?code=035420"
html = requests.get(url)
soup = BeautifulSoup(html.content, "html.parser")
naver_stock = soup.find("p", {"class" : "no_today"})
print(f'naver_stock : {naver_stock}')
check = soup.find("em", {"class" : "no_down"}).text
print(f'check = {check}')




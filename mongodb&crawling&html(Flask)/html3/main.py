import requests
from flask import Flask, render_template
from bs4 import BeautifulSoup

app = Flask(__name__)

url = 'http://movie.naver.com/movie/running/current.nhn'

# 우측 클릭 -> copy -> copy selector

@app.route('/')
def data_gather():
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    # print(soup.prettify())

    ul = soup.find('ul', class_='lst_detail_t1')
    # print(ul)

    list = []
    img_list = []
    rating_list = []
    movie_name_list = []
    estimate_rate_list = []
    movie_type_list = []

    img = ul.select('li > div > a > img')
    print(f'이미지 개수 : {len(img)}')
    for i in img:
        # print(i.get('alt'))
        # print(i.get('src'))
        img_list.append(i.get('src'))

    rating = ul.select('dl > dt > span')
    for rate in rating:
        # print(rate.text)
        rating_list.append(rate.text)

    movie_names = ul.select('li > dl > dt > a')
    for movie_name in movie_names:
        # print(movie_name.text)
        movie_name_list.append(movie_name.text)

    estimate_rates = ul.select('dl > dd.star > dl.info_star > dd > div > a > span.num')
    for estimate_rate in estimate_rates:
        # print(estimate_rate.text)
        estimate_rate_list.append(estimate_rate.text)

    movie_types = ul.select('li > dl > dd:nth-child(3) > dl > dd:nth-child(2) > span.link_txt > a')
    for movie_type in movie_types:
        # print(movie_type.text)
        movie_type_list.append(movie_type.text)

    list.append(img_list)
    list.append(rating_list)
    list.append(movie_name_list)
    list.append(estimate_rate_list)
    list.append(movie_type_list)

    for i in list:
        print(len(i))

    for i in list[1]:
        print(i)

    return render_template('data_gathering')


if __name__ == "__main__":
    app.run()
#
# import requests
# from bs4 import BeautifulSoup
# from flask import Flask, render_template
#
# app = Flask(__name__)
#
# url = 'https://movie.naver.com/movie/running/current.nhn'
#
#
# class NaverMovie:
#     def __init__(self, img_src, age, movie_name, netizen, netizen_num,\
#                  actor_list, directer):
#         self.img_src = img_src
#         self.age = age
#         self.movie_name = movie_name
#         self.netizen = netizen
#         self.netizen_num = netizen_num
#         self.actor_list = actor_list
#         self.actor_list = actor_list
#         self.directer = directer
#
#
# @app.route('/')
# def hello_world():
#     response = requests.get(url)
#     soup = BeautifulSoup(response.content, 'html.parser')
#     ul = soup.find('ul', class_='lst_detail_t1')
#     movie_list = []
#     li = ul.find_all('li')
#     for piece in li:
#         img = piece.find('img')
#         actor_list = [act.text for act in piece.select('dl > dd:nth-child(3) > dl > dd:nth-child(6) > span > a')]
#         img_src = img.get('src')
#         directer = piece.select('dl > dd:nth-child(3) > dl > dd:nth-child(4) > span > a')[0].text
#         age = [ag.text for ag in piece.select('dl > dt > span')]
#         movie_name = piece.select(' dl > dt > a')[0].text
#         netizen = piece.select('dl > dd.star > dl > dd > div > a > span.num')[0].text
#         netizen_num = piece.select('dl > dd.star > dl.info_star > dd > div > a > span.num2 > em')[0].text
#         naverMovie = NaverMovie(img_src, age, movie_name, netizen, netizen_num, actor_list, directer)
#         movie_list.append(naverMovie)
#         #movie_list.append([img_src, age, movie_name, netizen, netizen_num, actor_list, directer])
#     for Movie in movie_list:
#         print(Movie)
#     return render_template('data_gathering.html', movie_list=movie_list)
#
#
# class Book:
#     def __init__(self, title, author):
#         self.title = title
#         self.author = author
#
#
# @app.route('/study')
# def study():
#     book_list = []
#     book = Book('제목1', '저자1')
#     book_list.append(book)
#
#     book = Book('제목2', '저자2')
#     book_list.append(book)
#
#     for b in book_list:
#         print(b.title, b.author)
#
#     return render_template('study.html', book_list=book_list)
#
#
# if __name__ == '__main__':
#     app.run()

import base64
import random
from bson import ObjectId
from flask import Flask, render_template, request, session
from pymongo import MongoClient
from datetime import datetime
import requests
from werkzeug.utils import redirect

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret_key'
# methods=["GET"] : 데이터 받기, methods=["POST"] : 데이터 처리


class MyMongoClient(object):
    # def __init__(self):
    #     self.client = MongoClient()
    #     self.database = self.client["kwon_db"]
    #     self.collection = self.database["books"]

    # def __init__(self):
    #     filename = 'atlas_connect_info'
    #     with open(filename, encoding='utf-8') as f:
    #         self.atlas_connection_info = f.read()
    #     self.client = MongoClient(self.atlas_connection_info)
    #     self.database = self.client["bookstore"]
    #     self.collection = self.database["books"]

    def __init__(self, collection):
        filename = 'atlas_connect_info'
        with open(filename, encoding='utf-8') as f:
            self.atlas_connection_info = f.read()
        self.client = MongoClient(self.atlas_connection_info)
        self.database = self.client["bookstore"]
        self.collection = self.database[collection]


@app.route('/')
def home():
    if 'username' in session:  # session : 서버메모리
        message = session['username'] + '님이 로그인 되었습니다.'
    else:
        message = '로그인되지 않았습니다'

    # city = 'daegu'
    # appid = 'e5d4ba22d1c0aae4130753ea87c69eec'
    # url = f'http://api.openweathermap.org/data/2.5/weather?q={city}&appid={appid}'
    # res = requests.get(url)
    # weather_data = res.json()
    #
    # description = weather_data["weather"][0]["description"]
    # icon = weather_data["weather"][0]["icon"]
    # temp = round(weather_data["main"]["temp"] - 273, 1)

    # return render_template('/index.html', temp=temp, icon=icon, description=description, message=message)
    return render_template('/index.html', message=message)


@app.route('/book_add', methods=['GET'])
def book_add():
    return render_template('/book_add.html')


@app.route('/book_add_process', methods=['POST'])
def book_add_process():
    # client = MongoClient("mongodb://localhost:27017/")
    # database = client["kwon_db"]
    # collection = database["books"]
    client = MyMongoClient()
    collection = client.collection

    title = request.form['title']
    file = request.files['file']
    author = request.form['author']
    price = request.form['price']
    isbn = request.form['isbn']
    encoded_data = base64.b64encode(file.read())

    doc = {'title': title, 'encoded_data': encoded_data, 'author': author,
           'price': price, 'created_date': datetime.now()}

    result = collection.insert_one(doc)

    book_add_result = None
    if result.inserted_id is not None:
        book_add_result = "정상 등록"
    else:
        book_add_result = "등록 실패"

    return render_template('/book_add_result.html',
                           book_add_result=book_add_result)


@app.route('/book_id_search', methods=['GET', 'POST'])
def book_id_search():
    button_name = "Select"

    return render_template('/book_id_search.html', button_name=button_name)


@app.route('/book_id_search_process', methods=['GET', 'POST'])
def book_id_search_process():
    search = request.form['search']
    if search == "검색1":
        print("check")
    else:
        print("nono")

    client = MongoClient()
    database = client["kwon_db"]
    collection = database["books"]
    _id = request.form['id']

    doc = collection.find_one({'_id': ObjectId(_id)})
    title = doc['title']
    author = doc["author"]
    price = doc["price"]

    encoded_data = doc["encoded_data"].decode("utf-8")
    # decoded_data = base64.b64decode(encoded_data) # ->: 안먹힘
    img_src_data = f'data:image/png;base64, {encoded_data}'

    return render_template('/book_id_search_result.html',
                           title=title, img_src_data=img_src_data, price=price, author=author)


@app.route('/jiji', methods=['GET', 'POST'])
def jiji():
    if request.method == 'POST':
        year = int(request.form['year'])
        jiji_list = ['자', '축', '인', '묘', '진', '사', '오', '미', '신', '유', '술', '해']
        jiji_index = (year - 4) % 12
        jiji = jiji_list[jiji_index]
    else:
        jiji = None
    return render_template('/jiji.html', jiji=jiji)


@app.route('/game', methods=['GET'])
def game():
    my_list = [
        '1-1', '1-2', '2-1', '2-2', '3-1', '3-2', '4-1', '4-2', '5-1', '5-2',
        '6-1', '6-2', '7-1', '7-2', '8-1', '8-2', '9-1', '9-2', '10-1', '10-2'
     ]
    random.shuffle(my_list)
    selected_list = my_list[0:4]
    my_score = (int(selected_list[0].split('-')[0]) + int(selected_list[1].split('-')[0])) % 10
    com_score = (int(selected_list[2].split('-')[0]) + int(selected_list[3].split('-')[0])) % 10

    # 판정
    winner = None
    if my_score > com_score:
        winner = '너다'
    elif my_score == com_score:
        winner = '없다. 무승부'
    else:
        winner = '컴퓨터다'

    return render_template('/game.html', selected_list=selected_list, winner=winner)


@app.route('/book_list', methods=['GET', 'POST'])
def book_list():
    #cluster = MongoClient("mongodb://localhost:27017/")
    #collection = cluster["kwon_db"]["books"]
    cluster = MyMongoClient()
    cursors = cluster.collection.find()
    cursors_count = cursors.count()

    count = 0
    title = []
    encoded_data = []
    author = []
    price = []
    created_date = []
    cursor_list = []

    for cursor in cursors:

        print(cursor)
        title.append(cursor["title"])
        img_src_data = f'data:image/png;base64, {cursor["encoded_data"].decode("utf-8")}'
        encoded_data.append(img_src_data)
        author.append(cursor["author"])
        price.append(cursor["price"])
        created_date.append(cursor["created_date"])
        count = count + 1

        cursor_list.append(cursor)

    # my_id = request.form['my_id']
    # print(my_id)

    print(f'count {count}')
    print(f'title : {title}')
    print(f'encoded_data - {encoded_data}')
    return render_template('/book_list.html', count=count, title=title, encoded_data=encoded_data,
                           author=author, price=price, created_date=created_date, cursor=cursor_list,
                           cursors_count=cursors_count)

    # myclient = MyMongoClient()
    # count = myclient.collection.find().count()
    # print(count)
    # books = myclient.collection.find()
    #
    # # for doc in cursor:
    # #    print(doc['title'])
    #
    # return render_template('/book_list.html', books=books)


@app.route('/book_details/<_id>')
def book_details(_id=None):
    print(_id)
    return render_template('/book_details.html')


@app.route('/book_search', methods=['GET'])
def book_search():
    return render_template('/book_search.html')


@app.route('/book_search_process', methods=['POST'])
def book_search_process():
    item = request.form['item_to_search']
    data = request.form['data_to_search']
    print(item, data)

    myclient = MyMongoClient()
    if item == 'id':
        query = {'_id': data}
    elif item == 'title':
        query = {'title': data}

    books = myclient.collection.find(query)

    return render_template('/book_search_process_result.html', books=books)


@app.route('/atlas_connect_info')
def atlas_connect_info():
    filename = 'atlas_connect_info'
    with open(filename, encoding='utf-8') as f:
        atlas_connection_info = f.read()

    cluster = MongoClient().address
    print(cluster)

    return render_template('/atlas_connect_info.html',
                           atlas_connection_info=atlas_connection_info, cluster=cluster)


@app.route('/weather', methods=['GET'])
def weather():
    city = 'daegu'
    appid = 'e5d4ba22d1c0aae4130753ea87c69eec'
    url = f'http://api.openweathermap.org/data/2.5/weather?q={city}&appid={appid}'
    res = requests.get(url)
    #weather_data = json.loads(res.text)
    weather_data = res.json()

    description = weather_data["weather"][0]["description"]
    icon = weather_data["weather"][0]["icon"]
    temp = round(weather_data["main"]["temp"]-273, 2)

    return render_template('/weather.html',
                           description=description,
                           icon=icon,
                           temp=temp)


@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == "GET":
        return render_template('login.html')
    else:
        username = request.form["username"]
        password = request.form["password"]

        myclient = MyMongoClient('users')
        cursors = myclient.collection.find()
        print("cursors:", cursors)
        for cursor in cursors:
            print("test:", cursor)
        user = myclient.collection.find_one({'username': username, 'password': password})
        if user["username"] is not None:
            print(user["username"], user["password"])
            session['username'] = user['username']  # session(서버메모리)에 등록한다
            return redirect('/')


    #return render_template('index.html', )


if __name__ == '__main__':
    app.run()
    # app.run(host='0.0.0.0', port=9900)

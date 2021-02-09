from pymongo import MongoClient
import base64
from bson import ObjectId
import pickle

#https://stackoverflow.com/questions/47668507/how-to-store-images-in-mongodb-through-pymongo


# client = MongoClient() local에 접속
client = MongoClient("localhost", 27017)  # local에 접속
photo_path = "C:\\Users\\w\\Pictures\\Saved Pictures\\run_img.jpg"

# store 방법 1
# with open(photo_path, "rb") as imageFile:
#     stored_data = base64.b64encode(imageFile.read())
# print(f'stored_data : {stored_data}')

# store 방법 2
# photo = open(photo_path, 'rb')
# print(f'photo : {type(photo.read())}')
# encoded_string = base64.b64encode(photo.read())  # 사진 비트화
# print(f'encoded_string : {type(encoded_string)}')

photo = open(photo_path, "rb")

#data = {"titles": "Python", "photo": stored_data}
#client.kwon_db.books.insert_one(data)   # 사진 db에 입력

db_photo = client.kwon_db.books.find({'_id':ObjectId("6006480a4af31f0e32748059")})
print(f'db_photo: {db_photo}, type(db_photo) : {type(db_photo)}, count : {db_photo.count()}')

for bite in db_photo:
    print(f'bite {bite}')
    print(f'type(bite) {type(bite)}')
    print(f'check {bite["encoded_data"]}')
    with open("check.jpg", mode="wb") as f:
        f.write(base64.b64decode(bite['encoded_data']))
    # with open("checkcheck.jpg", "wb") as f:
    #     f.write(bite['encoded_data'].decode('utf-8'))     # jinja(html)에서 쓰는 방법이라 python에서 write로 안먹힘





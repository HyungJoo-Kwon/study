from pymongo import MongoClient
import base64
from bson import ObjectId

client = MongoClient()
db = client.gridfs

for x in db.fs.files.find():
    print(x)

for x in db.fs.chunks.find(): # 사이즈마다 잘게 썰어 놓은거
    print(x)

photo = client.gridfs.fs.chunks.find({"files_id": ObjectId("6004f01ab875c8782aaf7f61")})
print(f'type(photo) : {type(photo)}')
for bite in photo:
    with open("fs.chunks.jpg", mode="wb") as f:
        f.write((bite["data"]))

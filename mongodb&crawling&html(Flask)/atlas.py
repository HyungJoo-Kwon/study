from pymongo import MongoClient
from pprint import pprint
# dnspython 설치 해야
# pymongo와 atlas연결
# https://www.c-sharpcorner.com/article/mongodb-atlas-with-python/
# http://blog.naver.com/PostView.nhn?blogId=shino1025&logNo=221296103823&categoryNo=25&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search
# https://wooiljeong.github.io/python/mongodb-01/

from datetime import datetime
# datetime.now().strftime('%Y--%d %m%H:%M:%S')
datetime = datetime.now()
year = datetime.year
month = datetime.month
day = datetime.day
hour = datetime.hour
minute = datetime.minute
second = datetime.second
datetime = f'{year}-{month}-{day} {hour}:{minute}:{second}'
print(datetime)

cluster = MongoClient("mongodb+srv://user-kwon:1234@kwon-cluster-start.tmtan.mongodb.net/"
                      "db-kwon?retryWrites=true&w=majority")

for db_name in cluster.list_database_names():
    print(f'database - {db_name}')
    for col_name in cluster.get_database(db_name).list_collection_names():
        print(f'    collection - {col_name}')
    print()

# db = cluster["db-kwon"]
# collection = db["books"]
collection = cluster["db-kwon"]["books"]

# input_data1 = {"_id": 1, "title":"권성규"}
# input_data2 = {"_id": 2, "title":"권123"}
# collection.insert_many([input_data1, input_data2])

results = collection.find()
for result in results:
    pprint(result)

print(collection.find({"title" : "권성규"}))





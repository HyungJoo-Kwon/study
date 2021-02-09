from flask import Flask, render_template, request
# 한 html에 GET, POST 다 되게

app = Flask(__name__)


@app.route('/')
@app.route('/newgugu', methods=['GET', 'POST'])
def new_gugu():

    if request.method == 'POST':
        dan = int(request.form['dan'])
        gugu_list = []
        for i in range(1, 10):
            gugu = f'{dan} × {i} = {dan * i}'
            gugu_list.append(gugu)

    else:
        gugu_list = []

    return render_template('new_gugu.html', gugu_list=gugu_list)


if __name__ == "__main__":
    app.run()
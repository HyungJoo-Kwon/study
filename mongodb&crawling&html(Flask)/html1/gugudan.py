from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/", methods=['GET'])
def gugudan_input():
    return render_template('gugudan_input.html')


@app.route("/gugudan_result", methods=['POST'])
def gugudan_result():
    value = request.form.get("value")
    value = int(value)
    return render_template('gugudan_result.html', value=value)


if __name__ == "__main__":
    app.run()
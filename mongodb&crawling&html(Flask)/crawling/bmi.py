# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def bmi(weight, height):
    height, weight = int(height), int(weight)
    height = height / 100
    bmi_score = weight / pow(height, 2)
    bmi_score = round(bmi_score, 2)

    if bmi_score >= 25.00:
        bmi_result = "비만"
    elif bmi_score >= 23.00:
        bmi_result = "과체중"
    elif bmi_score >= 18.5:
        bmi_result = "정상"
    else:
        bmi_result = "저체중"

    result = f'bmi 지수: {bmi_score}, bmi 결과: {bmi_result}'
    return result

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    weight = input("weight(kg): ")
    height = input("height(cm): ")
    print(bmi(weight, height))

# See PyCharm help at https://www.jetbrains.com/help/pycharm/

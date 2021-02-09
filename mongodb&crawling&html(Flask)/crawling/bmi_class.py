class Bmi:
    def __int__(self):
        self.height = 0
        self.weight = 0
        self.bmi_score = 0
        print(1)

    def __init__(self, weight, height):
        self.weight = weight
        self.height = height
        self.bmi_score = 0
        print(2)

    def bmi_calc(self):
        height, weight, bmi_score = int(self.height), int(self.weight), self.bmi_score
        height = height / 100
        bmi_score = weight / pow(height, 2)
        return round(bmi_score, 2)


if __name__ == '__main__':
    weight = input("weight(kg): ")
    height = input("height(cm): ")

    Bmi = Bmi(weight, height)
    print(f'BMI 지수 = {Bmi.bmi_calc()}')
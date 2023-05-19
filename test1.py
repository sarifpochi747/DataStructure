from gettext import find


in_txt = input("Enter digits : ")
arabic_number = "0123456789"
thai_number = "๐๑๒๓๔๕๖๗๘๙"
thai = ""

for i in in_txt:
    index = arabic_number.find(i)
    if index != -1:
        thai = thai + thai_number[index]
print(thai)



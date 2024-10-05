from django.shortcuts import render
import joblib,os

#pkl


def index(request):
    phish_model = open('templates/phishing.pkl','rb')
    phish_model_ls = joblib.load(phish_model)
    if request.method == 'GET':  
        X_predict = []
        search_text = request.GET.get("search_box")
        print(search_text)
        X_predict.append(str(search_text))
        y_Predict = phish_model_ls.predict(X_predict)
        result=""
        if y_Predict == 'bad':
            result = "Not Secure"
        else:
            result = "Secure"
    return render(request, "index.html", {'search_text':result,'text':search_text})
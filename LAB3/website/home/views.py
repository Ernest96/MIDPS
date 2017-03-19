from django.http import HttpResponse
from django.shortcuts import render
from django.http import HttpResponse
from django.template import loader
from django.http import Http404
from django.shortcuts import render

def index(request):
    return render(request, 'images/home.html')

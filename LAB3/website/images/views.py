from django.http import HttpResponse
from django.template import loader
from django.http import Http404
from .models import Category
from django.shortcuts import  render, redirect


def index(request):
    all_category = Category.objects.all()
    template = loader.get_template('images/index.html')
    context = { 'all_category': all_category,}
    return HttpResponse(template.render(context, request))

def detail(request, category_id):
    try:
        category = Category.objects.get(pk = category_id)
    except Category.DoesNotExist:
        raise Http404("Albumul nu exista")
    return render(request, 'images/detail.html', {'category' : category})
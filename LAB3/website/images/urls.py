from django.conf.urls import include, url
from . import views

urlpatterns = [
    url(r'^$', views.index, name = 'index'),
    url(r'^(?P<category_id>[0-9]+)/$', views.detail, name='detail'),
]
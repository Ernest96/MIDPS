from django.db import models

class Category(models.Model):
    name = models.CharField(max_length=64)
    year = models.CharField(max_length=5)
    category_logo = models.CharField(max_length=512)

    def __str__(self):
        return self.name

class Wallpaper(models.Model):
    category = models.ForeignKey(Category, on_delete= models.CASCADE)
    file_type = models.CharField(max_length=16)
    title = models.CharField(max_length=64)
    path = models.CharField(max_length=512)

    def __str__(self):
        return self.title
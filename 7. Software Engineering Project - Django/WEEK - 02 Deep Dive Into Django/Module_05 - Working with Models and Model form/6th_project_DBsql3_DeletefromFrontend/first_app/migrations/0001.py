# Generated by Django 4.2.4 on 2023-08-10 09:21

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Student',
            fields=[
                ('name', models.CharField(max_length=20)),
                ('roll', models.IntegerField(primary_key=True)),
                ('address', models.TextField()),
            ],
        ),
    ]

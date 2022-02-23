from setuptools import setup


setup(
    name="uwsgi-shortmsecs",
    version="0.1",
    release="0.0.1",
    author='SAP',
    url='https://github.com/sapcc/uwsgi-shortmsecs',
    long_description="README.txt",
    data_files=[('lib', [
        'shortmsecs_plugin.so'
    ])],
)
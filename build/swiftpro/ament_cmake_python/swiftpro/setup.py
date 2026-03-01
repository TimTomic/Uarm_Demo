from setuptools import find_packages
from setuptools import setup

setup(
    name='swiftpro',
    version='2.0.0',
    packages=find_packages(
        include=('swiftpro', 'swiftpro.*')),
)

from setuptools import find_packages
from setuptools import setup

setup(
    name='uarm_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('uarm_interfaces', 'uarm_interfaces.*')),
)

#!/bin/bash
your_name="chenqiao"
echo ${your_name}

for skill in ada coffe action java; do
    echo "I am good at ${skill} script"
done

myUrl="https://www.runoob.com/linux/linux-shell-variable.html"
readonly myUrl
# myUrl="xxx"

sex="female"
name="chenqiao ${sex}"
echo ${name}

string="abcd"
echo ${#string}

# string="runoob is a great site"
# echo ${string:1:4} # 输出 unoo

string="runoob is a great site"
echo `expr index "$string" rs`

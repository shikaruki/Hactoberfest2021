import streamlit as st
num1 = st.number_input("Enter the First Number")
operation = st.selectbox("Select Operation", ("Add", "Substract", "Multiply", "Divide", "Modulus", "Raised to the Power"))
num2 = st.number_input("Enter the Second Number")
output_type = st.radio("Select Output Type", ("Int", "Float"))
st.write("### Output :")
# Doing required operation regarding the selected option
if output_type == "Float":

    if operation == "Add":
        result = (num1 + num2)
        st.write(f"## {num1}+{num2} = {result}")
    elif operation == "Substract":
        result = (num1 - num2)
        st.write(f"## {num1}-{num2} = {result}")
    elif operation == "Multiply":
        result = (num1 * num2)
        st.write(f"## {num1}*{num2} = {result}")
    elif operation == "Divide":
        result = (num1 / num2)
        st.write(f"## {num1}/{num2} = {result}")
    elif operation == "Modulus":
        result = (num1 % num2)
        st.write(f"## {num1}%{num2} = {result}")
    elif operation == "Raised to the Power":
        result = (num1 ** num2)
        st.write(f"## {num1}^{num2} = {result}")
    else:
        st.write("Choose a valid operation")
if output_type == "Int":
    num1 = int(num1)
    num2 = int(num2)
    if operation == "Add":
        result = int(num1 + num2)
        st.write(f"## {num1}+{num2} = {result}")
    elif operation == "Substract":
        result = int(num1 - num2)
        st.write(f"## {num1}-{num2} = {result}")
    elif operation == "Multiply":
        result = int(num1 * num2)
        st.write(f"## {num1}*{num2} = {result}")
    elif operation == "Divide":
        result = int(num1 / num2)
        st.write(f"## {num1}/{num2} = {result}")
    elif operation == "Modulus":
        result = int(num1 % num2)
        st.write(f"## {num1}%{num2} = {result}")
    elif operation == "Raised to the Power":
        result = int(num1 ** num2)
        st.write(f"## {num1}^{num2} = {result}")
    else:
        st.write("Choose a valid operation")
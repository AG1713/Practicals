'''
6.  Implement any one of the following Expert System 
    I. Information management
    II. Hospitals and medical facilities
    III. Help desks management
    IV. Employee performance evaluation
    V. Stock market trading
    VI. Airline scheduling and cargo schedules 
'''

# Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser

import streamlit as st

knowledge_base = {
    "cold" : [
        "1: Tylenol",
        "2: Panadol",
        "3: Nasal spray",
        "4: Please wear warm clothes!"
    ],

    "influenza": [
        "1: Tamiflu"
        "2: Panadol",
        "2: Zanamivir",
        "4: Please take a warm bath and do salt gargling!"
    ],

    "typhoid": [
        "1: Chloramphenicol",
        "2: Amoxicillin",
        "3: Ciproflaxacin",
        "4: Azithromycin",
        "5: Please do complete bed rest and take soft diet!"
    ],

    "chicken pox" : [
        "1: Varicella vaccine",
        "2: Immunoglobulin",
        "3: Acetomenaphin",
        "4: Acyclovir",
        "5: Please do have have oatmeal and stay at home!"
    ],

    "measles" : [
        "1: Tylenol",
        "2: Aleve",
        "3: Advil",
        "4: Vitamin A",
        "5: Please get rest and use more liquid!"
    ],   

    "malaria" : [
        "1: Aralen",
        "2: Qualaquin",
        "3: Plaquenil",
        "4: Mefloquine",
        "5: Please do not sleep in open air and cover your full skin!"
    ]
}

symptoms_db = {
    frozenset(["rash", "body ache", "fever"]): "chicken pox",
    frozenset(["headache", "runny nose", "sneezing", "sore throat"]): "cold",
    frozenset(["headache", "abdominal pain", "poor appetite", "fever"]): "typhoid",
    frozenset(["fever", "runny nose", "rash", "conjunctivitis"]): "measles",
    frozenset(["sore throat", "fever", "headache", "chills", "body ache"]): "influenza",
    frozenset(["fever", "sweating", "headache", "nausea", "vomiting", "diahrrea"]): "malaria"
}

def respond(symptoms_input: list[str]):
    # If u are getting error somewhere here that list[str] is invalid syntax, your python is probably outdated.
    symptoms = frozenset(symptoms_input)

    if symptoms in symptoms_db:
        disease = symptoms_db[symptoms]
        st.write(f"You have {disease}!")
        st.write("Please take the following medicines and precautions-")
        for item in knowledge_base[disease]:
            st.write(item)
    else:
        st.write("This symptom combination is not in the knowledge base. Consult a physician")

if __name__ == "__main__":
    st.header("Medical Diagnosis Expert System")
    options = st.multiselect(
    'What are your symptoms?',
    ["headache", "runny nose", "sneezing", "sore throat", "fever", "chills", "body ache", "abdominal pain", "poor appetite", "rash", "conjunctivitis", "sweating", "nausea", "vomiting", "diahrrea"],
    [])

    col1, col2 = st.columns([1,0.1])
    with col1:
        ask = st.button("Ask")
    with col2:
        quit = st.button("Quit")
    if (ask):
        respond(options)
    if (quit):
        st.write("Thank you for using the Expert system!")
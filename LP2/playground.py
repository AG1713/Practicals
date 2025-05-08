import streamlit as st

st.title("Simple Chatbot")

# Initialize session state
if "messages" not in st.session_state:
    st.session_state.messages = []

# Display existing chat messages
for msg in st.session_state.messages:
    with st.chat_message(msg["role"]):
        st.write(msg["content"])

# Chat input
user_input = st.chat_input("Say something...")

if user_input:
    # Save user message
    st.session_state.messages.append({"role": "user", "content": user_input})
    with st.chat_message("user"):
        st.write(user_input)

    # Generate bot response
    response = "I didn't get that. Try again!"  # default response

    if "hello" in user_input.lower():
        response = "Hi! How can I help you?"
    elif "your name" in user_input.lower():
        response = "I'm a simple Streamlit chatbot."

    # Save and show bot response
    st.session_state.messages.append({"role": "assistant", "content": response})
    with st.chat_message("assistant"):
        st.write(response)

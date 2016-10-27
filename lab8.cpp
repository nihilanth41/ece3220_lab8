#include <iostream>
#include <string>

using namespace std;

// Input: 'Word'
// output: e.g. .... . ._.. etc
// See L14

#define NUM_LETTERS 26

string Letters = "abcdefghijklmnopqrstuvwxyz";
string mCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };


class Message { 
	protected: string msg;

	public:
		virtual void printInfo(void);
		// Constructors
		Message();
		Message(string m);
		//Destructor
		~Message();
};

Message::Message() { 
	// Empty constructor ask user for input:
	cout << "Enter a message: ";
	cin >> msg;
}

Message::Message(string m) {
	// Get user input from command line args
	msg = m;
}

void Message::printInfo(void) {
	// Print message string to stdout
	cout << msg << endl;
}

Message::~Message() {
}
	


class morseCodeMessage : public Message {
	private:
		string *translated_msg;
	public:

		void translate();
		// Override virtual:
		void printInfo();
		// Constructor
		morseCodeMessage();
		// Destructor
		~morseCodeMessage();
};

morseCodeMessage::morseCodeMessage() {
	translated_msg = new string[msg.length()];
}

morseCodeMessage::~morseCodeMessage() {
	delete[] translated_msg;
}


void morseCodeMessage::translate() {
	for(int i=0; i<msg.length(); i++)
	{
		for(int j=0; j<NUM_LETTERS; j++)
		{
			if(msg[i] == Letters[j])
			{
				translated_msg[i] = mCode[j];
				break;
			}
		}
	}
}
		

void morseCodeMessage::printInfo() {
	cout << "Original text: " << msg << endl;
	cout << "Morse code: ";
	for(int i=0; i<msg.length(); i++)
	{
		cout << translated_msg[i];
	}
	cout << endl;
}

class messageStack {
	public:
		// Fixed stack size
		// replace with LL eventually
		Message *stack[10]; 
		messageStack(Message);
		int stack_top_index;
		int num_obj;
		//~messageStack();
	private:
		void pop();         //LIFO
		void push(Message); //LIFO
		void printStack();
};

messageStack::messageStack(Message m) {
	stack_top_index = 9;
	num_obj = 0;
	push(m);
}

void messageStack::push(Message m) {
	if(num_obj == 0)
	{
		stack[stack_top_index] = m;
	}

	


int main(int argc, char **argv) {

	//Message m1 = Message();
	//m1.printInfo();
	morseCodeMessage m2 = morseCodeMessage();
	m2.translate();
	m2.printInfo();

	//if(argc > 1)
	//{
	//	Message m2 = Message(argv[1]);
	//	m2.printInfo();
	//}

	return 0;
}



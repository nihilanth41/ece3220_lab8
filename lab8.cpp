#include <iostream>
#include <string>

using namespace std;

// Input: 'Word'
// output: e.g. .... . ._.. etc

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
		int index;
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

void morseCodeMessage::printInfo() {
	cout << "Original text: " << msg << endl;
	cout << "Morse code   : " << translated_msg << endl;
}

class messageStack {
	public:
		// Fixed stack size -> replaced with LL eventually
		Message *stack[10]; 
		messageStack();
	private:
		void pop();
		void push(Message);
		void printStack();
};

int main(int argc, char **argv) {

	Message m1 = Message();
	m1.printInfo();
	if(argc > 1)
	{
		Message m2 = Message(argv[1]);
		m2.printInfo();
	}

	return 0;
}



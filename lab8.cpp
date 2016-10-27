#include <iostream>
#include <string>

using namespace std;

// Input: 'Word'
// output: e.g. .... . ._.. etc

class Message { 
	protected: string msg;
	private:
		virtual void printInfo(void);
	public:
		// Constructors
		Message();
		Message(string m);
		//Destructor
	//	~Message();
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
	cout << msg;
}
	


class morseCodeMessage : public Message {
	private:
		int index;
		string *translated_msg;
	public:
		morseCodeMessage();
		void translate();
		// Override virtual:
		void printInfo();
};

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

	//Message m1 = Message();
	if(argc > 1)
	{
		Message m2 = Message(argv[1]);
	}

	return 0;
}



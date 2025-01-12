#pragma once
#include <iostream>
#include <Queue>
#include <iomanip>
#include "clsDate.h"
using namespace std;

class clsQueueLine
{
private:
	string _Prefix = "";
	int _TotalTickets = 0;
	int _Served = 0;
	int _Waiting = 0;
	int _Time = 0;

	struct stTicket
	{
		string Date = "";
		int WaitingClients = 0;
		int ServeTime = 0;
	};

	stTicket Push()
	{
		stTicket Q1;
		Q1.Date = clsDate::GetSystemDateTimeString();
		Q1.WaitingClients = Queue1.size();
		//cout << Q1.WaitingClients << endl;
		Q1.ServeTime = Q1.WaitingClients * _Time;
		//cout << Q1.ServeTime << endl;
		return Q1;
	}
public:
	queue<stTicket> Queue1;
	clsQueueLine(string Prefix, int time)
	{
		_Prefix = Prefix;
		_Time = time;
	}

	void IssueTicket()
	{
		Queue1.push(Push());
		_TotalTickets = Queue1.size();
		_Waiting++;
		return;
	}

	void PrintInfo()
	{
		

		cout << setw(50) << right << "________________________________\n\n";
		cout << setw(37) << right << "Queue Line\n\n";
		cout << setw(50) << right << "________________________________\n\n";
		cout << setw(30) << right << "  Prefix : " << _Prefix << endl;
		cout << setw(37) << right << "  Total Tickets : " << _TotalTickets << endl;
		cout << setw(38) << right << "  Served Clients : " << _Served << endl;
		cout << setw(38) << right << "  Waiting Clients :" << _Waiting << endl << endl;
		cout << setw(50) << right << "________________________________\n\n";
	}

	void PrintTicketsLineRTL()
	{
		cout << "\n " << setw(15) << "Tickets: ";
		for (int i = 1; i <= Queue1.size(); i++)
			cout  << _Prefix << i << " <-- ";
		cout << endl;
	}

	void PrintTicketsLineLTR()
	{
		cout << "\n " << setw(15) << "Tickets: ";
		for (int i = Queue1.size(); i > 0; i--)
			cout << _Prefix << i << " --> ";
		cout << endl;
	}

	void PrintAllTickets()
	{
		queue<stTicket> Temp = Queue1;
		cout << "\n " << setw(45) << "---Tickets---\n\n";
		for (int i = 0 ; i < Queue1.size() ; i++)
		{
			cout << setw(50) << "__________________________\n\n";
			stTicket T1 = Temp.front();
			cout << setw(44) << T1.Date << endl;
			cout << setw(41) << "Waiting Clients = " << T1.WaitingClients << endl;
			cout << setw(40) << "Serve Time In\n  " << setw(25) << T1.ServeTime  << " minutes\n\n";
			cout << setw(50) << "_________________________\n\n";
			Temp.pop();
		}
	}

	void ServeNextClient()
	{
		Queue1.pop();
		queue<stTicket> Temp = Queue1;
		for (int i = 0; i < Queue1.size(); i++)
		{
			stTicket T1 = Temp.front();
			T1.ServeTime -= _Time;
			T1.WaitingClients--;
			Queue1.push(T1);
			Queue1.pop();
			Temp.pop();

		}
		_Waiting--;
		_Served++;
	}
};
/*#pragma once

#include <iostream>
#include "clsDate.h"
#include "queue"
#include "stack"

using namespace std;

class clsQueueLine
{

private:

    short _TotalTickets = 0;
    short _AverageServeTime = 0;
    string _Prefix = "";

    class clsTicket
    {
    private:

        short _Number = 0;
        string _Prefix;
        string _TicketTime;
        short _WaitingClients = 0;
        short _AverageServeTime = 0;
        short _ExpectedServeTime = 0;

    public:
        clsTicket(string Prefix,short Number  , short WaitingClients, short AverageServeTime)
        {
         
            _Number = Number;
            _TicketTime = clsDate::GetSystemDateTimeString();
            _Prefix = Prefix;
            _WaitingClients = WaitingClients;
            _AverageServeTime = AverageServeTime;
        }

        string Prefix()
        {
            return _Prefix;

        }
        short Number()
        {
            return _Number;
        }

        string FullNumber()
        {
            return _Prefix + to_string(_Number);
        }

        string TicketTime()
        {
            return _TicketTime;
        }

        short WaitingClients()
        {
            return _WaitingClients;
        }

        short ExpectedServeTime()
        {
            return _AverageServeTime * _WaitingClients;
        }

        void Print()
        {
            cout << "\n\t\t\t  _______________________\n";
            cout << "\n\t\t\t\t    " << FullNumber();
            cout << "\n\n\t\t\t    " << _TicketTime;
            cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
            cout << "\n\t\t\t      Serve Time In";
            cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
            cout << "\n\t\t\t  _______________________\n";
            

        }
    };
   
public:

    queue <clsTicket> QueueLine;

    clsQueueLine(string Prefix,short AverageServeTime)
    {
        _Prefix = Prefix;
        _TotalTickets = 0;
        _AverageServeTime = AverageServeTime;
    }

  

    void IssueTicket()
    {
        _TotalTickets++;
        clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
        QueueLine.push(Ticket);
      
    }

    int WaitingClients()
    {
        return QueueLine.size();

    }

   
    string WhoIsNext()
    {
        if (QueueLine.empty())
            return "No Clients Left.";
        else
            return QueueLine.front().FullNumber();
  
    }

    bool ServeNextClient()
    {
        if (QueueLine.empty())
            return false;


         QueueLine.pop();
       
         return true;

    }

    short ServedClients()
    {
        return _TotalTickets - WaitingClients();
    }

    void PrintInfo()
    {
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t\tQueue Info";
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t    Prefix   = " << _Prefix;
        cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets ;
        cout << "\n\t\t\t    Served Clients  = " << ServedClients();
        cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
        cout << "\n\t\t\t _________________________\n";
        cout << "\n";

    }

    void PrintTicketsLineRTL()
    {

        if (QueueLine.empty())
            cout << "\n\t\tTickets: No Tickets.";
        else
            cout << "\n\t\tTickets: ";

        //we copy the queue in order not to lose the original
        queue <clsTicket> TempQueueLine = QueueLine;

       
        while (!TempQueueLine.empty())
        {
          clsTicket Ticket=  TempQueueLine.front();
          
          cout <<" " << Ticket.FullNumber() << " <-- ";
          
          TempQueueLine.pop();
        }

        cout << "\n";

    }

    void PrintTicketsLineLTR()
    {
        if (QueueLine.empty())
            cout << "\n\t\tTickets: No Tickets.";
        else
            cout << "\n\t\tTickets: ";

        //we copy the queue in order not to lose the original
        queue <clsTicket> TempQueueLine = QueueLine;
        stack <clsTicket> TempStackLine;

        while (!TempQueueLine.empty())
        {
            TempStackLine.push(TempQueueLine.front());
            TempQueueLine.pop();
        }

        while (!TempStackLine.empty())
        {
            clsTicket Ticket = TempStackLine.top();

            cout << " " << Ticket.FullNumber() << " --> ";

            TempStackLine.pop();
        }
        cout << "\n";
    }


    void PrintAllTickets()
    {
       
        cout << "\n\n\t\t\t       ---Tickets---";

        if (QueueLine.empty())
        cout << "\n\n\t\t\t     ---No Tickets---\n";

        //we copy the queue in order not to lose the original
        queue <clsTicket> TempQueueLine= QueueLine;

       
        while (!TempQueueLine.empty())
        {
            TempQueueLine.front().Print();
            TempQueueLine.pop();
        }

    }


};

*/
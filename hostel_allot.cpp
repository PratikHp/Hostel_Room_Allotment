#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

class Room
{
    char room[5], host[10], start[5], send[5], from[10], to[10], chair[8][4][10];

public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int n);
};

// Max number of rooms
const int MAX_ROOMS = 10;
Room rooms[MAX_ROOMS];
int roomCount = 0;

void vline(char ch)
{
    for (int i = 80; i > 0; i--)
        cout << ch;
}

void Room::install()
{
    cout << "Enter room no: ";
    cin >> room;

    cout << "\nEnter Host's name: ";
    cin >> host;

    cout << "\nStart Time: ";
    cin >> start;

    cout << "\nSession Ends at: ";
    cin >> send;

    cout << "\nFrom: \t\t\t";
    cin >> from;

    cout << "\nTo: \t\t\t";
    cin >> to;

    empty();
    roomCount++;
}

void Room::allotment()
{
    int chair;

    char number[5];

top:
    cout << "Room no: ";
    cin >> number;

    int n;

    for (n = 0; n < roomCount; n++)
    {
        if (strcmp(rooms[n].room, number) == 0)
            break;
    }

    while (n < roomCount)
    {
        cout << "\nChair Number: ";
        cin >> chair;

        if (chair > 32)
        {
            cout << "\nThere are only 32 chairs available in this Room.";
        }
        else
        {
            if (strcmp(rooms[n].chair[chair / 4][(chair % 4)], "Empty") == 0)
            {
                cout << "Enter passenger's name: ";
                cin >> rooms[n].chair[chair / 4][(chair % 4)];
                break;
            }
            else
            {
                cout << "The Chair no. is already reserved.\n";
            }
        }
    }
    if (n >= roomCount)
    {
        cout << "Enter correct room no.\n";
        goto top;
    }
}

void Room::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(chair[i][j], "Empty");
        }
    }
}

void Room::show()
{
    char number[5];
    cout << "Enter room no. ";
    cin >> number;
    int n;
    for (int n = 0; n < roomCount; n++)
    {
        if (strcmp(rooms[n].room, number) == 0)
        {
            vline('*');
            cout << "Room no: \t" << rooms[n].room << "\nHost: \t" << rooms[n].host << "\t\tStart time: \t"
                 << rooms[n].start << "\t End time:" << rooms[n].send << "\nFrom: \t\t" << rooms[n].from << "\t\tTo: \t\t" << rooms[n].to << "\n";
            vline('*');
            position(n);

            int a = 0;

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    a++;

                    if (strcmp(rooms[n].chair[i][j], "Empty") != 0)
                    {
                        cout << "\nThe Chair no. " << a << " is reserved for " << rooms[n].chair[i][j] << ".";
                    }
                }
            }
            break;
        }
    }
    if (n >= roomCount)
    {
        cout << "Enter correct room no: ";
    }
}

void Room::position(int n)
{
    int s = 0;

    for (int i = 0; i < 8; i++)
    {
        cout << "\n";

        for (int j = 0; j < 4; j++)
        {
            s++;

            if (strcmp(rooms[n].chair[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << rooms[n].chair[i][j];
            }
        }
    }

    cout << "\n\nThere are " << (32 - s) << " Chairs empty in Room No. " << rooms[n].room;
}

void Room::avail()
{
    for (int n = 0; n < roomCount; n++)
    {
        vline('*');
        cout << "Room no: \t" << rooms[n].room << "\nHost: \t" << rooms[n].host
             << "\t\tStart time: \t" << rooms[n].start << "\t End Time: \t"
             << rooms[n].send << "\nFrom: \t\t" << rooms[n].from << "\t\tTo: \t\t\t"
             << rooms[n].to << "\n";
        vline('*');
        vline('_');
    }
}

int main()
{
    int w;

    while (1)
    {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t1.Install\n\t\t\t"
             << "2.Reservation\n\t\t\t"
             << "3.Show\n\t\t\t"
             << "4.Rooms Available. \n\t\t\t"
             << "5.Exit";
        cout << "\n\t\t\tEnter your choice:--> ";
        cin >> w;

        switch (w)
        {
        case 1:
            rooms[roomCount].install();
            break;

        case 2:
            rooms[roomCount].allotment();
            break;

        case 3:
            rooms[roomCount].show();
            break;

        case 4:
            rooms[roomCount].avail();
            break;

        case 5:
            exit(0);
        }
    }

    return 0;
}

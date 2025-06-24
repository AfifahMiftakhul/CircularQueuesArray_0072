/** 
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction
 * project ini merupakan project struktur data
 * menggunakan struktur data queues dg pendekatan circulaer arrays.
 * 
 * @section operarions
 * project ini memiliki beberapa operasi :
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 
 * @section Cara Penggunaan 
 * Berikut beberapa cara yang bisa digunakan : 
 * 1.en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * 
 * @author profil
 * - nama : Afifah Miftakhul
 * - nim : 20240140072
 * - kelas : B
 * 
 * @brief
 * @version 0.1
 * date 2025-06-24
 * 
 * @copyright a.miftakhul.ft24@mail.umy.ac.id (c) 2025
 * 
 */
 #include <iostream>
using namespace std;
/**
 * @class queues
 * @brief class ini untuk operasi lengkap queues
 * 
 */

class Queues
{
    private :
    static const int max = 5;   ///< ukuran max antrian
    int FRONT, REAR;            ///< front dan rear untuk menyimpan posisi depan & belakang antrian
    int queue_array[5];         ///< untuk menyimpan element antrian 

    public :
    /**
     * @brief construct a new queues object
     * set default queues null
     * with front = -1 & rear = -1
     */
    Queues()
    {
        FRONT = -1;    // front & rear masih diluar krn blm memasukkan data
        REAR = -1;
    }
    /**
     * @brief methode untuk memasukkan  data dalam antrian
     * data dimasukkan dlm variable queue_array
     */

    void  insert()
    {
        int num;                ///< variable num untuk menyimpan nilai
        cout << "Enter a number : ";
        cin >> num;
        cout << endl;

        // 1. cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max -1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overlow\n";
            return;
        }
        // 2. cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
           // jika rear berada di posisi terkahir, kembali ke awal array
           if (REAR == max -1)
               REAR = 0;
           else
           REAR = REAR +1; 
        }
        queue_array[REAR] = num;
    }

    /** 
     * @brief methode untuk menghapus data dlm antrian
     * data dihapuskan dr dlm variable queue_array
     */
    void remove()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is : " << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki 1 element
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            //jika element yg dihapus berada di akhir, maka array kembali ke awal
            if (FRONT == max -1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
    /**
     * @brief methode untuk menampilkan data dlm antrian
     * data dihapuskan dr dlm variable queue_array
     */
    void display()
    {
        int FRONT_position = FRONT;      ///< variable front_position untuk menandakan posisi element pertama pd variable front
        int REAR_position = REAR;        ///< variable rear_position untuk menandakan posisi element terakhir pd varirble rear

        // cek apakah antrean kosong
        if (FRONT == -1)
        {
            cout << "Queueu is empty \n";
            return;
        }
        cout << "\nElements is the queueu are ...\n";

        //jika front position <= rear position, iterasi dr front hingga rear
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;  
        }
        else 
        {
            // jika FRONT_position >  REAR_position, iterasi dr front hingga akhir rear
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            FRONT_position = 0;

            // iterasi dr awal array hingga rear
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};
/**
 * @brief methode utama untuk menjalankan program
 * 
 * @return int
 */

int main()
    {
        Queues q;    ///< objek untuk menggunakan member yg ada pd class queue
        char ch;      ///< variable ch untuk menyimpan pilihan pd menu yg diberikan

        while (true)
        {
            try
            {
                cout << "Menu" << endl;
                cout << "1. Implement insert operation" << endl;
                cout << "2. Implement delete operation" << endl;
                cout << "3. Display values" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter your choice :  ";
                cin >> ch;
                cout << endl;

                switch (ch)
                {
                    case '1' :
                    {
                        q.insert();
                        break;
                    }

                    case '2' :
                    {
                        q.remove();
                        break;
                    }

                    case '3' :
                    {
                        q.display();
                        break;
                    }
                    
                    case '4' :
                    {
                        return 0;
                    }
                    
                    default :
                    {
                        cout << "Invalid option !!" << endl;
                        break;
                    }
                }
            }
            catch (exception &e)
            {
                cout << "check for the vlaues entered. " << endl;
            }
        }
        return 0;
    }

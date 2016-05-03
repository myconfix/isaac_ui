#include "keythread.h"
#include "isaac.h"

keythread::keythread(QObject *parent) :
    QThread(parent)
{

}
void keythread::run()
{
    while(1)
    {
        if(last_pin_status !=1)
        {
        if(digitalRead(bt_next_pin) ==1)
        {
            emit rpikeyevent(bt_next_pin);
            last_pin_status =1;

        }else if(digitalRead(bt_back_pin) ==1)
        {
            emit rpikeyevent(bt_back_pin);
            last_pin_status =1;

         }else  if(digitalRead(bt_minus_pin) ==1)
                 {
                   emit rpikeyevent(bt_minus_pin);
            last_pin_status =1;

         }else if(digitalRead(bt_add_pin) == 1)
                  {
            emit rpikeyevent(bt_add_pin);
            last_pin_status =1;

                   }
        }else last_pin_status =0;
            this->msleep(100);
    }
}

 //�̾ջ�

#include <armor.h>

inherit HEAD;

void create()
{
         set_name("�̾ջ�",({ "lu juhua", "flower", "hua" }) );
         set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "plant");
                set("long", "����һ����˪����ϲ�����̾ջ���\n");

        }
           
        setup();
}



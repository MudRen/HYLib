inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG"�߲�"NOR, ({ "xian cai" , "cai"}) );
        set_weight(50); 
        set("no_give",1);
        set("no_put",1);        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ʵ��߲ˡ�\n");
                set("value", 1);
        }
}




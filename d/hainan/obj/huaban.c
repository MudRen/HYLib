
#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("����", ({ "hua ban" ,"flower"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��ɫ���һ����ꡣ\n");
                set("unit", "Ƭ");
                set("base_unit", "Ƭ");
                set("base_weight", 2);
                set("base_value", 1);
                set("value", 0);
              }
        set_amount(1);
        init_throwing(111);
        setup();
}

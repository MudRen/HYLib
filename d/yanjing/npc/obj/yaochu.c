#include <weapon.h>

inherit HAMMER;

void create()
{
set_name("ҩ��",({"yao chu"}));
set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit","��");
set("long","һ��������ҩ�ĵ�С��ͷ.\n");
set("value",1200);
                set("material", "iron");
set("wield_msg","$N�ͳ�һ��$n���˻�.\n");
set("unwield_msg","$�������е�$n,���˿���.\n");
        }

        init_hammer(15);
        setup();
}

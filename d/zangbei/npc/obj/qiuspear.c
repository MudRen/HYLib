#include <weapon.h>
#include <ansi.h>
inherit STAFF; 
void create()
{
        set_name(HIW"��ǹ"NOR, ({ "silver spear","spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѹ⻪��Ŀ����ǹ��ǹ���Ǵ����ģ������������֣�����ǣ���ǹ���񡣡���\n");
                set("value", 4000);
                set("strength",32);
                set("material", "steel");
                set("wield_msg", "$N��֪��ʲô�ط�����һ��$n,��ৡ���һ���������С�\n");
                set("unwield_msg", "$N�����е�$n����\n");
        }
    ::init_staff(185);
}    

// yitian-jian ���콣

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name("���潣",({ "xuanzhen jian", "xuanzhen", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("rigidity", 9);
                set("sharpness", 9); 
                set("no_get", 1);
                set("material", "steel");
                set("wield_msg", HIY"$N��ৡ���һ�����һ����潣��\n"NOR);
                set("long", "����һ���ĳ������ĹŽ���\n");                
                set("unwield_msg", HIY "��潣����һ���׹⣬��ৡ��ط��뽣�ʡ�\n" NOR);                
        }
        init_sword(200);
        setup();
}

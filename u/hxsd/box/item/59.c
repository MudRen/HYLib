//standard blade.c(�ڶ���) edit by lin on March 3,  97
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name("����", ({ "blade"}) );
        set_weight(2500);
        set("long","һ�Ѿ��ִ�͵ĵ�����Լ���߰룬��ϵ��˿�������ɼ��ˡ�\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",1500);
                set("material", "steel");
        }
        init_blade(60);
        set("wield_msg", "$N��ৡ���һ�����һ�����λε�$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        setup();
}

#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(NOR + WHT "������" NOR, ({ "heilong bian", "heilong", "bian", "whip" }) );
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ֧ͨ����ڵĳ��ޣ�����ȥ���Ǻܼ��͡�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "������ȡ��һ����ڵĳ��ޣ���ջ����Ȧ�ӡ�\n" NOR);
                set("unwield_msg", WHT "$N" WHT "һ����ߣ������к������̺ã��Ż����䡣\n" NOR);
                set("stable", 100);
        }
        init_whip(600+random(320));
        setup();
}

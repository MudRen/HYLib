#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIG"����ն"NOR, ({"hanyue blade", "blade"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѵ���ɫ��Բ���䵶��������������ɱ����\n");
                set("value", 1500);
                set("material", "ice");
                set("wield_msg",
"$N��ৡ���һ�����һ��$n�������У���������һ�����⣡\n");
                set("unwield_msg",
"$N�����е�$n�������䣬���¶��һ˿Ц�⣮\n");
        set("weapon_prop/courage", 10);

        }
        init_blade(880);
        setup();
}


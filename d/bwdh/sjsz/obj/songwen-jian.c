//Cracked by Kafei
//���ƽ�
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(YEL"���ƹŽ�"NOR, ({ "songwen jian","sword","jian" }));
	set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long","����һ�����ƹ��ӵĳ�������ɫ������������Ϊ���أ�����������һЩ���ơ�\n");
		set("value", 15000);
                set("material", "steel");
		set("wield_msg", "$N��ɫ���أ��������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������뽣�ʡ�\n");
        }
	init_sword(254);
        setup();
}

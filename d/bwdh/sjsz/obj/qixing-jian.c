//Cracked by Kafei
//���ǽ�
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIB"���ǽ�"NOR, ({ "qixing jian","sword","jian" }));
	set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "����һ�Ѻ��������ı������������б�������ͼ����\n");
		set("value", 10000);
                set("material", "steel");
		set("wield_msg", "$N����һ�����������֡�ৡ���һ���γ���$n��\n");
		set("unwield_msg", "$N�����е�$n��ὣ�ʡ�\n");
        }
	init_sword(249);
        setup();
}

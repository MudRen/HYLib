
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("���µ�", ({ "wangblade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ѩƬ����������ı���");
                set("value", 9000);
		set("rigidity", 200);
                set("material", "steel");
        }
        init_blade(190);

        set("wield_msg", "$N����Ƥ�����г��һ��ɱ�����˵�$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�����Ƥ�����С�\n");


        setup();
}


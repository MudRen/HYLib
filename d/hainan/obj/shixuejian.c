#include <ansi.h>;
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIR"��Ѫ��"NOR, ({ "shixue sword","sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��մ������������Ѫ�ı�����\n");
                set("value", 400);
                set("material", "steel");
        }
        init_sword(555);

        set("wield_msg", HIR"$N��ৡ���һ�����һ��$n��������,��ʱɱ������.\n");
        set("unwield_msg", YEL"$N�����е�$n��������Ľ���,ɱ����������ʧ�ˡ�\n");


        setup();
}


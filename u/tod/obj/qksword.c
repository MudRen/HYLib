// By Batman @ Freedom Studio 2001/6/6

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"Ǭ����"NOR, ({ "qiankun sword","sword","jian" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ����"HIC"�����塹"NOR"��"MAG"��������"NOR"��ϳɵ����������\n");
                set("value", 10000);
                set("material", "steel");
                set("wield_msg", HIW"$N��$n���������������ʱ������š�\n"NOR);
                set("unwield_msg", HIW"$N��$n�����ع��뽣�ʡ�\n"NOR);
                set("����",1);

                set("no_pawn", 1);
                set("breakup_object1", "/u/tod/obj/skysword.c");
                 set("breakup_object2", "/u/tod/obj/groundsword.c");
                set("breakup_msg", "˫���ս���ͻ���澢�������ȵ������֣�����");
        }
        init_sword(150);
        setup();
}


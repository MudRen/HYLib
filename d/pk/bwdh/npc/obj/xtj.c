// xuantiejian ������

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( HIB"������"NOR,({ "xuantie jian", "xuantie", "jian", "sword"}) );
        set_weight(35000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("rigidity", 8);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -10);
                set("treasure",1);
                set("wield_neili", 1500);
                set("wield_maxneili", 2000);
                set("wield_str", 32);
                set("wield_msg", HIB"$N�˵�һ���ӱ����������ؽ��������������ˣ���Բ֮�ں�Ȼ������������ɱ��֡�\n"NOR);
                set("long", "�˽����߳ߣ����������������������ޱȣ��޷����У�ȴɱ��ɭȻ��ʵ�����µ�һ�����\n");                
                set("unwield_msg", HIB "$N����������ؼ��ɱ���ټ���\n" NOR);               
        }
        init_sword(200);
        setup();
}


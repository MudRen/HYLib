// xuantie jian �����ؽ�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( HIB"�����ؽ�"NOR,({ "xuantie jian", "xuantie", "jian", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
                set("unique", 1);
                set("rigidity", 10);
                set("sharpness", 1);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -12);
                set("treasure",1);
                set("wield_neili", 1500);
                set("wield_maxneili", 2100);
                set("wield_str", 32);
                set("wield_msg", HIY"$N�˵�һ���ӱ����������ؽ��������������ˣ�ɱ����ã��
��Բ֮�ں�Ȼ������������ɱ��֡�\n"NOR);
                set("long", "�˽����߳ߣ����������������������������ޱȣ��޷����У�
ȴɱ��ɭȻ��ʵ�����µ�һ�����\n");                
                set("unwield_msg", BLU "$N����������ؼ��ɱ���ټ���\n" NOR);               
        }
        init_sword(620);
        setup();
}

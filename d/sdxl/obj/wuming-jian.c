// xuantie jian �����ؽ�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( "��������",({ "wuming jian", "sword", "jian"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
                set("unique", 1);
                set("rigidity", 5);
                set("sharpness", 3);
                set("material", "steel");
                set("weapon_prop/dodge", 2);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 1000);
                set("wield_str", 25);
                set("wield_msg", "ֻ������һ����$N�������һ�Ѻ���ɭɭ�ı�����\n");
                set("long", "�˽���Լ�ĳߣ�����������ǰ��������������\n");                
                set("unwield_msg","$N����������С�ĵĲ�����\n");               
        }
        init_sword(250);
        setup();
}

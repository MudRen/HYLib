#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(RED"���浶"NOR, ({ "lieyan dao", "dao", "lieyan", "blade" }) );        
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("value", 10000000);
           set("rigidity", 2);
           set("sharpness", 2);
           set("unique", 1);
           set("treasure",1);
           set("wield_neili", 100);
           set("wield_maxneili", 1000);
           set("wield_str", 22);
           set("unit", "��");
           set("long", RED"�˵��������л�����������������������桱������׭���������̵���̱��ƽʱ�������ڹ�������֮�ڡ�\n"NOR);
           }
        init_blade(200);
        setup();
}

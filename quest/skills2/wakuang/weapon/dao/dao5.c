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
           set("value", 1000);

           set("unit", "��");
           set("long", RED"�˵��������л�����������������������桱������׭���������̵���̱��ƽʱ�������ڹ�������֮�ڡ�\n"NOR);
           }
        init_blade(200);
        setup();
}

// item: /d/xingxiu/npc/obj/fire.c
// Jay 3/17/96
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"ħ������"NOR, ({"fire", "magicfire"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", RED"����һ��ħ�����棬������ǰ�ŵĺڰ���\n"NOR);
                set("unit", "��");
                set("value", 0);
                set("no_drop", 1);
                set("no_get", 1);
                set("no_put", 1);
                set("no_steal", 1);
        }
}

void init()
{
     call_out("dest", 300);   
}

 
void dest()
{
        tell_room(environment(this_object()),HIR"ħ������ʧȥ��ħ����������Ϩ���ˡ�\n"NOR);
        destruct(this_object());
}

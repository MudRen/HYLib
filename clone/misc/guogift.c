// yuebing �±�


inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(RED"����ں��"NOR, ({"hongbao", "gift"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ǹ���ڸ���ҵ�����.��\n");
                set("unit", "ֻ");
                set("no_get", 1);
                set("no_give", 1);
           
        }
}
void init()
{
add_action("do_open","open");
}
int do_open()
{object me;
me = this_player();
if(!me->query("marks/hongbao"))
{
message_vision("$N���Ų�����˫�ֻ����ش��˺����\n",me);
me -> add("combat_exp",5000);
me -> add("potential",3000);
tell_object(me,"�㱻��������ǧ��ʵս����,��ǧ��Ǳ�ܡ�\n");
me->set("marks/hongbao",1);
}
else tell_object(me,"���Ѿ��ù�һ�κ���ˣ������ã�\n");
destruct(this_object());
return 1;
}

// jiuhuawan.c �Ż���¶��
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("�Ż���¶��", ({"jiuhuayulu wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ŷ��ŵ��������СԲ�򡣲������ۡ�\n");
                set("value", 100);
		set("no_drop", 1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if ((int)this_player()->query("eff_qi") ==
            (int)this_player()->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ��ҩ�\n");
        
if (this_player()->is_busy() || this_player()->is_fighting())
        return notify_fail("����æ���ء�\n");


 if (me->query_skill_mapped("force") != "bihai-chaosheng")
        {
                me->add("max_neili", -10);
                message_vision(HIR "$N����һ�žŻ���¶�裬ֻ���õ������絶�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }

        else {
                me->receive_curing("qi", 500);
                message_vision("$N����һ�žŻ���¶�裬���ƴ�Ϊ��ת��\n", this_player());
        
        }
        destruct(this_object());
                return 1;
}


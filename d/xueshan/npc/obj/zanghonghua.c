//  zanghonghua

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "fu");
}

void create()
{
        set_name(HIR"�غ컨"NOR, ({"zang honghua","zanghonghua","hua"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
set("treasure",1);
                set("unit", "��");
                set("long", "����һ�����������ظ�ԭ�ϼ��亱���Ĳغ컨��\n"
                           "��˵�غ컨����һ�������仨������������Ч������\n");
                set("value", 1000);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

      if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ء�\n");

        if ((int)me->query("eff_qi") ==
            (int)me->query("max_qi"))
                return notify_fail("�����ھ���������Ѫ��ӯ������Ҫ��ҩ�\n");

        if(me->query_condition("medicine") > 0){
             message_vision(HIR "$N���²غ컨��ֻ��������ת��ԭ����ҩ��Ƶ�����Ʒ������ء�\n" NOR, me);
             me->set("eff_qi", 1);
             me->add("max_neili",-(10+random(5)));
             me->start_busy(2);
             me->unconcious();
             destruct(this_object());
             return 1;
        }
        if (random(10) > 2) {
         me->add("max_neili",2+random(4));
         me->apply_condition("medicine", me->query_condition("medicine")+55);
        }
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("max_qi"));
        message_vision(HIW"$N���²غ컨��ֻ������������������ˬ���������ƴ�Ϊ��ת��\n"+
                          "�����ƺ�Ҳ����ǰǿ����ࡣ\n"NOR, this_player());       
        me->apply_condition("medicine", me->query_condition("medicine") +10);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}


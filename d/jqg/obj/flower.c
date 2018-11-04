// flower.c �黨
// By River 99/05/20
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
       set_name(HIM"�黨" NOR, ({"qing hua", "flower", "hua"}));
       set_weight(700);
       if( clonep() )
               set_default_object(__FILE__);
       else {
             set("long", "����һ�伫Ϊ���޵��黨��\n"+
                         "�������ɫ�����ޱȣ���ܽ�ض����㣬��ɽ������ޡ�\n");
             set("unit", "��");
             set("no_drop", 1);
             set("no_get", 1);
             set("no_give",1);    
             set("material", "plant");
             set("wear_msg", "$N��$n���ڷ����ϡ�\n");
             set("remove_msg", "$N�ӷ�����ժ����$n��\n");
             set("armor_prop/armor", 1);
	     }
             setup();
}

void init()
{
     add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
        if(!id(arg))
             return notify_fail("��Ҫ��ʲô��\n");
        message_vision(HIY"$N��"HIM"�黨"HIY"һ����ժ��������У�������𣬷������ۣ���΢������Ȼ�ľ�����\n"NOR,me);
        if(me->query_condition("medicine")){
          me->add("max_neili", -5);
          write(HIY"����������㳩�������˼��£�ȴ��һ�ɿ�ɬ��ζ��ֱ����ͷ��\n"NOR);
          me->unconcious();
          return 1;
          }
        message_vision(HIY"���Ըп�ζ��Ҫ���³����ƾ����ᣬҪ������ڣ����е��������ʡ�\n"NOR,me);
        if ( !me->query("marry"))
          me->set("food",me->max_food_capacity());
        else {
          me->add("max_neili",random(2)+1);
          me->apply_condition("medicine", 25);
          }
        destruct(this_object());
	return 1;
}

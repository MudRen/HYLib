// yuan.c ԧ��
// zly 99.6.22

#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
               set_name(HIC"ԧ��"NOR, ({"yuan dao","yung","dao","blade"}));
               set_weight(4000);
               if( clonep() )
               set_default_object(__FILE__);
        else{
               set("treasure", 1);
               set("unit", "��");
               set("long", HIC"����ԧ�쵶�е�ԧ������������ҫ�ۣ������Ͽ��������ߡ����֡�\n" NOR);
               set("value",400000);
               set("material","steel");
               set("weapon_prop/parry",5);
               set("unique", 1);
               set("rigidity", 3);
               set("sharpness", 1);
               set("wield_neili", 100);
               set("wield_maxneili", 700);
               set("wield_str", 20);
               set("wield_msg", HIY "$N���һ�������ҫ���������˵Ķ̵��������С���ʱ������������һ��
��Ȼ����,���֮������η�塣 \n" NOR);
	       set("unwield_msg", HIY "$N���Ὣ���е�ԧ����������ĵ��ʡ�\n" NOR);
};

          init_blade(380);
        setup();
}


void init()
{
      add_action("do_add",({"he", "��"}));
}

int do_add()
{
     object me,ob, obj;

     me = this_player();
     ob = this_object();
     obj = present("yang dao", me);
     if(!objectp(obj))
           return notify_fail("������ֻ��һ��ԧ�������ҵ���һ����˵�ɡ�\n");
     if((int)me->query("neili") < 1000)
           return notify_fail("��о�ȫ����Ѫ���ڣ�ͷ��Ŀѣ��ԭ���������������޷���˫���ϲ���\n");
     if((int)me->query_str() < 28)
           return notify_fail("��о�ʹ����ȫ������������޷���˫���ϲ���\n");
     me->add("neili", -300);
     message_vision(HIC"\nֻ��һ�����죬��˫�ְѵ�һ�������һ���϶�Ϊһ������$N�����\n"NOR, me);
     destruct(obj);   
     new(__DIR__"yyd")->move(me, 1);     
     destruct(ob);
     return 1;
}


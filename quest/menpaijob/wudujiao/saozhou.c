//yaochu.c ҩ��
//����II���������䣩
//����lywin 2000/6/15

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_wayao", "zuoduwu");
}

void create()
{
	set_name("�嶾ץ", ({"wudu zhua", "wuduzhua"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_put",1);
		set("long", "����һ���嶾ץ�������������׽���zuoduwu����\n");
		set("value", 0);
	}
	setup();
}

int do_wayao()
{
int maxpot;
        object obj;
        object me=this_player();


//&& !environment(me)->query("no_fight")

        if (me->is_busy())
        {
          tell_object(me,"����æ���ˣ���׽�ɣ���\n");
          return 1;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"�ȴ����ˣ���׽�ɣ���\n");
          return 1;
        }
       else
        if ((me->query("neili") < 100 ))
        {
          tell_object(me,"�������״̬̫�����������\n");
          return 1;
        }

        if ((me->query("jing") < 100))
        {  
          tell_object(me,"��ľ������ܼ��У�������׽���\n");
          return 1;
        }
        else
        if ((me->query("qi") < 100 ))
        {
          tell_object(me,"�������״̬̫�����׽���\n");
          return 1;
        }
        else
	if (environment(me)->query("short") !=me->query_temp("wudujiaojob"))
        {
          tell_object(me,"���ǽ��㵽������׽����İɣ�\n");
          return 1;
        }
        else
	if (!me->query_temp("wudujiao"))
        {
          tell_object(me,"û����׽����ɣ�\n");
          return 1;
        }
        else
	if (environment(me)->query("short") ==me->query_temp("wudujiaojob"))
        {
        message_vision(HIC"$N���嶾ץ��ʼ�ڵ���׽�𶾳�����\n"NOR,me);
        if (random(30)>28 && !environment(me)->query("no_fight")
        && me->query("combat_exp") >800000 )
        {
          tell_object(me,"��Ȼ����������һ��������ʿ������㲻����\n");
                obj=new(__DIR__"mengbing"); 
	        obj->do_copy(me,maxpot,1);
	        obj->set("title",HIW"��������"NOR);
	        obj->move(environment(me));
                obj->set("dex",100);
                obj->kill_ob(me);
                me->start_busy(2);
          return 1;
        }

        me->add("jing",-me->query("max_jing")/20);
        me->add("qi",-me->query("max_qi")/20);
        me->add("eff_jing",-me->query("max_jing")/20);
        me->add("eff_qi",-me->query("max_qi")/20);
        me->add("neili",-me->query("neili")/20);
        me->start_busy(10);   
        me->apply_condition("wdj_busy",4);
       call_out("destroying", 0, me);                       
      	}
}

void destroying(object me)
{   
        message_vision(HIG"���浹��׽�ò���ˣ���ϧ�嶾ץȴ���ˡ�\n"NOR,me); 
        me->set_temp("wudujiaook",1);
        destruct(this_object());
}
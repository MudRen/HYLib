// wudi.c 
// by emnil   98.8.12

#include <ansi.h>

inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
void remove_effect2(object me, int amount);

int exert(object me, object target)
{
	int skill,qi;
	string s;

	/*if( target != me )
		return notify_fail("��ֻ���������ķ��������Լ���ս������\n");*/

        if(  !me->is_fighting() )
                return notify_fail("ֻ���ڴ��в���ʹ��!\n");
                
	if( (int)me->query_skill("shenlong-xinfa",1) < 100  )
		return notify_fail("��������ķ������������޷�ʩ�á��޵С��󷨡�\n");

	if( (int)me->query("neili") < 600  ) return notify_fail("�������������\n");
	if( me->is_busy()  ) return notify_fail("����æ���ء�\n");
	if( (int)me->query("eff_qi")<me->query("max_qi")/2) 
	{
		if((int)me->query_temp("sld/wudi")==0)
			return notify_fail("���������˹��أ�����ʹ�á��޵С��󷨡�\n");
	}

	skill = me->query_skill("force");
	switch((int)me->query_temp("sld/wudi")) {
		case 2:return notify_fail("���Ѿ�������������Ǳ����\n");
		case 0: 	if( (int)me->query("neili") < 600  ) return notify_fail("�������������\n");
			me->add("neili", -400);
			me->set_temp("wdneili",0);
			s=HIR"$N�����е������������ͨ����ҽ�ս�޲�ʤ�����޲��ˣ��޼᲻�ݣ��޵в��ƣ�\n�����������ң���֮زز������˫��ͻȻð��һ˿��⣬�ƺ�ͻȻ�����˹�����\n"NOR;
			me->set_temp("sld/wudi", 1);

			qi=me->query("max_qi");
			me->add("max_qi",qi/4);
			me->add("eff_qi",qi/4);
			me->add("qi",qi/4);
			if (skill > 500) skill=500;
			me->add_temp("apply/attack", skill/3);
			me->add_temp("apply/defense", skill/4);
			me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), 40);
			
			break;
		case 1:	if( (int)me->query("max_neili") < 1000  ) return notify_fail("�������������\n");
			me->add("max_neili",-5);
			s=
RED"$N�����Ľе������������ͨ���ӣ��ڵ��������ٱ�����һ���٣��԰ٵ���
�������Ŀ��磬�����ķ����ҵ���ɱ�л��̣�������׼���Σ�����ʥְ��
�ҽ̵��ӻ��̶�����ͬ�����ã�����ͻȻ���һ����Ѫ���ƺ��Ѿ���������ʹ��\n"NOR;
			me->set_temp("sld/wudi", 2);			
			me->delete_temp("wdneili");
			me->set("eff_qi",me->query("max_qi"));
			me->set("qi",me->query("eff_qi"));
			me->set("jing",me->query("eff_jing"));
			me->set("neili",me->query("max_neili"));
			if (skill > 500) skill=500;
			me->start_call_out( (: call_other, __FILE__, "remove_effect2", me, skill:), 90);
			
			break;
//		defeat: break;
	}

	
	message_vision(s, me);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount )
{

	if(!objectp(me)) return;
	if ((int)me->query_temp("sld/wudi")>1) return;
	if(me->is_ghost())
	{
		me->delete_temp("sld/wudi");
		me->delete_temp("sld/shougong");
		me->delete_temp("wdneili");
		me->add_temp("apply/attack", -amount/3);	
		me->add_temp("apply/defense", -amount/4);	
		me->add("max_qi",-me->query("max_qi")/4);
		return;
	}
	if ( (int)me->query_temp("sld/wudi")>0 ) {
		if( ((me->query("neili")-me->query_temp("wdneili",1))<100) || (me->query_temp("sld/shougong")>0) )	{
			message_vision(HIR"$N����������һ����ͻȻ����������\n"NOR,me);		
			
			me->add("neili",-me->query_temp("wdneili",1));
			if(me->query("neili")<0)
				me->set("neili",0);
			me->add_temp("apply/attack", -amount/3);	
			me->add_temp("apply/defense", -amount/4);	
			me->add("max_qi",-me->query("max_qi")/4);
			if(me->query("eff_qi")>me->query("max_qi")) 
				me->set("eff_qi",me->query("max_qi"));
			if(me->query("qi")>me->query("eff_qi")) 
				me->set("qi",me->query("eff_qi"));

			me->delete_temp("sld/wudi");
			me->delete_temp("sld/shougong");
			me->delete_temp("wdneili");
		}
		else {
			message_vision(HIR"$N�����е������������ͨ����ҽ�ս�޲�ʤ�����޲��ˣ��޼᲻�ݣ��޵в��ƣ�\n�����������ң���֮زز������˫��ͻȻð��һ˿��⣡\n"NOR,me);

			me->add_temp("wdneili",100);
			me->add("eff_qi",50);
			if(me->query("eff_qi")>me->query("max_qi")) 
				me->set("eff_qi",me->query("max_qi"));
			call_out("remove_effect",30,me,amount);
		}
	}
}

void remove_effect2(object me, int amount)
{
	if(!objectp(me)) return;
	if(me->is_ghost())
	{
		me->delete_temp("sld/wudi");
		me->add_temp("apply/attack", -amount/3);	
		me->add_temp("apply/defense", -amount/4);	
		me->add("max_qi",-me->query("max_qi")/4);
		return;
	}
	message_vision(RED"$N����һ�ɣ���Ҳ֧�ֲ�����\n"NOR,me);		
	
	me->add_temp("apply/attack", - amount/3);
	me->add_temp("apply/defense",- amount/4);		
	me->add("max_qi",-me->query("max_qi")/4);
	if(me->query("eff_qi")>me->query("max_qi")) 
		me->set("eff_qi",me->query("max_qi"));
	if(me->query("qi")>me->query("eff_qi")) 
		me->set("qi",me->query("eff_qi"));
	me->delete_temp("sld/wudi");

//	me->unconcious();
}
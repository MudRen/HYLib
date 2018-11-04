//Cracked by Kafei

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object weapon, int damage);

int perform(object me, object target)
{
        object weapon,cloth;
        int damage, skill;

        weapon = me->query_temp("weapon");
//	cloth = me->query_temp("armor/cloth");
	
        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("��ɽ�����߶��ھ��ķ������ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽�������˾�춽���\n");

        if( me->query_temp("songshan_attack") )
                return notify_fail("��Ľ������ڻ������\n");
        
        if( me->query_temp("songshan_wait") )
                return notify_fail("��ղų������Ѵ����Ԫ�������޷��������\n");

        if( me->query_skill("songshan-jian",1) < 100 )
                return notify_fail("�����ɽ������Ϊ���㣬�߶��ھ������ô���\n");

        if( me->query_skill("force", 1) < 100 )
                return notify_fail("����ڹ���Ϊ���㣬�߶��ھ������ô���\n");

        if( me->query("max_neili") <= 1000 )
                return notify_fail("��������������\n");

        if( me->query("neili") <= 800 )
                return notify_fail("����������㣡\n");

        if( me->query("jing") <= 200 )
                return notify_fail("��ľ������㣡\n");
        if( !me->query("jiali")  )
                return notify_fail("�����������ã�\n");

        skill = me->query_skill("songshan-jian",1);

        damage = me->query_skill("songshan-jian")/4;

	me->add("neili", -300);
	me->add("jing", -100);

	
//	me->add_temp("apply/speed", -damage);

        message_vision(YEL"$N��������"+weapon->name()+YEL"�������׼��$n�ؿڡ�\n"NOR, me,target);
//	if (cloth->query("material") == "cloth")
        message_vision(HIY"����$N��������������������ƳԱ��˷�ķ���һ�㣬��������ƽ������Ѱ�����죬���$Pȫ���������е��ұ�֮�ϣ������ĵ��������䶼�����ѣ�ֱ�Ƿ�ͬС�ɡ�\n"NOR, me,target);

        me->set_temp("songshan_attack", 1); 
        me->add_temp("songshan_xuli", 1); 
	me->start_busy(1);
	call_out("checking", 1, me, target, weapon,skill,damage);
        return 1;
}

void checking(object me, object target, object weapon, int skill, int damage)
{
//        object weapon,cloth;

//	object cloth = me->query_temp("armor/cloth");

	int xuli,jiali;
        if (!me) return;
        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽�������˾�춽���\n");

        if( !me->query("jiali")  )
                return notify_fail("�����������ã�\n");

	jiali = me->query("jiali");
	
	if( !living(me) || me->is_ghost() )
	{
		remove_effect(me, weapon, damage);
		return ;
	}

	me->add_temp("songshan_xuli", skill); 
//	me->add("neili",-skill/2);
	me->start_busy(2);
	xuli = me->query_temp("songshan_xuli");

                if( wizardp(me) )
                        tell_object(me,"��ɽ����������"+xuli+"����Ҫ"+skill*4+"��\n");

	if( !me->is_fighting() )
	{
		message_vision("\n$N�����������ֱۣ��������"+weapon->name()+"�ϵ�����ɢȥ��\n", me);
		remove_effect(me, weapon, damage);
		return ;
	}

	else if( environment(weapon) != me || weapon != me->query_temp("weapon") )
	{
		remove_effect(me, weapon, damage);
		return ;
        }
	else if( me->query_skill_mapped("sword") != "songshan-jian" )
	{
		remove_effect(me, weapon, damage);
		return ;
	}
	else if(  (int)me->query("neili") < skill ||(int)me->query("jing") < skill )
	{
//	if (cloth->query("material") == "cloth")
        message_vision("$N��������һ�ɣ��������䴹��������\n", me,target);
		return ;
	}

	else if(xuli > skill*4){
		
	//���ɣ�����
	me->set_temp("s_hit",1);
	me->add_temp("apply/attack", skill);
	me->add_temp("apply/damage", skill);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add_temp("apply/attack", -skill);
	me->add_temp("apply/damage", -skill);
	me->delete_temp("s_hit");

	me->set_temp("songshan_wait", 1); 
	call_out("checking2", skill/30 , me, weapon,damage);
		
	remove_effect(me, weapon, damage);

	return ;
	}
		else call_out("checking", 1, me, target, weapon, skill, damage);
		return;
}
void checking2(object me, object weapon, int damage)
{
	tell_object(me,"����õ����е���Ϣ�������������ˡ�\n");
	me->delete_temp("songshan_wait"); 
}

void remove_effect(object me, object weapon, int damage) 
{
        if (!me) return;
//        me->add_temp("apply/speed", damage);
	me->delete_temp("songshan_xuli");
	me->delete_temp("songshan_attack");

}

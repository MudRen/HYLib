//by sdong 07/98

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int skill, skill1, skill2;
        string msg;
        object victim,ob;
        object weapon,weapon2;
    object *inv;
    int i, count;
     int damage,jiali,jiajin;
     string bei_skill;
	jiali = (int)me->query("jiali");
	jiajin= (int)me->query("jiali");

        if( !victim ) victim = offensive_target(me);

       if( !target ) target = offensive_target(me);
        if( !victim || !victim->is_character() || !me->is_fighting(victim) )
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if(     me->query_skill("yunv-jian",1) < 1 ||
                me->query_skill("quanzhen-jian",1) < 1 
                )
                return notify_fail("����ͨ����������Ů������ȫ�潣����\n");

        if(me->query_skill("quanzhen-jian",1) <120)
                return notify_fail("���ȫ�潣����������������˫��������һ�����\n");

        if(me->query_skill("yunv-jian",1) <180)
                return notify_fail("�����Ů������������������˫��������һ�����\n");

        if( !objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword" )
                return notify_fail("������н���\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("meinv-quan", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("yunv-jian", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("yunv-xinfa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "yunv-xinfa")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ��Ĺ����ѧ��ʹ���˹�Ĺ�ɵľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
if (random(3)==0) target->start_busy(3);

        skill =  ( me->query_skill("yunv-jian",1) + me->query_skill("yunv-jian",1)
                + me->query_skill("meinv-quan",1) +me->query_skill("yunv-xinfa",1) 
                + me->query_skill("yunv-xinfa")) / 10; 
        message_vision(
        HIR "$NͻȻ�����ֳ����һ�ѽ���˫��ʹ����Ȼ��ͬ�Ľ������������һ���������\n"+HIC"ֻ��$N˫��һ������������Ů������ȫ�潣����ϵ������޷죬����֮����Ȼ������\n\n" NOR, me);

        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/damage", skill/2);
        me->add_temp("apply/dodge",  skill/2);
        me->add_temp("apply/parry",  skill/2);

        bei_skill = me->query_skill_mapped("sword");
    me->map_skill("sword", "yunv-jian");
        message_vision(HIG"�˼����ģ�\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIY"��ǰ���£�\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "yunv-jian");
        me->setup();
        message_vision(HIG"���ٰ�����\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");

        message_vision(
        HIR "$N������������,���ǻ����Ӧ������ɱ��ȴ�ǲ������\n" NOR, me);

        me->setup();
        message_vision(HIY"С԰�վգ�\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "yunv-jian");
        me->setup();
        message_vision(HIG"����ҹ����\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIY"���¶��ģ�\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIG"����С����\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));

    me->map_skill("sword", bei_skill);
        me->setup();

        me->start_busy(3);

	msg = HIB "\n\n$N�����߶�������ȭ���ݺ����飡\n"NOR;
        msg += HIY "\n$N����֧�ã���������ӳ�����̾һ�������ּ���֮�⣬������ʹ��ɱ�С�\n\n"NOR;
  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/3 ) || !living(target) )
  {
			damage = random(  me->query_skill("meinv-quan",1) + me->query_skill("yunv-xinfa",1) + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
			if(damage > 6000) damage = 6000;
			if(damage < 600) damage = 600;

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", damage, me);
			target->start_busy(0);

		if ( damage < 1000) {
			msg += HIR"ֻ�����һ����$n��һȭ����С������Ѫ��ӿ��ڶ�����\n"NOR;
		}else if ( damage < 2000) {
			msg += HIR"ֻ���顢��������$n���۷��ࡢ���۷��ϣ���Ѫֱ����\n"NOR;
		}else if ( damage < 3000) {
			msg += HIR"ֻ���顢�顢�������죬$n���ϱ��˼�����������Ѫ���硣\n"NOR;
		}else {
			msg += HIR"ֻ���顢�顢�顢�鼸�����죬$n����ù������ѷ��˳�ȥ��\n"NOR;
		}
		msg += NOR;
  }
  else {
	 msg += HIG"$n���һ�֣�����Ծ�𣬱��ܵķ�Ӧ��$n�ӹ��˽١�\n\n"NOR;
	 message_vision(msg+"\n", me, target);
	 return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);

	msg = HIB "\n$N����������Ҫ����������֧�ã�����������$n�ӳ�����̾һ�������ּ���֮�⡣\n\n"NOR;

	msg += HIY"���ǡ���Ůȭ�������һ�е���ʽ����������Ĺ�ľӡ���ȴ��������Դ����ֳ�Ӣ��Ȼ\n";
	msg += HIY"��֪��������С��ŮҲ�ǲ��ᡣ�����������ѧȫ����Ůȭ��֮��������ʦ��������\n";
	msg += HIY"���в����ڹŴ���Ů���书֮�߸�����˵����·ȭ����������ʦ�����ڣ��㲻��������\n";
	msg += HIY"������������������һ�У���˵Ϊ��д�ֳ�Ӣ��������ֹ��̬ȴ��ģ����ʦ��С��Ů��\n\n";

  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/3 ) || !living(target) )
  {
	damage = random(  me->query_skill("force",1) + me->query_skill("cuff",1) + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
	if(damage > 5000) damage = 5000;
	if(damage < 800) damage = 800;

	target->receive_damage("qi", damage,  me);
	target->receive_wound("qi", damage, me);
	target->start_busy(0);

	if ( damage < 800) {
		msg += HIR"ֻ���۵�һ����$n��һȭ����С������Ѫ��ӿ��ڶ�����\n"NOR;
	}else if ( damage < 1400) {
		msg += HIR"ֻ���顢��������$n���۷��ࡢ���۷��ϣ��Ǳ�������\n"NOR;
	}else if ( damage < 2000) {
		msg += HIR"������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
	}else {
		msg += RED"ֻ���顢�顢�顢�鼸�����죬$n����ù������ѷ��˳�ȥ��\n"NOR;
	}
	msg += NOR;
	}
	else {
	msg += HIG"$n���һ�֣�����Ծ�𣬱��ܵķ�Ӧ�ٿ���$N�����䡣\n\n"NOR;
	message_vision(msg+"\n", me, target);
	return 1;
  }

	message_vision(msg+"\n", me, target);
	COMBAT_D->report_status(target);

        return 1;
}


// holyword������

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
        int damagic;

	if((int)me->query("neili")< 1100)
	return notify_fail("�������̫���ˣ�\n");

        msg = HIW "$N��ǣ������$n" HIW "��������������ת�˺ü���Ȧ��\n" NOR;

        if ( userp(target) || random(me->query("combat_exp"))>(int)target->query("combat_exp"))
        {

       msg += HIC"���$n��$N�Ĺ�����,��֪���룡 \n"NOR;
                if (!target->is_busy())
                target->start_busy(6);
                target->set("neili",10);
		message_combatd(msg, me, target);
        } else
        {
        msg += HIC"$n"HIC"˫Ŀһ����ʶ������Ķ�����!\n"NOR;
		message_combatd(msg, me, target);
        }
me->add("neili",-150);

	return 1;
	
}
int perform(object me, object target)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;
	if( !target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIY"����������ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

//      if( !me->query("zhuanbest",1))
//        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( me->query_condition("tianrenheyi"))
        return notify_fail("����������㣡\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( me->query("zhuanfinal/4") !=1 )
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

    if( me->query("gender") == "����")
               {msg = YEL
"$N������������̬Ʈ��,һ�������貨,��������֮����\n" NOR;}
        else   {msg = YEL 
"$N����������ʩչ�貨΢��������������������Ů�·���\n" NOR;}

       msg += HIG"$N"HIG"�溬΢Ц������һ���ѽ��������н�������ȫ��������\n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
        me->apply_condition("tianrenheyi",3);
	me->start_busy(3);
	return 1;
}



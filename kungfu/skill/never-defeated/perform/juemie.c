// juemi.c ��ؾ���
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
	string msg;
	int ap, dp;
        int damage;

        if (! target)
        {
        	me->clean_up_enemy();
        	target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("��ؾ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (me->query_skill("never-defeated", 1) < 120)
		return notify_fail("��Ĳ����񹦻�������죬����ʹ����ؾ���\n");

        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("������ֱֳ��в���ʩչ��ؾ���\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʹ����ؾ���\n");
 
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "������˼�������Ȼһ�����е�" + weapon->name() +
              HIC "��Ѹ���ޱȵ�ɨ��$n" HIC "���仯����֮��������˼�飡\n" NOR;
 
	ap = me->query_skill("never-defeated", 1) * 3 / 2 + me->query("int") * 20 +
             me->query_skill("never-defeated", 1);
	dp = target->query_skill("dodge") + target->query("dex") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "ֻ��$n" HIG "�������ţ�ֻ������һ�����Ͷ����$N"
	               HIG "��һ����\n"NOR;
        } else
	{
		me->add("neili",-70);
                damage = ap + random(ap / 3);
if (me->query("zhuanfinal/1") ==1 && random(2)==0)
{
	if (userp(target))
	target->receive_wound("qi", target->query("qi")/8);
        if (!userp(target))
         target->receive_wound("qi", 500);
	msg +=RED"$Nʹ����ն�ɾ�!!$nͻȻ�ؿ�һʹ��Ѫ��!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(2)==0)
{
	if (userp(target))
	target->add("neili", -target->query("neili")/8);
        if (!userp(target))
         target->add("neili", -500);
	msg +=HIY"$Nʹ�������ɾ�!!$nͻȻ������ʧ!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(2)==0)
{
	if (!target->is_busy())
	target->start_busy(4);
	msg +=HIY"$Nʹ�������ɾ�!!$nͻȻ��æ����!\n"NOR;
}
                
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "��æ�񵲣�������һ��ʵ���ǹ���Ī"
                                           "�⣬������ĥ��͸����ʱ����$P" HIR "���ش���\n" NOR;
	}

	message_vision(msg, me, target);
	return 1;
}

// zhu.c ���ɾ�
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
int perform(object me, object target)
{
	string msg;
	int ap, dp;
        int damage;

        if (! target)
        {
        	me->clean_up_enemy();
        	target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("���ɾ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (me->query_skill("yinyang-shiertian", 1) < 120)
		return notify_fail("�������ʮ�����컹������죬����ʹ�����ɾ���\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʹ�����ɾ���\n");
 
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

    if( objectp(me->query_temp("weapon")) )
   return notify_fail("��������ʹ�ã�\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");


	msg = HIC "$N" HIC "�����ĳ�һ�ƣ������������һ�����$n"
              HIC "�ٶȿ�Ĳ���˼�飡\n" NOR;
 
	ap = me->query_skill("yinyang-shiertian", 1) * 3 / 2 + me->query("con") * 20 +
             me->query_skill("unarmed", 1);
	dp = target->query_skill("parry") + target->query("int") * 20 +
             target->query_skill("unarmed", 1);

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "Ȼ��$n" HIG "������$N" HIG
                       "�����ƣ����Ų�æ�Ķ������һ����\n" NOR;
        } else
	{
		me->add("neili",-75);
                damage = ap  + random(ap / 2);
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
                msg +=HIR "$n" HIR "����˼����һ�Ƶĺ��ƣ���������"
                                           "��ǰ��ֻ�����ۡ���һ����$n��Ѫ���ߣ�\n" NOR;
	}

	message_vision(msg, me, target);
	return 1;
}

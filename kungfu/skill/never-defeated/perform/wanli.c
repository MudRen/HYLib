// wanli.c �������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object  weapon;
	int     damage;
	string  msg;
        string  pmsg;
        string *limbs;
        string  limb;
        int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("never-defeated", 1) < 120)
		return notify_fail("��Ĳ����񹦻�������죬����ʹ��������\n");
	                        
        if ((int)me->query("neili", 1) < 200)
		return notify_fail("����������̫��������ʹ��������\n");
			
        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("������ֱֳ��в���ʩչ������\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");


       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "����" + weapon->name() + HIC "��һ"
              "ȦȦ�Ļ���$n" HIC "����$p" HIC "���ڵ��У�\n" NOR;
	me->add("neili", -20);

        ap = me->query_skill("never-defeated", 1) * 3 / 2 +
             me->query_skill("unarmed", 1);
        dp = target->query_skill("parry") +
             target->query_skill("unarmed", 1);

        if (ap / 2 + random(ap * 2) > dp)
        {
		me->start_busy(2);
                me->add("neili", -180);

		target->start_busy(3);

		damage = ap + (int)me->query_skill("force");
                damage = damage + random(damage / 2);

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
                if (arrayp(limbs = target->query("limbs")))
                        limb = limbs[random(sizeof(limbs))];
                else
                        limb = "Ҫ��";
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n��æ��Ų������Ȼ�������ꡱһ����" + weapon->name() +
		       HIR "���û���$p" HIR "��" + limb + "��$p"
		       HIR "һ���ҽУ�����������\n" NOR;
	} else 
	{
		me->start_busy(2);
		msg += CYN "����$p" CYN "������$P"
                       CYN "�ı仯�����в��У�û���ܵ��κ��˺���\n"NOR;
	}

	message_vision(msg, me, target);

	return 1;
}

// mie.c ��������

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	string msg;
        int ap, dp;
 
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
	        return notify_fail("��������ֻ����ս���жԶ���ʹ�á�\n");

	if (me->query_skill("yinyang-shiertian", 1) < 150)
		return notify_fail("�������ʮ�����컹������죬����ʹ����������\n");

	if (me->query("neili") < 300)
		return notify_fail("�������������\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

    if( objectp(me->query_temp("weapon")) )
   return notify_fail("��������ʹ�ã�\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

        msg = HIC "$N" HIC "����һ��������Ϊצ��Ѹ���ޱȵ�Ϯ��$n��\n";

        ap = me->query_skill("yinyang-shiertian");
        dp = target->query("combat_exp") / 10000;
	me->add("neili", -60);
	me->start_busy(4);

	me->want_kill(target);
        if (dp >= 100)
        {
                msg += HIC "$n" HIC "֪�����в��ƣ�С��Ӧ�ԣ�û��һ����\n" NOR;
        } else
        if (random(ap) > dp)
        {
                msg += HIR "��һ����ȫ������$n" HIR "�����󣬱�$N"
                       HIR "���ʵʵ��ץ��������Ѩ������������ʱ��ɢ��\n" NOR;
                message_vision(msg, me, target);
                                if (target->query("qi") > 35000)
{
target->add("qi",-30000);
target->add("eff_qi",-30000);
}else target->unconcious();
                return 1;
        } else
        {
if (me->query("zhuanfinal/4") ==1 && random(2)==0)
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);
                if (me->query("qi") < me->query("max_qi") )

	msg += HIY"$Nʹ�������ɾ�!!$Nȫ����˺��˺ܶ�!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(2)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!target->is_busy() )
target->start_busy(2);
	msg += HIY"$Nʹ���˶��ɾ�!!$NͻȻ�����ֿ���!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(2)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	msg += HIY"$Nʹ�������ɾ�!!$NͻȻ�����ָ���!\n"NOR;
}
                msg += HIM "$n" HIM "���һ������æ���ҵֵ�����"
                      "Ȼû��һ���˺������ҵ��ѣ�\n" NOR;
        }

        message_vision(msg, me, target);

	return 1;
}

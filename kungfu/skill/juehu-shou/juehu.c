#include <ansi.h>
#include <combat.h>

#define JUEHU "��" HIR "������ץ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        
        object weapon;
        int ap, dp;
        string wn, msg;
	int extra;
	int i,a;
        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(JUEHU "ֻ����ս���жԶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" JUEHU "��\n");
        if( (int)me->query_skill("taiji-shengong", 1) < 180 )
                return notify_fail("��ı����ڹ�����̫ǳ�ˡ�\n");
        if (userp(me) && me->query("shen") < 10000)
                return notify_fail(HIC "\n��������������ʩչ���У���ͻȻ�뵽����������"
                                   "��һ����룬���ò���;�����˹�����\n" NOR);

        if ((int)me->query_skill("juehu-shou", 1) < 120)
                return notify_fail("��Ļ�צ�����ֲ�����죬����ʩչ" JUEHU "��\n");

        if (me->query_skill_mapped("claw") != "juehu-shou")
                return notify_fail("��û�м�����צ�����֣�����ʩչ" JUEHU "��\n");

        if (me->query_skill_mapped("parry") != "juehu-shou")
                return notify_fail("��û��׼��ʹ�û�צ�����֣��޷�ʹ��" JUEHU "��\n");

        if (me->query("neili") < 300)
                return notify_fail("��������������������ʩչ" JUEHU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");
	extra = me->query_skill("juehu-shou",1) / 20;
	extra += me->query_skill("taiji-shengong",1) /20;
a=extra/3;
if (a> 6) a=6;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	for(i=0;i<a;i++)
	{
         msg = HIR "$N˫צ��������צӰ�����Ҫ��ץȥ��"+(i+1)+"צ��\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
me->add("neili", - 50 * i);      
        message_vision(HIM "$N" HIM "���һ��������Ϊצ��˫צ��������צӰ����������һ����$n\n"
                     "��Ҫ��ץȥ��"NOR,
                     me, target);

        if (random(me->query_skill("unarmed")) > target->query_skill("parry") / 2)
        {
                me->start_busy(2);

                damage = me->query_skill("juehu-shou", 1);
                damage = damage * 3 + random(damage * 6);
target->add("qi",-damage);
target->add("eff_qi",-damage);
msg =  "\n"NOR;
	msg += RED HIR "���$p" HIR "һ���Һ���û���м�ס$P"
                                           HIR "�����Ĺ��ƣ���ץ��Ƥ����룬��Ѫ�ɽ���\n" NOR;
if (random(6)==0 && target->query("gender")=="����" && target->query("qi") < 200
&& me->query_skill("juehu-shou",1)> 350)
{
message_vision(HIY"\n$nҪ������ȻӲ������$N˺������������Ƥ����룬��Ѫ�ɽ�\n" NOR, me,target);
target->set("gender","����");
}
                me->add("neili", -400);
if ((int)me->query("shen") > 0)
        	me->add("shen", -5000);
        } else
        {
                me->start_busy(3);
	        me->add("neili", -400);
if ((int)me->query("shen") > 0)
        	me->add("shen", -5000);
                msg += CYN "����$p" CYN "������$N"
                       CYN "����ͼ���㿪������ɱ�š�\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}


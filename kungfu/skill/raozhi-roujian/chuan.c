#include <ansi.h>
#include <combat.h>

#define CHUAN "��" HIM "���´���" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string wn, msg;
	int extra;
	int i,a;
        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(CHUAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHUAN "��\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" CHUAN "��\n");
        if( (int)me->query_skill("taiji-shengong", 1) < 180 )
                return notify_fail("��ı����ڹ�����̫ǳ�ˡ�\n");
        if (me->query_skill("raozhi-roujian", 1) < 100)
                return notify_fail("�����ָ�ὣ��Ϊ����������ʩչ" CHUAN "��\n");

        if (me->query_skill_mapped("sword") != "raozhi-roujian")
                return notify_fail("��û�м�����ָ�ὣ������ʩչ" CHUAN "��\n");

        if (me->query("neili") < 250)
                return notify_fail("��������������������ʩչ" CHUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

	extra = me->query_skill("raozhi-roujian",1) / 20;
	extra += me->query_skill("taiji-shengong",1) /20;
a=extra/3;
if (a> 6) a=6;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	for(i=0;i<a;i++)
	{
         msg = HIR "$N��ת���棬���ݳ���"+(i+1)+"����\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", - 30 * i);         



        message_vision(HIM "\nֻ��$N" HIM "ĺ����һ����Х���������䣬��\n"
                     "��" + wn + HIM "���Ƴ���һ��������������ۣ�Ʈ��\n"
                     "����������$n" HIM "���ţ�������;������΢������\n"
                     "Ȼ���˹�ȥб��$n" HIM "�Ҽ磬��ʽ����֮����\n" NOR,
                     me, target);

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap);
target->add("qi",-damage);
target->add("eff_qi",-damage);
msg =  "\n"NOR;
	msg += RED "���$pһ���������Ǳ�$P���д��У�"
                                          "һ���Һ�����Ѫ�ɽ�������\n" NOR;

                me->start_busy(2);
                me->add("neili", -150);
        } else
        {
                msg = CYN "����$p�������ң��������������"
                      "������$P�Ľ��С�\n" NOR;
                me->start_busy(3);
                me->add("neili", -60);
        }
        message_vision(msg, me, target);

        return 1;
}

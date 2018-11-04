// slj.c ������������
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	int extra;
	string msg;
        string wname;
        int ap, dp;

	
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if( (int)me->query_skill("yunlong-jian", 1) < 250 )
		return notify_fail("�����������������죬����ʹ�á�������������\n");
	                        
	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("��������񹦲����ߡ�\n");

       if (((int)me->query_skill("bazhen-zhang", 1)) < 120)
               return notify_fail("��İ��������̫���ˡ�\n");
               
       if (((int)me->query_skill("houquan", 1)) < 120)
               return notify_fail("��ĺ�ȭ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-zhua", 1)) < 120)
               return notify_fail("�������צ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shou", 1)) < 120)
               return notify_fail("���������̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shengong", 1)) < 120)
               return notify_fail("���������̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shenfa", 1)) < 120)
               return notify_fail("���������̫���ˡ�\n");

       if (((int)me->query_skill("baihua-cuoquan", 1)) < 120)
               return notify_fail("��İٻ���ȭ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-jian", 1)) < 120)
               return notify_fail("���������̫���ˡ�\n");

       if (((int)me->query_skill("wuhu-duanmendao", 1)) < 120)
               return notify_fail("����廢���ŵ�̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-bian", 1)) < 120)
               return notify_fail("��������޷�̫���ˡ�\n");
               			
	if( (int)me->query("neili", 1) < 800 )
		return notify_fail("����������̫��������ʹ�á�������������\n");
			
	extra = me->query_skill("yunlong-jian",1) / 15;
	extra += me->query_skill("yunlong-jian",1) /15;

	msg = HIM "$N" HIM "΢΢һЦ������һ����������Ԧ����������ʵʵ�Ĺ���$n"
              HIM "��\n" NOR;
        ap =  me->query_skill("sword");
        dp =  target->query_skill("force");
        
        if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("sword");

		me->add("neili", -180);
            
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIR "ֻ��$N" HIR "���н������һ���������ڿն�"
                                           "��ٿ������$n" HIR "��\n$p" HIR "ֻ��һ�ɴ���"
                                           "����ǵذ�ѹ������ʱ��ǰһ���������������۵�"
                                           "���һ����Ѫ����\n" NOR;
		me->start_busy(2);
	} else
	{
		msg += CYN "����$p" CYN "�͵���ǰһԾ��������$P"
                       CYN "�Ĺ�����Χ��\n"NOR;
	}
	message_combatd(msg, me, target);             

	if (extra > 200) extra=200;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 1000);

        msg = HIG"���磪"NOR + "$N�Ӷ�����$w����������Ƶ���$n��$l��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIW"���꣪"NOR + "$N�����ƶ����壬����$w�������꣬��$nΧ���м䣡"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIB"���ף�"NOR + "$N����һԽ������$w������Х������$n��ȥ��"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = CYN"���磪"NOR + "$N����$w����΢�񣬻ó�һ���������$n��$l"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC"���ƣ�"NOR + "$N����ǰ�������������ޣ�$w��������$n��$l��ȥ"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIM"����"NOR + "$N��������Ծ�𣬽������ּ�ת������ն��$n��$l";
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR"��˪��"NOR +  "$N����$w�й�ֱ����������Ϣ�ض�׼$n��$l�̳�һ��"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = BLU"��ѩ��"NOR +  "$N��ָ�����㣬����$w�Ƴ�����ѩ����â������$n��$l"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIY"���죪"NOR +  "$N����$wбָ���죬��â���£���׼$n��$lбб����"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);




	me->add("neili",-280);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -1000);
if ((int)me->query_skill("yunlong-jian", 1)> 350)
{
       wname = weapon->name();

        damage = (int)me->query_skill("yunlong-jian", 1) / 2;
        damage += random(damage / 3);

        ap = me->query_skill("sword");
        dp = target->query_skill("dodge");
        msg = HIG "$N" HIG "ʩ������������������������������" + wname +
              HIG "�漴һ������׼$n" HIG "������������ʽ�����ޱȣ�\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "$p" HIR "�����ֵ���ȴ�����мܵ�ס����$P"
                                           HIR "��һ������Ҫ������Ѫ�Ĵ��ɽ���\n" NOR;

        } else
        {
                msg += CYN "$p" CYN "���������Ӳ������$P"
                       CYN "��һ���ܿ���˿������\n" NOR;
        }

        ap = me->query_skill("sword");
        dp = target->query_skill("force");
        msg += "\n" HIG "ȴ��$N" HIG "�粽��ǰ������" + wname +
               HIG "���ж��䣬�ֹ���һ��������������������⣬"
               "����$n" HIG "ȫ��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "$p" HIR "ֻ���ۻ����ң�һʱ���Կ�͸��"
                                           "�а������������������Ѫ��ģ����\n" NOR;
        } else
        {
                msg += CYN "����$p" CYN "˿����Ϊ$P"
                       CYN "�����Ľ������������Ƚ���һ���ܿ���\n" NOR;
        }

        ap = me->query_skill("force");
        dp = target->query_skill("parry");
        msg += "\n" HIG "$N" HIG "�漴һ����ȣ����⻯�����⻯��������"
               + wname + HIG "��ʱ����һ����â���ٴι���$n" HIG "��ȥ��\n"
               NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "$p" HIR "�����ֵ�����ֻ��һ�����ν���"
                                           "͸�����������֮�������������Ѫ��\n" NOR;
        } else
        {
                msg += CYN "$p" CYN "һ�����Ե�������������$P"
                CYN "���彣â��Ȼ������ȴδ����$p" CYN "�ֺ���\n" NOR;
        }
        me->add("neili", -80);
        message_combatd(msg, me, target);
}
	me->start_busy(4);
	return 1;
}

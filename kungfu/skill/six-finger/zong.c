#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


#define ZONG "��" HIM "�ݺ�����" NOR "��"

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage, skill;

        if (! target) target = offensive_target(me);
        

        
        if (! target || ! me->is_fighting(target))
                return notify_fail(ZONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_prepared("finger") != "six-finger")
                return notify_fail("��û��׼��ʹ�������񽣣��޷�ʩչ" ZONG "��\n");



        skill = me->query_skill("six-finger", 1);

        if (skill < 320)
                return notify_fail("�����������Ϊ���ޣ��޷�ʹ��" ZONG "��\n");

        if (me->query_skill("force") < 280)
                return notify_fail("����ڹ���򲻹�������ʩչ" ZONG "��\n");

        if (me->query("max_neili") < 6500)
                return notify_fail("���������Ϊ����,�޷�ʩչ" ZONG "��\n");

        if (me->query("neili") < 1250)
                return notify_fail("������������������޷�ʩչ" ZONG "��\n");

        if (me->query_temp("weapon"))
                return notify_fail("������ǿ��ֲ���ʩչ" ZONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        if ((int)me->query_skill("kurong-changong",1) < 180)
            return notify_fail("��Ŀ�������̫�͡�\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 180)
		return notify_fail("��Ķμҽ����̫ǳ��\n");    
        if ((int)me->query_skill("jinyu-quan", 1) < 180)
		return notify_fail("��Ľ���ȭ���̫ǳ��\n");
        if ((int)me->query_skill("wuluo-zhang", 1) < 180)
		return notify_fail("������������ƻ��̫ǳ��\n");
        if ((int)me->query_skill("feifeng-whip", 1) < 180)
		return notify_fail("��ķɷ�޻��̫ǳ��\n");
        if ((int)me->query_skill("sun-finger", 1) < 180)
		return notify_fail("���һ��ָ���̫ǳ��\n");
        if ((int)me->query_skill("yiyang-zhi", 1) < 180)
		return notify_fail("��Ķ���һ��ָ���̫ǳ��\n");
				
        msg = HIM "$N" HIM "һ����Х��ʮָ�׵����پ�����������ӿ����ͷ������"
              "�˷������಻������ʱ�����籼�������޾������������Ȼ����$n" HIM 
              "��\n" NOR;

        ap = me->query_skill("six-finger", 1) +
             me->query_skill("force", 1) / 2;
        dp = target->query_skill("force");

        if (target->query_skill("martial-cognize", 1) >= 200
            && random (10) == 1 )
        {
                me->add("neili", -500);
                me->start_busy(3);
                msg += HIY "����$n" HIY "����һЦ��������䣬���׵Ķ����һ�У�\n"NOR;
        } else
        if (ap * 11 / 20 + random(ap) > dp)
        { 
                damage = me->query_skill("finger");
                me->add("neili", -500);
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("yyz_damage",30);

                        msg +=HIR "ֻ��$n" HIR "һ���ҽУ����������"
                                           "͸��������˿ڴ���Ѫ��ʱ��ӿ��ʹ���ѵ���\n" NOR;

                me->start_busy(2);
        } else
        {
                me->add("neili", -400);
                me->start_busy(3);
                msg += CYN "$n" CYN "��$N" CYN "������ӿ����������"
                       "�мܣ���æ����Ծ����\n" NOR;
        }
       message_combatd(msg, me, target); 
        msg = HIY "$N" HIY "̯��˫�֣���ָ��������ʱ��������ȣ���"
              "�����ڣ���������������Ѩ��һ��ɱ��$n" HIY "��\n" NOR;
        ap = me->query_skill("six-finger", 1) ;
        dp = target->query_skill("dodge"),1;
 if (random(ap)+10  > dp)
        {
                msg += HIM "$n�ô�������������Ҳʶ�ö����������������������֮�÷���һ���֮���Ȼ���ʧ��ֻ�������׸��ʱ�����������������ȫ����������Ѫ������Ѫ���粻ֹ��������ɢ֮�£�����һϢ��" + "\n" NOR;
target->start_busy(2);
        } else
        {
                msg += NOR + CYN "$p������������������÷����ĵ��������ɣ�����˫��һ�գ���ͷ�㵹���赹�ڵأ�ȴǡ�ñܹ����С�" + "\n" NOR;
        }
        message_combatd(msg, me, target); 

      msg = HIR  "$N���Ծ��ʹ���������񽣵���߾������������ڣݣ�����\n$Nɱ�����ۣ�ƴ�����й�������������⼲�����������$n��" NOR;
        message_vision(msg,me,target);
        msg = HIG  "�������������󽣡���\n$N����Сָ���㣬���������������޵С�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = HIY  "������������������������\n$Nʳָ�촦������������֮չ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = HIB  "���������������������ٳ彣����\n$N����Сָһ�죬һ·�������ٳ�Ѩ�м��������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = HIM  "���������������������������г彣����\n$N��ָһ�����г彣�͵���ǰ�̳���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = HIC  "�����������������������������������̽�����\n$NĴָ����������ʵʵ��ָ��$n�� " NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = HIW  "�������������������������������������س彣����\n$N����ָ���գ���֮һ˦��һ���������$n��$l��
" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = RED  "$NǱ���񹦣�������һ�������������⣡��\nһ��һ����һ��һ����һ��һ�µ�����$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
me->add("neili", -300);
me->start_busy(5);
        return 1;
}



// zhenwu.c �����а

#include <ansi.h>
#include <combat.h>

#define PFM_NAME        "�����а"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp,i,attack_time;
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("��" + PFM_NAME + "��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if ((int)me->query_skill("taiji-jian", 1) < 290)
                return notify_fail("���̫������������죬����ʹ�á�" + PFM_NAME + "����\n");

        if ((int)me->query_skill("raozhi-roujian", 1) < 200)
                return notify_fail("�����ָ�ὣ���̫ǳ��\n");

        if ((int)me->query_skill("yitian-zhang", 1) < 200)
                return notify_fail("������������ƻ��̫ǳ��\n");

        if ((int)me->query_skill("paiyun-shou", 1) < 200)
                return notify_fail("����������ֻ��̫ǳ��\n");
                
        if ((int)me->query_skill("shenmen-jian", 1) < 200)
                return notify_fail("�������ʮ�������̫ǳ��\n");
                                
        if ((int)me->query_skill("force", 1) < 250)
                return notify_fail("����ڹ���Ϊ�����ߣ��������á�" + PFM_NAME + "����\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 250)
                return notify_fail("���̫������Ϊ�����ߣ��������á�" + PFM_NAME + "����\n");


                                    
        if ((int)me->query("neili") < 2000)
                return notify_fail("��������������������ʹ�á�" + PFM_NAME + "����\n");

        if (me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("��û�м���̫������������ʹ�á�" + PFM_NAME + "����\n");

        msg = HIY "$N" HIY "��Ŀ���������ת��һ�г���̫������ġ�" HIW + PFM_NAME +
              HIY "������ʹ�������з��ӹ��棬����ƽ�����棬\nʵ��㼯�����֮���������"
              HIY "������" + weapon->name()+ "�û�������̫����Ȧ������ǵص�ѹ��$n��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        
        // ��ǿ ap
        if (me->query("shen") >= 10000) ap += (30 + random(20));
        if (target->is_bad()) ap = ap * 3 / 2;
        // ���� ap
        //if (me->is_not_good()) ap = ap / 2;
        if (me->query("shen") <= 0) ap = ap / 3;
        if (target->query("shen") >= 10000) ap = ap * 4 / 5;

        if (wizardp(me) && me->query("env/combat_test"))
        {
                tell_object(me, HIY "AP: " + ap + ". DP: " + dp + ".\n" NOR);
        }
        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = me->query_skill("sword")*3;

                me->add("neili", -(damage/2+300));
//              tell_object(me, HIC "DAMAGE: " + damage + ".\n" NOR);
       target->add("qi",-damage+500);
		target->add("eff_qi",-damage+500);
                msg += HIR "\n$p" HIR "��$P���������壬��Ȼ�ŵù˲����мܣ�"
                                           "��һ�����ؿ���С���Ữ������\n��ʱ��Ѫ�ɽ���\n" NOR;
                me->start_busy(3);
        } else 
        {
                msg += WHT "\nȻ��$p" WHT "��Ȼ˿������Ϊ�⣬���赭д�Ľ�$P"
                       WHT "�Ľ��мܿ���\n" NOR;
                me->add("neili", -50);
                me->start_busy(4);
        }
        message_combatd(msg, me, target, 0, 1);
        //msg="";
        msg = HIW "�Ӹ��ţ�$N" HIW "һ����Х������" + weapon->name() +
              HIW "��������������һ����ԲȦ����$n" HIW "Ȧ�ڵ�"
              "�С�\n" NOR;
                        msg += HIY "���$p" HIY "��$P" HIY
                       "���˸����ֲ������������˲�Ͼ��\n" NOR;
attack_time = (int)me->query_skill("taiji-jian", 1)/30;
                if (attack_time > 9)
                attack_time = 9;
        msg += HIC "��� $N" HIC "һ����Х����̨�����������Ԫ��ʹ��̫�����еĽ����ת��\n"
              HIY "����" + weapon->name() + HIY "��ʽ��Ȼ��������ޱȣ�һת��"
              HIY "����Ȼ����" + chinese_number(attack_time) + "�У�\n" NOR;
message_combatd(msg, me, target);
                	me->add_temp("apply/attack", 100);
	me->add_temp("apply/damage", 800);

        for (i = 0; i < attack_time; i++)
        {
                 if (random(3)==0) target->start_busy(2);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -800);

        return 1;
}


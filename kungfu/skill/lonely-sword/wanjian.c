// jiushi.c �򽣴���

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
    int damage , zhao,damage2;
    string msg;
    object weapon;
    int extra,skill;
    int i,ap,dp;
    

    if (!target ) target = offensive_target(me);

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ���򽣴��ġ���\n"NOR);
skill=(int)me->query_skill("lonely-sword", 1);
//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");

    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����ʽ��һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if ((int)me->query_skill("lonely-sword", 1) < 250 )
        return notify_fail(WHT"����¾Ž�������죬ʹ�������򽣴��ġ���\n"NOR);

    if ((int)me->query_skill("chongling-jian", 1) < 250 )
        return notify_fail(WHT"����齣��������죬ʹ�������򽣴��ġ���\n"NOR);


    if (me->query_skill("huashan-sword", 1) < 100)
        return notify_fail("�㻪ɽ������򲻹����޷������齣����\n");

    if (me->query_skill("fanliangyi-dao", 1) < 100)
        return notify_fail("�㷴���ǵ�����򲻹����޷������齣����\n");
    if (me->query_skill("feiyan-huixiang", 1) < 100)
        return notify_fail("���������򲻹����޷������齣����\n");
    if (me->query_skill("hunyuan-zhang", 1) < 100)
        return notify_fail("���Ԫ�ƻ�򲻹����޷������齣����\n");
    if (me->query_skill("poyu-quan", 1) < 100)
        return notify_fail("����ʯ����ȭ��򲻹����޷������齣����\n");
    if (me->query_skill("kuangfeng-jian", 1) < 100)
        return notify_fail("����콣��򲻹����޷������齣����\n");
    if ((int)me->query("max_neili")<2000)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);

     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("���¾Ž����������ϼ�񹦡�\n");

    if ((int)me->query("neili")<980)
    {
        return notify_fail(HIC"����������������û�ܽ����򽣴��ġ�ʹ�꣡\n"NOR);
    }

	extra = me->query_skill("lonely-sword",1) / 20;
	extra += me->query_skill("zixia-shengong",1) /20;
if (extra >=200) extra =200;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
      msg = HIW "$N����������ʹ����"HIG"�򽣴���"HIW"������������Ȼ�ӿ죬�͵�����9�У�\n"NOR;
        message_vision(msg, me, target);
        me->add("neili", -500);
        msg = HIC"��һ������"HIG"���¾Ž�"HIY"==��һ���ľ���=="HIC"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIW"�ڶ�������"HIG"���¾Ž�"HIC"==��һ��������=="HIW"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIY"����������"HIG"���¾Ž�"HIW"==��һ������Ȼ=="HIY"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIR"���Ľ�����"HIG"���¾Ž�"BBLU+HIW"==��һ���ķ���=="NOR+HIR"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = BLU"���彣��"HIB"��"HIG"���¾Ž�"HIR"==��һ���Ĳ���=="BLU"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIG"����������"HIG"���¾Ž�"RED"==��һ��������=="HIG"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = CYN"���߽�����"HIG"���¾Ž�"HIY"==��һ���İ���=="NOR+CYN"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIW+BLK"\n�ڰ˽�����"HIG"���¾Ž�"HIB"==��һ���ļ�į=="HIW+BLK"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = MAG"�ھŽ���"HIR"��"HIG"���¾Ž�"HIY"֮"U+HIG"��"HIW"��"HIY"��"HIW+BLK"��"HIR"��"NOR+HIR"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->start_busy(3);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);

       msg = HIW "$N" HIW "ʩ�����¾Ž�������ʽ��������" + weapon->name() +
              HIW "�й�ֱ����ңָ$n" HIW "������ҪѨ��\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("parry");
        dp = target->query_skill("force") + target->query_skill("parry");

        if (ap * 2 / 3 + random(ap * 2 / 3) > dp)
        {
                damage = me->query_skill("sword");
target->add("qi",-damage*2);
target->add("eff_qi",-damage*2);
target->start_busy(3);
                        msg +=HIR "$n" HIR "��$N" HIR "һ���������ţ��Ǹ�һ��"
                "׶�ĵĴ�ʹ��ȫ������ԴԴ��к��\n" NOR;

        } else 
        {
                msg += CYN "��$n" CYN "��֪$N" CYN "���е���"
                       "�����������������ߣ�����������\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
       	
	       switch (random(3))
        {
        case 0:
                msg = HIY "$N" HIY "����һ��ָ��$n" HIY "���������$n"
                      HIY "�������ڣ���֮�������������Ѳ⡣\n" NOR;
                break;

        case 1:
                msg = HIY "$N" HIY "���д󿪴��أ������������£�����"
                      "�нԻ�$n" HIY "����������������������\n" NOR;
                break;

        default:
                msg = HIY "$N" HIY "���ֺὣ����$n" HIY "������������"
                      "���е�һ����Ȼ����������˷�����˼��\n" NOR;
                break;
        }

        ap = me->query_skill("sword");
        dp = target->query_skill("parry") +
             target->query_skill("lonely-sword");

        if (ap * 2 / 3 + random(ap * 2 / 3) > dp)
        {
                damage = me->query_skill("sword");
target->add("qi",-damage*2);
target->add("eff_qi",-damage*2);
target->start_busy(3);
                        msg +=HIR "$n" HIR "ȫȻ�޷����$N" HIR "��"
                                           "���еİ��һ�����񣬵����ش���\n" NOR;

                me->start_busy(2);
        } else 
        {
                msg += CYN "��$n" CYN "��Ȼ��֮����û��$N"
                       CYN "���з������ϣ����ּܿ�����©���������\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
   
if (skill > 350) 
{
	   message_vision("\n
"HIY"$N�����뽣�ѿ�ʼ���˶�����һ�ּ��������������Ķ����������Ƿ���ô��Ȼ\n
"HIY"$N��ͫ����������"+weapon->name()+""HIY"�������Ĵ��˳���\n
"HIY"�����˼��Ĳ�λ���˳������̳�ʱ��Ȼ���������˼��ı仯\n
"HIY"���ϸ���û����������һ��������û���κ�����˭��ȥ����һ��������ȥ����\n\n"NOR,me,target);
 if(random(2)==0)
  {

   message_vision(HIR"Ѫ��ҫ���ֲ��ã����õ��������ǣ�����һ�ּ��ţ�Ѫ��Ҳ�ܿ������\n"NOR, me,target);
damage=target->query("max_qi")/5;
damage2=target->query("max_jing")/5;
if (damage >=20000) damage=20000;
	if (damage2 >=20000) damage2=20000;
        target->add("neili",-damage);
        target->receive_wound("qi",damage);
        target->receive_wound("jing",damage2);
        me->add("neili",-250);
  }
else
	{
 message_vision(HIB"$n ����һ����������$N�Ĺ��ƣ����첻���ı��˿�����\n"NOR,me,target);		
	}

}

   
    return 1;
}

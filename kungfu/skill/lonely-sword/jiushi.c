// jiushi.c ��ʽ��һ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
    int damage , zhao;
    string msg;
    object weapon;
    int extra;
    int i;
    
string  *pfattack_msg = ({
                       HIG"������ʽ��$NͻȻ�����н�ʽ��תΪʩ������$n��ʱ���Ƶ���æ���ң��Լ���$N�ĳ���ײ��������\n"NOR,
                       HIR"���潣ʽ��$N�������������֣����б�����ҵߵ���$nһʱû��Ū�����̸����š�\n"NOR,
                       HIC"���佣ʽ��$N������𣬳�ͷ�½����ƣ��ӿ��й���$n��$n�������������$N�Ĵ��С�\n"NOR,
                       HIY"��ҡ��ʽ��ֻ��$N�ĳ�����������һ�������ػ��ţ�$n��֪��Ҫ�����Լ���ʲôλ�ã�վ��ԭ�ط�������������С�\n"NOR,
                       HIW"������ʽ��$N�Ľ���ͻȻ����������������Ʈ��������$nֻ����ǰһ�����ؿ��ѱ����С�\n"NOR,
                       HIB"���˽�ʽ������󺣿��Σ���������$nѹȥ��$nֻ��������$N�Ľ��еĿ�籩��֮�У���֪�����Ѿ������С�\n"NOR,
                       YEL"���콣ʽ��$n��$N����һ����ֻ��$N����������һ����$n��С��������$N��һ����\n"NOR,
                       HIG"���뽣ʽ��ֻ��$N�����г�������������У��������Ⱪ�����������Ƿ���$n��$n��ܲ������������С�\n"NOR,
                       HIW"$N���г������һ�㣬"+HIR"������ʽ��"+HIW"Ӧ�ֶ���������֮�ڽ����ݺ����಻��Ϯ��$n��$n��æ�ڿն����Ѿ�̫�������Ѿ����ض�����\n"NOR
                       });

string *pfparry_msg = ({
                      HIG"$p������$P����ͼ��ͦ�����ϣ�һȦһ���ƽ���$P�����С�\n"NOR,
                      HIB"$p�������$P�Ľ������մӽ��²�����\n"NOR,
                      HIY"$PͻȻ���󷽹�ȥһ�������Ա�$p�ϵ���������������Ʈ�����࣬���������С�\n"NOR,
                      });

    if (!target ) target = offensive_target(me);

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ����ʽ��һ����\n"NOR);

//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");

    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����ʽ��һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if ((int)me->query_skill("lonely-sword", 1) < 250 )
        return notify_fail(WHT"����¾Ž�������죬ʹ��������ʽ��һ����\n"NOR);

    if ((int)me->query("max_neili")<2000)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);

     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("���¾Ž����������ϼ�񹦡�\n");

    if ((int)me->query("neili")<800)
    {
        return notify_fail(HIC"����������������û�ܽ�����ʽ��һ��ʹ�꣡\n"NOR);
    }

//    msg += HIR"����ʽ��һ��"+HIW+"��������Ʈ�������²�����ֱ��$n��ȥ��\n\n"NOR;
//if ((int)me->query_skill("zixia-shengong",1) > (int)me->query_skill("lonely-sword",1))
//if (random(2)==0)
if ((int)me->query_skill("zixia-shengong",1) >= (int)me->query_skill("lonely-sword",1))
{
    msg = HIW "$N�����������г�����âԾ�������Ⱪ�����������ʹ�����¾Ž��ģ����ž���\n"NOR;
    msg += HIR"����ʽ��һ��"+HIW+"��������Ʈ�������²�����ֱ��$n��ȥ��\n\n"NOR;

for (zhao=0;zhao<9;zhao++)
{ 

    if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
    {
        me->start_busy(3);
  if( !target->is_busy() )
{
        target->start_busy(random(2));
}
        damage = (int)me->query_skill("lonely-sword", 1) + (int)me->query_skill("sword", 1);
        damage = 100 + damage + random(damage);
        target->receive_damage("qi", damage/2);
        target->receive_wound("qi", damage/4);
      msg += pfattack_msg[random(sizeof(pfattack_msg))];
        me->add("neili", -damage/5);
    } else
    {
    me->start_busy(3);
 
      msg += pfparry_msg[random(sizeof(pfparry_msg))];
   }
}
    message_combatd(msg, me, target);
}
else
{
	extra = me->query_skill("lonely-sword",1) / 20;
	extra += me->query_skill("zixia-shengong",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
      msg = HIW "$N����������ʹ����"HIG"���¾Ž�"HIW"������������Ȼ�ӿ죬�͵�����9�У�\n"NOR;
        message_vision(msg, me, target);
        me->add("neili", -500);
        msg = HIC"��һ������"HIG"���¾Ž�"HIY"����ʽ"HIC"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIW"�ڶ�������"HIG"���¾Ž�"HIC"��ɳʽ"HIW"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIY"����������"HIG"���¾Ž�"HIW"����ʽ"HIY"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIR"���Ľ�����"HIG"���¾Ž�"BBLU+HIW"�п�ʽ"NOR+HIR"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = BLU"���彣��"HIB"��"HIG"���¾Ž�"HIR"��ɨʽ"BLU"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIG"����������"HIG"���¾Ž�"RED"ֱ��ʽ"HIG"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = CYN"���߽�����"HIG"���¾Ž�"HIY"����ʽ"NOR+CYN"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIW+BLK"\n�ڰ˽�����"HIG"���¾Ž�"HIB"б��ʽ"HIW+BLK"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = MAG"�ھŽ���"HIR"��"HIG"���¾Ž�"HIY"֮"U+HIG"��"HIW"��"HIY"��"HIW+BLK"��"HIR"��"NOR+HIR"��"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
           msg = HIW"\n���$n��$N���˸����ֲ�����\n"NOR;
           message_vision(msg, me, target);
        me->start_busy(3);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);
}        	
	
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}

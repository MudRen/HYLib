// ������
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count,extra,p;
  if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("ֻ����ս����ʹ�á�\n");
 weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") != "staff")
		return notify_fail("�������ֲ���ʹ�����������\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("tianshan-zhang", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("chousui-zhang", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("huagong-dafa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ��������ѧ��ʹ���������ɵľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          

  msg = HIM "\n$NͻȻ�������㵸�����������дʣ��е����������񹦣��������Ž��ޱȡ���\n";
  msg += HIM "���Ž�������������������ͣ������·������������޽����裬�����Ŀ���ࡣ\n\n"NOR;

  message_vision(msg, me, target );
if (random(3)==0) target->start_busy(3);
	msg = HIY "$Nʹ����ɽ�ɾ�������ɽ��塹������Ȼ�ӿ졣�������ڣ�" NOR;
	p  = me->query_skill("huagong-dafa",1);
        extra = me->query_skill("tianshan-zhang",1) / 10;
        extra += me->query_skill("huagong-dafa",1) /10;
        me->add_temp("apply/attack", extra*2);    
        me->add_temp("apply/damage", extra*3);
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIB  "        ^^�����أ�^^       " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  RED  "      ^^^^ɽ��������^^^^  " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIM  "    ^^^^^^���ż�ɽ��^^^^^ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "^^^^^^^^^^^��ɽѩ����^^^^^^^^^^^ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra*2);    
        me->add_temp("apply/damage", -extra*3);
        message_vision(HIY"$N����ʽͻ�䣬����ð�����̹�! $n���̹�ɨ�У�ȫ����һ��!\n"NOR,me,target);
        target->apply_condition("xx_poison",50);
	 msg =  HIR  "����ʬ����" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("poison_sandu",50);
	 msg =  HIR  "����ɰ�ơ�" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("sanpoison",50);
	 msg =  HIR  "�����ζ���" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -150);
        if (random(me->query("combat_exp")) >target->query("combat_exp")/3)
        {
       	 msg =  HIR  "����Ц��ңɢ��" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"$NͻȻ�����һЦ��$n��Ȼ����Ц��Ц!\n"NOR,me,target);
            target->receive_damage("qi", p*5);  
            target->receive_wound("qi", p*3);  
        target->apply_condition("sanxiao_poison",6);
        me->add("neili", -50);
        }
message_vision(RED "\n$N��ȫ�������ע����ϣ����ŵ���һָ..���ϳ�������"HIR"����\n" NOR, me);	
       message_vision(BLU"\n$N��ɫ�ҵ������ִ򿪷��٣������´����������ϣ����ŵ�ȼ���׷ۣ�ҧ����⣬
һ��"RED"��Ѫ"BLU"���������ȥ��"HIR"�������һ�����漴��Ϊ"RED"����"HIR"��ҫ�������۾�Ҳ����������\n\n"NOR,me);
        msg = BLU"\n$N�͵����Ӽ����������ݰ���ת��ʮ���Ȧ�ӣ�����$P���������"HIR"��������Ѷ��ز������
ȼ�գ�����һ��"RED"��ǽ"HIR"�㣬������ɽ����֮����$nѹ����\n"NOR;
 	if( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  ) {

            msg += HIY"\n$nֻ��Ŀ�ɿڴ���һ��֮�䣬��æԾ�𣬵�һ��"HIW"��"HIY"���䵽��ǰ���͵�һ���죬
�������϶Ǹ���$n��������һ����У���������������"HIR"���ǽ"HIY"Ҳ�����������С�\n" NOR;
            target->receive_damage("qi", p*8);  
            target->receive_wound("qi", p*5);  
            msg += "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
            msg += "( "RED"$n���˹��أ��Ѿ�������в�����ʱ�����ܶ�����"NOR")\n";
		message_combatd(msg, me, target);
}
else
{
		msg += "$p������������һ�𣬽�$N����Ĵ��ǽж��������!\n" NOR;
		message_combatd(msg, me, target);
}
	me->start_busy(4);
	return 1;
}

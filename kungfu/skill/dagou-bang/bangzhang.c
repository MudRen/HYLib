// bangzhang����˫��

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count,extra,damage;
 	if( !target ) target = offensive_target(me);


	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("xianglong-zhang", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

       if( !wizardp(me) &&(int)me->query_skill("dagou-bang", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("huntian-qigong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "huntian-qigong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨؤ����ѧ��ʹ����ؤ��ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);      
        extra = me->query_skill("xianglong-zhang",1);
        msg = YEL "$N����һ��,ûͷû�Ե���ǰ����˳�ȥ,�����Ǵ򹷰����ľ�Ҫ֮���ڣ�\n" NOR;
        msg+= HIR"$Nŭ��һ�������"+ weapon->name()+HIG"һ�����Ծ����δ�������ȵ��������»�����ʩ����ɱ�֣�\n" NOR;
        message_vision(msg, me);
if (random(3)==0) target->start_busy(3);
        me->add_temp("apply/attack", (int)me->query_skill("dagou-bang",1));
        me->add_temp("apply/damage", (int)me->query_skill("dagou-bang",1)/2);
       msg = WHT  "$Nת��"+ weapon->name()+HIG"��ˢˢˢ��������������������ף����Ǵ򹷰����е�ɱ�У�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                target->receive_wound("qi",random((int)me->query_skill("dagou-bang",1)));
        msg = HIC  "$NͻȻ�ɳ�"+ weapon->name()+HIG"��ӭ������$n������������£�������ʱ֮��ֵ�$p�ؿ�������Ѩ��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                target->receive_wound("qi",random((int)me->query_skill("dagou-bang",1)));
        msg = RED "$N����ӳ�������Ϊ�������ӳ��򹷰����еĹ��֣�����������ɱ�У�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = RED "��һ�� $N����ӳ���ʹ���˷��־���" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED "�ڶ��� $N����ӳ���ʹ����ת�־���" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED "������ $N����ӳ���ʹ���˰��־�����" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


                target->receive_wound("qi",random((int)me->query_skill("dagou-bang",1)));
        me->add_temp("apply/attack", - (int)me->query_skill("dagou-bang",1));
        me->add_temp("apply/damage", - (int)me->query_skill("dagou-bang",1)/2);
                 me->add_temp("apply/strength", extra/3);
                 me->add_temp("apply/attack", extra);
	         me->add_temp("apply/damage", extra);
	me->add("neili", -1000);
weapon->unequip();
		 msg = YEL "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ������ʮ���Ƶ����һ�С�"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+YEL"��һ�а�ʽ����$n��" NOR;
       	         message_vision(msg, me, target);                
	 msg =  HIC  "��һʽ��$N����һʽ��������Ұ���������ޱȵ�����$n��" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ڶ�ʽ��$N˫��ʩ��һʽ��������½��������ԼԼ�����Ʒ�����$n��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "����ʽ��$N�������أ�����һʽ��Ǳ����������������$n��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "����ʽ��$Nʹ������Ծ���졹����$n���������ƣ�" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "����ʽ��$N˫��һʽ��˫��Ϸˮ��һǰһ����$n����ǰ��" NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM  "����ʽ��$N����ת����ʹ����������������$n�������£�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "����ʽ��$N����һת��ͻȻ�۵�$n��ǰ��һʽ����ս��Ұ��ֱ����$n����" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "�ڰ�ʽ��$NͻȻ����˫�ƾӸ��������һʽ����Х���졹ȫ������$n��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/strength", -extra/3);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        if( random(me->query("combat_exp")) > target->query("combat_exp")/4
		)
	 {

 msg = HIR"��ҧ�����أ�˫�ƻ�������Ĭ���ʮ���ƵĿھ�!"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��!!"NOR+" ";
                msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
                target->receive_damage("qi",(int)me->query_skill("xianglong-zhang",1)*5);
                target->receive_wound("qi",(int)me->query_skill("xianglong-zhang",1)*3);
		target->receive_wound("jing", 10 + random(200));
                if (!target->is_busy()) target->start_busy(3);
		message_combatd(msg, me, target);
                COMBAT_D->report_status(target);
	}
        me->start_busy(4);


        return 1;
}


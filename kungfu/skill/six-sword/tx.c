// ning@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
        extra = me->query_skill("six-sword",1);
        if ( extra < 280) return notify_fail("��ģ�����׷�꽣���ݻ��������죡\n");
        if( me->query_skill("canhe-zhi",1) < 180 )
                return notify_fail("��Ĳκ�ָ��򲻵����޷�ʩչĽ�ݼҴ���ѧ��\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 180)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
        if ((int)me->query_skill("murong-daofa", 1) < 180)
                return notify_fail("���Ľ�ݵ������̫ǳ��\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 180)
                return notify_fail("������������̫ǳ��\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 180)
                return notify_fail("��Ķ�ת�����ƻ��̫ǳ��\n");
        if ((int)me->query_skill("murong-jianfa", 1) < 180)
                return notify_fail("���Ľ�ݽ������̫ǳ��\n");
        if ((int)me->query_skill("qxxy-shou", 1) < 180)
                return notify_fail("������������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("canhe-zhi", 1) < 180)
                return notify_fail("��Ĳκ�ָ���̫ǳ��\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
                return notify_fail("��Ķ�ת���ƻ��̫ǳ��\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�۽��ϸ������£�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");

        weapon = me->query_temp("weapon");
        if((int)me->query("neili") < 500 )
                return notify_fail("�������������㣬����ʹ�ã�\n");
                weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"       )
                return notify_fail("������û�н����޷�ʹ�ã�\n"); 
                if (extra>200) extra=200;
       msg = HIG  "$Nʹ������׷�꽣���еģ۽��ϸ������£ݣ�һ������������\n���е�"+ weapon->name()+  HIG"�������$n"HIG"������һ����" NOR;
        me->add_temp("apply/attack",extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
        msg = HIG  "�ڶ�����" NOR;
        me->add_temp("apply/damage",extra);
        me->add_temp("apply/attack",extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra);
        if (extra<130) {
        me->start_busy(3);
        return 1;
        } 
        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra);
        msg = HIG  "$N���⼱����һƬ��Ӱ���ֹ�����������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
        me->start_busy(3);


       me->start_call_out( (: call_other, __FILE__, "third_sword", me, 
target,extra,weapon :), random(2)+1);
                         
        me->start_busy(3);
        return 1;               
        
 me->add("neili",-380);
        me->start_busy(3);
	return 1;
}
int third_sword(object me,object target,int extra,object weapon)
{
        string msg;
        int bonus, exp_bonus;
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me)) return 0;
        if(!present(weapon,me)||weapon->query("equipped")!="wielded") return 0;

		me->add_temp("apply/attack",100);
        me->add_temp("apply/damage",1000);
        msg = HIG  "$N���⼱����һƬ��Ӱ���ֹ����� �� ��!!��"+HIW"������Ӱ�ѹ顣��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/attack",-100);
        me->add_temp("apply/damage",-1000);
if (random(5)==0) target->start_busy(3);
target->add("qi",-extra*2);
target->add("eff_qi",-extra);
msg = HIW"$N��ϣ۶�ת���ƣ�˫��һ�٣���ֱԾ������"+ weapon->name() + HIW"��ͣ�ز�����\n�����������ģ��� ɪ��һʫ��������ס$nȫ��\n\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "��ɪ�޶���ʮ�� \n" NOR + CYN "$N��������Ʈ������$w"NOR + CYN"����ʵʵ�׷���������$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "һ��һ��˼���� \n" NOR + CYN "$N������$n����һ�Σ�����$w"NOR + CYN"����һ�佣������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "ׯ�������Ժ��� \n" NOR + CYN "$N������$nһת������$w"NOR + CYN"����һָ���ó����콣Ӱ������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "���۴����жž� \n" NOR + CYN "$N����ƮȻ������Ȼһ������$w�������޵�������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "�׺����������� \n" NOR + CYN "$N�������࣬ͷ�½��ϣ�����$w"NOR + CYN"���һ����������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "������ů������ \n" NOR + CYN "$N����$w"NOR + CYN"����΢�񣬻ó�һ���׹����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",extra*4);
        msg = HIW  "����ɴ���׷�� \n" NOR + HIC "$N��������Ծ�𣬽�����ˮ��һкǧ�����$nȫ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*4);
        me->add_temp("apply/damage",extra*10);
        msg = HIW  "ֻ�ǵ�ʱ��ãȻ \n" NOR + HIC "$N����$w"NOR + HIC"һ����������Ϣ�ػ���$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*10);
        return 1;
}      

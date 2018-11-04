//Cracked by Kafei
//hengshan.c ��ɽ��彣 by maco

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ɽ��塹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("hengshan") )
                return notify_fail("���Ѿ�ʹ������ɽ��塹�ˣ�\n");

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽��������ʩչ����ɽ��塹��\n");

        if( me->query_skill("dodge") < 100 )
                return notify_fail("����Ṧ��Ϊδ��������ʩչ����ɽ��塹�ı��֮����\n");

        if( me->query_skill("sword") < 100 )
                return notify_fail("���ڽ����ϵ����費����ʹ������ɽ��塹��\n");

        if( me->query("neili") <= 200 )
                return notify_fail("�����������ʩչ����ɽ��塹��\n");

        skill = me->query_skill("sword");

	if(random(target->query_skill("parry"))>skill) {
        message_vision(HIW "\n$N����ʹ������ɽ��塹������$n�ϼӽ䱸��ȫ���Ż����޲��ر������������Ч��\n" NOR, me, target);
	me->start_busy(2);

	}
	else{
        message_vision(HIG "\n�������ⶸ����$N����"+weapon->query("name")+HIC"ԽʹԽ�죬�����ɽ�ĸߵͲ�ƽ����壬����"+HIR"����ɽ��塹"NOR+HIC"��\n" NOR, me, target);
	if (random(3)==0) target->start_busy(2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("hengshan", 1);
        call_out("checking", 1, me, target);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/4);
	}
        me->add("neili", -200);
        me->add("jing", -100);
        return 1;
}


void checking(object me, object target)
{

	object weapon;
if (!me) return;
	weapon = me->query_temp("weapon");

        if ( me->query_temp("hengshan")  ) {
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n������û�гֽ�������ɽ��塹�Ĺ��Ʊ㼴�߽⣡\n" NOR);
		me->delete_temp("hengshan");
                return;
           }


           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n���"+weapon->name()+"�ѻ٣��޷���������ɽ��塹�Ĺ��ƣ�\n\n" NOR);
		me->delete_temp("hengshan");
                return;
           }
           else if ( (int)me->query("neili") < 400  ) {
                tell_object(me, "\n���������̲��㣬���Գ�������ɽ��塹�������������ջ����С�\n\n" NOR);
		me->delete_temp("hengshan");
                return;
           }
           else if ( me->query_skill_mapped("sword") != "hengshan-jian" ) {
                tell_object(me, "\n��ת��ʩչ�����������޷����ԡ���ɽ��塹���У�\n\n" NOR);
		me->delete_temp("hengshan");
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n������û�к��˹��У������ջ��ˡ���ɽ��塹�Ĺ��ơ�\n\n" NOR);
		me->delete_temp("hengshan");
                return;
           }
	   else call_out("checking", 1, me, target);
	}
	   else return;

}  

void remove_effect(object me, int amount)
{
if (!me) return;
        if ( me->query_temp("hengshan") ) {
                message_vision(HIW"\n$N���н������ѽ�һ�ס���ɽ��塹ʹ�꣡\n" NOR, me);
        me->delete_temp("hengshan");
        }
}

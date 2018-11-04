//xunlei.c Ѹ�׽�

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��Ѹ�׽���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if(me->query_temp("xunlei_yushi"))
		return notify_fail("�㽣��δ����������ʩչ��Ѹ�׽�����\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query("neili") < 800 )
                return notify_fail("�������������\n");
	
	if( (int)me->query_skill("yunlong-jian", 1) < 200 )
		return notify_fail("�����������������죬����ʹ��Ѹ�׽���\n");
	                        
	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("��������񹦲����ߡ�\n");
			

        msg = HIR "\n$N����"+weapon->query("name")+HIR"����ָ���Լ��ؿڣ�����бб���⣬����֮�������ƻؽ�����һ�㣡\n\n" NOR;
        message_vision(msg, me,target);
	me->start_busy(1);
        ob = me->select_opponent();
	me->delete_temp("xunlei");
	me->set_temp("xunlei",3);
        me->add("neili", -50);
	me->set_temp("xunlei_yushi");
	call_out("checking", 1, me, target);
        return 1;
}


void checking(object me, object target)
{
int extra;
	object weapon;
        if (!me) {
                return;
        }

        if (!target) {
                return;
        }


        if (!me->query_temp("weapon")) {
                tell_object(me,  "\n�������û�ˡ�\n\n" NOR);
                return;
        }

	weapon = me->query_temp("weapon");

        if (!me) {
                return;
        }

        if ( me->query_temp("xunlei")  ) {
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n�������޽�������ֹͣ��Ѹ�׽��ļ��ơ�\n" NOR);
		me->delete_temp("xunlei");
                return;
           }
           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n���"+weapon->name()+"�ѻ٣��޷�����Ѹ�׽��Ĺ��ƣ�\n\n" NOR);
		me->delete_temp("xunlei");
                return;
           }
           else if ( (int)me->query("neili") < 200  ) {
                tell_object(me, "\n���������̲��㣬���ò�ֹͣѸ�׽��Ĺ��ƣ�\n\n" NOR);
		me->delete_temp("xunlei");
                return;
           }
           else if ( me->query_skill_mapped("sword") != "yunlong-jian" ) {
                tell_object(me, HIR "\n��ת��ʩչ�����������޷�����Ѹ�׽����У�\n\n" NOR);
		me->delete_temp("xunlei");
                return;
           }
           else if ( me->is_busy() ) {
                tell_object(me, HIR "\n�����ڶ����������޷�����ά��Ѹ�׽����ƣ�\n\n" NOR);
		me->delete_temp("xunlei");
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n������û�к��˹��У������ջ���Ѹ�׽��Ĺ��ơ�\n\n" NOR);
		me->delete_temp("xunlei");
                return;
           }
           else if (!target) {
                tell_object(me,  "\n������û�к��˹��У������ջ���Ѹ�׽��Ĺ��ơ�\n\n" NOR);
		me->delete_temp("xunlei");
                return;
           }
	   else{

        if ( me->query_temp("xunlei") ==4 )message_vision(HIY"\n$N�����ǰ��"+weapon->name()+HIY"��Ȼ���䵯��������ֱ��$n������֮������Ϊ�κν�����������\n" NOR, me,target);
        if ( me->query_temp("xunlei") ==3 )message_vision(HIW"\n$N��ָ��"+weapon->name()+HIW"��һ�����������ˣ�����������"+weapon->name()+HIW"�������������������޷���\n" NOR, me,target);
        if ( me->query_temp("xunlei") ==2 )message_vision(HIG"\n$N��Ȼ����һ����"+weapon->name()+HIG"�Ϻ����������ȵ�����"+target->name()+HIG"����С���ˣ���\n" NOR, me,target);
        if ( me->query_temp("xunlei") ==1 )message_vision(HIR"\n����$N���ֻӽ���"+weapon->name()+HIR"������ǰ�����ң�˲Ϣ֮���ѹ���������һʮ���У�\n" NOR, me,target);
	extra = me->query_skill("yunlong-jian",1) / 13;
	extra += me->query_skill("yunlong-jian",1) /13;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        me->add("neili", -60);
	me->start_busy(1);
if (!target->is_busy() && random(3)==1)
{
	target->start_busy(2);
}

        message_vision(HIW"��һ����\n" NOR,me,target);     
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIC"��һ����\n" NOR,me,target);     
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIR"��һ����\n" NOR,me,target);     
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIG"��һ����\n" NOR,me,target);     
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
  	   me->set_temp("xunlei_attack");
           me->set_temp("xunlei", me->query_temp("xunlei")-1);
           call_out("checking", 2, me, target);
		}
        }
        else {

        if ( me->query_temp("xunlei")  ) {
       if (!me) {
                return;
        }
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n�������޽�������ֹͣ��Ѹ�׽��ļ��ơ�\n" NOR);
		me->delete_temp("xunlei");
                return;
           }
        if (!target) {
                tell_object(me,  "\n������û�к��˹��У������ջ���Ѹ�׽��Ĺ��ơ�\n\n" NOR);
		me->delete_temp("xunlei");
                return;
        }
}
        message_vision(HIY "\n$N˳��Ȧת����"+weapon->name()+HIY"��һʮ���֡�Ѹ�׽�����Ȼ����ʹ����\n" NOR, me, weapon);
	me->start_busy(2);
	me->delete_temp("xunlei");
        call_out("xunlei_end", 3, me);
        }
}  
void xunlei_end(object me, object target)
{
	object weapon;
        if (!me) return;
	weapon = me->query_temp("weapon");

	me->delete_temp("xunlei");
	me->delete_temp("xunlei_yushi");
        if ( me->query_temp("xunlei")  ) {
        tell_object(me, HIR "\n�㰵�Ե�Ϣ������ƽ����ӿ��������\n\n" NOR);
	}
}

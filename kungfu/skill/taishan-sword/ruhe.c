//Cracked by Kafei
//ruhe.c ������ by maco
/*
��һ�п������̩ɽ�ɽ����������ľ��գ�Ҫּ�������ֽ��У�
�������ֵ����������ֲ�ס��ָ���㣬����ǵ���������λ���书
���ɡ����γ��̡����д�С���Լ��չ����ոߵ͵ȵȣ����㼫Ϊ��
����һ����׼��ͦ���������޲��еġ�
*/
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
                return notify_fail("�������Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("ruhe") )
                return notify_fail("���Ѿ����ԡ������Ρ�������γ����ˣ�\n");

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽�����ʹ�ԡ������Ρ����㹥�أ�Ҳ�޷�������\n");

        if( me->query_skill("sword") < 100 )
                return notify_fail("���ڽ����ϵ����費����ʹ���������Ρ���\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�������������\n");
        if( me->query("jing") <= 200 )
                return notify_fail("��ľ�������\n");

        skill = me->query_skill("taishan-sword");

        message_vision(YEL"\nֻ��$N����"+weapon->query("name")+YEL"бָ���£�������ָ������ָ���������ǡ������Ρ���Ҫּ��\n" NOR, me, target);
	me->set_temp("ruhe_count", 1);	
        me->add_temp("apply/attack", skill*2);
        me->add_temp("apply/dodge", skill);
        me->add_temp("apply/parry", skill);
        me->set_temp("ruhe", 1);

        call_out("checking", 1, me, target);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill /7);
	
        me->add("neili", -150);
        me->add("jing", -150);
        return 1;
}


void checking(object me, object target)
{

	object weapon;
        int skill;
	string *msg;
if (!me)
return;
        skill = me->query_skill("taishan-sword");
	weapon = me->query_temp("weapon");

	if ( me->query_temp("ruhe_finish")  ) {
		me->set_temp("ruhe_hit",1);
                message_vision(HIW"\n$N�������𽣾����Ѿ������������Ρ��ļ��㡣\n" NOR, me);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
        	me->delete_temp("ruhe");
        	me->delete_temp("ruhe_hit");
        	me->delete_temp("ruhe_count");
        	me->delete_temp("ruhe_finish");
	}
        else if ( me->query_temp("ruhe")  ) {

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n�������޽�����������ȥҲ����Ȼ������ֹͣ�������Ρ��ļ��㡣\n" NOR);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
		me->delete_temp("ruhe");
                return;
           }

           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n���"+weapon->name()+"�ѻ٣���������ȥҲ����Ȼ������ֹͣ�������Ρ��ļ��㡣\n" NOR);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
		me->delete_temp("ruhe");
                return;
           }
           else if ( (int)me->query("jing") < 200  ) {
                tell_object(me, "\n�㰵�����񲻼̣����Լ����ԡ������Ρ����㣬����ֹͣ������\n\n" NOR);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
		me->delete_temp("ruhe");
                return;
           }
           else if ( me->query_skill_mapped("sword") != "taishan-sword" ) {
                tell_object(me, "\n��ת��ʩչ�����������������ԡ������Ρ����㡣\n\n" NOR);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
		me->delete_temp("ruhe");
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n������û�к��˹��У���ȻҲ�����ԡ������Ρ������ˡ�\n\n" NOR);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
		me->delete_temp("ruhe");
                return;
           }
	   else {
        msg = ({
		"$N���ִ�һ�����壬�ն���ȭ��\n",
		"$N��Ĵָ������ζ�ʳָ��������ָȫչ����������Ĵָ����ʳָ��������ָ��\n",
		"$N���ֲ�ס��ָ���㣬����"+weapon->name()+"����ڶ���\n",
		"$N������ָ��ס�������ƺ��ڼ�����Ŀ��\n",
		});
	message_vision(msg[random(sizeof(msg))], me,target);
	me->add_temp("ruhe_count",1);	
        me->add("jing", -20);	
	call_out("checking", 1, me, target);
		}
	}
	   else return;

}  

void remove_effect(object me)
{
        int skill;
        skill = me->query_skill("taishan-sword");
        if ( me->query_temp("ruhe") ) {
		me->set_temp("ruhe_hit",1);
                message_vision(HIW"\n$N�������𽣾����Ѿ������������Ρ��ļ��㡣\n" NOR, me);
        	me->add_temp("apply/attack", -skill*2);
        	me->add_temp("apply/dodge", -skill);
        	me->add_temp("apply/parry", -skill);
        	me->delete_temp("ruhe");
        }
}

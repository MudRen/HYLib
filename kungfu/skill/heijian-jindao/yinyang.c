//heijian-jindao ���������з�
//by fqyy 2003.5.9
/*
�󵶺���
�ҽ�б�̡����������Ը���Ϊ��������������Ϊ�ȣ�������е����ӽ�Ȼ�෴��һ��ͬʹ��
�������Ǿ�������֮�£����������˫�ֱ���ԽʹԽ��������������ȴ�ֵ��������������
��ã������ศ�������������к����ľ�����

�뵽�˴����͵ء����ҹ����ҽ������ʹ����ƽ����ѧ������
�����з��������ڽ��������ᣬ��ʱͻȻӲ��������������յĵ����������س���ľ��
��ȴ������ϴ��ȫ�ߵ���������·�ӣ����ɽ������䵶������������޷���
*/
#include <ansi.h>
#include <combat.h> 

inherit F_SSERVER;

int perform(object me, object target)
{
	int i,skill;
	object *inv;
	object weapon2;
        object weapon = me->query_temp("weapon");  

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���������з�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_dex() < 40 )
                return notify_fail("�������������������㣬����ʹ�����������з���\n");
        
        if( me->query_skill("dodge") < 250 )
                return notify_fail("���������з���Ҫ�������Ṧ��ϣ�������Чʩչ��\n");

        if( me->query_skill("sword") < 250 )
                return notify_fail("�㽣��δ��¯����֮����������ʹ�����������з���\n");
        if( me->query_skill("blade") < 250 )
                return notify_fail("�㵶��δ��¯����֮����������ʹ�����������з���\n");
        if( me->query_skill("heijian-jindao",1) < 250 )
                return notify_fail("��ڽ���δ��¯����֮����\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("�����������ʹ�����������з���\n");

        if( me->query("jing") <= 500 )
                return notify_fail("��ľ�������ʹ�����������з���\n");

        if (!weapon)
                return notify_fail("�������޽�����ʹ�����������з�����\n");
        if (me->query_temp("heijian-jindao/luanren",1))
                return notify_fail("������ʹ�����������з��޷������������з���\n");
        if (me->query_temp("heijian-jindao/nizhuan",1)&&me->query_skill("heijian-jindao",1)<300)
                return notify_fail("����㹦�����ʹ�����������з�����\n");
        if ( me->query_skill_mapped("sword") != "heijian-jindao"
          || me->query_skill_mapped("parry") != "heijian-jindao"
          || me->query_skill_mapped("blade") != "heijian-jindao"
          && userp(me))
             	return notify_fail("������Ƚ��ڽ����໥��ϡ�\n");
       inv = all_inventory(me);
       for(i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
		if (weapon->query("skill_type") == "blade") {
        	   if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   i = 3;
			   break;
		   }
		}
		if (weapon->query("skill_type") == "sword") {
   	        if( inv[i]->query("skill_type") == "blade" ) 
		   {
			   weapon2 = inv[i];
			   i = 2;
			   break;
		   }
		}
       }
	if (!objectp(weapon2)) return notify_fail("��ֻ��һ�ֱ����������������з���\n");
	if (me->query_temp("heijian-jindao/nizhuan",1)) {
       message_vision(HIC"\n$N�͵ء����ҹ����ҽ������ʹ����ƽ����ѧ"HIW"�����������з���"HIC"����\n"+
				"�����������ᣬ��ʱͻȻӲ��������������յĵ�����\n"+
				"�����صĵ���ȴ������ϴ��ȫ�ߵ���������·�ӣ����ɽ������䵶������������޷���\n\n" NOR, me);
	} else {
       message_vision(HIW"\n$N�󵶺����ҽ�б�̡����������Ը���Ϊ��������������Ϊ�ȣ�������е����ӽ�Ȼ�෴��һ��ͬʹ��\n"+
				"�������Ǿ�������֮�£���$N˫�ֱ���ԽʹԽ��������������ȴ�ֵ��������������\n"+
				"��ã������ศ�������������к����ľ�����\n\n" NOR, me);
	}
        skill = me->query_skill("heijian-jindao", 1)/4*i;
        me->add_temp("apply/attack", skill/4 );
        me->add_temp("apply/damage", skill/4 );
        me->set_temp("heijian-jindao/yinyang",skill/4);
        me->set_temp("heijian-jindao/luanren",1);
        if( me->is_fighting() && userp(me))
        	me->start_busy(2);
        me->start_perform(1,"���������з�");
        me->add("neili", -800);
        me->add("jing", -100);
        call_out("remove_effect", 1, me, weapon,weapon2, skill/3);
        return 1;
}

void remove_effect(object me, object weapon,object weapon2, int count)
{
        if ( !me ) return;
        if (objectp(me) && me->query_temp("heijian-jindao/yinyang")) {
          	if (count-- > 0
		&& me->is_fighting()
		&& me->query_skill_mapped("sword") == "heijian-jindao"
		&& me->query_skill_mapped("blade") == "heijian-jindao"
		&& me->query_temp("weapon")
		&& objectp(weapon2)
		&& weapon == me->query_temp("weapon")) {
              		call_out("remove_effect", 1, me, weapon,weapon2, count);
              		return;
          	}
          	me->add_temp("apply/attack", - me->query_temp("heijian-jindao/yinyang"));
          	me->add_temp("apply/damage", - me->query_temp("heijian-jindao/yinyang"));
          	me->delete_temp("heijian-jindao/yinyang");
          	me->delete_temp("heijian-jindao/luanren");
       message_vision(HIR"\n$N֪���Լ��������������з��������󣬲��Ҷ��ã������ջ��˹��ơ�\n\n" NOR, me);
        }
}

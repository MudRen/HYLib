#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage, club;

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("���׶����졹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon = me->query_temp("weapon")) 
           || weapon->query("skill_type") != "club" )
                return notify_fail("�������޹����������á��׶����졹����\n");

        if( me->query_temp("sl_leidong") )
                return notify_fail("���ʹ�꡸�׶����졹��Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
        
        if( (int)me->query_skill("weituo-gun", 1) < 150 ||
           (int)me->query_skill("weituo-gun", 1) < 150 ||
            (int)me->query_str() <=25 )
                return notify_fail("����Ϊ����������δ�������׶����졹��\n");

        if( me->query_skill("yijinjing", 1) < 150 )
                return notify_fail("����׽�ڹ���Ϊ���δ����ʩչֻ���˼�����\n");

        if( me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("�����õ��ڹ��롸�׶����졹�ķ���㣣�\n");
        if (me->query_skill_mapped("club") != "weituo-gun" ||
            me->query_skill_mapped("parry") != "weituo-gun")
                return notify_fail("�������޷�ʹ�á��׶����졹���й�����\n");                                                                                 
      
        if( me->query("neili") <= 2000 )
                return notify_fail("���������Ϊ���㣬����������ʩչ���׶����졹��\n");

        if( me->query("jing") <= 200 )
                return notify_fail("��ľ������ޣ�������ʩչ���׶����졹��\n");

        message_vision(BLU"\nͻȻ$N���һ�������׶����졹����ɫ৵ı��ͨ�죬�뷢�Էɣ���������"+weapon->name()+BLU"���У����ˡ���һ��������"HIW"��������"BLU"��\n" NOR, me);
        
        damage = me->query_skill("weituo-gun", 1) + me->query_skill("yijinjing",1);
     damage /= 6;
        club = me->query_skill("club")/3;
        if ( userp(me) ) {
                me->add("neili", -300);
                me->add("jingli", -50);
                if ( damage > weapon->query("weapon_prop/damage") * 2)
                        damage = weapon->query("weapon_prop/damage") * 2;
                else weapon->add("rigidity", 1);
        }

        me->set_temp("sl_leidong", 1); 
        me->add_temp("apply/damage", damage);
        me->add_temp("apply/attack", damage);
        
        call_out("remove_effect1", club/2, me, weapon, damage);
        call_out("remove_effect2", club*2/3, me);
//        me->start_exert(club*2/6, "���׶����졹");

        return 1;
}

void remove_effect1(object me, object weapon, int damage) 
{
        if (!me) return;
        me->add_temp("apply/attack", -damage);  

        if (!weapon) {
                me->set_temp("apply/damage", 0);
                return;
        }
        me->add_temp("apply/damage", -damage);
        message_vision(HIY"\n$Nһ�ס��׶����졹ʹ�꣬����"NOR+weapon->name()+HIY"�ϵĹ�â����Ҳ��ʧ�ˡ�\n"NOR, me);                
}

void remove_effect2(object me)
{
        if (!me) return;
        me->delete_temp("sl_leidong");
        tell_object(me, HIG"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á��׶����졹�ˡ�\n"NOR); 
}

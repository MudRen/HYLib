 // void_sense.c
#include <ansi.h> 
inherit F_SSERVER;
int bbqthem(object me, object obj);
int perform(object me, object target)
{
        int lvl,i;
        object env, *inv;
        if((int) me->query_skill("kwan-yin-spells",1) < 120)
                return notify_fail("��Ĺ����������䲻�����");
        if (!me->is_fighting())
                return notify_fail("���ء�ֻ����ս����ʹ�á�\n"); 
        lvl = (int) me->query_skill("magic");
        if( me->query("neili") < 200 )
                return notify_fail("��ķ���������\n");
        if( me->query("max_jing") <= 200 )
                return notify_fail("����񲻹���\n"); 
        if (target==me)
                        return notify_fail("��Ҫ���ˣ�\n");
        if (userp(me)) me->add("neili", -200);
        if (userp(me)) me->receive_damage("jing", 200);
        
        message_vision(WHT"$N����һ�����ء������ֻ��ģ�����ƽ̯�����Ǽ��������գ������һ�� 
ֻ�������İ׹�͸�����⡣ \n" NOR, me);
        message_vision(HIW "������$N��һ�ɵ����İ�������Χ����\n" NOR, me);
        if(target) {
                bbqthem(me, target);
        }
        else
        {
                env = environment(me);
                inv = all_inventory(env);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]==me ) continue;
                        if( inv[i]->is_corpse() ) continue;
                        if( !inv[i]->is_character()) continue;
                        if( !inv[i]->is_fighting(me)) continue;                 
                        bbqthem(me, inv[i]);
           }
        }
        if(me->query_busy()<5) me->start_busy(5); 
        return 1; 
} 
int bbqthem(object me, object obj)
{
        int magic,objsen;
        
        magic = (int) me->query_skill("magic");        
        
        message_vision(MAG "\n������"NOR+"$N"+MAG"��ͷ������������ע��$n�����ڣ�\n" NOR, obj,me);
        obj->receive_damage("qi", 1, me);
        
        if(obj->is_ghost()==1 && obj->query("combat_exp")<random(me->query("combat_exp"))*10) {
                message_vision(WHT "$N�漴���������Ӱ���٣�\n" NOR, obj);
                me->add("qi",obj->query("qi")/10);
                obj->die();
                return 1;
        }
        if(obj->is_zombie()==1 && obj->query("combat_exp")<random(me->query("combat_exp"))*10) {
                message_vision(WHT "$N����ȫ��������������һ����ľͷ�Ƶص��£���Ϊ��һ̲Ѫˮ��\n" NOR, obj);
                me->add("qi",obj->query("qi")/10);
                obj->die();
                return 1;
        }
        
        magic = random(magic*2) + magic;
        obj->receive_damage("qi",magic);
        
        me->receive_curing("jing", magic);
        if (me->query("qi")<me->query("eff_qi"))   me->add("qi",magic);
                else me->set("qi",me->query("eff_qi"));
        
        COMBAT_D->report_status(obj);
        //COMBAT_D->win_lose_check(me,obj,1);
        return 1;
}        

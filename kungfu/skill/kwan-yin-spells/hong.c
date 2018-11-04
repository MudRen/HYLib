#include <ansi.h> 
inherit F_SSERVER;
int bbqthem(object me, object obj);

int perform(object me, object target)
{
        int lvl,i,j,k, bonus;
        object env, *inv, *myteam;

        if((int) me->query_skill("kwan-yin-spells",1) < 150)
                return notify_fail("������Է�����Ϊ�������\n");
        if (!me->is_fighting())
                return notify_fail("���ˡ�ֻ����ս����ʹ�á�\n");
                        
        lvl = (int) me->query_skill("magic");
        bonus = (me->query("combat_exp")-4000000)/15000;
        if (bonus<0) bonus=0;
        if (bonus>200) bonus = 200; 
        if( me->query("neili") < (300 - bonus) )
                return notify_fail("��ķ���������\n");
        if( me->query("jing") <= 200 )
                return notify_fail("����񲻹���\n"); 
        me->add("neili", bonus-300);
        me->receive_damage("jing", 100);
        
        message_vision(HIW "$N��������ǰչ������֮״��������������������̨�����������£������ྲ��������ˡ� \n" NOR, me);
        message_vision(HIY "������ֻ��$N˫��һ˲�䷢����̫����Ҫҫ�۵Ĺ�â������\n" NOR, me); 
        env = environment(me);
        inv = all_inventory(env); 
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( inv[i]->is_corpse() ) continue;
                if( !inv[i]->is_character()) continue;
                if( !me->is_fighting(inv[i])) continue;
                bbqthem(me, inv[i]);
        }
        me->start_busy(2);
        return 1; 
}  
int bbqthem(object me, object obj) 
{
        int spells, busy_num;
        string id_enemy;
        spells = (int) me->query_skill("magic");
        spells = spells+ random(spells*2);
        if(obj->query("combat_exp")>random(me->query("combat_exp")/100*spells))
        {
                message_vision(HIB"$N��æת��ͷȥ������$n��\n"NOR,obj,me);
                //obj->kill_ob(me);
                //me->kill_ob(obj);
                return 1;
        }
        if(userp(obj))
        {
                tell_object(obj,HIW"��ֻ������ǰ��ãã��һƬ��ʲô���������ˡ�����\n"NOR);
                obj->set_temp("block_msg/all",1);
                obj->start_busy(5);
                message_vision(CYN"$Nʹ�����ס�۾���ֱ�ڵ��ϴ����\n"NOR,obj);
                call_out ("recover",10, obj);
        }
        else
        {
                if (obj->query("no_busy")) {
                        busy_num = obj->query("no_busy");
                        obj->delete("no_busy");
                         obj->start_busy(8);
                        call_out ("busy_recover",12, busy_num, obj);
                        }
                obj->start_busy(3+random(2));
                message_vision(CYN"$Nʹ�����ס�۾���ֱ�ڵ��ϴ����\n"NOR,obj);
        }
        return 1;
}  
int recover (object obj)
{
        obj->delete_temp("block_msg/all");
        tell_object(obj, HIG"���������ģ�����۾���ʼ���Էֱ���Χ�������ˡ�\n" NOR);
        return 1;
}        
int busy_recover (int busy_num, object obj)
{
   obj->set("no_busy",busy_num);
        return 1;
}         

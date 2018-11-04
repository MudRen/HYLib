//jianzhen.c �����ǽ���csy 99.05.26

#include <ansi.h>

inherit F_SSERVER;

void npc_attack(object invoker, object target, string npc, object where);

int perform(object me, object target)
{
        string msg;
        string npc_dir = "/d/quanzhen/npc/";
        object where;

        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me
        ||   !me->is_fighting(target))
                return notify_fail("������ȫ�����ӶԸ�˭ѽ��\n");

        if((string)me->query("family/family_name") != "ȫ���" )
                return notify_fail("���ֲ���ȫ��̵��ӣ�ȫ�������������㣿�\n");

        if((string)target->query("family/family_name") == "ȫ���" )
                return notify_fail("ͬ���භ��ʦ����æ��\n");

        if((int)me->query_skill("qixing-array", 1) < 150)
                return notify_fail("��ı�����������Ϊ����޷���ȫ��������Ͻ���\n"); 

        if((int)me->query_skill("quanzhen-jian", 1) < 150)
                return notify_fail("���ȫ�潣����Ϊ������ܺ�ȫ����������ϡ�\n");        

        if((int)me->query("neili") < 300 )
                return notify_fail("�������������û�취��ȫ����������ϡ�\n"); 
       
        if((int)me->query("jing") < 60 )
                return notify_fail("���������ǲ��壬�����������������ˣ�\n");

        me->add("neili", -200);
        me->receive_damage("jing", 10);

        if( random(me->query("max_qi")) < 60 ) 
        {
                write("�ף�ȫ�����Ӻ����ڸ�����\n");
                return 1;
        }

     msg = HIR "\n$N����һչ��һ�����������ֻ����$N���һ����ȫ���������ںδ���\n" NOR +
              HIY "\nֻ������һ����������������������ӡ��´�ͨ��"+
               "���������ӡ������������������ӡ��𴦻��������ڴˣ�\n"NOR +
              HIR "\n$Nһָ$n�������޶��������񼫣���ʦ��ʦ����������ˣ�\n\n" NOR;      
        message_vision(msg, me, target);
        msg = HIC "$n����$N����������üһһӵ�����ˣ��������㣡\n\n" NOR;     
        message_vision(msg, me, target);
//        target->kill_ob(me);
        
        where=environment(target);
        call_out("npc_attack", 2, me, target, npc_dir+"hao", where);
        call_out("npc_attack", 3, me, target, npc_dir+"liu", where);
        call_out("npc_attack", 5, me, target, npc_dir+"ma", where);
        call_out("npc_attack", 6, me, target, npc_dir+"qiu", where);
        call_out("npc_attack", 8, me, target, npc_dir+"sun", where);
        call_out("npc_attack", 9, me, target, npc_dir+"tan", where);
        call_out("npc_attack", 11, me, target, npc_dir+"wangchuyi", where);
        me->start_busy(2);
        return 30+random(30);
}

void npc_attack(object invoker, object target, string npc, object where)
{
        object attacker;
        int rd;
        string tid;

        if(!invoker || !target) return;

        if( environment(invoker) != environment(target) ) return;
        if( environment(target) != where) return;

        seteuid(getuid());
        attacker = new(npc);
        attacker->move(environment(invoker));

        //do not attack too weak ppls...
        if( (int)target->query("combat_exp") < 10000 )
        {
                tid = (string)target->query("id");
                rd = random(7);
                if( rd == 0 ) attacker->command_function("wait " + tid);
                else if( rd == 1 ) attacker->command_function("kick " + tid);
                else if( rd == 2 ) attacker->command_function("kok " + tid);
                else if( rd == 3 ) attacker->command_function("slogan " + tid);
                else if( rd == 4 ) attacker->command_function("tx " + tid);
                else if( rd == 5 ) attacker->command_function("hammer " + tid);
                else attacker->command_function("pei " + tid);
        }
        else
        {
                COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"));
        
                // give the killing credit to the invoker.
                // so this would be counted as PK if the invoker is user.
                if(target->query_temp("last_damage_from")==attacker)
                        target->set_temp("last_damage_from", invoker);
        
                if(target->query_temp("last_fainted_from")==attacker)
                        target->set_temp("last_fainted_from", invoker->query("id"));
        }
        destruct(attacker);
}



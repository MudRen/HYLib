// snowman
#include <ansi.h>

int check_fight(object me);
int remove_effect(object me);
int perform(object me)
{
        if( !me->is_fighting() || !living(me))
                return notify_fail("��������ֻ����ս���е�ʹ�á�\n");

        if(objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ������á������𡹣�\n");
        if(me->query_temp("honglian"))        
                return notify_fail("������ʹ�á������𡹡�\n");  
        if(me->query_temp("mz_lx"))        
                return notify_fail("������ʹ�á�������ħ�䡹��\n");  
        if((int)me->query_skill("huoyan-dao", 1) < 180 )
                return notify_fail("��Ļ��浶������죬��������ᡸ������֮���ϡ�\n");
        if( (int)me->query("max_neili", 1) < 1500 )
                return notify_fail("���������Ϊ̫����ʹ�����������𡹡�\n");                
        if( (int)me->query("neili", 1) < 800 )
                return notify_fail("����������������ʹ�����������𡹡�\n");
        if(userp(me) && (int)me->query_skill("xiaowuxiang", 1) < 100 )
                return notify_fail("���С���๦�ȼ������ߣ�ʹ�����������𡹡�\n");
        if(userp(me) && (int)me->query_skill("lamaism", 1) < 150 )
                return notify_fail("��������ķ������򲻹����޷�ʹ�á������𡹡�\n");
        if (userp(me) && me->query_skill_mapped("parry") != "huoyan-dao")
                return notify_fail("�������𡹱����ڼ����мܵ�����²���ʹ�á�\n");
        message_vision(RED"\n$N������浶֮�������𡹾����������������ʺ�ɫ����ӿ��������ǰ����֮�����㼴ͣס������
����Ʈ���޶����������ڰ�գ�������������翣�����׽����ȴ��ɱ�������Σ�ʵ������������\n"NOR,me);
        me->start_busy(1);
        me->set_temp("honglian", 1);
        me->add("neili", -300);
        me->add_temp("apply/parry", me->query_skill("huoyan-dao", 1)/2);
        me->add_temp("apply/arrmor", me->query_skill("huoyan-dao", 1)/2);
        check_fight(me);
        return 1;
}

int check_fight(object me)
{
        object *enemy, target;
        int sz;        

	if (!me) return 0;
        if(me->is_ghost() || !living(me) || environment(me)->query("no_fight") || me->query_temp("weapon")){
           me->add_temp("apply/parry", -me->query_skill("huoyan-dao", 1)/2);
           me->add_temp("apply/arrmor",-me->query_skill("huoyan-dao", 1)/2);
           me->delete_temp("honglian");
           return 0;
           }        

        me->add("neili", -5);
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) remove_effect(me);
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;
        if( sz > 0 ) target = enemy[random(sz)];
        else remove_effect(me);
        if(!me->query_temp("honglian")) return 1;
        else if(!me->is_fighting()){
                if(!me->query_temp("stopped")){
                    me->set_temp("stopped", 1);
                    call_out("check_fight", 2, me);
                    }
                else remove_effect(me);
                }
       else if (userp(me) && (me->query_skill_mapped("strike") != "huoyan-dao" || me->query_skill_mapped("parry") != "huoyan-dao")){
                  message_vision(HIY"$Nһ��������ͻȻ���У���Ȼ����ȫ��ͬ����������\n"NOR,me);
                  me->add_temp("apply/parry", -me->query_skill("huoyan-dao", 1)/2);
                  me->add_temp("apply/arrmor", -me->query_skill("huoyan-dao", 1)/2);
                  me->delete_temp("honglian");
                  return 1;
                  }   
       else if( me->query("neili") <= 10 || !target ) remove_effect(me);
       else call_out("check_fight", 1, me);
       return 1;
}       

int remove_effect(object me)
{
   string msg;
   msg = "/kungfu/skill/huoyan-dao"->query_skill_name(me->query_skill("huoyan-dao", 1));
   message_vision(HIY "\n$N����һ��"+msg+"ʹ�꣬˫�ֺ�ʮ���ڵ��أ�ʾ�ȱ�Ϊ����\n\n"NOR, me);
   me->add_temp("apply/parry", -me->query_skill("huoyan-dao", 1)/2);
   me->add_temp("apply/armor", -me->query_skill("huoyan-dao", 1)/2);
   me->delete_temp("honglian");
   me->delete_temp("stopped");
   remove_call_out("check_fight"); 
   return 0;
}

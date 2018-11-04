// ̫��ȭPFM
// snowman
#include <ansi.h>

int check_fight(object me);
int remove_effect(object me);
int exert(object me)
{
        if( !me->is_fighting() || !living(me))
                return notify_fail("��̫����ֻ����ս���е�ʹ�á�\n");

        if(objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ������á�̫������\n");
        if(me->is_busy())        
         return notify_fail("��������æ���ء�\n");  

        if(me->query_temp("taiji"))        
                return notify_fail("��̫����֮�����಻�������Ѿ��ڷ������������ˡ�\n");  
        if((int)me->query_skill("taiji-quan", 1) < 100 )
                return notify_fail("���̫��ȭ������죬��������ᡸ̫����֮���ϡ�\n");

        if( (int)me->query("neili", 1) < 1200 )
                return notify_fail("���������Ϊ̫�������Ӳ�����̫���������ơ�\n");                
        if(userp(me) && (int)me->query_skill("taiji-shengong", 1) < 100 )
                return notify_fail("���̫���񹦵ȼ������ߣ����Ӳ�����̫������������\n");

        if(userp(me) && me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("����ڹ����ԣ��������ܷ��ӳ���̫���������ơ�\n");                                                                                     
        if (userp(me) && me->query_skill_mapped("parry") != "taiji-quan")
                return notify_fail("̫��ȭ�ġ�̫�������ϱ����ڼ����мܵ�����²���ʹ�á�\n");
        message_vision("$N�����ƶ���˫���´����ֱ����⣬��ָ΢�棬����ֿ�ƽ�У���������������������ǰ����۰뻷��
������Գ����ƣ����Ʒ��������ƣ�����$P˫��Բת��ÿһ�ж�����̫��ʽ�������仯����΢���\n",me);
        tell_object(me, CYN"\n��Ĭ���񹦣�˫����Ȼ�Ӷ����������һ����̫��ȭ"RED"��ȭ�⡹"CYN"���ӵ����쾡�£�\n\n"NOR);
        me->start_busy(1);
        me->set_temp("taiji", 1);
        me->add_temp("apply/dodge", me->query_skill("taiji-quan", 1)/3);
        me->add_temp("apply/defense", me->query_skill("taiji-quan", 1)/3);
        me->add_temp("apply/armor", me->query_skill("taiji-quan", 1)/3);

        check_fight(me);
        return 1;
}

int check_fight(object me)
{
        object *enemy, target;
        int sz;        

        if (!me || !me->query_temp("taiji")) return 0;

        if(me->is_ghost() || !living(me)){
           me->add_temp("apply/dodge", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/defense", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/armor", -me->query_skill("taiji-quan", 1)/3);           
           
           me->delete_temp("taiji");
           return 0;
           }        
        
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) remove_effect(me);
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;
        if( sz > 0 ) target = enemy[random(sz)];
        else remove_effect(me);

        if(!me->is_fighting()){
                if(!me->query_temp("stopped")){
                    me->set_temp("stopped", 1);
                    call_out("check_fight", 2, me);
                    }
                else remove_effect(me);
                }
        else if (userp(me) && (me->query_skill_mapped("unarmed") != "taiji-quan" 
                || me->query_skill_mapped("parry") != "taiji-quan"
                || me->query_temp("weapon"))){
                  message_vision(HIY"$Nʹ��һʽ̫��ȭ��ͻȻ���У���Ȼ����ȫ��ͬ��������\n"NOR,me);
//                  target->start_busy(3);
                  me->start_busy(1);
           me->add_temp("apply/dodge", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/defense", -me->query_skill("taiji-quan", 1)/3);
           me->add_temp("apply/armor", -me->query_skill("taiji-quan", 1)/3);           
           me->delete_temp("taiji");
                  }   
       else if( me->query("neili") <= 10 || !target || me->query("jiali")) remove_effect(me);
       else call_out("check_fight", 1, me);
       return 1;
}       

int remove_effect(object me)
{
   string msg;
   msg = "/kungfu/skill/taiji-quan"->query_skill_name(me->query_skill("taiji-quan", 1));
   message_vision(CYN "\n$Nʹ��"+msg+"����̫����˫�ֱ��˸�̫��ʽ��ԲȦ�������е�վ�ڵ��ء�\n\n"NOR, me);
   me->add_temp("apply/dodge", -me->query_skill("taiji-quan", 1)/3);
   me->add_temp("apply/defense", -me->query_skill("taiji-quan", 1)/3);
   me->add_temp("apply/armor", -me->query_skill("taiji-quan", 1)/3);           

   me->delete_temp("taiji");
   me->delete_temp("stopped");
   remove_call_out("check_fight"); 
   return 0;
}

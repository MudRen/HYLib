 //mimicat@fy4
#include <ansi.h> 
inherit F_SSERVER;
string *gifts=({ "qi","jing","jingli" });
string *gifts1=({"eff_qi","eff_jing","neili"});  

int perform(object me, object target)
{
        int extra,i;
        

        extra=me->query_skill("kwan-yin-spells",1);
        if(extra<120) return notify_fail("��Ĺ�����������ĵȼ����������\n");
        
        if( !target )
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
        //if( !userp(target) )
        //        return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

                
        if( me==target)
                return notify_fail("���Է������������Լ����ϡ�\n"); 
        if( (int)me->query("neili") < 1200 )
                return notify_fail("��ķ���������\n");
        
        message_vision(HIC "$N�����������֮ɫ��˫�ֺ�ʮ��Ը��������$n��������䡱 \n\n"NOR
        HIM"һ����ʥ�Ĺ��������$N��Χ��$N�����ն������Ĵȱ�֮ɫ������ԴԴ 
��������$n���ڡ� \n"NOR,me, target );
        
        for( i = 0; i < sizeof(gifts); i++ )
        {
                target->set(gifts[i],target->query("max_"+gifts[i]));
                target->set("eff_"+gifts[i],target->query("max_"+gifts[i]));
        }
        for( i = 0; i < sizeof(gifts1); i++ )
        {
                target->set(gifts1[i],target->query("max_"+gifts1[i]));
        }
 
   //     target->clear_condition();
        message_vision(HIR"$n�е�����������������$N����ɫȴ������ή������\n"NOR,me,target);
        me->unconcious();
        me->set("neili",0);
        //me->set("force",0);
   //me->set("atman",0);
        return 1;
}      

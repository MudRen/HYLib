// dagou.c ����
// By lichen@xkx.us
// For trying to make a dagou zhen. When perform dagou, increase temp damage.
// Suggestion: Zhenfa can be created in multiple rooms. Maybe we can use
// OOD to do it. I believe it will be more fun than making zhenfa as perform
// or skill.

#include <ansi.h>

// Define requirement is 4 dai gbdizi
// maximum number of people in ���� is 6 people
// minimum number of people in ���� is 2 people

#define REQUIRE 4
#define MAX_INARRAY 6
#define MIN_INARRAY 2

inherit F_DBASE;
inherit F_SSERVER;

string *ran_msg = ({
        "�߽У�����ү��̫̫��ʩ����䷹����",
        "�е�������ү̫̫���кã��ʹ����һ��Ǯ����",
        "��������������·�㲻���ģ���",
        "�����������������㴳��������",
        "��������ʩ�ữ��һ�뷹�ģ���",
});

string *ran_color = ({ HIC, HIG, HIY, HIR, HIM });

private string location(string direct);
void check_fight(object leader);
private void reset_effect(object *inarray, int partner, int ori_effect, int skill);
private void remove_effect(object inarray, int skill);
void random_msg(object leader);

int perform(object me)
{
    int skill, ori_effect;
    int partner, num;
    int user_num;
    object victim, weapon;
    object leader, *obj, *inarray, env;
    object *user_list;
    string id;
    
    leader = 0;
    inarray = ({0, 0 , 0, 0, 0, 0, 0});
    
    if( me->query("family/family_name") != "ؤ��" )
                return notify_fail("�㲻��ؤ����ӣ�ʹ�ò��˴���\n");
                
    if( (int)me->query_temp("dagou") ) 
        return notify_fail("���Ѿ��ڲ�������ˡ�\n");

                                                                
    if( !victim ) victim = offensive_target(me);

    if( !victim || !victim->is_character() || !me->is_fighting(victim) 
)
        return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( victim->query("family/family_name") == "ؤ��" )
                return notify_fail("����ô���Զ�ͬ��ʹ�ô���\n");
        
        if( me->query_skill_mapped("staff") != "dagou-bang" 
            || !objectp(weapon = me->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "staff" ) 

        return notify_fail("�����ʹ�ô򹷰������ܼ������\n");
   
        env = environment(me);
        obj = all_inventory(env);
        num = sizeof(obj);
        partner = 0;
        
        // check how many users are in ����. If there are someone in the ����,
        // then get leader and victim.
        
        for( int i = 0; i < num; i++ ) {
            if( obj[i]->query_temp("dagou") ) {
                if( !leader ) {
                        if( obj[i]->query_temp("dagou/is_leader") == -1 )
                        leader = obj[i]->query_temp("dagou/data");
                    else
                        leader = obj[i];
                    victim = leader->query_temp("dagou/data")[0][MAX_INARRAY];
                }
                partner++;
            }
        }
        
        // If in the room there is no one take part in ����, then set this user
        // as leader. If any other 4dai or above gb dizi here are fighting the same 
        // victim, then these gb dizi set_temp("dagou", pointer to the leader ). the 
        // leader set_temp("dagou") 4 variables. First one is "leader"(indicate he is 
        // the leader of the array, second one is a pointer point to all people in 
        // array(����), third one is total staff skill of all people who join the 
        // arraym, the forth is the number of people who join the array.
        
        if( partner == 0 ) {
                inarray[0] = me;
                inarray[MAX_INARRAY] = victim;
                           
            message_vision( HIR"$N��Ȼ�����е�����λؤ���ֵܣ�����󣡰��ҶԸ�$n��\n" NOR, me, victim);
                
                user_list = users();
                user_num = sizeof(user_list);

                // Let all 4 dai(or above) gb dizi who are in the same area know that someone is using ����.
                // It is to increase the interaction between gb dizi.
                // ����ν��һ�����ѣ��ٷ�֧Ԯ��
                
                while( user_num-- ) {
                        if( !environment(user_list[user_num]) ) continue;
                  if( user_list[user_num]->query("family/family_name") != "ؤ��" 
                       ) continue;
                        if( environment(user_list[user_num]) == env ) continue;
                        if( !living(user_list[user_num]) ) continue;
                        if( location(file_name(env)) == location(file_name(environment(user_list[user_num]))) )
                            tell_object( user_list[user_num], HIG"������ԼԼ��������Զ��" + me->query("name")
                                    + "�����ڷ�������Ը�" + victim->query("name") + "��"
                                    + "\n�����������" + env->query("short") + "��\n\n"NOR );
                    else 
                            tell_object( user_list[user_num], HIG"������ԼԼ��������Զ��ɱ�����죬������ؤ������ڷ�������\n\n"NOR );
                } 
                        
                partner = 1;
                skill = me->query_skill("staff");
                
            for( int i=0; i < num; i++) {
            if( obj[i] == me ) continue;
            if( !living(obj[i]) ) continue;
                if( !obj[i]->is_character() || obj[i]->is_corpse() ) continue;
                if( !obj[i]->is_fighting(victim) ) continue;
                if( obj[i]->query_skill_mapped("staff") != "dagou-bang" ) continue;
                if( !objectp(weapon = obj[i]->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "staff" )
                continue;
//                    if( obj[i]->query("rank") < REQUIRE ) continue;
                        if( !obj[i]->is_fighting(victim) ) continue;                                             
                    if( (int)obj[i]->query_temp("dagou") ) continue;              
                        
            inarray[partner] = obj[i];
            message_vision( 
                            HIR "$Nһ�߳�������������·�ĵ������ַ�Ӵ����Ӵ���Ӵ������" + 
                            "һ�߰�Χ��$n��\n" NOR, inarray[partner], victim );
            skill += inarray[partner]->query_skill
("staff");
            partner++;
            if( partner == MAX_INARRAY ) break;
                }
                

                me->set_temp("dagou/is_leader", 1);
                me->set_temp("dagou/data", ({ inarray, skill, partner }) );
                
                skill = (int)(skill / (partner*3));
                if( partner > 1 ) {
                        for( int i = 0; i < partner; i++ ) {
                        inarray[i]->add_temp("apply/dodge",  skill );
                        if( i > 0 ) {



                                inarray[i]->set_temp("dagou/is_leader", -1);
                                inarray[i]->set_temp("dagou/data",  me );
                        }
                        }
                }
        
            call_out("random_msg", 5, me);
        
                me->start_call_out( (: call_other, __FILE__, "check_fight", me :), 1);

        }
        
        else if( partner >= MAX_INARRAY ) 
                return notify_fail("����ֻ���ɶ��������˲��롣\n");

    else {
        inarray = leader->query_temp("dagou/data")[0];
            skill = leader->query_temp("dagou/data")[1];
            ori_effect = (int)(skill / (partner*3));
            if(partner == 1) 
                leader->add_temp("apply/dodge", ori_effect );
            me->add_temp("apply/dodge", ori_effect );
        inarray[partner] = me;
          partner += 1;
        skill += me->query_skill("staff");
        leader->set_temp("dagou/data", ({ inarray, skill, partner }) );
        reset_effect(inarray, partner, ori_effect, skill);      
        me->fight_ob(victim);
                victim->fight_ob(me);
                me->set_temp("dagou/is_leader", -1);
                me->set_temp("dagou/data", leader);
                message_vision( 
            HIR "$Nһ�߳�������������ү̫̫���кã��ʹ����һ��Ǯ����" +
            "һ�߼�����󣬰�Χ$n��\n" NOR, me, victim );
            for( int i = 0; i < partner-1; i++ )
                tell_object(inarray[i], HIG"\n�㿴�����˼�����󣬲��ɵþ���Ϊ֮һ��\n"NOR);
        }

    return 1;
}

private string location(string direct)
{
        int start, end, count, next;

        while (count != 3) {
                  if( direct[next] == '/' ) count++;
                if (count == 2 && start == 0) 
                        start = next+1;
                next++;
        }
        end = next-2;
        direct = direct[start..end];
        return direct;
}

void check_fight(object leader)
{
    object weapon, *inarray;
    int partner, skill, ori_effect, ori_partner;
        
        if (!leader) return;
        if( !leader->query_temp("dagou") ) return;
        
        inarray = leader->query_temp("dagou/data")[0];
        skill = leader->query_temp("dagou/data")[1];
        partner = leader->query_temp("dagou/data")[2];
        ori_effect = (int)(skill / (partner*3));
        ori_partner = partner;
        
  // If the victim is dead or run away or the qi less than 50, then
        // the ���� is done.
        // If the leader is not fighting with the victim or the leader is not
        // using dagou-bang skill, then the ���� is finish too. 
    
if (!inarray[MAX_INARRAY]) return;
    if( !living(inarray[MAX_INARRAY]) 
        || !present(inarray[MAX_INARRAY]->query("id"), environment(leader)) 
        || inarray[MAX_INARRAY]->query("qi") <= 50 
        || !leader->is_fighting(inarray[MAX_INARRAY]) 
        || leader->query_skill_mapped("staff") != "dagou-bang"
        || !objectp(weapon = leader->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "staff" )  
    {
                if ( partner != 1 ) {
                for ( int i = 0; i < partner; i++ )
                        remove_effect(inarray[i], ori_effect);
                    if (living( leader ))
                        message_vision(HIM"$N��һ���������󣡡������˿ڳ��������󡱣��������С�\n\n"NOR, leader);
                    else
                        message_vision(HIM"����ʧȥ��$N��Ⱥ�����ף�����һ���ɢ��\n\n"NOR, leader);
                }
                else {
                        leader->delete_temp("dagou");
                        if ( living(leader) )
                    message_vision(HIM"$N����û���˼�����󣬽ŵ�Ĩ�ͣ�һ�����Ե����ˡ�\n\n"NOR, leader);
        }
        return;
    }

        // Else, if the leader is still in the ����check all the people who are in
        // the array. If someone is not fighting with the victim or is not using	 dagou-bang
        // skill, then this guy quit the ����After that, reset the effect.
        
    else {
        for ( int i = 1; i < ori_partner; i++ ) {
                if ( inarray[i] == 0 ) break;
                if ( !inarray[i]->is_fighting(inarray[MAX_INARRAY]) 
                         || inarray[i]->query_skill_mapped("staff") != "dagou-bang"
                     || !objectp(weapon = inarray[i]->query_temp("weapon")) 
                     || (string)weapon->query("skill_type") != "staff" ) 
                {
                        message_vision( 
                            HIG "$Nһ�߳�������������·�ĵ���

���극Ӵ����Ӵ���Ӵ��������"
                            + "һ���˳��˴���\n"NOR, inarray[i]);
                        remove_effect(inarray[i], ori_effect);
                        skill -= inarray[i]->query_skill("staff");
                          partner -= 1;
                    if( i != partner ) {                      
                        inarray[i] = inarray[partner];
                        inarray[partner] = 0;                   
                        i--;
                    }
                    
                    else inarray[i] = 0;
                }
            }
            
            if( ori_partner != partner ) {
                    leader->set_temp("dagou/data", ({inarray, skill, partner}));
                reset_effect(inarray, partner, ori_effect, skill);              
            }
        }
    
    call_out("check_fight", 1, leader);
}

private void reset_effect(object *inarray, int partner, int ori_effect, int skill)
{
        skill = (int)(skill/(partner*3));
        if(partner == 1) 
        {
                inarray[0]->add_temp("apply/dodge", -ori_effect );
                return;
        }
        
        else {
                for( int i = 0; i < partner; i++ )
                {
                        if(inarray[i] == 0 ) break;
                        inarray[i]->add_temp("apply/dodge", -ori_effect );
                        inarray[i]->add_temp("apply/dodge", skill );
                }
        }
}

private void remove_effect(object inarray, int skill)
{
    inarray->add_temp("apply/dodge", -skill );
    inarray->delete_temp("dagou");
}

void random_msg(object leader)
{
        int partner;
        int ran;
        int extra;
        int ran_usr, ran_usr1;
        object obj, obj1, victim, weapon;
        
if (!leader) return;
if (!leader->query_temp("dagou/data")) return;
        if( partner = leader->query_temp("dagou/data")[2] ) {
                if(random(5) < 2) {
                        if( partner > 1 ) {
                                ran_usr = random(partner);
                                obj = leader->query_temp("dagou/data")[0][ran_usr];
                                ran = random(5);
                                message_vision( ran_color[ran] + "$N�ڴ�����" + ran_msg[ran] + "\n" NOR, obj);
                                victim = leader->query_temp("dagou/data")[0][MAX_INARRAY];
                                
                                // This is for ���ƽ�� and ˫�����.
                                
                                // this is ���ƽ�ϡ�
                                if ( random(2) == 1 ) {                                         
                                        if( obj->query_skill_prepare()["strike"] == "xianglong-zhang" ) {
                                            message_vision(ran_color[ran] + "$NͻȻð�ս��������ְֳ�������$n��\n"NOR, obj, victim);
                                            weapon = obj->query_temp("weapon");
        extra=obj->query_skill("dagou-bang");
        obj->add_temp("apply/attack", (2*extra));
        obj->add_temp("apply/damage", extra);
                                            COMBAT_D->do_attack(obj, victim, weapon, 1);
                                            COMBAT_D->do_attack(obj, victim, weapon, 1);
                                                COMBAT_D->do_attack(obj, victim, weapon, 1);
                                        obj->delete_temp("weapon");
                                        obj->set_temp("action_flag",1);
                                            COMBAT_D->do_attack(obj, victim);
                                            COMBAT_D->do_attack(obj, victim);
                                            COMBAT_D->do_attack(obj, victim);
        obj->add_temp("apply/attack", -(2*extra));
        obj->add_temp("apply/damage", -extra);

                                            obj->set_temp("weapon", weapon);
                                            obj->set_temp("action_flag",0);
                                            if ( obj->query("neili") >= 150 ) obj->add("neili", -10);
                                        }
                                }
                                // this is ˫����ϡ�
                                else {  
                                        do {
                                                ran_usr1 = random(partner);
                                        } while ( ran_usr1 == ran_usr);
                                        
                                        obj1 = leader->query_temp("dagou/data")[0][ran_usr1];

                                        message_vision(ran_color[ran] + "$N��$nͻȻð�ս�����˫����ϣ����һ�Ű�Ӱ����ͬ������\n"NOR, obj, obj1);
        extra=obj->query_skill("dagou-bang");
        obj->add_temp("apply/attack", (2*extra));
        obj->add_temp("apply/damage", extra);
                                        COMBAT_D->do_attack(obj, victim, obj->query_temp("weapon"), 1);
                                        COMBAT_D->do_attack(obj, victim, obj->query_temp("weapon"), 1);
        obj->add_temp("apply/attack", -(2*extra));
        obj->add_temp("apply/damage", -extra);
                                        obj1->set_temp("action_flag", 1);
        extra=obj1->query_skill("dagou-bang");
        obj1->add_temp("apply/attack", (2*extra));
        obj1->add_temp("apply/damage", extra);
                                        COMBAT_D->do_attack(obj1, victim, obj1->query_temp("weapon"), 1);
                                        COMBAT_D->do_attack(obj1, victim, obj1->query_temp("weapon"), 1);
                                        obj1->set_temp("action_flag", 0);
        obj1->add_temp("apply/attack", -(2*extra));
        obj1->add_temp("apply/damage", -extra);
                                        if ( obj->query("neili") >= 150 ) obj->add("neili", -5);
                                        if ( obj1->query("neili") >= 150 ) obj1->add("neili", -5);
                          }
                        }
                        else
                                message_vision( ran_color[ran] + "$N�¾���ս��" + ran_msg[ran] + "����������ʱ�䣬�ȴ�Ⱥؤ���롣\n"NOR, leader);
                }
                        
                call_out("random_msg", 6, leader);
        }
}
